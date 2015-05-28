/*
程序名称：万年历
功能：输入一个年份和一个月份，打印出该月的月历。      */

#include<stdio.h>
#include<stdlib.h>

typedef enum{Su,Mo,Tu,We,Th,Fr,Sa}WEEKDAY;

int main()
{
    int days_of_month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int leap_year(int b);
    int year,month,a,i=0,sum=0,y;
    WEEKDAY weekday;
    printf("Please input a year and a month:\n");
    scanf("%d,%d",&year,&month);
    if(year<0||month>12||month<1)
    {
        printf("Numbers error!\n");
        system("PAUSE");
        return 0;
    }
    if(year<2000) a=2000-year;
    else  a=year-2000;
    for(;i<a;i++)
    {
        if(year<2000)  y=year+i;
        else  y=2000+i;
        sum=sum+365+leap_year(y);
    }
    if(year<2000)  y=13-sum%7;
    else  y=6+sum%7;
    weekday=(WEEKDAY)(y%7);
    if(leap_year(year)) days_of_month[1]=29;
    for(i=1,sum=0;i<month;i++)
        sum=sum+days_of_month[i-1];
    weekday=(WEEKDAY)(((int)weekday+sum%7)%7);
    /*此时weekday为该年月1日的星期*/
    printf("Calendar %d-%d\n",year,month);
    printf("-----------------------------\n");
    printf("Su  Mo  Tu  We  Th  Fr  Sa\n");
    printf("-----------------------------\n");
    a=(int)weekday;
    i=1;
    switch(a)
        {
            case 0: printf("%2d",i);break; 
            case 1: printf("%6d",i);break;
            case 2: printf("%10d",i);break;
            case 3: printf("%14d",i);break;
            case 4: printf("%18d",i);break;
            case 5: printf("%22d",i);break;
            case 6: printf("%26d\n",i);
        }
    
    for(i=2;i<=days_of_month[month-1];i++)
    {
        a=((int)weekday+i-1)%7;
        switch(a)
        {
            case 0: printf("%2d",i);break; 
            case 1: printf("%4d",i);break;
            case 2: printf("%4d",i);break;
            case 3: printf("%4d",i);break;
            case 4: printf("%4d",i);break;
            case 5: printf("%4d",i);break;
            case 6: printf("%4d\n",i);
        }
    }
    printf("\n");
    printf("\n");
    system("PAUSE");
    return 0;
}

int leap_year(int b)
{
    int a=0;
    if(b%4==0&&b%100!=0||b%400==0)  a=1;
    return a;
}     
