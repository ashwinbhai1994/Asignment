#include<stdio.h>
int main()
{
	char str[100];
	int i,j=0,arr[100]={0};
	scanf("%s",str);
	for(i=str[j];str[j]!='\0';j++)
	{
		i=str[j];
		arr[i]+=1;
	}
	for(j='A';j<'Z';j++)
	{
		printf("%c \t %d",j,arr[j]);
	}
	return 0;
}
