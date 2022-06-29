// Inventory.cpp : implementation file
//

#include "pch.h"
#include "MFCApplication5.h"
#include "Inventory.h"
#include "afxdialogex.h"
#include "dataStoring.h"
#include "Sport.h"
#include "Regular.h"
#include "Comfort.h"
#include "Luxury.h"

CStatic* ImageHolder;
// Inventory dialog

IMPLEMENT_DYNAMIC(Inventory, CDialogEx)

int CarLoc;

Inventory::Inventory(CWnd* pParent)
	: CDialogEx(IDD_DIALOG2, pParent)
	, CarNumber(_T(""))
	, Company(_T(""))
	, carType(0)
	, Speed(0)
	, carColor(0)
	, inStock(0)
	, SCarNumber(_T(""))
	, SeatType(FALSE)
	, GearBox(FALSE)
	, CarSize(FALSE)
	, IsMetal(FALSE)
{

}

Inventory::~Inventory()
{
}

void Inventory::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, SCarNumber);
	DDX_Text(pDX, IDC_EDIT4, CarNumber);
	DDX_Text(pDX, IDC_EDIT3, Company);
	DDX_Radio(pDX, IDC_RADIO1, carType);
	DDX_Text(pDX, IDC_EDIT2, Speed);
	DDX_Radio(pDX, IDC_RADIO5, carColor);
	DDX_Control(pDX, IDC_LIST2, ListOfCarss);
	DDX_Radio(pDX, IDC_RADIO14, SeatType);
	DDX_Radio(pDX, IDC_RADIO20, GearBox);
	DDX_Radio(pDX, IDC_RADIO17, CarSize);
	DDX_Radio(pDX, IDC_RADIO12, IsMetal);
	GetDlgItem(IDC_RADIO1)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO2)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO3)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO4)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO5)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO6)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO7)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO8)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO9)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO12)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO13)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO14)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO15)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO16)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO17)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO18)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO19)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO20)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO21)->EnableWindow(FALSE);
	ImageHolder = (CStatic*)GetDlgItem(IDC_LUXURY);
	CString str;
	str = CString(_T("rolls-royce.bmp"));
	HBITMAP pic1 = (HBITMAP)LoadImage(NULL, str, IMAGE_BITMAP, 124, 89, LR_LOADFROMFILE);
	ImageHolder->SetBitmap(pic1);

	ListOfCarss.ResetContent();
	int i = 0;
	while (i < dataStoring::CarList.size())
	{
		ListOfCarss.AddString(dataStoring::CarList[i]->getNumber() + _T("   ") + dataStoring::CarList[i]->getCompany() + _T("   ") + dataStoring::CarList[i]->getColorName());
		i++;

	}
}


BEGIN_MESSAGE_MAP(Inventory, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &Inventory::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON2, &Inventory::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_RADIO1, &Inventory::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &Inventory::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &Inventory::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO4, &Inventory::OnBnClickedRadio4)
	ON_BN_CLICKED(IDC_BUTTON3, &Inventory::OnBnClickedButton3)
	ON_EN_CHANGE(IDC_EDIT6, &Inventory::OnEnChangeEdit6)
	ON_BN_CLICKED(IDC_DATETIMEPICKER1, &Inventory::OnBnClickedDatetimepicker1)
	ON_BN_CLICKED(IDC_RADIO6, &Inventory::OnBnClickedRadio6)
	ON_EN_CHANGE(IDC_EDIT4, &Inventory::OnEnChangeEdit4)
	ON_BN_CLICKED(IDC_RADIO5, &Inventory::OnBnClickedRadio5)
	ON_BN_CLICKED(IDC_RADIO7, &Inventory::OnBnClickedRadio7)
	ON_BN_CLICKED(IDC_RADIO8, &Inventory::OnBnClickedRadio8)
	ON_BN_CLICKED(IDC_RADIO9, &Inventory::OnBnClickedRadio9)
	ON_BN_CLICKED(IDC_BUTTON1, &Inventory::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT3, &Inventory::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT2, &Inventory::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON4, &Inventory::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_RADIO14, &Inventory::OnBnClickedRadio14)
	ON_LBN_SELCHANGE(IDC_LIST2, &Inventory::OnLbnSelchangeList2)
	ON_BN_CLICKED(IDC_RADIO14, &Inventory::OnBnClickedRadio14)
