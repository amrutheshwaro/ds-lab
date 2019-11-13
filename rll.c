#include<stdio.h>
#include<stdlib.h>
int i=0, count=0, a[30];
typedef struct node{
	int data;
	struct node *link;
};
struct node *ptr, *start=NULL, *cur, *temp1, *temp2;
void insert(){
	temp1=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data.\n");
	scanf("%d", &temp1->data);
	temp1->link=NULL;
	if(start==NULL)
		start=temp1;
	else{
		ptr=start;
		while(ptr->link!=NULL)
			ptr=ptr->link;
		ptr->link=temp1;
	}
}
void display(){
	if(start==NULL){
		printf("Linked list is empty.\n");
	}
	else{
		ptr=start;
		while(ptr!=NULL){					
			printf("%d-->", ptr->data);
			ptr=ptr->link;
		}
		printf("\n");
	}
}
void reverse(){
	if(start==NULL)
		printf("Linked list is empty.\n");
	else{
		ptr=start;
		while(ptr!=NULL){
			a[i]=ptr->data;
			ptr=ptr->link;
			++i;
		}
		count=i;
		ptr=start;
		for(i=count-1; ptr!=NULL; --i){
			ptr->data=a[i];
			ptr=ptr->link;
		}
		printf("The linked list has been reversed.\n");
	}
}
void main(){
	int ch;
	while(1){
		printf("Enter your choice.\n");
		printf("1. Insert\n2. Reverse\n3. Display\n4. Exit\n");
		scanf("%d", &ch);
		switch(ch){
			case 1: insert();
				break;
			case 2: reverse();
				break;
			case 3: display();
				break;
			case 4: exit(0);
			default: printf("Invalid choice.\n");
		}
	}
}		
