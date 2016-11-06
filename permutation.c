#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void swap(char *a,char *b);
void permute(char str[],int l,int r);
int main()
{
	char str[]="abc";
	int n=strlen(str);
	permute(str,0,n-1);
	return 0;
}
void swap(char *a,char *b)
{
	char temp=*a;
	*a=*b;
	*b=temp;
}
void permute(char arr[],int l,int r)
{
	int i=0;
	if(l==r)
	{
		printf("%s\n",arr);
	}
	else
	{
		for(i=l;i<=r;i++)
		{
			swap((arr+i),(arr+l));
			permute(arr,l+1,r);
			swap((arr+i),(arr+l));
		}
	}
}