#include <iostream>
#include <string>
#include "promptQuoteOptionType.h"

std::string promptQuoteOptionType() {

std::string userInput;
std::string quoteOptionType;
bool userDone=false;

while (!userDone) {
	std::cout << "The following options are available for the Quote of the Day \n" << std::endl;
	std::cout << "\t 1: Inspire:    Inspiring Quote of the day "<< std::endl;
	std::cout << "\t 2: Management: Management Quote of the day" << std::endl;
	std::cout << "\t 3: Sports:     Sports Quote of the day"<< std::endl;
	std::cout << "\t 4: Life:       Quote of the day about life"<< std::endl;
	std::cout << "\t 5: Funny:      Funny Quote of the day"<< std::endl;
	std::cout << "\t 6: Love:       Quote of the day about Love"<< std::endl;
	std::cout << "\t 7: Art:        Art quote of the day "<< std::endl;
	std::cout << "\t 8: Students:   Quote of the day for students"<< std::endl;
	std::cout << "\t 9: Random:     Quote of the day selected randomly from the above categories (default)"<< std::endl;
	std::cout << "\n Please enter a number 1 - 9 to select your quote type (default 9)" << std::endl;
	
	std::getline (std::cin,userInput);
	char ui;
	ui = userInput[0];

	switch (ui) {
		case '1':
			quoteOptionType = "inspire";
			break;
			
		case '2':			
			quoteOptionType = "management";
			break;
	
		case '3':			
			quoteOptionType = "sports";
			break;

		case '4':			
			quoteOptionType = "life";
			break;

		case '5':			
			quoteOptionType = "funny";
			break;
			
		case '6':			
			quoteOptionType = "love";
			break;
			
		case '7':			
			quoteOptionType = "art";
			break;
			
		case '8':			
			quoteOptionType = "students";
			break;
			
		case '9':			
			quoteOptionType = "";
			break;
			
		default:			
			quoteOptionType = "";
			break;
		}
		
		std::string quoteOptionTypePrompt;
		
		if (quoteOptionType != "") quoteOptionTypePrompt = quoteOptionType;
		else quoteOptionTypePrompt = "random";
		
		std::cout << "You have selected the " << quoteOptionTypePrompt << " type for the quote of the day" << std::endl;
		std::cout << "Would you like to keep this selection? <Y or N> ";
		std::getline (std::cin,userInput);
		
		if (!(userInput == "n"||  userInput == "N")) {
			userDone=true;
		}
	}
	return quoteOptionType;
}
			
		  
