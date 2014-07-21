// toubiao_finalDlg.cpp : implementation file
//

#include "stdafx.h"
#include "toubiao_final.h"
#include "toubiao_finalDlg.h"
#include <vector>
#include "Helper_Function.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CToubiao_finalDlg dialog

CToubiao_finalDlg::CToubiao_finalDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CToubiao_finalDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CToubiao_finalDlg)
	m_Choice_Num = _T("");
	m_Up_Penalty = _T("");
	m_Down_Penalty = _T("");
	m_Lower_Bound = _T("");
	m_Upper_Bound = _T("");
	m_Step = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CToubiao_finalDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CToubiao_finalDlg)
	DDX_Text(pDX, IDC_EDIT1, m_Choice_Num);
	DDX_Text(pDX, IDC_EDIT2, m_Up_Penalty);
	DDX_Text(pDX, IDC_EDIT3, m_Down_Penalty);
	DDX_Text(pDX, IDC_EDIT4, m_Lower_Bound);
	DDX_Text(pDX, IDC_EDIT5, m_Upper_Bound);
	DDX_Text(pDX, IDC_EDIT6, m_Step);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CToubiao_finalDlg, CDialog)
	//{{AFX_MSG_MAP(CToubiao_finalDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, OnButton_clicked)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON3, OnButtonClearClicked)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CToubiao_finalDlg message handlers

 

BOOL CToubiao_finalDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	m_Choice_Num.Format("%d", 3);
	GetDlgItem(IDC_EDIT1)->SetWindowText(m_Choice_Num);

	m_Up_Penalty.Format("%d", 3);
	GetDlgItem(IDC_EDIT2)->SetWindowText(m_Up_Penalty);

	m_Down_Penalty.Format("%d", 2);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_Down_Penalty);

	m_Lower_Bound.Format("%d", 98);
	GetDlgItem(IDC_EDIT4)->SetWindowText(m_Lower_Bound);

	m_Upper_Bound.Format("%d", 100);
	GetDlgItem(IDC_EDIT5)->SetWindowText(m_Upper_Bound);

	m_Step.Format("%.1lf", 0.2);
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_Step);

	GetDlgItem(IDC_EDIT7)->SetFocus();

	return FALSE;  // return TRUE  unless you set the focus to a control
}

void CToubiao_finalDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CToubiao_finalDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

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
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CToubiao_finalDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}



