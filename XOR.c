#include<stdio.h>
#include<string.h>
int main()
{
	int num;
	int n,x;
	int i=0;
	int res=0;
	scanf("%d",&num);
	while(num--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			if(i%2!=0)
			{
				res=res^x;
			}
		}
	}
	if(n%2==0)
	{
		printf("0");
	}
	else
	{
		printf("%d",res);
	}
	return 0;
}¯
