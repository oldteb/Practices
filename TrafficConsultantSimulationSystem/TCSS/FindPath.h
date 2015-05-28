#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include"PathInitFunction.h"
using namespace std;
void GetCustomersRequirement(Customer &customer);                                     //��ʼ���ͻ�����
string FindPlaneLowestpay(pNode p,PList plist);                               //ѡȡ����������֮�仨�����ٵķɻ����࣬���غ�����
string FindTrainLowestpay(pNode p,TLinkList tlinklist,int start,int arrival); //ѡȡ����������֮�仨�����ٵ��г��������г��İ������start�ͷֱ�Ϊ�ض��������յ�
string FindTrainLowestime_ignore(pNode p,TLinkList tlinklist,int start,int arrival); //ѡȡ����������֮���ʱ���ٵĻ𳵣����ػ𳵰���������Ե����վ��ʱ���ѷ��������
string FindTrainLowestime(pNode p,TLinkList tlinklist,int start,int arrival,string come); //ѡȡ������վ��֮����ʱ�ܸ��ϵĺ�ʱ��̵Ļ𳵣����İ��Ϊcome
string FindPlaneLowestime_ignore(pNode p,PList plist);                        //ѡȡ����������֮���ʱ���ٵķɻ������طɻ�������,�����ǵ����վ��ʱ�Ѹϲ��ϴ˺�������
string FindPlaneLowestime(pNode p,PList plist,string come);                   //ѡȡ����������֮���ʱ���ٵķɻ������طɻ������������ǵ����վ��ʱ�Ѹϲ��ϴ˺�������
int CountTrainCost(string name,TLinkList tlinkList,int start,int arrival);    //������Ӧ�Ļ𳵰�������г����䣬������Ӧ�Ļ���
int CountPlaneCost(string name,PList plist);                                  //������Ӧ�ĺ����������غ�����еķ���
Time CountPlaneTime(string name,PList plist);                                 //���뺽���������غ���ķ���ʱ��
Time CountTrainTime(string name,TLinkList tlinklist,int start,int arrival);   //������Ӧ�Ļ𳵰�������г����䣬���س˳��ĺ�ʱ
Time FindTArriveMoment(string name,TLinkList tlinklist,int arrival);          //������Ӧ�Ļ𳵰�����͵����վ�������ص����վ���ʱ��
Time FindPArriveMoment(string name,PList plist);                              //������Ӧ�ĺ����������ص�վ��ʱ��
Time FindTLeftMoment(string name,TLinkList tlinklist,int arrival);            //������Ӧ�Ļ𳵰�����͵����վ���������뿪��վ���ʱ��
Time FindPLeftMoment(string name,PList plist);                                //������Ӧ�ĺ��������������ʱ��
int FindPlanePath_lowpay(Graph graph,PList plist,Final final,int startcity,int destination);         //�õϽ�˹�����㷨���ʼ������Ŀ�ĵ�֮�仨�����ٵķɻ�������Ϣ����ʼ�����в�ͨ�ɻ��򷵻�0�����򷵻�1
int FindTrainPath_lowpay(Graph graph,TLinkList tlinklist,Final final,int startcity,int destination); //�õϽ�˹�����㷨���ʼ������Ŀ�ĵ�֮�仨�����ٵĻ𳵰����Ϣ����ʼ�����в�ͨ���򷵻�0�����򷵻�1
int FindTrainPath_lowtime(Graph graph,TLinkList tlinklist,Final final,int startcity,int destination);//�õϽ�˹�����㷨���ʼ������Ŀ�ĵ�֮���ʱ��̵Ļ𳵰����Ϣ����ʼ�����в�ͨ�ɻ��򷵻�0�����򷵻�1��
int FindPlanePath_lowtime(Graph graph,PList plist,Final final,int startcity,int destination);        //�õϽ�˹�����㷨���ʼ������Ŀ�ĵ�֮���ʱ��̵ķɻ�������Ϣ����ʼ�����в�ͨ�ɻ��򷵻�0�����򷵻�1


