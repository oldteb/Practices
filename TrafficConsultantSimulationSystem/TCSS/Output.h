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


int CityToInt(TCHAR* szText){                                  //匹配城市对应的编号
	if(_tcscmp(szText,_T("B包头"))==0)     return 1;
	if(_tcscmp(szText,_T("B宝鸡"))==0)     return 2;
	if(_tcscmp(szText,_T("B北京"))==0)     return 3;
	if(_tcscmp(szText,_T("C重庆"))==0)     return 49;
	if(_tcscmp(szText,_T("C长春"))==0)     return 46;
	if(_tcscmp(szText,_T("C成都"))==0)     return 4;
	if(_tcscmp(szText,_T("C长沙"))==0)     return 47;
	if(_tcscmp(szText,_T("D大连"))==0)     return 5;
	if(_tcscmp(szText,_T("D大庆"))==0)     return 6;
	if(_tcscmp(szText,_T("D大同"))==0)     return 7;
	if(_tcscmp(szText,_T("D东莞"))==0)     return 8;
	if(_tcscmp(szText,_T("F福州"))==0)     return 9;
	if(_tcscmp(szText,_T("G赣州"))==0)     return 10;
	if(_tcscmp(szText,_T("G广州"))==0)     return 11;
	if(_tcscmp(szText,_T("G贵阳"))==0)     return 12;
	if(_tcscmp(szText,_T("H哈尔滨"))==0)   return 13;
	if(_tcscmp(szText,_T("H海口"))==0)     return 14;
	if(_tcscmp(szText,_T("H杭州"))==0)     return 15;
	if(_tcscmp(szText,_T("H合肥"))==0)     return 16;
	if(_tcscmp(szText,_T("H衡水"))==0)     return 17;
	if(_tcscmp(szText,_T("H呼和浩特"))==0) return 18;
	if(_tcscmp(szText,_T("J济南"))==0)     return 19;
	if(_tcscmp(szText,_T("K昆明"))==0)     return 20;
	if(_tcscmp(szText,_T("L拉萨"))==0)     return 21;
	if(_tcscmp(szText,_T("L兰州"))==0)     return 22;
	if(_tcscmp(szText,_T("L柳州"))==0)     return 23;
	if(_tcscmp(szText,_T("L洛阳"))==0)     return 24;
	if(_tcscmp(szText,_T("N南昌"))==0)     return 25;
	if(_tcscmp(szText,_T("N南京"))==0)     return 26;
	if(_tcscmp(szText,_T("N南宁"))==0)     return 27;
	if(_tcscmp(szText,_T("N宁波"))==0)     return 28;
	if(_tcscmp(szText,_T("Q青岛"))==0)     return 29;
	if(_tcscmp(szText,_T("S深圳"))==0)     return 32;
	if(_tcscmp(szText,_T("S沈阳"))==0)     return 33;
	if(_tcscmp(szText,_T("S石家庄"))==0)   return 34;
	if(_tcscmp(szText,_T("S苏州"))==0)     return 35;
	if(_tcscmp(szText,_T("T太原"))==0)     return 36;
	if(_tcscmp(szText,_T("T天津"))==0)     return 37;
	if(_tcscmp(szText,_T("W温州"))==0)     return 38;
	if(_tcscmp(szText,_T("W乌鲁木齐"))==0) return 39;
	if(_tcscmp(szText,_T("W芜湖"))==0)     return 40;
	if(_tcscmp(szText,_T("W武汉"))==0)     return 41;
	if(_tcscmp(szText,_T("X西安"))==0)     return 42;
	if(_tcscmp(szText,_T("X西宁"))==0)     return 43;
	if(_tcscmp(szText,_T("X上海"))==0)     return 31;
	if(_tcscmp(szText,_T("X厦门"))==0)     return 30;
	if(_tcscmp(szText,_T("X徐州"))==0)     return 44;
	if(_tcscmp(szText,_T("Y银川"))==0)     return 45;
	if(_tcscmp(szText,_T("Z郑州"))==0)     return 48;
	if(_tcscmp(szText,_T("Z株洲"))==0)     return 50;
	else return ERROR;
}
                   
