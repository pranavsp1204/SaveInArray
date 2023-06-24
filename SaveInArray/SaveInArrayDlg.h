
// SaveInArrayDlg.h : header file
//

#pragma once
#include "afxstr.h"

// CSaveInArrayDlg dialog
class CSaveInArrayDlg : public CDialogEx
{
// Construction
public:
	CSaveInArrayDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SAVEINARRAY_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	
public:
	CStringArray m_EditValues;
	CStringArray str;
	CString m_EditControl1;
	CString m_EditControl2;
	CString m_EditControl3;
	afx_msg void OnBnClickedFsvae();
	afx_msg void SaveEditValuesToArray();
};
