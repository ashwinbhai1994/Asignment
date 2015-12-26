//  xCode
//  main.c
//  SingularMatTran
//
//  Created by Bharadwaj on 26/12/15.
//

#include <stdio.h>

int main(int argc, const char * argv[])
{
    int row,col;
    int temp=0;
    int n=3;
    int a[3][3]={{1,2,3},
                {4,5,6},
                {7,8,9}
                };
    for(row=1;row<n;row++)
    {
        for(col=0;col<n-1;col++)
        {
            if(row!=col)
            {
                temp=a[row][col];
                a[row][col]=a[col][row];
                a[col][row]=temp;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    
    
    return 0;
}
