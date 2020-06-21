#include<stdio.h>
#include<stdlib.h>
struct tree{
	int data;
	struct tree *left;
	struct tree *right;
};

typedef struct tree treenode;
typedef treenode *binarytree;

binarytree insertnode(binarytree root,int value){

	binarytree newnode;
	binarytree current;
	binarytree previous;

	newnode=(binarytree)malloc(sizeof(treenode));
	newnode->data=value;
	newnode->left=NULL;
	newnode->right=NULL;
	if (root==NULL){
		return newnode;
	}
	else{
		current=root;
		while(current!=NULL){
			previous=current;
			if(current->data>value){
				current=current->left;
			}
			else{
				current=current->right;
			}
		}
		if(previous->data>value){
			previous->left=newnode;
		}
		else{
			previous->right=newnode;
		}
	}
	return root;
}

binarytree createBinaryTree(int*data,int length){
	binarytree root=NULL;
	int i;
	for(i=0;i<length;i++){
		root=insertnode(root,data[i]);
	}
	return root;
}

void inorder(binarytree ptr){
	if(ptr!=NULL){
		inorder(ptr->left);
		printf("[%2d]",ptr->data);
		inorder(ptr->right);

	}
}
void preorder(binarytree ptr){
	if(ptr!=NULL){
		printf("[%2d]",ptr->data);
		preorder(ptr->left);
		preorder(ptr->right);

	}
}
void postorder(binarytree ptr){
	if(ptr!=NULL){
		
		postorder(ptr->left);
		postorder(ptr->right);
		printf("[%2d]",ptr->data);
	}
}

int main(){
	binarytree root=NULL;
	int data[9]={25,64,42,86,722,32,74,11,92};
	root=createBinaryTree(data,9);
	printf("inorder: ");
	inorder(root);
	printf("\n");

	printf("preorder: ");
	preorder(root);
	printf("\n");

	printf("postorder: ");
	postorder(root);
	printf("\n");

}
