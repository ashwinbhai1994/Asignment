//
//  main.c
//  Sort
//
//  Created by Bharadwaj on 22/12/15.
//  Copyright © 2015 Bharadwaj. All rights reserved.
//

#include <stdio.h>
int binarysearch(int *,int ,int ,int );

int main(int argc, const char * argv[])
{
    // insert code here...
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int x=4;
    int result=binarysearch(arr,0,n-1,x);
    printf("index %d \n",result);
    return 0;
}
int binarysearch(int arr[],int l,int r,int x)
{
    if(r>=l)
    {
        int mid=l+(r-l)/2;
        if(arr[mid]==x)
        {
            return mid;
        }
        if(arr[mid]>x)
        {
            return binarysearch(arr, l, mid-1, x);
        }
        if(arr[mid]<x)
        {
            return binarysearch(arr, mid+1, r, x);
        }
    }
    return -1;
}