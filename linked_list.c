//C linked List
struct node
{
    int value;
    struct node *next;
};
typedef struct node node1;
#include<stdio.h>
#include<stdlib.h>
void insertans(int );
void insertatbeg(int );
void insertatbeg1(int num);
int delfirst1();
int delans();
int delfirst();
int rev();
node1 *afront;
node1 *front1;
node1 *front2;
int main()
{
    int rem=0;
    int n1;
    int temp;
    int temp2;
    int n2;
    int res=0;
    int ch=0;
    int ans;
    int f=1;
    int carry=0;
    printf("Enter two numbers");
    scanf("%d %d",&n1,&n2);
    temp=rev(n1);
    temp2=rev(n2);
    n1=temp;
    n2=temp2;
    while(n1!=0)
    {
        rem=n1%10;
        insertatbeg(rem);
        n1=n1/10;
    }
    while(n2!=0)
    {
        rem=n2%10;
        insertatbeg1(rem);
        n2=n2/10;
    }
    while(front1 !=NULL || front2!=NULL)
    {
        ans=delfirst()+delfirst1();
        if(ans>10||ans==10)
        {
            res=carry+ans%10;
            insertans(res);
            carry=ans/10;
        }
        else
        {
            res=carry+ans;
            insertans(res);
            carry=0;
        }
    }
    if(carry)
    {
        insertans(carry);
    }
    while(f)
    {
        temp=delans();
        if(temp==-1)
        {
            break;
        }
        ch=ch*10+temp;
    }
    printf("%d\n",ch);
    return 0;
}
void insertans(int num)
{

    node1 *temp;
    temp=(node1*)malloc(sizeof(node1));
    temp->value=num;
    if(afront==NULL)
    {
        temp->next=NULL;
        afront=temp;
    }
    else
    {
        temp->next=afront;
        afront=temp;
    }
}
int delans()
{
    int ans=0;
    node1 *delptr;
    if(afront==NULL)
    {
        return -1;
    }
    else
    {
        delptr=afront;
        afront=afront->next;
        ans=(delptr->value);
        free(delptr);
        return ans;
    }
}



int delfirst1()
{
    int ans=0;
    node1 *delptr;
    if(front2==NULL)
    {
        return 0;
    }
    else
    {
        delptr=front2;
        front2=front2->next;
        ans=(delptr->value);
        free(delptr);
        return ans;
    }
}
int delfirst()
{
    int ans=0;
    node1 *delptr;
    if(front1==NULL)
    {
        return 0;
    }
    else
    {
        delptr=front1;
        front1=front1->next;
        ans= (delptr->value);
        free(delptr);
        return ans;
    }
}

void insertatbeg1(int num)
{
    node1 *temp;
    temp=(node1*)malloc(sizeof(node1));
    temp->value=num;
    if(front2==NULL)
    {
        temp->next=NULL;
        front2=temp;
    }
    else
    {
        temp->next=front2;
        front2=temp;
    }
}
void insertatbeg(int num)
{
    node1 *temp;
    temp=(node1*)malloc(sizeof(node1));
    temp->value=num;
    if(front1==NULL)
    {
        temp->next=NULL;
        front1=temp;
    }
    else
    {
        temp->next=front1;
        front1=temp;
    }
}
int rev(int n)
{
    int rem=0;
    int rev=0;
    while(n)
    {
        rem=n%10;
        rev=rev*10+rem;
        n=n/10;
    }
    return rev;
}
