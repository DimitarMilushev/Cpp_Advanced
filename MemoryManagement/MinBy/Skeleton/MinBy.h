#ifndef MIN_BY_H
#define MIN_BY_H


std::string minBy(const std::vector<std::string>& values, bool(*compare)(const std::string&, const std::string&))
{
	std::string minString = values[0];

	for (int i = 1; i < values.size();i ++)
	{
		std::string word = values[i];

		if (!compare(minString, word))
		{
			minString = word;
		}
	}

	return minString;
}
#endif // !MIN_BY_H
