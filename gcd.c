#include<stdio.h>
int gcd(int a, int b){
	if(a==b)
		return a;
	else{
		while(a!=b){
			if(a>b)
				return gcd(a-b, b);
			else
				return gcd(a, b-a);
		}
	}
}
void main(){
	int a, b;
	printf("Enter the two numbers.\n");
	scanf("%d%d", &a, &b);
	printf("GCD= %d\n", gcd(a,b));
}
