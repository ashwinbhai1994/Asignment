//
//  main.c
//  2048
//
//

#include <stdio.h>
void upper(int mat[4][4]);
void lower(int mat[4][4]);
void right(int mat[4][4]);
void left(int mat[4][4]);
int main(int argc, const char * argv[]) {
    // insert code here...
    int mat[4][4]={
        {0,2,3,4},{5,0,1,6},{3,4,5,6},{0,0,0,0}
    };
    char tes;
    
    printf("Enter the desired direction");
    for(int i=0;i<100;i++)
    {
        scanf("%c",&tes);
        switch (tes)
        {
                case 'u':
                {
                    upper(mat);
                }
                case 'd':
                {
                    lower(mat);
                }
                case 'r':
                {
                    right(mat);
                }
                case 'l':
                {
                    left(mat);
                }
        }
        
        
    }
}

    
     void upper(int mat[][4])
     {
         for(int row=0; row<4 ;row++)
         {
             for(int col=0; col<4 ;col++)
             {
                 if(!mat[col][row])
                 {
                     for(int k=col+1; k<4 ;k++)
                     {
                         if(mat[k][row])
                         {
                             mat[col][row]=mat[k][row];
                             mat[k][row]=0;
                             break;
                         }
                     }
                 }
             }
         }
         for(int i=0;i<4;i++)
         {
             for(int j=0;j<4;j++)
             {
                 if(mat[i][j])
                 {
                    printf("| %d |",mat[i][j]);
                 }
                 else
                 {
                     printf(" ");
                 }
             }
             printf("\n");
         }
     }

 void lower(int mat[][4])
{
    for(int row=3; row>=0 ;row--)
    {
        for(int col=3; col>=0 ;col--)
        {
            if(!mat[col][row])
            {
                for(int k=col-1; k>=0 ;k--)
                {
                    if(mat[k][row])
                    {
                        mat[col][row]=mat[k][row];
                        mat[k][row]=0;
                        break;
                    }
                }
            }
        }
    }
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(mat[i][j])
            {
                printf("| %d |",mat[i][j]);
            }
            else
            {
                 printf(" ");
            }
        }
        printf("\n");
    }
}

void right(int mat[][4])
{
    for(int row=3; row>=0 ;row--)
    {
        for(int col=3; col>=0 ;col--)
        {
            if(!mat[row][col])
            {
                for(int k=col-1; k>=0 ;k--)
                {
                    if(mat[row][k])
                    {
                        mat[row][col]=mat[row][k];
                        mat[row][k]=0;
                        break;
                    }
                }
            }
        }
    }
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(mat[i][j])
            {
                printf("| %d |",mat[i][j]);
            }
            else
            {
                 printf(" ");
            }
        }
    }
}
void left(int mat[][4])
{
    for(int row=0; row<4 ;row++)
    {
        for(int col=0; col<4 ;col++)
        {
            if(!mat[row][col])
            {
                for(int k=col+1; k<4 ;k++)
                {
                    if(mat[row][k])
                    {
                        mat[row][col]=mat[row][k];
                        mat[row][k]=0;
                        break;
                    }
                }
            }
        }
    }
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(mat[i][j])
            {
                printf("| %d |",mat[i][j]);
            }
            else
            {
                 printf(" ");
            }
        }
    }
}
