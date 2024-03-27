#include <stdio.h>

// WAP to find the maximum frequency number in an array

int main(){
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements of the array: ");
    for(int i = 0; i<n; i++){
        scanf("%d", &a[i]);
    }
    int maxFreq = 0;
    int maxFreqNum = 0;
    for(int i = 0; i<n; i++){
        int freq = 1;
        for(int j = i+1; j<n; j++){
            if(a[i] == a[j]){
                freq++;
            }
        }
        if(freq > maxFreq){
            maxFreq = freq;
            maxFreqNum = a[i];
        }
    }
    printf("The maximum frequency number is %d with frequency %d\n", maxFreqNum, maxFreq);
    return 0;
}