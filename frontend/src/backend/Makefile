# ====================================================================
# 
#        Filename:  Makefile
# 
#     Description:  Makefile to compile and execute cc/cpp files.
# 
#         Version:  0.7
#         Created:  Saturday 30 February 2013 11:15:42  IST
#        Compiler:  g++
# 
#          Author:  Mandeep Kaur, meghasimak@gmail.com
#         License:  GNU General Public License
#       Copyright:  Copyright (c) 2013, Great Developers
#                   https://github.com/GreatDevelopers 
# 
# ====================================================================

# ====================================================================
#   Including file Make.common file for variable declaration
# ====================================================================

include Make.common

# ====================================================================
#   Targets
# ====================================================================

all : main
#$(READINPUT)$(O)

#	Target for compiling .cc or .cpp files

$(DB): $(D_DB)
	$(CXX) $(CFLAG) ../database.cc $(LMYSQL)

$(READINPUT)$(O) : $(D_READINPUT)
	$(CXX) $(CFLAG) $(READINPUT)$(CC)

$(EXPANDROLLNO)$(O) : $(D_EXPANDROLLNO)
	$(CXX) $(CFLAG) $(EXPANDROLLNO)$(CC)

$(ARRANGEROLLNO)$(O) : $(D_ARRANGEROLLNO)
	$(CXX) $(CFLAG) $(ARRANGEROLLNO)$(CC)

$(DATESHEET)$(O) : $(D_DATESHEET)
	$(CXX) $(CFLAG) $(DATESHEET)$(CC)

$(SEATPLAN)$(O) : $(D_SEATPLAN)
	$(CXX) $(CFLAG) $(SEATPLAN)$(CC) $(LMYSQL)

$(STRATEGY)$(O) : $(D_STRATEGY)
	$(CXX) $(CFLAG) $(STRATEGY)$(CC) $(LMYSQL)

main.o: main.cpp $(H_DATESHEET) $(H_STRATEGY)
	$(CXX) $(CFLAG) main.cpp $(LMYSQL)

main: $(L_DATESHEET) $(L_STRATEGY) main.o
	$(CXX) $(OFLAG) main $(L_DATESHEET) $(L_STRATEGY) main.o $(LMYSQL)

run : main
	./main

$(CLEAN) : 
	rm -f *.o main
