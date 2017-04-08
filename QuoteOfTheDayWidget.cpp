
#include <string>
#include "QuoteOfTheDayWidget.h"
  
  QuoteOfTheDayWidget::QuoteOfTheDayWidget(){
	  
	quote = "";
	author = "";
	quoteOptionType = "";
}

  QuoteOfTheDayWidget::QuoteOfTheDayWidget(std::string qteTypeOption) {
	quote = "";
	author = "";
	quoteOptionType = qteTypeOption;
}	  

  //QuoteOfTheDayWidget::QuoteOfTheDayWidget(rapidjson::Document configDoc) {

	//quote = "";
	//author = "";
	// todo add in rapidjson call to unpack the joson config string
	//quoteOptionType = "";
//}

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
