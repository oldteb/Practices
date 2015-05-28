//**************************************************************************
//-----------------------------V1.9-----------------------------------------
//**************************************************************************
#include<string>
#define    MaxVnum            70
#define    Num                20  
#define    CityNum            50
#define    MAX                999999

using namespace std;

typedef struct {
    int hour;
    int minute;
}Time;

//-------------------------------------------------路径图---------------------------------------------------------------



typedef struct Node{      //（前向声明）存储城市之间能够直达的班次信息,用于邻接矩阵中
    string       number;     //飞机/火车的班次号
    struct Node  *next;
}Node, *pNode;

typedef struct CityInfo{           //（前向声明）邻接矩阵每一个结点的结构体
    pNode  trains;            //指向火车链表头结点的指针
    pNode  planes;            //指向飞机链表头结点的指针
}CityInfo;

typedef  CityInfo  AdjMatrix[MaxVnum][MaxVnum];

typedef struct Graph{               //图的结构体定义
    int        vexnum,arcnum;       
    AdjMatrix  arcs;     
}Graph; 

//----------------------------------------------------火车-------------------------------------------------------------

//typedef  TNode  TPath[MaxVnum];   //一班火车的所有停靠站信息


typedef struct TNode{             //(前向声明)存储同一班次火车经过站点的信息，用于数组
    int     station;             //站名（参看附录A）
    Time    arrivetime;          //相对于初始发车时间的相对到达时间 
    Time    staytime;         
	int     fee;                 //相对于起点站的票价,path[0].fee表示该数组中数据的个数。
}TNode;

typedef  TNode  TPath[Num];   //一班火车的所有停靠站信息

typedef struct TNumber{     //火车班次链表结点
    string          number;       //火车班次
    Time            startime;     //发车时间
    TPath           path;         //记录所经站点的数组
    struct TNumber  *next;        
}TNumber, *TLinkList;

//------------------------------------------------------飞机------------------------------------------------------------



typedef struct{             //（前向声明）存储同一班次火车经过站点的信息，用于数组
    string      number;           //飞机航班号
    int         start;            //起始站
    int         arrive;           //终点站
    int         fee;              //费用,plist[0].fee表示该数组中数据的个数。
    Time        startime;         //起飞时间 
    Time        arrivetime;       //到达时间 
}PNode;

typedef  PNode  PList[MaxVnum];   //飞机航班信息数组

//------------------------------------------------------存储路径数组--------------------------------------------------
typedef struct{             //记录查找到的最终路线
    string     number;            //班次信息
    int        start;             //起始站
    int        arrive;            //终点站
	TLinkList  ptll;              //如果存放的是火车信息，则该指针指向火车链表中相应班次结点
	int        ip;                //如果存放的是飞机信息，则该整数为相应航班所在飞机数组中的下标
}Final[Num];

   
//-------------------------------------------------------用户需求------------------------------------------------------

typedef enum{plane,train}TRAFICTOOL;
typedef enum{lowpay, lowtime, lowchange}STRATEGY;


typedef  struct{
    int           startcity;        //出发城市
    int           destination;      //目的城市
    TRAFICTOOL    trafictool;       //选择的交通工具
    STRATEGY      strategy;         //选择的解决策略
}Customer;