
// UIS63Dlg.h : ��� ����
//

#pragma once

// CUIS63Dlg ��ȭ ����
class CUIS63Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	CUIS63Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_UIS63_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString strHWID;
	CString strMKey;
	CString strMId;

	char* HW_ID;
	char* M_KEY;
	char* M_ID;

	afx_msg void OnBnClickedButtonCreateUserpermit();
	afx_msg void OnDestroy();
};
