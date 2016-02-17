//
//  main.c
//  nextPalindrome.c
//
//  Created by Bharadwaj on 17/02/16.
//  Copyright © 2016 Bharadwaj. All rights reserved.
//

#include <stdio.h>
#include<string.h>
#include<stdlib.h>
void even(int *i,int *j,int count);
void odd(int *i,int *j,int count);
void aboveNine(int *,int ,int ,int);
void Palindrome(int num[],int );
int main(int argc, const char * argv[]) {
    int i,j,count;
    long int l;
    scanf("%ld",&l);
    long int temp;
    temp=l;
    int num[10000]={0};
    while(l)
    {
        count++;
        l=l/10;
    }
    l=temp;
    num[count]=-1;
    int ccount=count;
   
    while(count--)
    {
        num[count]=l%10;
        l=l/10;
    }
    
    int f=0;
    count=ccount;
    
    j=count;
    i=-1;
    while(++i<=--j)
    {
        if(num[i]!=num[j])
        {
            break;
        }
    }
    if(j<i)
    {
        Palindrome(num,count);
    }
    else
    {
        if(count%2!=0)
        {
            odd(&i, &j, count);
        }
        else
        {
            even(&i, &j, count);
        }
        while(i>=0)
        {
            if(num[i]-num[j]>0)
            {
                f=1;
                break;
            }
            else if(num[i]-num[j]<0)
            {
                f=0;
                break;
            }
            i--;
            j++;
        }
        if(count%2 !=0)
        {
            odd(&i, &j, count);
        }
        else
        {
            even(&i, &j, count);
        }
        if(f==1)
        {
            while(i>=0)
            {
                num[j]=num[i];
                i--;
                j++;
            }
        }
        else if(f==0 && num[count/2]<9 && count%2!=0)
        {
            
            num[count/2]++;
            odd(&i, &j, count);
            while(i>=0)
            {
                num[j]=num[i];
                i--;
                j++;
            }
        }
        else
        {
            if(count%2!=0)
            {
                num[count/2]=0;
            }
            while(i>=0)
            {
                if(num[i]<9)
                {
                    num[i]++;
                    num[j]=num[i];
                    break;
                }
                else
                {
                    num[i]=0;
                    num[j]=0;
                }
                i--;
                j++;
            }
            while(i>=0)
            {
                num[j]=num[i];
                i--;
                j--;
            }
        }
        for(int p=0;num[p]!=-1;p++)
        {
            printf("%d",num[p]);
        }
        //printf("%s",num);
    }
    return 0;
}
void Palindrome(int num[],int count)
{
    
    int i,j;
    if(count%2!=0)
    {
        if(num[count/2] < 9)
        {
            
            num[count/2]++;
            for(int p=0;num[p]!=-1;p++)
            {
                printf("%d",num[p]);
            }
        }
        else
        {
            num[count/2]=0;
            odd(&i,&j,count);
            aboveNine(num,count,i,j);
        }
    }
    else
    {
        even( &i, &j, count);
        aboveNine(num, count, i, j);
    }
}
void odd(int *i,int *j,int count)
{
    *i=(count/2) - 1;
    *j=(count/2)+1;
    
}
void even(int *i,int *j,int count)
{
    *i=count/2 -1;
    *j=count/2;
}
void aboveNine(int num[],int count,int i,int j)
{
    while(i>=0)
    {
        if(num[i]<9)
        {
            num[i]++;
            num[j]++;
            break;
        }
        else
        {
            num[i]=num[j]=0;
        }
        i--;
        j++;
    }
    if(i<0)
    {
        printf("1");
        for(int k=1;k<count;k++)
        {
            printf("0");
        }
        printf("1");
    }
    else
    {
        for(int p=0;num[p]!=-1;p++)
        {
            printf("%d",num[p]);
        }
    }
}
