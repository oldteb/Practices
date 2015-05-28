#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int data_init(const char *ccp, char *&s1, char *&s2);
int LCSS(char* s1,char* s2);



int main()
{
    char *s1,*s2;
    data_init("LCS.dat",s1,s2);
    LCSS(s1,s2);
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


int LCSS(char* s1,char* s2)
{    
    int k;   
    char* p;
    int n = strlen(s1);
    int m = strlen(s2);
    char* c = (char *)malloc(m);
    int start,end,len,i,j;
    end=len=0;
    for(i=0;i<n;i++)
    {
        for(j=m-1;j>=0;j--)
        {    
            if(*(s1+i)==*(s2+j))
            { 
                if(i==0||j==0)
                    c[j]=1;
                else  
                    c[j]=c[j-1]+1;
            }
            else
                c[j] = 0;
            if(c[j]>len)
            {    
                len=c[j];
                end=j;
            }
        }
    }
    start=end-len+1;
    p = (char *)malloc(len+1);
    for(i=start;i<=end;i++)   
        p[i-start] = *(s2+i);
    p[len]='\0';
    printf(p);
    return 1;
}
