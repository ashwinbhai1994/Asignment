
#include <stdio.h>
int findnext(int);
int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    int t;
    scanf("%d",&n);
    for(int i=n+1;;i++)
    {
        t=findnext(i);
        if(t==1)
        {
            break;
        }
    }
    return 0;
}
int findnext(int n)
{
    int count=0;
    for(int i=2;i<n;i++)
    {
        if(n%i==0)
        {
            count++;
        }
    }
    if(count==0)
    {
        printf("%d",n);
        return 1;
    }
    else
    {
        return 0;
    }
}
