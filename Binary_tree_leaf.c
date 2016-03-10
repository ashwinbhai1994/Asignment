#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node* left;
    struct node* right;
    int val;
};
int sum=0;
struct node* root;
int isleaf(struct node *root);
void inorder(struct node *root);
void insert(int val, struct node **root);
int main()
{
    int digit=0;
    printf("Enter the elements! To end enter 0\n");
    scanf("%d",&digit);
    while(digit!=0)
    {
        insert(digit, &root);
        scanf("%d",&digit);
    }
    inorder(root);
    printf("%d",sum);
    return 0;
}
void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        if(isleaf(root))
        {
            sum=sum+(root->val);
        }
        inorder(root->right);
    }
    
}
int isleaf(struct node *root)
{
    if(root->left==NULL && root->right==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void insert(int val, struct node **root)
{
    if(*root == NULL )
    {
        *root = (struct node*) malloc( sizeof( struct node ) );
        (*root)->val = val;
        (*root)->left = NULL;
        (*root)->right = NULL;
    }
    else if(val < (*root)->val)
    {
        insert( val, &(*root)->left );
    }
    else if(val > (*root)->val)
    {
        insert( val, &(*root)->right );
    }
}
