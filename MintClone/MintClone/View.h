// View.h

#ifndef VIEW_H_INCLUDED
#define VIEW_H_INCLUDED

// INCLUDES
#include <Windows.h>

// MY CLASS INCLUDES


class View
{
	public:
		virtual ~View() {};

		virtual void draw(HWND hWnd, HDC hdc) = 0;
	private:
};



#endif