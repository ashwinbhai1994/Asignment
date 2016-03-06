struct std
{
	int s_no;
	char name[100];
	char ans[100];
	int ind[100];
	int count;
	int start;
	int end;
}*p;
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int i,j;
	int l,m;
	int t;
	int n;
	int start,end;
	scanf("%d\n",&n);
	p=(struct std*)malloc(sizeof(struct std)*n);
	for(i=0;i<n;i++)
	{
		scanf("%d %[^\n]s",&p[i].s_no,p[i].name);
	}
	for(i=0;i<n;i++)
	{
		p[i].start=0;
		p[i].end=0;
		for(j=0;p[i].name[j]!=0;j++)
		{
			if(p[i].name[j]=='.')
			{
				p[i].start=j+1;
			}
			else if(p[i].name[j]==' ')
			{
				p[i].end=j-1;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		t=0;
		if(p[i].start!=0)
		{
			for(m=p[i].start;p[i].name[m]!='\0';m++)
			{
				p[i].ans[t]=p[i].name[m];
				t++;
			}
			p[i].ans[t]='\0';
		}
		else if(p[i].end!=0)
		{
			for(m=0;p[i].name[m]!=' ';m++)
			{
				p[i].ans[t]=p[i].name[m];
				t++;
			}
			p[i].ans[t]='\0';
		}
		else if(p[i].start==0 &&p[i].end==0)
		{
			strcpy(p[i].ans,p[i].name);
		}
	}
	for(i=0;i<n;i++)
	{
		l=1;
		p[i].ind[0]=i+1;
		p[i].count=1;
		for(j=i+1;j<n;j++)
		{
			if(p[j].ans[0]!=-1)
			{
				if(strcmp(p[i].ans,p[j].ans)==0)
				{
					p[i].count++;
					p[i].ind[l++]=j+1;
					p[j].ans[0]=-1;
				}
			}
		}
		p[i].ind[l]=-1;
	}
	for(i=0;i<n;i++)
	{
		if(p[i].ans[0]!=-1)
		{
			printf("%s %d [",p[i].ans,p[i].count);
			for(m=0;p[i].ind[m]!=-1;m++)
			{
				printf("%d,",p[i].ind[m]);
			}
			printf("]\n");
		}
	}
	return 0;
}
