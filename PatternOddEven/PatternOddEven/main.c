//
//  main.c
//  PatternOddEven
//
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int i,j;
    int n;
    scanf("%d",&n);
    int odd=1;
    int even=2;
    //int temp[n][n];
    for(i=1;i<n;i++)
    {
        for(j=1;j<=i;j++)
        {
            if(i%2!=0)
            {
                //temp[i][j]=odd;
                printf("%d",odd);
                odd+=2;
                
            }
            else
            {
                //temp[i][j]=even;
                printf("%d",even);
                even+=2;
            }
            
        }
        printf("\n");
    }
    
    return 0;
}
