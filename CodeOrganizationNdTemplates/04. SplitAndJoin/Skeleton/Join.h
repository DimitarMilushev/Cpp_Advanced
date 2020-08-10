#include <sstream>
#include <string>
#include <vector>

template<typename T>
std::string join(std::vector<T> elements, std::string joinStr)
{
	std::ostringstream joinedElements;

	for (size_t i = 0; i < elements.size() - 1; i++)
	{
		joinedElements << elements[i] << joinStr;
	}
	
	joinedElements << elements[elements.size() - 1]; //So i doesn't do unnecessary operations.

	return joinedElements.str();
}