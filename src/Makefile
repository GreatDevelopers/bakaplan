# ====================================================================
# 
#        Filename:  Makefile
# 
#     Description:  Makefile to compile and execute cc/cpp files.
# 
#         Version:  0.6
#         Created:  Saturday 16 February 2013 11:15:42  IST
#        Compiler:  gcc
# 
#          Author:  Mandeep Kaur, meghasimak@gmail.com
#         License:  GNU General Public License
#       Copyright:  Copyright (c) 2013, Great Developers
#                   https://github.com/GreatDevelopers 
# 
# ====================================================================

# ====================================================================
#   Variables for compilation of c/c++ files
# ====================================================================

CC      =   g++                          # Compiler 
WALL    =   -Wall                        # Warning all flag
WERROR  =   -Werror                      # Convert warnings into error
DEBUG   =   -g                           # Debugging flag
CFLAG   =   -c -Wl,--stack,8388608 $(WALL) $(WERROR) $(DEBUG)# Compilation flag
OFLAG   =   $(DEBUG) -o                  # O/p Flag
LCGICC  =   -lcgicc     		         # cgicc lib flag
LMYSQL  =   -L/usr/include/mysql -lmysqlclient -I/usr/include/mysql

# ====================================================================
#   Variables for running make file in backend folder
# ====================================================================

BACKEND = cd backend && make && cd ..

# ====================================================================
#   Variables for header files (H_HEADER_FILE_NAME)
# ====================================================================

H_MD5               =   md5.h
H_CONSTANTS         =   constant.h
H_FILENAMES	        =   filename.h $(H_CONSTANTS)
H_HEADER            =   header.h
H_CGICC             =   cgicc.h
H_DATABASE_DETAIL   =   database-detail.h
H_DATABASE	        =   database.h $(H_HEADER) $(H_DATABASE_DETAIL)
H_JAVASCRIPT        =   javascript.h
H_PAGESTRUCTURE     =   pagestructure.h $(H_HEADER)
H_PAGELAYOUT        =   pagelayout.h $(H_PAGESTUCTURE)
H_INPUTFIELDNAMES   =   inputfieldname.h $(H_HEADER)
H_READINPUTFIELDS   =   readinputfield.h $(H_HEADER) $(H_CGICC)
H_FIELD             =   $(H_INPUTFIELDNAMES) $(H_READINPUTFIELDS)
H_DETAILS           =   inputdetail.h $(H_PAGELAYOUT) $(H_FIELD) $(H_FILENAMES)
H_LOGIN             =   login.h $(H_DETAILS)
H_PROJECTDETAIL     =   projectdetail.h $(H_LOGIN)
H_CLASSDETAILS      =   classdetail.h $(H_DETAILS)
H_ROLNODETAIL       =   rollnodetail.h $(H_DETAILS)
H_ROOMDETAIL        =   roomdetail.h $(H_DETAILS)
H_SUBJECT_RNO       =   backend/subject-wise-rollno.h
H_ARRANGE_RNO       =   backend/arrange-rollno.h
H_READ_INPUT        =   backend/read-input.h
H_EXPAND_RNO        =   backend/expand-rollno.h
H_SUBJECT           =   $(H_READ_INPUT) $(H_ARRANGE_RNO) $(H_EXPAND_RNO) $(H_SUBJECT_RNO)
H_STRATEGY          =   strategy.h $(H_DETAILS) $(H_SUBJECT) 
H_VALIDATION        =   validation.h $(H_DETAILS)
H_EXAMDETAIL        =   examdetail.h $(H_DETAILS)
H_REPORT            =   report.h $(H_DETAILS)

# ====================================================================
#	Variables for definition files (CC_FILENAME)
# ====================================================================

