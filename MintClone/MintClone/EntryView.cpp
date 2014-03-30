// EntryView.cpp

#include "EntryView.h"


void EntryView::draw(HWND hWnd, HDC hdc)
{
	TCHAR greeting[] = _T("Welcome to Mint!");
	TCHAR goodbye[] = _T("GoodBye!");
	static bool hi = true;
	if (hi){
		TextOut(hdc, 5, 5, greeting, _tcslen(greeting));
		hi = false;
	}
	else
	{
		TextOut(hdc, 5, 5, greeting, _tcslen(goodbye));
		hi = true;
	}	
	HWND hWndButton = GetDlgItem(hWnd, static_cast<int>(ButtonEnum::ENTRIES_MAIN_BUTTON));
	if (hWndButton == NULL){
		// Create a push button
		hWndButton=CreateWindowEx(NULL,
			TEXT("BUTTON"),
			TEXT("OK"),
			WS_TABSTOP|WS_VISIBLE|
			WS_CHILD|BS_DEFPUSHBUTTON,
			50,
			220,
			100,
			24,
			hWnd,
			(HMENU)ButtonEnum::ENTRIES_MAIN_BUTTON,
			GetModuleHandle(NULL),
			NULL);
	}
}