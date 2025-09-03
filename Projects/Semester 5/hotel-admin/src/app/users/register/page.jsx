"use client";

import { useState, useEffect } from "react";
import { useForm } from "react-hook-form";
import { zodResolver } from "@hookform/resolvers/zod";
import * as z from "zod";
import Link from "next/link";
import { Card, CardContent, CardDescription, CardHeader, CardTitle } from '@/components/ui/card';
import { Button } from '@/components/ui/button';
import { Input } from '@/components/ui/input';
import { Label } from '@/components/ui/label';
import { Select, SelectContent, SelectItem, SelectTrigger, SelectValue } from '@/components/ui/select';
import { Alert, AlertDescription } from '@/components/ui/alert';
import { Badge } from '@/components/ui/badge';
import { Separator } from '@/components/ui/separator';
import { supabase } from "../../../lib/supabaseClient";
import ProtectedRoute from "@/components/ProtectedRoute";

const userSchema = z.object({
  full_name: z.string().min(3, "Full name is required"),
  dob: z.string().optional(),
  gender: z.enum(["Male", "Female", "Other"]),
  nationality: z.string().optional(),
  address: z.string().optional(),
  city: z.string().optional(),
  state: z.string().optional(),
  pin_code: z.string().optional(),
  country: z.string().optional(),
  mobile_number: z.string().min(10, "Mobile number is required"),
  alternate_number: z.string().optional(),
  email: z.string().email("Invalid email").optional(),
  membership_type: z.enum(["Silver", "Gold", "Platinum", "Corporate"]),
  membership_number: z.string().min(3, "Membership number is required"),
});

