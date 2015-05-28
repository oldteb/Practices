#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define    ARR_SIZE       20


int data_init(const char* ccp, int arr[]);
int print_2(int **a, int n);
int print_path(int arr[], int **m,int **s,int j, int i);
int Matrix_chain(int arr[]);

int main()
{
    int arr[ARR_SIZE];
    data_init("Matrix-chain product.dat",arr);
    Matrix_chain(arr);
    
    system("pause");
    return 0;
} 



int data_init(const char* ccp, int arr[])
{
    int i,tital;
    FILE* fp;
    fp = fopen(ccp,"r");
    for(i=1,fscanf(fp,"%d",&arr[0]);i<=arr[0];i++)
        fscanf(fp,"%d",&arr[i]);
    fclose(fp);
    return 0;    
}


int print_2(int **a, int n)
{
    int i,j;
    printf("print the vertex:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            printf("%-10d",a[i][j]);
        printf("\n");
    }
    return 0;    
}

int print_path(int arr[], int **m,int **s,int j, int i)
{
    if(j==i)
    {
        printf("A%d",j);
        return 1;        
    }
    else 
    {
        printf("(");
        print_path(arr,m,s,j,s[j][i]);
        print_path(arr,m,s,s[j][i]+1,i);
        printf(")",i);
        return 1;
    }  
}


int Matrix_chain(int arr[])
{
    int i,j,k;
    int mid;
    int **m,**s;
    int matrix_num;
    matrix_num = arr[0]-1;
    if(matrix_num<1)
    {
        printf("matrix number ERROR!"); 
        system("pause");
        exit(0);               
    }
    //动态申请M矩阵记录最小标量乘法次数及S矩阵记录分界点 
    m = (int **)malloc((matrix_num+1)*sizeof(int *));
    for(i=0;i<=matrix_num;i++)
        m[i] = (int *)malloc((matrix_num+1)*sizeof(int));     
    s = (int **)malloc((matrix_num+1)*sizeof(int *));
    for(i=0;i<=matrix_num;i++)
        s[i] = (int *)malloc((matrix_num+1)*sizeof(int));   
    //初始化矩阵M及S  
    for(i=0;i<=matrix_num;i++)
    {
        for(j=0;j<=matrix_num;j++)
        {
            if(i==j)
            {
                m[i][j] = 0;
                s[i][j] = i;        
            }
            else
            {
                m[i][j] = 0;
                s[i][j] = 0;
            }                                
        }
                         
    }
    for(i=2;i<=matrix_num;i++)
        for(j=i-1;j>=1;j--)
        {
            if(i-j==1)
            {
                m[j][i] = arr[j]*arr[i]*arr[i+1];
                s[j][i] = j;
                continue;
            }
            for(k=j,mid=INT_MAX;k<=i-1;k++)
            {
                if(mid>m[j][k]+m[k+1][i]+arr[j]*arr[k+1]*arr[i+1])   
                {
                    mid = m[j][k]+m[k+1][i]+arr[j]*arr[k+1]*arr[i+1];
                    s[j][i] = k;                                                   
                }                    
            } 
            m[j][i] = mid;                     
        }
    //print_2(m,matrix_num);
    //print_2(s,matrix_num);
    print_path(arr,m,s,1,matrix_num);
    return 0;   
}
