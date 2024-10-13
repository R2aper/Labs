# Compiler settings
CC = g++
CXXFLAGS = -std=c++11 -Wall -Werror -Wextra -Wpedantic -Wconversion

# Makefile settings
APPNAME = Lab7

build: 
	$(CC) -c $(CXXFLAGS) src/mylib.cpp -o  obj/mylib.o
	$(CC) -c $(CXXFLAGS) src/Lab7.cpp -o obj/Lab7.o
	$(CC) $(CXXFLAGS) obj/mylib.o obj/Lab7.o -o $(APPNAME) 

################### Cleaning rules for Unix-based OS ###################
cleanu:
	rm obj/*.o	
	rm $(APPNAME)

#################### Cleaning rules for Windows OS #####################
cleanw:
	del obj\*.o
	del $(APPNAME).exe	