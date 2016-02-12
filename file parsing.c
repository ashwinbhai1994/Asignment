#include <stdio.h>
#include<stdlib.h>
void average(int n,float avg[]);
void topmark(int i,int top[])
struct str
{
    int mar[5];
    char name[25];
    int no;
}*s;
int main(int argc, const char * argv[]) {
    int n=0,i;
    char single;
    char head[7][25];
    int top[6]={0};
    float avg[6]={0};
    FILE *fp;
    fp = fopen("File.csv","r");
    if (fp == NULL)
    {
        return 0;
    }
    while( (single=fgetc(fp)) != EOF)
    {
        if(single == '\n')
        {
            n++;
        }
    }
    rewind(fp);   //pointer return to the top
    s = (struct str*) malloc(sizeof(struct str)*n);
    for(i=0;i<7;i++)
    {
        fscanf(fp,"%[^,\n],",head[i]); //heading of the file are stored in array head
    }
    for(i=0;i<n;i++)
    {
        fscanf(fp, "%d,%[^,],%d,%d,%d,%d,%d", &s[i].no, s[i].name,&s[i].mar[0], &s[i].mar[1], &s[i].mar[2],&s[i].mar[3],&s[i].mar[4]);
            topmark(i,top);
    }
    for(i=0;i<5;i++)
    {
        printf("%s %s %d",head[i+2],s[top[i]].name,s[top[i]].mar[i]);
        printf("\n");
    }
    average(n,avg);
    for(i=0;i<5;i++)
    {
        printf("%s: %.2f",head[i+2],avg[i]);
        printf("\n");
    }

    return 0;
}


void average(int n,float avg[])
{
    int i,j;
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<5;j++)
        {
            avg[j]+=s[i].mar[j];
        }
    }
    for(j=0;j<5;j++)
    {
        avg[j]/=n;
    }
}
void topmark(int i,int top[])
{
    int j;
    for(j=0;j<5;j++)
    {
        if(s[top[j]].mar[j] < s[i].mar[j])
        {
            top[j] = i;
        }
    }
}
