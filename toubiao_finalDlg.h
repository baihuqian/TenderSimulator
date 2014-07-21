// toubiao_finalDlg.h : header file
//

#if !defined(AFX_TOUBIAO_FINALDLG_H__E216B4D2_501B_4694_91DD_42EDEF35BFE6__INCLUDED_)
#define AFX_TOUBIAO_FINALDLG_H__E216B4D2_501B_4694_91DD_42EDEF35BFE6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CToubiao_finalDlg dialog

class CToubiao_finalDlg : public CDialog
{
// Construction
public:
	CToubiao_finalDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CToubiao_finalDlg)
	enum { IDD = IDD_TOUBIAO_FINAL_DIALOG };
	CString	m_Choice_Num;
	CString	m_Up_Penalty;
	CString	m_Down_Penalty;
	CString	m_Lower_Bound;
	CString	m_Upper_Bound;
	CString	m_Step;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CToubiao_finalDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CToubiao_finalDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton_clicked();
	afx_msg void OnClose();
	afx_msg void OnButtonClearClicked();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TOUBIAO_FINALDLG_H__E216B4D2_501B_4694_91DD_42EDEF35BFE6__INCLUDED_)
