
// ActivateCortanaDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "ActivateCortana.h"
#include "ActivateCortanaDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
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


// CActivateCortanaDlg 对话框



CActivateCortanaDlg::CActivateCortanaDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_ACTIVATECORTANA_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CActivateCortanaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CActivateCortanaDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CActivateCortanaDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CActivateCortanaDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_ACT, &CActivateCortanaDlg::OnBnClickedAct)
	ON_BN_CLICKED(IDC_UNI, &CActivateCortanaDlg::OnBnClickedUni)
	ON_BN_CLICKED(IDC_REB, &CActivateCortanaDlg::OnBnClickedReb)
END_MESSAGE_MAP()


// CActivateCortanaDlg 消息处理程序

BOOL CActivateCortanaDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

void CActivateCortanaDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CActivateCortanaDlg::OnPaint()
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
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CActivateCortanaDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CActivateCortanaDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CActivateCortanaDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialog::OnCancel();
}

#include "Reg.h"

char K1[] = "SOFTWARE\\Microsoft\\Speech_OneCore\\Voices\\Tokens\\CortanaChinese";
char K2[] = "SOFTWARE\\Microsoft\\Speech_OneCore\\Voices\\Tokens\\CortanaChinese\\Attributes";
char K3[] = "SOFTWARE\\Microsoft\\Speech\\Voices\\Tokens\\CortanaChinese";
char K4[] = "SOFTWARE\\Microsoft\\Speech\\Voices\\Tokens\\CortanaChinese\\Attributes";

