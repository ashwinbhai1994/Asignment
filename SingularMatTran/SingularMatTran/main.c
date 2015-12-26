//  xCode
//  main.c
//  SingularMatTran
//
//  Created by Bharadwaj on 26/12/15.
//

#include <stdio.h>
void printarray(int n,int a[][n]);
int main(int argc, const char * argv[])
{
    int row,col;
    int temp=0;
    int n=4;
    scanf("%d",&n);
    
    int a[4][4]={{1,2,3,4},
                {4,5,6,4},
                {7,8,9,4},
                {10,11,12,13}
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
    printarray(n,a);
    
    
    return 0;
}
void printarray(int n,int a[][n])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}
