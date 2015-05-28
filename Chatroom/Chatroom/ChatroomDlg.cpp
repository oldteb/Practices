// ChatroomDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Chatroom.h"
#include "ChatroomDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CChatroomDlg 对话框




CChatroomDlg::CChatroomDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CChatroomDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_ListenSock = INVALID_SOCKET;

}

void CChatroomDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CChatroomDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &CChatroomDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_SETTINGS, &CChatroomDlg::OnBnClickedSettings)
	ON_BN_CLICKED(IDC_OPEN_BUTTON, &CChatroomDlg::OnBnClickedOpenButton)
END_MESSAGE_MAP()


// CChatroomDlg 消息处理程序

BOOL CChatroomDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	DlgAllInit();
	ExtendWindow(FALSE);


	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CChatroomDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CChatroomDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CChatroomDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CChatroomDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	OnOK();
}

void CChatroomDlg::DlgAllInit()
{
	EnableWindow(IDC_STOP_BUTTON1, FALSE);
	EnableWindow(IDC_STOP_BUTTON2, FALSE);
	EnableWindow(IDC_LISTEN_PORT,  FALSE);
	EnableWindow(IDC_STATIC_TEXT2, FALSE);

	CheckRadioButton(IDC_CLIENT_RADIO, IDC_SERVER_RADIO, IDC_CLIENT_RADIO);
	SetDlgItemText(IDC_IPADDRESS, _T("127.0.0.1"));
	SetDlgItemText(IDC_CONNECT_PORT, _T("7788"));
	SetDlgItemText(IDC_LISTEN_PORT, _T("7788"));
}

bool CChatroomDlg::EnableWindow(UINT uID, bool bEnable)
{
	 return GetDlgItem(uID)->EnableWindow(bEnable);

}
void CChatroomDlg::OnBnClickedSettings()
{
	// TODO: 在此添加控件通知处理程序代码
	ExtendWindow(bShowAll);


}


bool CChatroomDlg::ExtendWindow(bool bShow)
{
	static CRect rBigWindow(0,0,0,0);
	static CRect rSmallWindow(0,0,0,0);
	if(rBigWindow.IsRectNull())
	{
		GetWindowRect(&rBigWindow); 
		rSmallWindow = rBigWindow;
		int x = GetSystemMetrics(SM_CXSCREEN);
		x =(x*280)/1366;
		rSmallWindow.right -= x;
	}
	if(bShow)
	{
		SetWindowPos(NULL,0,0,rBigWindow.Width(),rBigWindow.Height(),SWP_NOZORDER|SWP_NOMOVE );
		bShowAll = FALSE;
	}
	else
	{	
		SetWindowPos(NULL,0,0,rSmallWindow.Width(),rSmallWindow.Height(),SWP_NOZORDER|SWP_NOMOVE );
		bShowAll = TRUE;
	}
	return TRUE;

}
void CChatroomDlg::OnBnClickedOpenButton()
{
	// TODO: 在此添加控件通知处理程序代码


	m_ListenSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if ( m_ListenSock == INVALID_SOCKET ) {
		AfxMessageBox(_T("新建SOCKET失败！"));
		return;
	}
	UINT uPort = GetDlgItemInt(IDC_LISTEN_PORT);
	if ( uPort <= 0 || uPort > 65535 ) {
		AfxMessageBox(_T("请输入合适的端口：1 - 65535"));
		goto __Error_End;
	}
	sockaddr_in service;
	service.sin_family = AF_INET;
	service.sin_addr.s_addr = INADDR_ANY;
	service.sin_port = htons(uPort);

	if ( bind(m_ListenSock, (sockaddr*)&service, sizeof(sockaddr_in)) == SOCKET_ERROR ) {
		AfxMessageBox(_T("绑定端口失败！"));
		goto __Error_End;
	}

	if( listen(m_ListenSock, 5) == SOCKET_ERROR ) {
		AfxMessageBox(_T("监听失败！"));
		goto __Error_End;
	}

	sockaddr_in clientAddr;
	int iLen = sizeof(sockaddr_in);
	SOCKET accSock = accept(m_ListenSock,(sockaddr*)&clientAddr ,&iLen);
	if (accSock == INVALID_SOCKET)
	{
		AfxMessageBox(_T("接受客户端失败！"));
		closesocket(m_ListenSock);
	}

	//做一些其他操作……

	__Error_End:
	closesocket(m_ListenSock);

}
