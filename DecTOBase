
#include<stdio.h>
void AllBase(int,int);
int main()
{
    int num,base;
    printf("Enter the number:");
    scanf("%d",&num);
    printf("Base");
    scanf("%d",&base);
    AllBase(num,base);
    return 0;
}
void AllBase(int n,int b)
{
    int q=1,r,i=0,j;
    char ans[100];
    while(q!=0)
    {
        q=n/b;
        r=n%b;
        if(r<10)
        {
            ans[i++]=r+48;
        }
        else
        {
            ans[i++]=r+55;
        }
        n=q;
    }
    for(j=i-1;j>=0;j--)
    {
        printf("%c",ans[j]);
    }
    printf("\n");
}
