#ifndef OPERATORS_H
#define OPERATORS_H

#include <ostream>
#include <vector>
#include <string>
#include <sstream>

std::string operator+ (const std::string& str, const int& number)
{
	return str + std::to_string(number);
}
std::vector<std::string>& operator<<(std::vector<std::string>& container,std::string const &s)
{
	container.push_back(s);

	return container;
}

std::ostream& operator<<(std::ostream& out, std::vector<std::string>& container)
{
	for (std::string str : container)
		out << str << std::endl;

	return out;
}

#endif // !OPERATORS_H
