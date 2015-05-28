#include<stdio.h>
#include<stdlib.h>
int days(int m);
/*#define y1 year1
#define y2 year2
#define m1 month1
#define m2 month2
#define days days_of_month
#define d1 day1
#define d2 day2 */

int main()
{
    int y1,y2,m1,m2,d1,d2,sum,sum1,sum2,sum3,result,result1,result2,i,j;
    printf("Please input the first date:\n");
    scanf("%d,%d,%d",&y1,&m1,&d1);
    printf("Please input the secend date:\n");
    scanf("%d,%d,%d",&y2,&m2,&d2);
    if(y1>y2||y1<=y2&&m1>m2||y1<=y2&&m1<=m2&&d1>d2)
    {
        printf("date error!");
        system("PAUSE");
        return 0;
    }
    if(y1==y2&&m1==m2)
        result=d2-d1;
    else if(y1==y2&&m1!=m2)
    {   
        for(i=0,sum=0;i<m2-m1-1;i++)
            sum=sum+days(m1+i+1);
        result=sum+d2+days(m1)-d1;
    }   
    else
    {
        for(i=0,sum1=0;i<y2-y1-1;i++)
        {
            if((y1+i+1)%4==0&&(y1+i+1)%100!=0||(y1+i+1)%400==0)
                j=366;
            else
                j=365;
            sum1=sum1+j;
        }
        for(i=0,sum2=0;i<12-m1-1;i++)
            sum2=sum2+days(m1+i+1);
        result1=sum2+31+days(m1)-d1;
        for(i=0,sum3=0;i<m2-1;i++)
            sum3=sum3+days(i+1);
        result2=365-(sum3+31+days(m1)-d1);
        result=result1+result2+sum1;
        
    
    printf("The days between is %d.\n",result);
    
    system("PAUSE");
    return 0;
}

int days(int m)
{
    int a;
    switch(m)
    {
        case 1:case 3:case 5:case 7:case 8:case 10:case 12: a=31;break;
        case 4:case 6:case 9:case 11: a=30;break;
        case 2: a=28;
    }
    return a;
}
        
    
