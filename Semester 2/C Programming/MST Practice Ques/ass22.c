#include<stdio.h>
int binarySearch(int arr[], int size, int element){
	int low = 0, high = size-1;
	while(low<=high){
		int mid = (low+high)/2;
		if(arr[mid] == element){
			return mid;
		}
		else if(arr[mid] < element){
			low = mid + 1;
		}
		else{
			high = mid - 1;
		}
	}
	return -1;
}

int main(){
	int arr[] = { 10, 9, 7, 101, 23, 44, 12, 78, 34, 23};
	int size = sizeof(arr)/sizeof(arr[0]);
//	printf("%d", arr[8]);
	int element = 44;
	int index = binarySearch(arr, size, element);
	if(index == -1){
		printf("Element not found");
	}
	else{
		printf("Element is at index: %d", index);
	}
	return 0;
}

