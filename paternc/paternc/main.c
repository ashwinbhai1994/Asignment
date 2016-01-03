//
//  main.c
//  paternc
//
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    scanf("%d",&n);
    
    int arr[n][n];
    for(int r=0;r<n;r++)
    {
        for(int i=0;i<=r;i++)
        {
            if(r==i||i==0)
            {
                arr[r][i]=1;
            }
            else
            {
                arr[r][i]=arr[r-1][i-1]+arr[r-1][i];
            }
            printf("%d",arr[r][i]);
        }
        printf("\n");
    }
    return 0;
}
