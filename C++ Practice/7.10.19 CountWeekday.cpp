#include<iostream>
#define    TRUE       1
#define    FALSE      0

using namespace std;

//typedef enum{Su,Mo,Tu,We,Th,Fr,Sa}WEEKDAY;

class Date{
     int day;
     int month;
     int year;
public:
     Date(int y=2000,int m=1,int d=1){ day=d; month=m; year=y;}
     Date(string& s);
     bool DofW();          
};

int leap_year(int b);


Date::Date(string& s){
    year  = atoi(s.substr(0,4).c_str());
    month = atoi(s.substr(5,2).c_str());
    day   = atoi(s.substr(8,2).c_str());
}

//2000,1,1 ÐÇÆÚÁù 5 
bool Date::DofW(){
    int i,rd;
    int yy=2000,mm,dd;
    int DofM[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    for(i=5;yy<year;yy++){
        //if((i+365+leap_year(yy))%7==0)  i=7;
        //else 
        i=(i+365+leap_year(yy))%7;
    }
    //cout<<i;
    for(mm=1;mm<month;mm++){
        if(leap_year(year))  DofM[1]=29;
        i=(i+DofM[mm-1])%7;
    }
    //cout<<i;
    i=(i+day-1)%7;
    i=i+1;
    switch(i){
        case 1:cout<<"Monday";    break;
        case 2:cout<<"Tuesday";   break;
        case 3:cout<<"Wednesday"; break;
        case 4:cout<<"Thursday";  break;
        case 5:cout<<"Friday";    break;
        case 6:cout<<"Saturday";  break;
        case 7:cout<<"Sunday"; 
    }
    cout<<endl;
    return TRUE;
}


int main(){
    string s;
    //Date d1(2011,4,20);
    cin>>s;
    Date d2(s);
    //cout<<d1.DofW()<<"\n"<<d2.DofW();
    //d1.DofW();
    d2.DofW();
    system("pause");
    return 0;    
}

int leap_year(int b)
{
    int a=0;
    if(b%4==0&&b%100!=0||b%400==0)  a=1;
    return a;
}     
