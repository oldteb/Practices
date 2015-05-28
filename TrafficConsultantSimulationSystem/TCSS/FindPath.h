#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include"PathInitFunction.h"
using namespace std;
void GetCustomersRequirement(Customer &customer);                                     //初始化客户需求
string FindPlaneLowestpay(pNode p,PList plist);                               //选取在两个城市之间花费最少的飞机航班，返回航班名
string FindTrainLowestpay(pNode p,TLinkList tlinklist,int start,int arrival); //选取在两个城市之间花费最少的列车，返回列车的班次名，start和分别为特定的起点和终点
string FindTrainLowestime_ignore(pNode p,TLinkList tlinklist,int start,int arrival); //选取在两个城市之间耗时最少的火车，返回火车班次名，忽略到达该站点时火车已发车的情况
string FindTrainLowestime(pNode p,TLinkList tlinklist,int start,int arrival,string come); //选取在两个站点之间来时能赶上的耗时最短的火车，来的班次为come
string FindPlaneLowestime_ignore(pNode p,PList plist);                        //选取在两个城市之间耗时最少的飞机，返回飞机航班名,不考虑到达该站点时已赶不上此航班的情况
string FindPlaneLowestime(pNode p,PList plist,string come);                   //选取在两个城市之间耗时最少的飞机，返回飞机航班名，考虑到达该站点时已赶不上此航班的情况
int CountTrainCost(string name,TLinkList tlinkList,int start,int arrival);    //输入相应的火车班次名和行车区间，返回相应的花费
int CountPlaneCost(string name,PList plist);                                  //输入相应的航班名，返回航班飞行的费用
Time CountPlaneTime(string name,PList plist);                                 //输入航班名，返回航班的飞行时间
Time CountTrainTime(string name,TLinkList tlinklist,int start,int arrival);   //输入相应的火车班次名和行车区间，返回乘车的耗时
Time FindTArriveMoment(string name,TLinkList tlinklist,int arrival);          //输入相应的火车班次名和到达的站名，返回到达该站点的时刻
Time FindPArriveMoment(string name,PList plist);                              //输入相应的航班名，返回到站的时刻
Time FindTLeftMoment(string name,TLinkList tlinklist,int arrival);            //输入相应的火车班次名和到达的站名，返回离开该站点的时刻
Time FindPLeftMoment(string name,PList plist);                                //输入相应的航班名，返回起飞时刻
int FindPlanePath_lowpay(Graph graph,PList plist,Final final,int startcity,int destination);         //用迪杰斯特拉算法求得始发地与目的地之间花费最少的飞机航班信息，若始发城市不通飞机则返回0，否则返回1
int FindTrainPath_lowpay(Graph graph,TLinkList tlinklist,Final final,int startcity,int destination); //用迪杰斯特拉算法求得始发地与目的地之间花费最少的火车班次信息，若始发城市不通火车则返回0，否则返回1
int FindTrainPath_lowtime(Graph graph,TLinkList tlinklist,Final final,int startcity,int destination);//用迪杰斯特拉算法求得始发地与目的地之间耗时最短的火车班次信息，若始发城市不通飞机则返回0，否则返回1，
int FindPlanePath_lowtime(Graph graph,PList plist,Final final,int startcity,int destination);        //用迪杰斯特拉算法求得始发地与目的地之间耗时最短的飞机航班信息，若始发城市不通飞机则返回0，否则返回1


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
    Final          final; //主要变量定义
	//TLinkList bp;                                      //检查火车信息的读入，检查完成后置为NULL
	string name;
	//int pay;
	Time time;
//读入火车信息
	ReadTrainInfo(tlinklist);
//测试火车读入
	//PrintList_T(tlinklist);                                       //查看火车班次
	for(bp=tlinklist->next;bp!=NULL;bp=bp->next){                 //查看班次信息
		cout<<endl;
		PrintTPath(bp->path);   
	}
	bp = NULL;
	system("pause");
//读入飞机信息
	ReadPlaneInfo(plist);