CC_MD5              =   md5.cc
CC_JAVASCRIPT       =   javascript.cc
CC_DATABASE         =   database.cc
CC_PAGESTRUCTURE    =   pagestructure.cc
CC_PAGELAYOUT       =   pagelayout.cc 
CC_INPUTFIELDNAMES  =   inputfieldname.cc 
CC_READINPUTFIELDS  =   readinputfield.cc
CC_DETAILS          =   inputdetail.cc
CC_LOGIN            =   login.cc
CC_PROJECTDETAIL    =   projectdetail.cc
CC_CLASSDETAILS	    =   classdetail.cc
CC_ROLLNODETAIL     =   rollnodetail.cc
CC_ROOMDETAIL       =   roomdetail.cc
CC_STRATEGY         =   strategy.cc
CC_VALIDATION       =   validation.cc
CC_EXAMDETAIL       =   examdetail.cc
CC_REPORT           =   report.cc

# ====================================================================
#	Variables for main method files (M_FILENAME)
# ====================================================================

M_JAVASCRIPT        =   javascript-main.cpp
M_TOTALCLASSES      =   totalclasses-main.cpp
M_CLASSINFO         =   classinfo-main.cpp
M_LOGIN             =   login-main.cpp
M_PROJECTDETAIL     =   projectdetail-main.cpp
M_REGISTER          =   register-main.cpp
M_NEWUSER           =   newuser-main.cpp
M_LOGOUT            =   logout-main.cpp
M_ROLLNO            =   rollnodetail-main.cpp
M_TOTALCENTRE       =   totalcentre-main.cpp
M_CENTREDETAIL      =   centredetail-main.cpp
M_ROOMDETAIL        =   roomdetail-main.cpp
M_GETCOOKIE         =   getcookies.cpp
M_STRATEGY          =   strategy-main.cpp
M_VALIDATION        =   validation-main.cpp
M_EXAMDETAIL        =   examdetail-main.cpp
M_REPORT            =   report-main.cpp

# ====================================================================
#	Variables for object files
# ====================================================================

O_MD5               =   md5.o
O_JAVASCRIPT        =   javascript.o
O_DATABASE          =   database.o
O_PAGESTRUCTURE     =   pagestructure.o
O_PAGELAYOUT        =   pagelayout.o
O_INPUTFIELDNAMES   =   inputfieldname.o
O_READINPUTFIELDS   =   readinputfield.o
O_DETAILS           =   inputdetail.o
O_LOGIN             =   login.o
O_PROJECTDETAIL		=	projectdetail.o
O_CLASSDETAILS      =   classdetail.o
O_ROLLNODETAIL      =   rollnodetail.o
O_ROOMDETAIL        =   roomdetail.o
O_STRATEGY          =   strategy.o
O_VALIDATION        =   validation.o
O_SUBJECT_RNO       =   backend/subject-wise-rollno.o
O_ARRANGE_RNO       =   backend/arrange-rollno.o
O_EXPAND_RNO        =   backend/expand-rollno.o
O_READ_INPUT        =   backend/read-input.o
O_STRATEGY_BACKEND  =   backend/strategy.o
O_SEATPLAN          =   backend/seatplan.o $(O_STRATEGY_BACKEND)
O_EXAMDETAIL        =   examdetail.o
O_REPORT            =   report.o

# Object files of main files

O_JAVASCRIPT_MAIN   =   javascript-main.o
O_TOTALCLASSES_MAIN =   totalclasses-main.o
O_LOGIN_MAIN        =   login-main.o
O_PROJECTDETAIL_MAIN=   projectdetail-main.o
O_CLASSINFO_MAIN    =   classinfo-main.o
O_REGISTER_MAIN     =   register-main.o
O_NEWUSER_MAIN      =   newuser-main.o
O_LOGOUT_MAIN       =   logout-main.o
O_ROLLNO_MAIN       =   rollnodetail-main.o
O_TOTALCENTRE_MAIN  =   totalcentre-main.o
O_CENTREDETAIL_MAIN =   centredetail-main.o
O_ROOMDETAIL_MAIN   =   roomdetail-main.o
O_GETCOOKIE_MAIN    =   getcookies.o
O_STRATEGY_MAIN     =   strategy-main.o
O_VALIDATION_MAIN   =   validation-main.o
O_EXAMDETAIL_MAIN   =   examdetail-main.o
O_REPORT_MAIN       =   report-main.o

