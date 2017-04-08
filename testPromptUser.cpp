#include <iostream>
#include <string>
#include "promptQuoteOptionType.h"

int main() {

	std::string quoteOptionType;

	quoteOptionType = promptQuoteOptionType();

	std::cout << "\nThe quote type string returned is: " << quoteOptionType << std::endl;
	
	return 0;
}
