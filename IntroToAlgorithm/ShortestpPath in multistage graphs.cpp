#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define  MAX_VERTEX_NUM     20

typedef struct ArcNode
{
    int from_vex;
    int value;
    ArcNode* nextarc;       
}ArcNode;

typedef struct vnode
{
    int adjvex;
    int qq;
    ArcNode* firstarc;    
}adjlist[MAX_VERTEX_NUM];

typedef struct
{
    adjlist vertices;
    int vexnum;
    int edge;        
}MSGragh;


int init_data(const char* ccp, MSGragh &g);
int print_path(MSGragh &g,int i);
int SPMG(MSGragh &g);

int main()
{
    MSGragh g;
    init_data("Multistages Gragh.dat",g);
    SPMG(g);
    system("pause");
    return 0;    
}



int init_data(const char* ccp, MSGragh &g)
{
    int i=0;
    int peep;
    ArcNode* anp;
    FILE* fp = fopen(ccp,"r");
    fscanf(fp,"%d %d",&g.vexnum,&g.edge);
    //初始化邻接表...每次迭代初始化一个节点 
    for(i=0;i<g.vexnum;i++)
    {
        g.vertices[i].firstarc = NULL;
        g.vertices[i].adjvex = i;
        g.vertices[i].qq = -1;
        if(fscanf(fp,"%d",&peep)==1 && peep!=-1)
        {
            g.vertices[i].firstarc = anp = (ArcNode *)malloc(sizeof(ArcNode)); 
            anp->from_vex = peep;
            fscanf(fp,"%d",&peep);
            anp->value = peep;
            anp->nextarc = NULL;
        }
        else  continue;
        while(fscanf(fp,"%d",&peep)==1 && peep!=-1)
        {                             
            anp->nextarc = (ArcNode *)malloc(sizeof(ArcNode)); 
            anp = anp->nextarc;
            anp->from_vex = peep;
            fscanf(fp,"%d",&peep);
            anp->value = peep;
            anp->nextarc = NULL;           
        }
    }
    fclose(fp);
    return 0;
}


int print_path(MSGragh &g,int i)
{
    if(g.vertices[i].adjvex==0)
    {
        printf("0");
        return 1;                           
    }
    else
    {
        print_path(g,g.vertices[i].qq); 
        printf("->%d",g.vertices[i].adjvex);   
    }
    return 0;   
}


int SPMG(MSGragh &g)
{
    int i;
    ArcNode* anp;          
    int s[MAX_VERTEX_NUM];    //s[i]记录已找到到达节点i的最短路径长度 
    for(i=0;i<g.vexnum;i++)
        s[i] = INT_MAX;       //s[i]初始化为不可达 
    for(i=1,s[0]=0;i<g.vexnum;i++)
    {
        if(g.vertices[i].firstarc == NULL)
            continue; 
        anp = g.vertices[i].firstarc;                
        while(anp!=NULL)
        {            
            if(s[i]>s[anp->from_vex]+(anp->value))
            {
                s[i] = s[anp->from_vex]+anp->value;
                g.vertices[i].qq = anp->from_vex;            
            } 
            anp = anp->nextarc;                
        }   
    }
    //打印路径 
    for(i=0;i<g.vexnum;i++)
    {
        printf("From %d to %d:",0,i);
        print_path(g,i);
        printf("\nThe total:%d\n",s[i]);  
    }
    return 0;   
}