# ====================================================================
#	Linking Variables (L_EXE_FILENAME)
# ====================================================================

L_PAGELAYOUT	=	$(O_PAGESTRUCTURE) $(O_PAGELAYOUT)
L_FIELDS		=	$(O_INPUTFIELDNAMES) $(O_READINPUTFIELDS)
L_DETAILS		=	$(L_PAGELAYOUT) $(L_FIELDS) $(O_DATABASE) $(O_DETAILS)
L_LOGIN         =   $(L_DETAILS) $(O_LOGIN) $(O_MD5)
L_PROJECTDETAIL =   $(L_LOGIN) $(O_PROJECTDETAIL)
L_CLASSDETAILS	=	$(L_DETAILS) $(O_CLASSDETAILS)
L_ROLLNODETAIL	=	$(L_DETAILS) $(O_ROLLNODETAIL)
L_ROOMDETAIL    =   $(L_DETAILS) $(O_ROOMDETAIL)
L_SUBJECT       =   $(O_READ_INPUT) $(O_EXPAND_RNO) $(O_ARRANGE_RNO) $(O_SUBJECT_RNO)
L_STRATEGY      =   $(L_DETAILS) $(O_STRATEGY) $(L_SUBJECT)
L_VALIDATION    =   $(L_DETAILS) $(O_VALIDATION) $(O_SEATPLAN)
L_EXAMDETAIL    =   $(L_DETAILS) $(O_EXAMDETAIL)
L_REPORT        =   $(L_DETAILS) $(O_REPORT) backend/room-report.o

# Linking of main files

L_TOTALCLASSES	=	$(L_CLASSDETAILS) $(O_TOTALCLASSES_MAIN)
L_CLASSINFO		=	$(L_CLASSDETAILS) $(O_CLASSINFO_MAIN)
L_LOGINPAGE     =   $(L_LOGIN) $(O_LOGIN_MAIN)
L_JAVASCRIPT    =   $(O_JAVASCRIPT) $(O_JAVASCRIPT_MAIN)
L_PROJECTDETAIL_M = $(L_PROJECTDETAIL) $(O_PROJECTDETAIL_MAIN)
L_REGISTER      =   $(L_LOGIN) $(O_REGISTER_MAIN)
L_NEWUSER       =   $(L_LOGIN) $(O_NEWUSER_MAIN)
L_LOGOUT        =   $(L_LOGIN) $(O_LOGOUT_MAIN)
L_ROLLNO        =   $(L_ROLLNODETAIL) $(O_ROLLNO_MAIN)
L_TOTALCENTRE   =   $(L_ROOMDETAIL) $(O_TOTALCENTRE_MAIN)
L_CENTREDETAIL  =   $(L_ROOMDETAIL) $(O_CENTREDETAIL_MAIN)
L_ROOM          =   $(L_ROOMDETAIL) $(O_ROOMDETAIL_MAIN)
L_GETCOOKIE     =   $(L_LOGIN) $(O_GETCOOKIE_MAIN)
L_STRATEGY_M    =   $(L_STRATEGY) $(O_STRATEGY_MAIN)
L_VALID         =   $(L_VALIDATION) $(O_VALIDATION_MAIN)
L_EXAM          =   $(L_EXAMDETAIL) $(O_EXAMDETAIL_MAIN)
L_REPORT_M      =   $(L_REPORT) $(O_REPORT_MAIN)

# ====================================================================
# 	O/P file names(exe) (E_FILENAME)
# ====================================================================

