#include<stdio.h>
#include<stdlib.h>
#define size 5
int q[size], front=-1, rear=-1, item;
void insert(){
	if(rear==size-1)
		printf("Queue is full.\n");
	else{
		printf("Enter data.\n");
		scanf("%d", &item);
		if(front==-1&&rear==-1){
			front=0;
			rear=0;
		}
		else
			++rear;
		q[rear]=item;
	}
}
void delete(){
	if(front==-1)
		printf("Queue is empty.\n");
	else{
		if(front==rear){
			front=-1;
			rear=-1;
		}
		else
			++front;
	}
}
void display(){
	if(rear==-1)
		printf("Queue is empty.\n");
	else{
		int i;
		for(i=front; i<=rear; i++)
			printf("%d\t", q[i]);
		printf("\n");
	}
}
void main(){
	int ch;
	while(1){
		printf("Enter your choice.\n");
		printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
		scanf("%d", &ch);
		switch(ch){
			case 1: insert();
				break;
			case 2: delete();
				break;
			case 3: display();
				break;
			case 4: exit(0);
			default: printf("Invalid choice.\n");
				 break;
		}
	}
}
