#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


typedef struct{
    int x;
    int y;
}point;


typedef struct{
    int vertex;
    int edge;
    int** A;
    point* E;
}matrix;

int print(matrix &a);
int init_data(matrix* a,const char* ccp);
int extract(matrix &a,int *d,int *s_arr);
int* Dijkstra(matrix &a, int s);
int bellman_ford(matrix& a,int s,int **h);
int Johnson(matrix &a);

int main()
{
    matrix a;
    init_data(&a,"Johnson.dat");
    Johnson(a);
    system("pause");
    return 0;    
}

int print(matrix &a)
{
    int i,j;
    printf("print the vertex:\n");
    for(i=0;i<a.vertex;i++)
    {
        for(j=0;j<a.vertex;j++)
            printf("%-9d",a.A[i][j]);
        printf("\n");
    }
    return 0;    
}

int init_data(matrix* a,const char* ccp){
    int i,j;
    FILE* fp;
    int** f;
    point* p;
    int test1;
    fp = fopen(ccp,"r");
    if(!fp)  
    {
        perror("fopen");
        system("pause");
        exit(0);
    }
    fscanf(fp,"%d %d",&(a->vertex),&(a->edge));
    //动态申请数组A[n+1][n+1] 及 E[] 
    f = (int**)malloc((a->vertex+1)*sizeof(int *));
    for(i=0;i<=a->vertex;i++)  
        f[i] = (int *)malloc((a->vertex+1)*sizeof(int));
    p = (point *)malloc((a->edge+1)*sizeof(point));
    a->A = f;
    a->E = p;
    for(i=1;i<=a->vertex;i++)
        for(j=1;j<=a->vertex;j++)
            fscanf(fp,"%d",&a->A[i][j]);
    for(i=1;i<=a->edge;i++)
        fscanf(fp,"%d %d",&a->E[i].x,&a->E[i].y);
    fclose(fp);
    return 0;   
}

int bellman_ford(matrix& a,int s,int *&h)
{
    int i,j,x;
    int* d = (int *)malloc((a.vertex+1)*sizeof(int));
    int* f = (int *)malloc((a.vertex+1)*sizeof(int));

    //initialize the d[] and f[]...
    for(i=0;i<=a.vertex;i++)
    {
        d[i] = INT_MAX;
        f[i] = 0;                   
    }
    d[s] = 0;     
    for(i=1;i<=a.vertex-1;i++)
    {
        for(j=1;j<=a.edge;j++)
        {
            if(d[a.E[j].y]==INT_MAX && (d[a.E[j].x]==INT_MAX || a.A[a.E[j].x][a.E[j].y]==INT_MAX))
                continue;
            else if(d[a.E[j].y]!=INT_MAX && (d[a.E[j].x]==INT_MAX || a.A[a.E[j].x][a.E[j].y]==INT_MAX))
                continue;  
            if(d[a.E[j].y]>d[a.E[j].x]+a.A[a.E[j].x][a.E[j].y])
            {
                d[a.E[j].y] = d[a.E[j].x]+a.A[a.E[j].x][a.E[j].y];
                f[a.E[j].y] = a.E[j].x;                           
            }                      
        }
        
        for(x=0;x<=a.vertex-1;x++)        
            printf("%d   ",d[x]);
        printf("\n");
        for(x=0;x<=a.vertex-1;x++)        
            printf("%d   ",f[x]);
        printf("\n"); 
        system("pause"); 
              
    }
    
    //检查负环       
    for(j=1;j<=a.edge;j++)
    { 
        if(d[a.E[j].y]==INT_MAX && (d[a.E[j].x]==INT_MAX || a.A[a.E[j].x][a.E[j].y]==INT_MAX))
            continue;
        else if(d[a.E[j].y]!=INT_MAX && (d[a.E[j].x]==INT_MAX || a.A[a.E[j].x][a.E[j].y]==INT_MAX))
            continue;
        else if(d[a.E[j].y]>d[a.E[j].x]+a.A[a.E[j].x][a.E[j].y])
            return 0;
    }
    h = d;
    return 1;   
}



int extract(matrix &a,int *d,int *s_arr)
{
    int i,j,min;
    min = INT_MAX;
    j=0;
    for(i=1;i<=a.vertex;i++)
    {
        if(d[i]<min && s_arr[i]==0)
        {
            min = d[i];
            j = i; 
            continue;           
        }            
        else  continue;            
    }  
    return j;    
}