E_TOTALCLASSES	=	totalclasses.html
E_CLASSINFO		=	classinfo.html
E_LOGIN         =   login.html
E_JAVASCRIPT    =   javascript.js
E_PROJECTDETAIL =   projectdetail.html
E_REGISTER      =   register.html
E_NEWUSER       =   newuser.html
E_LOGOUT        =   logout.html
E_ROLLNO        =   rollnodetail.html
E_TOTALCENTRE   =   totalcentre.html
E_CENTREDETAIL  =   centredetail.html
E_ROOM          =   roomdetail.html
E_GETCOOKIE     =   getcookie.html
E_STRATEGY      =   strategy.html
E_VALIDATION    =   validation.html
E_EXAMDETAIL    =   examdetail.html
E_REPORT        =   report.html

# ====================================================================
#	Main target (1st target)
# ====================================================================

all: back $(E_JAVASCRIPT) $(E_LOGIN) $(E_TOTALCLASSES) $(E_CLASSINFO) $(E_PROJECTDETAIL) $(E_REGISTER) $(E_NEWUSER) $(E_ROLLNO) $(E_TOTALCENTRE) $(E_CENTREDETAIL) $(E_ROOM) $(E_GETCOOKIE) $(E_LOGOUT) $(E_STRATEGY) $(E_VALIDATION) $(E_EXAMDETAIL) $(E_REPORT)

# ====================================================================
#   Target for compiling files in backend folder
# ====================================================================

back:
	$(BACKEND)

# ====================================================================
#	targets for compiling .cc or .cpp files
# ====================================================================

$(O_MD5): $(CC_MD5) $(H_MD5)
	$(CC) $(CFLAG) $(CC_MD5)

$(O_JAVASCRIPT): $(CC_JAVASCRIPT) $(H_JAVASCRIPT)
	$(CC) $(CFLAG) $(CC_JAVASCRIPT)

$(O_DATABASE):	$(CC_DATABASE) $(H_DATABASE)
	$(CC) $(CFLAG) $(CC_DATABASE) $(LMYSQL)

$(O_PAGESTRUCTURE): $(CC_PAGESTRUCTURE) $(H_PAGESTRUCTURE) 
	$(CC) $(CFLAG) $(CC_PAGESTRUCTURE)

$(O_PAGELAYOUT): $(CC_PAGELAYOUT) $(H_PAGELAYOUT)
	$(CC) $(CFLAG) $(CC_PAGELAYOUT)

$(O_INPUTFIELDNAMES): $(CC_INPUTFIELDNAMES) $(H_INPUTFIELDNAMES)
	$(CC) $(CFLAG) $(CC_INPUTFIELDNAMES)

$(O_READINPUTFIELDS): $(CC_READINPUTFIELDS) $(H_READINPUTFIELDS)
	$(CC) $(CFLAG) $(CC_READINPUTFIELDS) $(LCGICC)

$(O_DETAILS): $(CC_DETAILS) $(H_DETAILS)
	$(CC) $(CFLAG) $(CC_DETAILS) $(LMYSQL)

$(O_LOGIN): $(CC_LOGIN) $(H_LOGIN)
	$(CC) $(CFLAG) $(CC_LOGIN) $(LMYSQL)

$(O_PROJECTDETAIL): $(CC_PROJECTDETAIL) $(H_PROJECTDETAIL)
	$(CC) $(CFLAG) $(CC_PROJECTDETAIL) $(LMYSQL) $(LCGICC)

$(O_CLASSDETAILS): $(CC_CLASSDETAILS) $(H_CLASSDETAILS)
	$(CC) $(CFLAG) $(CC_CLASSDETAILS) $(LMYSQL)

$(O_ROLLNODETAIL): $(CC_ROLLNODETAIL) $(H_ROLLNODETAIL)
	$(CC) $(CFLAG) $(CC_ROLLNODETAIL) $(LMYSQL)

$(O_ROOMDETAIL): $(CC_ROOMDETAIL) $(H_ROOMDETAIL)
	$(CC) $(CFLAG) $(CC_ROOMDETAIL) $(LMYSQL)

