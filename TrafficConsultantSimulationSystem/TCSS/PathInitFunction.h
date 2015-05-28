#include<stdio.h>
#include<string>
#include<stdlib.h>
#include"Time.h"
#define		OK       1
#define		ERROR    0

using namespace std;

typedef int status;


//****************************************************************************
//-----------------------------应用模块---------------------------------------
//****************************************************************************

status CreatList_T(TLinkList& tp){               //建立一个火车类型链表的头结点

	//tp=(TLinkList)malloc(sizeof(TNumber));
	tp=new TNumber;
	tp->next=NULL;                                   //将nest域
	return OK;
}

status AddList_T(const TLinkList& tp){                 //在链表末尾增加一个火车类型的结点
	TLinkList  p,s;
	p=tp;
	while(p->next!=NULL)  p=p->next;
	//s=(TLinkList)malloc(sizeof(TNumber));
	s=new TNumber;
	p->next=s;  s->next=NULL;
	s->path[0].fee=0;                               //path[0]存储数组中的数据的数量，初始化时赋值0
	return OK;
}



status CreatList_G(pNode& trains, pNode& planes){          //建立一个图链表的头结点(包括火车链表头结点以及飞机链表头结点)
	trains=new Node;  planes=new Node;
	trains->next=NULL;
	planes->next=NULL;
	return OK;
}

pNode AddList_G(const pNode& p){                          //增加一个图链表的结点（火车与飞机链表共用),并返回申请结点的地址
	pNode s,l;
	l=p;
	while(l->next!=NULL)  l=l->next;
	s=new Node;
	l->next=s;  s->next=NULL;
	return s;
}

status InitGraph(Graph& graph,const int& citynum){                         //初始化一个图
	int i,j;
	graph.vexnum  = citynum;
	for(i=1;i<=graph.vexnum;i++)
		for(j=1;j<=graph.vexnum;j++)
			CreatList_G(graph.arcs[i][j].trains, graph.arcs[i][j].planes);
	return OK;
}


//****************************************************************************
//-----------------------------功能模块---------------------------------------
//****************************************************************************

status ReadTrainInfo(TLinkList& tlinklist){           //从文件读入火车信息
	int a,i;
	string s;
    TLinkList bp;
    
    CreatList_T(tlinklist);                                      //创建一个火车链表头结点

//-------------------------------------------文件数据读入------------------------------------------------------
	ifstream in_t("TrainInfo.in");                         //文件流打开路径存储文件

	bp=tlinklist;                                         //tp赋值给bp
	for(string str;getline(in_t,str);s="0"){             //每一次循环读入一班火车，str中存放火车班次号
		AddList_T(tlinklist);                      //创建3个火车班次存放地址
		bp=bp->next;
		if(bp==NULL){                                           //如果路径信息文件中班次的数量与申请的内存空间不等，返回错误！   
			cout<<"Amount of TNumber ERROR! Please check the file 'TrainInfo.in' to see whether it has been changed or not. ";
			system("pause");
			exit(0);
		}
		bp->number=str;  //cout<<bp->number<<endl;             //将火车班次号存入内存
		getline(in_t,str);                                       //将列车首发时刻存入str中
		InitTime(bp->startime);                                //初始化相应内存空间
		i=0;
		for(istringstream sin(str);sin>>a;i++){              //将str中的放列车首发时刻存入内存
			if(i==0)       bp->startime.hour   = a;
			else if(i==1)  bp->startime.minute = a;
		}
		for(int j=1,i=0;getline(in_t,s);j++,i=0){              //每次循环读入一个站点的信息，s中存放站点信息
			//cout<<s<<endl;
			if(s=="")    break;                              //返回外围for循环开始读入下一班火车
			for(istringstream sin(s);sin>>a;i++){             //每次循环读入一个整数
				if(i==0)       bp->path[j].station=a;                                                //存放站点名
				else if(i==1)  {InitTime(bp->path[j].arrivetime);  bp->path[j].arrivetime.hour=a;}   //存放到达时刻（小时）
				else if(i==2)  bp->path[j].arrivetime.minute=a;										 //存放到达时刻（分钟）
				else if(i==3)  {InitTime(bp->path[j].staytime);    bp->path[j].staytime.minute=a; }  //存放停留时刻
				else if(i==4)  bp->path[j].fee=a;													 //存放费用
			}
			(bp->path[0].fee)++;                           //站点数自增1
		}
	}

//------------------------------------------测试区-------------------------------------------------------
/*	
	PrintList_T(tlinklist);                                       //查看火车班次
	for(bp=tlinklist->next;bp!=NULL;bp=bp->next){                 //查看班次信息
		cout<<endl;
		PrintTPath(bp->path);   
	}
*/
	
//-----------------------------------------收尾工作----------------------------------------------
	in_t.close();                                            //关闭文件
	return OK;

}


