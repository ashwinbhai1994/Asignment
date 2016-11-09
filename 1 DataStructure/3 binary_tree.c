#include<stdio.h>
#include<stdlib.h>
struct tree
{
	int data;
	struct tree *left;
	struct tree *right;
};
struct tree* newNode(int data)
{
	struct tree *node=(struct tree*)malloc(sizeof(struct tree));
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	return node;
}
int main()
{
	struct tree *root=newNode(1);
	root->left=newNode(2);
	root->right=newNode(9);
	root->left=newNode(10);
	return 0;
}