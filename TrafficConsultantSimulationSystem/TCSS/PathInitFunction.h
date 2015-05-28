#include<stdio.h>
#include<string>
#include<stdlib.h>
#include"Time.h"
#define		OK       1
#define		ERROR    0

using namespace std;

typedef int status;


//****************************************************************************
//-----------------------------Ӧ��ģ��---------------------------------------
//****************************************************************************

status CreatList_T(TLinkList& tp){               //����һ�������������ͷ���

	//tp=(TLinkList)malloc(sizeof(TNumber));
	tp=new TNumber;
	tp->next=NULL;                                   //��nest��
	return OK;
}

status AddList_T(const TLinkList& tp){                 //������ĩβ����һ�������͵Ľ��
	TLinkList  p,s;
	p=tp;
	while(p->next!=NULL)  p=p->next;
	//s=(TLinkList)malloc(sizeof(TNumber));
	s=new TNumber;
	p->next=s;  s->next=NULL;
	s->path[0].fee=0;                               //path[0]�洢�����е����ݵ���������ʼ��ʱ��ֵ0
	return OK;
}



status CreatList_G(pNode& trains, pNode& planes){          //����һ��ͼ�����ͷ���(����������ͷ����Լ��ɻ�����ͷ���)
	trains=new Node;  planes=new Node;
	trains->next=NULL;
	planes->next=NULL;
	return OK;
}

pNode AddList_G(const pNode& p){                          //����һ��ͼ����Ľ�㣨����ɻ�������),������������ĵ�ַ
	pNode s,l;
	l=p;
	while(l->next!=NULL)  l=l->next;
	s=new Node;
	l->next=s;  s->next=NULL;
	return s;
}

status InitGraph(Graph& graph,const int& citynum){                         //��ʼ��һ��ͼ
	int i,j;
	graph.vexnum  = citynum;
	for(i=1;i<=graph.vexnum;i++)
		for(j=1;j<=graph.vexnum;j++)
			CreatList_G(graph.arcs[i][j].trains, graph.arcs[i][j].planes);
	return OK;
}


//****************************************************************************
//-----------------------------����ģ��---------------------------------------
//****************************************************************************

status ReadTrainInfo(TLinkList& tlinklist){           //���ļ��������Ϣ
	int a,i;
	string s;
    TLinkList bp;
    
    CreatList_T(tlinklist);                                      //����һ��������ͷ���

//-------------------------------------------�ļ����ݶ���------------------------------------------------------
	ifstream in_t("TrainInfo.in");                         //�ļ�����·���洢�ļ�

	bp=tlinklist;                                         //tp��ֵ��bp
	for(string str;getline(in_t,str);s="0"){             //ÿһ��ѭ������һ��𳵣�str�д�Ż𳵰�κ�
		AddList_T(tlinklist);                      //����3���𳵰�δ�ŵ�ַ
		bp=bp->next;
		if(bp==NULL){                                           //���·����Ϣ�ļ��а�ε�������������ڴ�ռ䲻�ȣ����ش���   
			cout<<"Amount of TNumber ERROR! Please check the file 'TrainInfo.in' to see whether it has been changed or not. ";
			system("pause");
			exit(0);
		}
		bp->number=str;  //cout<<bp->number<<endl;             //���𳵰�κŴ����ڴ�
		getline(in_t,str);                                       //���г��׷�ʱ�̴���str��
		InitTime(bp->startime);                                //��ʼ����Ӧ�ڴ�ռ�
		i=0;
		for(istringstream sin(str);sin>>a;i++){              //��str�еķ��г��׷�ʱ�̴����ڴ�
			if(i==0)       bp->startime.hour   = a;
			else if(i==1)  bp->startime.minute = a;
		}
		for(int j=1,i=0;getline(in_t,s);j++,i=0){              //ÿ��ѭ������һ��վ�����Ϣ��s�д��վ����Ϣ
			//cout<<s<<endl;
			if(s=="")    break;                              //������Χforѭ����ʼ������һ���
			for(istringstream sin(s);sin>>a;i++){             //ÿ��ѭ������һ������
				if(i==0)       bp->path[j].station=a;                                                //���վ����
				else if(i==1)  {InitTime(bp->path[j].arrivetime);  bp->path[j].arrivetime.hour=a;}   //��ŵ���ʱ�̣�Сʱ��
				else if(i==2)  bp->path[j].arrivetime.minute=a;										 //��ŵ���ʱ�̣����ӣ�
				else if(i==3)  {InitTime(bp->path[j].staytime);    bp->path[j].staytime.minute=a; }  //���ͣ��ʱ��
				else if(i==4)  bp->path[j].fee=a;													 //��ŷ���
			}
			(bp->path[0].fee)++;                           //վ��������1
		}
	}

//------------------------------------------������-------------------------------------------------------
/*	
	PrintList_T(tlinklist);                                       //�鿴�𳵰��
	for(bp=tlinklist->next;bp!=NULL;bp=bp->next){                 //�鿴�����Ϣ
		cout<<endl;
		PrintTPath(bp->path);   
	}
*/
	
//-----------------------------------------��β����----------------------------------------------
	in_t.close();                                            //�ر��ļ�
	return OK;

}


