
// SaveInArrayDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "SaveInArray.h"
#include "SaveInArrayDlg.h"
#include "afxdialogex.h"
#include "afx.h"
#include "afxstr.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSaveInArrayDlg dialog



CSaveInArrayDlg::CSaveInArrayDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SAVEINARRAY_DIALOG, pParent)
	, m_EditControl1(_T(""))
	, m_EditControl2(_T(""))
	, m_EditControl3(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSaveInArrayDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_EditControl1);
	DDX_Text(pDX, IDC_EDIT2, m_EditControl2);
	DDX_Text(pDX, IDC_EDIT3, m_EditControl3);
}

BEGIN_MESSAGE_MAP(CSaveInArrayDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_FSVAE, &CSaveInArrayDlg::OnBnClickedFsvae)
END_MESSAGE_MAP()


// CSaveInArrayDlg message handlers

BOOL CSaveInArrayDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSaveInArrayDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSaveInArrayDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CSaveInArrayDlg::SaveEditValuesToArray()
{
	//m_EditValues.RemoveAll(); // Clear the array before adding values
	
	m_EditValues.Add(m_EditControl1);
	m_EditValues.Add(m_EditControl2);
	m_EditValues.Add(m_EditControl3);
	// Add each member variable to the array
	
}


void CSaveInArrayDlg::OnBnClickedFsvae()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	SaveEditValuesToArray();
	
	CString textToSave;
	CString y;
	
	CFileDialog fileDlg(FALSE, _T("txt"), _T("TextFile.txt"), OFN_OVERWRITEPROMPT, _T("Text Files (*.txt)|*.txt||"));

	if (fileDlg.DoModal() == IDOK)
	{
		CString filePath = fileDlg.GetPathName();

		CStdioFile file;
		if (file.Open(filePath, CFile::modeCreate | CFile::modeWrite | CFile::typeText))
		{
			str.Add(_T("Value 1"));
			str.Add(_T("Value 2")); 
			str.Add(_T("Value 3"));
			
			for (int i = 0; i < 3; i++) {
				textToSave = m_EditValues.GetAt(i);
				y = str.GetAt(i);
				file.WriteString(y);
				file.WriteString(_T(" : "));
				file.WriteString(textToSave);
				file.WriteString(_T("\n"));
			}
			file.Close();
		}
		else
		{
			// Failed to open the file, handle the error
		}
	}
	UpdateData(FALSE);
}
