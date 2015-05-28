#include<stdio.h>
#include<stdlib.h>

#define  BUFSIZE     10
#define  MAXINT      100000


int SJF(int arr[]);

int main()
{
    int arr[BUFSIZE] = {4,15,8,3,10};
    SJF(arr);
    system("pause");
    return 0;   
}


int SJF(int arr[])
{
    int result[BUFSIZE]={0};
    int i,j,d,min;
    int s[BUFSIZE];
    for(i=0;i<BUFSIZE;i++)
        s[i]=arr[i];
    for(i=1;i<=s[0];i++)
    {
        for(j=2,min=s[1];j<=s[0];j++)
        {
            if(min>s[j])
            {
                min = s[j];
                d = j;
            }
        }
        if(min==s[1])  d = 1;
        result[i] = d;
        s[d] = MAXINT;
    }
    
    for(i=1,d=0;i<=arr[0];i++)
    {
        printf("[%d]j%d\n",i,result[i]); 
        d = d+(arr[0]-(i-1))*arr[result[i]];
    }
    d = d/arr[0];
    printf("The minimum average completion time is:%d\n",d);          
    return 0;   
}
