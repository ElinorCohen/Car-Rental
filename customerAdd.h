#pragma once


// customerAdd dialog

class customerAdd : public CDialogEx
{
	DECLARE_DYNAMIC(customerAdd)

public:
	customerAdd(CWnd* pParent = nullptr);   // standard constructor
	virtual ~customerAdd();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString newID;
	CString newName;
	COleDateTime newDate;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnMcnSelchangeMonthcalendar2(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnLbnSelchangeList1();
};
