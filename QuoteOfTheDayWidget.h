#include <string>

#ifndef QUOTEOFDAY_QUOTEOFDAY_H 
#define QUOTEOFDAY_QUOTEOFDAY_H


//class QuoteOfTheDayWidget:public ApiWidget {
class QuoteOfTheDayWidget {
  
public:
  
  QuoteOfTheDayWidget();
  QuoteOfTheDayWidget(std::string quoteTypeOption);
  //QuoteOfTheDayWidget(rapidjson::Document configDoc);
  
  std::string getQuote();
  void setQuote(std::string quote);
  
  std::string getAuthor();
  void setAuthor(std::string author);
  
  std::string getQuoteTypeOption();
  void setQuoteTypeOption(std::string quoteTypeOption);
  
private:
  std::string quote;
  std::string author;
  std::string quoteOptionType;
  
};


#endif //QUOTEOFDAY_QUOTEOFDAY_H
