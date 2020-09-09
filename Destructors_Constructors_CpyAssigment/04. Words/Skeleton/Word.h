#ifndef WORD_H
#define WORD_H

#include <string>
#include <unordered_map>

std::unordered_map <std::string, size_t> words{};

class Word
{
	std::string word;

public:
	Word(std::string word) : word(word)
	{
		++words[this->word];
	}

	std::string getWord() const
	{
		return this->word;
	}
	size_t getCount() const
	{
		size_t count = words[this->word];
		words.erase(this->word);
		return count;
	}

	bool operator <(const Word& other) const
	{
		if (this->getWord() < other.getWord())
			return true;
		return false;
	}
};

#endif // !WORD_H