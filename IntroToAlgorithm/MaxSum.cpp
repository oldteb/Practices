#include<string.h>
#include<stdio.h>
#include<stdlib.h>

#define    ARR_SIZE      50


int data_init(const char* ccp,int a[]);
int max_sum(int arr[]);


int main()
{
    int mid,a;
    int arr[ARR_SIZE];
    data_init("MaxSum.dat",arr);
    max_sum(arr);
    system("pause");
    return 0;   
}


int data_init(const char* ccp,int a[])
{
    int mid,count=0;
    FILE* fp = fopen(ccp,"r");
    while(fscanf(fp,"%d",&a[count+1])==1)
        count++;                          
    a[0] = count;
    fclose(fp);  
    return 0;   
}

int max_sum(int arr[])
{
    int i,max;
    int b[ARR_SIZE] = {0};   //b[i]用来记录以第i个数字为结束的最大和 
    int t[ARR_SIZE] = {0};   //t[i]用来记录串长 
    b[1] = arr[1];  t[1] = 1;
    for(i=2,max=1;i<=arr[0];i++)
    {
        if(b[i-1]>0)
        {
            b[i] = b[i-1]+arr[i];
            t[i] = t[i-1]+1;          
        }  
        else
        {
            b[i] = arr[i];
            t[i] = 1; 
        } 
        if(b[i]>b[max])
            max = i;                                     
    }
    //打印 
    for(i=1;i<=arr[0];i++)
    {
        if(i==max-t[max]+1)
            printf("(");      
        printf(" %d ",arr[i]);
        if(i==max)
            printf(")");                     
    }
    printf("\nThe max sum is:%d",b[max]);
    return 0;   
}
