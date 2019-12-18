#include<stdio.h>
#include<stdlib.h>
#define size 5
int pq[size], rear=-1, front=-1, i, j, data;
void check(int data){
	for(i=front; i<=rear; i++){
		if(data>=pq[i]){
			for(j=rear+1; j>i; j--)
				pq[j]=pq[j-1];
			pq[i]=data;
		}
		return;
	}
	pq[i]=data;
}
void insert(){
	if(rear>=size-1)
		printf("Queue is full.\n");
	else{
		printf("Enter data.\n");
		scanf("%d", &data);
		if(front==-1&&rear==-1){
			front=0;
			rear=0;
			pq[rear]=data;
			return;
		}
		else
			check(data);
		rear++;
	}
}
void delete(){
	if(front==-1&&rear==-1)
		printf("Queue is empty.\n");
	else{
		if(front==rear){
			front=-1;
			rear=-1;
		}
		else
			front++;
	}
}
void display(){
	if(rear==-1)
		printf("Queue is empty.\n");
	else{
		for(i=front; i<=rear; i++)
			printf("%d--", pq[i]);
		printf("\n");
	}
}
void main(){
	int ch;
	printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
	while(1){
		printf("Enter your choice.\n");
		scanf("%d", &ch);
		switch(ch){
			case 1: insert();
				break;
			case 2: delete();
				break;
			case 3: display();
				break;
			case 4: exit(0);
		}
	}
}
