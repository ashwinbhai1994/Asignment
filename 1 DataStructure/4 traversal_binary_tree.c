#include<stdio.h>
#include<stdlib.h>
struct tree
{
	int data;
	struct tree *right;
	struct tree *left;
};
struct tree* newnode(int data);
void preorder(struct tree *node);
void postorder(struct tree *node);
void inorder(struct tree *node);
int main()
{
	struct tree *root=NULL;
	root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->left=newnode(4);
	root->right->right=newnode(5);
	root->left->right=newnode(6);
	root->right->right=newnode(7);
	printf("preorder\n");
	preorder(root);
	printf("Postorder\n");
	postorder(root);
	printf("inorder\n");
	inorder(root);
	return 0;
}
struct tree* newnode(int data)
{
	struct tree* node=(struct tree*)malloc(sizeof(struct tree));
	node->data=data;
	node->right=NULL;
	node->left=NULL;
	return node;
}
void preorder(struct tree *node)
{
	if(node==NULL)
	{
		return ;
	}
	printf("%d\n",node->data);
	preorder(node->left);
	preorder(node->right);
}
void postorder(struct tree *node)
{
	if(node==NULL)
	{
		return ;
	}
	postorder(node->left);
	postorder(node->right);
	printf("%d\n",node->data);
}
void inorder(struct tree* node)
{
	if(node==NULL)
	{
		return ;
	}
	inorder(node->left);
	printf("%d\n",node->data);
	inorder(node->right);
}