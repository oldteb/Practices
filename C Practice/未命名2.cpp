#include <stdio.h>
#include <stdlib.h>

int LeapYear(int a)
{
    
    if(a%4==0&&a%100!=0||a%400==0) return 1;      /*1Ϊ���꣬0Ϊƽ��*/ 
    else return 0;
}
  
int main()
{
    int c,a;
    scanf("%d",&a);
    c=LeapYear(a);
    printf("%d",c);
    
    

   system("PAUSE");
   return 0;
}
