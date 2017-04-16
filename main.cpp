// this is a test program for the quote of the day widget
// it shows that the widget can be configured, can access the quote web site, and updates its refresh time when refreshed
// note that this program can be run only 10 times in one hour due to the access restrictions on the web site

#include <iostream>
#include "widgets/QuoteOfTheDayWidget.h"
#include <ctime>
#include <chrono>
#include <thread>
#include "include/json.hpp"

std::string promptQuoteOptionType();

int main() {
	
    
    QuoteOfTheDayWidget qod = QuoteOfTheDayWidget();
    qod.config();
    
    nlohmann::json qodJson;						// JSON string to be returned to the mirror
    
    time_t curTime;
    time_t lastTime;
    time_t interval = qod.getRefreshInterval();
    
    for (int i=0; i < 2; i++) {
		curTime = time(0);   						// current time in seconds since January 1, 1970
		lastTime = qod.getLastRefreshed();			// last time qod was refreshed
		
		if ((curTime - lastTime) >= interval) {		// only invoke the QOD refresh if it is time to update (max allowed is 10 per hour)
			//qodJson = qod.refreshData();
			std::string jsonString = qod.refresh();
			std::cout << "QOD returned json " << jsonString << std::endl;		// this is the JSON string that will be returned to the mirror
		}
		
		std::cout << "\nThe quote of the day is: " << qod.getQuote() << std::endl;			// this is the quote of the day 
		std::cout << "\nThe quote of the day author is: " << qod.getAuthor() << std::endl;	// this is the author of the quote of the day 
		
			
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));	}
	    
 

    return 0;
}




			
		  


