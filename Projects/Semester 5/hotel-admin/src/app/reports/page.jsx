"use client";

import { useEffect, useState } from "react";
import Link from "next/link";
import { Card, CardContent, CardDescription, CardHeader, CardTitle } from '@/components/ui/card';
import { Badge } from '@/components/ui/badge';
import { Button } from '@/components/ui/button';
import { Tabs, TabsContent, TabsList, TabsTrigger } from '@/components/ui/tabs';
import { Alert, AlertDescription } from '@/components/ui/alert';
import {
  BarChart, Bar, XAxis, YAxis, Tooltip, Legend, ResponsiveContainer,
  PieChart, Pie, Cell, LineChart, Line, AreaChart, Area
} from "recharts";
import { supabase } from "../../lib/supabaseClient";
import { Dialog, DialogTrigger, DialogContent, DialogHeader, DialogTitle } from "@/components/ui/dialog";
import ProtectedRoute from "@/components/ProtectedRoute";

export default function ReportsPage() {
  const [payments, setPayments] = useState([]);
  const [users, setUsers] = useState([]);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState(null);
  
  async function fetchData() {
    try {
      setLoading(true);
      
      // Fetch payments data from Supabase
      const { data: paymentData, error: paymentError } = await supabase
        .from("payments")
        .select("total_amount, discount_price, to_be_paid, created_at, user_id")
        .order('created_at', { ascending: true });

      if (paymentError) {
        throw new Error(`Failed to fetch payments: ${paymentError.message}`);
      }

      // Fetch users data from Supabase
      const { data: userData, error: userError } = await supabase
        .from("users")
        .select("id, membership_type, email, mobile_number, city, state, membership_number, full_name");

      if (userError) {
        throw new Error(`Failed to fetch users: ${userError.message}`);
      }

      setPayments(paymentData || []);
      setUsers(userData || []);
    } catch (err) {
      console.error('Error fetching data:', err);
      setError(err.message || "Failed to fetch data");
    } finally {
      setLoading(false);
    }
  }
  useEffect(() => {
    fetchData();
  }, []);

  // Calculate totals
  const totalRevenue = payments.reduce((sum, p) => sum + Number(p.to_be_paid || 0), 0);
  const totalDiscounts = payments.reduce((sum, p) => sum + Number(p.discount_price || 0), 0);
  const averageOrderValue = payments.length > 0 ? totalRevenue / payments.length : 0;

  // Revenue trend (grouped by date)
  const revenueByDate = Object.values(
    payments.reduce((acc, p) => {
      const date = new Date(p.created_at).toLocaleDateString();
      if (!acc[date]) acc[date] = { date, revenue: 0, discount: 0 };
      acc[date].revenue += Number(p.to_be_paid || 0);
      acc[date].discount += Number(p.discount_price || 0);
      return acc;
    }, {})
  );

  // Membership distribution
  const membershipCounts = Object.values(
    users.reduce((acc, u) => {
      const type = u.membership_type || "None";
      if (!acc[type]) acc[type] = { name: type, value: 0 };
      acc[type].value += 1;
      return acc;
    }, {})
  );

  // Calculate users who made payments (for active members metric)
  const usersWhoMadePayments = new Set(payments.map(p => p.user_id).filter(Boolean));

  const COLORS = ["#0088FE", "#00C49F", "#FFBB28", "#FF8042", "#8884d8"];

  const getMembershipColor = (type) => {
    const colors = {
      Silver: "bg-gray-100 text-gray-800",
      Gold: "bg-yellow-100 text-yellow-800",
      Platinum: "bg-purple-100 text-purple-800",
      Corporate: "bg-blue-100 text-blue-800"
    };
    return colors[type] || "bg-gray-100 text-gray-800";
  };

  // Refresh data function
  const handleRefresh = async () => {
    setError(null);
    await fetchData();
  };

  // Export data function (basic implementation)
  const handleExportData = () => {
    const exportData = {
      summary: {
        totalRevenue,
        totalDiscounts,
        totalPayments: payments.length,
        totalUsers: users.length,
        averageOrderValue
      },
      payments: payments,
      users: users,
      membershipDistribution: membershipCounts,
      revenueByDate: revenueByDate
    };
    
    const dataStr = JSON.stringify(exportData, null, 2);
    const dataUri = 'data:application/json;charset=utf-8,'+ encodeURIComponent(dataStr);
    
    const exportFileDefaultName = `reports-${new Date().toISOString().split('T')[0]}.json`;
    
    const linkElement = document.createElement('a');
    linkElement.setAttribute('href', dataUri);
    linkElement.setAttribute('download', exportFileDefaultName);
    linkElement.click();
  };

  if (loading) {
    return (
      <div className="min-h-screen bg-gradient-to-br from-gray-50 to-gray-100 p-4 md:p-8">
        <div className="max-w-7xl mx-auto">
          <div className="flex items-center justify-center h-64">
            <div className="flex items-center gap-2">
              <div className="w-6 h-6 border-2 border-blue-600 border-t-transparent rounded-full animate-spin"></div>
              <span className="text-gray-600">Loading reports...</span>
            </div>
          </div>
        </div>
      </div>
    );
  }

  // Calculate active users per membership type
  const activeUsersByMembership = users.reduce((acc, user) => {
    const type = user.membership_type || "None";
    if (!acc[type]) acc[type] = new Set();
    // Find if this user has made a payment
    const hasPayment = payments.some(p => p.user_id === user.id);
    if (hasPayment) acc[type].add(user.id);
    return acc;
  }, {});

  return (
    <ProtectedRoute>
    <div className="min-h-screen bg-gradient-to-br from-gray-50 to-gray-100 p-4 md:p-8">
      <div className="max-w-7xl mx-auto">
        {/* Header */}
        <div className="mb-8"></div>
          <Link href="/" className="text-sm text-gray-600 hover:text-gray-900 mb-4 inline-flex items-center">
            ← Back to Dashboard
          </Link>
          <div className="flex flex-col sm:flex-row sm:items-center sm:justify-between gap-4">
            <div>
              <h1 className="text-3xl font-bold text-gray-900 mb-2 flex items-center gap-3">
                📊 Reports Dashboard
              </h1>
              <p className="text-gray-600">
                Track revenue, discounts, and membership analytics
              </p>
            </div>
            <div className="flex gap-2"></div>
              <Button variant="outline" size="sm" onClick={handleExportData}>
                Export Data
              </Button>
              <Button size="sm" onClick={handleRefresh} disabled={loading}>
                {loading ? 'Loading...' : 'Refresh'}
              </Button>
            </div>
          </div>

        {error && (
          <Alert className="border-red-200 bg-red-50 mb-6">
            <AlertDescription className="text-red-800">
              ❌ {error}
            </AlertDescription>
          </Alert>
        )}

        {/* No Data State */}
        {!loading && payments.length === 0 && users.length === 0 && (
          <Alert className="border-yellow-200 bg-yellow-50 mb-6">
            <AlertDescription className="text-yellow-800">
              ⚠️ No data available. Please check your database connection and ensure you have data in your payments and users tables.
            </AlertDescription>
          </Alert>
        )}

        {/* Summary Cards */}
        <div className="grid grid-cols-1 md:grid-cols-2 lg:grid-cols-4 gap-6 mb-8">
          <Card className="bg-gradient-to-r from-green-500 to-green-600 text-white border-0 shadow-lg">
            <CardContent className="p-6">
              <div className="flex items-center justify-between">
                <div>
                  <p className="text-green-100 text-sm font-medium">Total Revenue</p>
                  <p className="text-3xl font-bold">₹{totalRevenue.toFixed(2)}</p>
                </div>
                <div className="text-green-200 text-2xl">💰</div>
              </div>
              <p className="text-green-100 text-xs mt-2">
                From {payments.length} payments
              </p>
            </CardContent>
          </Card>

          <Card className="bg-gradient-to-r from-red-500 to-red-600 text-white border-0 shadow-lg">
            <CardContent className="p-6">
              <div className="flex items-center justify-between">
                <div>
                  <p className="text-red-100 text-sm font-medium">Total Discounts</p>
                  <p className="text-3xl font-bold">₹{totalDiscounts.toFixed(2)}</p>
                </div>
                <div className="text-red-200 text-2xl">🎫</div>
              </div>
              <p className="text-red-100 text-xs mt-2">
                {totalRevenue + totalDiscounts > 0 
                  ? ((totalDiscounts / (totalRevenue + totalDiscounts)) * 100).toFixed(1)
                  : 0}% of gross revenue
              </p>
            </CardContent>
          </Card>

          <Card className="bg-gradient-to-r from-blue-500 to-blue-600 text-white border-0 shadow-lg">
            <CardContent className="p-6">
              <div className="flex items-center justify-between">
                <div>
                  <p className="text-blue-100 text-sm font-medium">Total Payments</p>
                  <p className="text-3xl font-bold">{payments.length}</p>
                </div>
                <div className="text-blue-200 text-2xl">💳</div>
              </div>
              <p className="text-blue-100 text-xs mt-2">
                Avg: ₹{averageOrderValue.toFixed(2)} per order
              </p>
            </CardContent>
          </Card>

          <Card className="bg-gradient-to-r from-purple-500 to-purple-600 text-white border-0 shadow-lg">
            <CardContent className="p-6">
              <div className="flex items-center justify-between">
                <div>
                  <p className="text-purple-100 text-sm font-medium">Total Users</p>
                  <p className="text-3xl font-bold">{users.length}</p>
                </div>
                <div className="text-purple-200 text-2xl">👥</div>
              </div>
              <p className="text-purple-100 text-xs mt-2">
                Registered members
              </p>
            </CardContent>
          </Card>
        </div>

        {/* Charts Section */}
        <Tabs defaultValue="revenue" className="space-y-6">
          <TabsList className="grid w-full grid-cols-3">
            <TabsTrigger value="revenue">Revenue Analytics</TabsTrigger>
            <TabsTrigger value="membership">Membership Stats</TabsTrigger>
            <TabsTrigger value="trends">Trend Analysis</TabsTrigger>
          </TabsList>

          <TabsContent value="revenue" className="space-y-6">
            <div className="grid grid-cols-1 lg:grid-cols-2 gap-6">
              <Card className="shadow-lg border-0">
                <CardHeader>
                  <CardTitle className="flex items-center gap-2">
                    📈 Daily Revenue Trend
                  </CardTitle>
                  <CardDescription>
                    Revenue and discounts over time
                  </CardDescription>
                </CardHeader>
                <CardContent>
                  {revenueByDate.length > 0 ? (
                    <ResponsiveContainer width="100%" height={300}>
                      <AreaChart data={revenueByDate}>
                        <XAxis dataKey="date" />
                        <YAxis />
                        <Tooltip formatter={(value) => [`₹${value}`, '']} />
                        <Legend />
                        <Area
                          type="monotone"
                          dataKey="revenue"
                          stackId="1"
                          stroke="#82ca9d"
                          fill="#82ca9d"
                          name="Revenue"
                        />
                        <Area
                          type="monotone"
                          dataKey="discount"
                          stackId="2"
                          stroke="#ff7c7c"
                          fill="#ff7c7c"
                          name="Discounts"
                        />
                      </AreaChart>
                    </ResponsiveContainer>
                  ) : (
                    <div className="h-300 flex items-center justify-center text-gray-500">
                      No revenue data available
                    </div>
                  )}
                </CardContent>
              </Card>

              <Card className="shadow-lg border-0">
                <CardHeader>
                  <CardTitle className="flex items-center gap-2">
                    📊 Revenue vs Discounts
                  </CardTitle>
                  <CardDescription>
                    Comparison of revenue and discount amounts
                  </CardDescription>
                </CardHeader>
                <CardContent>
                  {revenueByDate.length > 0 ? (
                    <ResponsiveContainer width="100%" height={300}>
                      <BarChart data={revenueByDate}>
                        <XAxis dataKey="date" />
                        <YAxis />
                        <Tooltip formatter={(value) => [`₹${value}`, '']} />
                        <Legend />
                        <Bar dataKey="revenue" fill="#82ca9d" name="Revenue" />
                        <Bar dataKey="discount" fill="#ff7c7c" name="Discounts" />
                      </BarChart>
                    </ResponsiveContainer>
                  ) : (
                    <div className="h-300 flex items-center justify-center text-gray-500">
                      No revenue data available
                    </div>
                  )}
                </CardContent>
              </Card>
            </div>
          </TabsContent>

          <TabsContent value="membership" className="space-y-6">
            <div className="grid grid-cols-1 lg:grid-cols-2 gap-6">
              <Card className="shadow-lg border-0">
                <CardHeader>
                  <CardTitle className="flex items-center gap-2">
                    💎 Membership Distribution
                  </CardTitle>
                  <CardDescription>
                    Breakdown of membership types
                  </CardDescription>
                </CardHeader>
                <CardContent>
                  {membershipCounts.length > 0 ? (
                    <ResponsiveContainer width="100%" height={300}>
                      <PieChart>
                        <Pie
                          data={membershipCounts}
                          cx="50%"
                          cy="50%"
                          labelLine={false}
                          outerRadius={120}
                          fill="#8884d8"
                          dataKey="value"
                          label={(entry) => `${entry.name}: ${entry.value}`}
                        >
                          {membershipCounts.map((entry, index) => (
                            <Cell key={`cell-${index}`} fill={COLORS[index % COLORS.length]} />
                          ))}
                        </Pie>
                        <Tooltip />
                      </PieChart>
                    </ResponsiveContainer>
                  ) : (
                    <div className="h-300 flex items-center justify-center text-gray-500">
                      No membership data available
                    </div>
                  )}
                </CardContent>
              </Card>

              <Card className="shadow-lg border-0">
                <CardHeader>
                  <CardTitle className="flex items-center gap-2">
                    🎯 Membership Details
                  </CardTitle>
                  <CardDescription>
                    Detailed membership breakdown (with active users)
                  </CardDescription>
                </CardHeader>
                <CardContent>
                  {membershipCounts.length > 0 ? (
                    <div className="space-y-4">
                      {membershipCounts.map((membership, index) => {
                        const activeCount = activeUsersByMembership[membership.name]?.size || 0;
                        return (
                          <div key={membership.name} className="flex items-center justify-between p-3 bg-gray-50 rounded-lg">
                          <div className="flex items-center gap-3">
                            <div
                            className="w-4 h-4 rounded-full"
                            style={{ backgroundColor: COLORS[index % COLORS.length] }}
                            ></div>
                            <span className="font-medium">{membership.name}</span>
                          </div>
                          <div className="flex items-center gap-2">
                            {/* DialogTrigger for user list */}
<Dialog>
  <DialogTrigger asChild>
    <Badge
      className={getMembershipColor(membership.name) + " cursor-pointer"}
      title={`View users with ${membership.name} membership`}
    >
      {membership.value} users
    </Badge>
  </DialogTrigger>
  <DialogContent className="max-w-3xl">
    <DialogHeader>
      <DialogTitle>
        Users with {membership.name} membership
      </DialogTitle>
    </DialogHeader>

    <div className="max-h-80 overflow-y-auto mt-4">
      {users
        .filter((u) => (u.membership_type || "None") === membership.name)
        .map((u) => (
          <div
            key={u.id}
            className="p-3 rounded-lg bg-gray-50 border mb-2 shadow-sm"
          >
            <p className="font-semibold text-gray-900">{u.full_name}</p>
            <p className="text-sm text-gray-600">{u.email || "N/A"}</p>
            <p className="text-sm text-gray-600">{u.mobile_number}</p>
            <p className="text-sm text-gray-600">{u.city}, {u.state}</p>
            <p className="text-sm text-gray-600">{u.membership_number}</p>
          </div>
        ))}

      {users.filter((u) => (u.membership_type || "None") === membership.name).length === 0 && (
        <div className="text-gray-500 text-sm">No users found.</div>
      )}
    </div>
  </DialogContent>
</Dialog>

                            <span className="text-sm text-gray-500">
                            {users.length > 0 
                              ? ((membership.value / users.length) * 100).toFixed(1)
                              : 0}% total
                            </span>
                            <Badge variant="outline" className="ml-2 border-green-400 text-green-700">
                            Active: {activeCount}
                            </Badge>
                          </div>
                          </div>
                        );
                      })}
                    </div>
                  ) : (
                    <div className="text-center text-gray-500 py-8">
                      No membership data available
                    </div>
                  )}
                </CardContent>
              </Card>
            </div>
          </TabsContent>

          <TabsContent value="trends" className="space-y-6">
            <Card className="shadow-lg border-0">
              <CardHeader>
                <CardTitle className="flex items-center gap-2">
                  📈 Performance Trends
                </CardTitle>
                <CardDescription>
                  Revenue performance over time
                </CardDescription>
              </CardHeader>
              <CardContent>
                {revenueByDate.length > 0 ? (
                  <ResponsiveContainer width="100%" height={400}>
                    <LineChart data={revenueByDate}>
                      <XAxis dataKey="date" />
                      <YAxis />
                      <Tooltip formatter={(value) => [`₹${value}`, '']} />
                      <Legend />
                      <Line
                        type="monotone"
                        dataKey="revenue"
                        stroke="#8884d8"
                        strokeWidth={3}
                        dot={{ fill: '#8884d8', strokeWidth: 2, r: 6 }}
                        name="Revenue"
                      />
                      <Line
                        type="monotone"
                        dataKey="discount"
                        stroke="#ff7c7c"
                        strokeWidth={2}
                        strokeDasharray="5 5"
                        name="Discounts"
                      />
                    </LineChart>
                  </ResponsiveContainer>
                ) : (
                  <div className="h-400 flex items-center justify-center text-gray-500">
                    No trend data available
                  </div>
                )}
              </CardContent>
            </Card>
          </TabsContent>
        </Tabs>
      </div>
      </ProtectedRoute>
  );
}