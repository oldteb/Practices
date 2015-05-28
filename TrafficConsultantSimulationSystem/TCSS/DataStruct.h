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

//-------------------------------------------------·��ͼ---------------------------------------------------------------



typedef struct Node{      //��ǰ���������洢����֮���ܹ�ֱ��İ����Ϣ,�����ڽӾ�����
    string       number;     //�ɻ�/�𳵵İ�κ�
    struct Node  *next;
}Node, *pNode;

typedef struct CityInfo{           //��ǰ���������ڽӾ���ÿһ�����Ľṹ��
    pNode  trains;            //ָ�������ͷ����ָ��
    pNode  planes;            //ָ��ɻ�����ͷ����ָ��
}CityInfo;

typedef  CityInfo  AdjMatrix[MaxVnum][MaxVnum];

typedef struct Graph{               //ͼ�Ľṹ�嶨��
    int        vexnum,arcnum;       
    AdjMatrix  arcs;     
}Graph; 

//----------------------------------------------------��-------------------------------------------------------------

//typedef  TNode  TPath[MaxVnum];   //һ��𳵵�����ͣ��վ��Ϣ


typedef struct TNode{             //(ǰ������)�洢ͬһ��λ𳵾���վ�����Ϣ����������
    int     station;             //վ�����ο���¼A��
    Time    arrivetime;          //����ڳ�ʼ����ʱ�����Ե���ʱ�� 
    Time    staytime;         
	int     fee;                 //��������վ��Ʊ��,path[0].fee��ʾ�����������ݵĸ�����
}TNode;

typedef  TNode  TPath[Num];   //һ��𳵵�����ͣ��վ��Ϣ

typedef struct TNumber{     //�𳵰��������
    string          number;       //�𳵰��
    Time            startime;     //����ʱ��
    TPath           path;         //��¼����վ�������
    struct TNumber  *next;        
}TNumber, *TLinkList;

//------------------------------------------------------�ɻ�------------------------------------------------------------



typedef struct{             //��ǰ���������洢ͬһ��λ𳵾���վ�����Ϣ����������
    string      number;           //�ɻ������
    int         start;            //��ʼվ
    int         arrive;           //�յ�վ
    int         fee;              //����,plist[0].fee��ʾ�����������ݵĸ�����
    Time        startime;         //���ʱ�� 
    Time        arrivetime;       //����ʱ�� 
}PNode;

typedef  PNode  PList[MaxVnum];   //�ɻ�������Ϣ����

//------------------------------------------------------�洢·������--------------------------------------------------
typedef struct{             //��¼���ҵ�������·��
    string     number;            //�����Ϣ
    int        start;             //��ʼվ
    int        arrive;            //�յ�վ
	TLinkList  ptll;              //�����ŵ��ǻ���Ϣ�����ָ��ָ�����������Ӧ��ν��
	int        ip;                //�����ŵ��Ƿɻ���Ϣ���������Ϊ��Ӧ�������ڷɻ������е��±�
}Final[Num];

   
//-------------------------------------------------------�û�����------------------------------------------------------

typedef enum{plane,train}TRAFICTOOL;
typedef enum{lowpay, lowtime, lowchange}STRATEGY;


typedef  struct{
    int           startcity;        //��������
    int           destination;      //Ŀ�ĳ���
    TRAFICTOOL    trafictool;       //ѡ��Ľ�ͨ����
    STRATEGY      strategy;         //ѡ��Ľ������
}Customer;