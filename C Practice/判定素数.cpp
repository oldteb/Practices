#include<stdio.h>
#include<stdlib.h>
int main()
{
     int n,i;
     printf("Please input a number:\n");
     scanf("%d",&n);
     for(i=2;i<=n/i;i++)
     {
         if(n%i==0)
         {
             printf("Number %d is not a prime.\n",n);         /*primeÎªËØÊý*/  
             system("PAUSE");
             exit(0);
         }
     }
     printf("Number %d is a prime.\n",n);
     system("PAUSE");
     return 0; 
}    
