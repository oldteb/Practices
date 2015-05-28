#include<stdio.h>
#include<stdlib.h>
#include<iostream>


using namespace std;

int main(int argc,char* argv[]){
    int i;
    if(argc<=1){ cout<<"Arguments ERROR!";  return 0; }
    for(i=1;i<argc;i++)
        cout<<"Hellow "<<argv[i]<<endl;
    return 0;                           
}
