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
    int num;
    scanf("%d",&num);
    while (num>0)
    {
        int k = big(num);
        printf("%d\t",k);
        num = num-k;
    }
    return 0;
}
//output 100 89 8 3 || 5 5
