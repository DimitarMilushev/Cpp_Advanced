#ifndef SUMOFVECTORS_H
#define SUMOFVECTORS_H

#include <vector>
#include <string>

std::vector<std::string> operator+(std::vector<std::string> objects, std::vector<std::string> values)
{
	std::vector<std::string> concatinatedVector;
	for (int i = 0; i < objects.size(); i++)
	{
		concatinatedVector.push_back(objects[i] + " " + values[i]);
	}

	return concatinatedVector;
}

#endif // !SUMOFVECTORS_H