void FindPath(Graph graph ,PList plist ,TLinkList  tlinklist,Final final ,Customer customer){
		switch(customer.trafictool){
			case(train):{
				if(customer.strategy==lowpay){
					FindTrainPath_lowpay(graph,tlinklist,final,customer.startcity,customer.destination);
				}
				if(customer.strategy==lowtime){
					FindTrainPath_lowtime(graph,tlinklist,final,customer.startcity,customer.destination);
				}
			}; break;
			case(plane):{
				if(customer.strategy==lowpay){
					FindPlanePath_lowpay(graph,plist,final,customer.startcity,customer.destination);
				};
				if(customer.strategy==lowtime){
					FindPlanePath_lowtime(graph,plist,final,customer.startcity,customer.destination);
				}
			};break;
		}
}










/*int main(){
	int i;
	Graph graph;
	TLinkList tlinklist,p;int plane;
	PList plist; 
	Customer       customer;
    Final          final; //��Ҫ��������
	//TLinkList bp;                                      //������Ϣ�Ķ��룬�����ɺ���ΪNULL
	string name;
	//int pay;
	Time time;
//�������Ϣ
	ReadTrainInfo(tlinklist);
//���Ի𳵶���
	//PrintList_T(tlinklist);                                       //�鿴�𳵰��
	for(bp=tlinklist->next;bp!=NULL;bp=bp->next){                 //�鿴�����Ϣ
		cout<<endl;
		PrintTPath(bp->path);   
	}
	bp = NULL;
	system("pause");
//����ɻ���Ϣ
	ReadPlaneInfo(plist);
//���Էɻ�����
	//PrintPList(plist);                               //��ӡ���зɻ���Ϣ
	InitGraph(graph,CityNum);                               //����һ��ͼ
	//printf("a\n");
	//������Ϣ����ͼ��
	TrainToGraph(graph,tlinklist);
	//printf("b\n");
	//���ɻ���Ϣ����ͼ��
	PlaneToGraph(graph,plist);
	//�����Ϣ�Ƿ���ȷ����ͼ��
	//PrintGraph(graph);
	GetCustomersRequirement(customer);                                 //��ʼ���ͻ�����
	for(i=1;i<Num;i++){
			final[i].number="0";
			final[i].ip=0;
			final[i].ptll=NULL;
		}
	FindPath(graph,plist,tlinklist,final,customer);
	for(i=1;final[i].number!="0";i++){
		cout<<final[i].number<<endl;
		cout<<final[i].start<<endl;
		cout<<final[i].arrive<<endl;
	}
	system("pause");
	return 0;
}
*/
void GetCustomersRequirement(Customer &customer){                               //��ʼ���ͻ�����
	printf("please input your requirement\n");
	printf("The start city:");
	scanf("%d",&customer.startcity);
	//printf("\n");
	printf("The destination:");
	scanf("%d",&customer.destination);
	//printf("\n");
	printf("The Traffic Tool:");
	scanf("%d",&customer.trafictool);
	//printf("\n");
	printf("The Strategy:");
	scanf("%d",&customer.strategy);
}
TLinkList FindTheTrain(string name,TLinkList tlinklist){                   //����𳵰�����������ڰ�������л���Ϣ�Ľ��
	TLinkList p;
	for(p=tlinklist;p!=NULL;p=p->next){
		if(p->number!=name) continue;
		else break;
	}
	return p;
}
int FindThePlane(string name,PList plist){
	int i;
	for(i=1;i<=MaxVnum;i++){
		if(plist[i].number!=name) continue;
		else break;
	}
	return i;
}

