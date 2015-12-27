//
//  main.c
//  SpiralMatrix
//
//  Created by Bharadwaj on 27/12/15.
//  Copyright © 2015 Bharadwaj. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int arr[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int sr,er,sc,ec,i;
    
    sr=0;
    sc=0;
    
    er=3;
    ec=3;
   
    while(sr<er && sc<ec)
    {
        for(i=sc;i<ec;i++)
        {
            printf("%d",arr[sr][i]);
        }
        sr++;
        for(i=sr;i<er;i++)
        {
            printf("%d",arr[i][ec-1]);
        }
        ec--;
        if(sr<er)
        {
            for(i=ec-1;i>=sc;i--)
            {
                printf("%d",arr[er-1][i]);
            }
            er--;
        }
        if(sc<ec)
        {
            for(i=er-1;i>=sr;i--)
            {
                printf("%d",arr[i][sc]);
            }
            sc++;
        }
    }
    return 0;
}
