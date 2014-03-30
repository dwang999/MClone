// EntryController.h

#ifndef ENTRYCONTROLLER_H_INCLUDED
#define ENTRYCONTROLLER_H_INCLUDED

// INCLUDES
#include <vector>
#include <fstream>

// MY CLASS INCLUDES
#include "Entry.h"

class EntryController
{

	public:

		void push_back(time_t date, std::string category, std::string subCategory, 
			std::string description, float amount);
		void remove(int indexToRemove);
		void save(std::string profileName);
		void load(std::string profileName);

	private:
		std::vector<Entry> entries;

};


#endif