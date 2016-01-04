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
    
    int arr[10][10]={0};
    arr[0][0]=1;
    for(int r=1;r<=n;r++)
    {
        for(int i=1;i<=r;i++)
        {
            arr[r][i]=arr[r-1][i-1]+arr[r-1][i];
            printf("%d",arr[r][i]);
        }
        printf("\n");
    }
    return 0;
}
