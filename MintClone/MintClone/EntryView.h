// EntryView.h

#ifndef ENTRYVIEW_H_INCLUDED
#define ENTRYVIEW_H_INCLUDED

// INCLUDES
#include <Windows.h>
#include <tchar.h>


// MY CLASS INCLUDES
#include "Enums.h"
#include "View.h"

class EntryView : public View
{
	public:

		void draw(HWND hWnd, HDC hdc);
	private:
};



#endif