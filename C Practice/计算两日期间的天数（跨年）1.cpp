#include<stdio.h>
#include<stdlib.h>
int main()
{
    int y1,y2,m1,m2,d1,d2,i,fresult,sum=0,o,p,q;
    int Days(int year,int month1,int month2,int day1,int day2);
    printf("Please input the first date:\n");
    scanf("%d,%d,%d",&y1,&m1,&d1);
    printf("Please input the second date:\n");
    scanf("%d,%d,%d",&y2,&m2,&d2);
    if(y1==y2&&m1==m2)
        fresult=d2-d1;
    else if(y1==y2&&m1!=m2)
        fresult=Days(y1,m1,m2,d1,d2);
    else
    {
        for(i=1;i<y2-y1;i++)
        {
            if((y1+i)%4==0&&(y1+i)%100!=0||(y1+i)%400==0)
                sum=sum+366;
            else
                sum=sum+356;
        }
        o=12;p=1;q=31;
        fresult=sum+Days(y1,m1,o,d1,q)+Days(y2,p,m2,p,d2);
    }
    printf("Days between is %d.\n",fresult);
    system("PAUSE");
    return 0;
}

int Days(int year,int month1,int month2,int day1,int day2)
{
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
    return sum;
}
    
    
    











 
