//
//  main.c
//  NumberOfBits
//


#include<stdio.h>
int main()
{
    int number,bits=0,number1;
    printf("\n Enter a number: ");
    scanf("%d",&number);
    number1=number;
    do
    {
        number1/=2;
        bits++;
    }while(number1>0);
    printf("\n The number of bits required to store %d is: %d",number,bits);
    return 0;
}
/// Input 9 output 4 Input 5 output 3