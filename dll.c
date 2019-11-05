#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *llink, *rlink;
};
struct node *start=NULL, *ptr, *temp;
void insert_beg(){
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the element.\n");
	scanf("%d", &temp->data);
	temp->rlink=NULL;
	temp->llink=NULL;
	if(start==NULL)
		start=temp;
	else{
		temp->llink=start;
		start->rlink=temp;
		start=temp;
	}
}
void delete_beg(){
	if(start==NULL){
		printf("Linked list is empty.\n");
		exit(0);
	}
	else{
		ptr=start;
		start=ptr->llink;
		free(ptr);
	}
}
void display(){
	int ch, i;
	if(start==NULL){
		printf("Linked list is empty.\n");
		exit(0);
	}
	else{
		ptr=start;
		for(i=0; ptr!=NULL; i++){
			printf("%d\n", ptr->data);
			ptr=ptr->llink;
		}
	}	
}
void main(){
	int ch;
	while(1){
		printf("Enter your choice.\n");
		printf("1. Insert_beg()\n2. Delete_beg\n7. Display()\n");
		scanf("%d", &ch);
		switch(ch){
			case 1: insert_beg();
				break;
			case 2: delete_beg();
				break;
			case 7: display();
				break;
			default: printf("Invalid option chosen.");
				 exit(0);
		}
	}
}

