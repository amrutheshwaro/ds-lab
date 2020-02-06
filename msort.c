#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void combine(int a[], int low, int mid, int high){
	int b[1000], k=low, i=low, j=mid+1;
	while(i<=mid&&j<=high){
		if(a[i]<=a[j])
			b[k++]=a[i++];
		else
			b[k++]=a[j++];
	}
	while(i<=mid)
		b[k++]=a[i++];
	while(j<=high)
		b[k++]=a[j++];
	for(k=low; k<=high; k++)
		a[k]=b[k];
}
void mergesort(int a[], int l, int h){
	int m=(l+h)/2;
	int b[1000];
	if(l<h){
		mergesort(a, l, m);
		mergesort(a, m+1, h);
		combine(a, l, m, h);
	}
}
void main(){
	int a[1000], n, i, l, h;
	printf("Enter the number of elements.\n");
	scanf("%d", &n);
	printf("Enter the elements.\n");
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);
	l=0;
	h=n-1;
	mergesort(a, l, h);
	printf("The sorted array is\n");
	for(i=0; i<n; i++)
		printf("%d\n", a[i]);
}
