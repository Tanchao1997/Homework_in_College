
// MFCApplication9-calculatorDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "MFCApplication9-calculator.h"
#include "MFCApplication9-calculatorDlg.h"
#include "afxdialogex.h"
#include "strstream"
#include"string"
#include"iostream"
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();
	int key = 0;//用数字记录按下的键
	int opNum = 0;
// 对话框数据
#ifdef AFX_DediGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication9calculatorDlg 对话框



CMFCApplication9calculatorDlg::CMFCApplication9calculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION9CALCULATOR_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication9calculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON10, num_7);
	DDX_Control(pDX, IDC_BUTTON11, num_8);
	DDX_Control(pDX, IDC_BUTTON12, num_9);
	DDX_Control(pDX, IDC_BUTTON14, num_4);
	DDX_Control(pDX, IDC_BUTTON15, num_5);
	DDX_Control(pDX, IDC_BUTTON16, num_6);
	DDX_Control(pDX, IDC_BUTTON18, num_1);
	DDX_Control(pDX, IDC_BUTTON19, num_2);
	DDX_Control(pDX, IDC_BUTTON20, num_3);
	DDX_Control(pDX, IDC_BUTTON23, num_0);
}

BEGIN_MESSAGE_MAP(CMFCApplication9calculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON10, &CMFCApplication9calculatorDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &CMFCApplication9calculatorDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &CMFCApplication9calculatorDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON14, &CMFCApplication9calculatorDlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON15, &CMFCApplication9calculatorDlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON16, &CMFCApplication9calculatorDlg::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON18, &CMFCApplication9calculatorDlg::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON19, &CMFCApplication9calculatorDlg::OnBnClickedButton19)
	ON_BN_CLICKED(IDC_BUTTON20, &CMFCApplication9calculatorDlg::OnBnClickedButton20)
	ON_BN_CLICKED(IDC_BUTTON23, &CMFCApplication9calculatorDlg::OnBnClickedButton23)
	ON_BN_CLICKED(IDC_BUTTON8, &CMFCApplication9calculatorDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON26, &CMFCApplication9calculatorDlg::OnBnClickedButton26)
	ON_BN_CLICKED(IDC_BUTTON27, &CMFCApplication9calculatorDlg::OnBnClickedButton27)
	ON_BN_CLICKED(IDC_BUTTON28, &CMFCApplication9calculatorDlg::OnBnClickedButton28)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplication9calculatorDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON9, &CMFCApplication9calculatorDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON13, &CMFCApplication9calculatorDlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON17, &CMFCApplication9calculatorDlg::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON21, &CMFCApplication9calculatorDlg::OnBnClickedButton21)
	ON_BN_CLICKED(IDC_BUTTON25, &CMFCApplication9calculatorDlg::OnBnClickedButton25)
	ON_BN_CLICKED(IDC_BUTTON24, &CMFCApplication9calculatorDlg::OnBnClickedButton24)
	ON_EN_CHANGE(IDC_EDIT2, &CMFCApplication9calculatorDlg::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON100, &CMFCApplication9calculatorDlg::OnBnClickedButton100)
END_MESSAGE_MAP()


// CMFCApplication9calculatorDlg 消息处理程序

BOOL CMFCApplication9calculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCApplication9calculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplication9calculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCApplication9calculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication9calculatorDlg::OnBnClickedButton10()
{
	// TODO: 在此添加控件通知处理程序代码
	num.append("7");
	cstrNum = num.c_str();
	SetDlgItemText(IDC_EDIT2, cstrNum);
}


void CMFCApplication9calculatorDlg::OnBnClickedButton11()
{
	// TODO: 在此添加控件通知处理程序代码
	num.append("8");
	cstrNum = num.c_str();
	SetDlgItemText(IDC_EDIT2, cstrNum);
}


void CMFCApplication9calculatorDlg::OnBnClickedButton12()
{
	// TODO: 在此添加控件通知处理程序代码
	num.append("9");
	cstrNum = num.c_str();
	SetDlgItemText(IDC_EDIT2, cstrNum);
}


void CMFCApplication9calculatorDlg::OnBnClickedButton14()
{
	// TODO: 在此添加控件通知处理程序代码
	num.append("4");
	cstrNum = num.c_str();
	SetDlgItemText(IDC_EDIT2, cstrNum);
}


void CMFCApplication9calculatorDlg::OnBnClickedButton15()
{
	// TODO: 在此添加控件通知处理程序代码
	num.append("5");
	cstrNum = num.c_str();
	SetDlgItemText(IDC_EDIT2, cstrNum);
}


void CMFCApplication9calculatorDlg::OnBnClickedButton16()
{
	// TODO: 在此添加控件通知处理程序代码
	num.append("6");
	cstrNum = num.c_str();
	SetDlgItemText(IDC_EDIT2, cstrNum);
}


void CMFCApplication9calculatorDlg::OnBnClickedButton18()
{
	// TODO: 在此添加控件通知处理程序代码
	num.append("1");
	cstrNum = num.c_str();
	SetDlgItemText(IDC_EDIT2, cstrNum);
}


