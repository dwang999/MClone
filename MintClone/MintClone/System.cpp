// System.cpp

#include "System.h"


// Methods
bool System::Initialize(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pScmdline, int iCmdshow)
{
	ApplicationHandle = this;

	// Create windows class  
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName  = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));

	// Regiser windows class
	if (!RegisterClassEx(&wcex))
	{
		MessageBox(NULL, _T("Call to RegisterClassEX failed!"), szTitle, NULL);
		return false;
	}

	// Creating Window for application
	HWND hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, NULL, NULL, hInstance, 
		NULL);

	if (!hWnd)
	{
		MessageBox(NULL, _T("Call to CreateWindow failed!"), szTitle, NULL);
		return false;
	}
	
	input = Input();
	graphics = Graphics();


	ShowWindow(hWnd, iCmdshow);
	UpdateWindow(hWnd);
	return true;
}

void System::Shutdown()
{
	ApplicationHandle = NULL;
}

int System::Run()
{
	// Main message loop:
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int) msg.wParam;
}

LRESULT System::MessageHandler(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	switch (message)
	{
		case WM_PAINT:
		{
			hdc = BeginPaint(hWnd, &ps);
			graphics.draw(hWnd, hdc);
			EndPaint(hWnd, &ps);
			break;		
		}
	case WM_COMMAND:
		{
			input.WMCOMMAND(wParam, hWnd);
			break;
		}
	default:
		{
			return DefWindowProc(hWnd, message, wParam, lParam);
			break;
		}
	}

	return 0;
}




// Global Methods
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return ApplicationHandle -> MessageHandler(hWnd, message, wParam, lParam);
	}

	return 0;
}