wstring IntToCity(int i){
	wstring s;
	if(i == 1)      s = _T("包头");  
	if(i == 2)      s = _T("宝鸡"); 
	if(i == 3)      s = _T("北京");
	if(i == 49)     s = _T("重庆");
	if(i == 46)     s = _T("长春");
	if(i == 4)      s = _T("成都");
	if(i == 47)     s = _T("长沙");
	if(i == 5)      s = _T("大连");
	if(i == 6)      s = _T("大庆");
	if(i == 7)      s = _T("大同");
	if(i == 8)      s = _T("东莞");
	if(i == 9)      s = _T("福州");
	if(i == 10)     s = _T("赣州");
	if(i == 11)     s = _T("广州");
	if(i == 12)     s = _T("贵阳");
	if(i == 13)     s = _T("哈尔滨");
	if(i == 14)     s = _T("海口");
	if(i == 15)     s = _T("杭州");
	if(i == 16)    s = _T("合肥");
	if(i == 17)     s = _T("衡水");
	if(i == 18)     s = _T("呼和浩特");
	if(i == 19)     s = _T("济南");
	if(i == 20)     s = _T("昆明");
	if(i == 21)     s = _T("拉萨");
	if(i == 22)     s = _T("兰州");
	if(i == 23)     s = _T("柳州");
	if(i == 24)     s = _T("洛阳");
	if(i == 25)     s = _T("南昌");
	if(i == 26)     s = _T("南京");            
	if(i == 27)     s = _T("南宁");
	if(i == 28)     s = _T("宁波");
	if(i == 29)     s = _T("青岛");
	if(i == 32)     s = _T("深圳");
	if(i == 33)     s = _T("沈阳");
	if(i == 34)     s = _T("石家庄");
	if(i == 35)     s = _T("苏州");
	if(i == 36)     s = _T("太原");
	if(i == 37)     s = _T("天津");
	if(i == 38)     s = _T("温州");
	if(i == 39)     s = _T("乌鲁木齐");
	if(i == 40)     s = _T("芜湖");
	if(i == 41)     s = _T("武汉");
	if(i == 42)     s = _T("西安");
	if(i == 43)     s = _T("西宁");
	if(i == 31)     s = _T("上海");
	if(i == 30 )    s = _T("厦门");
	if(i == 44)     s = _T("徐州");
	if(i == 45)     s = _T("银川");
	if(i == 48)     s = _T("郑州");
	if(i == 50)     s = _T("株洲");
	return s;
}




