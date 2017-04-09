#include <ctime>
#include <iostream>
#include <string>
#include "QuoteOfTheDayWidget.h"
#include "httpreq.h" 
#include "jsonhttpreq.h" 

  QuoteOfTheDayWidget::QuoteOfTheDayWidget(){
	  
	quote = "";
	author = "";
	quoteOptionType = "";
	baseUrl = "http://quotes.rest/qod.json";
	
	time_t rfreshInterval = 24*60*60;		// refresh interval in seconds (24 hours)
	this->setRefreshInterval(rfreshInterval);	
	time_t lstRefreshed = 0;
	this->setLastRefreshed(lstRefreshed);
}

  QuoteOfTheDayWidget::QuoteOfTheDayWidget(std::string qteTypeOption) {
	quote = "";
	author = "";
	
	time_t rfreshInterval = 24*60*60;		// refresh interval in seconds (24 hours)
	this->setRefreshInterval(rfreshInterval); 
	time_t lstRefreshed = 0;
	this->setLastRefreshed(lstRefreshed);
	
	quoteOptionType = qteTypeOption;
	if (qteTypeOption != "")
		baseUrl = "http://quotes.rest/qod.json?category="+qteTypeOption;
	else
		baseUrl = "http://quotes.rest/qod.json";
}	  

  QuoteOfTheDayWidget::~QuoteOfTheDayWidget(){}

  void QuoteOfTheDayWidget::configure() {
// I'm not sure what this method is supposed to do

  }
   
  std::string QuoteOfTheDayWidget::getConfiguration() {
// I'm not sure what this method is supposed to do
	  std::string result = " ";
	  return result;
  } 

 std::string QuoteOfTheDayWidget::refreshData() {
	 
	// refreshData is only called from the parent class refresh method
	// refresh is responsible for checking to see if it is time to refresh
	// this method always refreshes and does not check the time interval
	// the method does update its refreshed time

	 JSONHTTPReq req = JSONHTTPReq(); 
	 
     std::string url = baseUrl; 
     
     std::cout << "url " << url << std::endl;
     
     req.setUrl(url); 
     req.send(); 
        
     nlohmann::json json = req.getJSONResponse(); 
	 
     nlohmann::json transformedJson = transformResponse(json); 
     
     time_t curTime = time(0);			// get current time
     this->setLastRefreshed(curTime);	// save the time in the lastRefreshed variable
          
     return transformedJson.dump(4); 
    
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
 
    quote = response["contents"]["quotes"][0]["quote"]; 
	author = response["contents"]["quotes"][0]["author"];

     nlohmann::json data = { 
             {"quote",quote}, 
             {"author", author} 
     }; 
 
     nlohmann::json json = { 
             {"name", "Quote"}, 
             {"data", data} 
     }; 
  
     return json; 
 }; 
