#include<stdio.h>
#include<stdlib.h>
//All the functions used till now !
int allarenine(int arr[],int num);
void incrementMidAlone(int arr[],int mid);
void copy1(int s,int s1,int arr[],int e);
void copy2(int s,int s1,int arr[],int e);
void reverse(int arr[],int num);
int findLength(int a);
void printarr(int arr[],int num);
void wholeNew(int arr[],int n);
//1.Check whether the number size if of Odd or even 
//	1.a.Check if all the elements are 9 If yes then 1 to n-1 0 is printed 
//	1.a.1 is printed at 0th and nth index 
//2.if the number is odd 
//	2.a.The number should be divided into two parts left and right 
//	2.b.If the left part is greater than right Copy left side to right 
//	2.c.If the right part is greatert than left part Copy right to left and Increment middle by 1
//3.if the number is even:
//	3.a.Do the same as odd put mid element is (n/2)-1
//
int main()
{
	int n;
	scanf("%d",&n);
	//gets the number
	int temp=n;

	int num=findLength(n);
	//func findLength finds the length of the number
	int *arr=(int*)malloc(sizeof(int)*num);
	//dynamically allocated memory of array to hold number
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
	//to get the number into the array in reverse order
	//for ex if 123 is number the number will be stored as 3,2,1
	reverse(arr,num);
	//reverse the array 
	//now it changes to 1,2,3
	if(num%2==0) //If the length of the array is even 
	{
		if(allarenine(arr,num)) //If all the elements are nine This block of code executes
		{
			printf("1");
			for(i=0;i<num-1;i++)
			{
				printf("0");
			}
			printf("1");
		}
		else  //else this will execute
		{
			wholeNew(arr,num);
		}
	}
	else
	{
	
		// if the length of the array is odd then this block gets executed
		if(allarenine(arr,num))//If all elements are nine (Actually odd and even allnine can be bought to a single func)
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
			while(arr[left]==arr[right]) //if the element is 11211 then it is already a palindrome 
				//I just need to Increase the middle element
				//so I am checking all the elements from mid to left and to right 
				//if they are equal then flag will remain 1
			{
				left--;
				right++;
			}
			if(arr[left]!=arr[right] && left>=0 && right>=0)//This one is nothing but when the elements are not equal 
				//then the arr[left] is checked with arr[right]
			{
			
				flag=0;
			 	if(arr[left]>arr[right])//If left side is larger 
			 		//then left side is copied to right side 
			 	{
			 	
			 		copy1(mid+1,num,arr,mid-1);
			 		printarr(arr,num);
			 	}	
			 	else //if Right side is larger 
			 		//then left is coppied to right 
			 		//middle element of the array is incremented
			 	{
			 	
			 		copy1(mid+1,num,arr,left);
			 		incrementMidAlone(arr,mid);
			 		printarr(arr,num);
			 	}
			 
			}
			//if the array given is already a palindrome 
			//we have to just increment the middle element alone 
			if(flag==1)
			{
			
				incrementMidAlone(arr,mid);
				printarr(arr,num);//This is a func to print the element of the array.
			}

		}
	}
	return 0;
}
void wholeNew(int arr[],int n)//this whole block of code is for even number of elemets
{
	int mid=(n/2)-1;
	//mid element is subtracted by 1 
	//For example : 1111
	//n=4 n/2 = 2 
	//here arr[2]=1; which is higher than the mid 
	//instead we sub and take 1 as mid index
	int temp_mid=mid;
	//just for sending the midincrement if it is a palindrome 
	int right=mid+1;
	//mid+1 is taken as right 
	int temp_right=right;
	int left=mid-1;

	int flag=1;
	//same logic as in odd 
	while(arr[mid]==arr[right] && right<n) //here we are checking for 
		//whether it is a palindrome already 
	{
		mid--;
		right++;
	}
	//if it is not a palindrome
	if(arr[mid]!=arr[right] )
	{
		flag=0;
		//flag is set to zero 
		if(arr[mid]>arr[right]) //if arr[mid]>arr[right] which is simlar to that of arr[left]>arr[right]
			//in odd
		{
			copy1(right,n,arr,mid);
			//coping left side
			printarr(arr,n);
			//printing the answer
		}
		else
		{
			
			incrementMidAlone(arr,right-1);
			copy1(n/2,n,arr,(n/2)-1);
			//copying right side
			
			//this is tittle tricky ! 
			//for example 1234
			// the answer without this line is 1224
			//because the copy block only copies till 1.2 index 
			//inorder to copy 0 index alone we have to use this part
			printarr(arr,n);
		}
	}
	if(flag==1)
	{
		//This part is bit easy
		//for example : If 1111 is the number 
		//we have to increment 2 middle elements 
		//which is not in the case of odd size number 
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
void copy1(int s,int s1,int arr[],int e)//for odd and even copy func
{
	int i=0;
	for(i=s;i<s1;i++)
	{
		arr[i]=arr[e];	
		e--;//this part is to copy in reverse order
	}
	
}


void incrementMidAlone(int arr[],int mid)// func to increment middle part of the array both in odd and even 
{
	arr[mid]++;
}
int findLength(int a)//to find the length of the array 
{
	int count=0;
	while(a>0)
	{
		count++;
		a=a/10;
	}
	return count;
}
int allarenine(int arr[],int num)//check if all the elements in the array are 9
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
void reverse(int arr[],int num)//used to reverse the array with time complexity of n/2
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
