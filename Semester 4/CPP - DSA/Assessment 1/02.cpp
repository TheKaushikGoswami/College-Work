// Write a C++ program to sort a vector without using sort function.

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    int n;
    cout << "Enter the number of elements in the vector: ";
    cin >> n;
    cout << "Enter the elements of the vector: ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
    cout << "The sorted vector is: ";
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}