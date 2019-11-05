#include<stdio.h>
#include<stdlib.h>
int i=0;
typedef struct node{
	int data;
	struct node *link;
};
struct node *start=NULL, *ptr, *temp;

void insert_beg(){
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data.\n");
	scanf("%d", &temp->data);
	temp->link=NULL;
	if(start==NULL)
		start=temp;
	else{
		temp->link=start;
		start=temp;
	}
}
void delete_beg(){
	if(start==NULL)
		printf("Linked list is empty.\n");
	else{
		ptr=start;
		start=ptr->link;
		free(ptr);
	}
}
void insert_end(){
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data.\n");
	scanf("%d", &temp->data);
	temp->link=NULL;
	if(start==NULL)
		start=temp;
	else{
		ptr=start;
		while(ptr->link!=NULL){
		ptr=ptr->link;
		}
		ptr->link=temp;
	}
}					
void delete_end(){
	if(start==NULL)
		printf("Linked list is empty.\n");
	else if(start->link==NULL){
		free(start);
		start=NULL;
	}
	else{
		struct node *cur;
		ptr=start;
		while(ptr->link!=NULL){
			cur=ptr;
			ptr=ptr->link;
		}
		cur->link=NULL;
		free(ptr);
	}
}
void insert_anyloc(){
	int count=0, pos, i;
	ptr=start;
	while(ptr!=NULL){
		++count;
		ptr=ptr->link;
	}
	printf("Enter the position.\n");
	scanf("%d", &pos);
	if(pos==1)
		insert_beg();
	else if(pos==count+1)
		insert_end();
	else if(pos>1&&pos<count+1){
		temp=(struct node*)malloc(sizeof(struct node));
		printf("Enter the data.\n");
		scanf("%d", &temp->data);
		temp->link=NULL;
		ptr=start;
		for(i=1; i<pos-1; i++)
			ptr=ptr->link;
		temp->link=ptr->link;
		ptr->link=temp;
	}
	else
		printf("Invalid position.\n");
}	
void delete_anyloc(){
	int count=0, pos, i;
	ptr=start;
	while(ptr!=NULL){
		++count;
		ptr=ptr->link;
	}
	printf("Enter the position.\n");
	scanf("%d", &pos);
	if(pos==1)
		delete_beg();
	else if(pos==count+1)
		delete_end();
	else if(pos>1&&pos<=count){
		ptr=start;
		struct node *cur;
		for(i=1; i<pos;i++){
			cur=ptr;
			ptr=ptr->link;
		}
		cur->link=ptr->link;
		free(ptr);
	}
	else
		printf("Invalid position.\n");
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
void main(){
	int ch;
	while(1){
		printf("Enter your choice.\n");
		printf("1. Insert_Beg\n2. Delete_Beg\n3. Insert_end\n4. Delete_end\n5. Insert_anyloc\n6. Delete_anyloc\n7. Display\n8. Exit\n");
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
			default: printf("Invalid choice.\n");
		}
	}
}
