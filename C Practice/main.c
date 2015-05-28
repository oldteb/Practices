#include <stdio.h>
#include <stdlib.h>
int test(int a,int b)
{
    int c;
    c=a+b;
    return c;
}
    
int main()
{
  int a,b,c;
  scanf("%d\n",&a);
  scanf("%d",&b);
  c=test(a,b);
  printf("%d",c);
  
  system("PAUSE");	
  return 0;
}
