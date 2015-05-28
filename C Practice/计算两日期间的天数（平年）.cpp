#include<stdio.h>
#include<stdlib.h>
#define m1 month1
#define m2 month2
#define days days_of_month
#define d1 day1
#define d2 day2

int main()
{
    int m1,m2,d1,d2,sum,result,i;
    int days(int m);
    scanf("%d,%d,%d,%d",&m1,&d1,&m2,&d2);
    if(m1==m2)
        result=d2-d1;
    else
    {   
        for(i=0,sum=0;i<m2-m1-1;i++)
            sum=sum+days(m1+i+1);
        result=sum+d2+days(m1)-d1;
    }   
    
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
        case 2:case 4:case 6:case 9:case 11: a=30;break;
    }
    return a;
}
        
    
