#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *ll, *rl;
};
struct node *start=NULL, *ptr, *temp, *cur;
void insert(){
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter data.\n");
	scanf("%d", &temp->data);
	temp->ll=NULL;
	temp->rl=NULL;
	if(start==NULL)
		start=temp;
	else{
		ptr=start;
		while(ptr->rl!=NULL)
			ptr=ptr->rl;
		ptr->rl=temp;
		temp->ll=ptr;
	}
}
void display(){
	if(start==NULL){
		printf("Linked list is empty.\n");
		exit(0);
	}
	else{
		ptr=start;
		while(ptr!=NULL){					
			printf("%d-->", ptr->data);
			ptr=ptr->rl;
		}
		printf("\n");
	}
}
void del(){
	printf("After deletion.\n");
	int count=0;
	ptr=start;
	while(ptr->rl!=NULL){
		cur=ptr;
		ptr=ptr->rl;
		if(count%2!=0){
			cur->ll->rl=ptr;
			ptr->ll=cur->ll;
			free(cur);
			cur=NULL;
		}
		++count;
	}
	if(count%2!=0&&ptr->rl==NULL){
			cur->rl=NULL;
			free(ptr);
	}
}
void main(){
	int ch;	
	while(1){
		printf("Enter your choice.\n");
		printf("1. Insert()\n2. Delete even nodes.\n3. Exit\n");
		scanf("%d", &ch);
		switch(ch){
			case 1: insert();
				break;
			case 2: printf("Before deletion.\n");
				display();
				del();
				display();
				exit(0);
			case 3: exit(0);
			default: printf("Invalid choice.\n");
				 break;
		}
	}
}

