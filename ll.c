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
	ptr=start;
	start=start->link;
	free(ptr);
}

void display(){
	int count=0;
	ptr=start;
	while(ptr->link!=NULL){
		count++;
		ptr=ptr->link;	
	}
	if(count<0){
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
		printf("1. Insert_Beg\n2. Delete_Beg\n3. Display\n");
		scanf("%d", &ch);
		switch(ch){
			case 1: insert_beg();
				break;
			case 2: delete_beg();
				break;
			case 3: display();
				break;
			default: printf("Invalid choice.\n");
				 exit(0);
		}
	}
}
