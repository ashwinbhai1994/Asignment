//
//  main.c
//  Words
//
//


#include <stdio.h>
#define out 0
#define in 1
int countwords(char *);
int main(int argc, const char * argv[]) {
    // insert code here...
    char str[]="Hello world     is a dind dond ";
    printf("No of words %d",countwords(str));
    return 0;
}
int countwords(char *str)
{
    int state=out;
    int wc=0;
    while(*str)
    {
        if(*str==' ')
        {
            state=out;
        }
        else if(state==out)
        {
            state=in;
            ++wc;
        }
        ++str;
    }
    return wc;
}
