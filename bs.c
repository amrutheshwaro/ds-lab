#include<stdio.h>
int a[30], n, i, key, result;
int bs(int A[], int low, int high, int  key){
	int mid=(low+high)/2;
	if(low>high){
		return -1;
	}
	else{
		if(A[mid]==key)
			return mid+1;
		else if(mid>key)
			return bs(A, low, mid-1, key);
		else if(mid<key)
			return bs(A, mid+1, high, key);
	}
}
void main(){
	printf("Enter the size of the sorted array.\n");
	scanf("%d", &n);
	printf("Enter the elements of the sorted array (ascending order).\n");
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);
	printf("Enter the element to  be  searched.\n");
	scanf("%d", &key);
	result= bs(a, 0, n-1, key);
	if(result==-1)
		printf("The key is not found.\n");
	else
		printf("The key %d is found at location %d.\n", key, result);
}
