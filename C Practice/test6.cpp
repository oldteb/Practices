#include<stdio.h>
#include<stdlib.h>

typedef enum{Su,Mo,Tu,We,Th,Fr,Sa}WEEKDAY;
int main()
{
    int days_of_month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int leap_year(int b);
    int year,month,a,i=0,sum=0;
    WEEKDAY weekday;
    printf("Please input a year and a month:\n");
    scanf("%d,%d",&year,&month);
    for(a=year-2000;i<a;i++)
        sum=sum+365+leap_year(2000+i);
    weekday=(WEEKDAY)((6+sum%7)%7);
    if(leap_year(year)) days_of_month[1]=29;
    for(i=1,sum=0;i<month;i++)
        sum=sum+days_of_month[i-1];
    weekday=(WEEKDAY)(((int)weekday+sum%7)%7);
    a=(int)weekday;
    printf("%d",a);
    system("PAUSE");
    return 0;
}
int leap_year(int b)
{
    int a=0;
    if(b%4==0&&b%100!=0||b%400==0)  a=1;
    return a;
}     
