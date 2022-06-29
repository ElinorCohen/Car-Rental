#pragma once


// Inventory dialog

class Inventory : public CDialogEx
{
	DECLARE_DYNAMIC(Inventory)

public:
	Inventory(CWnd* pParent = nullptr);   // standard constructor
	virtual ~Inventory();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedRadio4();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnEnChangeEdit6();
	afx_msg void OnBnClickedDatetimepicker1();
	afx_msg void OnBnClickedRadio6();
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnBnClickedRadio5();
	afx_msg void OnBnClickedRadio7();
	afx_msg void OnBnClickedRadio8();
	afx_msg void OnBnClickedRadio9();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnLbnSelchangeList2();
	afx_msg void OnBnClickedRadio14();
	CString CarNumber;
	CString Company;
	int Speed;
	int carType;
	int carColor;
	int inStock;
	CString SCarNumber;

	BOOL SeatType;
	BOOL GearBox;
	BOOL CarSize;
	BOOL IsMetal;

	CListBox ListOfCarss;
};
