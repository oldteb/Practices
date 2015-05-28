#include<iostream>
#include<string>

using namespace std;

template<typename T>
class Srep{
public:
    T* s;
    int sz;
    int n;
    Srep(int nsz, const T* p){
        n  = 1;
        sz = nsz;
        s  = new T[sz+1];
        strcpy<T>(s,p);
    }
    ~Srep() {delete[] s; }
    int assign(int nsz, const T* p){
        if(sz! = nsz){
            delete[] s;
            sz = nsz;
            s  = new T[sz+1];
        }
        strcpy<T>(s,p);
    }
    int print(){
        cout<<s;
        return 0;
    }
};

template<typename T>
class String{
    Srep* rep;
public:
    String(){  rep = new Srep(0,"");  }
    String(const T* str){ 
        int nsz = strlen<T>(str);
        rep = new Srep(nsz,str);
    } 
    String(const String<T>& str){
        str.rep->n++;
        rep = str.rep;
    }
    T read(int )const{  return rep->s[i]; }
    int Print(){  return rep->print(); }
    //......
};

int main(){
    String<char> s = "Hello world!";
    s.Print();
    
    system("pause");
    return 0;
    
}
    
    


    


    
    
      
    
