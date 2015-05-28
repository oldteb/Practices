#include <stdio.h>
#include <stdlib.h>
int main()
{
    int c,b,q,z,i,j,a[4][5];
    int m,w[20];
    printf("please input some integers randomly:\n");
    for(i=0;i<4;i++)
    {
                    for(j=0;j<5;j++)
                    {
                                    scanf("%d ",&a[i][j]);
                    }
    }
    
    for(i=0;i<4;i++)
    {
                    for(j=0;j<5;j++)
                    {
                                    printf("%5d",a[i][j]);
                    }
                    printf("\n");
    }
    m=0;
    b=0;
    for(i=0;i<4;i++)
    {
                    for(j=0;j<5;j++)
                    {
                                    w[m]=a[i][j];
                                    m++;
                    }
    }
    for(c=0;c<20;c++)
    {
                     for(m=0;m<20;m++)
                     {
                                      if(w[m]>w[m+1])
                                      {
                                                     z=w[m];
                                                     w[m]=w[m+1];
                                                     w[m+1]=z;
                                      }
                     }
    }
    printf("the biggest number is :%d\n",w[19]);
    printf("the status is in ?.");
                                                      
    
                    
    
  
  system("PAUSE");	
  return 0;
}