export default function RegisterUserPage() {
  const [loading, setLoading] = useState(false);
  const [success, setSuccess] = useState(null);
  const [error, setError] = useState(null);

  const {
    register,
    handleSubmit,
    formState: { errors },
    reset,
    setValue,
    watch,
  } = useForm({
    resolver: zodResolver(userSchema),
  });

  const membershipType = watch("membership_type");
  const mobileNumber = watch("mobile_number");

  // Auto-generate membership number when mobile number changes
  useEffect(() => {
    if (mobileNumber && mobileNumber.length >= 10) {
      const membershipNumber = `GSP${mobileNumber}`;
      setValue("membership_number", membershipNumber);
    }
  }, [mobileNumber, setValue]);

  const getMembershipDiscount = (type) => {
    const discounts = {
      Silver: "10%",
      Gold: "15%",
      Platinum: "20%",
      Corporate: "25%"
    };
    return discounts[type] || "";
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
    setError(null);
    setSuccess(null);

    try {
      const { error } = await supabase.from("users").insert([
        {
          full_name: data.full_name,
          dob: data.dob || null,
          gender: data.gender,
          nationality: data.nationality || null,
          address: data.address || null,
          city: data.city || null,
          state: data.state || null,
          pin_code: data.pin_code || null,
          country: data.country || null,
          mobile_number: data.mobile_number,
          alternate_number: data.alternate_number || null,
          email: data.email || null,
          membership_type: data.membership_type,
          membership_number: data.membership_number,
        },
      ]);

      if (error) throw error;

      setSuccess("User registered successfully!");
      reset();
    } catch (err) {
      setError(err.message || "Something went wrong");
    } finally {
      setLoading(false);
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
            👤 Register New User
          </h1>
          <p className="text-gray-600">
            Add a new user to the system and assign membership benefits
          </p>
        </div>

        <Card className="shadow-lg border-0">
          <CardHeader>
            <CardTitle className="flex items-center gap-2">
              User Registration Form
            </CardTitle>
            <CardDescription>
              Fill in the user details below. Required fields are marked with an asterisk (*).
            </CardDescription>
          </CardHeader>
          <CardContent>
            <form onSubmit={handleSubmit(onSubmit)} className="space-y-8">
              
              {/* Personal Information Section */}
              <div>
                <h3 className="text-lg font-semibold text-gray-900 mb-4 flex items-center gap-2">
                  👥 Personal Information
                </h3>
                <div className="grid grid-cols-1 md:grid-cols-2 gap-4">
                  <div className="space-y-2">
                    <Label htmlFor="full_name">Full Name *</Label>
                    <Input
                      id="full_name"
                      placeholder="Enter full name"
                      {...register("full_name")}
                      className={errors.full_name ? "border-red-500" : ""}
                    />
                    {errors.full_name && (
                      <p className="text-sm text-red-500">{errors.full_name.message}</p>
                    )}
                  </div>

                  <div className="space-y-2">
                    <Label htmlFor="dob">Date of Birth</Label>
                    <Input
                      id="dob"
                      type="date"
                      {...register("dob")}
                    />
                  </div>

                  <div className="space-y-2">
                    <Label htmlFor="gender">Gender *</Label>
                    <Select onValueChange={(value) => setValue("gender", value)}>
                      <SelectTrigger className={errors.gender ? "border-red-500" : ""}>
                        <SelectValue placeholder="Select gender" />
                      </SelectTrigger>
                      <SelectContent>
                        <SelectItem value="Male">Male</SelectItem>
                        <SelectItem value="Female">Female</SelectItem>
                        <SelectItem value="Other">Other</SelectItem>
                      </SelectContent>
                    </Select>
                    {errors.gender && (
                      <p className="text-sm text-red-500">{errors.gender.message}</p>
                    )}
                  </div>

                  <div className="space-y-2">
                    <Label htmlFor="nationality">Nationality</Label>
                    <Input
                      id="nationality"
                      placeholder="Enter nationality"
                      {...register("nationality")}
                    />
                  </div>
                </div>
              </div>

              <Separator />

              {/* Address Information Section */}
              <div>
                <h3 className="text-lg font-semibold text-gray-900 mb-4 flex items-center gap-2">
                  🏠 Address Information
                </h3>
                <div className="grid grid-cols-1 md:grid-cols-2 gap-4">
                  <div className="space-y-2 md:col-span-2">
                    <Label htmlFor="address">Address</Label>
                    <Input
                      id="address"
                      placeholder="Enter full address"
                      {...register("address")}
                    />
                  </div>

                  <div className="space-y-2">
                    <Label htmlFor="city">City</Label>
                    <Input
                      id="city"
                      placeholder="Enter city"
                      {...register("city")}
                    />
                  </div>

                  <div className="space-y-2">
                    <Label htmlFor="state">State</Label>
                    <Input
                      id="state"
                      placeholder="Enter state"
                      {...register("state")}
                    />
                  </div>

                  <div className="space-y-2">
                    <Label htmlFor="pin_code">Pin Code</Label>
                    <Input
                      id="pin_code"
                      placeholder="Enter pin code"
                      {...register("pin_code")}
                    />
                  </div>

                  <div className="space-y-2">
                    <Label htmlFor="country">Country</Label>
                    <Input
                      id="country"
                      placeholder="Enter country"
                      {...register("country")}
                    />
                  </div>
                </div>
              </div>

              <Separator />

              {/* Contact Information Section */}
              <div>
                <h3 className="text-lg font-semibold text-gray-900 mb-4 flex items-center gap-2">
                  📞 Contact Information
                </h3>
                <div className="grid grid-cols-1 md:grid-cols-2 gap-4">
                  <div className="space-y-2">
                    <Label htmlFor="mobile_number">Mobile Number *</Label>
                    <Input
                      id="mobile_number"
                      placeholder="Enter mobile number"
                      {...register("mobile_number")}
                      className={errors.mobile_number ? "border-red-500" : ""}
                    />
                    {errors.mobile_number && (
                      <p className="text-sm text-red-500">{errors.mobile_number.message}</p>
                    )}
                  </div>

                  <div className="space-y-2">
                    <Label htmlFor="alternate_number">Alternate Number</Label>
                    <Input
                      id="alternate_number"
                      placeholder="Enter alternate number"
                      {...register("alternate_number")}
                    />
                  </div>

                  <div className="space-y-2 md:col-span-2">
                    <Label htmlFor="email">Email Address</Label>
                    <Input
                      id="email"
                      type="email"
                      placeholder="Enter email address"
                      {...register("email")}
                      className={errors.email ? "border-red-500" : ""}
                    />
                    {errors.email && (
                      <p className="text-sm text-red-500">{errors.email.message}</p>
                    )}
                  </div>
                </div>
              </div>

              <Separator />

              {/* Membership Information Section */}
              <div>
                <h3 className="text-lg font-semibold text-gray-900 mb-4 flex items-center gap-2">
                  💎 Membership Information
                </h3>
                <div className="grid grid-cols-1 md:grid-cols-2 gap-4">
                  <div className="space-y-2">
                    <Label htmlFor="membership_type">Membership Type *</Label>
                    <Select onValueChange={(value) => setValue("membership_type", value)}>
                      <SelectTrigger className={errors.membership_type ? "border-red-500" : ""}>
                        <SelectValue placeholder="Select membership type" />
                      </SelectTrigger>
                      <SelectContent>
                        <SelectItem value="Silver">Silver (10% discount)</SelectItem>
                        <SelectItem value="Gold">Gold (15% discount)</SelectItem>
                        <SelectItem value="Platinum">Platinum (20% discount)</SelectItem>
                        <SelectItem value="Corporate">Corporate (25% discount)</SelectItem>
                      </SelectContent>
                    </Select>
                    {membershipType && (
                      <Badge className={`${getMembershipColor(membershipType)} mt-2`}>
                        {membershipType} - {getMembershipDiscount(membershipType)} discount
                      </Badge>
                    )}
                    {errors.membership_type && (
                      <p className="text-sm text-red-500">{errors.membership_type.message}</p>
                    )}
                  </div>

                  <div className="space-y-2">
                    <Label htmlFor="membership_number">Membership Number (Auto-generated) *</Label>
                    <Input
                      id="membership_number"
                      placeholder="Will be auto-generated based on mobile number"
                      {...register("membership_number")}
                      readOnly
                      className="bg-gray-50 cursor-not-allowed"
                    />
                    <p className="text-sm text-gray-600">
                      Format: GSP{mobileNumber || "XXXXXXXXXX"}
                    </p>
                    {errors.membership_number && (
                      <p className="text-sm text-red-500">{errors.membership_number.message}</p>
                    )}
                  </div>
                </div>
              </div>

              {/* Submit Button */}
              <div className="flex flex-col sm:flex-row gap-4 pt-6">
                <Button
                  type="submit"
                  disabled={loading}
                  className="flex-1 bg-blue-600 hover:bg-blue-700"
                >
                  {loading ? (
                    <div className="flex items-center gap-2">
                      <div className="w-4 h-4 border-2 border-white border-t-transparent rounded-full animate-spin"></div>
                      Registering...
                    </div>
                  ) : (
                    "Register User"
                  )}
                </Button>
                <Button
                  type="button"
                  variant="outline"
                  onClick={() => reset()}
                  disabled={loading}
                  className="flex-1 sm:flex-none sm:w-32"
                >
                  Reset Form
                </Button>
              </div>

              {/* Success/Error Messages */}
              {success && (
                <Alert className="border-green-200 bg-green-50">
                  <AlertDescription className="text-green-800">
                    ✅ {success}
                  </AlertDescription>
                </Alert>
              )}
              {error && (
                <Alert className="border-red-200 bg-red-50">
                  <AlertDescription className="text-red-800">
                    ❌ {error}
                  </AlertDescription>
                </Alert>
              )}
            </form>
          </CardContent>
        </Card>
      </div>
    </div>
    </ProtectedRoute>
  );
}