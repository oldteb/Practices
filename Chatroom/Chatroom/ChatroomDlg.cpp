// ChatroomDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Chatroom.h"
#include "ChatroomDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CChatroomDlg �Ի���




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


// CChatroomDlg ��Ϣ�������

BOOL CChatroomDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	DlgAllInit();
	ExtendWindow(FALSE);


	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CChatroomDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CChatroomDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CChatroomDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������


	m_ListenSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if ( m_ListenSock == INVALID_SOCKET ) {
		AfxMessageBox(_T("�½�SOCKETʧ�ܣ�"));
		return;
	}
	UINT uPort = GetDlgItemInt(IDC_LISTEN_PORT);
	if ( uPort <= 0 || uPort > 65535 ) {
		AfxMessageBox(_T("��������ʵĶ˿ڣ�1 - 65535"));
		goto __Error_End;
	}
	sockaddr_in service;
	service.sin_family = AF_INET;
	service.sin_addr.s_addr = INADDR_ANY;
	service.sin_port = htons(uPort);

	if ( bind(m_ListenSock, (sockaddr*)&service, sizeof(sockaddr_in)) == SOCKET_ERROR ) {
		AfxMessageBox(_T("�󶨶˿�ʧ�ܣ�"));
		goto __Error_End;
	}

	if( listen(m_ListenSock, 5) == SOCKET_ERROR ) {
		AfxMessageBox(_T("����ʧ�ܣ�"));
		goto __Error_End;
	}

	sockaddr_in clientAddr;
	int iLen = sizeof(sockaddr_in);
	SOCKET accSock = accept(m_ListenSock,(sockaddr*)&clientAddr ,&iLen);
	if (accSock == INVALID_SOCKET)
	{
		AfxMessageBox(_T("���ܿͻ���ʧ�ܣ�"));
		closesocket(m_ListenSock);
	}

	//��һЩ������������

	__Error_End:
	closesocket(m_ListenSock);

}
