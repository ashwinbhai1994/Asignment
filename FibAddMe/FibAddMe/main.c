//
//  main.c
//  FibAddMe
//
//  Created by Bharadwaj on 30/01/16.
//  Copyright © 2016 Bharadwaj. All rights reserved.
//

#include <stdio.h>
int small(int);
int main(int argc, const char * argv[]) {
    int n;
    int s;
    scanf("%d",&n);
    while(n>0)
    {
        s=small(n);
        printf("%d \t",s);
        n=n-s;
    }
    return 0;
}
int small(int n)
{
    int fib[]={1,1,2,3,5,8,13,21,34,55,89,144,233,377,610};
    int i,count=0;
    for(i=0;i<14;i++)
    {
        if(n>fib[i])
        {
            count++;
            continue;
        }
        else
        {
            break;
        }
    }
   
    return fib[count-1];
}