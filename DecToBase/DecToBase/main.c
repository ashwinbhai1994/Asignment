//
//  main.c
//  DecToBase
//
//  Created by Bharadwaj on 25/01/16.
//  Copyright © 2016 Bharadwaj. All rights reserved.
//

#include<stdio.h>
void baseConversion(int,int);
int main()
{
    int num,base;
    printf("Enter the number:");
    scanf("%d",&num);
    printf("Enter the base:");
    scanf("%d",&base);
    baseConversion(num,base);
    return 0;
}
void baseConversion(int num,int base)
{
    int quo=1,rem,i=0,j;
    char conv[128];
    while(quo!=0)
    {
        quo=num/base;
        rem=num%base;
        if(rem<=9)
        {
            conv[i++]=rem+48;//used to convert n to 'n'
        }
        else
        {
            conv[i++]=rem+55;
        }
        num=quo;
    }
    for(j=i-1;j>=0;j--)
    {
        printf("%c",conv[j]);
    }
    printf("\n");
}

