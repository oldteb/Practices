#include<windows.h>
#include<iostream>
#include<stdio.h>
#include"resource.h"


#define		OK       1
#define		ERROR    0

using namespace std;

typedef int status;




//****************************************************************************
//-----------------------------数据模块---------------------------------------
//****************************************************************************


int CityToInt(char* szText){                                  //匹配城市对应的编号
	if(strcmp(szText,"B包头")==0)     return 1;
	if(strcmp(szText,"B宝鸡")==0)     return 2;
	if(strcmp(szText,"B北京")==0)     return 3;
	if(strcmp(szText,"C重庆")==0)     return 49;
	if(strcmp(szText,"C长春")==0)     return 46;
	if(strcmp(szText,"C成都")==0)     return 4;
	if(strcmp(szText,"C长沙")==0)     return 47;
	if(strcmp(szText,"D大连")==0)     return 5;
	if(strcmp(szText,"D大庆")==0)     return 6;
	if(strcmp(szText,"D大同")==0)     return 7;
	if(strcmp(szText,"D东莞")==0)     return 8;
	if(strcmp(szText,"F福州")==0)     return 9;
	if(strcmp(szText,"G赣州")==0)     return 10;
	if(strcmp(szText,"G广州")==0)     return 11;
	if(strcmp(szText,"G贵阳")==0)     return 12;
	if(strcmp(szText,"H哈尔滨")==0)   return 13;
	if(strcmp(szText,"H海口")==0)     return 14;
	if(strcmp(szText,"H杭州")==0)     return 15;
	if(strcmp(szText,"H合肥")==0)     return 16;
	if(strcmp(szText,"H衡水")==0)     return 17;
	if(strcmp(szText,"H呼和浩特")==0) return 18;
	if(strcmp(szText,"J济南")==0)     return 19;
	if(strcmp(szText,"K昆明")==0)     return 20;
	if(strcmp(szText,"L拉萨")==0)     return 21;
	if(strcmp(szText,"L兰州")==0)     return 22;
	if(strcmp(szText,"L柳州")==0)     return 23;
	if(strcmp(szText,"L洛阳")==0)     return 24;
	if(strcmp(szText,"N南昌")==0)     return 25;
	if(strcmp(szText,"N南京")==0)     return 26;
	if(strcmp(szText,"N南宁")==0)     return 27;
	if(strcmp(szText,"N宁波")==0)     return 28;
	if(strcmp(szText,"Q青岛")==0)     return 29;
	if(strcmp(szText,"S深圳")==0)     return 32;
	if(strcmp(szText,"S沈阳")==0)     return 33;
	if(strcmp(szText,"S石家庄")==0)   return 34;
	if(strcmp(szText,"S苏州")==0)     return 35;
	if(strcmp(szText,"T太原")==0)     return 36;
	if(strcmp(szText,"T天津")==0)     return 37;
	if(strcmp(szText,"W温州")==0)     return 38;
	if(strcmp(szText,"W乌鲁木齐")==0) return 39;
	if(strcmp(szText,"W芜湖")==0)     return 40;
	if(strcmp(szText,"W武汉")==0)     return 41;
	if(strcmp(szText,"X西安")==0)     return 42;
	if(strcmp(szText,"X西宁")==0)     return 43;
	if(strcmp(szText,"X上海")==0)     return 31;
	if(strcmp(szText,"X厦门")==0)     return 30;
	if(strcmp(szText,"X徐州")==0)     return 44;
	if(strcmp(szText,"Y银川")==0)     return 45;
	if(strcmp(szText,"Z郑州")==0)     return 48;
	if(strcmp(szText,"Z株洲")==0)     return 50;
	else return ERROR;
}


