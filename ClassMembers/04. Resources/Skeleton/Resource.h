#ifndef RESOURCE_H
#define RESOURCE_H

#include "ResourceType.h"

#include <string>

namespace SoftUni
{
	class Resource
	{
	private:
		int id;
		SoftUni::ResourceType resourceType{};
		std::string link;
	public:
		
		Resource() 
		{
		}

		Resource(int id, SoftUni::ResourceType type, std::string link)
			: id(id), resourceType(type), link(link)
		{
		}

		
		friend std::istream& operator>>(std::istream& input, Resource& obj);
		friend std::ostream& operator<<(std::ostream& output, const Resource& obj);
		bool operator<(const Resource& other) const
		{
			return this->id < other.id;
		}

		SoftUni::ResourceType getType() const 
		{
			return this->resourceType;
		}

		int getId() const
		{
			return this->id;
		}
		
	};

	
	 SoftUni::ResourceType parseType(std::string& input)
	{
		if (input == "Video")
			return SoftUni::ResourceType::VIDEO;
		else if (input == "Presentation")
			return SoftUni::ResourceType::PRESENTATION;
		else
			return SoftUni::ResourceType::DEMO;
	}

	std::istream& operator>>(std::istream& input,  Resource& obj)
	{
		std::string id, type, link;
		input >> id >> type >> link;

		obj.id = std::stoi(id);
		obj.resourceType = parseType(type);
		obj.link = link;
		return input;
	}

	std::ostream& operator<<(std::ostream& output, const Resource& obj)
	{
		output << obj.id << " " << obj.resourceType << " " << obj.link;
		return output;
	}
}

#endif // !RESOURCE_H 
