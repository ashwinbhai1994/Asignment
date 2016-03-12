struct tree
{
    struct tree *left;
    struct tree *right;
    int val;
};
#include<stdio.h>
#include<stdlib.h>
typedef struct tree node1;
node1* createnode(int num);
int sumn(node1 *temp);

int main()
{ 
    int sum=0;
    int left=0;
    int right=0;
    node1 *root=createnode(26);
    root->left=createnode(10);
    root->right=createnode(3);
    root->left->left=createnode(4);
    root->left->right=createnode(6);
    root->right->left=createnode(3);
    node1 *temp=root;
    
    int ls=sumn(temp->left);
    int rs=sumn(temp->right);
    sum=ls+rs;
    printf("%d\n",sum);
    return 0;
}
int sumn(node1 *temp)
{
    int ss=0;
    
    if(temp!=NULL && (temp->left!=NULL && temp->right==NULL))
    {
        ss=sumn(temp->left)+temp->val+sumn(temp->right);
        return ss;
    }
    else if(temp->left==NULL && temp->right==NULL)
    {
        return temp->val;
    }
    else 
    {
        return 0;
    }
}
node1* createnode(int num)
{
    node1 *temp=(node1*)malloc(sizeof(node1));
    temp->left=NULL;
    temp->right=NULL;
    temp->val=num;
    return temp;
}
