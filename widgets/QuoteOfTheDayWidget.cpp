#include <ctime>
#include <iostream>
#include <string>
#include "QuoteOfTheDayWidget.h"
#include "../include/httpreq.h" 
#include "../include/jsonhttpreq.h" 

  QuoteOfTheDayWidget::QuoteOfTheDayWidget(){
	  
	quote = "";
	author = "";
	quoteOptionType = "";
	baseUrl = "http://quotes.rest/qod.json";
	
	time_t rfreshInterval = 24*60*60;		// overriding default refresh interval of 10 minutes to 24 hours
	this->setRefreshInterval(rfreshInterval);	
	time_t lstRefreshed = 0;
	this->setLastRefreshed(lstRefreshed);
}

  QuoteOfTheDayWidget::QuoteOfTheDayWidget(std::string qteTypeOption) {
	quote = "";
	author = "";
	
	time_t rfreshInterval = 24*60*60;		// overriding default refresh interval of 10 minutes to 24 hours
	this->setRefreshInterval(rfreshInterval); 
	time_t lstRefreshed = 0;
	this->setLastRefreshed(lstRefreshed);
	
	quoteOptionType = qteTypeOption;
	if (qteTypeOption != "")
		baseUrl = "http://quotes.rest/qod.json?category="+qteTypeOption;
	else
		baseUrl = "http://quotes.rest/qod.json";
}	  

	QuoteOfTheDayWidget::QuoteOfTheDayWidget(nlohmann::json conf) {
	quote = "";
	author = "";
	
	time_t rfreshInterval = 24*60*60;		// overriding default refresh interval of 10 minutes to 24 hours
	this->setRefreshInterval(rfreshInterval); 
	time_t lstRefreshed = 0;
	this->setLastRefreshed(lstRefreshed);
	std::string qteTypeOption = conf["quoteOptionType"];
	
	quoteOptionType = qteTypeOption;
	if (qteTypeOption != "")
		baseUrl = "http://quotes.rest/qod.json?category="+qteTypeOption;
	else
		baseUrl = "http://quotes.rest/qod.json";
}	  

  QuoteOfTheDayWidget::~QuoteOfTheDayWidget(){}		//destructor

  nlohmann::json QuoteOfTheDayWidget::getConfigurationJson() {
		nlohmann::json conf = { 						//creates a configuration json conf
             {"name", "QuoteOfTheDay"}, 
             {"configuration", {
									{"quoteOptionType", this->getQuoteTypeOption()}
								}} 
     };
		return conf;
	} 
	

  void QuoteOfTheDayWidget::configure() {  // this is the part that prompts the user asking for the quote type
		//std::string quoteTypeOption = promptQuoteOptionType();
		//std::string promptQuoteOptionType() {
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
				}	//end of switch statement

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
			//return quoteOptionType;
		//}		
			//	std::string result = " ";
				//return result;

			std::string quoteTypeOption = quoteOptionType;
			quoteOptionType = quoteTypeOption;
			if (quoteOptionType != "")
				baseUrl = "http://quotes.rest/qod.json?category="+quoteOptionType;
			else
				baseUrl = "http://quotes.rest/qod.json";
 	 }
   
  std::string QuoteOfTheDayWidget::getConfiguration() {
		return quoteOptionType;
	}

 nlohmann::json QuoteOfTheDayWidget::refreshData() {
	 
	// refreshData is only called from the parent class's refresh method
	// refresh is responsible for checking to see if it is time to refresh
	// this method always refreshes and does not check the time interval
	// the method does update its refreshed time

	 JSONHTTPReq req = JSONHTTPReq(); 
	 
     std::string url = baseUrl; 
     
     //std::cout << "url " << url << std::endl;
     
     req.setUrl(url); //sets the URL
     req.send(); 	  //sends out the URL and receives the response from the website
        
     nlohmann::json json = req.getJSONResponse(); //gets the response that was returned
	 
     nlohmann::json transformedJson = transformResponse(json); //extracts the desired data from the json that the website returned and puts it back into a simpler json
     
     //Base class also sets LastRefreshed time
     //time_t curTime = time(0);			// get current time
     //this->setLastRefreshed(curTime);	// save the time in the lastRefreshed variable
          
     return transformedJson; //returns the json to the calling function as a regular string
    
}

std::string QuoteOfTheDayWidget::QuoteOfTheDayWidget::getQuote(){
	return quote;
}

  void QuoteOfTheDayWidget::setQuote(std::string quoteStr) {
	  quote = quoteStr;
  }
  
  std::string QuoteOfTheDayWidget::getAuthor() {
	  return author;
  }
  
  void QuoteOfTheDayWidget::setAuthor(std::string authorStr) {
	  author = authorStr;
  }
  
  std::string QuoteOfTheDayWidget::getQuoteTypeOption() {
	  return quoteOptionType;
  }
  
  void QuoteOfTheDayWidget::setQuoteTypeOption(std::string quoteTypeOptionStr) {
	  quoteOptionType = quoteTypeOptionStr;
  }

nlohmann::json QuoteOfTheDayWidget::transformResponse(nlohmann::json response) 
  { 
 
    quote = response["contents"]["quotes"][0]["quote"];  //accesses the quote and author from json that the website returned
	author = response["contents"]["quotes"][0]["author"];

     nlohmann::json data = { //creates the new, simpler json data containing only the desired information
             {"quote",quote}, 
             {"author", author} 
     }; 
 
     nlohmann::json json = {  //creates the actual json object using the data that was just created
             {"name", "Quote"}, 
             {"data", data} 
     }; 
  
     return json; 
 }; 
