#ifndef COMPANYMEMORYUTILS_H
#define COMPANYMEMORYUTILS_H

typedef unsigned char byte;

std::string getName(byte* memory, int& pos)
{
	std::ostringstream name;
	while (memory[pos] != '\0')
	{
		name << memory[pos];
		pos++;
	}
	pos++;

	return name.str();
}
std::vector<std::pair<char, char>> getEmployees(byte* memory, int& pos, const int& count)
{
	std::vector<std::pair<char, char>> empCollection;

	for (int i = 0; i < count; i++)
	{
		std::pair<char, char> employee;

		employee.first = memory[pos];
		pos++;

		employee.second = memory[pos];
		pos++;

		empCollection.push_back(employee);
	}
	return empCollection;
}

std::vector<Company> readCompaniesFromMemory(byte* memory, int numCompanies)
{
	std::vector<Company> companies;
	int pos = 0;
	for (int i = 0; i < numCompanies; i++)
	{
		int id = memory[pos];
		pos++;

		std::string name = getName(memory, pos);
		int employeesCount = memory[pos];
		pos++;

		std::vector<std::pair<char, char> > employees = getEmployees(memory, pos, employeesCount);

		Company newCompany = Company(id, name, employees);
		companies.push_back(newCompany);
	}
	
	
	return companies;
}
#endif // !COMPANYMEMORYUTILS_H
