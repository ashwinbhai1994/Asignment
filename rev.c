#include <stdio.h>

int main(int argc, const char * argv[]) {
    int rev=0;
    int n=0;
    printf("Enter the number");
    scanf("%d",&n);
 
    while(n!=0)
    {
        rev=rev*10;
        rev=rev+n%10;
        n=n/10;
    }
    printf("%d",rev);
    return 0;
}