string FindTrainLowestpay(pNode p ,TLinkList tlinklist,int start,int arrival){//ѡȡ����������֮����ڶ��г��У��������ٵ��г��������г��İ������start��arrival�ֱ�Ϊ�ض��������յ�
	int sum;pNode q;string name,finame;int cost;                             //����sum��¼�����ض��г��������軨�ѵĽ���ܺ�,name�洢������֮��ĳһ��𳵵İ����,tqΪ�ڻ𳵰�������в�����Ӧ��ε�ָ�룻
	q=p->next;                                                                      //�����q�������α�����ȡ�����м�ĸ�����Σ�tpָ�������ڻ������в�����Ӧ�İ��
	sum=MAX;
	while(q!=NULL){
		name=q->number; 
		cost=CountTrainCost(name,tlinklist,start,arrival);
		if(cost<sum){
			finame=name;                                               //finame��¼����ҵ��ģ��������ٵĻ𳵰����
			sum=cost;
		}
		q=q->next;
	}
	if(sum==MAX) return "0";
	return finame;
}
string FindPlaneLowestpay(pNode p,PList plist){                                                      //ѡȡ����������֮�仨�����ٵķɻ����࣬���غ�����
	string name,finame;int i;int cost;pNode q;
	cost=MAX;
	q=p->next;
	while(q!=NULL){
		name=q->number;
		for(i=1;i<=MaxVnum;i++){
			if(plist[i].number==name) break;
		}                                                                                            //�ڷɻ�������Ϣ�������ҵ���Ӧ�ɻ�����
		if(cost>plist[i].fee){
			cost=plist[i].fee;
			finame=name;
		}
		q=q->next;
	}
	if(cost==MAX) return "0";
	return finame;
}
string FindTrainLowestime_ignore(pNode p,TLinkList tlinklist,int start,int arrival){      //ѡȡ����������֮���ʱ���ٵĻ𳵣����ػ𳵰����,���Ե����վ��ʱ�����Ѿ����������
	Time sum;pNode q;string name,finame;Time cost;
	q=p->next;
	sum.hour=MAX;
	sum.minute=MAX;
	while(q!=NULL){
		name=q->number;
		//cout<<name<<endl;
	    cost=CountTrainTime(name,tlinklist,start,arrival);
		if(CompareTime(sum,cost)){
			sum=cost;
			finame=name;
		}
		q=q->next;
	}
	return finame;
}
string FindTrainLowestime(pNode p,TLinkList tlinklist,int start,int arrival,string come){  //ѡȡ������վ��֮����ʱ�ܸ��ϵĺ�ʱ��̵Ļ𳵣����İ��Ϊcome
	Time sum;  pNode q;  Time cost;  Time startstay,finishstay,stay;  string name,finame;
	q=p->next;
	//cout<<come<<endl;
	//if(q==NULL) printf("NULL\n");
	//while(q!=NULL){
		//cout<<q->number<<endl;
		//q=q->next;
	//}
	//printf("aaa\n");
	//q=p->next;
	sum.hour=MAX;
	sum.minute=MAX;
	while(q!=NULL){
		name=q->number;
		//cout<<name<<endl;
		finishstay=FindTLeftMoment(name,tlinklist,start);
		startstay=FindTArriveMoment(come,tlinklist,start);
		if(CompareTime(startstay,finishstay)){
			q=q->next;
			continue;
			}                                                             //����һ�೵��ʱ�Ѹϲ��ϴ��л�
		else{
			cost=CountTrainTime(name,tlinklist,start,arrival);
			stay=MinusTime(finishstay,startstay);
			cost=AddTime(cost,stay);
			if(CompareTime(sum,cost)) {
				sum=cost;
				finame=name;
			}
			q=q->next;
		}
	}
	if(sum.hour==MAX&&sum.minute==MAX) 
		//printf("END\n");
		return "0";
	
	else 
		//printf("END\n");
		return finame;
}
string FindPlaneLowestime_ignore(pNode p,PList plist){                                   //ѡȡ����������֮���ʱ���ٵķɻ������طɻ��������������ǵ����վ��ʱ�Ѹϲ��ϴ˺�������
	string name,finame;int i;Time cost,fincost;pNode q;
	q=p->next;
	fincost.hour=MAX;fincost.minute=MAX;
	while(q!=NULL){
		name=q->number;
		//cout<<name<<endl;
		for(i=1;i<=MaxVnum;i++){
			if(plist[i].number==name) break;
		}
		cost=MinusTime(plist[i].arrivetime,plist[i].startime);
		if(CompareTime(fincost,cost)) {
			fincost=cost;
			finame=name;
		}
		q=q->next;
	}
	return finame;
}		
string FindPlaneLowestime(pNode p,PList plist,string come){                           //ѡȡ����������֮���ʱ���ٵķɻ������طɻ������������ǵ����վ��ʱ�Ѹϲ��ϴ˺�������
	string name,finame;Time cost,fincost;pNode q;Time startstay,finishstay;
	q=p->next;Time stay;
	fincost.hour=MAX;fincost.minute=MAX;
	while(q!=NULL){
		name=q->number;
		startstay=FindPArriveMoment(come,plist);
		finishstay=FindPLeftMoment(name,plist);
		if(CompareTime(startstay,finishstay)) {
			q=q->next;
			continue;
		}
		else{
			cost=CountPlaneTime(name,plist);
			stay=MinusTime(finishstay,startstay);
			cost=AddTime(cost,stay);
			if(CompareTime(fincost,cost)){
				fincost=cost;
				finame=name;
			}
			q=q->next;
		}
	}
	if(fincost.hour==MAX&&fincost.minute) return "0";
	else return finame;
}		
int CountTrainCost(string name,TLinkList tlinklist,int start,int arrival){  //������Ӧ�Ļ𳵰�������г����䣬������Ӧ�Ļ���
	TLinkList p;int i=1,st_cost,ar_cost,cost;
	p=tlinklist;
	while(p->number!=name) p=p->next;                                   //�ڻ𳵰����Ϣ�����ϲ��ҵ���Ӧ�İ�Σ���pָ��
	while(p->path[i].station!=start) i++;                               //�ҵ�������ʼ��վ��
	st_cost=p->path[i].fee;                                             //��¼�Ӱ��ʼ��վ������ʼ��վ�Ļ���
	while(p->path[i].station!=arrival) i++;                             //�ҵ�������յ�վ
	ar_cost=p->path[i].fee;                                             //��¼�Ӱ��ʼ��վ�������յ�Ļ���
    cost=ar_cost-st_cost;
	return cost;
}

