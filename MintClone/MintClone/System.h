// System.h

#ifndef SYSTEM_H_INCLUDED
#define SYSTEM_H_INCLUDED

// INCLUDES
#include <Windows.h>
#include <tchar.h>




class System {
	public:
		System();
		System(const System&);
		~System();
		bool Initialize(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
			PSTR pScmdline, int iCmdshow);
		void Shutdown();
		int Run();
		LRESULT MessageHandler(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	private:
};



// Internal Linkage

static const TCHAR szWindowClass[] = _T("Mint Clone");
static const TCHAR szTitle[] = _T("Mint Clone");
static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// Global
static System * ApplicationHandle = NULL;

#endif