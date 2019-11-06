#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *ll, *rl;
};
struct node *root, *temp;
int ll(int data){
	int ch;
	printf("Do you want to insert a left link to  %d?\n", data);
	printf("Press 1. Yes 2. No\n");
	scanf("%d", &ch);
	if(ch==1)
		return 1;
	else
		return 0;
}
int rl(int data){
	int ch;
	printf("Do you want to insert a right link to  %d?\n", data);
	printf("Press 1. Yes 2. No\n");
	scanf("%d", &ch);
	if(ch==1)
		return 1;
	else
		return 0;
}
void insert_child(struct node *tree){
	temp=(struct node*)malloc(sizeof(struct node));
	if(ll(tree->data)==1){
		temp=(struct node*)malloc(sizeof(struct node));
		printf("Enter the data.\n");
		scanf("%d", &temp->data);
		tree->ll=temp;
		insert_child(temp);
	}
	else
		tree->ll=NULL;
	if(rl(tree->data)==1){
		temp=(struct node*)malloc(sizeof(struct node));
		printf("Enter the data.\n");
		scanf("%d", &temp->data);
		tree->rl=temp;
		insert_child(temp);
	}
	else{
		tree->rl=NULL;
		insert_child(tree);
	}
}	
void main(){
	root=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data.\n");
	scanf("%d", &root->data);
	root->ll=NULL;
	root->rl=NULL;
	insert_child(root);
}
			
