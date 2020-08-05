#ifndef LECTURE_H
#define LECTURE_H

#include "Resource.h"
#include <set>
#include <vector>

namespace SoftUni
{
	class Lecture
	{
	private:
		std::set<SoftUni::Resource> resources;
		std::map<SoftUni::ResourceType, int> resourceTypes;
	public:
		Lecture()
		{
		}

		Lecture operator<<(const SoftUni::Resource& r)
		{
			if (this->resources.erase(r) == 0)
			{
				this->resourceTypes[r.getType()]++;
			}

			this->resources.insert(r);

			return *this;
		}

		int operator[](const SoftUni::ResourceType type)
		{
			return resourceTypes[type];
		}

		std::set<SoftUni::Resource>::iterator begin()
		{
			return this->resources.begin();
		}
		std::set<SoftUni::Resource>::iterator end()
		{
			return this->resources.end();
		}
		friend std::vector<SoftUni::ResourceType>& operator<<
			(std::vector<SoftUni::ResourceType>& resTypes, const Lecture& lecture);

	};
	
	std::vector<SoftUni::ResourceType>& operator<<(std::vector<SoftUni::ResourceType>& resTypes, const Lecture& lecture)
	{
		for(std::pair<SoftUni::ResourceType, int> p : lecture.resourceTypes)
		{
			resTypes.push_back(p.first);
		}
		return resTypes;
	}
}
#endif // !LECTURE_H
