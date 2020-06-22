#include <string>
#ifndef TRYPARSE_H
#define TRYPARSE_H

bool tryParse(const std::string& text, int& num)
{
	try
	{
		num = std::stoi(text);
		return true;
	}
	catch (std::exception e)
	{
		return false;
	}
}

#endif
