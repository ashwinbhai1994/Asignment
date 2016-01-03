//
//  main.c
//  PatternB
//
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int rows;int i,j,k=1;
    scanf("%d",&rows);
    for(i=1;i<=rows;i++)
    {
        for(j=1;j<=i;++j,k++)
            printf("%d ",k);
        
        printf("\n");
    }
    return 0;
}
