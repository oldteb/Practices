#include <iostream>
#include <string>


using namespace std;


class Complex{
	double real;
	double imag;
public:
	Complex(){  real=0;imag=0; }
	Complex(double r,double i){  real=r,imag=i;}  
	Complex complex_add(Complex &c2);
	void display();
};


Complex Complex::complex_add(Complex &c2){
	Complex c;
	c.real=real+c2.real;
	c.imag=imag+c2.imag;
	return c;
}


void Complex::display(){
	cout<<"("<<real<<","<<imag<<"i"<<")"<<endl;
}



int main (int argc, char * const argv[]) {
	Complex c1(8,13),c2(4,-34),c3;
	c3=c1.complex_add(c2);
	cout<<"c1=";c1.display();
	cout<<"c2=";c2.display();
	cout<<"c1+c2=";c3.display();
	system("pause");
    return 0;
}