string IntToCity(int i){
	string s;
	if(i == 1)      s = "Baotou";  
	if(i == 2)      s = "Baoji"; 
	if(i == 3)      s = "Beijin";
	if(i == 49)     s = "Chongqin";
	if(i == 46)     s = "Changchun";
	if(i == 4)      s = "Chengdu";
	if(i == 47)     s = "Changsha";
	if(i == 5)      s = "Dalian";
	if(i == 6)      s = "Daqin";
	if(i == 7)      s = "Datong";
	if(i == 8)      s = "Dongguan";
	if(i == 9)      s = "Fuzhou";
	if(i == 10)     s = "Zhangzhou";
	if(i == 11)     s = "Guangzhou";
	if(i == 12)     s = "Guiyang";
	if(i == 13)     s = "Ha'erbin";
	if(i == 14)     s = "Haikou";
	if(i == 15)     s = "Hangzhou";
	if(i == 16)     s = "Hefei";
	if(i == 17)     s = "Henshui";
	if(i == 18)     s = "Huhehaote";
	if(i == 19)     s = "Jinan";
	if(i == 20)     s = "Kunming";
	if(i == 21)     s = "Lasa";
	if(i == 22)     s = "Lanzhou";
	if(i == 23)     s = "Liuzhou";
	if(i == 24)     s = "Luoyang";
	if(i == 25)     s = "Nanchang";
	if(i == 26)     s = "Nanjing";            
	if(i == 27)     s = "Nanning";
	if(i == 28)     s = "Ningbo";
	if(i == 29)     s = "Qindao";
	if(i == 32)     s = "Shenzhen";
	if(i == 33)     s = "Shengyang";
	if(i == 34)     s = "Shijiazhuang";
	if(i == 35)     s = "Suzhou";
	if(i == 36)     s = "Taiyuan";
	if(i == 37)     s = "Tianjing";
	if(i == 38)     s = "Wenzhou";
	if(i == 39)     s = "Wulumuqi";
	if(i == 40)     s = "Wuhu";
	if(i == 41)     s = "Wuhan";
	if(i == 42)     s = "Xi'an";
	if(i == 43)     s = "Xi'ning";
	if(i == 31)     s = "Shanghai";
	if(i == 30 )    s = "Xiamen";
	if(i == 44)     s = "Xuzhou";
	if(i == 45)     s = "Yinchuan";
	if(i == 48)     s = "Zhenzhou";
	if(i == 50)     s = "Zhuzhou";
	return s;
}