int* Dijkstra(matrix &a,int s)
{
    int i,j,u;
    int* d = (int *)malloc((a.vertex+1)*sizeof(int));
    int* s_arr = (int *)malloc((a.vertex+1)*sizeof(int));
    for(i=1,d[0]=a.vertex;i<=a.vertex;i++)
        d[i] = INT_MAX;
    d[s] = 0;
    for(i=0;i<=a.vertex;i++)
        s_arr[i] = 0;
    for(i=1;i<=a.vertex;i++)
    {    
        u = extract(a,d,s_arr); 
        //printf("%d\n",u);
        //system("pause");                       
        s_arr[u] = 1;                  //将点u加入S集 
        for(j=1;j<=a.edge;j++)
        {
            if(a.E[j].x==u)
            {
                if(d[a.E[j].y]==INT_MAX && (d[u]==INT_MAX || a.A[u][a.E[j].y]==INT_MAX))  
                    continue;
                else if(d[a.E[j].y]!=INT_MAX && (d[u]==INT_MAX || a.A[u][a.E[j].y]==INT_MAX))
                    continue;
                if(d[a.E[j].y]>d[u]+a.A[u][a.E[j].y])
                {
                    d[a.E[j].y] = d[a.E[j].x]+a.A[a.E[j].x][a.E[j].y];                         
                }
            } 
            else  continue;                      
        }  
    }
    //for(i=1;i<=a.vertex;i++)  printf("d[%d]=%d\n",i,d[i]);
    return d;   
}




int Johnson(matrix &a)
{
    int D[50][50];
    int i,j;
    matrix a1;
    int *h;
    int **f;
    int **t;
    point *p;
    t = (int**)malloc((a.vertex+1)*sizeof(int *));
    //初始化G' 
    f = (int**)malloc((a.vertex+1)*sizeof(int *));
    for(i=0;i<=a.vertex;i++)  
        f[i] = (int *)malloc((a.vertex+1)*sizeof(int));
    p = (point *)malloc((a.edge+1+a.vertex)*sizeof(point));
    
    //初始化a1 
    a1.vertex = a.vertex+1;
    a1.edge = a.edge+a.vertex;
    a1.A = f;
    a1.E = p;
    //初始化a1的邻接矩阵 
    for(i=0;i<a1.vertex;i++)
    {
        for(j=0;j<a1.vertex;j++)       
            if(i==0 || j==0)                       
                a1.A[i][j] = 0;
            else
                a1.A[i][j] = a.A[i][j];                                                   
    }
    //show a1...
    print(a1);
    system("pause");
    //初始化a1的边 
    for(i=1;i<=a.edge;i++)
        a1.E[i] = a.E[i]; 
    for(j=1;i<=a1.edge;i++,j++)
    {
        a1.E[i].x = 0;
        a1.E[i].y = j;     
    }
    //打印边集... 
    for(i=1;i<=a1.edge;i++)
        printf("%d->%d\n",a1.E[i].x,a1.E[i].y);
    system("pause");
    
    if(bellman_ford(a1,0,h)==0)
    {
        printf("ERROR!");
        exit(0);                         
    }                       
    else
    {
        //打印重赋权值之后的a1... 
        for(i=1;i<=a1.vertex;i++)
            printf("h[%d]=%d\n",i-1,h[i-1]);                            
        system("pause");
        
        for(i=1;i<=a1.edge;i++)        
            a1.A[a1.E[i].x][a1.E[i].y] = a1.A[a1.E[i].x][a1.E[i].y]+h[a1.E[i].x]-h[a1.E[i].y];  
        a1.vertex = a.vertex;
        a1.edge = a.edge;
        
        for(i=1;i<=a1.vertex;i++)
        {
            t[i] = Dijkstra(a1,i);
            //打印各点到各点的Dijkstra的算法运行结果... 
            for(j=1;j<=a1.vertex;j++)
                printf("t[%d][%d]=%d\n",i,j,t[i][j]);                            
            system("pause");
            for(j=1;j<=a.vertex;j++)
            {
                D[i][j] = t[i][j]+h[j]-h[i];                            
            }                        
        } 
    }
    //print...
    for(i=1;i<=a.vertex;i++)
    {
        for(j=1;j<=a.vertex;j++)        
            printf("%d  ",D[i][j]);
        printf("\n");
    }
    return 0;   
}

