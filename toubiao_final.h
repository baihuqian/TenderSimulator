// toubiao_final.h : main header file for the TOUBIAO_FINAL application
//

#if !defined(AFX_TOUBIAO_FINAL_H__E7C54761_6A90_4542_AE9B_9E63C94589A2__INCLUDED_)
#define AFX_TOUBIAO_FINAL_H__E7C54761_6A90_4542_AE9B_9E63C94589A2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CToubiao_finalApp:
// See toubiao_final.cpp for the implementation of this class
//

class CToubiao_finalApp : public CWinApp
{
public:
	CToubiao_finalApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CToubiao_finalApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CToubiao_finalApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TOUBIAO_FINAL_H__E7C54761_6A90_4542_AE9B_9E63C94589A2__INCLUDED_)
