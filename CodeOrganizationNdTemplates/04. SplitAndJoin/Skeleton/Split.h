#include <vector>
#include <string>

template<typename T>
std::vector<T> split(const std::string& line, const char& separator)
{
	std::stringstream ss(line);
	std::vector<T> splitElements;
	std::string newLine;



	while (std::getline(ss, newLine, separator))
	{
		std::istringstream iss(newLine);
		T element;
		iss >> element;
		splitElements.push_back(element);
	}

	return splitElements;
}