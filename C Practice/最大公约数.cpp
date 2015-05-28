#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a,b,i,n;
    printf("Please input two integers:\n");
    scanf("%d,%d",&a,&b);
    if(a<=b)
        i=a;
    else
        i=b;
    for(;i>1;i--)
    {
        if(a%i==0&&b%i==0)
        {
            printf("%d",i);
            system("PAUSE");
            exit(0);
        }
    }
    if(i==1) printf("1.\n");
    system("PAUSE");
    
    return 0;
}
