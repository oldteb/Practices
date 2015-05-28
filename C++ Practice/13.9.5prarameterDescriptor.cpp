#include<iostream>
#include<vector>
#include<time.h>
#define    NUM    20

using namespace std;

struct Record{
    int count;
    int price;
};


template<typename T>
class Count{
public:
    static int reverse(vector<T>& ,int );
};
template<typename T>
int Count<T>::reverse(vector<T>& v,int j){
    if(v[j].count > v[j+1].count){
        int temp       = v[j+1].count;
        v[j+1].count = v[j].count;
        v[j].count   = temp;
    }
    return 0;
}


template<typename T>
class Price{
public:
    static int reverse(vector<T>& ,int );
};
template<typename T>
int Price<T>::reverse(vector<T>& v,int j){
    if(v[j].price > v[j+1].price){
        int temp     = v[j+1].price;
        v[j+1].price = v[j].price;
        v[j].price   = temp;
    }
    return 0;
}

template<typename T,typename C>
int my_sort(vector<T>& v){
    int n = v.size();
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            C::reverse(v,j);
    return 0;
}

//template<typename T>
int PrintAll(const vector<Record>& v){
    int i;
    for(i=0;i<NUM;i++)  cout<<v[i].count<<" ";
    cout<<endl;
    for(i=0;i<NUM;i++)  cout<<v[i].price<<" ";
    cout<<endl;
    return 0;
}

int main(){
    Record a;
    a.count =1;
    vector<Record> v(NUM);
    
    for(int i=0;i<NUM;i++){
        v[i].count = rand();
        v[i].price = 19-i;
    }
    
    my_sort<Record, Count<Record> >(v);
    PrintAll(v);
    my_sort<Record, Price<Record> >(v);
    PrintAll(v);
    
    system("pause");
    return 0;
}

    
    
    
    
    
        

    


        
