//
//  main.c
//  NumberOfBits
//

#include <stdio.h>

int main(int argc, const char * argv[])
{
    int rem=0,r,n,count=0;
    scanf("%d",&n);
    while(n!=0)
    {
        
        n=n/2;
        count++;
    }
    printf("%d",count);
    return 0;
}

/// Input 9 output 4 Input 5 output 3
