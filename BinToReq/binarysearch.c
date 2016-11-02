#include<stdio.h>
#include<stdlib.h>
int binsear(int arr[],int l,int r,int n);
int main()
{
	int arr[]={1,5,34,98,234};
	int n=sizeof(arr)/sizeof(int);
	int x=5;
	int result=binsear(arr,0,n-1,x);
	printf("%d ",result);
	return 0;
}
int binsear(int arr[],int l,int r,int n)
{
	int mid=0;
	if(r>=l)
	{
		mid=l+(r-1)/2;
		if(n==arr[mid])
		{
			return mid;
		}
		if(arr[mid]>n)
		{
			binsear(arr,l,mid-1,n);
		}
		else 
		{
			binsear(arr,mid+1,r,n);
		}
	}
	return -1;
}