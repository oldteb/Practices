#include<iostream>

class A{
public:
    A(){  std::cout<<"The future is ours."<<std::endl;  }
    ~A(){  std::cout<<std::endl<<"For the lich king!";  }
};
    
A a;


int main(){
    std::cout<<"The evil is near!";
    system("pause");
    return 0;
}
