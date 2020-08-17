#ifndef VECTORCOMPARISONS_H
#define VECTORCOMPARISONS_H

#include "Vector.h"

template<typename T, typename Comparator>
struct ReverseComparer
{
	Comparator comp;
	const bool operator()(const T& firstVector, const T& secondVector ) const
	{
		return comp(firstVector, secondVector);
	}
};

struct VectorLengthComparer
{
	const bool operator()(const Vector& firstElement, const Vector& secondElement) const 
	{
		return  firstElement.getLength() > secondElement.getLength();
	}
};
#endif // !VECTORCOMPARISONS_H