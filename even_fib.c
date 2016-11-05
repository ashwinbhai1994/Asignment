#include<stdio.h>
#include<stdlib.h>
int findEvenFib(int n);
int main()
{
	int n;
	scanf("%d",&n);
	int ans=findEvenFib(n);
	printf("%d is the %d fib number\n",ans,n );
	return 0;
}
int findEvenFib(int n)
{
	if(n<1)
	{
		return n;
	}
	if(n==1)
	{
		return 2;
	}
	else
	{
		return (4*(findEvenFib(n-1))+findEvenFib(n-2));
	}
}