$(O_STRATEGY): $(CC_STRATEGY) $(H_STRATEGY)
	$(CC) $(CFLAG) $(CC_STRATEGY) $(LMYSQL)

$(O_VALIDATION): $(CC_VALIDATION) $(H_VALIDATION)
	$(CC) $(CFLAG) $(CC_VALIDATION) $(LMYSQL)

$(O_EXAMDETAIL): $(CC_EXAMDETAIL) $(H_EXAMDETAIL)
	$(CC) $(CFLAG) $(CC_EXAMDETAIL) $(LMYSQL)

$(O_REPORT): $(CC_REPORT) $(H_REPORT)
	$(CC) $(CFLAG) $(CC_REPORT) $(LMYSQL)

# Compiling Mian files

$(O_JAVASCRIPT_MAIN): $(M_JAVASCRIPT) $(H_JAVASCRIPT)
	$(CC) $(CFLAG) $(M_JAVASCRIPT)

$(O_LOGIN_MAIN): $(M_LOGIN) $(H_LOGIN)
	$(CC) $(CFLAG) $(M_LOGIN) $(LMYSQL) 

$(O_REGISTER_MAIN): $(M_REGISTER) $(H_LOGIN)
	$(CC) $(CFLAG) $(M_REGISTER) $(LMYSQL)

$(O_NEWUSER_MAIN): $(M_NEWUSER) $(H_LOGIN)
	$(CC) $(CFLAG) $(M_NEWUSER) $(LMYSQL)

$(O_LOGOUT_MAIN): $(M_LOGOUT) $(H_LOGIN)
	$(CC) $(CFLAG) $(M_LOGOUT) $(LMYSQL)

$(O_PROJECTDETAIL_MAIN): $(M_PROJECTDETAIL) $(H_PROJECTDETAIL)
	$(CC) $(CFLAG) $(M_PROJECTDETAIL) $(LMYSQL) $(LCGICC)

$(O_TOTALCLASSES_MAIN): $(M_TOTALCLASSES) $(H_CLASSDETAILS)
	$(CC) $(CFLAG) $(M_TOTALCLASSES) $(LMYSQL)

$(O_CLASSINFO_MAIN): $(M_CLASSINFO) $(H_CLASSDETAILS)
	$(CC) $(CFLAG) $(M_CLASSINFO) $(LMYSQL)

$(O_ROLLNO_MAIN): $(M_ROLLNO) $(H_ROLLNODETAIL)
	$(CC) $(CFLAG) $(M_ROLLNO) $(LMYSQL)

$(O_TOTALCENTRE_MAIN): $(M_TOTALCENTRE) $(H_ROOMDETAIL)
	$(CC) $(CFLAG) $(M_TOTALCENTRE) $(LMYSQL)

$(O_CENTREDETAIL_MAIN): $(M_CENTREDETAIL) $(H_ROOMDETAIL)
	$(CC) $(CFLAG) $(M_CENTREDETAIL) $(LMYSQL)

$(O_ROOMDETAIL_MAIN): $(M_ROOMDETAIL) $(H_ROOMDETAIL)
	$(CC) $(CFLAG) $(M_ROOMDETAIL) $(LMYSQL)

$(O_GETCOOKIE_MAIN): $(M_GETCOOKIE) $(H_LOGIN)
	$(CC) $(CFLAG) $(M_GETCOOKIE) $(LMYSQL)
	
$(O_STRATEGY_MAIN): $(M_STRATEGY) $(H_STRATEGY)
	$(CC) $(CFLAG) $(M_STRATEGY) $(LMYSQL) # --main-stacksize=8488608

$(O_VALIDATION_MAIN): $(M_VALIDATION) $(H_VALIDATION)
	$(CC) $(CFLAG) $(M_VALIDATION) $(LMYSQL)

$(O_EXAMDETAIL_MAIN): $(M_EXAMDETAIL) $(H_EXAMDETAIL)
	$(CC) $(CFLAG) $(M_EXAMDETAIL) $(LMYSQL)

