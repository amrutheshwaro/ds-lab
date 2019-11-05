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
}void delete_beg(){
	if(start==NULL){
		printf("Empty list.\n");
		exit(0);
	}
	else{
		ptr=start;
		start=ptr->link;
		free(ptr);
	}
}
void insert_end(){
	temp=(struct node*)malloc(sizeof(struct node));
	ptr=start;
	while(ptr->link!=NULL){
		ptr=ptr->link;
	}
	printf("Enter the data.\n");
	scanf("%d", &temp->data);
	temp->link=NULL;
	if(start==NULL)
		start=temp;
	else
		ptr->link=temp;
}					
void delete_end(){
	struct node *cur;
	ptr=start;
	while(ptr->link!=NULL){
		cur=ptr;
		ptr=ptr->link;
	}
	if(cur->link==NULL)
		printf("Empty list.\n");
	else{	
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
	else if(pos==count)
		insert_end();
	else{
		temp=(struct node*)malloc(sizeof(struct node));
		printf("Enter the data.\n");
		scanf("%d", &temp->data);
		temp->link=NULL;
		ptr=start;
		for(i=0; i<pos; i++)
			ptr=ptr->link;
		temp->link=ptr->link;
		ptr->link=temp;
	}
}	
void display(){
	int count=0;
	ptr=start;
	while(ptr!=NULL){
		++count;
		ptr=ptr->link;	
	}
	if(count==0){
		printf("Linked list is empty.\n");
		exit(0);
	}
	else{
		ptr=start;
		for(i=0; i<=count; i++){
			printf("%d\n", ptr->data);
			ptr=ptr->link;
		}
	}
}
void main(){
	int ch;
	for(;;){
		printf("Enter your choice.\n");
		printf("1. Insert_Beg\n2. Delete_Beg\n3. Insert_end\n4. Delete_end\n5. Insert_anyloc\n6. Display\n");
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
			case 6: display();
				break;
			default: printf("Invalid choice.\n");
				 exit(0);
		}
	}
}
