#ifndef REMOVE_DUPLICATES_H
#define REMOVE_DUPLICATES_H

#include "Company.h"
#include <vector>
#include <algorithm>
#include <list>
#include <set>

bool hasName(std::set<std::string>& uniqueNames, const std::string& name)
{
	if (std::binary_search(uniqueNames.begin(), uniqueNames.end(), name))
	{
		return true;
	}

	return false;
}

void removeDuplicates(std::list<Company*>& companies)
{
	std::set<std::string> uniqueNames;
	std::list<Company*>::iterator it = companies.begin();
	
	for (it; it != companies.end();)
	{
		std::string name = (*it)->getName();

		if (hasName(uniqueNames, name))
		{
			Company** duplicate = &(*it);

			it = companies.erase(it);
			//delete duplicate;
		}
		else
		{
			uniqueNames.insert(name);
			++it;
		}
	}

	/*companies.sort();
	companies.unique();*/
}



#endif // !REMOVE_DUPLICATES_H
