#include<iostream>
#include<vector>
#define    VECTOR_SIZE       4

using namespace std;

class Vec4{
    float v[VECTOR_SIZE];
public:
    Vec4(float ,float ,float ,float );
    float operator[](int );
    Vec4 operator+(Vec4& );
    Vec4 operator-(Vec4& );
    Vec4 operator*(Vec4& );
    Vec4 operator/(Vec4& );
    Vec4& operator+=(Vec4& );
    Vec4& operator-=(Vec4& );
    Vec4& operator*=(Vec4& );
    Vec4& operator/=(Vec4& );

};

Vec4::Vec4(float f1,float f2,float f3,float f4){
    v[0]=f1;
    v[1]=f2;
    v[2]=f3;
    v[3]=f4;
}

float Vec4::operator[](int t){
    return v[t-1];
}

Vec4 Vec4::operator+(Vec4& v1){
    int i=0;
    Vec4 vec(0,0,0,0);
    for(;i<VECTOR_SIZE;i++)
        vec.v[i]=v1.v[i]+this->v[i];
    return vec;
}

Vec4 Vec4::operator-(Vec4& v1){
    int i=0;
    Vec4 vec(0,0,0,0);
    for(;i<VECTOR_SIZE;i++)
        vec.v[i]=this->v[i]-v1.v[i];
    return vec;
}

Vec4 Vec4::operator*(Vec4& v1){
    int i=0;
    Vec4 vec(0,0,0,0);
    for(;i<VECTOR_SIZE;i++)
        vec.v[i]=this->v[i]*v1.v[i];
    return vec; 
}

Vec4 Vec4::operator/(Vec4& v1){
    int i=0;
    Vec4 vec(0,0,0,0);
    for(;i<VECTOR_SIZE;i++)
        vec.v[i]=this->v[i]/v1.v[i];
    return vec; 
}




Vec4& Vec4::operator+=(Vec4& v1){
    for(int i=0;i<VECTOR_SIZE;i++)
        this->v[i]=this->v[i]+v1.v[i];
    return *this;
}

Vec4& Vec4::operator-=(Vec4& v1){
    for(int i=0;i<VECTOR_SIZE;i++)
        this->v[i]=this->v[i]-v1.v[i];
    return *this;
}

Vec4& Vec4::operator*=(Vec4& v1){
    for(int i=0;i<VECTOR_SIZE;i++)
        this->v[i]=this->v[i]*v1.v[i];
    return *this;
}

Vec4& Vec4::operator/=(Vec4& v1){
    for(int i=0;i<VECTOR_SIZE;i++)
        this->v[i]=this->v[i]/v1.v[i];
    return *this;
}



    

int main(){
    Vec4 a(1,2,3,4);
    Vec4 b(4,5,6,7);
    Vec4 c(0,0,0,0);
    a*=b;
    cout<<a[3];
    system("pause");
    return 0;
}
    
    
        
    
    
    
    