END_MESSAGE_MAP()


// Inventory message handlers


void Inventory::OnEnChangeEdit1()
{

}


void Inventory::OnBnClickedButton2()
{
	UpdateData(true);

	int loc = -1;
	for (int i = 0; i < dataStoring::CarList.size(); i++)
	{
		CarNumber = SCarNumber;
		if (dataStoring::CarList[i]->getNumber() == CarNumber) {

			GetDlgItem(IDC_EDIT1)->EnableWindow(TRUE);
			GetDlgItem(IDC_EDIT2)->EnableWindow(FALSE);
			GetDlgItem(IDC_EDIT3)->EnableWindow(FALSE);
			GetDlgItem(IDC_RADIO1)->EnableWindow(FALSE);
			GetDlgItem(IDC_RADIO2)->EnableWindow(FALSE);
			GetDlgItem(IDC_RADIO3)->EnableWindow(FALSE);
			GetDlgItem(IDC_RADIO4)->EnableWindow(FALSE);
			GetDlgItem(IDC_RADIO5)->EnableWindow(FALSE);
			GetDlgItem(IDC_RADIO6)->EnableWindow(FALSE);
			GetDlgItem(IDC_RADIO7)->EnableWindow(FALSE);
			GetDlgItem(IDC_RADIO8)->EnableWindow(FALSE);
			GetDlgItem(IDC_RADIO9)->EnableWindow(FALSE);
			GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
			GetDlgItem(IDC_BUTTON2)->EnableWindow(TRUE);
			GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);

			CarLoc = loc = i;
			inStock = dataStoring::CarList[i]->getQuantity();
			CarNumber = dataStoring::CarList[i]->getNumber();
			Company = dataStoring::CarList[i]->getCompany();
			Speed = dataStoring::CarList[i]->getTopSpeed();
			carType = dataStoring::CarList[i]->type;
			UpdateData(false);
			break;
		}
	}
	if (loc == -1) {
		if (MessageBox(L"Car not found, Add car?", L"Error", MB_YESNO | MB_ICONQUESTION) == IDYES) {
			CarNumber=SCarNumber;
			Company = "";
			carType = 0;
			Speed = 0;
			carColor = 0;
			inStock = 0;
			UpdateData(false);
			UpdateWindow();
			GetDlgItem(IDC_EDIT1)->EnableWindow(FALSE);
			GetDlgItem(IDC_EDIT2)->EnableWindow(FALSE);
			GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);
			GetDlgItem(IDC_EDIT3)->EnableWindow(TRUE);
			GetDlgItem(IDC_RADIO1)->EnableWindow(TRUE);
			GetDlgItem(IDC_RADIO2)->EnableWindow(TRUE);
			GetDlgItem(IDC_RADIO3)->EnableWindow(TRUE);
			GetDlgItem(IDC_RADIO4)->EnableWindow(TRUE);
			GetDlgItem(IDC_RADIO5)->EnableWindow(TRUE);
			GetDlgItem(IDC_RADIO6)->EnableWindow(TRUE);
			GetDlgItem(IDC_RADIO7)->EnableWindow(TRUE);
			GetDlgItem(IDC_RADIO8)->EnableWindow(TRUE);
			GetDlgItem(IDC_RADIO9)->EnableWindow(TRUE);
			GetDlgItem(IDC_RADIO12)->EnableWindow(TRUE);
			GetDlgItem(IDC_RADIO13)->EnableWindow(TRUE);
			GetDlgItem(IDC_RADIO14)->EnableWindow(TRUE);
			GetDlgItem(IDC_RADIO15)->EnableWindow(TRUE);
			GetDlgItem(IDC_RADIO16)->EnableWindow(TRUE);
			GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);
			GetDlgItem(IDC_BUTTON3)->EnableWindow(TRUE);

		}
		else
		{
			return;
		}
	}


}


