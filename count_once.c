#include<stdio.h>
#include<stdlib.h>
int countone(int arr[],int l,int r);
int main()
{
	int arr[]={1, 1, 1, 1, 0, 0, 0};
	int n=sizeof(arr)/sizeof(int);
	int ans=countone(arr,0,n);
	printf("%d\n",ans );
	return 0;
}
int countone(int arr[],int l,int r)
{
	if(r>=l)
	{
		int mid=(l+(r-l))/2;
		if((mid==r || arr[mid+1]==0)&&arr[mid]==1)
		{
			return mid+1;
		}
		if(arr[mid]==1)
		{
			return countone(arr,mid+1,r);
		}
		return countone(arr,l,(mid-1));
	}
	return 0;
}