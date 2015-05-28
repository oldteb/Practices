#include<iostream>
#include<cstdlib>
#include<iomanip>

using namespace std;

int leap_year(int );


class Date{
    int day,month,year;
    static Date default_date;
public:
    Date(int y=0,int m=0,int d=0);
    Date(string& );
    bool AddDay(int d);
    static bool set_default(int ,int ,int );
    friend ostream& operator<<(ostream& o, const Date& d);
};

Date Date::default_date(2011,4,21);

Date::Date(int y,int m,int d){
    year  = y?y:default_date.year;
    month = m?m:default_date.month;
    day   = d?d:default_date.day;
}
    

Date::Date(string& s){
    year  = atoi(s.substr(0,4).c_str());
    month = atoi(s.substr(5,2).c_str());
    day   = atoi(s.substr(8,2).c_str());
}

bool Date::AddDay(int d){
    int i,y=year,rd=d,m;
    int days_of_month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    for(i=0;rd>=356;i++)
        rd=rd-355-leap_year(y+i);
    if(leap_year(y+i)!=1 && rd==355){ rd=0;  i++;}
    for(m=month-1;rd>days_of_month[m];m++){
        if(m==0)
            if(leap_year(y+i)==1)
                days_of_month[1]=29;
        rd=rd-days_of_month[m];
    }
    if((rd+day)/days_of_month[m]==1){ rd=(rd+day)%days_of_month[m]; m++; }
    else rd=(rd+day)%days_of_month[m];
    year  = y+i;
    month = m+1;
    day   = rd;
    return 1;
}
     
     

bool Date::set_default(int y,int m,int d){
    Date::default_date=Date(y,m,d);
    return 1;
}

ostream& operator<<(ostream& o, const Date& d){
        o<<setfill('0');
        o<<setw(4)<<d.year<<'-'<<setw(2)<<d.month<<'-'<<setw(2)<<d.day<<endl;
        return o;
}
/*
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
    month = m+1;
    day   = rd+1;
}
*/


int main(){
    //Date day1(2011,4,19);
    //Date day2;
    //Date day3(2011);
    string s;
    //cin>>s;
	Date day1(1421);
	Date day2(2000,1,1);
	Date day3;
	//Date day4(s);
	Date day5(1421,0,0);
	cout<<day3;
	day3.AddDay(10);
	cout<<day3;
    //cout<<day1;
    //cout<<day2;
    //cout<<day3;
	//cout<<day1<<day2<<day3<<day4<<day5;
    system("pause");
    return 0;
}

int leap_year(int b)
{
    int a=0;
    if(b%4==0&&b%100!=0||b%400==0)  a=1;
    return a;
} 
