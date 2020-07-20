#ifndef PARSE_COMPANIES_H
#define PARSE_COMPANIES_H

#include "Company.h"
#include <iterator>
#include <unordered_set>

Company* parseUniqueCompanies(std::string input, int& numOfCompanies, std::string byIdentifier(const Company& c))
{
	std::istringstream iss(input);
	std::vector<std::string> initials(std::istream_iterator<std::string>{iss},
		std::istream_iterator<std::string>());

	//	boost::split(results, text, [](char c) {return c == ' ';});

	std::vector<Company> companies;
	std::unordered_set<std::string> identifiers;

	for (size_t i = 0; i < initials.size(); i += 2)
	{
		int id = std::stoi(initials[i]);
		std::string name = initials[i + 1];
		Company newCompany = Company(id, name);

		if (identifiers.insert(byIdentifier(newCompany)).second)
		{
			companies.push_back(newCompany);
		}
	}

	numOfCompanies = companies.size();
	auto uniqueCompanies = new Company[numOfCompanies];
	std::copy(companies.begin(), companies.end(), uniqueCompanies);

	return uniqueCompanies;
}


#endif // !PARSE_COMPANIES_H

//123 valid
//123 copy
//321 ancientmarinerinc
//end
//1
