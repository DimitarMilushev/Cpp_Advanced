#ifndef REMOVE_INVALID_H
#define REMOVE_INVALID_H

#include "Company.h"
#include <list>

void removeInvalid(std::list<Company*>& companies)
{
	companies.remove_if([](Company* company) {
		if (company->getId() < 0) {
			delete company;
			return true;
		}
		return false;
		});
}

#endif // !REMOVE_INVALID_H
