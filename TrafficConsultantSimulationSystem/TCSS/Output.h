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


int CityToInt(TCHAR* szText){                                  //ƥ����ж�Ӧ�ı��
	if(_tcscmp(szText,_T("B��ͷ"))==0)     return 1;
	if(_tcscmp(szText,_T("B����"))==0)     return 2;
	if(_tcscmp(szText,_T("B����"))==0)     return 3;
	if(_tcscmp(szText,_T("C����"))==0)     return 49;
	if(_tcscmp(szText,_T("C����"))==0)     return 46;
	if(_tcscmp(szText,_T("C�ɶ�"))==0)     return 4;
	if(_tcscmp(szText,_T("C��ɳ"))==0)     return 47;
	if(_tcscmp(szText,_T("D����"))==0)     return 5;
	if(_tcscmp(szText,_T("D����"))==0)     return 6;
	if(_tcscmp(szText,_T("D��ͬ"))==0)     return 7;
	if(_tcscmp(szText,_T("D��ݸ"))==0)     return 8;
	if(_tcscmp(szText,_T("F����"))==0)     return 9;
	if(_tcscmp(szText,_T("G����"))==0)     return 10;
	if(_tcscmp(szText,_T("G����"))==0)     return 11;
	if(_tcscmp(szText,_T("G����"))==0)     return 12;
	if(_tcscmp(szText,_T("H������"))==0)   return 13;
	if(_tcscmp(szText,_T("H����"))==0)     return 14;
	if(_tcscmp(szText,_T("H����"))==0)     return 15;
	if(_tcscmp(szText,_T("H�Ϸ�"))==0)     return 16;
	if(_tcscmp(szText,_T("H��ˮ"))==0)     return 17;
	if(_tcscmp(szText,_T("H���ͺ���"))==0) return 18;
	if(_tcscmp(szText,_T("J����"))==0)     return 19;
	if(_tcscmp(szText,_T("K����"))==0)     return 20;
	if(_tcscmp(szText,_T("L����"))==0)     return 21;
	if(_tcscmp(szText,_T("L����"))==0)     return 22;
	if(_tcscmp(szText,_T("L����"))==0)     return 23;
	if(_tcscmp(szText,_T("L����"))==0)     return 24;
	if(_tcscmp(szText,_T("N�ϲ�"))==0)     return 25;
	if(_tcscmp(szText,_T("N�Ͼ�"))==0)     return 26;
	if(_tcscmp(szText,_T("N����"))==0)     return 27;
	if(_tcscmp(szText,_T("N����"))==0)     return 28;
	if(_tcscmp(szText,_T("Q�ൺ"))==0)     return 29;
	if(_tcscmp(szText,_T("S����"))==0)     return 32;
	if(_tcscmp(szText,_T("S����"))==0)     return 33;
	if(_tcscmp(szText,_T("Sʯ��ׯ"))==0)   return 34;
	if(_tcscmp(szText,_T("S����"))==0)     return 35;
	if(_tcscmp(szText,_T("T̫ԭ"))==0)     return 36;
	if(_tcscmp(szText,_T("T���"))==0)     return 37;
	if(_tcscmp(szText,_T("W����"))==0)     return 38;
	if(_tcscmp(szText,_T("W��³ľ��"))==0) return 39;
	if(_tcscmp(szText,_T("W�ߺ�"))==0)     return 40;
	if(_tcscmp(szText,_T("W�人"))==0)     return 41;
	if(_tcscmp(szText,_T("X����"))==0)     return 42;
	if(_tcscmp(szText,_T("X����"))==0)     return 43;
	if(_tcscmp(szText,_T("X�Ϻ�"))==0)     return 31;
	if(_tcscmp(szText,_T("X����"))==0)     return 30;
	if(_tcscmp(szText,_T("X����"))==0)     return 44;
	if(_tcscmp(szText,_T("Y����"))==0)     return 45;
	if(_tcscmp(szText,_T("Z֣��"))==0)     return 48;
	if(_tcscmp(szText,_T("Z����"))==0)     return 50;
	else return ERROR;
}
                   
