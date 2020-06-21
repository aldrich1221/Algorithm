#include<stdio.h>
struct tree{
	int data;
	struct tree *left;
	struct tree *right;
}

typedef struct tree treenode;
typedef treenode *binarytree;

binarytree insertnode(binarytree root,int value);

	
	


binarytree createBinaryTree(int*data,int len);

void inorder(binarytree ptr);

void preorder(binarytree ptr);
void postorder(binarytree ptr)