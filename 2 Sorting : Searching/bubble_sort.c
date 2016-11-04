#include<stdio.h>
#include<stdlib.h>
void printarr(int arr[],int n);
void bubblesort(int arr[],int n);
int main()
{
	int arr[]={9,42,6,33,16,32,8};
	int n=sizeof(arr)/sizeof(int);
	bubblesort(arr,n);
	printarr(arr,n);
	return 0;
}
void printarr(int arr[],int n)
{
	int i=0;
	for(i=0;i<n;i++)
	{
		printf("%d\n",arr[i]);
	}
}
void bubblesort(int arr[],int n)
{
	int i=0;
	int j=0;
	int temp=0;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}