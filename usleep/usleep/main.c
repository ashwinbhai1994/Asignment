//
//  main.c
//  usleep
//


#include <stdio.h>
#include<time.h>
#include<unistd.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int i=0;
    char pon[]="Happy pongal";
    while(pon[i]!='\0')
    {
        printf("%c",pon[i]);
        fflush(stdout);
        sleep(1);
        i++;
    }
    return 0;
}

