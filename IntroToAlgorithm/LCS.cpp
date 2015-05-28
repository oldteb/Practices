#include<stdio.h>
#include<stdlib.h>
#include<string.h>



int data_init(const char *ccp, char *&s1, char *&s2);
int print_path(int** c,char* s1,char* s2,int i,int j);
int LCS(char *s1, char *s2);



int main()
{
    char *s1,*s2;
    data_init("LCS.dat",s1,s2);
    LCS(s1,s2);
    system("pause");
    return 0;    
}



int data_init(const char *ccp, char *&s1, char *&s2)
{
    FILE *fp;
    s1 = (char *)malloc(100*sizeof(char));
    s2 = (char *)malloc(100*sizeof(char));
    fp = fopen(ccp,"r");
    fscanf(fp,"%s",s1);
    fscanf(fp,"%s",s2);
    fclose(fp);
    return 0;
}

int print_path(int** c,char* s1,char* s2,int i,int j)
{
    if(c[i][j]==0)
        return 1;
    else if(c[i-1][j]==c[i][j])
    {
        print_path(c,s1,s2,i-1,j);     
        return 1;
    }
    else if(c[i][j-1]==c[i][j])
    {
        print_path(c,s1,s2,i,j-1);
        return 1;     
    }
    else if(c[i-1][j-1]+1==c[i][j])
    {
        print_path(c,s1,s2,i-1,j-1);
        printf("%c",*(s1+i-1));
        return 1;
    }
    else 
    {
        printf("ERROR!");
        system("pause");
        exit(0);    
    }
}


int LCS(char *s1, char *s2)
{
    int i,j;
    int** c;  
    int n = strlen(s1);
    int m = strlen(s2);
    c = (int **)malloc((n+1)*sizeof(int *));
    for(i=0;i<=n;i++)
        c[i] = (int *)malloc((m+1)*sizeof(int));
    for(i=0;i<=n;i++)
        c[i][0] = 0;
    for(j=0;j<=m;j++)
        c[0][j] = 0;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            if((*(s1+i-1))==(*(s2+j-1)))
                c[i][j] = c[i-1][j-1]+1;                                  
            else if(c[i-1][j]>=c[i][j-1])
                c[i][j] = c[i-1][j];     
            else 
                c[i][j] = c[i][j-1];
        } 
    print_path(c,s1,s2,n,m);
    return 0;
}
