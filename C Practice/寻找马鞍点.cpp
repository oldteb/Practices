#include<stdio.h>
#include<stdlib.h>

int main()
{
     int A[3][3],i,j,min,max,x,y,m,n;
     printf("Please input some integers:\n");
     for(i=0;i<3;i++){
          for(j=0;j<3;j++)
              scanf("%d",&A[i][j]);
     }
     printf("The number you have input are:\n");
     for(i=0;i<3;i++){
          for(j=0;j<3;j++)
              printf("%8d",A[i][j]);
          printf("\n");
     }

     for(m=0,n=0;m<3;n=0,m++){
          i=m;
          j=n;
          min=A[i][j];
          y=0;
          for(;j<2;j++){
              if(min>A[i][j+1])
              {
                  min=A[i][j+1];
                  y=j+1;
              }
          }
          printf("%d\n",min);
          system("PAUSE");
          max=A[i][y];
          x=0;
          for(i=0;i<2;i++){
              if(max<A[i+1][y])
              {
                  max=A[i+1][y];
                  x=i+1;
              }
          }
          printf("%d\n",max);
          system("PAUSE");
          if(min==max)
              printf("The number is: %5d\n",A[x][y]);
          else
              printf("Not found!\n");              
     }  
     system("PAUSE");
}
          
     
         
         
     
