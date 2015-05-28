#include<stdio.h>
#include<stdlib.h>

#define    ARR_SIZE       20



int PLACE(int col[],int k);
int print_path(int col[],int n);
int N_Queen(int n);


int main()
{
    N_Queen(4);
    system("pause");
    return 0;    
}

int PLACE(int col[],int k)
{
    int i=1;
    while(i<k)
    {
        if(col[i]==col[k])
            return 0;
        else if(i>k && (i-k==col[i]-col[k] || i-k==col[k]-col[i]))   
            return 0;
        else if(i<=k && (k-i==col[i]-col[k] || k-i==col[k]-col[i])) 
            return 0;  
        else i++;               
    }
    if(i==k)
    return 1;
}


int print_path(int col[],int n)
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(col[i]==j)
                printf(" Q ");
            else 
                printf("   ");               
        }  
        printf("\n");            
    }
    system("pause");
    return 0;   
}

int N_Queen(int n)
{
    int arr[ARR_SIZE][ARR_SIZE] = {0};
    int col[ARR_SIZE] = {0};
    int k = 1;  col[1] = 0;
    while(k>=0)
    {
        col[k]++;
        while(col[k]<=n && PLACE(col,k)==0)       
            col[k]++;
        if(col[k]<=n)
        {
            if(k==n)
            {
                print_path(col,n);   
                exit(0); 
            }
            else 
            {
                k++;
                col[k] = 0;     
            }        
        }
        else  k--;  
    }
    return 0;   
}
