#include <stdio.h>
#include <stdlib.h>

#define   SIZE    32


typedef struct{
    int   value;
    int   weight;
    float vwrate;
}item;


int data_init(int* total,item arr[]);
int fractional_knapsack(int total, item arr[], int result[]);

int main()
{
    int i;
    int total=0;
    item arr[SIZE];
    int result[SIZE]={0};
    data_init(&total,arr);
    fractional_knapsack(total,arr,result);
    
    for(i=1;i<=total;i++)
        printf("result[%d]:%d \n",i,result[i]);
    
    system("pause");
    return 0;
}


int data_init(int* total,item arr[])
{
    int i=1;
    FILE* fp;
    fp = fopen("knapsack.dat","r");
    if(fp<0)  
    {
        perror("fopen");
        exit(0);
    }
    //if(fread(&arr[i++],1,1,fp)!=1)  exit(0);
    fscanf(fp,"%d",total);
    while(i<=(*total))
    {
        fscanf(fp,"%d %d %f",&arr[i].value,&arr[i].weight,&arr[i].vwrate);
        i++;
    }
    fclose(fp);
    return 0;
}

int fractional_knapsack(int total, item arr[], int result[])
{
    int i,surplus=100;
    //for(i=1;i<=total;i++)  surplus += arr[i].weight;
    for(i=1;i<=total;i++)
    {
        if(arr[i].weight<=surplus)
        {
            surplus -= arr[i].weight;
            result[i] = arr[i].weight;
            continue;
        }
        else
        {
            result[i] = surplus;
            break;
        }
    }
    
    return 0;
}



    
/**错误总结：
1. typedef   与struct 混淆
2. fread函数在读ASCII文件的时候会将字符的ASCII值读入，而不是按整型读入。
   但是fscanf函数能规定读入格式，故能按指定格式读入。
   
   **/ 
    
    
    
    
    
    
    
