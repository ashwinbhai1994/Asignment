#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int findGcd(int a,int b);
int main()
{
	char str[100]="9/12";
	printf("Enter the fraction\n");
	char *token=strtok(str,"/");
	int num=atoi(token);
	token=strtok(NULL,"/");
	int den=atoi(token);
	int gcd=findGcd(num,den);
	printf("%d/%d",(num/gcd),(den/gcd));
	return 0;
}
int findGcd(int a,int b)
{
	if(b!=0)
	{
		return findGcd(b,a%b);
	}
	else
	{
		return a;
	}
}
