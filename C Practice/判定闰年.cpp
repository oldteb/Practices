#include<stdio.h>
#include<stdlib.h>

int main()
{
    int year;
    printf("Please input a year:\n");
    scanf("%d",&year);
    if(year%4==0&&year%100!=0||year%400==0)
        printf("%d is a leap year.\n",year);       /*leap year Ϊ����*/ 
    else
        printf("%d is not a leap year.\n",year);
    system("PAUSE");
    return 0;
}
