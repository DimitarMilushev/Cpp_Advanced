#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <sstream>
#include <map>


bool isIn(const std::map<int, int>& fromRange,
	      const std::map<int, int>& toRange,
		  const int& number)
{
	 auto fromIt = fromRange.upper_bound(number);
     auto toIt = toRange.lower_bound(number);

	if (fromIt != fromRange.begin() && ((--fromIt)->second == toIt->second))
	{
		return true;
	}
	else
	{
		return false;
	}

	
}

std::string getResult(std::map<int, int>& rangesFrom,
						std::map<int, int>& rangesTo,
						int& number)
{
	if (isIn(rangesFrom, rangesTo, number))
		return "in";

	return "out";
}

int main() {

	std::ostream::sync_with_stdio(false);
	std::istream::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string line;
	std::istringstream ss;
	int from;
	int to;
	
	std::map<int, int> mapFrom;
	std::map<int, int> mapTo;
	int range = 0;
	while (std::getline(std::cin, line) && line != ".")
	{

		ss.clear();
		ss.str(line);
		ss >> from >> to;

		mapFrom[from] = range;
		mapTo[to] = range;
		++range;
	}

	int number;
	while (getline(std::cin, line) && line != ".") {
		
		ss.clear();
		ss.str(line);
		ss >> number;

		std::cout << getResult(mapFrom, mapTo, number) << '\n';
	}


}

