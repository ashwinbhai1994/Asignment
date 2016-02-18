//
//  main.c
//  BinToReq
//
//

#include<stdio.h>
void baseConvert(int ,int );
int main()
{
    int num,b;
    printf("Enter the num\n");
    scanf("%d",&num);
    printf("\nEnter the base\n");
    scanf("%d",&b);
    baseConvert(num,b);
    return 0;
}
void baseConvert(int num,int base)
{
    int i=0,j,rem;
    char res[100];
    while(num!=0)
    {
        rem=num%base;
        if(rem<10)
        {
            res[i]=rem+'0';
        }
        else
        {
            res[i]=rem+55;
        }
        i++;
        num=num/base;
    }
    printf("Converted number is :\n");
    for(j=i-1;j>=0;j--)
    {
        printf("%c",res[j]);
    }
}