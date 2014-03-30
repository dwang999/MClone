// Graphics.cpp

#include "Graphics.h"

Graphics::Graphics()
{
	this->view = new EntryView();
}


void Graphics::setView(ViewEnum viewEnum)
{
	switch (viewEnum)
	{
	case ViewEnum::ENTRIES:
		{	
			this->view = new EntryView();
		}
	}
}

void Graphics::draw(HWND hWnd, HDC hdc)
{
	this-> view -> draw(hWnd, hdc);
}