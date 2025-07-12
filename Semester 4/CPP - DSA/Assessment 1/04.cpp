// Write a C++ program to calculate the suffix array sum and prefix array sum for a given input array.

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    vector<int> prefixSum(n), suffixSum(n);
    prefixSum[0] = v[0];
    suffixSum[n - 1] = v[n - 1];
    for (int i = 1; i < n; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + v[i];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        suffixSum[i] = suffixSum[i + 1] + v[i];
    }
    cout << "The prefix array sum is: ";
    for (int i = 0; i < n; i++)
    {
        cout << prefixSum[i] << " ";
    }
    cout << endl;
    cout << "The suffix array sum is: ";
    for (int i = 0; i < n; i++)
    {
        cout << suffixSum[i] << " ";
    }
    return 0;
}