status ReadPlaneInfo(PList& plist){                    //���ļ�����ɻ���Ϣ
	int a,i,j;
	string str, s;

	ifstream in_p("PlaneInfo.in");                        //�ļ�����·���洢�ļ�
	
	plist[0].fee=0;                                     //plist[0].fee�洢�ɻ��������������ʼ��ʱ��ֵ0
	i=1;
	for(;getline(in_p,s);i++){                    //ÿһ��ѭ������һ��������Ϣ������s��
		istringstream sin(s);                           
		sin>>str;
		plist[i].number=str;                            //��s�е�һ���ַ�����Ϊ�ɻ��ĺ����
		for(j=1;sin>>a;j++){                            //��s�е���Ϣ���δ�����Ӧλ��
			if(j==1)       plist[i].start  = a;                                              //�洢ʼ��վ
			else if(j==2)  plist[i].arrive = a;                                              //�洢Ŀ�ĵ�
			else if(j==3)  {InitTime(plist[i].startime);  plist[i].startime.hour = a;}       //��ʼ�����ʱ�䣬�洢���ʱ�䣨Сʱ��
			else if(j==4)  plist[i].startime.minute = a;                                     //�洢���ʱ�䣨���ӣ�
			else if(j==5)  {InitTime(plist[i].arrivetime);  plist[i].arrivetime.hour = a;}   //��ʼ������ʱ�䣬�洢����ʱ�䣨Сʱ��
			else if(j==6)  plist[i].arrivetime.minute = a;                                   //�洢����ʱ�䣨���ӣ�
			else if(j==7)  plist[i].fee    = a;                                              //�洢����
		}
		(plist[0].fee)++;                               //����������1
	}
//------------------------------------------������-------------------------------------------------------
//	PrintPList(plist);                               //��ӡ���зɻ���Ϣ
 


//-----------------------------------------��β����----------------------------------------------
	in_p.close();                                            //�ر��ļ�
	return OK;

}






status SingleTrainToGraph(Graph& graph,const TLinkList& tp){               //��һ��𳵴���ͼ��
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


status TrainToGraph(Graph& graph,const TLinkList& tlinklist){                  //�����л���Ϣ����ͼ��
	TLinkList tll;
	tll = tlinklist;
	while(tll->next != NULL){
		tll = tll->next;
		SingleTrainToGraph(graph,tll);
	}
	return OK;
}

status PlaneToGraph(Graph& graph,const PList& plist){                        //�����еķɻ�����ͼ��
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
//-----------------------------����ģ��-------------------------------------
//**************************************************************************

status PrintList_T(const TLinkList& tp){       //��ӡ���л𳵰��
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

status PrintTPath(TNode* path){        //��ӡȷ�����ÿվ����ϸ��Ϣ
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

status PrintPList(PNode* plist){              //��ӡ���зɻ���Ϣ
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

status PrintPNode(const pNode& p){            //��ӡͼ��һ�����Ļ𳵻�ɻ��������Ϣ
	pNode pn;
	pn = p;
	while(pn->next != NULL){
		pn = pn->next;
		cout<<pn->number;
		cout<<"   ";
	}
	return OK;
}


status PrintGraph(const Graph& graph){           //��ӡͼ��������Ϣ
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