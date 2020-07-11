#ifndef MIN_BY_H
#define MIN_BY_H

std::string minBy(std::vector<std::string> values, bool (*mode)(const std::string&,const std::string&))
{
	std::string target = values[0];

	if (values.size() > 1)
	{
		for (size_t i = 1; i < values.size(); i++)
		{
			if ((*mode)(values[i], target))
			{
				target = values[i];
			}
		}
	}

	return target;
}

#endif // !MIN_BY_H
