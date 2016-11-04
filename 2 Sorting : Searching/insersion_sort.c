#include<stdio.h>
#include<stdlib.h>
void printarr(int arr[],int n);
void insersionsort(int arr[],int n);
int main()
{
	int arr[]={11,4,54,64,34,2};
	int n=sizeof(arr)/sizeof(int);
	insersionsort(arr,n);
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
void insersionsort(int arr[],int n)
{
	int i=0;
	int j=0;
	int key=0;
	for(i=1;i<n;i++)
	{
		key=arr[i];
		j=i-1;
		while(j>=0 && arr[j]>key)
		{
			arr[j+1]=arr[j];
			j=j-1;
		}
		arr[j+1]=key;
	}
}