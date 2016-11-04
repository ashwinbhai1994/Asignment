#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *next;
};
void printlist(struct Node **head);
void push(struct Node **head,int data);
void reverse(struct Node **head);
int main()
{
	struct Node *head=NULL;
	push(&head,11);
	push(&head,22);
	push(&head,33);
	push(&head,44);
	reverse(&head);
	printlist(&head);
	return 0;
}
void reverse(struct Node **head)
{
	struct Node *next,*current,*prev;
	prev=NULL;
	current=*head;
	while(current!=NULL)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
	*head=prev;
}	
void printlist(struct Node **head)
{
	struct Node *temp=*head;
	while(temp!=NULL)
	{
		printf("%d\n",(temp)->data);
		temp=temp->next;
	}
}
void push(struct Node **head,int data)
{
	struct Node *node=(struct Node*)malloc(sizeof(struct Node));
	node->data=data;
	node->next=*head;
	*head=node;
}
