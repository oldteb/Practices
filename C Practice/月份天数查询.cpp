#include <stdio.h>
#include <stdlib.h>
int LeapYear(int a)
{
    
    if(a%4==0&&a%100!=0||a%400==0) return 1;      /*1为闰年，0为平年*/ 
    else return 0;
}

int main()
{
    int a,b,d;
    scanf("%d,%d",&a,&b);
    switch(b)
    {
             case 1:case 3:case 5:case 7:case 8:case 10:case 12: d=31; break;
             case 4:case 6:case 9:case 11: d=30; break;
             case 2: d=28+LeapYear(a); break;
    }
    printf("days=%d",d);
    
   system("PAUSE");
   return 0;
}
