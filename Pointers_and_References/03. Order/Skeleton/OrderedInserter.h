#ifndef ORDERED_INSERTER_H 
#define ORDERED_INSERTER_H

#include <vector>
#include "Company.h"

class OrderedInserter
{
public:
	OrderedInserter(std::vector<const Company*>& c) : companies(c) {}

	void insert(const Company* newCompany)
	{
		if (!companies.empty())
		{
			int it = 0;
			for (const Company* c : this->companies)
			{
				if ((*c).getId() > (*newCompany).getId())
				{
					this->companies.insert(this->companies.begin() + it, newCompany);
					return;
				}	

				it++;
			}

			this->companies.push_back(newCompany);
		}
		else
		{
			this->companies.push_back(newCompany);
		}
	}
private:
	std::vector<const Company*>& companies;

};

#endif // !ORDERED_INSERTER_H
