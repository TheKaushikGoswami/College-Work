// Write a c++ program to calculate the Fibonacci series using (a) loop approach and (b) recursion approach.

#include <iostream>
using namespace std;

int fibonacciLoop(int n)
{
    int a = 0, b = 1, c;
    if (n == 0)
    {
        return a;
    }
    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int fibonacciRecursion(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return fibonacciRecursion(n - 1) + fibonacciRecursion(n - 2);
}

int main()
{
    int n;
    cout << "Enter the number of terms: ";
    cin >> n;
    cout << "The Fibonacci series using loop approach is: ";
    for (int i = 0; i < n; i++)
    {
        cout << fibonacciLoop(i) << " ";
    }
    cout << endl;
    cout << "The Fibonacci series using recursion approach is: ";
    for (int i = 0; i < n; i++)
    {
        cout << fibonacciRecursion(i) << " ";
    }
    return 0;
}