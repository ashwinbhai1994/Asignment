//
//  main.c
//

#include <stdio.h>
void swapu(int * ,int *);
void upper(int [3][3]);
void print(int (*)[3]);
void down(int [3][3]);
void left(int [3][3]);
void right(int [3][3]);

int main(int argc, const char * argv[]) {
   char ch;
    int arr[3][3]={1,0,3,4,5,6,7,8,9};
    do{
        scanf("%c",&ch);
        switch (ch) {
            case 'U':
                upper(arr);
                break;
            case 'D':
                down(arr);
                break;
            case 'L':
                left(arr);
                break;
            case 'R':
                right(arr);
                break;
        }
        
    }while(ch!='Q');
    return 0;
}
    void upper(int arr[][3])
    {
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(arr[j][i]==0)
                {
                    swapu(&arr[j][i],&arr[j+1][i]);
                    break;
                }
            }
        }
        print(arr);
    }
void down(int arr[][3])
{
    for(int i=2;i>=0;i--)
    {
        for(int j=2;j>=0;j--)
        {
            if(arr[j][i]==0)
            {
                
                swapu(&arr[j-1][i], &arr[j][i]);
                break;
            }
        }
    }
    print(arr);
}
void left(int arr[][3])
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(arr[i][j]==0)
            {
                //if(j!=2 || j!=0)
                {
                    swapu(&arr[i][j], &arr[i][j+1]);
                    break;
                }
               
            }
        }
    }
    print(arr);
}
void right(int arr[][3])
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(arr[i][j]==0)
            {
                swapu(&arr[i][j], &arr[i][j-1]);
                break;
            }
        }
    }
    print(arr);
}
   
    
 void print(int arr[][3])
{
    for(int r=0;r<3;r++)
    {
        for(int c=0;c<3;c++)
        {
            if(arr[r][c])
            {
                printf("%d",arr[r][c]);
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
}
void swapu(int *a,int *b)
{
    int temp=0;
    temp=*a;
    *a=*b;
    *b=temp;
}
