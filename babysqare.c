#include <stdio.h>

int main(int argc, const char * argv[]) {
    int n;
    float t;
    float p=1;
    float d=0.0001;
    printf("Enter the number :");
    scanf("%d",&n);
    t=n;
    while((t-p)>d)
    {
        t=(t+p)/2;
        p=n/t;
    }
    printf("%f",t);
    
    return 0;
}

//output 3 1.7320003