status InitCombolBox(HWND& hComBox){                               //将城市插入到下拉框中
	SendMessage(hComBox, CB_INSERTSTRING, 0,  (LPARAM)"B包头");
	SendMessage(hComBox, CB_INSERTSTRING, 1,  (LPARAM)"B宝鸡");
	SendMessage(hComBox, CB_INSERTSTRING, 2,  (LPARAM)"B北京");
	SendMessage(hComBox, CB_INSERTSTRING, 3,  (LPARAM)"C重庆");
	SendMessage(hComBox, CB_INSERTSTRING, 4,  (LPARAM)"C长春");
	SendMessage(hComBox, CB_INSERTSTRING, 5,  (LPARAM)"C成都");
	SendMessage(hComBox, CB_INSERTSTRING, 6,  (LPARAM)"C长沙");
	SendMessage(hComBox, CB_INSERTSTRING, 7,  (LPARAM)"D大连");
	SendMessage(hComBox, CB_INSERTSTRING, 8,  (LPARAM)"D大庆");
	SendMessage(hComBox, CB_INSERTSTRING, 9,  (LPARAM)"D大同");
	SendMessage(hComBox, CB_INSERTSTRING, 10, (LPARAM)"D东莞");
	SendMessage(hComBox, CB_INSERTSTRING, 11, (LPARAM)"F福州");
	SendMessage(hComBox, CB_INSERTSTRING, 12, (LPARAM)"G赣州");
	SendMessage(hComBox, CB_INSERTSTRING, 13, (LPARAM)"G广州");
	SendMessage(hComBox, CB_INSERTSTRING, 14, (LPARAM)"G贵阳");
	SendMessage(hComBox, CB_INSERTSTRING, 15, (LPARAM)"H哈尔滨");
	SendMessage(hComBox, CB_INSERTSTRING, 16, (LPARAM)"H海口");
	SendMessage(hComBox, CB_INSERTSTRING, 17, (LPARAM)"H杭州");
	SendMessage(hComBox, CB_INSERTSTRING, 18, (LPARAM)"H合肥");
	SendMessage(hComBox, CB_INSERTSTRING, 19, (LPARAM)"H衡水");
	SendMessage(hComBox, CB_INSERTSTRING, 20, (LPARAM)"H呼和浩特");
	SendMessage(hComBox, CB_INSERTSTRING, 21, (LPARAM)"J济南");
	SendMessage(hComBox, CB_INSERTSTRING, 22, (LPARAM)"K昆明");
	SendMessage(hComBox, CB_INSERTSTRING, 23, (LPARAM)"L拉萨");
	SendMessage(hComBox, CB_INSERTSTRING, 24, (LPARAM)"L兰州");
	SendMessage(hComBox, CB_INSERTSTRING, 25, (LPARAM)"L柳州");
	SendMessage(hComBox, CB_INSERTSTRING, 26, (LPARAM)"L洛阳");
	SendMessage(hComBox, CB_INSERTSTRING, 27, (LPARAM)"N南昌");
	SendMessage(hComBox, CB_INSERTSTRING, 28, (LPARAM)"N南京");
	SendMessage(hComBox, CB_INSERTSTRING, 29, (LPARAM)"N南宁");
	SendMessage(hComBox, CB_INSERTSTRING, 30, (LPARAM)"N宁波");
	SendMessage(hComBox, CB_INSERTSTRING, 31, (LPARAM)"Q青岛");
	SendMessage(hComBox, CB_INSERTSTRING, 32, (LPARAM)"S深圳");
	SendMessage(hComBox, CB_INSERTSTRING, 33, (LPARAM)"S沈阳");
	SendMessage(hComBox, CB_INSERTSTRING, 34, (LPARAM)"S石家庄");
	SendMessage(hComBox, CB_INSERTSTRING, 35, (LPARAM)"S苏州");
	SendMessage(hComBox, CB_INSERTSTRING, 36, (LPARAM)"T太原");
	SendMessage(hComBox, CB_INSERTSTRING, 37, (LPARAM)"T天津");
	SendMessage(hComBox, CB_INSERTSTRING, 38, (LPARAM)"W温州");
	SendMessage(hComBox, CB_INSERTSTRING, 39, (LPARAM)"W乌鲁木齐");
	SendMessage(hComBox, CB_INSERTSTRING, 40, (LPARAM)"W芜湖");
	SendMessage(hComBox, CB_INSERTSTRING, 41, (LPARAM)"W武汉");
	SendMessage(hComBox, CB_INSERTSTRING, 42, (LPARAM)"X西安");
	SendMessage(hComBox, CB_INSERTSTRING, 43, (LPARAM)"X西宁");
	SendMessage(hComBox, CB_INSERTSTRING, 44, (LPARAM)"X上海");
	SendMessage(hComBox, CB_INSERTSTRING, 45, (LPARAM)"X厦门");
	SendMessage(hComBox, CB_INSERTSTRING, 46, (LPARAM)"X徐州");
	SendMessage(hComBox, CB_INSERTSTRING, 47, (LPARAM)"Y银川");
	SendMessage(hComBox, CB_INSERTSTRING, 48, (LPARAM)"Z郑州");
	SendMessage(hComBox, CB_INSERTSTRING, 49, (LPARAM)"Z株洲");


	return OK;
}


//****************************************************************************
//-----------------------------功能模块---------------------------------------
//****************************************************************************

wstring StringToWString(const string& s){                              //ANSI转UTF-16 (wstring类)
	const char* _Source = s.c_str();
    size_t _Dsize = MultiByteToWideChar(CP_ACP, 0, _Source, -1, NULL, 0);
    wchar_t *_Dest = new wchar_t[_Dsize];
	MultiByteToWideChar(CP_ACP, 0, _Source, -1, _Dest, _Dsize);
	wstring result = _Dest;
	delete []_Dest;
	return result;
}

/*status a(wstring wstr,TCHAR* szText){
	//const char* _Source = s.c_str();
    //size_t _Dsize = MultiByteToWideChar(CP_ACP, 0, _Source, -1, NULL, 0);
	size_t _Dsize = WideCharToMultiByte(CP_ACP,0,wstr,-1,NULL,0,NULL,NULL);
    TCHAR* _Dest = new TCHAR[_Dsize];
	//MultiByteToWideChar(CP_ACP, 0, _Source, -1, _Dest, _Dsize);
	WideCharToMultiByte(CP_ACP,0,wstr,-1,_Dest,0,NULL,NULL);
	szText = _Dest;
	delete []_Dest;
	return OK;
}*/



