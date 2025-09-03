"use client";

import Link from "next/link";
import { Card, CardContent, CardDescription, CardHeader, CardTitle } from '@/components/ui/card';
import { Badge } from '@/components/ui/badge';
import ProtectedRoute from "@/components/ProtectedRoute";
import { useRouter } from "next/navigation";
import { supabase } from "@/lib/supabaseClient";

export default function DashboardPage() {

  const router = useRouter();

  const handleLogout = async () => {
    await supabase.auth.signOut();
    router.push("/login");
  };

  const menu = [
    {
      title: "Register User",
      description: "Add a new user and assign membership",
      href: "/users/register",
      color: "bg-blue-500",
      icon: "👤",
      badge: "Users"
    },
    {
      title: "New Payment",
      description: "Record a payment and apply membership discounts",
      href: "/payments/new",
      color: "bg-green-500",
      icon: "💳",
      badge: "Payments"
    },
    {
      title: "Reports",
      description: "View revenue, discounts, and membership stats",
      href: "/reports",
      color: "bg-purple-500",
      icon: "📊",
      badge: "Analytics"
    },
    {
      title: "Transactions",
      description: "View all transactions made by users",
      href: "/users/transactions",
      color: "bg-purple-500",
      icon: "📊",
      badge: "Analytics"
    },
  ];

  return (
    <ProtectedRoute>
    <div className="min-h-screen bg-gradient-to-br from-gray-50 to-gray-100 p-4 md:p-8">
      <div className="max-w-6xl mx-auto">
        {/* Header */}
        <div className="mb-8 justify-between">
          <h1 className="text-4xl font-bold text-gray-900 mb-2 flex items-center gap-3">
            🏨 Hotel Admin Dashboard
          </h1>
          <div className="flex items-center justify-between gap-4">
            <p className="text-gray-600 text-lg">
              Manage your hotel operations efficiently
            </p>
            <button
              onClick={handleLogout}
              className="bg-red-600 text-white px-4 py-2 rounded hover:bg-red-700"
            >
              Logout
            </button>
          </div>
        </div>

        {/* Dashboard Cards */}
        <div className="grid grid-cols-1 md:grid-cols-2 lg:grid-cols-3 gap-6">
          {menu.map((item) => (
            <Link
              key={item.href}
              href={item.href}
              className="block transition-transform hover:scale-105"
            >
              <Card className="h-full hover:shadow-lg transition-shadow duration-200 border-0 shadow-md">
                <CardHeader className="pb-4">
                  <div className="flex items-start justify-between">
                    <div className={`${item.color} w-14 h-14 rounded-xl flex items-center justify-center text-white shadow-lg`}>
                      <span className="text-2xl">{item.icon}</span>
                    </div>
                    <Badge variant="secondary" className="text-xs">
                      {item.badge}
                    </Badge>
                  </div>
                  <CardTitle className="text-xl font-semibold text-gray-900 mt-4">
                    {item.title}
                  </CardTitle>
                </CardHeader>
                <CardContent className="pt-0">
                  <CardDescription className="text-gray-600 leading-relaxed">
                    {item.description}
                  </CardDescription>
                  
                  {/* Hover indicator */}
                  <div className="mt-4 flex items-center text-sm text-gray-500 opacity-0 group-hover:opacity-100 transition-opacity">
                    <span>Click to continue</span>
                    <svg 
                      className="w-4 h-4 ml-1 transform transition-transform group-hover:translate-x-1" 
                      fill="none" 
                      stroke="currentColor" 
                      viewBox="0 0 24 24"
                    >
                      <path strokeLinecap="round" strokeLinejoin="round" strokeWidth={2} d="M9 5l7 7-7 7" />
                    </svg>
                  </div>
                </CardContent>
              </Card>
            </Link>
          ))}
        </div>
      </div>
    </div>
    </ProtectedRoute>
  );
}