#include<stdio.h>
int main(){
	int n, i;
	printf("Size of array:");
	scanf("%d", &n);
	int arr[n];
	for(i=0; i<n; i++){
		printf("Enter %d element of array:", i+1);
		scanf("%d", &arr[i]);
	}
	printf("---------------------------\n");
	printf("\nElements of an array:\n");
	int *ptr = arr;
	for(i=0; i<n; i++){
		printf("%d ", *ptr);
		ptr++;
	}
}
