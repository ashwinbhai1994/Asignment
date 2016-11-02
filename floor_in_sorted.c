#include<stdio.h>
#include<stdlib.h>
int findSearch(int arr[],int low,int high,int x);
int main()
{
	int arr[]={1,2,5,8,9,11};
	int num=8;
	int n=sizeof(arr)/sizeof(int);
	int ind=findSearch(arr,0,n-1,num);
	printf("%d\n",arr[ind] );
	return 0;
}
int findSearch(int arr[],int low,int high,int x)
{
	if(low>high)
	{
		return -1;
	}
	if(x>=arr[high])
	{
		return high;
	}
	int mid=(low+high)/2;
	if(arr[mid]==x)
	{
		return mid;
	}
	if(mid>0 && arr[mid-1]<=x && x<arr[mid])
	{
		return mid-1;
	}
	if(x<arr[mid])
	{
		return findSearch(arr,low,mid-1,x);
	}
	return findSearch(arr,mid+1,high,x);
}