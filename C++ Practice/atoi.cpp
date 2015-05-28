#include<iostream>
#include<string>
#define    Num      20

int atoi(char* );
//int otoi(char* );
int htoi(char* );
//int Shi(int );
int ShiLiu(int );
    
int main(){
    int a;
    char* str=new char;
    gets(str);
    //atoi(str);
    htoi(str);
    system("pause");
    return 0;
}

int atoi(char* str){
    int i[Num];
    int m=1;
    int d=0;
    for(;str[d]!='\0';d++,m++)
        i[m]=(int)(str[d]-48);
    i[0]=--m;
    for(m=1;m<=i[0];m++)
        printf("%d",i[m]);
    return 0;
}

int htoi(char* str){
    int i[Num];
    int m=1;
    int d=0;
    for(;str[d]!='\0';d++,m++){
        if(str[d]=='A'||str[d]=='B'||str[d]=='C'||str[d]=='D'||str[d]=='E'||str[d]=='F')
            i[m]=(int)(str[d]-65)+11;
        else
            i[m]=(int)(str[d]-48);
    }
    i[0]=--m;
    for(m=1;m<=i[0];m++)
        printf("%d",i[m]);
    for(m=0,d=1;d<=i[0];d++)
        m=m+(i[d])*(ShiLiu(i[0]-d));
        
    printf("%d",m);
    return m;
}

int ShiLiu(int d){
    int m;
    for(m=1;d>0;d--)
        m=m*16;
    return m;
}
