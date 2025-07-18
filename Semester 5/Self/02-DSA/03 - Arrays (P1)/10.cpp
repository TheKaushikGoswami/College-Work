// Print intersection of 2 Arrays

#include <bits/stdc++.h>
using namespace std;

void printIntersection(int a1[], int s1, int a2[], int s2){
    for(int i=0; i<s1; i++){
        for(int j=0; j<s2; j++){
            if(a1[i] == a2[j]){
                cout << a1[i] << " ";
            }
        }
    }
}

int main(){

    int a1[] = {4, 3, 6, 7, 5};
    int a2[] = {1, 2, 3, 4, 5};

    printIntersection(a1, 5, a2, 5);

    return 0;
}