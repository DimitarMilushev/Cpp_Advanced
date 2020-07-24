#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

#include "Company.h"

bool byName (Company& a, Company& b ) 
{
	return a.getName() < b.getName();
}

bool byId(Company& a, Company& b)
{
	return a.getId() < b.getId();
}

std::vector<std::string> getStringLines()
{
	std::vector<std::string> lines;
	
	std::string line;
	while (true)
	{
		std::getline(std::cin, line);

		if (line == "end")
		{
			break;
		}
		std::istringstream lineIn;
		lineIn.clear();
		lineIn.str(line);

		std::string value;
		while (lineIn >> value)
		{
			lines.push_back(value);
		}
	}

	return lines;
}

void sortArray(std::vector<Company>& companies, bool comparator(Company& a, Company& b))
{
	std::sort(companies.begin(), companies.end(), comparator);
}

int main() {

	std::vector<std::string> stringLines = getStringLines();
	std::vector<Company> companies;

	for (size_t i = 0; i < stringLines.size(); i+=2)
	{
			std::string name = stringLines[i];
			int id = stoi(stringLines[i + 1]);

			//companies.push_back(Company(id, name));
			companies.emplace_back(id, name); //Doesn't need to use more memory for a temporary variable
	}

	std::string searchBy;
	std::cin >> searchBy;

	if (searchBy == "id")
	{
		sortArray(companies, byId);
	}
	else if (searchBy == "name")
	{
		sortArray(companies, byName);
	}
	else
	{
		return 0;
	}

	for (Company c : companies)
	{
		std::cout << c.toString() << '\n';
	}
}