//测试飞机读入
	//PrintPList(plist);                               //打印所有飞机信息
	InitGraph(graph,CityNum);                               //创建一个图
	//printf("a\n");
	//将火车信息读入图中
	TrainToGraph(graph,tlinklist);
	//printf("b\n");
	//将飞机信息读入图中
	PlaneToGraph(graph,plist);
	//检查信息是否正确读入图中
	//PrintGraph(graph);
	GetCustomersRequirement(customer);                                 //初始化客户需求
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
void GetCustomersRequirement(Customer &customer){                               //初始化客户需求
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
TLinkList FindTheTrain(string name,TLinkList tlinklist){                   //输入火车班次名，返回在班次链表中火车信息的结点
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

string FindTrainLowestpay(pNode p ,TLinkList tlinklist,int start,int arrival){//选取在两个城市之间的众多列车中，花费最少的列车，返回列车的班次名，start和arrival分别为特定的起点和终点
	int sum;pNode q;string name,finame;int cost;                             //这里sum记录火车在特定行车区间所需花费的金额总和,name存储两城市之间某一班火车的班次名,tq为在火车班次链表中查找相应班次的指针；
	q=p->next;                                                                      //这里的q用以依次遍历读取两城市间的各个班次，tp指针用以在火车链表中查找相应的班次
	sum=MAX;
	while(q!=NULL){
		name=q->number; 
		cost=CountTrainCost(name,tlinklist,start,arrival);
		if(cost<sum){
			finame=name;                                               //finame记录最后找到的，花费最少的火车班次名
			sum=cost;
		}
		q=q->next;
	}
	if(sum==MAX) return "0";
	return finame;
}
string FindPlaneLowestpay(pNode p,PList plist){                                                      //选取在两个城市之间花费最少的飞机航班，返回航班名
	string name,finame;int i;int cost;pNode q;
	cost=MAX;
	q=p->next;
	while(q!=NULL){
		name=q->number;
		for(i=1;i<=MaxVnum;i++){
			if(plist[i].number==name) break;
		}                                                                                            //在飞机航班信息数组中找到相应飞机航班
		if(cost>plist[i].fee){
			cost=plist[i].fee;
			finame=name;
		}
		q=q->next;
	}
	if(cost==MAX) return "0";
	return finame;
}
string FindTrainLowestime_ignore(pNode p,TLinkList tlinklist,int start,int arrival){      //选取在两个城市之间耗时最少的火车，返回火车班次名,忽略到达该站点时，火车已经发车的情况
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
string FindTrainLowestime(pNode p,TLinkList tlinklist,int start,int arrival,string come){  //选取在两个站点之间来时能赶上的耗时最短的火车，来的班次为come
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
			}                                                             //乘上一班车来时已赶不上此列火车
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
string FindPlaneLowestime_ignore(pNode p,PList plist){                                   //选取在两个城市之间耗时最少的飞机，返回飞机航班名，不考虑到达该站点时已赶不上此航班的情况
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
string FindPlaneLowestime(pNode p,PList plist,string come){                           //选取在两个城市之间耗时最少的飞机，返回飞机航班名，考虑到达该站点时已赶不上此航班的情况
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
int CountTrainCost(string name,TLinkList tlinklist,int start,int arrival){  //输入相应的火车班次名和行车区间，返回相应的花费
	TLinkList p;int i=1,st_cost,ar_cost,cost;
	p=tlinklist;
	while(p->number!=name) p=p->next;                                   //在火车班次信息链表上查找到相应的班次，由p指向
	while(p->path[i].station!=start) i++;                               //找到区间间的始发站点
	st_cost=p->path[i].fee;                                             //记录从班次始发站到区间始发站的花费
	while(p->path[i].station!=arrival) i++;                             //找到区间的终点站
	ar_cost=p->path[i].fee;                                             //记录从班次始发站到区间终点的花费
    cost=ar_cost-st_cost;
	return cost;
}

int CountPlaneCost(string name,PList plist){                              //输入相应的航班名，返回航班飞行的费用
	int i;int cost;
	for(i=1;i<=MaxVnum;i++){
		if(plist[i].number==name) break;
	}
	cost=plist[i].fee;
	return cost;
}
Time CountPlaneTime(string name,PList plist){                            //输入航班名，返回航班的飞行时间
	int i;Time cost;
	for(i=1;i<=MaxVnum;i++){
		if(plist[i].number==name) break;
	}
	cost=MinusTime(plist[i].arrivetime,plist[i].startime);
	return cost;
}
Time CountTrainTime(string name,TLinkList tlinklist,int start,int arrival){      //输入相应的火车班次名和行车区间，返回乘车的耗时
	TLinkList p;int i=1;Time st_cost,ar_cost,cost;
	p=tlinklist;															
	while(p->number!=name) p=p->next;											 //在列车信息链表中找到所求的列车
	while(p->path[i].station!=start) i++;										 //在该列车的路径矩阵中找到所求的起始站点
	st_cost=AddTime(p->path[i].arrivetime,p->path[i].staytime);
	while(p->path[i].station!=arrival) i++;                                      //找到终止站点
	ar_cost=p->path[i].arrivetime;
	cost=MinusTime(ar_cost,st_cost);
	return cost;
}

Time FindTArriveMoment(string name,TLinkList tlinklist,int arrival){             //输入相应的火车班次名和到达的站名，返回到达该站点的时刻
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
Time FindPArriveMoment(string name,PList plist){                                  //输入相应的航班名，返回到站的时刻
	int i;Time arrive;
	for(i=1;i<=MaxVnum;i++){
		if(plist[i].number==name) break;
	}
	arrive=plist[i].arrivetime;
	return arrive;
}
Time FindTLeftMoment(string name,TLinkList tlinklist,int arrival){               //输入相应的火车班次名和到达的站名，返回离开该站点的时刻
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
Time FindPLeftMoment(string name,PList plist){                                  //输入相应的航班名，返回起飞时刻
	int i;Time left;
	for(i=1;i<=MaxVnum;i++){
		if(plist[i].number==name) break;
	}
	left=plist[i].startime;
	return left;
}
int FindTrainPath_lowpay(Graph graph ,TLinkList tlinklist,Final final,int startcity,int destination){ //用迪杰斯特拉算法求得始发地与目的地之间花费最少的火车班次信息,若始发站不通火车则返回0，否则返回1
	int pay;string name;int record[MaxVnum];int i,j,k=1;int cost[MaxVnum];Final road[MaxVnum]; 
	int min;int v;//string lastnumber[Maxvnum];                                                           //v和min都是实现算法时用以临时存储的变量
	for(i=1;i<=graph.vexnum;i++) record[i]=0;                                                             //数组初始化
	for(i=1;i<=graph.vexnum;i++){
		for(j=1;j<MaxVnum;j++){
			road[i][j].number="0";
		}
	}                                                                                                    //对路径进行初始化操作
	for(i=1;i<=graph.vexnum;i++){//这里i代表的是各个城市，具体可参见附录数据结构的表
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
	}																									 //在迪杰特斯拉算法中的标记
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
			if(CompareTime(startstay,finishstay)) continue;                                                 //表示乘客到达该站点时，行车耗时更短的火车已发车**/
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
int FindPlanePath_lowpay(Graph graph,PList plist,Final final,int startcity,int destination){//用迪杰斯特拉算法求得始发地与目的地之间花费最少的飞机航班信息，该起发城市不通飞机则返回0，否则返回1
	int pay;string name;int record[MaxVnum+1];int i,j,k=1;int cost[MaxVnum];Final road[MaxVnum]; 
	int min;int v; 
	for(i=1;i<=MaxVnum;i++) record[i]=0;                                                                                      //数组初始化
	for(i=1;i<=graph.vexnum;i++){
		for(j=1;j<MaxVnum;j++){
			road[i][j].number="0";
		}
	}                                                                                                       //对路径进行初始化操作
	for(i=1;i<=graph.vexnum;i++){//这里i代表的是各个城市，具体可参见附录数据结构的表
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
	}																										//在迪杰特斯拉算法中的标记
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


int FindTrainPath_lowtime(Graph graph,TLinkList tlinklist,Final final,int startcity,int destination){      //用迪杰斯特拉算法求得始发地与目的地之间耗时最短的火车班次信息,若城市不通火车则返回0，否则返回1
	Time pay,min,stay,finishstay,startstay;string name;int record[MaxVnum];int i,j,k=1;Time cost[MaxVnum];Final road[MaxVnum]; 
	int v;string lastnumber[MaxVnum];Time Max;                                                                          //数组lastnumber在这里用来存放各个城市之间线路的最后一个火车班次，用以算法中的回溯
	Max.hour=MAX;Max.minute=MAX;
	for(i=1;i<=graph.vexnum;i++) lastnumber[i]="0";															   //初始化数组
	for(i=1;i<=graph.vexnum;i++) record[i]=0;                                                                                      //数组初始化
	for(i=1;i<=graph.vexnum;i++){
		for(j=1;j<MaxVnum;j++){
			road[i][j].number="0";
		}
	}                                                                                                       //对路径进行初始化操作
	for(i=1;i<=graph.vexnum;i++){                                                                           //这里i代表的是各个城市，具体可参见附录数据结构的表
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
	}																										//在迪杰特斯拉算法中的标记
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
			if(CompareTime(startstay,finishstay)) continue;                                                 //表示乘客到达该站点时，行车耗时更短的火车已发车**/
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
int FindPlanePath_lowtime(Graph graph,PList plist,Final final,int startcity,int destination){				   //用迪杰特斯拉算法求得从出发地到目的地耗时最少的飞机航班，该起发城市不通飞机则返回0，否则返回1
	Time pay,min,stay,startstay,finishstay;string name;int record[MaxVnum];int i,j,k=1;Time cost[MaxVnum];Final road[MaxVnum]; 
	int v;string lastnumber[MaxVnum];Time Max;                                                             //数组lastnumber在这里用来存放各个城市之间线路的最后一个火车班次，用以算法中的回溯
	for(i=1;i<=graph.vexnum;i++) lastnumber[i]="0";														   //初始化数组
	Max.hour=MAX;Max.minute=MAX;
	for(i=1;i<=graph.vexnum;i++) record[i]=0;                                                               //数组初始化
	for(i=1;i<=graph.vexnum;i++){
		for(j=1;j<MaxVnum;j++){
			road[i][j].number="0";
		}
	}                                                                                                      //对路径进行初始化操作
	for(i=1;i<=graph.vexnum;i++){                                                                           //这里i代表的是各个城市，具体可参见附录数据结构的表
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
	if(i==graph.vexnum+1) return 0;																									//在迪杰特斯拉算法中的标记
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
		