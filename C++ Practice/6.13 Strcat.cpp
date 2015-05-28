#include<iostream.h>


using namespace std;

char* cat(char* ,char* );
int PrintStr(char* );


int main(){
    char* str1=new char;
    char* str2=new char;
    char* str=new char;
    gets(str1);
    gets(str2);
    str=cat(str1,str2);
    PrintStr(str);
    
    //printf("Hellow world!");   
    
    system("pause");
    return 0;
     
}


char* cat(char* str1,char* str2){
    int i,j;
    char* str=new char;
    for(i=0;str1[i]!='\0';i++){
        str[i]=str1[i];
    }
    for(j=0;str2[j]!='\0';i++,j++){
        str[i]=str2[j];
    }
    str[i]='\0';
    return str;
}

int PrintStr(char* str){
    int i=0;
    for(;str[i]!='\0';i++){
        printf("%c",str[i]);                       
    }  
    return 0;
}
    
    
               
  
