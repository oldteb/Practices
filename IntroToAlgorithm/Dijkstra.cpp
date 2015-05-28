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


int init_data(matrix* a,const char* ccp);
int extract(matrix &a,int *d,int *s_arr);
int Dijkstra(matrix &a, int s);

int main()
{
    matrix a;
    init_data(&a,"Dijkstra.dat");
    Dijkstra(a,2);
    
    system("pause");
    return 0;   
}


int init_data(matrix* a,const char* ccp){
    int i,j;
    FILE* fp;
    int** f;
    point* p;
    fp = fopen(ccp,"r");
    if(fp<0)  
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
    for(i=1;i<=a->vertex;i++)
        for(j=1;j<=a->vertex;j++)
            fscanf(fp,"%d",&a->A[i][j]);
    for(i=1;i<=a->edge;i++)
        fscanf(fp,"%d %d",&a->E[i].x,&a->E[i].y);
    fclose(fp);
    return 0;   
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



int Dijkstra(matrix &a,int s)
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
    for(i=1;i<=a.vertex;i++)  printf("d[%d]=%d\n",i,d[i]);
    return 0;   
}
