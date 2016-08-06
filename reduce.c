//Reduce to fraction

char** ReduceFraction(int n, char** str, int* res) {
    int i=0;
    int num=0;
    char **ans=(char**)malloc(sizeof(char*)*n);
    for(i=0;i<n;i++)
    {
            ans[i]=(char*)malloc(sizeof(char)*10);
    }
    int den=0;
    char *token;
    int gcd=0;
    for(i=0;i<n;i++)
    {
         token=strtok(str[i],"/");
         num=atoi(token);
        token=strtok(NULL,"/");
        den=atoi(token);
        gcd=findGcd(num,den);
        sprintf(ans[i],"%d/%d",num/gcd,den/gcd);
        printf("%s",ans[i]);
    }
    *res=n;
    return ans;
}
int findGcd(int a,int b)
{
    if(b!=0)
        {
        return findGcd(b,a%b);
    }
    else
        {
        return a;
    }
}
