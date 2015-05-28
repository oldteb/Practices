#include<windows.h>
#include<stdio.h>
#include"DataStruct.h"
#include"FindPath.h"
#include"Output1.h"



using namespace std;


int      iCurrentTool      = IDC_RADIO4;
int      iCurrentStrategic = IDC_RADIO6;
//char  szAppName[] = "PopMenu";


INT_PTR CALLBACK DialogProc(HWND ,UINT ,WPARAM ,LPARAM );

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//HINSTANCE hInst = hInstance;
	DialogBox(hInstance,MAKEINTRESOURCE(IDD_MAIN_DIALOG),NULL,DialogProc);
	return 0;
}

INT_PTR CALLBACK DialogProc(HWND hwndDlg,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
	static int          iPlace1, iPlace2, iTool, iStrategy;
	static TRAFICTOOL	eTool;
	static STRATEGY     eStrategy;
	static HMENU        hMenu;

	Customer       customer;
	Graph          graph;
	PList          plist;
	TLinkList      tlinklist;
	Final          final;
	//CMenu menu;
	POINT    point;
	int      i;


	switch(uMsg)
	{
	case WM_CREATE:{
		    hMenu = CreatePopupMenu();
			//hMenu = LoadMenu((HINSTANCE)hwndDlg ,MAKEINTRESOURCE(IDR_MENU2));
			//hMenu = GetSubMenu(hMenu ,0);
			return 0;
	}
		

	case WM_INITDIALOG:{
		    //TCHAR str[Num]={0};

			HWND hComBox1 = GetDlgItem(hwndDlg,IDC_COMBO1);
			HWND hComBox2 = GetDlgItem(hwndDlg,IDC_COMBO2);
			//对下拉表插入信息，用for循环从文件中读入
			InitCombolBox(hComBox1);
			InitCombolBox(hComBox2);

            iTool      = iCurrentTool;
			iStrategy  = iCurrentStrategic;
			CheckRadioButton(hwndDlg, IDC_RADIO4, IDC_RADIO5, iTool);
			CheckRadioButton(hwndDlg, IDC_RADIO6, IDC_RADIO7, iStrategy);
			//_stprintf(str,_T("%d"),iTool);
			//MessageBox(hwndDlg,str, _T("测试"), MB_OK);

	}break;

	case WM_RBUTTONUP:{
			point.x = LOWORD(lParam);
			point.y = HIWORD(lParam);
			ClientToScreen(hwndDlg ,&point);
			TrackPopupMenu(hMenu ,TPM_RIGHTBUTTON ,point.x ,point.y ,0 ,hwndDlg ,NULL);
			return 0;
	}


	case WM_COMMAND:{

			TCHAR szText1[Num]         ={0};
			TCHAR szText2[Num]         ={0};
			GetDlgItemText(hwndDlg, IDC_COMBO1, szText1, Num);
			GetDlgItemText(hwndDlg, IDC_COMBO2, szText2, Num);

			ReadTrainInfo(tlinklist);
			ReadPlaneInfo(plist);
			InitGraph(graph,CityNum); 
			TrainToGraph(graph,tlinklist);
			PlaneToGraph(graph,plist);


			switch(wParam)
			{
			case IDOK:{
					i=0;
					iPlace1 = CityToInt(szText1);
					iPlace2 = CityToInt(szText2);
					char str[Num]={0};
				    char szText[1024]={0};
				    //打印咨询结果
					if(iPlace1 == ERROR || iPlace2 == ERROR){
						MessageBeep(0);
						i = MessageBox(hwndDlg,"没有找到该城市的城市信息！","提示",MB_OK)+1;
					}
					if(iPlace1 == iPlace2 && iPlace1 != ERROR && iPlace2 != ERROR){
						MessageBeep(0);
						i = MessageBox(hwndDlg,"出发与到达不能相同！","提示",MB_OK)+2;
					}
					if(i!=IDOK+1 && i!=IDOK+2){
						//初始化用户需求
						customer.startcity    = iPlace1;                 //初始化起始地
					    customer.destination  = iPlace2;				 //初始化目的地
						customer.trafictool   = eTool;                   //初始化交通工具
						customer.strategy     = eStrategy;               //初始化最优策略


						//sprintf(str,"%d",(int)eTool);
						//MessageBox(hwndDlg,str, "test", MB_OK);
				
						InitFinal(final);
						FindPath(graph,plist,tlinklist,final,customer);      //FindPath()函数找出最短路径并返回final数组


						InitMessageBox(hwndDlg, final, customer, plist,tlinklist);    //将咨询结果放入szText串中
						//MessageBeep(0);
						//MessageBox(hwndDlg, szText, "咨询结果", MB_OK);       //调用消息框打印输出结果
					}
		    }break;

			case IDCANCEL:{
                    MessageBeep(0);
				    int iRet = MessageBox(hwndDlg,"您是否要退出？","提示",MB_OKCANCEL);
				    if(iRet == IDOK)  EndDialog(hwndDlg,IDCANCEL);
			}break;

			case IDC_RADIO4:
			case IDC_RADIO5:  
                    eTool = (TRAFICTOOL)(LOWORD(wParam)-1007);
					//iToolTest = LOWORD(wParam);
					CheckRadioButton(hwndDlg, IDC_RADIO4, IDC_RADIO5, LOWORD(wParam));

					return TRUE ;
				

			case IDC_RADIO6:
			case IDC_RADIO7:
					eStrategy = (STRATEGY)(LOWORD(wParam)-1005);
					CheckRadioButton(hwndDlg, IDC_RADIO6, IDC_RADIO7, LOWORD(wParam));
					return TRUE ;
				
			default:  break;
			}
	    }break;
		default:  break;
	}
	return FALSE;
}
