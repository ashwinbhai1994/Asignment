#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char str[7][4]={"1","3","7","9","6","2","5"};
    int len=sizeof(str)/sizeof(str[0]);
    int i,j;
    char temp[7][4];
    for(i=0;i<len;i++)
    {
        for(j=i+1;j<len;j++)
        {
            if(strcmp(*(str+i),*(str+j))>=1)
            {
                strcpy(*(temp+i),*(str+i));
                strcpy(*(str+i), *(str+j));
                strcpy(*(str+j),*(temp+i));
            }
        }
        printf("\n");
    }
    for(i=0;i<len;i++)
    {
        printf("%s ",*(str+i));
    }
}