void CMFCApplication9calculatorDlg::OnBnClickedButton19()
{
	// TODO: 在此添加控件通知处理程序代码
	num.append("2");
	cstrNum = num.c_str();
	SetDlgItemText(IDC_EDIT2, cstrNum);
}


void CMFCApplication9calculatorDlg::OnBnClickedButton20()
{
	// TODO: 在此添加控件通知处理程序代码
	num.append("3");

	cstrNum = num.c_str();
	SetDlgItemText(IDC_EDIT2, cstrNum);
}


void CMFCApplication9calculatorDlg::OnBnClickedButton23()
{
	// TODO: 在此添加控件通知处理程序代码
	num.append("0");
	cstrNum = num.c_str();
	SetDlgItemText(IDC_EDIT2, cstrNum);
}

double CMFCApplication9calculatorDlg::calculator(double n1, double n2, int op)
{
	//整数和整数 运算
	_asm
	{
	finit    //初始化FPU栈
	fld n2
	fld n1
	switch1:
		cmp op,1
			je case1
		cmp op,2
			je case2
		cmp op, 3
			je case3
		cmp op, 4
			je case4
		cmp op, 5
			je case5
		cmp op, 6
			je case6
		cmp op, 7
			je case7
		cmp op, 8
			je case8
		cmp op, 9
			je case9
		cmp op, 10
			je case10
		cmp op, 11
			je case11
		cmp op, 12
			je case12
	case1://加法
		fadd st(0), st(1)
		jmp endswitch1
	case2://减法
		fsub st(0), st(1)
		jmp endswitch1
	case3://乘法
		fmul st(0), st(1)
		jmp endswitch1
	case4://除法
		fdiv st(0), st(1)
		jmp endswitch1
	case5:
		jmp endswitch1
	case6:
		jmp endswitch1
	case7:
		jmp endswitch1
	case8:
		jmp endswitch1
	case9://MOD
		fprem
		jmp endswitch1
	case10:
		jmp endswitch1
	case11:
		jmp endswitch1
	case12:
		jmp endswitch1
	endswitch1:
		fst n1
		nop
	}
	return n1;
}

void CMFCApplication9calculatorDlg::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	num.erase(num.length() - 1, 1);
	cstrNum = num.c_str();
	SetDlgItemText(IDC_EDIT2, cstrNum);
}


void CMFCApplication9calculatorDlg::OnBnClickedButton26()
{
	double n1, n2, nAns;
	n2 = atof(num.c_str());
	int opN = opNum;

	//存储第一个数
	_asm
	{
		finit    //初始化FPU栈
		fld n2
		fsin
		fstp n2
	}

	//double结果转为string

	//文本框显示
	num = to_string(n2);
	cstrNum = num.c_str();

	SetDlgItemText(IDC_EDIT2, cstrNum);
}


void CMFCApplication9calculatorDlg::OnBnClickedButton27()
{
	// TODO: 在此添加控件通知处理程序代码
	double n1, n2, nAns;
	n2 = atof(num.c_str());
	int opN = opNum;

	//存储第一个数
	_asm
	{
		finit    //初始化FPU栈
		fld n2
		fcos
		fstp n2
	}

	//double结果转为string

	//文本框显示
	num = to_string(n2);
	cstrNum = num.c_str();

	SetDlgItemText(IDC_EDIT2, cstrNum);
}


void CMFCApplication9calculatorDlg::OnBnClickedButton28()
{
	// TODO: 在此添加控件通知处理程序代码
	double n1, n2, nAns;
	n2 = atof(num.c_str());
	int opN = opNum;

	//存储第一个数
	_asm
	{
		finit    //初始化FPU栈
		fld n2
		fsin
		fld n2
		fcos
		fdiv
		fstp n2
	}

	//double结果转为string

	//文本框显示
	num = to_string(n2);
	cstrNum = num.c_str();

	SetDlgItemText(IDC_EDIT2, cstrNum);
}


void CMFCApplication9calculatorDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	double n1, n2, nAns;
	n2 = atof(num.c_str());
	int opN = opNum;

	//存储第一个数
	_asm
	{
		finit    //初始化FPU栈
		fld n2
		fabs
		fstp n2
	}

	//double结果转为string

	//文本框显示
	num = to_string(n2);
	cstrNum = num.c_str();

	SetDlgItemText(IDC_EDIT2, cstrNum);
}

void CMFCApplication9calculatorDlg::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	double n1, n2, nAns;
	n1 = atof(num1.c_str());
	n2 = atof(num.c_str());
	//double d1=Double.parseDouble(num);
	int opN = opNum;

	_asm
	{
	finit    //初始化FPU栈
	L0 :
		cmp opN, 0
			je assign1
			cmp opN, 1
			je div1
	assign1 :
		fld n2
		fstp n1
			inc opN
			jmp out1
	div1 :
		jmp out1
	out1 : nop
	}

	//double结果转为string

	//文本框显示
	if (opNum == 0) {
		num1 = to_string(n1);
		cstrNum = "";
		opNum++;
	}
	else {
		n1=calculator(n1, n2, key);
		num1 = to_string(n1);
		cstrNum = num1.c_str();
	}
	num.clear();
	SetDlgItemText(IDC_EDIT2, cstrNum);
	key = 4;
}


