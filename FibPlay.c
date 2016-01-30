#include <stdio.h>
int big(int num)
{
    int f1 = 0, f2 = 1, f3 = 1;
    if (num == 0)
    {
        return 0;
    }
    else if(num==1)
    {
        return 1;
    }
    while (f3 <= num)
    {
        f1 = f2;
        f2 = f3;
        f3 = f1+f2;
    }
    return f2;
}
int main()
{
    int num = 100;
    while (num>0)
    {
        int k = big(num);
        printf("%d",k);
        num = num-k;
    }
    return 0;
}
