#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int count=1;
	char str[25];
	int k;
	scanf("%s",str);
	for(int i=0;str[i]!='\0';i++)
	{
		count++;
	}
	for(int i=0;i<count;i++)
	{
		if(isdigit(str[i])&&(!isdigit(str[i+1])))
		{
			k=str[i]-'0';
			for(int h=0;h<k;h++)
			{
				printf("%c",str[i-1]);
			}
		}
		else if(isdigit(str[i])&&isdigit(str[i+1]))
		{
			k=(str[i]-'0')*10+(str[i]-'0');
			for(int h=0;h<k;h++)
			{
				printf("%c",str[i-1]);
			}
		}
	}
}
