//
//  main.c
//  Decoding
//
//
#include<stdio.h>
#include<string.h>
int main()
{
    char str[100];char arr[100],arr1;
    int i,count,len;char h;
    scanf("%s",str);
    len=strlen(str);
    for(i=0;i<len;i++)
    {
        count=0;
        h=str[i];
        printf("%c",str[i]);
        while(str[i]==str[i+1])
        {
            count++;
            i++;
        }
        if(count<2)
        {
            arr[arr1++]=h;
        }
        else if(count>=2)
        {
            arr[arr1++]=
        }
        printf("%d",count+1);
    }
    return 0;
}