#include <stdio.h>
#include <stdlib.h>
int Compare(int a,int b)
{
    if(a==b)    return 0;
    else if(a>b)       return 1;
    return 2;
} 
int main()
{
    int a,b,c;
    scanf("%d %d",&a,&b);
    c=Compare(a,b);
    switch(c)
    {
                 case 0: printf("a's value is the same with the b's"); break;
                 case 1: printf("%d",a); break;
                 case 2: printf("%d",b); 
                 default:;
    }

  
  system("PAUSE");	
  return 0;
}