void CToubiao_finalDlg::OnButton_clicked() 
{
	GetDlgItem(IDC_STATIC_STATUS)->SetWindowText("计算中，请稍等！");
	// TODO: Add your control notification handler code here
	//CEdit* pBoxOne;
	CString str;
	// choice number
	GetDlgItem(IDC_EDIT1)->GetWindowText(str);
	int choice_Num = atof(str);

	// up penalty
	GetDlgItem(IDC_EDIT2)->GetWindowText(str);
	double up_Penalty = atof(str);

	// down penalty
	GetDlgItem(IDC_EDIT3)->GetWindowText(str);
	double down_Penalty = atof(str);

	// lower bound of variance
	GetDlgItem(IDC_EDIT4)->GetWindowText(str);
	double lower_Bound = atof(str);

	// higher bound of variance
	GetDlgItem(IDC_EDIT5)->GetWindowText(str);
	double higher_Bound = atof(str);

	// step of variance
	GetDlgItem(IDC_EDIT6)->GetWindowText(str);
	double step = atof(str);

	double variance_Num = (higher_Bound - lower_Bound) / step + 1;
	int variance_num = int(variance_Num);
	CString Warning_Message = "";
	if (double(variance_num) != variance_Num)
	{
		//warning
		str.Format("合理浮动率上下限和间隔不匹配，请检查！");
		Warning_Message += str + _T("\r\n");
	}
	
	// get input
	GetDlgItem(IDC_EDIT7)->GetWindowText(str);

	str.Replace(" ", _T("\r\n"));
	TCHAR sep_token[] = _T("\r\n");
	std::vector<double> input_item;
	// seperate input into items
	TCHAR* token_temp = _tcstok((LPTSTR)(LPCTSTR)str, sep_token);
	while(token_temp != NULL) 
	{
		input_item.push_back(_ttol(token_temp));
		token_temp = _tcstok(NULL, sep_token); 
	}
	int item = input_item.size();

	//input check
	//check input size
	if (item == 0)
	{
		//warning
		str.Format("请输入投标金额，以回车分隔！");
		Warning_Message += str + _T("\r\n");
	}
	//check choice number
	if(choice_Num < 3 || choice_Num > 8)
	{
		str.Format("抽签人数须在3至8之间！");
		Warning_Message += str + _T("\r\n");
	}
	//check if input number is greater than choice number
	else if (item < choice_Num && item > 0)
	{
		str.Format("投标数必须不小于抽签人数！");
		Warning_Message += str + _T("\r\n");
	}
	//if any warning, print it and stop calculation
	if (Warning_Message != "")
	{
		MessageBox(Warning_Message);
		GetDlgItem(IDC_STATIC_STATUS)->SetWindowText("");
		return;
	}
	else
	{

	double *input = new double[item];
	int *win_time = new int[item];
	double win_rate;

	int i;

	for(i = 0; i < item; i++)
	{
		input[i] = input_item[i];
		win_time[i] = 0;
	}

	int draw_num = cnm(item, choice_Num);


	switch(choice_Num)
	{
	case 3:
		{
			int i1, i2, i3;
			double choice[3];
			for( i1 = 0; i1 < item - 2; i1++)
			{
				choice[0] = input[i1];
				for( i2 = i1 + 1; i2 < item - 1; i2++)
				{
					choice[1] = input[i2];
					for( i3 = i2 + 1; i3 < item; i3++)
					{
						choice[2] = input[i3];
						Add_Win_time(choice, win_time, choice_Num, variance_num, lower_Bound, step, input, item, up_Penalty, down_Penalty);
						/*double average = (input[i1] + input[i2] + input[i3]) / choice_Num;
						for(j = 0; j < variance_num; j++)
						{
							double base = (lower_Bound + j * step) / 100 * average;
							int winner = Find_Winner(input, item, base, up_Penalty, down_Penalty);
							win_time[winner]++;
						}
						*/
					}
				}
			}
			break;
		}
	case 4:
		{
			int i1, i2, i3, i4;
			double choice[4];
			for( i1 = 0; i1 < item - 3; i1++)
			{
				choice[0] = input[i1];
				for( i2 = i1 + 1; i2 < item - 2; i2++)
				{
					choice[1] = input[i2];
					for( i3 = i2 + 1; i3 < item - 1; i3++)
					{
						choice[2] = input[i3];
						for( i4 = i3 + 1; i4 < item; i4++)
						{
							choice[3] = input[i4];
							Add_Win_time(choice, win_time, choice_Num, variance_num, lower_Bound, step, input, item, up_Penalty, down_Penalty);
						}
					}
				}
			}
			break;
		}
	case 5:
		{
			int i1, i2, i3, i4, i5;
			double choice[5];
			for( i1 = 0; i1 < item - 4; i1++)
			{
				choice[0] = input[i1];
				for( i2 = i1 + 1; i2 < item - 3; i2++)
				{
					choice[1] = input[i2];
					for( i3 = i2 + 1; i3 < item - 2; i3++)
					{
						choice[2] = input[i3];
						for( i4 = i3 + 1; i4 < item - 1; i4++)
						{
							choice[3] = input[i4];
							for(i5 = i4 + 1; i5 < item; i5++)
							{
								choice[4] = input[i5];
								Add_Win_time(choice, win_time, choice_Num, variance_num, lower_Bound, step, input, item, up_Penalty, down_Penalty);
							}
						}
					}
				}
			}
			break;
		}
	case 6:
		{
			int i1, i2, i3, i4, i5, i6;
			double choice[6];
			for( i1 = 0; i1 < item - 5; i1++)
			{
				choice[0] = input[i1];
				for( i2 = i1 + 1; i2 < item - 4; i2++)
				{
					choice[1] = input[i2];
					for( i3 = i2 + 1; i3 < item - 3; i3++)
					{
						choice[2] = input[i3];
						for( i4 = i3 + 1; i4 < item - 2; i4++)
						{
							choice[3] = input[i4];
							for(i5 = i4 + 1; i5 < item - 1; i5++)
							{
								choice[4] = input[i5];
								for(i6 = i5 + 1; i6 < item; i6++)
								{
									choice[5] = input[i6];
									Add_Win_time(choice, win_time, choice_Num, variance_num, lower_Bound, step, input, item, up_Penalty, down_Penalty);
								}
							}
						}
					}
				}
			}
			break;
		}
	case 7:
		{
			int i1, i2, i3, i4, i5, i6, i7;
			double choice[7];
			for( i1 = 0; i1 < item - 6; i1++)
			{
				choice[0] = input[i1];
				for( i2 = i1 + 1; i2 < item - 5; i2++)
				{
					choice[1] = input[i2];
					for( i3 = i2 + 1; i3 < item - 4; i3++)
					{
						choice[2] = input[i3];
						for( i4 = i3 + 1; i4 < item - 3; i4++)
						{
							choice[3] = input[i4];
							for(i5 = i4 + 1; i5 < item - 2; i5++)
							{
								choice[4] = input[i5];
								for(i6 = i5 + 1; i6 < item - 1; i6++)
								{
									choice[5] = input[i6];
									for(i7 = i6 + 1; i7 < item; i7++)
									{
										choice[6] = input[i7];
										Add_Win_time(choice, win_time, choice_Num, variance_num, lower_Bound, step, input, item, up_Penalty, down_Penalty);
									}
								}
							}
						}
					}
				}
			}
			break;
		}
	case 8:
		{
			int i1, i2, i3, i4, i5, i6, i7, i8;
			double choice[8];
			for( i1 = 0; i1 < item - 7; i1++)
			{
				choice[0] = input[i1];
				for( i2 = i1 + 1; i2 < item - 6; i2++)
				{
					choice[1] = input[i2];
					for( i3 = i2 + 1; i3 < item - 5; i3++)
					{
						choice[2] = input[i3];
						for( i4 = i3 + 1; i4 < item - 4; i4++)
						{
							choice[3] = input[i4];
							for(i5 = i4 + 1; i5 < item - 3; i5++)
							{
								choice[4] = input[i5];
								for(i6 = i5 + 1; i6 < item - 2; i6++)
								{
									choice[5] = input[i6];
									for(i7 = i6 + 1; i7 < item - 1; i7++)
									{
										choice[6] = input[i7];
										for(i8 = i7 + 1; i8 < item; i8++)
										{
											choice[7] = input[i8];
											Add_Win_time(choice, win_time, choice_Num, variance_num, lower_Bound, step, input, item, up_Penalty, down_Penalty);
										}
									}
								}
							}
						}
					}
				}
			}
			break;
		}
	default:
		{
		}
	}
	
	//delete [] average;

	CString out = "";
	//CString out = "";

	for(i = 0; i < item; i++)
	{
		//win_rate[i] = (double)win_time[i] / (double)(draw_num * variance_num);
		win_rate = (double)win_time[i] / (double)(draw_num * variance_num);
		str.Format(_T("%.3f"), input[i]);
		out += str + _T(": ");
		//out_input += ;
		//str.Format("%.2lf", win_rate[i] * 100);
		str.Format(_T("%6.2f"), win_rate * 100);//3 digit+decimal dot+2 digit = 6 digit
		out += str + _T("%\r\n");
		//out_result += ;
	}

	GetDlgItem(IDC_EDIT8)->SetWindowText(out);
	

	//pBoxOne = (CEdit*) GetDlgItem(IDC_EDIT9);
	//pBoxOne->SetWindowText(out_result);
	
	delete [] input;
	delete [] win_time;
	//delete [] average;
	}
	GetDlgItem(IDC_STATIC_STATUS)->SetWindowText("");
}


void CToubiao_finalDlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	if(AfxMessageBox("你真的想退出吗？",MB_YESNO)==IDYES)
	{
		CDialog::OnClose();
	}
	//CDialog::OnClose();
}

BOOL CToubiao_finalDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_ESCAPE)
		return TRUE;

	return CDialog::PreTranslateMessage(pMsg);
}

void CToubiao_finalDlg::OnButtonClearClicked() 
{
	// TODO: Add your control notification handler code here
	//CEdit* pBoxOne;
	CString str;
	
	GetDlgItem(IDC_EDIT7)->GetWindowText(str);

	if(str == "")
	{
		GetDlgItem(IDC_EDIT8)->SetWindowText(str);
	}
	else
	{
		str = "";
		GetDlgItem(IDC_EDIT7)->SetWindowText(str);
	}
}
