// HellEd.cpp : main project file.

#include <windows.h>
#include "stdafx.h"
#include "FormMain.h"

using namespace HellEd;
using namespace System::Diagnostics;

typedef System::Object object;
typedef System::String string;

#ifdef SendMessage
#undef SendMessage
#endif 
#ifdef EnumWindows
#undef EnumWindows
#endif 
#ifdef GetWindowText
#undef GetWindowText
#endif 
#ifdef GetWindowTextLength
#undef GetWindowTextLength
#endif 

delegate bool EnumWindowsProc(IntPtr hWnd, int lParam);

[DllImport("user32.dll")]
extern IntPtr SendMessage(IntPtr hWnd, int Msg, IntPtr wParam, IntPtr lParam);
[DllImport("user32.dll")]
extern int EnumWindows(EnumWindowsProc^ lpEnumFunc, IntPtr lParam);
[DllImport("user32.dll")]
extern int GetWindowText(IntPtr hWnd, System::Text::StringBuilder^ text, int cnt);
[DllImport("user32.dll")]
extern int GetWindowTextLength(IntPtr hWnd);

IntPtr hWndHellEd;

bool __clrcall searcher(IntPtr hWnd, int lParam)
{
	string^ ttl = string::Concat(L"HellEd ", System::Reflection::Assembly::GetExecutingAssembly()->GetName()->Version->Major,".",
		System::Reflection::Assembly::GetExecutingAssembly()->GetName()->Version->Minor,".",
		System::Reflection::Assembly::GetExecutingAssembly()->GetName()->Version->Build);
	System::Text::StringBuilder^ tt = gcnew System::Text::StringBuilder(GetWindowTextLength(hWnd)+1);
	GetWindowText(hWnd,tt,GetWindowTextLength(hWnd)+1);
	if (tt)
	{
		if (tt->ToString()->Equals(ttl))
		{
			hWndHellEd = hWnd;
			return false;
		}
	}
    return true;
}


[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	array<Process^> ^ processes = Process::GetProcessesByName(
		Process::GetCurrentProcess()->ProcessName);
	int length = processes->Length;

	string^ url = L"";
	if (args)
	for (int i=0;i<args->Length;i++)
	{url = string::Concat(args[i]);}
	if (length==1)
	{
		DevExpress::UserSkins::OfficeSkins::Register();
		
		Application::EnableVisualStyles();
		Application::SetCompatibleTextRenderingDefault(false); 
		Application::Run(gcnew FormMain(url));
		return 0;
	}
	if (length>1)
	{
		IntPtr pStr = IntPtr::Zero;
		pStr = Marshal::StringToHGlobalAnsi(url);
		COPYDATASTRUCT data;
		data.lpData = (void*)pStr;
		data.cbData = System::Text::Encoding::ASCII->GetByteCount(url);
		IntPtr hWnd;
		EnumWindows(gcnew EnumWindowsProc(searcher), hWnd);
		if (hWndHellEd!=IntPtr::Zero)
		{SendMessage(hWndHellEd, WM_COPYDATA, IntPtr::Zero, (IntPtr)&data);}
		Marshal::FreeHGlobal(pStr);
		return 0;
	}
}
