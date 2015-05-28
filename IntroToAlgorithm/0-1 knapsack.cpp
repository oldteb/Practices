#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


#define   SIZE    32       
#define   W       100      //compacity

typedef struct{
    int   value;
    int   weight;
    float vwrate;
}item;

int data_init(const char *);
int print_path(int i, int j, int **f, int **result);
int zero_one_knapsack(int n, int w);

int total=0;                               //共多少个item 
item arr[SIZE]={0};                         

int main()
{
    data_init("knapsack.dat");
    printf("max value:%d\n",zero_one_knapsack(total,W));
    system("pause");
    return 0;   
}


int data_init(const char * ccp)
{
    int i=1;
    FILE* fp;
    fp = fopen(ccp,"r");
    if(fp<0)  
    {
        perror("fopen");
        exit(0);
    }
    fscanf(fp,"%d",&total);
    while(i<=total)
    {
        fscanf(fp,"%d %d %f",&arr[i].value,&arr[i].weight,&arr[i].vwrate);
        i++;
    }
    fclose(fp);
    return 0;
}



int print_path(int i, int j, int **f, int **result)
{
    if(i==1)
    {
        if(result[1][j]==1)
        {
            printf("Select:(%d)",i); 
            return 0;                 
        }
        else if(result[i][j]==0)
        {
            return 0;    
        }
    }
    else
    {
        if(result[i][j]==1)
        { 
            print_path(i-1,j-arr[i].weight,f,result);
            printf("(%d)",i);
            return 0;                 
        }
        else if(result[i][j]==0)
        {
            print_path(i-1,j,f,result);
            return 0;    
        }         
    } 
    return 0;
}


int zero_one_knapsack(int n, int w)
{
    int i,j,max;
    int **f,**result;
    //动态申请数组f[n+1][w+1] and result[]
    f = (int**)malloc((n+1)*sizeof(int *));
    for(i=0;i<=n;i++)  
        f[i] = (int *)malloc((w+1)*sizeof(int)); 
    result = (int**)malloc((n+1)*sizeof(int *));
    for(i=0;i<=n;i++)  
        result[i] = (int *)malloc((w+1)*sizeof(int));       
    for(i=0;i<=w;i++)
    {                
        f[0][i] = 0;
        result[0][i] = 0;
    }
    for(i=1;i<=n;i++)
    {
        for(j=0;j<=w;j++)
        {
            //选择要不要加入第i件物品 
            if(j-arr[i].weight>=0 && f[i-1][j-arr[i].weight]+arr[i].value>f[i-1][j])
            {
                f[i][j] = f[i-1][j-arr[i].weight]+arr[i].value;
                result[i][j] = 1;
                continue; 
            }
            else
            {
                f[i][j] = f[i-1][j];
                result[i][j] = 0;
                continue;
            }
        }
    }    
    for(i=2,j=1,max = f[n][1];i<=w;i++)
    {
        if(max < f[n][i])
        {
            max = f[n][i];
            j = i;
        }
    }   
    print_path(n,j,f,result);
    printf("\n");    
    return max;  
}