wstring IntToCity(int i){
	wstring s;
	if(i == 1)      s = _T("��ͷ");  
	if(i == 2)      s = _T("����"); 
	if(i == 3)      s = _T("����");
	if(i == 49)     s = _T("����");
	if(i == 46)     s = _T("����");
	if(i == 4)      s = _T("�ɶ�");
	if(i == 47)     s = _T("��ɳ");
	if(i == 5)      s = _T("����");
	if(i == 6)      s = _T("����");
	if(i == 7)      s = _T("��ͬ");
	if(i == 8)      s = _T("��ݸ");
	if(i == 9)      s = _T("����");
	if(i == 10)     s = _T("����");
	if(i == 11)     s = _T("����");
	if(i == 12)     s = _T("����");
	if(i == 13)     s = _T("������");
	if(i == 14)     s = _T("����");
	if(i == 15)     s = _T("����");
	if(i == 16)    s = _T("�Ϸ�");
	if(i == 17)     s = _T("��ˮ");
	if(i == 18)     s = _T("���ͺ���");
	if(i == 19)     s = _T("����");
	if(i == 20)     s = _T("����");
	if(i == 21)     s = _T("����");
	if(i == 22)     s = _T("����");
	if(i == 23)     s = _T("����");
	if(i == 24)     s = _T("����");
	if(i == 25)     s = _T("�ϲ�");
	if(i == 26)     s = _T("�Ͼ�");            
	if(i == 27)     s = _T("����");
	if(i == 28)     s = _T("����");
	if(i == 29)     s = _T("�ൺ");
	if(i == 32)     s = _T("����");
	if(i == 33)     s = _T("����");
	if(i == 34)     s = _T("ʯ��ׯ");
	if(i == 35)     s = _T("����");
	if(i == 36)     s = _T("̫ԭ");
	if(i == 37)     s = _T("���");
	if(i == 38)     s = _T("����");
	if(i == 39)     s = _T("��³ľ��");
	if(i == 40)     s = _T("�ߺ�");
	if(i == 41)     s = _T("�人");
	if(i == 42)     s = _T("����");
	if(i == 43)     s = _T("����");
	if(i == 31)     s = _T("�Ϻ�");
	if(i == 30 )    s = _T("����");
	if(i == 44)     s = _T("����");
	if(i == 45)     s = _T("����");
	if(i == 48)     s = _T("֣��");
	if(i == 50)     s = _T("����");
	return s;
}




