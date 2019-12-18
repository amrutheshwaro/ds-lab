#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int data, sum=0;
struct term{
	int coeff, power;
	struct term *link;
} *temp, *start=NULL, *ptr, *cur;
void insert(){
	temp=(struct term*)malloc(sizeof(struct term));
	printf("Enter the coefficient and degree of the polynomial term.\n");
	scanf("%d%d", &temp->coeff, &data);
	temp->power=data;
	temp->link=NULL;
	if(start==NULL)
		start=temp;
	else if(start->link==NULL&&start->power<temp->power){
		temp->link=start;
		start=temp;
	}
	else if(start->link==NULL&&start->power==temp->power)
		start->coeff+=temp->coeff;
	else if(start->link==NULL&&start->power>temp->power)
		start->link=temp;
	else if(start->link!=NULL){
		ptr=start;
		while(ptr->link!=NULL&&ptr->power>temp->power){
			cur=ptr;
			ptr=ptr->link;
		}
		if(ptr->power==temp->power)
			ptr->coeff+=temp->coeff;
		else if(ptr->power<temp->power){
			if(ptr==start){
				temp->link=start;
				start=temp;
			}
			else{
				temp->link=cur->link;
				cur->link=temp;
			}
		}
		else if(ptr->link==NULL&&ptr->power>temp->power)
			ptr->link=temp;
	}
	if(data>0)
		insert();
}
void display(){
	if(start==NULL){
		printf("No equation.\n");
	}
	else{
		ptr=start;
		while(ptr!=NULL){					
			printf("%d.x^%d+", ptr->coeff, ptr->power);
			ptr=ptr->link;
		}
		printf("\n");
	}
}
void evaluate(){
	printf("Enter the value of x.\n");
	scanf("%d", &data);
	ptr=start;
	while(ptr!=NULL){
		sum+=(ptr->coeff*pow(data, ptr->power));
		ptr=ptr->link;
	}
	printf("Value of the expression is %d.\n", sum);
}
void main(){
	printf("Enter term with power zero to complete entering the polynomial expression.\n");
	insert();
	display();
	evaluate();
}
