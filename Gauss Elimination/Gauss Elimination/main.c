//ide xcode


#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int i,j,k,n,m;
    scanf("%d%d",&n,&m);//dimen of square array
    float a[n][m],factor;
    float prod=1;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%f",&a[i][j]);
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        
        
        {
            if(j>i)                         //a(2,1),a(3,1),a(3,2)  where 2>1 3>1 3>2
            {
                factor=a[j][i]/a[i][i];    //factor=a[2][1]/a[1][1]......a[3][2]/a[2][2]
                for(k=1;k<n;k++)
                {
                    a[j][k]=a[j][k]-factor*a[i][k];   //a[2][1]=a[2][1]-factor*a[1][1] which is equal to zero
                }
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i==j)
                
            {
               
                prod*=a[i][j];
                
            }
        }
    }
    printf("%f",prod);
    
    return 0;
}
