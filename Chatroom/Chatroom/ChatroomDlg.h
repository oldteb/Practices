// ChatroomDlg.h : ͷ�ļ�
//

#pragma once


// CChatroomDlg �Ի���
class CChatroomDlg : public CDialog
{
// ����
public:
	CChatroomDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CHATROOM_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