status InitCombolBox(HWND& hComBox){                               //�����в��뵽��������
	SendMessage(hComBox, CB_INSERTSTRING, 0,  (LPARAM)_T("B��ͷ"));
	SendMessage(hComBox, CB_INSERTSTRING, 1,  (LPARAM)_T("B����"));
	SendMessage(hComBox, CB_INSERTSTRING, 2,  (LPARAM)_T("B����"));
	SendMessage(hComBox, CB_INSERTSTRING, 3,  (LPARAM)_T("C����"));
	SendMessage(hComBox, CB_INSERTSTRING, 4,  (LPARAM)_T("C����"));
	SendMessage(hComBox, CB_INSERTSTRING, 5,  (LPARAM)_T("C�ɶ�"));
	SendMessage(hComBox, CB_INSERTSTRING, 6,  (LPARAM)_T("C��ɳ"));
	SendMessage(hComBox, CB_INSERTSTRING, 7,  (LPARAM)_T("D����"));
	SendMessage(hComBox, CB_INSERTSTRING, 8,  (LPARAM)_T("D����"));
	SendMessage(hComBox, CB_INSERTSTRING, 9,  (LPARAM)_T("D��ͬ"));
	SendMessage(hComBox, CB_INSERTSTRING, 10, (LPARAM)_T("D��ݸ"));
	SendMessage(hComBox, CB_INSERTSTRING, 11, (LPARAM)_T("F����"));
	SendMessage(hComBox, CB_INSERTSTRING, 12, (LPARAM)_T("G����"));
	SendMessage(hComBox, CB_INSERTSTRING, 13, (LPARAM)_T("G����"));
	SendMessage(hComBox, CB_INSERTSTRING, 14, (LPARAM)_T("G����"));
	SendMessage(hComBox, CB_INSERTSTRING, 15, (LPARAM)_T("H������"));
	SendMessage(hComBox, CB_INSERTSTRING, 16, (LPARAM)_T("H����"));
	SendMessage(hComBox, CB_INSERTSTRING, 17, (LPARAM)_T("H����"));
	SendMessage(hComBox, CB_INSERTSTRING, 18, (LPARAM)_T("H�Ϸ�"));
	SendMessage(hComBox, CB_INSERTSTRING, 19, (LPARAM)_T("H��ˮ"));
	SendMessage(hComBox, CB_INSERTSTRING, 20, (LPARAM)_T("H���ͺ���"));
	SendMessage(hComBox, CB_INSERTSTRING, 21, (LPARAM)_T("J����"));
	SendMessage(hComBox, CB_INSERTSTRING, 22, (LPARAM)_T("K����"));
	SendMessage(hComBox, CB_INSERTSTRING, 23, (LPARAM)_T("L����"));
	SendMessage(hComBox, CB_INSERTSTRING, 24, (LPARAM)_T("L����"));
	SendMessage(hComBox, CB_INSERTSTRING, 25, (LPARAM)_T("L����"));
	SendMessage(hComBox, CB_INSERTSTRING, 26, (LPARAM)_T("L����"));
	SendMessage(hComBox, CB_INSERTSTRING, 27, (LPARAM)_T("N�ϲ�"));
	SendMessage(hComBox, CB_INSERTSTRING, 28, (LPARAM)_T("N�Ͼ�"));
	SendMessage(hComBox, CB_INSERTSTRING, 29, (LPARAM)_T("N����"));
	SendMessage(hComBox, CB_INSERTSTRING, 30, (LPARAM)_T("N����"));
	SendMessage(hComBox, CB_INSERTSTRING, 31, (LPARAM)_T("Q�ൺ"));
	SendMessage(hComBox, CB_INSERTSTRING, 32, (LPARAM)_T("S����"));
	SendMessage(hComBox, CB_INSERTSTRING, 33, (LPARAM)_T("S����"));
	SendMessage(hComBox, CB_INSERTSTRING, 34, (LPARAM)_T("Sʯ��ׯ"));
	SendMessage(hComBox, CB_INSERTSTRING, 35, (LPARAM)_T("S����"));
	SendMessage(hComBox, CB_INSERTSTRING, 36, (LPARAM)_T("T̫ԭ"));
	SendMessage(hComBox, CB_INSERTSTRING, 37, (LPARAM)_T("T���"));
	SendMessage(hComBox, CB_INSERTSTRING, 38, (LPARAM)_T("W����"));
	SendMessage(hComBox, CB_INSERTSTRING, 39, (LPARAM)_T("W��³ľ��"));
	SendMessage(hComBox, CB_INSERTSTRING, 40, (LPARAM)_T("W�ߺ�"));
	SendMessage(hComBox, CB_INSERTSTRING, 41, (LPARAM)_T("W�人"));
	SendMessage(hComBox, CB_INSERTSTRING, 42, (LPARAM)_T("X����"));
	SendMessage(hComBox, CB_INSERTSTRING, 43, (LPARAM)_T("X����"));
	SendMessage(hComBox, CB_INSERTSTRING, 44, (LPARAM)_T("X�Ϻ�"));
	SendMessage(hComBox, CB_INSERTSTRING, 45, (LPARAM)_T("X����"));
	SendMessage(hComBox, CB_INSERTSTRING, 46, (LPARAM)_T("X����"));
	SendMessage(hComBox, CB_INSERTSTRING, 47, (LPARAM)_T("Y����"));
	SendMessage(hComBox, CB_INSERTSTRING, 48, (LPARAM)_T("Z֣��"));
	SendMessage(hComBox, CB_INSERTSTRING, 49, (LPARAM)_T("Z����"));


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



wstring TimeToWString(const Time& time){                   //��ʱ����תΪUTF-16��ʽ (wstring��)
	TCHAR str[Num]={0};
	wstring wstr;
	if(time.hour<10 && time.minute<10)        _stprintf(str, _T("  0%d:0%d  "), time.hour, time.minute);
	else if(time.hour>=10 && time.minute<10)  _stprintf(str, _T("  %d:0%d  "), time.hour, time.minute);
	else if(time.hour<10 && time.minute>=10)  _stprintf(str, _T("  0%d:%d  "), time.hour, time.minute);
	else if(time.hour>=10 && time.minute>=10) _stprintf(str, _T("  %d:%d  "), time.hour, time.minute);
	wstr = str;

	return wstr;
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

wstring GetFee_T(const Final& final,int i){                    //��ȡ�𳵻��ѣ�������֮�䣩����ת��UTF-16��ʽ (wstring��)
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


wstring GetFee_P(const Final& final,int i,const PList& plist){                    //��ȡ�ɻ����ѣ���ת��UTF-16��ʽ (wstring��)
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
		szText = _T("�𳵰��    ����    ����    ��ʼʱ��    ����ʱ��    ����\n");
		for(i=0; final[i].number!="0"; i++){
			number = StringToWString(final[i].number);
			city1  = IntToCity(final[i].start);
			city2  = IntToCity(final[i].arrive);
			time1  = TimeToWString(GetStartime_T(final,i));
			time2  = TimeToWString(GetArrivetime_T(final,i));
			fee    = GetFee_T(final,i);
			//��������Ϣװ��һ������
			wstr = szText+number+city1+city2+time1+time2+fee;
		}
	}
	else if(ctt == 0){
		szText = _T("�����    ����    ����    ��ʼʱ��    ����ʱ��    ����\n");
		for(i=0; final[i].number!="0"; i++){
			number = StringToWString(final[i].number);
			city1  = IntToCity(final[i].start);
			city2  = IntToCity(final[i].arrive);
			time1  = TimeToWString(plist[final[i].ip].startime);
			time2  = TimeToWString(plist[final[i].ip].arrivetime);
			fee  = GetFee_P(final,i,plist);
			//��������Ϣװ��һ������
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
	MessageBox(hwndDlg, t, _T("��ѯ���"), MB_OK);       //������Ϣ���ӡ������
	return OK;
}






	//s = _T("abcd efgh 1234");
	//_stprintf_s(szText, MaxVnum, _T("��������Ϊ%d\n������%s"), s);







/*
			B��ͷ	1
			B����	2
			B����	3
			C����	49
			C����	46
			C�ɶ�	4
			C��ɳ	47
			D����	5
			D����	6
			D��ͬ	7
			D��ݸ	8
			F����	9
			G����	10
			G����	11
			G����	12
			H������	13
			H����	14
			H����	15
			H�Ϸ�	16
			H��ˮ	17
			H���ͺ���	18
			J����	19
			K����	20
			L����	21
			L����	22
			L����	23
			L����	24
			N�ϲ�	25
			N�Ͼ�	26
			N����	27
			N����	28
			Q�ൺ	29
			S����	32
			S����	33
			Sʯ��ׯ	34
			S����	35
			T̫ԭ	36
			T���	37
			W����	38
			W��³ľ��	39
			W�ߺ�	40
			W�人	41
			X����	42
			X����	43
			X�Ϻ�	31
			X����	30
			X����	44
			Y����	45
			Z֣��	48
			Z����	50


*/
