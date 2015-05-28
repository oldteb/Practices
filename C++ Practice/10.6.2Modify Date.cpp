#include<iostream>
#include <cstdlib>
#include <iomanip>
#include<Date>

using namespace std;

class Date{
    int day,month,year;
public:
    Date(int y=0,int m=0,int d=0){ year=y; month=m; day=d;}
    //Date(char* strd);
    Date(int d);
    inline ostream& operator<<(ostream& o){
        o<<setfill('0');
        o<<setw(4)<<year<<'-'<<setw(2)<<month<<'-'<<setw(2)<<day<<endl;
        return o;
    }
};

int leap_year(int b)
{
    int a=0;
    if(b%4==0&&b%100!=0||b%400==0)  a=1;
    return a;
}     


Date::Date(int d){
    int i,y=1970,rd=d,m;
    int days_of_month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    for(i=0;rd>=356;i++)
        rd=rd-355-leap_year(y+i);
    if(leap_year(y+i)!=1 && rd==355){ rd=0;  i++;}
    for(m=0;rd>days_of_month[m];m++){
        if(m==0)
            if(leap_year(y+i)==1)
                days_of_month[1]=29;
        rd=rd-days_of_month[m];
    }
    year  = y+i;
    month = m;
    day   = rd;
}



int main(){
    Date day1(2011,4,19);
    Date day2;
    //Date dat3(2011);
    cout<<day1;
    cout<<day2;
    cout<<day3;
    system("pause");
    return 0;
}
