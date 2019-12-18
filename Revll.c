#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *link;
} *start=NULL, *temp, *ptr;
void insert(){
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter data.\n");
	scanf("%d", &temp->data);
	temp->link=NULL;
	if(start==NULL)
		start=temp;
	else{
		ptr=start;
		while(ptr->link!=NULL)
			ptr=ptr->link;
		ptr->link=temp;
	}
}
void reverse(){
	struct node *pre, *cur;
	if(start==NULL)
		printf("List is empty.\n");
	else{
		pre=start;
		cur=start->link;
		start=start->link;
		pre->link=NULL;
		while(start!=NULL){
			start=start->link;
			cur->link=pre;
			pre=cur;
			cur=start;
		}
		start=pre;
		printf("List has been reversed.\n");
	}
}
void display(){
	if(start==NULL)
		printf("List is empty.\n");
	else{
		ptr=start;
		while(ptr!=NULL){
			printf("%d-->", ptr->data);
			ptr=ptr->link;
		}
		printf("\n");
	}
}
void main(){
	int ch;
	printf("1. Insert\n2. Reverse\n3. Display\n4. Exit\n");
	while(1){
		printf("Enter your choice.\n");
		scanf("%d", &ch);
		switch(ch){
			case 1: insert();
				break;
			case 2: reverse();
				break;
			case 3: display();
				break;
			case 4: exit(0);
		}
	}
}
