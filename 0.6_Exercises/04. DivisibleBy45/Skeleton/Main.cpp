#include "BigInt.h"
#include <iostream>

size_t sumOfDigits(const BigInt& num);
void findSuitableStart(BigInt& num);

int main()
{
	const BigInt numToDivideBy = 45;
	BigInt start, end;
	std::string input;

	std::cin >> input;
	start = input;

	std::cin >> input;
	end = input;
	
	findSuitableStart(start);

	for (BigInt i = start; i < end; i += numToDivideBy)
	{
		std::cout << i << '\n';
	}
	return 0;
}

size_t sumOfDigits(const BigInt& num)
{
	size_t sum = 0;
	std::string start = num.getDigits();
	for (char digit : start) {
		sum += digit - '0';
	}

	return sum;
}

void findSuitableStart(BigInt& num)
{
	std::string start = num.getDigits();
	const int endDigit = start[start.size() - 1] - '0';
	if (endDigit != 0 && endDigit != 5) {
		if (endDigit > 5) {
			num += BigInt(10 - endDigit);
		}
		else {
			num += BigInt(5 - endDigit);
		}
	}

	const BigInt five(5);

	size_t sum = sumOfDigits(num);
	while (sum % 9 != 0) {
		num += five;
		sum = sumOfDigits(num.getDigits());
	}

}