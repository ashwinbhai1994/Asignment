#include <stdio.h>
#include<stdlib.h>
void FindSub(char *,int);
int main(int argc, const char * argv[])
{
    int num;
    char* str;
    printf("Enter the size of the string");
    scanf("%d",&num);
    str=(char*)malloc(sizeof(char) * num);
    scanf("%s",str);
    FindSub(str,num);
    return 0;
}
void FindSub(char *str,int n)
{
    int i=0;
    while(str[i]!=0)
    {
        i++;
    }
    int curr=1;
    int max=1;
    int start=0;
    int end=0;
    int prev;
    int *visited=(int*)malloc(sizeof(int)*256);
    for(i=0;i<256;i++)
    {
        visited[i]=-1;
    }
    visited[str[0]]=0;
    for(i=1;i<n;i++)
    {
        prev=visited[str[i]];
        if(prev==-1||i-curr>prev)
        {
            curr++;
            end=i;
        }
        else
        {
            if(curr>max)
            {
                max=curr;
            }
            curr=i-prev;
            
        }
        visited[str[i]]=i;
    }
    if(end-curr>0)
    {
        start=end-curr+1;
    }
    else{
        start=0;
    }
    for(i=start;i<=end;i++)
    {
        putchar(str[i]);
    }
    
}
//input 6 abcabc output abc
//input 6 aaabcd output abcd 
