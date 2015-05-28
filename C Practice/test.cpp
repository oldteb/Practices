#include<stdio.h>
#include<stdlib.h>

int main()
{
    int year=2001,month1=12,month2=12,day1=28,day2=31;
    int days[12]={31,28,31,30,31,30,31,31,30,31,30,31},i,sum;
    if(year%4==0&&year%100!=0||year%400==0)
        days[1]=29;
    if(month1==month2)
        sum=day2-day1;
    else
    { 
        for(i=1,sum=0;i<month2-month1;i++)
            sum=sum+days[month1+i];
        sum=sum+days[month1]-day1+day2;
    }
    printf("%d",sum);
    system("PAUSE");
    return 0;
}
