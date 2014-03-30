// Input.cpp

#include "Input.h"

void Input::WMCOMMAND(WPARAM wParam, HWND hWnd)
{
	switch(LOWORD(wParam)) // Handle Button Clicks
	{
	case ButtonEnum::ENTRIES_MAIN_BUTTON:
		{
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		}
	}
}