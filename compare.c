#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int m=7;
int n=4;
void countone(int ,char str[m][n],int *,int);

void counttwo(int ,char str[m][n],int *,int);
int main()
{
    char str[7][4]={"1","3","11","100","19","2","5"};
    int len=sizeof(str)/sizeof(str[0]);
    int i,j;
    int m=7,n=4;
    int c[7];
   
    int count=0;
    for(i=0;i<len;i++)
    {
        for(j=0;str[i][j]!=0;j++)
        {
            count++;
        }
        c[i]=count;
        count=0;
    }
    for(i=0;i<7;i++)
    {
        if(c[i]==1)
        {
            countone(n,str,c,m);
        }
        else if(c[i]==2)
        {
            counttwo(n,str,c,m);
        }
    }
    for(i=0;i<m;i++)
    {
        printf("%s ",*(str+i));
    }
}
void countone(int n,char str[][n],int c[],int m)
{
    int i,j;
    int t;
    char temp[m][n];
    for(i=0;i<m;i++)
    {
        for(j=i+1;j<m;j++)
        {
            if(c[i]>c[j])
            {
                t=c[i];
                
                strcpy(*(temp+i),*(str+i));
                
                c[i]=c[j];
                strcpy(*(str+i), *(str+j));
                c[j]=t;
                strcpy(*(str+j),*(temp+i));
                
            }
        }
    }
    t=0;
    for(i=0;i<m;i++)
    {
        if(c[i]==1)
        {
            t++;
        }
    }
    for(i=0;i<t;i++)
    {
        for(j=i+1;j<t;j++)
        {
            if(strcmp(*(str+i),*(str+j))>=1)
            {
                strcpy(*(temp+i),*(str+i));
                strcpy(*(str+i), *(str+j));
                strcpy(*(str+j),*(temp+i));
            }
        }
    }
}
void counttwo(int n,char str[][n],int c[],int m)
{
    int i,j;
    char temp[m][n];
    
    for(i=0;i<m;i++)
    {
        for(j=i;j<m;j++)
        {
            if(str[i][0]==str[j][0])
            {
                if(c[i]==2&&c[j]==2)
                {
                    if(str[i][1]>str[j][1])
                    {
                        strcpy(*(temp+i),*(str+i));
                        strcpy(*(str+i), *(str+j));
                        strcpy(*(str+j),*(temp+i));
                    }
                }
            }
            else if(str[i][0]>str[j][0])
            {
                if(c[i]==2&&c[j]==2)
                {
                    strcpy(*(temp+i),*(str+i));
                    strcpy(*(str+i), *(str+j));
                    strcpy(*(str+j),*(temp+i));
                }
            }
        }
    }
    
}
