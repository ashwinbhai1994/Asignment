#include<stdio.h>
#include<stdlib.h>
struct stack
{
	int num;
	struct stack *next;
};
void push(struct stack **root,int data);
void print(struct stack *root);
void pop(struct stack **root);
int main()
{
	struct stack *head=NULL;
	push(&head,10);
	push(&head,20);
	push(&head,30);
	push(&head,40);
	push(&head,50);
	push(&head,60);
	print(head);
	pop(&head);
	print(head);
	return 0;
}
void push(struct stack **root,int data)
{
	struct stack *node=(struct stack*)malloc(sizeof(struct stack));
	node->num=data;
	node->next=(*root);
	(*root)=node;
}
void pop(struct stack **root)
{
	struct stack *temp=*root;
	*root=(*root)->next;
	int pop=temp->num;
	printf("%d is the element being poped]\n", pop);

	free(temp);
}
void print(struct stack *root)
{
	while(root!=NULL)
	{
		printf("%d is the element \n",(root)->num);
		root=(root)->next;
	}
}