void Inventory::OnBnClickedRadio1()
{
	GetDlgItem(IDC_RADIO12)->EnableWindow(TRUE);
	GetDlgItem(IDC_RADIO13)->EnableWindow(TRUE);
	GetDlgItem(IDC_RADIO14)->EnableWindow(TRUE);
	GetDlgItem(IDC_RADIO15)->EnableWindow(TRUE);
	GetDlgItem(IDC_RADIO16)->EnableWindow(TRUE);
	GetDlgItem(IDC_RADIO17)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO18)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO19)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO20)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO21)->EnableWindow(FALSE);
	ImageHolder = (CStatic*)GetDlgItem(IDC_LUXURY);
	CString str;
	str = CString(_T("rolls-royce.bmp"));
	HBITMAP pic1 = (HBITMAP)LoadImage(NULL, str, IMAGE_BITMAP, 124, 89, LR_LOADFROMFILE);
	ImageHolder->SetBitmap(pic1);
}


void Inventory::OnBnClickedRadio2()
{
	GetDlgItem(IDC_RADIO12)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO13)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO14)->EnableWindow(TRUE);
	GetDlgItem(IDC_RADIO15)->EnableWindow(TRUE);
	GetDlgItem(IDC_RADIO16)->EnableWindow(TRUE);
	GetDlgItem(IDC_RADIO17)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO18)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO19)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO20)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO21)->EnableWindow(FALSE);
	ImageHolder = (CStatic*)GetDlgItem(IDC_LUXURY);
	CString str;
	str = CString(_T("sport.bmp"));
	HBITMAP pic1 = (HBITMAP)LoadImage(NULL, str, IMAGE_BITMAP, 124, 89, LR_LOADFROMFILE);
	ImageHolder->SetBitmap(pic1);
}


void Inventory::OnBnClickedRadio3()
{
	GetDlgItem(IDC_RADIO12)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO13)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO14)->EnableWindow(TRUE);
	GetDlgItem(IDC_RADIO15)->EnableWindow(TRUE);
	GetDlgItem(IDC_RADIO16)->EnableWindow(TRUE);
	GetDlgItem(IDC_RADIO17)->EnableWindow(TRUE);
	GetDlgItem(IDC_RADIO18)->EnableWindow(TRUE);
	GetDlgItem(IDC_RADIO19)->EnableWindow(TRUE);
	GetDlgItem(IDC_RADIO20)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO21)->EnableWindow(FALSE);
	ImageHolder = (CStatic*)GetDlgItem(IDC_LUXURY);
	CString str;
	str = CString(_T("comfort.bmp"));
	HBITMAP pic1 = (HBITMAP)LoadImage(NULL, str, IMAGE_BITMAP, 124, 89, LR_LOADFROMFILE);
	ImageHolder->SetBitmap(pic1);
}



void Inventory::OnBnClickedRadio4()
{
	GetDlgItem(IDC_RADIO12)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO13)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO14)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO15)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO16)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO17)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO18)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO19)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO20)->EnableWindow(TRUE);
	GetDlgItem(IDC_RADIO21)->EnableWindow(TRUE);
	ImageHolder = (CStatic*)GetDlgItem(IDC_LUXURY);
	CString str;
	str = CString(_T("regular.bmp"));
	HBITMAP pic1 = (HBITMAP)LoadImage(NULL, str, IMAGE_BITMAP, 124, 89, LR_LOADFROMFILE);
	ImageHolder->SetBitmap(pic1);
}