int CountPlaneCost(string name,PList plist){                              //������Ӧ�ĺ����������غ�����еķ���
	int i;int cost;
	for(i=1;i<=MaxVnum;i++){
		if(plist[i].number==name) break;
	}
	cost=plist[i].fee;
	return cost;
}
Time CountPlaneTime(string name,PList plist){                            //���뺽���������غ���ķ���ʱ��
	int i;Time cost;
	for(i=1;i<=MaxVnum;i++){
		if(plist[i].number==name) break;
	}
	cost=MinusTime(plist[i].arrivetime,plist[i].startime);
	return cost;
}
Time CountTrainTime(string name,TLinkList tlinklist,int start,int arrival){      //������Ӧ�Ļ𳵰�������г����䣬���س˳��ĺ�ʱ
	TLinkList p;int i=1;Time st_cost,ar_cost,cost;
	p=tlinklist;															
	while(p->number!=name) p=p->next;											 //���г���Ϣ�������ҵ�������г�
	while(p->path[i].station!=start) i++;										 //�ڸ��г���·���������ҵ��������ʼվ��
	st_cost=AddTime(p->path[i].arrivetime,p->path[i].staytime);
	while(p->path[i].station!=arrival) i++;                                      //�ҵ���ֹվ��
	ar_cost=p->path[i].arrivetime;
	cost=MinusTime(ar_cost,st_cost);
	return cost;
}