status ReadPlaneInfo(PList& plist){                    //从文件读入飞机信息
	int a,i,j;
	string str, s;

	ifstream in_p("PlaneInfo.in");                        //文件流打开路径存储文件
	
	plist[0].fee=0;                                     //plist[0].fee存储飞机航班的数量，初始化时赋值0
	i=1;
	for(;getline(in_p,s);i++){                    //每一次循环读入一个航班信息，存在s中
		istringstream sin(s);                           
		sin>>str;
		plist[i].number=str;                            //将s中第一个字符串存为飞机的航班号
		for(j=1;sin>>a;j++){                            //将s中的信息依次存入相应位置
			if(j==1)       plist[i].start  = a;                                              //存储始发站
			else if(j==2)  plist[i].arrive = a;                                              //存储目的地
			else if(j==3)  {InitTime(plist[i].startime);  plist[i].startime.hour = a;}       //初始化起飞时间，存储起飞时间（小时）
			else if(j==4)  plist[i].startime.minute = a;                                     //存储起飞时间（分钟）
			else if(j==5)  {InitTime(plist[i].arrivetime);  plist[i].arrivetime.hour = a;}   //初始化到达时间，存储到达时间（小时）
			else if(j==6)  plist[i].arrivetime.minute = a;                                   //存储到达时间（分钟）
			else if(j==7)  plist[i].fee    = a;                                              //存储费用
		}
		(plist[0].fee)++;                               //航班数自增1
	}
//------------------------------------------测试区-------------------------------------------------------
//	PrintPList(plist);                               //打印所有飞机信息
 


//-----------------------------------------收尾工作----------------------------------------------
	in_p.close();                                            //关闭文件
	return OK;

}






status SingleTrainToGraph(Graph& graph,const TLinkList& tp){               //将一班火车存入图中
	int i,j;
	int plc1,plc2;
	pNode pn;
	for(i=1;i<=tp->path[0].fee;i++)
		for(j=i;j<=tp->path[0].fee;j++){
			if(i==j)  continue;
			plc1 = tp->path[i].station;
			plc2 = tp->path[j].station;
			pn = AddList_G(graph.arcs[plc1][plc2].trains);
			pn->number = tp->number;
		}
	return OK;
}


status TrainToGraph(Graph& graph,const TLinkList& tlinklist){                  //将所有火车信息读入图中
	TLinkList tll;
	tll = tlinklist;
	while(tll->next != NULL){
		tll = tll->next;
		SingleTrainToGraph(graph,tll);
	}
	return OK;
}

status PlaneToGraph(Graph& graph,const PList& plist){                        //将所有的飞机读入图中
	int i;
	int plc1,plc2;
	pNode pn;
	for(i=1;i<=plist[0].fee;i++){
		plc1 = plist[i].start;
		plc2 = plist[i].arrive;
		pn = AddList_G(graph.arcs[plc1][plc2].planes);
		pn->number = plist[i].number;
	}
	return OK;
}



//**************************************************************************
//-----------------------------测试模块-------------------------------------
//**************************************************************************

status PrintList_T(const TLinkList& tp){       //打印所有火车班次
    TLinkList p;
    p=tp; p=p->next;
    while(p!=NULL){
		cout<<"------"<<p->number<<"------";
		cout<<endl;
		PrintTime(p->startime);
		cout<<endl;
        p=p->next;
    }
    return OK;
}

status PrintTPath(TNode* path){        //打印确定班次每站的详细信息
	for(int i=1;i<=path[0].fee;i++){
		cout<<path[i].station;//printf("%d ,",path[i].station);
		cout<<"  ";
		PrintTime(path[i].arrivetime);
		cout<<"  ";
		PrintTime(path[i].staytime);
		cout<<"  ";
		cout<<path[i].fee;//printf("%d ,",path[i].fee);
		cout<<endl;
	}
	return OK;
}

status PrintPList(PNode* plist){              //打印所有飞机信息
	for(int i=1;i<=plist[0].fee;i++){
		cout<<plist[i].number<<"   ";
		cout<<plist[i].start<<"   ";
		cout<<plist[i].arrive<<"   ";
		PrintTime(plist[i].startime);
		cout<<"   ";
		PrintTime(plist[i].arrivetime);
		cout<<"   ";
		cout<<plist[i].fee;
		cout<<endl;
	}
	return OK;
}

status PrintPNode(const pNode& p){            //打印图中一个结点的火车或飞机链表的信息
	pNode pn;
	pn = p;
	while(pn->next != NULL){
		pn = pn->next;
		cout<<pn->number;
		cout<<"   ";
	}
	return OK;
}


status PrintGraph(const Graph& graph){           //打印图中所有信息
	int i,j;
	for(i=1;i<=graph.vexnum;i++)
		for(j=1;j<=graph.vexnum;j++){
			cout<<"-------------- From "<<i<<"to "<<j<<" --------------"<<endl;
			cout<<"Trains:   ";
			PrintPNode(graph.arcs[i][j].trains);
			cout<<endl;
			cout<<"Planes:   ";
			PrintPNode(graph.arcs[i][j].planes);
			cout<<endl;
		}
	return OK;
}