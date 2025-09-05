"use client";

import { useEffect, useState } from "react";
import { useForm } from "react-hook-form";
import Link from "next/link";
import { Card, CardContent, CardDescription, CardHeader, CardTitle } from '@/components/ui/card';
import { Button } from '@/components/ui/button';
import { Input } from '@/components/ui/input';
import { Label } from '@/components/ui/label';
import { Select, SelectContent, SelectItem, SelectTrigger, SelectValue } from '@/components/ui/select';
import { Alert, AlertDescription } from '@/components/ui/alert';
import { Badge } from '@/components/ui/badge';
import { Separator } from '@/components/ui/separator';
import { Tabs, TabsContent, TabsList, TabsTrigger } from '@/components/ui/tabs';
import { supabase } from "../../../lib/supabaseClient";
import { membershipDiscounts } from "../../../lib/discountConfig";
import ProtectedRoute from "@/components/ProtectedRoute";
import toast from "react-hot-toast";


export default function NewPaymentPage() {
  const [users, setUsers] = useState([]);
  const [filteredUsers, setFilteredUsers] = useState([]);
  const [selectedUser, setSelectedUser] = useState(null);
  const [searchPhone, setSearchPhone] = useState("");
  const [searchName, setSearchName] = useState("");
  const [loading, setLoading] = useState(false);
  const [searchBy, setSearchBy] = useState("name"); // "name" or "phone"
  const [isExpired, setIsExpired] = useState(false);
  const [cardNumber, setCardNumber] = useState("");

  const {
    register,
    handleSubmit,
    watch,
    setValue,
    reset,
    formState: { errors },
  } = useForm({
    defaultValues: {
      user_id: "",
      mode_of_payment: "Cash",
      total_amount: "",
      discount_percent: "",
      discount_price: "",
      to_be_paid: "",
      receipt_no: "",
    },
  });

  const totalAmount = watch("total_amount");
  const discountPercent = watch("discount_percent");
  const modeOfPayment = watch("mode_of_payment");

  // Fetch users from Supabase
  useEffect(() => {
    async function fetchUsers() {
      try {
        const { data, error } = await supabase
          .from("users")
          .select("id, full_name, membership_type, mobile_number, valid_to");
        if (error) throw new Error("Failed to load users");
        setUsers(data || []);
        setFilteredUsers(data || []);
      } catch (err) {
        toast.error(err.message);
      }
    }
    fetchUsers();
  }, []);

  // Filter users based on search
  useEffect(() => {
    if (searchBy === "phone" && searchPhone) {
      const filtered = users.filter(user =>
        user.mobile_number.includes(searchPhone)
      );
      setFilteredUsers(filtered);
    } else if (searchBy === "name" && searchName) {
      const filtered = users.filter(user =>
        user.full_name.toLowerCase().includes(searchName.toLowerCase())
      );
      setFilteredUsers(filtered);
    } else {
      setFilteredUsers(users);
    }
  }, [searchPhone, searchName, users, searchBy]);

  // Auto calculate discount and payable amount
  useEffect(() => {
    if (totalAmount && discountPercent) {
      const discountPrice = (parseFloat(totalAmount) * parseFloat(discountPercent)) / 100;
      const toBePaid = parseFloat(totalAmount) - discountPrice;
      setValue("discount_price", discountPrice.toFixed(2));
      setValue("to_be_paid", toBePaid.toFixed(2));
    } else if (totalAmount) {
      setValue("discount_price", "0.00");
      setValue("to_be_paid", parseFloat(totalAmount).toFixed(2));
    }
  }, [totalAmount, discountPercent, setValue]);

  const handleUserSelect = (userId) => {
    setValue("user_id", userId);
    const user = users.find((u) => u.id === userId);
    setSelectedUser(user);
    setIsExpired(false);

    if (user) {
      if (user.valid_to) {
        const today = new Date();
        today.setHours(0, 0, 0, 0); // Set time to the beginning of the day for comparison
        const validToDate = new Date(user.valid_to);
        if (validToDate < today) {
          setIsExpired(true);
        }
      }

      const defaultDiscount = membershipDiscounts[user.membership_type] || 0;
      setValue("discount_percent", defaultDiscount);
    }

    // Clear search fields
    setSearchPhone("");
    setSearchName("");
  };

  const getMembershipColor = (type) => {
    const colors = {
      Silver: "bg-gray-100 text-gray-800",
      Gold: "bg-yellow-100 text-yellow-800",
      Platinum: "bg-purple-100 text-purple-800",
      Corporate: "bg-blue-100 text-blue-800"
    };
    return colors[type] || "bg-gray-100 text-gray-800";
  };

  const onSubmit = async (data) => {
    setLoading(true);
    const toastId = toast.loading('Processing payment...');

    try {
      // get currently logged-in admin
      const {
        data: { user },
        error: userError,
      } = await supabase.auth.getUser();

      if (userError) throw userError;
      if (!user) throw new Error("No logged in admin found");

      const paymentData = {
        user_id: data.user_id,
        mode_of_payment: data.mode_of_payment,
        total_amount: data.total_amount,
        discount_percent: data.discount_percent,
        discount_price: data.discount_price,
        to_be_paid: data.to_be_paid,
        receipt_no: data.receipt_no,
        created_by: user.email, // ✅ auto-fill with admin email
      };

      if (
        (data.mode_of_payment === "Credit Card" || data.mode_of_payment === "Debit Card") &&
        cardNumber
      ) {
        paymentData.card_number = cardNumber;
      }

      const { error } = await supabase.from("payments").insert([paymentData]);

      if (error) throw error;

      toast.success("Payment recorded successfully!", { id: toastId });
      reset();
      setCardNumber("");
      setSelectedUser(null);
    } catch (err) {
      if (err.message && err.message.includes('payments_receipt_no_key')) {
        toast.error("A payment with this receipt number already exists.", { id: toastId });
      } 
      else if (err.message && err.message.includes('users_email_key')) {
        toast.error("A user with this email already exists.", { id: toastId });
      }
      else {
        toast.error(err.message || "Something went wrong", { id: toastId });
      }
    } finally {
      setLoading(false);
    }
  };


  const clearSearch = () => {
    setSearchPhone("");
    setSearchName("");
    setFilteredUsers(users);
  };

  const handleCardNumberChange = (e) => {
    const input = e.target.value.replace(/\s/g, "");
    if (/^\d*$/.test(input) && input.length <= 16) {
      const formatted = input.match(/.{1,4}/g)?.join(" ") || "";
      setCardNumber(formatted);
    }
  };

  return (
    <ProtectedRoute>
      <div className="min-h-screen bg-gradient-to-br from-gray-50 to-gray-100 p-4 md:p-8">
        <div className="max-w-4xl mx-auto">
          {/* Header */}
          <div className="mb-8">
            <Link href="/" className="text-sm text-gray-600 hover:text-gray-900 mb-4 inline-flex items-center">
              ← Back to Dashboard
            </Link>
            <h1 className="text-3xl font-bold text-gray-900 mb-2 flex items-center gap-3">
              💳 New Payment
            </h1>
            <p className="text-gray-600">
              Record a new payment and apply membership discounts
            </p>
          </div>

          <div className="grid grid-cols-1 lg:grid-cols-3 gap-8">
            {/* User Selection Card */}
            <Card className="lg:col-span-1 shadow-lg border-0">
              <CardHeader>
                <CardTitle className="flex items-center gap-2">
                  👤 Select Customer
                </CardTitle>
                <CardDescription>
                  Search by name or phone number
                </CardDescription>
              </CardHeader>
              <CardContent className="space-y-4">
                {/* Search Type Tabs */}
                <Tabs value={searchBy} onValueChange={setSearchBy} className="w-full">
                  <TabsList className="grid w-full grid-cols-2">
                    <TabsTrigger value="name">Search by Name</TabsTrigger>
                    <TabsTrigger value="phone">Search by Phone</TabsTrigger>
                  </TabsList>

                  <TabsContent value="name" className="space-y-4">
                    <div className="space-y-2">
                      <Label htmlFor="search-name">Customer Name</Label>
                      <Input
                        id="search-name"
                        placeholder="Type customer name..."
                        value={searchName}
                        onChange={(e) => setSearchName(e.target.value)}
                      />
                    </div>
                  </TabsContent>

                  <TabsContent value="phone" className="space-y-4">
                    <div className="space-y-2">
                      <Label htmlFor="search-phone">Phone Number</Label>
                      <Input
                        id="search-phone"
                        placeholder="Type phone number..."
                        value={searchPhone}
                        onChange={(e) => setSearchPhone(e.target.value)}
                      />
                    </div>
                  </TabsContent>
                </Tabs>

                {(searchPhone || searchName) && (
                  <Button
                    variant="outline"
                    size="sm"
                    onClick={clearSearch}
                    className="w-full"
                  >
                    Clear Search
                  </Button>
                )}

                {/* User List */}
                <div className="space-y-2 max-h-64 overflow-y-auto">
                  {filteredUsers.length === 0 ? (
                    <p className="text-sm text-gray-500 text-center py-4">
                      {searchPhone || searchName ? "No users found" : "No users available"}
                    </p>
                  ) : (
                    filteredUsers.map((user) => (
                      <div
                        key={user.id}
                        onClick={() => handleUserSelect(user.id)}
                        className={`p-3 border rounded-lg cursor-pointer transition-colors hover:bg-gray-50 ${selectedUser?.id === user.id ? "border-blue-500 bg-blue-50" : "border-gray-200"
                          }`}
                      >
                        <div className="flex items-center justify-between">
                          <div>
                            <p className="font-medium text-sm">{user.full_name}</p>
                            <p className="text-xs text-gray-600">📱 {user.mobile_number}</p>
                          </div>
                          <Badge className={`${getMembershipColor(user.membership_type)} text-xs`}>
                            {user.membership_type}
                          </Badge>
                        </div>
                      </div>
                    ))
                  )}
                </div>

                {/* Selected User Info */}
                {selectedUser && (
                  <div className="mt-4 p-4 bg-blue-50 border border-blue-200 rounded-lg">
                    <h4 className="font-semibold text-blue-900">Selected Customer</h4>
                    <p className="text-sm text-blue-800">{selectedUser.full_name}</p>
                    <p className="text-sm text-blue-700">📱 {selectedUser.mobile_number}</p>
                    <Badge className={`${getMembershipColor(selectedUser.membership_type)} mt-2`}>
                      {selectedUser.membership_type} - {membershipDiscounts[selectedUser.membership_type]}% discount
                    </Badge>
                    {isExpired && (
                      <p className="text-red-600 font-semibold mt-2 text-sm">Membership Expired</p>
                    )}
                  </div>
                )}
              </CardContent>
            </Card>

            {/* Payment Form Card */}
            <Card className="lg:col-span-2 shadow-lg border-0">
              <CardHeader>
                <CardTitle className="flex items-center gap-2">
                  💰 Payment Details
                </CardTitle>
                <CardDescription>
                  Enter payment information and calculate final amount
                </CardDescription>
              </CardHeader>
              <CardContent>
                <form onSubmit={handleSubmit(onSubmit)}>
                  <fieldset className="space-y-8" disabled={!selectedUser || isExpired}>

                    {!selectedUser && (
                      <Alert className="border-yellow-200 bg-yellow-50">
                        <AlertDescription className="text-yellow-800">
                          ⚠️ Please select a customer first to proceed with payment
                        </AlertDescription>
                      </Alert>
                    )}
                    {isExpired && (
                      <Alert className="border-red-200 bg-red-50">
                        <AlertDescription className="text-red-800">
                          This user's membership has expired. Please renew the membership to make a payment.
                        </AlertDescription>
                      </Alert>
                    )}

                    {/* Payment Method */}
                    <div>
                      <h3 className="text-lg font-semibold text-gray-900 mb-4 flex items-center gap-2">
                        💳 Payment Method
                      </h3>
                      <div className="space-y-2">
                        <Label htmlFor="payment-method">Mode of Payment</Label>
                        <Select
                          onValueChange={(value) => setValue("mode_of_payment", value)}
                          defaultValue="Cash"
                        >
                          <SelectTrigger>
                            <SelectValue />
                          </SelectTrigger>
                          <SelectContent>
                            <SelectItem value="Cash">💵 Cash</SelectItem>
                            <SelectItem value="Credit Card">💳 Credit Card</SelectItem>
                            <SelectItem value="Debit Card">💳 Debit Card</SelectItem>
                            <SelectItem value="UPI">📱 UPI</SelectItem>
                            <SelectItem value="Cheque">📝 Cheque</SelectItem>
                          </SelectContent>
                        </Select>
                      </div>
                      {(modeOfPayment === "Credit Card" || modeOfPayment === "Debit Card") && (
                        <div className="space-y-2 mt-4">
                          <Label htmlFor="card-number">Card Number</Label>
                          <Input
                            id="card-number"
                            placeholder="XXXX XXXX XXXX XXXX"
                            value={cardNumber}
                            onChange={handleCardNumberChange}
                          />
                        </div>
                      )}
                    </div>

                    <Separator />

                    {/* Amount Details */}
                    <div>
                      <h3 className="text-lg font-semibold text-gray-900 mb-4 flex items-center gap-2">
                        💰 Amount Details
                      </h3>
                      <div className="grid grid-cols-1 md:grid-cols-2 gap-4">
                        <div className="space-y-2">
                          <Label htmlFor="total-amount">Total Amount *</Label>
                          <Input
                            id="total-amount"
                            type="number"
                            step="0.01"
                            placeholder="0.00"
                            {...register("total_amount", { required: "Total amount is required" })}
                            className={errors.total_amount ? "border-red-500" : ""}
                          />
                          {errors.total_amount && (
                            <p className="text-sm text-red-500">{errors.total_amount.message}</p>
                          )}
                        </div>

                        <div className="space-y-2">
                          <Label htmlFor="discount-percent">Discount Percent (%)</Label>
                          <Input
                            id="discount-percent"
                            type="number"
                            step="0.01"
                            placeholder="0"
                            {...register("discount_percent")}
                          />
                        </div>

                        <div className="space-y-2">
                          <Label htmlFor="discount-price">Discount Amount</Label>
                          <Input
                            id="discount-price"
                            type="number"
                            step="0.01"
                            {...register("discount_price")}
                            readOnly
                            className="bg-gray-50"
                          />
                        </div>

                        <div className="space-y-2">
                          <Label htmlFor="to-be-paid">Final Amount</Label>
                          <Input
                            id="to-be-paid"
                            type="number"
                            step="0.01"
                            {...register("to_be_paid")}
                            readOnly
                            className="bg-green-50 border-green-200 font-semibold"
                          />
                        </div>
                      </div>
                    </div>

                    <Separator />

                    {/* Receipt Details */}
                    <div>
                      <h3 className="text-lg font-semibold text-gray-900 mb-4 flex items-center gap-2">
                        🧾 Receipt Details
                      </h3>
                      <div className="space-y-2">
                        <Label htmlFor="receipt-no">Receipt Number *</Label>
                        <Input
                          id="receipt-no"
                          placeholder="Enter receipt number"
                          {...register("receipt_no", { required: "Receipt number is required" })}
                          className={errors.receipt_no ? "border-red-500" : ""}
                        />
                        {errors.receipt_no && (
                          <p className="text-sm text-red-500">{errors.receipt_no.message}</p>
                        )}
                      </div>
                    </div>

                    {/* Submit Buttons */}
                    <div className="flex flex-col sm:flex-row gap-4 pt-6">
                      <Button
                        type="submit"
                        disabled={loading || !selectedUser || isExpired}
                        className="flex-1 bg-green-600 hover:bg-green-700"
                      >
                        {loading ? (
                          <div className="flex items-center gap-2">
                            <div className="w-4 h-4 border-2 border-white border-t-transparent rounded-full animate-spin"></div>
                            Processing...
                          </div>
                        ) : (
                          "💾 Save Payment"
                        )}
                      </Button>
                      <Button
                        type="button"
                        variant="outline"
                        onClick={() => {
                          reset();
                          setSelectedUser(null);
                          clearSearch();
                        }}
                        disabled={loading}
                        className="flex-1 sm:flex-none sm:w-32"
                      >
                        Reset Form
                      </Button>
                    </div>
                  </fieldset>
                </form>
              </CardContent>
            </Card>
          </div>
        </div>
      </div>
    </ProtectedRoute>
  );
}