#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct{
    int vertex;
    int edge;
    int** A;
}matrix;


int init_data(matrix &a,const char* ccp);
int print_path(int** D, int** T,int x, int y); 
int floyd_warshall(matrix &a);


int main()
{
    matrix a;
    init_data(a,"BellmanFord1.dat");
    floyd_warshall(a); 
    system("pause");
    return 0;   
}



int init_data(matrix &a,const char* ccp){
    int i,j;
    FILE* fp;
    int** f;
    fp = fopen(ccp,"r");
    if(fp<0)  
    {
        perror("fopen");
        exit(0);
    }
    fscanf(fp,"%d %d",&(a.vertex),&(a.edge));
    //动态申请数组A[n+1][n+1] 及 E[] 
    f = (int**)malloc((a.vertex+1)*sizeof(int *));
    for(i=0;i<=a.vertex;i++)  
        f[i] = (int *)malloc((a.vertex+1)*sizeof(int));
    a.A = f;
    for(i=1;i<=a.vertex;i++)
        for(j=1;j<=a.vertex;j++)
            fscanf(fp,"%d",&a.A[i][j]);
    fclose(fp);
    return 0;   
}

int print_path(int** D, int** T,int x, int y)
{
    if(x==T[x][y])
    {
        printf("(%d)",x);
        printf("-->(%d)",y);
        return 0;
    }
    else if(T[x][y]==0)
    {
        printf("can't reach!\n");
        return 0;
    }
    else
    {
        print_path(D,T,x,T[x][y]);  
        printf("-->(%d)",y);
        return 0;  
    } 
}


int floyd_warshall(matrix &a)
{
    int i,j,k;
    int n = a.vertex;
    int **D,**T,**DP,**TP;
    //动态申请数组D[n][n] 及 T[n][n] 
    
    D = (int**)malloc((n+1)*sizeof(int *));
    for(i=0;i<=n;i++)  
        D[i] = (int *)malloc((n+1)*sizeof(int));
    T = (int**)malloc((n+1)*sizeof(int *));
    for(i=0;i<=n;i++)  
        T[i] = (int *)malloc((n+1)*sizeof(int));  
    DP = (int**)malloc((n+1)*sizeof(int *));
    for(i=0;i<=n;i++)  
        DP[i] = (int *)malloc((n+1)*sizeof(int));
    TP = (int**)malloc((n+1)*sizeof(int *));
    for(i=0;i<=n;i++)  
        TP[i] = (int *)malloc((n+1)*sizeof(int));
    
    //InitD[][] and T[][]...
     for(i=1;i<=n;i++)     
         for(j=1;j<=n;j++)
         {
             if(i==j)  D[i][j] = 0;
             else if(a.A[i][j]==0)  D[i][j] = INT_MAX;
             else D[i][j] = a.A[i][j];
             
             if(D[i][j]!=0 && D[i][j]!=INT_MAX)  T[i][j] = i;    
             else T[i][j] = 0;
         }
     /*for(i=1;i<=n;i++)
        {
            printf("%-12d%-12d%-12d%-12d%-12d%-12d\n",D[i][1],D[i][2],D[i][3],D[i][4],D[i][5],D[i][6]);               
        }
        system("pause");
        */
    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
            {
                if(D[i][j]==INT_MAX && (D[i][k]==INT_MAX || D[k][j]==INT_MAX))  
                {
                    DP[i][j] = INT_MAX;
                    TP[i][j] = T[i][j];
                }
                else if(D[i][j]!=INT_MAX && (D[i][k]==INT_MAX || D[k][j]==INT_MAX))
                {
                    DP[i][j] = D[i][j];      
                    TP[i][j] = T[i][j]; 
                }
                else if(D[i][j]<=D[i][k]+D[k][j])
                {
                    DP[i][j] = D[i][j];      
                    TP[i][j] = T[i][j]; 
                       
                }
                else
                {
                    DP[i][j] = D[i][k]+D[k][j]; 
                    if(k==j)  TP[i][j] = T[i][j];   
                    else  TP[i][j] = T[k][j];          
                }            
            } 
        
        
        /*for(i=1;i<=n;i++)
        {
            printf("%-12d%-12d%-12d%-12d%-12d%-12d\n",DP[i][1],DP[i][2],DP[i][3],DP[i][4],DP[i][5],DP[i][6]);               
        }
        system("pause");
        */
        
        //替换D[][]与T[][]      
        for(i=1;i<=n;i++)     
            for(j=1;j<=n;j++)
            {
                D[i][j] = DP[i][j];
                T[i][j] = TP[i][j];
            }
    }
    //print the route...      
    
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(i==j)  continue;
            else
            {
                printf("From (%d) to (%d):",i,j); 
                print_path(D,T,i,j);
                if(D[i][j]==INT_MAX)  continue;
                else  printf("\n\tThe total value:%d\n",D[i][j]);
            }
                             
    
    return 0;   
}
