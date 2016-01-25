//
//  main.c
//  Hex
//

#include <stdio.h>
void printF(int );
void bittog(int ,int );
void bittogex(int ,int );
void bitset(int ,int);
void bitz(int ,int);
void swap(int);
void bitriR(int);
void bitriL(int);
int main(int argc, const char * argv[]) {
    int num=11;
    printf("given bit \t");
    printF(num);
    int k=2;
    bitset(num,k);
    bitz(num,k);
    bittog(num,k);
    bittogex(num,k);
    bitriR(num);
    bitriL(num);
    swap(num);
}
void swap(int num)
{
    printf("After swapping nibble");
    printF(num<<4|num>>4);
}
void bitriR(int num)
{
    printf("After right rotate");
    num=num>>1|num<<7;
    printF(num);
}
void bitriL(int num)
{
    printf("After left rotate");
    num=num<<1|num>>7;
    printF(num);
}
void bittogex(int num,int k)
{
    num=(~num)|(1<<k);
    printf("After toggling other than bit %d\t",k);
    printF(num);
}
void bittog(int num,int k)
{
    num=num^(1<<k);
    printf("After toggling bit %d\t",k);
    printF(num);
}


void bitz(int num,int k)
{
    num=num&(~(1<<k));
    printf("Bit %d to 0\t",k);
    printF(num);
}


void bitset(int num,int k)
{
    num=num|1<<k;
    printf("Bit set %d to 1 \t",k);
    printF(num);
}


void printF(int num)
{
    int n=128;
    while(n>0)
    {
        if((num&n)==0)
        {
            printf("0");
        }
        else
        {
            printf("1");
        }
        n=n>>1;
    }
    printf("\n");
}