Time FindTArriveMoment(string name,TLinkList tlinklist,int arrival){             //������Ӧ�Ļ𳵰�����͵����վ�������ص����վ���ʱ��
	TLinkList p;int i=1;Time moment;
	p=tlinklist->next;
	while(p!=NULL){
		//printf("0000");
		if(p->number==name) break;
		else p=p->next;
	}
	if(p==NULL) printf("ERROR");
	while(p->path[i].station!=arrival) i++;
	moment=AddTime(p->startime,p->path[i].arrivetime);
	return moment;
}
Time FindPArriveMoment(string name,PList plist){                                  //������Ӧ�ĺ����������ص�վ��ʱ��
	int i;Time arrive;
	for(i=1;i<=MaxVnum;i++){
		if(plist[i].number==name) break;
	}
	arrive=plist[i].arrivetime;
	return arrive;
}
Time FindTLeftMoment(string name,TLinkList tlinklist,int arrival){               //������Ӧ�Ļ𳵰�����͵����վ���������뿪��վ���ʱ��
	TLinkList p;int i=1;Time moment;
	p=tlinklist;
	while(p!=NULL){
		if(p->number==name) break;
		else p=p->next;
	}
	while(p->path[i].station!=arrival) i++;
	moment=AddTime(p->path[i].arrivetime,p->path[i].staytime);
	moment=AddTime(p->startime,moment);
	return moment;
}
Time FindPLeftMoment(string name,PList plist){                                  //������Ӧ�ĺ��������������ʱ��
	int i;Time left;
	for(i=1;i<=MaxVnum;i++){
		if(plist[i].number==name) break;
	}
	left=plist[i].startime;
	return left;
}
int FindTrainPath_lowpay(Graph graph ,TLinkList tlinklist,Final final,int startcity,int destination){ //�õϽ�˹�����㷨���ʼ������Ŀ�ĵ�֮�仨�����ٵĻ𳵰����Ϣ,��ʼ��վ��ͨ���򷵻�0�����򷵻�1
	int pay;string name;int record[MaxVnum];int i,j,k=1;int cost[MaxVnum];Final road[MaxVnum]; 
	int min;int v;//string lastnumber[Maxvnum];                                                           //v��min����ʵ���㷨ʱ������ʱ�洢�ı���
	for(i=1;i<=graph.vexnum;i++) record[i]=0;                                                             //�����ʼ��
	for(i=1;i<=graph.vexnum;i++){
		for(j=1;j<MaxVnum;j++){
			road[i][j].number="0";
		}
	}                                                                                                    //��·�����г�ʼ������
	for(i=1;i<=graph.vexnum;i++){//����i������Ǹ������У�����ɲμ���¼���ݽṹ�ı�
		if(graph.arcs[startcity][i].trains->next==NULL) cost[i]=MAX;
		else{
			name=FindTrainLowestpay(graph.arcs[startcity][i].trains,tlinklist,startcity,i);
			cost[i]=CountTrainCost(name,tlinklist,startcity,i);
			road[i][1].number=name;
			road[i][1].start=startcity;
			road[i][1].arrive=i;
			road[i][1].ptll=FindTheTrain(name,tlinklist);
			//lastnumber[i]=name;
		}
	}																									 //�ڵϽ���˹���㷨�еı��
	for(i=1;i<=graph.vexnum;i++){
		if(cost[i]<MAX) break;
		else continue;
	}
	if(i==graph.vexnum+1) return 0;
	record[startcity]=1;                                                                             
	for(i=1;i<graph.vexnum;i++){
		min=MAX;
		for(j=1;j<=graph.vexnum;j++){
			if(record[j]!=1){
				if(min>cost[j]) {min=cost[j];v=j;}
			}
		}
		record[v]=1;
		for(j=1;j<=graph.vexnum;j++){
			name=FindTrainLowestpay(graph.arcs[v][j].trains,tlinklist,v,j);
		 /**startstay=FindArriveMoment(lastnumber[j],tlinklist,v);
			finishstay=FindLeftMoment(name,tlinklist,v);
			if(CompareTime(startstay,finishstay)) continue;                                                 //��ʾ�˿͵����վ��ʱ���г���ʱ���̵Ļ��ѷ���**/
			if(name=="0") continue;
			pay=CountTrainCost(name,tlinklist,v,j);
			if(!record[j]&&min+pay<cost[j]){
				cost[j]=min+pay;
				k=1;
				while(road[v][k].number!="0"){
					road[j][k].number=road[v][k].number;
					road[j][k].start=road[v][k].start;
					road[j][k].arrive=road[v][k].arrive;
					road[j][k].ptll=road[v][k].ptll;
					k++;
				}
				road[j][k].number=name;
				road[j][k].start=v;
				road[j][k].arrive=j;
				road[j][k].ptll=FindTheTrain(name,tlinklist);
			}
		}
	}
	for(i=1;road[destination][i].number!="0";i++){
		final[i].number=road[destination][i].number;
		final[i].start=road[destination][i].start;
		final[i].arrive=road[destination][i].arrive;
		final[i].ptll=road[destination][i].ptll;
	}
	return 1;
}
int FindPlanePath_lowpay(Graph graph,PList plist,Final final,int startcity,int destination){//�õϽ�˹�����㷨���ʼ������Ŀ�ĵ�֮�仨�����ٵķɻ�������Ϣ�����𷢳��в�ͨ�ɻ��򷵻�0�����򷵻�1
	int pay;string name;int record[MaxVnum+1];int i,j,k=1;int cost[MaxVnum];Final road[MaxVnum]; 
	int min;int v; 
	for(i=1;i<=MaxVnum;i++) record[i]=0;                                                                                      //�����ʼ��
	for(i=1;i<=graph.vexnum;i++){
		for(j=1;j<MaxVnum;j++){
			road[i][j].number="0";
		}
	}                                                                                                       //��·�����г�ʼ������
	for(i=1;i<=graph.vexnum;i++){//����i������Ǹ������У�����ɲμ���¼���ݽṹ�ı�
		if(graph.arcs[startcity][i].planes->next==NULL) cost[i]=MAX;
		else{
			name=FindPlaneLowestpay(graph.arcs[startcity][i].planes,plist);
			if(name=="0") continue;
			cost[i]=CountPlaneCost(name,plist);
			road[i][1].number=name;
			road[i][1].start=startcity;
			road[i][1].arrive=i;
			road[i][1].ip=FindThePlane(name,plist);
		}
	}																										//�ڵϽ���˹���㷨�еı��
	for(i=1;i<=graph.vexnum;i++){
		if(cost[i]<MAX) break;
		else continue;
	}
	if(i==graph.vexnum+1) return 0;
	record[startcity]=1;
	for(i=1;i<graph.vexnum;i++){
		min=MAX;
		for(j=1;j<=graph.vexnum;j++){
			if(record[j]!=1){
				if(min>cost[j]) {min=cost[j];v=j;}
			}
		}
		record[v]=1;//cout<<v<<endl;
		for(j=1;j<=graph.vexnum;j++){
			name=FindPlaneLowestpay(graph.arcs[v][j].planes,plist);
			if(name=="0") continue;
			//cout<<name<<endl;
			pay=CountPlaneCost(name,plist);
			//cout<<pay<<endl;
			if(!record[j]&&min+pay<cost[j]){
				cost[j]=min+pay;
				for(k=1;road[v][k].number!="0";k++){
					//cout<<road[v][k].number<<endl;
					road[j][k].number=road[v][k].number;
					road[j][k].start=road[v][k].start;
					road[j][k].arrive=road[v][k].arrive;
					road[j][k].ip=road[v][k].ip;
				}
				road[j][k].number=name;
				road[j][k].start=v;
				road[j][k].arrive=j;
				road[j][k].ip=FindThePlane(name,plist);
				/**for(k=1;road[j][k].number!="0";k++){
					cout<<road[j][k].number<<endl;
				}**/
			}
		}
	}
	/**for(i=1;road[destination][i].number!="0";i++){
		cout<<road[destination][i].number<<endl;
	}**/
	for(i=1;road[destination][i].number!="0";i++){
		final[i].number=road[destination][i].number;
		final[i].start=road[destination][i].start;
		final[i].arrive=road[destination][i].arrive;
		final[i].ip=road[destination][i].ip;
		//cout<<road[destination][i].number<<endl;
	}
	return 1;
	/**for(i=1;i<=graph.vexnum;i++){
		if(road[i][1].number=="0") continue;
		else {
			for(j=1;road[i][j].number!="0";j++){
				cout<<road[i][j].number<<endl;
			}
			printf("\n");
		}
	}**/
}			


