#include<stdio.h>
#include<stdio.h>
#include<string.h>
int Palin(char str[],int n);
int main()
{
	char str[]="abba";
	int n=strlen(str);
	int is=Palin(str,n);
	if(is)
	{
		printf("Is a palindrome\n");
	}
	else
	{
		printf("Go to Hell\n");
	}
	return 0;
}
int Palin(char str[],int n)
{
	int i=0;
	int k=1;
	while(i<=n/2)
	{
		if(str[i]==str[n-i-1])
		{
			k=k&1;
		}
		else
		{
			k=0;
		}
		i++;
	}
	if(k==1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}