#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *llink, *rlink;
};
struct node *start=NULL, *ptr, *temp;
void insert(){
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data.\n");
	scanf("%d", &temp->data);
	temp->rlink=NULL;
	temp->llink=NULL;
	ptr=start;
	if(start==NULL)
		start=temp;
	else{
		ptr=start;
		while(ptr->rlink!=NULL&&ptr->data<temp->data)
			ptr=ptr->rlink;
		if(ptr->data<temp->data&&ptr->rlink==NULL){
			ptr->rlink=temp;
			temp->llink=ptr;
		}
		else{
			ptr->llink->rlink=temp;
			temp->rlink=ptr->rlink;
			ptr->llink=temp;
			temp->rlink=ptr;	
		}
	}
}
void display(){
	int ch, i;
	if(start==NULL)
		printf("Linked list is empty.\n");
	else{
		ptr=start;
		while(ptr!=NULL){
			printf("%d<-->", ptr->data);
			ptr=ptr->rlink;
		}
		printf("\n");
	}	
}
void main(){
	int ch;
	while(1){
		printf("Enter your choice.\n");
		printf("1. Insert()\n2. Display()\n3. Exit\n");
		scanf("%d", &ch);
		switch(ch){
			case 1: insert();
				break;
			case 2: display();
				break;
			case 3: exit(0);
			default: printf("Invalid choice.");
				 exit(0);
		}
	}
}
