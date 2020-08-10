template<typename T>
struct LessThan
{
	bool operator()(const T& firstElement, const T& secondElement)
	{
		return firstElement < secondElement;
	}
};

template<typename T, typename Comparator>
struct Reverse
{
	bool operator()(const T& firstElement, const T& secondElement) const
	{
		Comparator comp;
		return !comp(firstElement, secondElement);
	}
};