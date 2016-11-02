#include<stdio.h>
#include<stdlib.h>
int getans(int arr[],int x,int n);
int firstoccurance(int arr[],int l,int r,int x,int n);
int lastoccurance(int arr[],int l,int r,int x,int n);
int main()
{
	int arr[]={1,1,2,2,2,2,3};
	int n=sizeof(arr)/sizeof(int);
	int num=2;
	int result=getans(arr,n,num);
	printf("%d \n",result);
	return 0;
}
int getans(int arr[],int n,int x)
{
	int i;
	int j;
	i=firstoccurance(arr,0,n-1,x,n);
	printf("i %d\n",i );
	if(i==-1)
	{
		return i;
	}
	j=lastoccurance(arr,0,n-1,x,n);
	printf("j %d\n",j);
	return j-i+1;
}
int firstoccurance(int arr[],int l,int r,int x,int n)
{
	int mid=0;
	if(r>=l)
	{
		mid=(l+r)/2;
		if(mid==0 || (arr[mid-1]<n && arr[mid]==x))
		{
			return mid;
		}
		else if(x>arr[mid])
		{
			return firstoccurance(arr,mid+1,r,x,n);
		}
		else
		{
			return firstoccurance(arr,l,(mid-1),x,n);
		}
		
	}
	return -1;
}
int lastoccurance(int arr[],int l,int r,int x,int n)
{
	int mid=0;
	if(r>=l)
	{
		mid=(l+r)/2;
		if(mid==n-1 || (arr[mid+1]>n && arr[mid]==x))
		{
			return mid;
		}
		else if(x<arr[mid])
		{
			return lastoccurance(arr,l,mid-1,x,n);
		}
		else
		{
			return lastoccurance(arr,mid+1,r,x,n);
		}
		
	}
	return -1;
}