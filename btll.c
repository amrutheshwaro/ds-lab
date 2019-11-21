#include<stdio.h>
#include<stdlib.h>
int ch, i;
struct node{
	int data;
	struct node *ll, *rl;
} *root, *temp;
int ll(struct node *tree){
	printf("Do you want to insert a left link to  %d?\n", tree->data);
	printf("Press 1. Yes 2. No\n");
	scanf("%d", &ch);
	return ch;
}
int rl(struct node *tree){
	printf("Do you want to insert a right link to  %d?\n", tree->data);
	printf("Press 1. Yes 2. No\n");
	scanf("%d", &ch);
	return ch;
}
void insert_child(struct node *tree){
	if(ll(tree)==1){
		temp=(struct node*)malloc(sizeof(struct node));
		printf("Enter the data.\n");
		scanf("%d", &temp->data);
		tree->ll=temp;
		insert_child(temp);
	}
	else
		tree->ll=NULL;
	if(rl(tree)==1){
		temp=(struct node*)malloc(sizeof(struct node));
		printf("Enter the data.\n");
		scanf("%d", &temp->data);
		tree->rl=temp;
		insert_child(temp);
	}
	else
		tree->rl=NULL;
}
void display(struct node *root, int space, int height){ 
	if(root==NULL)
		return;
	space+=height;
	display(root->rl, space, height);
	printf("\n");
	for(i=height; i<space; i++)
		printf("  ");
	printf("%d\n", root->data);
	display(root->ll, space, height);
}
void inorder(struct node *tree){
	if(tree!=NULL){
		inorder(tree->ll);
		printf("%d.", tree->data);
		inorder(tree->rl);
	}
}
void preorder(struct node *tree){
	if(tree!=NULL){
		printf("%d.", tree->data);
		preorder(tree->ll);
		preorder(tree->rl);
	}
}
void postorder(struct node *tree){
	if(tree!=NULL){
		postorder(tree->ll);
		postorder(tree->rl);
		printf("%d.", tree->data);
	}
}	
void main(){
	root=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data.\n");
	scanf("%d", &root->data);
	root->ll=NULL;
	root->rl=NULL;
	insert_child(root);
	printf("Binary tree representation in  2D.\n");
	display(root, 0, 10);
	printf("The binary tree representation in:\n");
	printf("Inorder.\n");
	inorder(root);
	printf("\n");
	printf("Preorder.\n");
	preorder(root);
	printf("\n");
	printf("Postorder.\n");
	postorder(root);
	printf("\n");
}	
			