void Inventory::OnBnClickedButton3()
{
	UpdateData(true);
	CarNumber = SCarNumber;
	for (int i = 0; i < dataStoring::CarList.size(); i++)
	{
		if (dataStoring::CarList[i]->getNumber() == CarNumber)
		{
			if (MessageBox(_T("Car is already exist, Search another car?"), _T(""), MB_YESNO | MB_ICONQUESTION) == IDYES)
			{
				GetDlgItem(IDC_EDIT1)->EnableWindow(TRUE);
				GetDlgItem(IDC_EDIT2)->EnableWindow(FALSE);
				GetDlgItem(IDC_EDIT3)->EnableWindow(FALSE);
				GetDlgItem(IDC_EDIT4)->EnableWindow(FALSE);
				GetDlgItem(IDC_RADIO1)->EnableWindow(FALSE);
				GetDlgItem(IDC_RADIO2)->EnableWindow(FALSE);
				GetDlgItem(IDC_RADIO3)->EnableWindow(FALSE);
				GetDlgItem(IDC_RADIO4)->EnableWindow(FALSE);
				GetDlgItem(IDC_RADIO5)->EnableWindow(FALSE);
				GetDlgItem(IDC_RADIO6)->EnableWindow(FALSE);
				GetDlgItem(IDC_RADIO7)->EnableWindow(FALSE);
				GetDlgItem(IDC_RADIO8)->EnableWindow(FALSE);
				GetDlgItem(IDC_RADIO9)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON2)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);

				CarNumber = "";
				SCarNumber = "";
				Company = "";
				carType = 0;
				Speed = 0;
				carColor = 0;
				inStock = 0;
			}
			else
				CDialogEx::OnCancel();
			return;
		}
	}
	Car* newCar = 0;
	if (carType == 0)  newCar = new Luxury(CarNumber);
	else if (carType == 1) newCar = new Sport(CarNumber);
	else if (carType == 2) newCar = new Comfort(CarNumber);
	else if (carType == 3) newCar = new Regular(CarNumber);
	

	newCar->setCompany(Company);
	newCar->setColor(carColor);
	newCar->setQuantity(inStock=1);

	switch (carColor)
	{
	case 0: newCar->setColor(0);//red
		break;
	case 1:newCar->setColor(1);//yellow
		break;
	case 2:newCar->setColor(2);//blue
		break;
	case 3:newCar->setColor(3);//black
		break;
	case 4:newCar->setColor(4);//white
		break;
	default:
		break;
	}
	dataStoring::CarList.push_back(newCar);


	ListOfCarss.ResetContent();
	int i = 0;
	while (i < dataStoring::CarList.size())
	{
		ListOfCarss.AddString(dataStoring::CarList[i]->getNumber() + _T("   ") + dataStoring::CarList[i]->getCompany() + _T("   ") + dataStoring::CarList[i]->getColorName());
		i++;

	}
	Speed = newCar->getTopSpeed();
	UpdateData(false);
	//MessageBox(L"Car Added", L"", MB_ICONWARNING);
	if (MessageBox(_T("Car added, Search another car?"), _T(""), MB_YESNO | MB_ICONQUESTION) == IDYES)
	{
		GetDlgItem(IDC_EDIT1)->EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT2)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT3)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT4)->EnableWindow(FALSE);
		GetDlgItem(IDC_RADIO1)->EnableWindow(FALSE);
		GetDlgItem(IDC_RADIO2)->EnableWindow(FALSE);
		GetDlgItem(IDC_RADIO3)->EnableWindow(FALSE);
		GetDlgItem(IDC_RADIO4)->EnableWindow(FALSE);
		GetDlgItem(IDC_RADIO5)->EnableWindow(FALSE);
		GetDlgItem(IDC_RADIO6)->EnableWindow(FALSE);
		GetDlgItem(IDC_RADIO7)->EnableWindow(FALSE);
		GetDlgItem(IDC_RADIO8)->EnableWindow(FALSE);
		GetDlgItem(IDC_RADIO9)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON2)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
		CarNumber = "";
		SCarNumber = "";
		Company = "";
		carType = 0;
		Speed = 0;
		carColor = 0;
		inStock = 0;
	}
	else
    	 CDialogEx::OnCancel();

}


