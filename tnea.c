#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct str
{
	int mar[5];
	char name[25];
	int total;
	int pf;
	float cutoff;
}*s;
int main()
{
	FILE *f;
	FILE *rank;
	struct str temp;
	char tStr[100];
	int t=1;
	int number_of_lines=1;
	char single;
	rank=fopen("/Users/bharadwaj/Desktop/c/rank.csv","w");
	f=fopen("/Users/bharadwaj/Desktop/c/names.csv","r");
	if(f==NULL)
	{
		printf("Cant detect ");
		return 0;
	}
	while((single=fgetc(f))!=EOF)
	{
		if(single=='\n')
		{
			number_of_lines++;
		}
	}
	rewind(f);
	s=(struct str*)malloc(sizeof(struct str)*number_of_lines);

	for(int k=0;k<number_of_lines;k++)
	{
		fscanf(f,"%[^,],%d,%d,%d,%d,%d",s[k].name,&s[k].mar[0],&s[k].mar[1],&s[k].mar[2],&s[k].mar[3],&s[k].mar[4]);
		s[k].total=s[k].mar[0]+s[k].mar[1]+s[k].mar[2]+s[k].mar[3]+s[k].mar[4];
		s[k].cutoff=((s[k].mar[0])/2)+ (s[k].mar[1]+s[k].mar[2])/4;
	}
	for(int i=0;i<number_of_lines;i++)
	{
		for(int j=i+1;j<number_of_lines;j++)
		{
			if(s[i].cutoff<s[j].cutoff)
			{
				temp=s[i];
				s[i]=s[j];
				s[j]=temp;
			}
			else if(s[i].cutoff==s[j].cutoff)
			{
				if(s[i].total<s[j].total)
				{
					temp=s[i];
					s[i]=s[j];
					s[j]=temp;
				}else if(s[i].total==s[j].total)
				{
					if(s[i].mar[3]<s[j].mar[3])
					{
						temp=s[i];
						s[i]=s[j];
						s[j]=temp;
					}
				}
			}
		}
	}
	for(int i=0;i<number_of_lines;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(s[i].mar[j]<70)
			{
				s[i].pf=0;
			}
			else
			{
				s[i].pf=1;
			}
		}
	}
	for(int i=0;i<number_of_lines;i++)
	{
		if(s[i].pf)
		{
			fprintf(rank, "%d,%s,%0.2f,Pass\n",t,s[i].name,s[i].cutoff);
			t++;
		}
	}
	return 0;
}
