// Graphics.h

#ifndef GRAPHICS_H_INCLUDED
#define GRAPHICS_H_INCLUDED

// INCLUDES
#include <Windows.h>
#include <tchar.h>


// MY CLASS INCLUDES
#include "Enums.h"
#include "View.h"

// Views
#include "EntryView.h"


class Graphics
{
	public:
		Graphics();
		void draw(HWND hWnd, HDC hdc);
		void setView(ViewEnum view);
	private:
		View * view;
};



#endif