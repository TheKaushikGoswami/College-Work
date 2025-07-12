// Write a C++ Program to apply multiplication of matrices of two matrices considering the conditions required for multiplication of 2 matrices in terms of matrix size.

#include <iostream>
using namespace std;

int main()
{
    int a[10][10], b[10][10], c[10][10];
    int r1, c1, r2, c2;
    cout << "Enter the number of rows and columns of the first matrix: ";
    cin >> r1 >> c1;
    cout << "Enter the number of rows and columns of the second matrix: ";
    cin >> r2 >> c2;
    if (c1 != r2)
    {
        cout << "The matrices cannot be multiplied with each other.";
        return 0;
    }
    cout << "Enter the elements of the first matrix: ";
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << "Enter the elements of the second matrix: ";
    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            cin >> b[i][j];
        }
    }
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < c1; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    cout << "The resultant matrix is: " << endl;
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}