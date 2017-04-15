
#ifndef QUOTEOFDAY_QUOTEOFDAY_H 
#define QUOTEOFDAY_QUOTEOFDAY_H

#include <string>
#include "Widget.h" 
#include "include/json.hpp" 
 
class QuoteOfTheDayWidget : public Widget { 
  
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
  
  void configure() override; 
  std::string getConfiguration() override; 
  std::string refreshData() override; 
  
  ~QuoteOfTheDayWidget();

private:
  std::string quote;
  std::string author;
  std::string quoteOptionType;
  std::string baseUrl;

  nlohmann::json transformResponse(nlohmann::json response);
  
  
};


#endif //QUOTEOFDAY_QUOTEOFDAY_H
