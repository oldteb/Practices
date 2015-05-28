#include<iostream>
#include<string>
#include<stdio.h>
#define    TRUE    1
#define    FALSE   0
#define    Num     20

using namespace std;

typedef struct {
    string  name;
    string  value[Num];
    int     t_value;    
}Member;

int atoi(string );

bool CheckInt(string s){
    if(s[0]=='1'||
       s[0]=='2'||
       s[0]=='3'||
       s[0]=='4'||
       s[0]=='5'||
       s[0]=='6'||
       s[0]=='7'||
       s[0]=='8'||
       s[0]=='9')  return TRUE;
    else return FALSE;            
}

int Shi(int d){
    int m;
    for(m=1;d>0;d--)
        m=m*10;
    return m;
}

int Average(Member* );

int main(){
    int i,d;
    string s;
    Member array[Num];
    char* str=new char;
    string str1;
    for(i=1,d=1;;){
        if(array[i-1].name=="0")  break;
        cin>>s;
        if(CheckInt(s))  array[i-1].value[d++]=s;
        else { array[i++].name=s;  d=1;}
    }
    Average(array);
    for(d=1;d<i-1;d++){
        cout<<array[d].name<<"'s average: ";        
        cout<<array[d].t_value; 
        cout<<endl;
    }       
    cout<<"The Total:"<<array[0].t_value;    
    system("pause");
    return 0;
}

int Average(Member* array){
    int i,d;
    array[0].t_value=0;
    for(i=1;array[i].name!="0";i++){
        array[i].t_value=0; 
        for(d=1;array[i].value[d]!="\0";d++)
            array[i].t_value=array[i].t_value+atoi(array[i].value[d]);  
        array[i].t_value=array[i].t_value/--d;  
    }
    for(i=1;array[i].name!="0";i++)
        array[0].t_value=array[0].t_value+array[i].t_value;
    array[0].t_value=array[0].t_value/--i;
    return 0;   
}

int atoi(string str){
    int i[Num];
    int m=1;
    int d=0;
    for(;str[d]!='\0';d++,m++)
        i[m]=(int)(str[d]-48);
    i[0]=--m;
    for(d=0,m=1;m<=i[0];m++)
        d=d+i[m]*Shi(i[0]-m);
    return d;
}