/*wstring TimeToWString(const Time& time){                   //将时间类转为UTF-16格式 (wstring类)
	TCHAR str[Num]={0};
	wstring wstr;
	if(time.hour<10 && time.minute<10)        _stprintf(str, _T("  0%d:0%d  "), time.hour, time.minute);
	else if(time.hour>=10 && time.minute<10)  _stprintf(str, _T("  %d:0%d  "), time.hour, time.minute);
	else if(time.hour<10 && time.minute>=10)  _stprintf(str, _T("  0%d:%d  "), time.hour, time.minute);
	else if(time.hour>=10 && time.minute>=10) _stprintf(str, _T("  %d:%d  "), time.hour, time.minute);
	wstr = str;
	return wstr;
}*/





status TimeToString(Time time,string& str1,int n){                   //将时间类转为UTF-16格式 (wstring类)
	int d=2;
	char str[Num]={0};	
	char ds[Num]={0};
	if(n==0){
		if(time.hour<24){
			if(time.hour<10 && time.minute<10)        sprintf_s(str, Num,"0%d:0%d", time.hour, time.minute);
			else if(time.hour>=10 && time.minute<10)  sprintf_s(str, Num,"%d:0%d", time.hour, time.minute);
			else if(time.hour<10 && time.minute>=10)  sprintf_s(str, Num,"0%d:%d", time.hour, time.minute);
			else if(time.hour>=10 && time.minute>=10) sprintf_s(str, Num,"%d:%d", time.hour, time.minute);
			str1 = str;
			return OK;
		} 
		if(time.hour>=24 && time.hour<48){
			string dstr = "";
			n = n+1;
			time.hour   = time.hour-24;
			if(time.hour<10 && time.minute<10)        sprintf_s(str, Num,"0%d:0%d", time.hour, time.minute);
			else if(time.hour>=10 && time.minute<10)  sprintf_s(str, Num,"%d:0%d", time.hour, time.minute);
			else if(time.hour<10 && time.minute>=10)  sprintf_s(str, Num,"0%d:%d", time.hour, time.minute);
			else if(time.hour>=10 && time.minute>=10) sprintf_s(str, Num,"%d:%d", time.hour, time.minute);
			str1 = dstr + str;
			return OK;
		}
		if(time.hour>=48 && time.hour<72){
			string dstr = "";
			n = n+2;
			time.hour   = time.hour-48;
			if(time.hour<10 && time.minute<10)        sprintf_s(str, Num,"0%d:0%d", time.hour, time.minute);
			else if(time.hour>=10 && time.minute<10)  sprintf_s(str, Num,"%d:0%d", time.hour, time.minute);
			else if(time.hour<10 && time.minute>=10)  sprintf_s(str, Num,"0%d:%d", time.hour, time.minute);
			else if(time.hour>=10 && time.minute>=10) sprintf_s(str, Num,"%d:%d", time.hour, time.minute);
			str1 = dstr + str;
			return OK;
		}
	}
	if(n==1){
		if(time.hour<24){
			string dstr = "(2nd day)";
			if(time.hour<10 && time.minute<10)        sprintf_s(str, Num,"0%d:0%d", time.hour, time.minute);
			else if(time.hour>=10 && time.minute<10)  sprintf_s(str, Num,"%d:0%d", time.hour, time.minute);
			else if(time.hour<10 && time.minute>=10)  sprintf_s(str, Num,"0%d:%d", time.hour, time.minute);
			else if(time.hour>=10 && time.minute>=10) sprintf_s(str, Num,"%d:%d", time.hour, time.minute);
			str1 = dstr+str;
			return OK;
		} 
		if(time.hour>=24 && time.hour<48){
			string dstr = "(3th day)";
			n = n+1;
			time.hour   = time.hour-24;
			if(time.hour<10 && time.minute<10)        sprintf_s(str, Num,"0%d:0%d", time.hour, time.minute);
			else if(time.hour>=10 && time.minute<10)  sprintf_s(str, Num,"%d:0%d", time.hour, time.minute);
			else if(time.hour<10 && time.minute>=10)  sprintf_s(str, Num,"0%d:%d", time.hour, time.minute);
			else if(time.hour>=10 && time.minute>=10) sprintf_s(str, Num,"%d:%d", time.hour, time.minute);
			str1 = dstr + str;
			return OK;
		}
		if(time.hour>=48 && time.hour<72){

			string dstr = "(3rd day)";
			n = n+2;
			time.hour   = time.hour-48;
			if(time.hour<10 && time.minute<10)        sprintf_s(str, Num,"0%d:0%d", time.hour, time.minute);
			else if(time.hour>=10 && time.minute<10)  sprintf_s(str, Num,"%d:0%d", time.hour, time.minute);
			else if(time.hour<10 && time.minute>=10)  sprintf_s(str, Num,"0%d:%d", time.hour, time.minute);
			else if(time.hour>=10 && time.minute>=10) sprintf_s(str, Num,"%d:%d", time.hour, time.minute);
			str1 = dstr + str;
			return OK;
		}
	}
	if(n==2){
		if(time.hour<24){
			if(time.hour<10 && time.minute<10)        sprintf_s(str, Num,"0%d:0%d", time.hour, time.minute);
			else if(time.hour>=10 && time.minute<10)  sprintf_s(str, Num,"%d:0%d", time.hour, time.minute);
			else if(time.hour<10 && time.minute>=10)  sprintf_s(str, Num,"0%d:%d", time.hour, time.minute);
			else if(time.hour>=10 && time.minute>=10) sprintf_s(str, Num,"%d:%d", time.hour, time.minute);
			str1 = str;
			return OK;
		} 
		if(time.hour>=24 && time.hour<48){
			string dstr = "(2nd day)";
			n = n+1;
			time.hour   = time.hour-24;
			if(time.hour<10 && time.minute<10)        sprintf_s(str, Num,"0%d:0%d", time.hour, time.minute);
			else if(time.hour>=10 && time.minute<10)  sprintf_s(str, Num,"%d:0%d", time.hour, time.minute);
			else if(time.hour<10 && time.minute>=10)  sprintf_s(str, Num,"0%d:%d", time.hour, time.minute);
			else if(time.hour>=10 && time.minute>=10) sprintf_s(str, Num,"%d:%d", time.hour, time.minute);
			str1 = dstr + str;
			return OK;
		}
		if(time.hour>=48 && time.hour<72){
			d = d+n;
			string dstr = "(3rd day)";
			n = n+2;
			time.hour   = time.hour-48;
			if(time.hour<10 && time.minute<10)        sprintf_s(str, Num,"0%d:0%d", time.hour, time.minute);
			else if(time.hour>=10 && time.minute<10)  sprintf_s(str, Num,"%d:0%d", time.hour, time.minute);
			else if(time.hour<10 && time.minute>=10)  sprintf_s(str, Num,"0%d:%d", time.hour, time.minute);
			else if(time.hour>=10 && time.minute>=10) sprintf_s(str, Num,"%d:%d", time.hour, time.minute);
			str1 = dstr + str;
			return OK;
		}
	}


}
	

