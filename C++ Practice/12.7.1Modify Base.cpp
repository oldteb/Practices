#include<iostream>

using namespace std;


class Base{
public:
    virtual int iam(){  cout<<"I'm Base.\n";  return 0;  }
};

class Tomy : public Base{
    //string name;
public:
    //Tomy(string s):name(s){}
    virtual int iam(){  cout<<"I'm Tomy.\n";  return 0;  }
};

class Peter : public Base{
    //string name;
public:
    //Tomy(string s):name(s){}
    virtual int iam(){  cout<<"I'm Peter.\n";  return 0;  }
};

int main(){
    Base b;
    Tomy t;
    Peter p;
    t.iam();
    p.iam();
    Base* p1=&t;
    Base* p2=&p;
    p1->iam();
    p2->iam();
    
    system("pause");
    return 0;
}
    

