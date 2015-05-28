#include<iostream>
#define   TRUE     1    
#define   FALSE    0    

using namespace std;

class Circle;
class Square;
class Triangle;

typedef struct {
    int x;
    int y;
}point;

class Shape{
public:
    //virtual int print()=0;
    virtual int GetType()=0;
    virtual bool intersects(Circle* )=0;
    virtual bool intersects(Square* )=0;
    virtual bool intersects(Triangle* )=0;
};

class Circle : public Shape{
    point center;
    int   radius;
public:
    virtual int GetType(){  return 1; }
    virtual bool intersects(Circle* s){ cout<<"s1 is a Circle,s2 is a Circle \n"; return TRUE; }
    virtual bool intersects(Square* s){ cout<<"s1 is a Square,s2 is a Circle \n"; return TRUE; }
    virtual bool intersects(Triangle* s){ cout<<"s1 is a Triangle,s2 is a Circle \n"; return TRUE; }
};

class Square : public Shape{
    point leftup;
    point leftdown;
    point rightup;
    point rightdown;
public:
    virtual int GetType(){  return 2; }
    virtual bool intersects(Circle* s){ cout<<"s1 is a Circle,s2 is a Square \n"; return TRUE; }
    virtual bool intersects(Square* s){ cout<<"s1 is a Square,s2 is a Square \n"; return TRUE; }
    virtual bool intersects(Triangle* s){ cout<<"s1 is a Triangle,s2 is a Square \n"; return TRUE; }
};

class Triangle : public Shape{
    point p1;
    point p2;
    point p3;
public:
    virtual int GetType(){  return 3; }
    virtual bool intersects(Circle* s){ cout<<"s1 is a Circle,s2 is a Triangle \n"; return TRUE; }
    virtual bool intersects(Square* s){ cout<<"s1 is a Square,s2 is a Triangle \n"; return TRUE; }
    virtual bool intersects(Triangle* s){ cout<<"s1 is a Triangle,s2 is a Triangle \n"; return TRUE; }
};

bool intersect(Shape* s1,Shape* s2){
    if(Circle* c=dynamic_cast<Circle*>(s1))
        return s2->intersects(c);
    else if(Square* s=dynamic_cast<Square*>(s1))
        return s2->intersects(s);
    else if(Triangle* t=dynamic_cast<Triangle*>(s1))
        return s2->intersects(t);
    else{
        cout<<"Type ERROR!\n";
        exit(0);
    }
}
        
        
int main(){
    Circle c;
    Square s;
    Triangle t;
    Shape* p1=&s;
    Shape* p2=&t;
    
    intersect(p1,p2);
    
    system("pause");
    return 0;
}
    
    
