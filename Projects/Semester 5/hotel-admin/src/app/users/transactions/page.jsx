"use client";

import { useState } from "react";
import { Card, CardContent, CardHeader, CardTitle, CardDescription } from '@/components/ui/card';
import { Input } from '@/components/ui/input';
import { Button } from '@/components/ui/button';
import { supabase } from '../../../lib/supabaseClient';
import Link from "next/link";
import ProtectedRoute from "@/components/ProtectedRoute";

export default function TransactionsPage() {
  const [mobile, setMobile] = useState("");
  const [transactions, setTransactions] = useState([]);
  const [user, setUser] = useState(null);
  const [loading, setLoading] = useState(false);
  const [error, setError] = useState(null);

  const handleSearch = async (e) => {
    e.preventDefault();
    setLoading(true);
    setError(null);
    setTransactions([]);
    setUser(null);

    try {
      // Find user by mobile number
      const { data: users, error: userError } = await supabase
        .from("users")
        .select("id, full_name, mobile_number, membership_type")
        .eq("mobile_number", mobile);

      if (userError) throw userError;
      if (!users || users.length === 0) {
        setError("No user found with this mobile number.");
        setLoading(false);
        return;
      }
      setUser(users[0]);

      // Fetch transactions for user (by user id)
      const { data: txs, error: txError } = await supabase
        .from("payments")
        .select("*")
        .eq("user_id", users[0].id)
        .order("created_at", { ascending: false });

      if (txError) throw txError;

      // Normalize to always have created_by
      const normalizedTxs = (txs || []).map(tx => ({
        ...tx,
        created_by: tx.created_by ?? "NULL",
      }));

      setTransactions(normalizedTxs);
    } catch (err) {
      setError(err.message || "Something went wrong");
    } finally {
      setLoading(false);
    }
  };

  return (
    <ProtectedRoute>
      <div className="min-h-screen bg-gradient-to-br from-gray-50 to-gray-100 p-4 md:p-8">
        <div className="max-w-2xl mx-auto">
          <Link href="/" className="text-sm text-gray-600 hover:text-gray-900 mb-4 inline-flex items-center">
            ← Back to Dashboard
          </Link>

          {/* Search Card */}
          <Card className="mb-8">
            <CardHeader>
              <CardTitle>🔍 Search User Transactions</CardTitle>
              <CardDescription>
                Enter a mobile number to view all transactions for that user.
              </CardDescription>
            </CardHeader>
            <CardContent>
              <form onSubmit={handleSearch} className="flex gap-2 items-end">
                <Input
                  type="text"
                  placeholder="Enter mobile number"
                  value={mobile}
                  onChange={e => setMobile(e.target.value)}
                  className="max-w-xs"
                  required
                />
                <Button type="submit" disabled={loading}>
                  {loading ? "Searching..." : "Search"}
                </Button>
              </form>
              {error && <div className="text-red-500 mt-2">{error}</div>}
            </CardContent>
          </Card>

          {/* User Info */}
          {user && (
            <Card className="mb-6">
              <CardHeader>
                <CardTitle>User Details</CardTitle>
                <CardDescription>
                  <span className="font-semibold">{user.full_name}</span> ({user.membership_type})
                  <br />
                  Mobile: {user.mobile_number}
                </CardDescription>
              </CardHeader>
            </Card>
          )}

          {/* Transactions Table */}
          {transactions.length > 0 && (
            <Card>
              <CardHeader>
                <CardTitle>Transactions ({transactions.length})</CardTitle>
              </CardHeader>
              <CardContent>
                <div className="overflow-x-auto">
                  <table className="min-w-full text-sm border">
                    <thead>
                      <tr className="bg-gray-100">
                        {Object.keys(transactions[0]).map(key => (
                          <th key={key} className="px-3 py-2 border-b text-left">
                            {key.replaceAll("_", " ").toUpperCase()}
                          </th>
                        ))}
                      </tr>
                    </thead>
                    <tbody>
                      {transactions.map((tx, i) => (
                        <tr key={tx.id || i} className="even:bg-gray-50">
                          {Object.values(tx).map((val, j) => (
                            <td key={j} className="px-3 py-2 border-b">
                              {String(val)}
                            </td>
                          ))}
                        </tr>
                      ))}
                    </tbody>
                  </table>
                </div>
              </CardContent>
            </Card>
          )}

          {/* No transactions */}
          {user && transactions.length === 0 && !loading && !error && (
            <div className="text-gray-500 text-center">
              No transactions found for this user.
            </div>
          )}
        </div>
      </div>
    </ProtectedRoute>
  );
}