string IntToString(int d){
	char str[Num]={0};
	sprintf_s(str, Num,"%d", d);
	string str1 = str;
	return str1;
}




Time GetStartime_T(const Final& final,int i){                 //获取火车起始时间
	int c;
	Time time1;
	for(c=1; final[i].ptll->path[c].station!=final[i].start && c<=final[i].ptll->path[0].fee; c++){}
	if(c == Num+1)  exit(0);//MessageBox(hwndDlg,_T("查找火车起始时间错误！")，NULL,MB_OK);
	time1 = AddTime(final[i].ptll->startime, final[i].ptll->path[c].arrivetime);
	return  AddTime(time1, final[i].ptll->path[c].staytime);
}

Time GetArrivetime_T(const Final& final,int i){               //获取火车到达时间
	int c;
	for(c=1; final[i].ptll->path[c].station!=final[i].arrive && c<=final[i].ptll->path[0].fee; c++){}
	if(c == Num+1)  exit(0);
	return  AddTime(final[i].ptll->startime, final[i].ptll->path[c].arrivetime);
}

string GetFee_T(const Final& final,int i){                    //获取火车花费（两城市之间），并转成UTF-16格式 (wstring类)
	int c,f1,f2;
	char str[Num];
	for(c=1; final[i].ptll->path[c].station!=final[i].start && c<=Num; c++){}
	if(c == Num+1)  exit(0);
	f1 = final[i].ptll->path[c].fee;
	for(c=1; final[i].ptll->path[c].station!=final[i].arrive && c<=Num; c++){}
	if(c == Num+1)  exit(0);
	f2 = final[i].ptll->path[c].fee;
	f1 = f2-f1;
	sprintf_s(str,Num,"  %d  \n",f1);
	string str1 = str;
	return  str1;
}


