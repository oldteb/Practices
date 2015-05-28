#include<windows.h>
#include<iostream>
#include<stdio.h>
#include"resource.h"


#define		OK       1
#define		ERROR    0

using namespace std;

typedef int status;




//****************************************************************************
//-----------------------------����ģ��---------------------------------------
//****************************************************************************


int CityToInt(char* szText){                                  //ƥ����ж�Ӧ�ı��
	if(strcmp(szText,"B��ͷ")==0)     return 1;
	if(strcmp(szText,"B����")==0)     return 2;
	if(strcmp(szText,"B����")==0)     return 3;
	if(strcmp(szText,"C����")==0)     return 49;
	if(strcmp(szText,"C����")==0)     return 46;
	if(strcmp(szText,"C�ɶ�")==0)     return 4;
	if(strcmp(szText,"C��ɳ")==0)     return 47;
	if(strcmp(szText,"D����")==0)     return 5;
	if(strcmp(szText,"D����")==0)     return 6;
	if(strcmp(szText,"D��ͬ")==0)     return 7;
	if(strcmp(szText,"D��ݸ")==0)     return 8;
	if(strcmp(szText,"F����")==0)     return 9;
	if(strcmp(szText,"G����")==0)     return 10;
	if(strcmp(szText,"G����")==0)     return 11;
	if(strcmp(szText,"G����")==0)     return 12;
	if(strcmp(szText,"H������")==0)   return 13;
	if(strcmp(szText,"H����")==0)     return 14;
	if(strcmp(szText,"H����")==0)     return 15;
	if(strcmp(szText,"H�Ϸ�")==0)     return 16;
	if(strcmp(szText,"H��ˮ")==0)     return 17;
	if(strcmp(szText,"H���ͺ���")==0) return 18;
	if(strcmp(szText,"J����")==0)     return 19;
	if(strcmp(szText,"K����")==0)     return 20;
	if(strcmp(szText,"L����")==0)     return 21;
	if(strcmp(szText,"L����")==0)     return 22;
	if(strcmp(szText,"L����")==0)     return 23;
	if(strcmp(szText,"L����")==0)     return 24;
	if(strcmp(szText,"N�ϲ�")==0)     return 25;
	if(strcmp(szText,"N�Ͼ�")==0)     return 26;
	if(strcmp(szText,"N����")==0)     return 27;
	if(strcmp(szText,"N����")==0)     return 28;
	if(strcmp(szText,"Q�ൺ")==0)     return 29;
	if(strcmp(szText,"S����")==0)     return 32;
	if(strcmp(szText,"S����")==0)     return 33;
	if(strcmp(szText,"Sʯ��ׯ")==0)   return 34;
	if(strcmp(szText,"S����")==0)     return 35;
	if(strcmp(szText,"T̫ԭ")==0)     return 36;
	if(strcmp(szText,"T���")==0)     return 37;
	if(strcmp(szText,"W����")==0)     return 38;
	if(strcmp(szText,"W��³ľ��")==0) return 39;
	if(strcmp(szText,"W�ߺ�")==0)     return 40;
	if(strcmp(szText,"W�人")==0)     return 41;
	if(strcmp(szText,"X����")==0)     return 42;
	if(strcmp(szText,"X����")==0)     return 43;
	if(strcmp(szText,"X�Ϻ�")==0)     return 31;
	if(strcmp(szText,"X����")==0)     return 30;
	if(strcmp(szText,"X����")==0)     return 44;
	if(strcmp(szText,"Y����")==0)     return 45;
	if(strcmp(szText,"Z֣��")==0)     return 48;
	if(strcmp(szText,"Z����")==0)     return 50;
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




status InitCombolBox(HWND& hComBox){                               //�����в��뵽��������
	SendMessage(hComBox, CB_INSERTSTRING, 0,  (LPARAM)"B��ͷ");
	SendMessage(hComBox, CB_INSERTSTRING, 1,  (LPARAM)"B����");
	SendMessage(hComBox, CB_INSERTSTRING, 2,  (LPARAM)"B����");
	SendMessage(hComBox, CB_INSERTSTRING, 3,  (LPARAM)"C����");
	SendMessage(hComBox, CB_INSERTSTRING, 4,  (LPARAM)"C����");
	SendMessage(hComBox, CB_INSERTSTRING, 5,  (LPARAM)"C�ɶ�");
	SendMessage(hComBox, CB_INSERTSTRING, 6,  (LPARAM)"C��ɳ");
	SendMessage(hComBox, CB_INSERTSTRING, 7,  (LPARAM)"D����");
	SendMessage(hComBox, CB_INSERTSTRING, 8,  (LPARAM)"D����");
	SendMessage(hComBox, CB_INSERTSTRING, 9,  (LPARAM)"D��ͬ");
	SendMessage(hComBox, CB_INSERTSTRING, 10, (LPARAM)"D��ݸ");
	SendMessage(hComBox, CB_INSERTSTRING, 11, (LPARAM)"F����");
	SendMessage(hComBox, CB_INSERTSTRING, 12, (LPARAM)"G����");
	SendMessage(hComBox, CB_INSERTSTRING, 13, (LPARAM)"G����");
	SendMessage(hComBox, CB_INSERTSTRING, 14, (LPARAM)"G����");
	SendMessage(hComBox, CB_INSERTSTRING, 15, (LPARAM)"H������");
	SendMessage(hComBox, CB_INSERTSTRING, 16, (LPARAM)"H����");
	SendMessage(hComBox, CB_INSERTSTRING, 17, (LPARAM)"H����");
	SendMessage(hComBox, CB_INSERTSTRING, 18, (LPARAM)"H�Ϸ�");
	SendMessage(hComBox, CB_INSERTSTRING, 19, (LPARAM)"H��ˮ");
	SendMessage(hComBox, CB_INSERTSTRING, 20, (LPARAM)"H���ͺ���");
	SendMessage(hComBox, CB_INSERTSTRING, 21, (LPARAM)"J����");
	SendMessage(hComBox, CB_INSERTSTRING, 22, (LPARAM)"K����");
	SendMessage(hComBox, CB_INSERTSTRING, 23, (LPARAM)"L����");
	SendMessage(hComBox, CB_INSERTSTRING, 24, (LPARAM)"L����");
	SendMessage(hComBox, CB_INSERTSTRING, 25, (LPARAM)"L����");
	SendMessage(hComBox, CB_INSERTSTRING, 26, (LPARAM)"L����");
	SendMessage(hComBox, CB_INSERTSTRING, 27, (LPARAM)"N�ϲ�");
	SendMessage(hComBox, CB_INSERTSTRING, 28, (LPARAM)"N�Ͼ�");
	SendMessage(hComBox, CB_INSERTSTRING, 29, (LPARAM)"N����");
	SendMessage(hComBox, CB_INSERTSTRING, 30, (LPARAM)"N����");
	SendMessage(hComBox, CB_INSERTSTRING, 31, (LPARAM)"Q�ൺ");
	SendMessage(hComBox, CB_INSERTSTRING, 32, (LPARAM)"S����");
	SendMessage(hComBox, CB_INSERTSTRING, 33, (LPARAM)"S����");
	SendMessage(hComBox, CB_INSERTSTRING, 34, (LPARAM)"Sʯ��ׯ");
	SendMessage(hComBox, CB_INSERTSTRING, 35, (LPARAM)"S����");
	SendMessage(hComBox, CB_INSERTSTRING, 36, (LPARAM)"T̫ԭ");
	SendMessage(hComBox, CB_INSERTSTRING, 37, (LPARAM)"T���");
	SendMessage(hComBox, CB_INSERTSTRING, 38, (LPARAM)"W����");
	SendMessage(hComBox, CB_INSERTSTRING, 39, (LPARAM)"W��³ľ��");
	SendMessage(hComBox, CB_INSERTSTRING, 40, (LPARAM)"W�ߺ�");
	SendMessage(hComBox, CB_INSERTSTRING, 41, (LPARAM)"W�人");
	SendMessage(hComBox, CB_INSERTSTRING, 42, (LPARAM)"X����");
	SendMessage(hComBox, CB_INSERTSTRING, 43, (LPARAM)"X����");
	SendMessage(hComBox, CB_INSERTSTRING, 44, (LPARAM)"X�Ϻ�");
	SendMessage(hComBox, CB_INSERTSTRING, 45, (LPARAM)"X����");
	SendMessage(hComBox, CB_INSERTSTRING, 46, (LPARAM)"X����");
	SendMessage(hComBox, CB_INSERTSTRING, 47, (LPARAM)"Y����");
	SendMessage(hComBox, CB_INSERTSTRING, 48, (LPARAM)"Z֣��");
	SendMessage(hComBox, CB_INSERTSTRING, 49, (LPARAM)"Z����");


	return OK;
}


//****************************************************************************
//-----------------------------����ģ��---------------------------------------
//****************************************************************************

wstring StringToWString(const string& s){                              //ANSIתUTF-16 (wstring��)
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



/*wstring TimeToWString(const Time& time){                   //��ʱ����תΪUTF-16��ʽ (wstring��)
	TCHAR str[Num]={0};
	wstring wstr;
	if(time.hour<10 && time.minute<10)        _stprintf(str, _T("  0%d:0%d  "), time.hour, time.minute);
	else if(time.hour>=10 && time.minute<10)  _stprintf(str, _T("  %d:0%d  "), time.hour, time.minute);
	else if(time.hour<10 && time.minute>=10)  _stprintf(str, _T("  0%d:%d  "), time.hour, time.minute);
	else if(time.hour>=10 && time.minute>=10) _stprintf(str, _T("  %d:%d  "), time.hour, time.minute);
	wstr = str;
	return wstr;
}*/





status TimeToString(Time time,string& str1,int n){                   //��ʱ����תΪUTF-16��ʽ (wstring��)
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




Time GetStartime_T(const Final& final,int i){                 //��ȡ����ʼʱ��
	int c;
	Time time1;
	for(c=1; final[i].ptll->path[c].station!=final[i].start && c<=final[i].ptll->path[0].fee; c++){}
	if(c == Num+1)  exit(0);//MessageBox(hwndDlg,_T("���һ���ʼʱ�����")��NULL,MB_OK);
	time1 = AddTime(final[i].ptll->startime, final[i].ptll->path[c].arrivetime);
	return  AddTime(time1, final[i].ptll->path[c].staytime);
}

Time GetArrivetime_T(const Final& final,int i){               //��ȡ�𳵵���ʱ��
	int c;
	for(c=1; final[i].ptll->path[c].station!=final[i].arrive && c<=final[i].ptll->path[0].fee; c++){}
	if(c == Num+1)  exit(0);
	return  AddTime(final[i].ptll->startime, final[i].ptll->path[c].arrivetime);
}

string GetFee_T(const Final& final,int i){                    //��ȡ�𳵻��ѣ�������֮�䣩����ת��UTF-16��ʽ (wstring��)
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


string GetFee_P(const Final& final,int i,const PList& plist){                    //��ȡ�ɻ����ѣ���ת��UTF-16��ʽ (wstring��)
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
	static int n=0;                              //��¼�ڼ���
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
		MessageBox(hwndDlg, "�Բ���û���ҵ���Ӧ�Ľ��!", "��ʾ", MB_OK);
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
			//MessageBox(hwndDlg, t1, "��ѯ���", MB_OK);  
			TimeToString(GetArrivetime_T(final,i),time2,n);
			fee      = GetFee_T(final,i);

			itfee    = itfee+AddFee_T(final,i);
			//��������Ϣװ��һ������
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
			//MessageBox(hwndDlg, t1, "��ѯ���", MB_OK);   
			TimeToString(plist[final[i].ip].arrivetime,time2,n);
			fee  = GetFee_P(final,i,plist);
			itfee  = itfee+plist[final[i].ip].fee;
			//��������Ϣװ��һ������
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
	MessageBox(hwndDlg, t, "��ѯ���", MB_OK);       //������Ϣ���ӡ������

	return OK;
}






	//s = _T("abcd efgh 1234");
	//_stprintf_s(szText, MaxVnum, _T("��������Ϊ%d\n������%s"), s);

//**************************************************************************
//-----------------------------����ģ��-------------------------------------
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
