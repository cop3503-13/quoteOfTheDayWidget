INCLUDEOBJS = include/date.o include/common.o include/valid.o include/httpreq.o include/jsonhttpreq.o
WIDGETSOBJS = widgets/QuoteOfTheDayWidget.o widgets/Widget.o
OBJS = $(WIDGETSOBJS) $(INCLUDEOBJS) main.o


CC = g++
CFLAGS = -Wall -std=c++11 -c
LFLAGS = -Wall -std=c++11
IDIR = -I./
LD = -lcurl



widgets/QuoteOfTheDayWidget.o : include/httpreq.o include/jsonhttpreq.o include/common.o include/valid.o include/date.o
	$(CC) $(CFLAGS) $(IDIR) widgets/QuoteOfTheDayWidget.cpp -o widgets/QuoteOfTheDayWidget.o 
	
	
	
	
include/jsonhttpreq.o : include/httpreq.o
	$(CC) $(CFLAGS) $(IDIR) include/jsonhttpreq.cpp -o include/jsonhttpreq.o
	
include/httpreq.o :
	$(CC) $(CFLAGS) $(IDIR) include/httpreq.cpp -o include/httpreq.o

widgets/Widget.o :
	$(CC) $(CFLAGS) $(IDIR) widgets/Widget.cpp -o widgets/Widget.o


include/valid.o :
	$(CC) $(CFLAGS) $(IDIR) include/valid.cpp -o include/valid.o

include/date.o :
	$(CC) $(CFLAGS) $(IDIR) include/date.cpp -o include/date.o
	
include/common.o :
	$(CC) $(CFLAGS) $(IDIR) include/common.cpp -o include/common.o

main.o : $(INCLUDEOBJS) $(WIDGETSOBJS)
	$(CC) $(CFLAGS) $(IDIR) main.cpp

main : $(OBJS)
	$(CC) $(LFLAGS) $(IDIR) $(OBJS) $(LD) -o main.out
	


clean :
	\rm -fvr *.o *.out *~ include/*.o include/*.out include/*~ widgets/*.o widgets/*.out widgets/*~
