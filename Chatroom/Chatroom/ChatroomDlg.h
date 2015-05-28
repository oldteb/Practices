// ChatroomDlg.h : 头文件
//

#pragma once


// CChatroomDlg 对话框
class CChatroomDlg : public CDialog
{
// 构造
public:
	CChatroomDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CHATROOM_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	void DlgAllInit();
	bool EnableWindow(UINT uID, bool bEnable=TRUE);
	bool ExtendWindow(bool bShow);
	bool bShowAll;
	SOCKET m_ListenSock;



	afx_msg void OnBnClickedSettings();
	afx_msg void OnBnClickedOpenButton();
};
