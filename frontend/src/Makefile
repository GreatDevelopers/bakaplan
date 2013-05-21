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

all: back $(F_BP)$(LOGIN)$(HTML) $(F_BP)$(REGISTER)$(HTML) $(F_BP)$(RESET)$(HTML) $(F_BP)$(NEWUSER)$(HTML) $(F_BP)$(CONFIRM)$(HTML) $(F_BP)$(ADDUSER)$(HTML) $(F_BP)$(PROJECT)$(HTML) $(F_BP)$(LOGOUT)$(HTML) $(F_BP)$(CLASS)$(HTML) $(F_BP)$(ROLLNO)$(HTML) $(F_BP)$(DATESHEET)$(HTML) $(F_BP)$(EXAM)$(HTML) $(F_BP)$(ADDROOM)$(HTML) $(F_BP)$(ROOM)$(HTML) $(F_BP)$(STRATEGY)$(HTML) $(F_BP)$(VALIDSTRATEGY)$(HTML) $(F_BP)$(REPORT)$(HTML)

back:
	make -C backend

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

$(PAGESTRUCTURE)$(O) : $(D_PAGESTRUCTURE)
	$(CXX) $(CFLAG) $(PAGESTRUCTURE)$(CC)

$(INPUTDETAIL)$(O) : $(D_INPUTDETAIL)
	$(CXX) $(CFLAG) $(INPUTDETAIL)$(CC) $(LMYSQL)

$(SENDMAIL)$(O) : $(D_SENDMAIL)
	$(CXX) $(CFLAG) $(SENDMAIL)$(CC) $(LSMTP)

$(LOGIN)$(O) : $(D_LOGIN)
	$(CXX) $(CFLAG) $(LOGIN)$(CC) $(LMYSQL)

$(PROJECT)$(O) : $(D_PROJECT)
	$(CXX) $(CFLAG) $(PROJECT)$(CC) $(LMYSQL)

$(CLASS)$(O) : $(D_CLASS)
	$(CXX) $(CFLAG) $(CLASS)$(CC) $(LMYSQL)

$(ROLLNO)$(O) : $(D_ROLLNO)
	$(CXX) $(CFLAG) $(ROLLNO)$(CC) $(LMYSQL)

$(DATESHEET)$(O) : $(D_DATESHEET)
	$(CXX) $(CFLAG) $(DATESHEET)$(CC) $(LMYSQL)

$(EXAM)$(O) : $(D_EXAM)
	$(CXX) $(CFLAG) $(EXAM)$(CC) $(LMYSQL)

$(ROOM)$(O) : $(D_ROOM)
	$(CXX) $(CFLAG) $(ROOM)$(CC) $(LMYSQL)

$(STRATEGY)$(O) : $(D_STRATEGY)
	$(CXX) $(CFLAG) $(STRATEGY)$(CC) $(LMYSQL)

$(VALIDSTRATEGY)$(O) : $(D_VALIDSTRATEGY)
	$(CXX) $(CFLAG) $(VALIDSTRATEGY)$(CC) $(LMYSQL)

$(REPORT)$(O) : $(D_REPORT)
	$(CXX) $(CFLAG) $(REPORT)$(CC) $(LMYSQL)

#	Targets for compiling cpp file(main files)

$(LOGIN)$(MAIN)$(O) : $(D_LOGIN_M)
	$(CXX) $(CFLAG) $(LOGIN)$(MAIN)$(CPP) $(LMYSQL)

$(REGISTER)$(MAIN)$(O) : $(D_REGISTER_M)
	$(CXX) $(CFLAG) $(REGISTER)$(MAIN)$(CPP) $(LMYSQL)

$(RESET)$(MAIN)$(O) : $(D_RESET_M)
	$(CXX) $(CFLAG) $(RESET)$(MAIN)$(CPP) $(LMYSQL)

$(NEWUSER)$(MAIN)$(O) : $(D_NEWUSER_M)
	$(CXX) $(CFLAG) $(NEWUSER)$(MAIN)$(CPP) $(LMYSQL)

$(CONFIRM)$(MAIN)$(O) : $(D_CONFIRM_M)
	$(CXX) $(CFLAG) $(CONFIRM)$(MAIN)$(CPP) $(LMYSQL)

$(ADDUSER)$(MAIN)$(O) : $(D_ADDUSER_M)
	$(CXX) $(CFLAG) $(ADDUSER)$(MAIN)$(CPP) $(LMYSQL)

$(PROJECT)$(MAIN)$(O) : $(D_PROJECT_M)
	$(CXX) $(CFLAG) $(PROJECT)$(MAIN)$(CPP) $(LMYSQL)

$(LOGOUT)$(MAIN)$(O) : $(D_LOGOUT_M)
	$(CXX) $(CFLAG) $(LOGOUT)$(MAIN)$(CPP) $(LMYSQL)

$(CLASS)$(MAIN)$(O) : $(D_CLASS_M)
	$(CXX) $(CFLAG) $(CLASS)$(MAIN)$(CPP) $(LMYSQL)

$(ROLLNO)$(MAIN)$(O) : $(D_ROLLNO_M)
	$(CXX) $(CFLAG) $(ROLLNO)$(MAIN)$(CPP) $(LMYSQL)

$(DATESHEET)$(MAIN)$(O) : $(D_DATESHEET_M)
	$(CXX) $(CFLAG) $(DATESHEET)$(MAIN)$(CPP) $(LMYSQL)

$(EXAM)$(MAIN)$(O) : $(D_EXAM_M)
	$(CXX) $(CFLAG) $(EXAM)$(MAIN)$(CPP) $(LMYSQL)

$(ROOM)$(MAIN)$(O) : $(D_ROOM_M)
	$(CXX) $(CFLAG) $(ROOM)$(MAIN)$(CPP) $(LMYSQL)

