//  xCode
//  main.c
//  SingularMatTran
//
//  Created by Bharadwaj on 26/12/15.
//

#include <stdio.h>
#include<stdlib.h>
void printarray(int n,int **);
int main(int argc, const char * argv[])
{
    int row,col;
    int temp=0;
    int n=4;
    scanf("%d",&n);
    int *a[n];
    for(int i=0;i<n;i++)
    {
        a[i]=(int *)malloc(n*sizeof(int));
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
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
void printarray(int n,int *a[])
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