char K5[] = "SOFTWARE\\Microsoft\\Speech_OneCore\\Voices\\Tokens\\CortanaEnglish";
char K6[] = "SOFTWARE\\Microsoft\\Speech_OneCore\\Voices\\Tokens\\CortanaEnglish\\Attributes";
char K7[] = "SOFTWARE\\Microsoft\\Speech\\Voices\\Tokens\\CortanaEnglish";
char K8[] = "SOFTWARE\\Microsoft\\Speech\\Voices\\Tokens\\CortanaEnglish\\Attributes";
DWORD WINAPI Ins()
{
	CreateKey(K1);
	CreateKey(K2);
	CreateKey(K3);
	CreateKey(K4);

	CreateValueS(K1, "", "Cortana - Chinese(Simplified)");
	CreateValueS(K1, "LangDataPath", "%windir%\\Speech_OneCore\\Engines\\TTS\\zh-CN\\MSTTSLoczhCN.dat");
	CreateValueS(K1, "LangUpdateDataDirectory", "%SystemDrive%\\Data\\SharedData\\Speech_OneCore\\Engines\\TTS\\zh-CN");
	CreateValueS(K1, "VoicePath", "%windir%\\Speech_OneCore\\Engines\\TTS\\zh-CN\\M2052Hongyu");
	CreateValueS(K1, "VoiceUpdateDataDirectory", "%SystemDrive%\\Data\\SharedData\\Speech_OneCore\\Engines\\TTS\\zh-CN");
	CreateValueS(K1, "804", "Cortana - Chinese(Simplified)");
	CreateValueS(K1, "CLSID", "{179F3D56-1B0B-42B2-A962-59B7EF59FE1B}");
	CreateValueS(K2, "Version", "11.0");
	CreateValueS(K2, "Language", "804");
	CreateValueS(K2, "Gender", "Female");
	CreateValueS(K2, "Age", "Adult");
	CreateValueS(K2, "DataVersion", "11.0.2013.1022");
	CreateValueS(K2, "SharedPronunciation", "");
	CreateValueS(K2, "Name", "Cortana - Chinese(Simplified)");
	CreateValueS(K2, "Vendor", "Microsoft");
	CreateValueS(K2, "PersonalAssistant", "1");

	CreateValueS(K3, "", "Cortana - Chinese(Simplified)");
	CreateValueS(K3, "LangDataPath", "%windir%\\Speech_OneCore\\Engines\\TTS\\zh-CN\\MSTTSLoczhCN.dat");
	CreateValueS(K3, "LangUpdateDataDirectory", "%SystemDrive%\\Data\\SharedData\\Speech_OneCore\\Engines\\TTS\\zh-CN");
	CreateValueS(K3, "VoicePath", "%windir%\\Speech_OneCore\\Engines\\TTS\\zh-CN\\M2052Hongyu");
	CreateValueS(K3, "VoiceUpdateDataDirectory", "%SystemDrive%\\Data\\SharedData\\Speech_OneCore\\Engines\\TTS\\zh-CN");
	CreateValueS(K3, "804", "Cortana - Chinese(Simplified)");
	CreateValueS(K3, "CLSID", "{179F3D56-1B0B-42B2-A962-59B7EF59FE1B}");
	CreateValueS(K4, "Version", "11.0");
	CreateValueS(K4, "Language", "804");
	CreateValueS(K4, "Gender", "Female");
	CreateValueS(K4, "Age", "Adult");
	CreateValueS(K4, "DataVersion", "11.0.2013.1022");
	CreateValueS(K4, "SharedPronunciation", "");
	CreateValueS(K4, "Name", "Cortana - Chinese(Simplified)");
	CreateValueS(K4, "Vendor", "Microsoft");
	CreateValueS(K4, "PersonalAssistant", "1");

	CreateKey(K5);
	CreateKey(K6);
	CreateKey(K7);
	CreateKey(K8);

	CreateValueS(K5, "", "Cortana - English(United States)");
	CreateValueS(K5, "LangDataPath", "%windir%\\Speech_OneCore\\Engines\\TTS\\en-US\\MSTTSLocenUS.dat");
	CreateValueS(K5, "LangUpdateDataDirectory", "%SystemDrive%\\Data\\SharedData\\Speech_OneCore\\Engines\\TTS\\en-US");
	CreateValueS(K5, "VoicePath", "%windir%\\Speech_OneCore\\Engines\\TTS\\en-US\\M1033Eva");
	CreateValueS(K5, "VoiceUpdateDataDirectory", "%SystemDrive%\\Data\\SharedData\\Speech_OneCore\\Engines\\TTS\\en-US");
	CreateValueS(K5, "409", "Cortana - English(United States)");
	CreateValueS(K5, "CLSID", "{179F3D56-1B0B-42B2-A962-59B7EF59FE1B}");
	CreateValueS(K6, "Version", "11.0");
	CreateValueS(K6, "Language", "409");
	CreateValueS(K6, "Gender", "Female");
	CreateValueS(K6, "Age", "Adult");
	CreateValueS(K6, "DataVersion", "11.0.2013.1022");
	CreateValueS(K6, "SharedPronunciation", "");
	CreateValueS(K6, "Name", "Cortana - English(United States)");
	CreateValueS(K6, "Vendor", "Microsoft");
	CreateValueS(K6, "PersonalAssistant", "1");

	CreateValueS(K7, "", "Cortana - English(United States)");
	CreateValueS(K7, "LangDataPath", "%windir%\\Speech_OneCore\\Engines\\TTS\\en-US\\MSTTSLocenUS.dat");
	CreateValueS(K7, "LangUpdateDataDirectory", "%SystemDrive%\\Data\\SharedData\\Speech_OneCore\\Engines\\TTS\\en-US");
	CreateValueS(K7, "VoicePath", "%windir%\\Speech_OneCore\\Engines\\TTS\\en-US\\M1033Eva");
	CreateValueS(K7, "VoiceUpdateDataDirectory", "%SystemDrive%\\Data\\SharedData\\Speech_OneCore\\Engines\\TTS\\en-US");
	CreateValueS(K7, "409", "Cortana - English(United States)");
	CreateValueS(K7, "CLSID", "{179F3D56-1B0B-42B2-A962-59B7EF59FE1B}");
	CreateValueS(K8, "Version", "11.0");
	CreateValueS(K8, "Language", "409");
	CreateValueS(K8, "Gender", "Female");
	CreateValueS(K8, "Age", "Adult");
	CreateValueS(K8, "DataVersion", "11.0.2013.1022");
	CreateValueS(K8, "SharedPronunciation", "");
	CreateValueS(K8, "Name", "Cortana - English(United States)");
	CreateValueS(K8, "Vendor", "Microsoft");
	CreateValueS(K8, "PersonalAssistant", "1");
	return GetLastError();
}

DWORD WINAPI Unis()
{
	SHDeleteKey(HKEY_LOCAL_MACHINE, K1);
	SHDeleteKey(HKEY_LOCAL_MACHINE, K2);
	SHDeleteKey(HKEY_LOCAL_MACHINE, K3);
	SHDeleteKey(HKEY_LOCAL_MACHINE, K4);
	SHDeleteKey(HKEY_LOCAL_MACHINE, K5);
	SHDeleteKey(HKEY_LOCAL_MACHINE, K6);
	SHDeleteKey(HKEY_LOCAL_MACHINE, K7);
	SHDeleteKey(HKEY_LOCAL_MACHINE, K8);
	return GetLastError();
}

void CActivateCortanaDlg::OnBnClickedAct()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!Ins()) MessageBox("Successfully installed the cortana voice service for developers!\nYou need to reboot to use it!","Success",MB_ICONASTERISK);
	else MessageBox("Failed to install the cortana voice service for developers!\n", "Failure", MB_ICONASTERISK);
}


void CActivateCortanaDlg::OnBnClickedUni()
{

	if (!Unis()) MessageBox("Successfully uninstalled the cortana voice service for developers!\nYou need to reboot to clear it!", "Success", MB_ICONASTERISK);
	else MessageBox("Failed to uninstall the cortana voice service for developers!\n", "Failure", MB_ICONASTERISK);
}


void CActivateCortanaDlg::OnBnClickedReb()
{

	system("shutdown -f -r -t 0");
}
