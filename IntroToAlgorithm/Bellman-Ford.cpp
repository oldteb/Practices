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
int init_data(matrix* a,const char*);
int print_path(int d[],int f[],int s,int i); 
int bellman_ford(matrix& a,int s,int*h);


int main()
{
    matrix a;
    int *h;
    init_data(&a,"BellmanFord1.dat");
    print(a);
    system("pause");
    if(bellman_ford(a,1,h)>0)
        printf("Succeed!\n");
    else
        printf("Failed!\n");
    system("pause");
    return 0;   
}

int print(matrix &a)
{
    int i,j;
    printf("print the vertex:\n");
    for(i=0;i<=a.vertex;i++)
    {
        for(j=0;j<=a.vertex;j++)
            printf("%-7d",a.A[i][j]);
        printf("\n");
    }
    return 0;    
}

int init_data(matrix* a,const char* ccp){
    int i,j;
    FILE* fp;
    int** f;
    point* p;
    fp = fopen(ccp,"r");
    if(fp<=0)  
    {
        perror("fopen");
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
    for(i=0;i<=a->vertex;i++)
        for(j=0;j<=a->vertex;j++)
        {
            if(i==0 || j==0)
            {
                a->A[i][j] = 0;  
                continue;       
            }
            fscanf(fp,"%d",&a->A[i][j]);
        }
    for(i=1;i<=a->edge;i++)
        fscanf(fp,"%d %d",&a->E[i].x,&a->E[i].y);
    for(i=1;i<=a->edge;i++)
        printf("%d->%d\n",a->E[i].x,a->E[i].y);
    system("pause");
    fclose(fp);   
    return 0;   
}


int print_path(int d[],int f[],int s,int i)
{
    if(d[i]==INT_MAX)
    {
        printf("can't reach!\n");
        return 0;                 
    }
    if(f[i]==0)
    {
        printf("(%d)",s);
        return 1;
    }
    else 
        print_path(d,f,s,f[i]);
    printf("-->(%d)",i);
    return 1;   
}


int bellman_ford(matrix& a,int s,int *h)
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
            else if(d[a.E[j].y]>d[a.E[j].x]+a.A[a.E[j].x][a.E[j].y])
            {
                d[a.E[j].y] = d[a.E[j].x]+a.A[a.E[j].x][a.E[j].y];
                f[a.E[j].y] = a.E[j].x;                           
            }  
            //printf("i=%d,j=%d\nd[%d]=%d  ",i,j,a.E[j].y,d[a.E[j].y]);  system("pause");                    
        }
        //每次迭代打印 
        for(x=1;x<=a.vertex;x++)        
            printf("%d   ",d[x]);
        printf("\n");
        for(x=0;x<=a.vertex;x++)        
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
    //打印结果... 
    for(i=0;i<=a.vertex;i++)
    {
        if(i==s)  continue;
        printf("(%d)to(%d):",s,i);     
        if(print_path(d,f,s,i))   
            printf("\ntotal value:%d\n",d[i]);
    }
    h = d;
    return 1;   
}
