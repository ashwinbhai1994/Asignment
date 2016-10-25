#include<stdio.h>
#include<stdlib.h>
int allarenine(int arr[],int num);
void incrementMidAlone(int arr[],int mid);
void copy1(int s,int s1,int arr[],int e);
void reverse(int arr[],int num);
int findLength(int a);
void printarr(int arr[],int num);
void wholeNew(int arr[],int n);
int main()
{
	int n;
	scanf("%d",&n);
	int temp=n;
	int num=findLength(n);
	int *arr=(int*)malloc(sizeof(int)*num);
	int i=0;
	int mid=num/2;
	int flag=1;
	int left=mid-1;
	int right=mid+1;
	for(i=0;i<num;i++)
	{
		arr[i]=temp%10;
		temp=temp/10;
	}
	reverse(arr,num);
	if(num%2==0)
	{
		if(allarenine(arr,num))
		{
			printf("1");
			for(i=0;i<num-1;i++)
			{
				printf("0");
			}
			printf("1");
		}
		wholeNew(arr,num);
	}
	else
	{
	
	
		if(allarenine(arr,num))
		{
			printf("1");
			for(i=0;i<num-1;i++)
			{
				printf("0");
			}
			printf("1");
		}
		else
		{
			while(arr[left]==arr[right])
			{
				left--;
				right++;
			}
			if(arr[left]!=arr[right] && left>=0 && right>=0)
			{
			
				flag=0;
			 	if(arr[left]>arr[right])
			 	{
			 	
			 		copy1(mid+1,num,arr,mid-1);
			 		printarr(arr,num);
			 	}	
			 	else
			 	{
			 	
			 		copy1(mid+1,num,arr,left);
			 		incrementMidAlone(arr,mid);
			 		printarr(arr,num);
			 	}
			 
			}

			if(flag==1)
			{
			
				incrementMidAlone(arr,mid);
				printarr(arr,num);
			}

		}
	}
	return 0;
}
void wholeNew(int arr[],int n)
{
	printf("value of n%d\n",n );
	int mid=(n/2)-1;
	int temp_mid=mid;
	printf("in\n");
	int right=mid+1;
	int temp_right=right;
	int left=mid-1;
	int i=arr[mid]>arr[right];
	int flag=1;
	while(arr[mid]==arr[right] && right<n)
	{
		mid--;
		right++;
	}
	if(arr[mid]!=arr[right] )
	{
		flag=0;
		if(arr[mid]>arr[right])
		{
			copy1(right,n,arr,mid);
			printarr(arr,n);
		}
		else
		{
			copy1(left+1,n/2,arr,right);
			printarr(arr,n);
		}
	}
	if(flag==1)
	{
		incrementMidAlone(arr,temp_mid);
		incrementMidAlone(arr,temp_right);
		printarr(arr,n);
	}
}
void printarr(int arr[],int num)
{
	int i=0;
	for(i=0;i<num;i++)
	{
		printf("%d",arr[i]);
	}
	printf("\n");
}
void copy1(int s,int s1,int arr[],int e)
{
	int i=0;

	for(i=s;i<s1;i++)
	{
		arr[i]=arr[e];	
		e--;
	}
	
}
void incrementMidAlone(int arr[],int mid)
{
	arr[mid]++;
}
int findLength(int a)
{
	int count=0;
	while(a>0)
	{
		count++;
		a=a/10;
	}
	return count;
}
int allarenine(int arr[],int num)
{
	int k=1;
	int i=0;
	for(i=0;i<num;i++)
	{
		if(arr[i]==9)
		{
			k=k&1;
		}
		else
		{
			k=0;
		}
	}
	return k;
}
void reverse(int arr[],int num)
{
	int s=0;
	int i=0;
	for(i=0;i<=(num/2);i++)
	{
		s=arr[i];
		arr[i]=arr[--num];
		arr[num]=s;
	}
}
