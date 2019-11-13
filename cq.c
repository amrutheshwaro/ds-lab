#include<stdio.h>
#include<stdlib.h>
#define size 5
int cq[size], i, front=-1, rear=-1, item;
void insert(){
	if(rear==(front-1)||(front==0&&rear==(size-1)))
		printf("Overflow.\n");
	else{
		printf("Enter the element.\n");
		scanf("%d", &item);
		if(front==-1&&rear==-1)
			front=0;
		rear=(rear+1)%size;
		cq[rear]=item;
	}
}
void delete(){
	if(front==-1&&rear==-1)
		printf("Underflow.\n");
	else{
		if(front==rear){
			front=-1;
			rear=-1;
		}
		else
			front=(front+1)%size;
	}
}
void display(){
	if(rear==-1&&front==-1)
		printf("Circular queue is empty.\n");
	else{
		for(i=front; i!=rear; i=(i+1)%size)
			printf("%d--", cq[i]);
		printf("%d\n", cq[i]);
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
			default: printf("Invalid choice\n");
				 break;
		}
	}
}
