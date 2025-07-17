#include <bits/stdc++.h>
using namespace std;

int sumOfDigits(int x){
    int sum = 0;

    while(x!=0){
        sum+=x%10;
        x=x/10;
    }

    return sum;
}

int main(){

    int n;
    cin >> n;

    cout << sumOfDigits(n);

    return 0;

}