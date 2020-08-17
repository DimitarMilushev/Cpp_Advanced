#include "Echo.h"
#include <string>
#include <iostream>

bool echoOn = false;

void echo(std::string input)
{
	if (echoOn)
		std::cout << input << '\n';
}