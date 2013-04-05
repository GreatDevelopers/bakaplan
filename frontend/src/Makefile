# ====================================================================
# 
#        Filename:  Makefile
# 
#     Description:  Makefile to compile and execute cc/cpp files.
# 
#         Version:  0.6
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

all: $(LOGIN)$(HTML)

#$(DATABASE)$(O) $(INPUTFIELDNAME)$(O) $(READINPUTFIELD)$(O) $(MD5)$(O) $(JAVASCRIPT)$(O) $(PAGELAYOUT)$(O) $(PAGESTRUCTURE)$(O) $(INPUTDETAIL)$(O)

#$(READINPUT)$(O)

#	Target for compiling .cc or .cpp files

$(DATABASE)$(O) : $(D_DATABASE)
	$(CXX) $(CFLAG) $(DATABASE)$(CC) $(LMYSQL)

$(INPUTFIELDNAME)$(O) : $(D_INPUTFIELDNAME)
	$(CXX) $(CFLAG) $(INPUTFIELDNAME)$(CC)

$(READINPUTFIELD)$(O) : $(D_READINPUTFIELD)
	$(CXX) $(CFLAG) $(READINPUTFIELD)$(CC)

$(MD5)$(O) : $(D_MD5)
	$(CXX) $(CFLAG) $(MD5)$(CC)

$(JAVASCRIPT)$(O) : $(D_JAVASCRIPT)
	$(CXX) $(CFLAG) $(JAVASCRIPT)$(CC)

$(PAGELAYOUT)$(O) : $(D_PAGELAYOUT)
	$(CXX) $(CFLAG) $(PAGELAYOUT)$(CC)

$(PAGESTRUCTURE)$(O) : $(D_PAGEsTRUCTURE)
	$(CXX) $(CFLAG) $(PAGESTRUCTURE)$(CC)

$(INPUTDETAIL)$(O) : $(D_INPUTDETAIL)
	$(CXX) $(CFLAG) $(INPUTDETAIL)$(CC) $(LMYSQL)

$(LOGIN)$(O) : $(D_LOGIN)
	$(CXX) $(CFLAG) $(LOGIN)$(CC) $(LMYSQL)

#	Targets for compiling cpp file(main files)

$(LOGIN)$(MAIN)$(O) : $(D_LOGIN_M)
	$(CXX) $(CFLAG) $(LOGIN)$(MAIN)$(CPP) $(LMYSQL)

#	Targets for html pages

$(LOGIN)$(HTML) : $(L_LOGIN)
	$(CXX) $(OFLAG) $(LOGIN)$(HTML) $(L_LOGIN) $(LMYSQL) $(LCGICC)

$(CLEAN) : 
	rm -f *.o *.html