int FindTrainPath_lowtime(Graph graph,TLinkList tlinklist,Final final,int startcity,int destination){      //�õϽ�˹�����㷨���ʼ������Ŀ�ĵ�֮���ʱ��̵Ļ𳵰����Ϣ,�����в�ͨ���򷵻�0�����򷵻�1
	Time pay,min,stay,finishstay,startstay;string name;int record[MaxVnum];int i,j,k=1;Time cost[MaxVnum];Final road[MaxVnum]; 
	int v;string lastnumber[MaxVnum];Time Max;                                                                          //����lastnumber������������Ÿ�������֮����·�����һ���𳵰�Σ������㷨�еĻ���
	Max.hour=MAX;Max.minute=MAX;
	for(i=1;i<=graph.vexnum;i++) lastnumber[i]="0";															   //��ʼ������
	for(i=1;i<=graph.vexnum;i++) record[i]=0;                                                                                      //�����ʼ��
	for(i=1;i<=graph.vexnum;i++){
		for(j=1;j<MaxVnum;j++){
			road[i][j].number="0";
		}
	}                                                                                                       //��·�����г�ʼ������
	for(i=1;i<=graph.vexnum;i++){                                                                           //����i������Ǹ������У�����ɲμ���¼���ݽṹ�ı�
		if(graph.arcs[startcity][i].trains->next==NULL) {
			cost[i].hour=MAX;
			cost[i].minute=MAX;
		}
		else{
			name=FindTrainLowestime_ignore(graph.arcs[startcity][i].trains,tlinklist,startcity,i);
			cost[i]=CountTrainTime(name,tlinklist,startcity,i);
			road[i][1].number=name;
			road[i][1].start=startcity;
			road[i][1].arrive=i;
			road[i][1].ptll=FindTheTrain(name,tlinklist);
			lastnumber[i]=name;
		}
	}																										//�ڵϽ���˹���㷨�еı��
	for(i=1;i<=graph.vexnum;i++){
		if(CompareTime(Max,cost[i])) break;
		else continue;
	}
	if(i==graph.vexnum+1) return 0;		
	record[startcity]=1;                                                                             
	for(i=1;i<graph.vexnum;i++){
		min=Max;
		for(j=1;j<=graph.vexnum;j++){
			if(record[j]!=1){
				if(CompareTime(min,cost[j])) {min=cost[j];v=j;}
			}
		}
		record[v]=1;
		for(j=1;j<=graph.vexnum;j++){
			/**name=FindTrainLowestime(graph.arcs[v][j].trains,tlinklist,v,j);
			pay=CountTrainTime(name,tlinklist,v,j);
			startstay=FindArriveMoment(lastnumber[j],tlinklist,v);
			finishstay=FindLeftMoment(name,tlinklist,v);
			if(CompareTime(startstay,finishstay)) continue;                                                 //��ʾ�˿͵����վ��ʱ���г���ʱ���̵Ļ��ѷ���**/
			name=FindTrainLowestime(graph.arcs[v][j].trains,tlinklist,v,j,lastnumber[v]);
			if(name=="0") continue;
			startstay=FindTArriveMoment(lastnumber[v],tlinklist,v);
			finishstay=FindTLeftMoment(name,tlinklist,v);
			stay=MinusTime(finishstay,startstay);
			pay=CountTrainTime(name,tlinklist,v,j);
			pay=AddTime(pay,stay);
			if(!record[j]&&CompareTime(cost[j],AddTime(pay,min))){
				cost[j]=AddTime(pay,min);
				k=1;
				while(road[v][k].number!="0"){
					road[j][k].number=road[v][k].number;
					road[j][k].start=road[v][k].start;
					road[j][k].arrive=road[v][k].arrive;
					road[j][k].ptll=road[v][k].ptll;
					k++;
				}
				road[j][k].number=name;
				road[j][k].start=v;
				road[j][k].arrive=j;
				road[j][k].ptll=FindTheTrain(name,tlinklist);
				lastnumber[j]=name;
			}
		}
	}
	for(i=1;road[destination][i].number!="0";i++){
		final[i].number=road[destination][i].number;
		final[i].start=road[destination][i].start;
		final[i].arrive=road[destination][i].arrive;
		final[i].ptll=road[destination][i].ptll;
	}
	return 1;
}		
int FindPlanePath_lowtime(Graph graph,PList plist,Final final,int startcity,int destination){				   //�õϽ���˹���㷨��ôӳ����ص�Ŀ�ĵغ�ʱ���ٵķɻ����࣬���𷢳��в�ͨ�ɻ��򷵻�0�����򷵻�1
	Time pay,min,stay,startstay,finishstay;string name;int record[MaxVnum];int i,j,k=1;Time cost[MaxVnum];Final road[MaxVnum]; 
	int v;string lastnumber[MaxVnum];Time Max;                                                             //����lastnumber������������Ÿ�������֮����·�����һ���𳵰�Σ������㷨�еĻ���
	for(i=1;i<=graph.vexnum;i++) lastnumber[i]="0";														   //��ʼ������
	Max.hour=MAX;Max.minute=MAX;
	for(i=1;i<=graph.vexnum;i++) record[i]=0;                                                               //�����ʼ��
	for(i=1;i<=graph.vexnum;i++){
		for(j=1;j<MaxVnum;j++){
			road[i][j].number="0";
		}
	}                                                                                                      //��·�����г�ʼ������
	for(i=1;i<=graph.vexnum;i++){                                                                           //����i������Ǹ������У�����ɲμ���¼���ݽṹ�ı�
		if(graph.arcs[startcity][i].planes->next==NULL) {
			cost[i].hour=MAX;
			cost[i].minute=MAX;
		}
		else{
			name=FindPlaneLowestime_ignore(graph.arcs[startcity][i].planes,plist);
			cost[i]=CountPlaneTime(name,plist);
			road[i][1].number=name;
			road[i][1].start=startcity;
			road[i][1].arrive=i;
			road[i][1].ip=FindThePlane(name,plist);
			lastnumber[i]=name;
		}
	}
	for(i=1;i<=graph.vexnum;i++){
		if(CompareTime(Max,cost[i])) break;
		else continue;
	}
	if(i==graph.vexnum+1) return 0;																									//�ڵϽ���˹���㷨�еı��
	record[startcity]=1;                                                                             
	for(i=1;i<graph.vexnum;i++){
		min=Max;
		for(j=1;j<=graph.vexnum;j++){
			if(record[j]!=1){
				if(CompareTime(min,cost[j])) {min=cost[j];v=j;}
			}
		}
		record[v]=1;
		for(j=1;j<=graph.vexnum;j++){
			name=FindPlaneLowestime(graph.arcs[v][j].planes,plist,lastnumber[v]);
			/**pay=CountTrainTime(name,tlinklist,v,j);
			startstay=FindPArriveMoment(lastnumber[j],plist);
			finishstay=FindPLeftMoment(name,plist);
			if(CompareTime(startstay,finishstay)) continue;                                                
			stay=MinusTime(finishstay,startstay);**/
			if(name=="0") continue;
			startstay=FindPArriveMoment(lastnumber[v],plist);
			finishstay=FindPLeftMoment(name,plist);
			stay=MinusTime(finishstay,startstay);
			pay=CountPlaneTime(name,plist);
			pay=AddTime(pay,stay);
			if(!record[j]&&CompareTime(cost[j],AddTime(pay,min))){
				cost[j]=AddTime(pay,min);
				k=1;
				while(road[v][k].number!="0"){
					road[j][k].number=road[v][k].number;
					road[j][k].start=road[v][k].start;
					road[j][k].arrive=road[v][k].arrive;
					road[j][k].ip=road[v][k].ip;
					k++;
				}
				road[j][k].number=name;
				road[j][k].start=v;
				road[j][k].arrive=j;
				road[j][k].ip=FindThePlane(name,plist);
				lastnumber[j]=name;
			}
		}
	}
	for(i=1;road[destination][i].number!="0";i++){
		final[i].number=road[destination][i].number;
		final[i].start=road[destination][i].start;
		final[i].arrive=road[destination][i].arrive;
		final[i].ip=road[destination][i].ip;
	}
	return 1;
}		


void InitFinal(Final& final){
	for(int i=1;i<Num;i++){
		final[i].number="0";
		final[i].ip=0;
		final[i].ptll=NULL;
	}
}
		