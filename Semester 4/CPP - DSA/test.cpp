// Time Limit: 2 sec / Memory Limit: 1024 MB

// Score : 
// 150 points

// Problem Statement
// You are given an integer sequence 
// A=(A1,A2​,A3,A4,A5) obtained by permuting 
// (1,2,3,4,5).

// Determine whether 
// A can be sorted in ascending order by performing exactly one operation of swapping two adjacent elements in 
// A.

// Constraints
// A is an integer sequence of length 
// 5 obtained by permuting 
// (1,2,3,4,5).
// Input
// The input is given from Standard Input in the following format:

// A 
// 1
// ​
  
// A 
// 2
// ​
  
// A 
// 3
// ​
  
// A 
// 4
// ​
  
// A 
// 5
// ​
 
// Output
// If 
// A can be sorted in ascending order by exactly one operation, print Yes; otherwise, print No.

// Sample Input 1
// Copy
// 1 2 4 3 5
// Sample Output 1
// Copy
// Yes
// By swapping 
// A 
// 3
// ​
//   and 
// A 
// 4
// ​
//  , 
// A becomes 
// (1,2,3,4,5), so it can be sorted in ascending order. Therefore, print Yes.

// Sample Input 2
// Copy
// 5 3 2 4 1
// Sample Output 2
// Copy
// No
// No matter what operation is performed, it is impossible to sort 
// A in ascending order.

// Sample Input 3
// Copy
// 1 2 3 4 5
// Sample Output 3
// Copy
// No
// You must perform exactly one operation.

// Sample Input 4
// Copy
// 2 1 3 4 5
// Sample Output 4
// Copy
// Yes

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a(5);
    for (int i = 0; i < 5; i++) {
        cin >> a[i];
    }
    bool flag=false;
    for (int i = 0; i < 4; i++) {
        if (a[i] > a[i + 1]) {
            swap(a[i], a[i + 1]);
            flag=true;
            break;
        }
    }
    for (int i = 0; i < 5; i++) {
        if (a[i] != i + 1) {
            cout << "No" << endl;
            return 0;
        }
    }
    if(flag==false)
        cout<<"No"<<endl;
    else
        cout << "Yes" << endl;
    return 0;
}