status InitCombolBox(HWND& hComBox){                               //将城市插入到下拉框中
	SendMessage(hComBox, CB_INSERTSTRING, 0,  (LPARAM)_T("B包头"));
	SendMessage(hComBox, CB_INSERTSTRING, 1,  (LPARAM)_T("B宝鸡"));
	SendMessage(hComBox, CB_INSERTSTRING, 2,  (LPARAM)_T("B北京"));
	SendMessage(hComBox, CB_INSERTSTRING, 3,  (LPARAM)_T("C重庆"));
	SendMessage(hComBox, CB_INSERTSTRING, 4,  (LPARAM)_T("C长春"));
	SendMessage(hComBox, CB_INSERTSTRING, 5,  (LPARAM)_T("C成都"));
	SendMessage(hComBox, CB_INSERTSTRING, 6,  (LPARAM)_T("C长沙"));
	SendMessage(hComBox, CB_INSERTSTRING, 7,  (LPARAM)_T("D大连"));
	SendMessage(hComBox, CB_INSERTSTRING, 8,  (LPARAM)_T("D大庆"));
	SendMessage(hComBox, CB_INSERTSTRING, 9,  (LPARAM)_T("D大同"));
	SendMessage(hComBox, CB_INSERTSTRING, 10, (LPARAM)_T("D东莞"));
	SendMessage(hComBox, CB_INSERTSTRING, 11, (LPARAM)_T("F福州"));
	SendMessage(hComBox, CB_INSERTSTRING, 12, (LPARAM)_T("G赣州"));
	SendMessage(hComBox, CB_INSERTSTRING, 13, (LPARAM)_T("G广州"));
	SendMessage(hComBox, CB_INSERTSTRING, 14, (LPARAM)_T("G贵阳"));
	SendMessage(hComBox, CB_INSERTSTRING, 15, (LPARAM)_T("H哈尔滨"));
	SendMessage(hComBox, CB_INSERTSTRING, 16, (LPARAM)_T("H海口"));
	SendMessage(hComBox, CB_INSERTSTRING, 17, (LPARAM)_T("H杭州"));
	SendMessage(hComBox, CB_INSERTSTRING, 18, (LPARAM)_T("H合肥"));
	SendMessage(hComBox, CB_INSERTSTRING, 19, (LPARAM)_T("H衡水"));
	SendMessage(hComBox, CB_INSERTSTRING, 20, (LPARAM)_T("H呼和浩特"));
	SendMessage(hComBox, CB_INSERTSTRING, 21, (LPARAM)_T("J济南"));
	SendMessage(hComBox, CB_INSERTSTRING, 22, (LPARAM)_T("K昆明"));
	SendMessage(hComBox, CB_INSERTSTRING, 23, (LPARAM)_T("L拉萨"));
	SendMessage(hComBox, CB_INSERTSTRING, 24, (LPARAM)_T("L兰州"));
	SendMessage(hComBox, CB_INSERTSTRING, 25, (LPARAM)_T("L柳州"));
	SendMessage(hComBox, CB_INSERTSTRING, 26, (LPARAM)_T("L洛阳"));
	SendMessage(hComBox, CB_INSERTSTRING, 27, (LPARAM)_T("N南昌"));
	SendMessage(hComBox, CB_INSERTSTRING, 28, (LPARAM)_T("N南京"));
	SendMessage(hComBox, CB_INSERTSTRING, 29, (LPARAM)_T("N南宁"));
	SendMessage(hComBox, CB_INSERTSTRING, 30, (LPARAM)_T("N宁波"));
	SendMessage(hComBox, CB_INSERTSTRING, 31, (LPARAM)_T("Q青岛"));
	SendMessage(hComBox, CB_INSERTSTRING, 32, (LPARAM)_T("S深圳"));
	SendMessage(hComBox, CB_INSERTSTRING, 33, (LPARAM)_T("S沈阳"));
	SendMessage(hComBox, CB_INSERTSTRING, 34, (LPARAM)_T("S石家庄"));
	SendMessage(hComBox, CB_INSERTSTRING, 35, (LPARAM)_T("S苏州"));
	SendMessage(hComBox, CB_INSERTSTRING, 36, (LPARAM)_T("T太原"));
	SendMessage(hComBox, CB_INSERTSTRING, 37, (LPARAM)_T("T天津"));
	SendMessage(hComBox, CB_INSERTSTRING, 38, (LPARAM)_T("W温州"));
	SendMessage(hComBox, CB_INSERTSTRING, 39, (LPARAM)_T("W乌鲁木齐"));
	SendMessage(hComBox, CB_INSERTSTRING, 40, (LPARAM)_T("W芜湖"));
	SendMessage(hComBox, CB_INSERTSTRING, 41, (LPARAM)_T("W武汉"));
	SendMessage(hComBox, CB_INSERTSTRING, 42, (LPARAM)_T("X西安"));
	SendMessage(hComBox, CB_INSERTSTRING, 43, (LPARAM)_T("X西宁"));
	SendMessage(hComBox, CB_INSERTSTRING, 44, (LPARAM)_T("X上海"));
	SendMessage(hComBox, CB_INSERTSTRING, 45, (LPARAM)_T("X厦门"));
	SendMessage(hComBox, CB_INSERTSTRING, 46, (LPARAM)_T("X徐州"));
	SendMessage(hComBox, CB_INSERTSTRING, 47, (LPARAM)_T("Y银川"));
	SendMessage(hComBox, CB_INSERTSTRING, 48, (LPARAM)_T("Z郑州"));
	SendMessage(hComBox, CB_INSERTSTRING, 49, (LPARAM)_T("Z株洲"));


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



wstring TimeToWString(const Time& time){                   //将时间类转为UTF-16格式 (wstring类)
	TCHAR str[Num]={0};
	wstring wstr;
	if(time.hour<10 && time.minute<10)        _stprintf(str, _T("  0%d:0%d  "), time.hour, time.minute);
	else if(time.hour>=10 && time.minute<10)  _stprintf(str, _T("  %d:0%d  "), time.hour, time.minute);
	else if(time.hour<10 && time.minute>=10)  _stprintf(str, _T("  0%d:%d  "), time.hour, time.minute);
	else if(time.hour>=10 && time.minute>=10) _stprintf(str, _T("  %d:%d  "), time.hour, time.minute);
	wstr = str;

	return wstr;
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

wstring GetFee_T(const Final& final,int i){                    //获取火车花费（两城市之间），并转成UTF-16格式 (wstring类)
	int c,f1,f2;
	TCHAR* str={0};
	for(c=1; final[i].ptll->path[c].station!=final[i].start && c<=Num; c++){}
	if(c == Num+1)  exit(0);
	f1 = final[i].ptll->path[c].fee;
	for(c=1; final[i].ptll->path[c].station!=final[i].arrive && c<=Num; c++){}
	if(c == Num+1)  exit(0);
	f2 = final[i].ptll->path[c].fee;
	f1 = f2-f1;
	_stprintf(str,_T("  %d  \n"),f1);
	wstring wstr = str;
	return  wstr;
}


wstring GetFee_P(const Final& final,int i,const PList& plist){                    //获取飞机花费，并转成UTF-16格式 (wstring类)
	TCHAR* str;
	_stprintf(str,_T("  %d  \n"),plist[final[i].ip].fee);
	wstring wstr = str;
	return  wstr;
}




status InitMessageBox(HWND hwndDlg,const Final& final,const Customer& customer,const PList& plist){
	int i;
	int    ctt;
	wstring       number, city1, city2, time1, time2, fee;
	wstring       wstr;
	const TCHAR* szText;
	ctt =(int) customer.trafictool;
	if(ctt == 1){
		szText = _T("火车班次    出发    到达    起始时间    到达时间    费用\n");
		for(i=0; final[i].number!="0"; i++){
			number = StringToWString(final[i].number);
			city1  = IntToCity(final[i].start);
			city2  = IntToCity(final[i].arrive);
			time1  = TimeToWString(GetStartime_T(final,i));
			time2  = TimeToWString(GetArrivetime_T(final,i));
			fee    = GetFee_T(final,i);
			//将整行信息装在一个串中
			wstr = szText+number+city1+city2+time1+time2+fee;
		}
	}
	else if(ctt == 0){
		szText = _T("航班号    出发    到达    起始时间    到达时间    费用\n");
		for(i=0; final[i].number!="0"; i++){
			number = StringToWString(final[i].number);
			city1  = IntToCity(final[i].start);
			city2  = IntToCity(final[i].arrive);
			time1  = TimeToWString(plist[final[i].ip].startime);
			time2  = TimeToWString(plist[final[i].ip].arrivetime);
			fee  = GetFee_P(final,i,plist);
			//将整行信息装在一个串中
			wstr   = szText+number+city1+city2+time1+time2+fee;
		}
	}
	//a(wstr,szText);
	//string s(wstr.begin(), wstr.end());
	//szText = wstr;
	
	//sscanf(szText, "%s", wstr);
	//WideCharToMultiByte(CP_ACP,0,wstr,-1, LPCSTR lpMultiByteStr, int cchMultiByte, LPCSTR lpDefaultChar, PBOOL pfUsedDefaultChar );
	//szText = wstr.c_str();
	//TCHAR t[1000];
	//WideCharToMultiByte(CP_ACP, WC_NO_BEST_FIT_CHARS, wstr.c_str(), -1, t, 1000, NULL, NULL); 
	const TCHAR *t = wstr.c_str();
	//szText = t;

	MessageBeep(0);
	MessageBox(hwndDlg, t, _T("咨询结果"), MB_OK);       //调用消息框打印输出结果
	return OK;
}






	//s = _T("abcd efgh 1234");
	//_stprintf_s(szText, MaxVnum, _T("城市数量为%d\n哈哈哈%s"), s);







/*
			B包头	1
			B宝鸡	2
			B北京	3
			C重庆	49
			C长春	46
			C成都	4
			C长沙	47
			D大连	5
			D大庆	6
			D大同	7
			D东莞	8
			F福州	9
			G赣州	10
			G广州	11
			G贵阳	12
			H哈尔滨	13
			H海口	14
			H杭州	15
			H合肥	16
			H衡水	17
			H呼和浩特	18
			J济南	19
			K昆明	20
			L拉萨	21
			L兰州	22
			L柳州	23
			L洛阳	24
			N南昌	25
			N南京	26
			N南宁	27
			N宁波	28
			Q青岛	29
			S深圳	32
			S沈阳	33
			S石家庄	34
			S苏州	35
			T太原	36
			T天津	37
			W温州	38
			W乌鲁木齐	39
			W芜湖	40
			W武汉	41
			X西安	42
			X西宁	43
			X上海	31
			X厦门	30
			X徐州	44
			Y银川	45
			Z郑州	48
			Z株洲	50


*/
