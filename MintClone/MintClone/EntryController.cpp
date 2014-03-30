// EntryController.cpp

#include "EntryController.h"

namespace{

	static const std::string entryFileName = "-entries.txt";
	
	void parseTokens(EntryController *entry, std::string str)
	{	
		// Get Tokens
		std::string delim = "/";
		std::vector<std::string> tokens;
		tokens.reserve(NUMOFVARIABLESINENTRY);
		unsigned int delimPos = str.find(delim);
		int start = 0;
		while (delimPos != std::string::npos)
		{
			std::string token = str.substr(start, delimPos - start);
			start = delimPos + 1;
			delimPos = str.find(delim, start);
			tokens.push_back(token);
		}

		if (tokens.size() != NUMOFVARIABLESINENTRY)
		{
			throw std::exception("EntryController.cpp::parseTokens : tokens has incorrect size() for parsing");
		}
		
		// Parse tokens 
		std::time_t date;
		std::string category;
		std::string subCategory;
		std::string description;
		float amount;

		for (int i = 0; i < NUMOFVARIABLESINENTRY; i++)
		{
			switch (i)
			{
			case 0: // date
				date = std::stoi(tokens[i]);
				break;
			case 1: // category
				category = tokens[i];
				break;
			case 2: // sub-category
				subCategory = tokens[i];
				break;
			case 3: // description
				description = tokens[i];
				break;
			case 4: // amount
				amount = std::stof(tokens[i]);

				break;
			}
		}

		entry -> push_back(date, category, subCategory, description, amount);
	}
}

// Methods
void EntryController::push_back(time_t date, std::string category, std::string subCategory, 
								std::string description, float amount)
{
	entries.push_back(Entry(date, category, subCategory, description, amount));
}

void EntryController::remove(int indexToRemove)
{

	entries.erase(entries.begin() + indexToRemove);
}

void EntryController::save(std::string profileName)
{
	std::string filename = profileName + entryFileName;
	std::fstream fs;
	fs.open(filename, std::fstream::out | std::fstream::trunc);

	if (fs.is_open())
	{
		for(Entry entry : entries)
		{
			fs << entry << std::endl;
		} 

		fs.close();
	}


}

void EntryController::load(std::string profileName)
{
	std::string filename = profileName + entryFileName;
	std::fstream fs;
	std::string line;

	fs.open(filename, std::fstream::in);


	if (fs.is_open())
	{

		while(!fs.eof())
		{
			std::getline(fs, line);
			parseTokens(this , line);

		}


		fs.close();
	}

}
