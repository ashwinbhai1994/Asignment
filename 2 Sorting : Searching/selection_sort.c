#include<stdio.h>
#include<stdlib.h>
void printarr(int arr[],int n);
void selectionsort(int arr[],int n);
int main()
{
	int arr[]={11,55,23,88,45};
	int n=sizeof(arr)/sizeof(int);
	selectionsort(arr,n);
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

void selectionsort(int arr[],int n)
{
	int i=0;
	int min_ind=0;
	int temp=0;
	int j=0;
	for(i=0;i<n-1;i++)
	{
		min_ind=i;
		for(j=i+1;j<n;j++)
		{
			if (arr[min_ind]>arr[j])
			{
				temp=arr[min_ind];
				arr[min_ind]=arr[j];
				arr[j]=temp;
			}
		}
	}
}