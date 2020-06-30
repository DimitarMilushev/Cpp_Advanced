#ifndef FIND_H
#define FIND_H

#include "Company.h"

Company* find(const std::vector<Company*>& companies, int id)
{
	for (Company* c : companies)
	{
		if ((*c).getId() == id)
			return c;
	}

	return nullptr;
}

#endif // !FIND_H