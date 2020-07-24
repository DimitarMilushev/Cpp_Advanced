#ifndef SORT_BY_H
#define SORT_BY_H

#include "Company.h"
#include <algorithm>
#include <functional>

bool (*customComparator) (const Company& a, const Company& b);

bool comparator(Company* a, Company* b)
{
	return customComparator(*a, *b);
}

void sortBy(Company** firstCompany, Company** lastCompany, bool (*lessThan)(const Company& a, const Company& b))
{
	customComparator = lessThan;
	std::sort(firstCompany, lastCompany, comparator);
}



#endif // !SORT_BY_H
