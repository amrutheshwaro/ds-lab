#include<stdio.h>
#include<stdlib.h>
int ch;
struct node{
	int data;
	struct node *ll, *rl;
} *root=NULL, *temp, *parent, *ptr;
void inorder(struct node *tree){
	if(tree!=NULL){
		inorder(tree->ll);
		printf("%d.", tree->data);
		inorder(tree->rl);
	}
}
void create(struct node *root){
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter data.\n");
	scanf("%d", &ch);
	temp->rl=NULL;
	temp->ll=NULL;
	temp->data=ch;
	ptr=root;
	if(ch>=0){
		while(ptr!=NULL){
			parent=ptr;
			if(ptr->data==temp->data){
				printf("Node exits.\n");
				create(root);
			}
			else if(temp->data<ptr->data)
				ptr=ptr->ll;
			else
				ptr=ptr->rl;
		}
		if(parent->data<temp->data){
			parent->rl=temp;
			create(root);
		}
		else{
			parent->ll=temp;
			create(root);
		}
	}
}
void main(){
	printf("Enter the binary search tree.\n");
	printf("Enter a negative data to complete binary search tree creation.\n");
	root=(struct node*)malloc(sizeof(struct node));
	printf("Enter data.\n");
	scanf("%d", &root->data);
	root->rl=NULL;
	root->ll=NULL;
	create(root);
	printf("The binary search  tree is\n");
	inorder(root);
	printf("\n");
}
	
	
