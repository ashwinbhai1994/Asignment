//
//  main.c
//  PatternStar5
//
//  Created by Bharadwaj on 30/12/15.
//  Copyright © 2015 Bharadwaj. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int i,j,n=5;
    for(i=1;i<=n;i++)
    {
        if(i%2==0||i==n)
        {
            for(j=1;j<=i;j++)
            {
                printf("* ");
            }
            printf(" \n");
        }
    }
    for(i=n;i>1;i--)
    {
        if(i%2==0)
        {
            for(j=1;j<=i;j++)
            {
                printf("* ");
            }
            printf(" \n");
        }
    }
    return 0;
}
