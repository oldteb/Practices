#include<stdio.h>
#include<stdlib.h>
#define   pf          printf
#define   INIT_SIZE   1024
#define   TRUE        1
#define   sysP        system("pause")



long Eleven(int );
bool itoc(int ,int* );
bool pfci(int* );
bool cipci(int* ,int* );
int Min(int ,int );
int Max(int ,int );


int main(){
    int a,b;
    int m;
    long sum=1;
    double r;
    int bigNum[INIT_SIZE]={0};
    
    
    //a=2;  b=3;
    //r=(double)a/b;
    
    /*for(m=0;m<12;m++){
        sum=sum*11;
        printf("sum=%ld\n",sum);
    }*/
    
    /*m=99;
    a=m/100;
    
    pf("m=%d, a=%d\n",m,a);
    */
    
    m=11060219;
    itoc(m,bigNum);
    //pfci(bigNum);
    

    
    //printf("%f",r);
    
    system("pause");
    return 0;   
}



//将一个整数（大数）存进一个整型数组 
bool itoc(int n,int* bn){          
    int i,m,h=1;  int d=n; 
    for(m=10,i=1000000000;i>=1;i=i/10){
        if((d/i)<10&&(d/i)>=1){
            bn[h]=d/i;  h++;  //pf("%d",bn[h-1]);  sysP;
            d=d%i;
            if(h==2)  bn[0]=m;
            //pf("d=%d, i=%d, h=%d, m=%d",d,i,h,m); system("pause"); 
        }
        else if(h!=1){  bn[h]=0;  h++;  } 
        else m--;    
    }
    //printf("%d%d%d",bigNum[0],bigNum[1],bigNum[5]);
    pfci(bn);
    return TRUE;
}

//将整型数组中的数输出 
bool pfci(int* bn){
    int i=1;
    for(;i<=bn[0];i++)
        printf("%d",bn[i]);
    return TRUE;
}

