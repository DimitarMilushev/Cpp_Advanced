#include <istream>
#include <sstream>

template<typename T>
class Parser
{
	private:
		std::istream& in;
		std::string stopLine;
public:
	Parser(std::istream& in, std::string stopLine) : in(in), stopLine(stopLine)
	{
	}

	bool readNext(T& element)
	{
		std::string line;
		std::getline(in, line);
		if (line != this->stopLine)
		{
			std::istringstream str(line);
			str >> element;
			return true;
		}
		
		return false;
	}

};
