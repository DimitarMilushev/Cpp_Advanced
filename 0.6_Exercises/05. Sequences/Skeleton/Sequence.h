#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <vector>
#include <iostream>

template<typename T>
struct Iterator
{
private:
	static const int END_ITERATOR_INDEX = -1;
	std::vector<T>& elements;

	int next;
	Iterator(std::vector<T>& elements, int next) : elements(elements), next(next) {}

public:
	
	static Iterator begin(std::vector<T>& elements)
	{
		if (elements.size() == 0)
			return end(elements);

		return Iterator(elements, 0);
	}

	static Iterator end(std::vector<T>& elements)
	{
		return Iterator(elements, END_ITERATOR_INDEX);
	}

	const bool operator !=(const Iterator& it) const 
	{
		return this->elements != it.elements || this->next != it.next;
	}

	Iterator& operator++()
	{
		++this->next;
		if (this->next >= this->elements.size())
		{
			this->next = END_ITERATOR_INDEX;
		}

		return *this;
	}
	
	T& operator*() const
	{
			return this->elements.at(this->next);
	}
};


template<typename T, typename Generator>
struct Sequence
{
private:
	Generator generator;
	std::vector<T> elements; 
public:
	void generateNext(const int& numToGenerate)
	{
		if (numToGenerate < 1)
			return;
		
		for (size_t i = 0; i < numToGenerate; ++i)
		{
			
			this->elements.push_back(this->generator());
		}
	}

	Iterator<T> begin() 
	{
		return Iterator<T>::begin(this->elements);
	}

	Iterator<T> end() 
	{
		return Iterator<T>::end(this->elements);
	}
};

#endif // !SEQUENCE_H
