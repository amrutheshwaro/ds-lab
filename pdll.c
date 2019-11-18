#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *rl, *ll;
};
struct node *start=NULL, *end=NULL, *ptr, *temp;
int count=0, i, data;
void insert(){
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter single digit integers.\n");
	scanf("%d", &data);
	if(data>9||data<0)
		insert();
	else{
		temp->data=data;
		temp->rl=NULL;
		temp->ll=NULL;
		if(start==NULL){
			start=temp;
			end=temp;
			++count;
		}
		else{
			ptr=start;
			while(ptr->rl!=NULL)
				ptr=ptr->rl;
			ptr->rl=temp;
			temp->ll=ptr;
			end=temp;
			++count;
		}
	}
}
void display(){
	int ch, i;
	if(start==NULL)
		printf("Linked list is empty.\n");
	else{
		printf("Linked list is\n");
		ptr=start;
		while(ptr!=NULL){
			printf("%d", ptr->data);
			ptr=ptr->rl;
		}
		printf("\n");
	}	
}
void pal(){
	if(start==NULL){
		exit(0);
	}
	else if(end->data==start->data){
		printf("Palindrome.\n");
		exit(0);
	}
	else
		for(i=0; i<=count/2; i++){
			if(start->data==end->data){
				start=start->rl;
				end=end->ll;
				continue;
			}
			else{
				printf("Not a palindrome.\n");
				exit(0);
			}
		}
	if(i==count/2)
		printf("Palindrome.\n");
	exit(0);
}
void main(){
	int ch;
	while(1){
		printf("Enter your choice.\n");
		printf("1. Insert()\n2. Check()\n3. Exit()\n");
		scanf("%d", &ch);
		switch(ch){
			case 1: insert();	
				break;
			case 2: display();
				pal();
				break;
			case 3: exit(0);
			default: printf("Invalid choice.\n");
		}
	}
}
	