$(O_REPORT_MAIN): $(M_REPORT) $(H_REPORT)
	$(CC) $(CFLAG) $(M_REPORT) $(LMYSQL)

# ====================================================================
# 	Targets of o/p files(exe)
# ====================================================================

$(E_JAVASCRIPT): $(L_JAVASCRIPT)
	$(CC) $(OFLAG) $(E_JAVASCRIPT) $(L_JAVASCRIPT)

$(E_LOGIN): $(L_LOGINPAGE)
	$(CC) $(OFLAG) $(E_LOGIN) $(L_LOGINPAGE) $(LCGICC) $(LMYSQL)

$(E_REGISTER): $(L_REGISTER)
	$(CC) $(OFLAG) $(E_REGISTER) $(L_REGISTER) $(LCGICC) $(LMYSQL)

$(E_NEWUSER): $(L_NEWUSER)
	$(CC) $(OFLAG) $(E_NEWUSER) $(L_NEWUSER) $(LCGICC) $(LMYSQL)

$(E_LOGOUT): $(L_GETCOOKIE)
	$(CC) $(OFLAG) $(E_LOGOUT) $(L_GETCOOKIE) $(LCGICC) $(LMYSQL)

$(E_PROJECTDETAIL): $(L_PROJECTDETAIL_M)
	$(CC) $(OFLAG) $(E_PROJECTDETAIL) $(L_PROJECTDETAIL_M) $(LCGICC) \
	$(LMYSQL)

$(E_TOTALCLASSES): $(L_TOTALCLASSES)
	$(CC) $(OFLAG) $(E_TOTALCLASSES) $(L_TOTALCLASSES) $(LCGICC) \
	$(LMYSQL)

$(E_CLASSINFO): $(L_CLASSINFO)
	$(CC) $(OFLAG) $(E_CLASSINFO) $(L_CLASSINFO) $(LCGICC) $(LMYSQL)

$(E_ROLLNO): $(L_ROLLNO)
	$(CC) $(OFLAG) $(E_ROLLNO) $(L_ROLLNO) $(LCGICC) $(LMYSQL)

$(E_TOTALCENTRE): $(L_TOTALCENTRE)
	$(CC) $(OFLAG) $(E_TOTALCENTRE) $(L_TOTALCENTRE) $(LCGICC) \
	$(LMYSQL)

$(E_CENTREDETAIL): $(L_CENTREDETAIL)
	$(CC) $(OFLAG) $(E_CENTREDETAIL) $(L_CENTREDETAIL) $(LCGICC) \
	$(LMYSQL)

$(E_ROOM): $(L_ROOM)
	$(CC) $(OFLAG) $(E_ROOM) $(L_ROOM) $(LCGICC) \
	$(LMYSQL)

$(E_GETCOOKIE): $(L_GETCOOKIE)
	$(CC) $(OFLAG) $(E_GETCOOKIE) $(L_GETCOOKIE) $(LCGICC) $(LMYSQL)

$(E_STRATEGY): $(L_STRATEGY_M)
	$(CC) $(OFLAG) $(E_STRATEGY) $(L_STRATEGY_M) \
	$(LCGICC) $(LMYSQL)

$(E_VALIDATION): $(L_VALID)
	$(CC) $(OFLAG) $(E_VALIDATION) $(L_VALID) $(LCGICC) $(LMYSQL)

$(E_EXAMDETAIL): $(L_EXAM)
	$(CC) $(OFLAG) $(E_EXAMDETAIL) $(L_EXAM) $(LCGICC) $(LMYSQL)

$(E_REPORT): $(L_REPORT_M)
	$(CC) $(OFLAG) $(E_REPORT) $(L_REPORT_M) $(LCGICC) $(LMYSQL)

# ====================================================================
# 	Clean .o, .html files
# ====================================================================

clean:
	rm *.o *.html *.js
