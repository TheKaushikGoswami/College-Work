// Producer - Consumer Problem

#include <stdio.h>

int main(){
    int n, i, j, k;
    printf("Enter the number of producers: ");
    scanf("%d", &n);
    printf("Enter the number of consumers: ");
    scanf("%d", &k);
    int buffer[n], in = 0, out = 0, item = 0;
    for(i = 0; i < n; i++){
        buffer[i] = 0;
    }
    for(i = 0; i < n; i++){
        if(item < n){
            buffer[in] = item;
            printf("Producer %d produced item %d\n", i+1, item);
            in = (in + 1) % n;
            item++;
        }
        if(item == n){
            break;
        }
    }
    for(i = 0; i < k; i++){
        if(item > 0){
            printf("Consumer %d consumed item %d\n", i+1, buffer[out]);
            buffer[out] = 0;
            out = (out + 1) % n;
            item--;
        }
        if(item == 0){
            break;
        }
    }
    return 0;
}