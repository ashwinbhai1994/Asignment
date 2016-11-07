#include<stdio.h>
#include<stdlib.h>
void segregate(int arr[],int n);
void printarr(int arr[],int n);
int main()
{
	int arr[]={0,1,0,0,1,1,1,1};
	int n=sizeof(arr)/sizeof(int);
	segregate(arr,n);
	printarr(arr,n);
	return 0;
}
void printarr(int arr[],int n)
{
	int i=0;
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
}
void segregate(int arr[],int n)
{
	int left=0;
	int right=n-1;
	while(left<right)
	{
		while(arr[left]==0 && left<right)
		{
			left++;
		}
		while(arr[right]==1&& left<right)
		{
			right--;
		}
		if(left<right)
		{
			arr[left]=0;
			arr[right]=1;
			left++;
			right--;
		}
	}
}