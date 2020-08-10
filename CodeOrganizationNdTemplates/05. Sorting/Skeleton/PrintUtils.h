#ifndef PRINTUTILS_H
#define PRINTUTILS_H

#include <iostream>

template<typename T>
void printContainer(typename T::iterator start, typename T::iterator end)
{
	while (start != end)
	{
		std::cout << (*start) << ' ';
		++start;
	}
}

#endif // !PRINTUTILS_H