void CMFCApplication9calculatorDlg::OnBnClickedButton13()
{
	// TODO: 在此添加控件通知处理程序代码
	double n1, n2, nAns;
	n1 = atof(num1.c_str());
	n2 = atof(num.c_str());
	//double d1=Double.parseDouble(num);
	int opN = opNum;

	_asm
	{
	finit    //初始化FPU栈
	L0 :
		cmp opN, 0
			je assign1
			cmp opN, 1
			je imul1
	assign1 :
		fld n2
		fstp n1
			inc opN
			jmp out1
	imul1 :
		jmp out1
	out1 : nop
	}

	//double结果转为string

	//文本框显示
	if (opNum == 0) {
		num1 = to_string(n1);
		cstrNum = "";
		opNum++;
	}
	else {
		n1=calculator(n1, n2, key); 
		num1 = to_string(n1);
		cstrNum = num1.c_str();
	}
	num.clear();
	SetDlgItemText(IDC_EDIT2, cstrNum);
	key = 3;
}


void CMFCApplication9calculatorDlg::OnBnClickedButton17()
{
	// TODO: 在此添加控件通知处理程序代码
	double n1, n2, nAns;
	n1 = atof(num1.c_str());
	n2 = atof(num.c_str());
	//double d1=Double.parseDouble(num);
	int opN = opNum;

	_asm
	{
	finit    //初始化FPU栈
	L0 :
		cmp opN, 0
			je assign1
			cmp opN, 1
			je sub1
	assign1 :
		fld n2
		fstp n1
			inc opN
			jmp out1
	sub1 :
		jmp out1
	out1 : nop
	}

	//double结果转为string

	//文本框显示
	if (opNum == 0) {
		num1 = to_string(n1);
		cstrNum = "";
		opNum++;
	}
	else {
		n1=calculator(n1, n2, key); 
		num1 = to_string(n1);
		cstrNum = num1.c_str();
	}
	num.clear();
	SetDlgItemText(IDC_EDIT2, cstrNum);
	key = 2;
}

//加法
void CMFCApplication9calculatorDlg::OnBnClickedButton21()
{
	// TODO: 在此添加控件通知处理程序代码
	double n1, n2, nAns;
	n1 = atof(num1.c_str());
	n2 = atof(num.c_str());
	int opN = opNum;

	//存储第一个数
	_asm
	{
	finit    //初始化FPU栈
	L0:
		cmp opN, 0
			je assign1
		cmp opN, 1
			je add1
	assign1:
		fld n2
		fstp n1
		inc opN
		jmp out1
	add1:
		jmp out1
	out1:nop
	}

	//double结果转为string

	//文本框显示
	if (opNum == 0) {
		num1 = to_string(n1);
		cstrNum = "";
		opNum++;
	}
	else {
		n1=calculator(n1, n2, key);
		num1 = to_string(n1);
		cstrNum = num1.c_str();
	}
	num.clear();
	SetDlgItemText(IDC_EDIT2, cstrNum);
	key = 1;
}


void CMFCApplication9calculatorDlg::OnBnClickedButton25()
{
	// TODO: 在此添加控件通知处理程序代码
	double n1, n2, nAns;
	n1 = atof(num1.c_str());
	n2 = atof(num.c_str());
	int opN = opNum;

	//存储第一个数
	_asm
	{
		finit    //初始化FPU栈
		L0 :
		cmp opN, 0
			je assign1
			cmp opN, 1
			je add1
			assign1 :
		fld n2
			fstp n1
			inc opN
			jmp out1
			add1 :
		jmp out1
			out1 : nop
	}

	//double结果转为string

	//文本框显示
	if (opNum == 0) {
		num1 = to_string(n1);
	}
	else {
		n1 = calculator(n1, n2, key);
		num1 = to_string(n1);
		opNum--;
	}

	num = to_string(n1);
	cstrNum = num1.c_str();
	SetDlgItemText(IDC_EDIT2, cstrNum);
}


void CMFCApplication9calculatorDlg::OnBnClickedButton24()
{
	// TODO: 在此添加控件通知处理程序代码
	num.append(".");
	cstrNum = num.c_str();
	SetDlgItemText(IDC_EDIT2, cstrNum);
}


void CMFCApplication9calculatorDlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CMFCApplication9calculatorDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

}


void CMFCApplication9calculatorDlg::OnBnClickedButton100()
{
	// TODO: 在此添加控件通知处理程序代码
	key = 0;
	opNum = 0;
	num = "";
	num1 = "";
	n1 = 0;
	n2 = 0;
	cstrNum = num.c_str();
	SetDlgItemText(IDC_EDIT2, cstrNum);
}