int AddFee_T(const Final& final,int i){
	int c,f1,f2;
	char str[Num];
	for(c=1; final[i].ptll->path[c].station!=final[i].start && c<=Num; c++){}
	if(c == Num+1)  exit(0);
	f1 = final[i].ptll->path[c].fee;
	for(c=1; final[i].ptll->path[c].station!=final[i].arrive && c<=Num; c++){}
	if(c == Num+1)  exit(0);
	f2 = final[i].ptll->path[c].fee;
	f1 = f2-f1;
	return f1;
}


string GetFee_P(const Final& final,int i,const PList& plist){                    //获取飞机花费，并转成UTF-16格式 (wstring类)
	char str[Num];
	sprintf_s(str,Num,"  %d  \n",plist[final[i].ip].fee);
	string str1 = str;
	return  str1;
}


Time CountTheTotalTime(Final final,TLinkList tlinklist,PList plist,Customer customer){
	Time start,arrive,total;int i;
	for(i=1;i<=Num;i++){
		if(final[i].number!="0") continue;
		else break;
	}
	i--;
	if(customer.trafictool==train){
		start=FindTLeftMoment(final[1].number,tlinklist,final[1].start);
		arrive=FindTArriveMoment(final[i].number,tlinklist,final[i].arrive);
		total=MinusTime(arrive,start);
		return total;
	}
	if(customer.trafictool==plane){
		start=FindPLeftMoment(final[1].number,plist);
		arrive=FindPArriveMoment(final[i].number,plist);
		total=MinusTime(arrive,start);
		return total;
	}
}



