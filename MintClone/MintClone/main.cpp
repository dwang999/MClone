// main.cpp

// MEMORY LEAK DEBUGGING INCLUDES
#include <vld.h>


// MY CLASS INCLUDES
#include "System.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pScmdline, int iCmdshow)
{
	
	System * system = new System();
	int result;

	if(!system -> Initialize(hInstance, hPrevInstance, pScmdline, iCmdshow))
	{
		MessageBox(NULL, _T("System -> Initialize failed!"), szTitle, NULL);
	}

	result = system->Run();
	

	// Clean Up
	system->Shutdown();
	delete system;
	system = NULL;
	
	return result;
}


/*
#include <ctime>
#include "Entry.h"


std::time_t hi;
std::time(&hi);
std::time_t hi2;
std::time(&hi2);

DebugOut() << std::asctime(localtime(&hi)) << std::endl;
DebugOut() << std::asctime(gmtime(&hi2)) << std::endl;


Entry entry = Entry(hi, "hi", "hi", "hi", 10);
DebugOut() << entry << std::endl;
*/