#ifndef MAKE_COMPANY_H
#define MAKE_COMPANY_H

#include "Company.h"

Company* makeCompany(std::vector<std::string>& initials)
{
	std::vector<std::pair<char, char> > employees;
	int id = std::stoi(initials[0]);
	std::string name = initials[1];

	if (initials.size() > 2)
	{
		for (int i = 2; i < initials.size(); i++)
		{
			employees.push_back(std::pair<char, char>(initials[i][0], initials[i][1]));
		}
	}
	Company* newCompany = new Company(id, name, employees);
	return newCompany;

	delete newCompany;
}

#endif // !MAKE_COMPANY_H
