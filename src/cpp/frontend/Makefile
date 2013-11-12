# ====================================================================
# 
#        Filename:  Makefile
# 
#     Description:  Makefile to compile and execute cc/cpp files.
# 
#         Version:  0.7
#         Created:  Saturday 13 July 2013 11:15:42  IST
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

all: $(F_BP)$(SIGNUP) $(F_BP)$(LOGIN) $(F_BP)$(CONFIRM) input-detail.o

#	Target for compiling .cc or .cpp files

$(DATABASE)$(O) : $(D_DATABASE)
	$(CXX) $(CFLAG) $(DATABASE)$(CC) $(LMYSQL)

$(INPUTFIELDNAME)$(O) : $(D_INPUTFIELDNAME)
	$(CXX) $(CFLAG) $(INPUTFIELDNAME)$(CC)

$(READINPUTFIELD)$(O) : $(D_READINPUTFIELD)
	$(CXX) $(CFLAG) $(READINPUTFIELD)$(CC)

$(MD5)$(O) : $(D_MD5)
	$(CXX) $(CFLAG) $(MD5)$(CC)

$(SENDMAIL)$(O) : $(D_SENDMAIL)
	$(CXX) $(CFLAG) $(SENDMAIL)$(CC) $(LSMTP)

$(USER)$(O) : $(D_USER)
	$(CXX) $(CFLAG) $(USER)$(CC) $(LSMTP) $(LMYSQL) $(LCGICC)

$(INPUTDETAIL)$(O) : $(D_INPUTDETAIL)
	$(CXX) $(CFLAG) $(INPUTDETAIL)$(CC) $(LMYSQL) $(LCGICC)


#	Targets for compiling cpp file(main files)

$(SIGNUP)$(MAIN)$(O) : $(D_M_SIGNUP)
	$(CXX) $(CFLAG) $(SIGNUP)$(MAIN)$(CPP) $(LMYSQL)

$(LOGIN)$(MAIN)$(O) : $(D_M_LOGIN)
	$(CXX) $(CFLAG) $(LOGIN)$(MAIN)$(CPP) $(LMYSQL)

$(CONFIRM)$(MAIN)$(O) : $(D_M_CONFIRM)
	$(CXX) $(CFLAG) $(CONFIRM)$(MAIN)$(CPP) $(LMYSQL)

#	Targets for html pages

$(F_BP)$(SIGNUP) : $(L_SIGNUP)
	$(CXX) $(OFLAG) $(F_BP)$(SIGNUP) $(L_SIGNUP) $(LSMTP) \
	$(LMYSQL) $(LCGICC)

$(F_BP)$(LOGIN) : $(L_LOGIN)
	$(CXX) $(OFLAG) $(F_BP)$(LOGIN) $(L_LOGIN) $(LSMTP) \
	$(LMYSQL) $(LCGICC)

$(F_BP)$(CONFIRM) : $(L_CONFIRM)
	$(CXX) $(OFLAG) $(F_BP)$(CONFIRM) $(L_CONFIRM) $(LSMTP) \
	$(LMYSQL) $(LCGICC)

$(CLEAN) : 
	rm -f *.o ../bp/* ../input/*.in ../output/*.out