status InitMessageBox(HWND hwndDlg, Final& final,const Customer& customer,PList& plist,TLinkList tlinklist){
	int i;
	static int n=0;                              //记录第几天
	TRAFICTOOL   ctt;
	string       number, city1,city2,time1, time2, fee;
	string       ttime, tfee;
	Time         tttime1,tttime2;
	int 	     itfee=0;
	string       wstr,wstr1;
	char str[MaxVnum]={0};
	string str1 ="-->";
	string str2 ="    ";
	//char* city2={0};
	ctt = customer.trafictool;
	if(final[1].number=="0"){
		MessageBox(hwndDlg, "对不起，没有找到相应的结果!", "提示", MB_OK);
		return OK;
	}
	//InitTime(tttime);
	if(ctt == train){
		wstr = "number       start           arrive    startime   arrivetime   fee\n";
		//cout<<szText<<endl;
		for(i=1; final[i].number!="0"; i++){
			number = final[i].number;
			city1  = IntToCity(final[i].start);
			city2  = IntToCity(final[i].arrive);
			//sprintf_s(str,MaxVnum, "         %d       ", final[i].start);
			//city1 = str;
			//sprintf_s(str,MaxVnum, "         %d       ", final[i].arrive);
			//city2 = str;
			//city1  = final[i].start;
			//city2  = final[i].arrive;
			TimeToString(GetStartime_T(final,i),time1,n);  //const char* t1 = time1.c_str();;
			//MessageBox(hwndDlg, t1, "咨询结果", MB_OK);  
			TimeToString(GetArrivetime_T(final,i),time2,n);
			fee      = GetFee_T(final,i);

			itfee    = itfee+AddFee_T(final,i);
			//将整行信息装在一个串中
			//sprintf_s(str1, 1024,"%-9s %-6s %-6s %-6s %-6s %-6s",number,city1,city2,time1,time2,fee);
			//wstr1 = str1;
			//wstr = wstr+wstr1;
			wstr = wstr+number+str2+city1+str1+city2+str2+time1+str2+time2+str2+fee;
		}
		tfee = "\n\ntotal charge:  "+IntToString(itfee);
		wstr = wstr+tfee;
		/*i--;
		tttime1 = FindTArriveMoment(final[i].number,tlinklist,final[i].arrive);
		tttime2 = FindTLeftMoment(final[1].number,tlinklist,final[1].start);
		tttime1 = MinusTime(tttime1,tttime2);
		TimeToString(GetStartime_T(final,i),ttime,n);
		ttime = "\ntotal time:  "+ttime;
		*/
		tttime1 = CountTheTotalTime(final,tlinklist,plist,customer);
		TimeToString(tttime1,ttime,n);
		ttime = "\ntotal time:  "+ttime;
		wstr = wstr+ttime;
		//i--;
		//tttime = MinusTime(Time a1,Time a2);


	}
	else if(ctt == plane){
		wstr = "number       start           arrive    startime   arrivetime   fee\n";
		for(i=1; final[i].number!="0"; i++){
			number = final[i].number;
			city1  = IntToCity(final[i].start);
			city2  = IntToCity(final[i].arrive);
			TimeToString(plist[final[i].ip].startime,time1,n); // const char* t1 = time1.c_str();;
			//MessageBox(hwndDlg, t1, "咨询结果", MB_OK);   
			TimeToString(plist[final[i].ip].arrivetime,time2,n);
			fee  = GetFee_P(final,i,plist);
			itfee  = itfee+plist[final[i].ip].fee;
			//将整行信息装在一个串中
		    //str1 = number
			//wstr1 = str1;
			//wstr   = wstr+wstr1;
			wstr = wstr+number+str2+city1+str1+city2+str2+time1+str2+time2+str2+fee;
		}
		tfee = "\n\ntotal charge:  "+IntToString(itfee);
		wstr = wstr+tfee;
	}
	//a(wstr,szText);
	//string s(wstr.begin(), wstr.end());
	//szText = wstr;
	
	//sscanf(szText, "%s", wstr);
	//WideCharToMultiByte(CP_ACP,0,wstr,-1, LPCSTR lpMultiByteStr, int cchMultiByte, LPCSTR lpDefaultChar, PBOOL pfUsedDefaultChar );
	//szText = wstr.c_str();
	//TCHAR t[1000];
	//WideCharToMultiByte(CP_ACP, WC_NO_BEST_FIT_CHARS, wstr.c_str(), -1, t, 1000, NULL, NULL); 
	const char* t = wstr.c_str();
	//cout<<t<<endl;
	//MessageBeep(0);
	MessageBox(hwndDlg, t, "咨询结果", MB_OK);       //调用消息框打印输出结果

	return OK;
}






	//s = _T("abcd efgh 1234");
	//_stprintf_s(szText, MaxVnum, _T("城市数量为%d\n哈哈哈%s"), s);

//**************************************************************************
//-----------------------------测试模块-------------------------------------
//**************************************************************************


status TestFinalInit_T(Final& final,const TLinkList& tlinklist){
	final[1].number = "CA1351";
	final[1].start  = 3;
	final[1].arrive = 11;
	//final[1].ptll   = tlinklist->next;
	final[1].ip     = 2;

	final[2].number = "ZH9889";
	final[2].start  = 3;
	final[2].arrive = 32;
	//final[2].ptll   = tlinklist->next;
	final[2].ip     = 3;




	return OK;
}

status PrintFinal(const Final& final,const TLinkList& tlinklist,const PList& plist){
	for(int i=1;final[i].number!="0";i++){
		cout<<final[i].number<<"  ";
		cout<<final[i].start<<"  ";
		cout<<final[i].arrive<<"  ";
		cout<<plist[final[i].ip].fee<<"  ";
	    //cout<<final[i].ptll->number<<endl;
		cout<<final[i].ip<<endl;
	}
	return OK;
}
