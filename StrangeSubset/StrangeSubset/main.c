//
//  main.c
//  StrangeSubset
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int arr[3]={1,2,3};
    int power=pow(3,2);
    for(int i=0;i<power;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(i & (1<<j))
            {
                printf("%d",arr[j]);
            }
        }
        printf("\n");
    }
        
    return 0;
}
