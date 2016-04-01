#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<unistd.h>
int numberofwords(FILE*);
int numberofletters(FILE*);
int numberofspecial(FILE*);
void threecommonletters(FILE*);
void threecommonstring(FILE*);
int main()
{
	FILE *fp;
	int number_of_letters=0;
	int number_of_words=0;
	int number_of_special=0; 
	fp=fopen("bharadwaj","r");
	if(fp==NULL)
	{
		perror("Sorry Cant open the file");
	}
	else
	{
		number_of_words=numberofwords(fp);
		printf("Number of words:%d\n",number_of_words);
		rewind(fp);
		number_of_letters=numberofletters(fp);
		printf("Number of letters:%d\n",number_of_letters);
		rewind(fp);
		number_of_special=numberofspecial(fp);
		printf("Number of special symbols:%d\n",number_of_special);
		rewind(fp);
		threecommonstring(fp);
		rewind(fp);
		threecommonletters(fp);
		rewind(fp);
	}
	return 0;
}
void threecommonletters(FILE *fp)
{
	char ch;
	char ans[26]={0};
	char char_array[27]="abcdefghijklmnopqrstuvwxyz";
	while(!feof(fp))
	{
		ch=getc(fp);
		if(isupper(ch))
		{
			ans[ch-65]=ans[ch-65]+1;
		}
		else if(islower(ch))
		{
			ans[ch-97]=ans[ch-97]+1;
		}
	}
	char temp_var='0';
	char temp_num=0;
	for(int i=0;i<26;i++)
	{
		for(int j=0;j<26;j++)
		{
			if(ans[i]>ans[j])
			{
				temp_var=char_array[i];
				char_array[j]=char_array[i];
				char_array[i]=temp_var;
				temp_num=ans[i];
				ans[i]=ans[j];
				ans[j]=temp_num;
			}
		}
	}
	printf("Top frequent letters\n");
	for(int i=0;i<3;i++)
	{
		printf("%c %d\n",char_array[i],ans[i]);	
	}
}
void threecommonstring(FILE *fp)
{
	long number_of_char=0;
	char *str;
	if (fp)
	{
  		fseek (fp, 0, SEEK_END);
  		number_of_char = ftell (fp);
  		fseek (fp, 0, SEEK_SET);
  		str =(char*) malloc (sizeof(char)*number_of_char);
  		if (str)
  		{
    		fread (str, 1, number_of_char, fp);
  		}
	}
  	int slen = strlen(str);
	char temp[2000][2000];
	int w = 0;
	int wc = 0;
	for (int i = 0; i <= slen; i++)
	{
		if (str[i] != ' ' && str[i] != '.')
		{
			temp[w][wc] = str[i];
			wc++;
		}
		else
		{
			temp[w][wc] = '\0';
			w++;
			wc = 0;
		}
	}
 
	int map[2000][2];
	int m = 0;
	for (int i = 0; i <= w; i++)
	{
		map[i][0] = 1;
		map[i][1] = i;
		for (int k = 0; k <= w; k++)
		{
			if (i != k)
			{
				if (strcmp(temp[i], "\0"))
				{
					if (!strcasecmp(temp[i], temp[k]))
					{
						map[i][0]++;
						strcpy(temp[k], "\0");
					}
				}
			}
		}
	}
	int temp_var;
	for (int y = 0; y < w; y++)
	{
		for (int a = 0; a < w; a++)
		{
			if (map[a][0] < map[a + 1][0])
			{
				temp_var = map[a + 1][0];
				map[a + 1][0] = map[a][0];
				map[a][0] = temp_var;
 
				temp_var = map[a + 1][1];
				map[a + 1][1] = map[a][1];
				map[a][1] = temp_var;
			}
		}
	}
	printf("Frequent 3 words \n");
	for (int n = 0; n < 3; n++)
	{
		if (map[n][0] != 1)
		{
			printf("%s %d\n",temp[map[n][1]],map[n][0]);
		}
 
	}
}
int numberofspecial(FILE *fp)
{
	int n;
	char c;
	while(!feof(fp))
	{
		c=fgetc(fp);
		if(!( (c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9') ) )
		{
			n++;
		}
	}
	return n;
}
int numberofletters(FILE *fp)
{
	int n=0;
	char c;
	while(!feof(fp))
	{
		c=getc(fp);
		if( (c<='z'&&c>='a' )|| (c<='Z'&&c>='A')||(c<='9'&&c>='0') ) 
		{
			n++;
		}
	}
	return n;
}
int numberofwords(FILE *fp)
{
	int n=0;
	char c;
	while(!feof(fp))
	{
		c=getc(fp);
		if(c==' '||c=='.'||c=='!')
		{
			n++;
		}
	}
	return n;
}
