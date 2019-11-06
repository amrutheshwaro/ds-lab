#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *llink, *rlink;
};
struct node *start=NULL, *ptr, *temp;
void insert_beg(){
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data.\n");
	scanf("%d", &temp->data);
	temp->rlink=NULL;
	temp->llink=NULL;
	if(start==NULL)
		start=temp;
	else{
		temp->rlink=start;
		start->llink=temp;
		start=temp;
	}
}
void delete_beg(){
	if(start==NULL)
		printf("Linked list is empty.\n");
	else{
		ptr=start;
		start=ptr->rlink;
		free(ptr);
	}
}
void insert_end(){
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data.\n");
	scanf("%d", &temp->data);
	temp->llink=NULL;
	temp->rlink=NULL;
	if(start==NULL)
		start=temp;
	else{
	ptr=start;
		while(ptr->rlink!=NULL)
			ptr=ptr->rlink;
		ptr->rlink=temp;
		temp->llink=ptr;
	}
}
void delete_end(){
	if(start==NULL)
		printf("Linked list is empty.\n");
	else if(start->rlink==NULL){
		free(start);
		start=NULL;
	}
	else{
		ptr=start;
		while(ptr->rlink!=NULL)
			ptr=ptr->rlink;
		ptr->llink->rlink=NULL;
		free(ptr);
	}
}
void insert_anyloc(){
	int count=0, pos, i;
	ptr=start;
	while(ptr!=NULL){
		++count;
		ptr=ptr->rlink;
	}
	printf("Enter the position.\n");
	scanf("%d", &pos);
	if(pos==1)
		insert_beg();
	else if(pos==count+1)
		insert_end();
	else if(pos>1&&pos<=count){
		temp=(struct node*)malloc(sizeof(struct node));
		printf("Enter the data.\n");
		scanf("%d", &temp->data);
		temp->rlink=NULL;
		temp->llink=NULL;
		ptr=start;
		for(i=1; i<pos-1; i++)
			ptr=ptr->rlink;
		temp->rlink=ptr->rlink;
		temp->llink=ptr;
		ptr->rlink->llink=temp;
		ptr->rlink=temp;
	}
	else{
			printf("Invalid position.\n");
	}
}
void delete_anyloc(){
	int count=0, pos, i;
	ptr=start;
	while(ptr!=NULL){
		++count;
		ptr=ptr->rlink;
	}
	printf("Enter the position.\n");
	scanf("%d", &pos);
	if(pos==1)
		delete_beg();
	else if(pos==count)
		delete_end();
	else if(pos>1&&pos<count){
		ptr=start;
		for(i=1; i<pos; i++)
			ptr=ptr->rlink;
		ptr->llink->rlink=ptr->rlink;
		ptr->rlink->llink=ptr->llink;
		free(ptr);
	}
	else
		printf("Invalid position.\n");
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
		printf("1. Insert_beg()\n2. Delete_beg()\n3. Insert_end()\n4. Delete_end()\n5. Insert_anyloc()\n6. Delete_anyloc()\n7. Display()\n8. Exit\n");
		scanf("%d", &ch);
		switch(ch){
			case 1: insert_beg();
				break;
			case 2: delete_beg();
				break;
			case 3: insert_end();
				break;
			case 4: delete_end();
				break;
			case 5: insert_anyloc();
				break;
			case 6: delete_anyloc();
				break;
			case 7: display();
				break;
			case 8: exit(0);
			default: printf("Invalid choice.");
				 exit(0);
		}
	}
}
