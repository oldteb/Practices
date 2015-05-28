#include<iostream>
#include<new>


using namespace std;

class Char_vec{
    int sz;
    char element[1];
public:
    static Char_vec* new_char_vec(int s);
    char& operator[](int i){  return element[i]; }
};

Char_vec* Char_vec::new_char_vec(int s){
    char* temp=new char(sizeof(Char_vec)+s-1);
    Char_vec* cv=new(temp) Char_vec;
    cv->sz=s;
    return cv;
}
    
    

int main(){
    //Char_vec* a;
    Char_vec* a=Char_vec::new_char_vec(30);
    (*a)[3]='a';
    (*a)[29]='z';
    cout<<(*a)[3]<<endl<<(*a)[29]<<endl;
    
    
    
    system("pause");
    return 0;
}
       
    
    
  
