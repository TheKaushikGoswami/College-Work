#include<stdio.h>

// Write a program to sort this array:
// a[10] = { 10, 9, 7, 101, 23, 44, 12, 78, 34, 23}; then search element 34 using binary search algorithm

void bubbleSort(int a[], int n){
	for(int i = 0; i<n-1; i++){
		for(int j = 0; j<n-i-1; j++){
			if(a[j] > a[j+1]){
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}

int binarySearch(int a[], int n, int key){
	int low = 0;
	int high = n-1;
	while(low <= high){
		int mid = (low + high)/2;
		if(a[mid] == key){
			return mid;
		}else if(a[mid] < key){
			low = mid + 1;
		}else{
			high = mid - 1;
		}
	}
	return -1;
}

int main(){
	
	int a[10] = { 10, 9, 7, 101, 23, 44, 12, 78, 34, 23};
	int n = 10;
	int key = 34;

	bubbleSort(a, n);

	int index = binarySearch(a, n, key);
	if(index != -1){
		printf("Element found at index %d\n", index);
	}else{
		printf("Element not found\n");
	}

	return 0;

}