$(ADDROOM)$(MAIN)$(O) : $(D_ADDROOM_M)
	$(CXX) $(CFLAG) $(ADDROOM)$(MAIN)$(CPP) $(LMYSQL)

$(STRATEGY)$(MAIN)$(O) : $(D_STRATEGY_M)
	$(CXX) $(CFLAG) $(STRATEGY)$(MAIN)$(CPP) $(LMYSQL)

$(VALIDSTRATEGY)$(MAIN)$(O) : $(D_VALIDSTRATEGY_M)
	$(CXX) $(CFLAG) $(VALIDSTRATEGY)$(MAIN)$(CPP) $(LMYSQL)

$(REPORT)$(MAIN)$(O) : $(D_REPORT_M)
	$(CXX) $(CFLAG) $(REPORT)$(MAIN)$(CPP) $(LMYSQL)

#	Targets for html pages

$(F_BP)$(LOGIN)$(HTML) : $(L_LOGIN)
	$(CXX) $(OFLAG) $(F_BP)$(LOGIN)$(HTML) $(L_LOGIN) \
	$(LMYSQL) $(LCGICC) $(LSMTP)

$(F_BP)$(REGISTER)$(HTML) : $(L_REGISTER)
	$(CXX) $(OFLAG) $(F_BP)$(REGISTER)$(HTML) $(L_REGISTER) \
	$(LMYSQL) $(LCGICC) $(LSMTP)

$(F_BP)$(RESET)$(HTML) : $(L_RESET)
	$(CXX) $(OFLAG) $(F_BP)$(RESET)$(HTML) $(L_RESET) \
	$(LMYSQL) $(LCGICC) $(LSMTP)

$(F_BP)$(NEWUSER)$(HTML) : $(L_NEWUSER)
	$(CXX) $(OFLAG) $(F_BP)$(NEWUSER)$(HTML) $(L_NEWUSER) \
	$(LMYSQL) $(LCGICC) $(LSMTP)

$(F_BP)$(CONFIRM)$(HTML) : $(L_CONFIRM)
	$(CXX) $(OFLAG) $(F_BP)$(CONFIRM)$(HTML) $(L_CONFIRM) \
	$(LMYSQL) $(LCGICC) $(LSMTP)

$(F_BP)$(ADDUSER)$(HTML) : $(L_ADDUSER)
	$(CXX) $(OFLAG) $(F_BP)$(ADDUSER)$(HTML) $(L_ADDUSER) \
	$(LMYSQL) $(LCGICC) $(LSMTP)

$(F_BP)$(PROJECT)$(HTML) : $(L_PROJECT)
	$(CXX) $(OFLAG) $(F_BP)$(PROJECT)$(HTML) $(L_PROJECT) \
	$(LMYSQL) $(LCGICC) $(LSMTP)

$(F_BP)$(LOGOUT)$(HTML) : $(L_LOGOUT)
	$(CXX) $(OFLAG) $(F_BP)$(LOGOUT)$(HTML) $(L_LOGOUT) \
	$(LMYSQL) $(LCGICC) $(LSMTP)

$(F_BP)$(CLASS)$(HTML) : $(L_CLASS)
	$(CXX) $(OFLAG) $(F_BP)$(CLASS)$(HTML) $(L_CLASS) \
	$(LMYSQL) $(LCGICC) $(LSMTP)

$(F_BP)$(ROLLNO)$(HTML) : $(L_ROLLNO)
	$(CXX) $(OFLAG) $(F_BP)$(ROLLNO)$(HTML) $(L_ROLLNO) \
	$(LMYSQL) $(LCGICC) $(LSMTP)

$(F_BP)$(DATESHEET)$(HTML) : $(L_DATESHEET)
	$(CXX) $(OFLAG) $(F_BP)$(DATESHEET)$(HTML) $(L_DATESHEET) \
	$(LMYSQL) $(LCGICC) $(LSMTP)

$(F_BP)$(EXAM)$(HTML) : $(L_EXAM)
	$(CXX) $(OFLAG) $(F_BP)$(EXAM)$(HTML) $(L_EXAM) \
	$(LMYSQL) $(LCGICC) $(LSMTP)

$(F_BP)$(ROOM)$(HTML) : $(L_ROOM)
	$(CXX) $(OFLAG) $(F_BP)$(ROOM)$(HTML) $(L_ROOM) \
	$(LMYSQL) $(LCGICC) $(LSMTP)

$(F_BP)$(ADDROOM)$(HTML) : $(L_ADDROOM)
	$(CXX) $(OFLAG) $(F_BP)$(ADDROOM)$(HTML) $(L_ADDROOM) \
	$(LMYSQL) $(LCGICC) $(LSMTP)

$(F_BP)$(STRATEGY)$(HTML) : $(L_STRATEGY)
	$(CXX) $(OFLAG) $(F_BP)$(STRATEGY)$(HTML) $(L_STRATEGY) \
	$(LMYSQL) $(LCGICC) $(LSMTP)

$(F_BP)$(VALIDSTRATEGY)$(HTML) : $(L_VALIDSTRATEGY)
	$(CXX) $(OFLAG) $(F_BP)$(VALIDSTRATEGY)$(HTML) $(L_VALIDSTRATEGY) \
	$(LMYSQL) $(LCGICC) $(LSMTP)

$(F_BP)$(REPORT)$(HTML) : $(L_REPORT)
	$(CXX) $(OFLAG) $(F_BP)$(REPORT)$(HTML) $(L_REPORT) \
	$(LMYSQL) $(LCGICC) $(LSMTP)

$(CLEAN) : 
	rm -f *.o /home/*/public_html/bp/* && make -C backend clean
