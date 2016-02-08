#include <stdio.h>
#include <stdlib.h>
void empty(char *,int);
int hashset(char *,char,int,int);
int leng(char *,int ,int );
int main(int argc, const char * argv[]) {
    char *bigg;
    char *biggest;
    char *str;
    char *hash;
    int num,i,k=0,flag,itr=0,ll=0;
    printf("Enter the size of the char\n");
    scanf("%d",&num);
    
    
    bigg=(char*)malloc(sizeof(char)*num);
    empty(bigg,num);
    biggest=(char*)malloc(sizeof(char)*num);
    empty(biggest, num);
    hash=(char*)malloc(sizeof(char)*num);
    empty(hash, num);
    str=(char*)malloc(sizeof(char)*num);
   
    scanf("%s",str);
    char single;
    for(i=0;str[i]!=0;i++)
    {
        single=str[i];
        if(hashset(hash,single,num,flag))
        {
            printf("%c",single);
            empty(hash,num);
            k=0;
        }
        *(bigg+k)=single;
        *(hash+itr)=single;
        k++;
        itr++;
    }
    
    if(leng(bigg,num,ll)>leng(biggest,num,ll))
    {
        biggest=bigg;
    }
    printf("%s",biggest);
    return 0;
}
void empty(char *arr,int num)
{
    int i=0;
    for(i=0;i<num;i++)
    {
        *(arr+i)=0;
    }
    
}
int hashset(char *ans,char single,int num,int flag)
{
    int i;
    for(i=0;i<num;i++)
    {
        if(*(ans+i)!=single)
        {
            continue;
        }
        else
        {
            flag=1;
        }
    }
    return flag;
}
int leng(char *arr,int num,int ll)
{
    int i=0;
    for(i=0;*(arr+i)!=0;i++)
    {
        ll++;
    }
    return ll;
}
