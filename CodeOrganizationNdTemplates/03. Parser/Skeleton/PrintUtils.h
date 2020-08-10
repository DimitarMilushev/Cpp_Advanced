#ifndef PRINTUTILS_H
#define PRINTUTILS_H
#include <iostream>
#include <vector>

template<typename T>
void printVector(std::vector<T> container)
{
	for (T& element : container)
	{
		std::cout << element << ' ';
	}
}

#endif // !PRINTUTILS_H