void Inventory::OnEnChangeEdit6()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void Inventory::OnBnClickedDatetimepicker1()
{
	// TODO: Add your control notification handler code here
}


void Inventory::OnEnChangeEdit4()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void Inventory::OnBnClickedRadio5()
{
	// TODO: Add your control notification handler code here


}

void Inventory::OnBnClickedRadio6()
{
	// TODO: Add your control notification handler code here

}


void Inventory::OnBnClickedRadio7()
{
	// TODO: Add your control notification handler code here

}


void Inventory::OnBnClickedRadio8()
{
	// TODO: Add your control notification handler code here

}


void Inventory::OnBnClickedRadio9()
{
	// TODO: Add your control notification handler code here

}


void Inventory::OnBnClickedButton1()//earase
{
	UpdateData(true);
	CarNumber = SCarNumber;
	for (int i = 0; i < dataStoring::CarList.size(); i++)
	{
		if (dataStoring::CarList[i]->getNumber() == CarNumber)
		{
			if (dataStoring::CarList[i]->getIsRent() == false)
			{
				dataStoring::CarList[i]->setQuantity(dataStoring::CarList[i]->getQuantity()-1);
				auto t = dataStoring::CarList.begin() + i;
				dataStoring::CarList.erase(t);
				MessageBox(L" Car erased", L" Error", MB_ICONWARNING);
				GetDlgItem(IDC_EDIT1)->EnableWindow(TRUE);
				GetDlgItem(IDC_EDIT2)->EnableWindow(FALSE);
				GetDlgItem(IDC_EDIT3)->EnableWindow(FALSE);
				GetDlgItem(IDC_EDIT4)->EnableWindow(FALSE);
				GetDlgItem(IDC_RADIO1)->EnableWindow(FALSE);
				GetDlgItem(IDC_RADIO2)->EnableWindow(FALSE);
				GetDlgItem(IDC_RADIO3)->EnableWindow(FALSE);
				GetDlgItem(IDC_RADIO4)->EnableWindow(FALSE);
				GetDlgItem(IDC_RADIO5)->EnableWindow(FALSE);
				GetDlgItem(IDC_RADIO6)->EnableWindow(FALSE);
				GetDlgItem(IDC_RADIO7)->EnableWindow(FALSE);
				GetDlgItem(IDC_RADIO8)->EnableWindow(FALSE);
				GetDlgItem(IDC_RADIO9)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON2)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);

				CarNumber = "";
				SCarNumber = "";
				Company = "";
				inStock = 0;
				carType = 0;
				Speed = 0;
				carColor = 0;
				UpdateData(false);

				ListOfCarss.ResetContent();
				int i = 0;
				while (i < dataStoring::CarList.size())
				{
					ListOfCarss.AddString(dataStoring::CarList[i]->getNumber() + _T("   ") + dataStoring::CarList[i]->getCompany() + _T("   ") + dataStoring::CarList[i]->getColorName());
					i++;

				}

				return;
			}
			else
			{
				MessageBox(L" Car is rented by costumer", L" Error", MB_ICONWARNING);
				return;
			}
		}
	}
	MessageBox(L" Car is not found", L" Error", MB_ICONWARNING);
}


void Inventory::OnEnChangeEdit3()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void Inventory::OnEnChangeEdit2()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void Inventory::OnBnClickedButton4()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}



void Inventory::OnLbnSelchangeList2()
{
	// TODO: Add your control notification handler code here
}


void Inventory::OnBnClickedRadio14()
{
	// TODO: Add your control notification handler code here
}
