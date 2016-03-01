struct date
{
	int months[12];
	char name_month[12][5];
	char days[7][5];
	int Year_Date[12];
	int year,month,date;
}s={{0,3,3,6,1,4,6,2,5,0,3,5},
	{"Jan","Feb","mar","Apr","May","June","July","Aug","Sep","Oct","Nov","Dec"},
					{"sun","mon","tue","wed","thu","fri","sat"},
					{31,28,31,30,31,30,31,30,31,30,31,30}
				  };
#include<stdio.h>
#include<stdlib.h>
char Gstr[10]={0};
char* MonthName(int month);
char* Pre_Mon_Name(int month);
int NUMBEROFDAYS();
void DateBefore(int n);
char* Difference_Days(int n);
char* Week_Day_Name(int year,int C_month,int date);
int main(int argc, char const *argv[])
{
	int l=0;
	int Year_Date[12]={31,28,31,30,31,30,31,30,31,30,31,30};
	if(s.year%400==0 ||((s.year%4==0)&&(s.year%100!=0)))
	{
		l=1;
		Year_Date[1]=29;
	}
	char *month_name;
	char *prev_month_name;
	char *day_name;
	char *diff_days;
	int n;
	int num_of_Days;
	scanf("%d/%d/%d",&s.year,&s.month,&s.date);
	printf("current year %d\n",s.year);
	printf("pre year %d\n",s.year-1);
	printf("month in num %d\n",s.month);
	
	month_name=MonthName(s.month);
	printf("month name %s\n",month_name );
	
	prev_month_name=Pre_Mon_Name((s.month-1));
	printf("Prev month %s\n",prev_month_name);

	printf("Date in num %d\n",s.date);

	day_name=Week_Day_Name(s.year,s.months[s.month-1],s.date);
	printf("Day name %s\n",day_name);

	num_of_Days=NUMBEROFDAYS();
	printf("%d\n",num_of_Days);

	printf("Date before \n");
	scanf("%d",&n);
	DateBefore(n);
	printf("%s\n",Gstr);
	diff_days=Difference_Days(n);
	printf("%s\n",diff_days);
	return 0;
}
char* Difference_Days(int n)
{
	int i=0;
	char* str=(char*)malloc(100);
	//char* str=(char*)malloc((n*3*sizeof(char))+n);
	char* ans;
	int pole=s.date;
	while(n--)
	{
		ans=Week_Day_Name(s.year,s.months[s.month-1],pole--);
		sprintf(str,"%s",ans);
		for(int k=0;str[k]!=0;k++)
		{
			ans[i]=str[k];
			i++;
		}
		ans[i++]=',';
	}
	ans[i++]=0;
	return ans;
}
void DateBefore(int n)
{
	
	int tMon=0;
	int tYear=s.year;
	int tDate=0;
	if(n>s.date)
	{
		tMon=s.month-1;
		if(tMon==0)
		{
			tYear=s.year-1;
		}
		n=n-s.date;
		tDate=(s.Year_Date[tMon-1])-n;
	}
	else
	{
		tMon=s.month;
		tDate=s.date-n;
	}
	sprintf(Gstr,"%d/%d/%d",tYear,tMon,tDate);
}

char* MonthName(int month)
{
	char *str1=s.name_month[month-1];
	return str1;
}
char* Pre_Mon_Name(int month)
{
	char *str1=s.name_month[month-1];
	return str1;
}
char* Week_Day_Name(int year,int C_month,int date)
{
	int leap;
	int tyear;
	int ans;
	int day_offset=0;
	int tcen=year/100;
	if(tcen%4==0)
	{
		tcen=tcen+4;
	}
	else
	{
		while(tcen%4!=0)
		{
			tcen++;
		}
	}
	tcen=tcen-1;
	tcen=tcen-(year/100);
	tcen=tcen*2;
	leap=1;
	if(year%400==0 || ((year%4 == 0)&&(year%100 != 0)))
	{
		leap=1;
	}
	else
	{
		leap=0;
	}
	if(leap)
	{
		tyear=(((year%100)+((year%100)/4))%7)-1;
	}
	else
	{
		tyear=(((year%100)+((year%100)/4))%7);
	}
	day_offset=date%7;
	ans=day_offset+tyear+tcen+C_month;
	ans=ans%7;
	return s.days[ans+1];
}
int NUMBEROFDAYS()
{
	int l=0;
	int days=0;
	int Year_Date[12]={31,28,31,30,31,30,31,30,31,30,31,30};
	if(s.year%400==0 ||((s.year%4==0)&&(s.year%100!=0)))
	{
		l=1;
		Year_Date[1]=29;
	}
	for(int i=0;i<s.month-1;i++)
	{
		days=days+Year_Date[i];
	}
	days=days+s.date;
	return days;
}
