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
# 
# ====================================================================

# ====================================================================
#   Variables for compilation of c/c++ files
# ====================================================================

CC      =   g++       		  	# Compiler 
WALL	=	-Wall				# Warning all flag
DEBUG	=	-g					# Debugging flag
CFLAG   =   -c $(WALL) $(DEBUG) # Compilation flag
OFLAG   =   $(DEBUG) -o         # O/p Flag
LCGICC  =   -lcgicc     		# cgicc lib flag
LMYSQL	=	-L/usr/include/mysql -lmysqlclient -I/usr/include/mysql

# ====================================================================
#   Variables for header files (H_HEADER_FILE_NAME)
# ====================================================================

H_CONSTANTS			=	constant.h
H_FILENAMES			=	filename.h
H_HEADER			=   header.h
H_CGICC             =   cgicc.h
H_MYSQL				=	mysql.h $(H_HEADER)
H_PAGESTRUCTURE     =   pagestructure.h $(H_HEADER)
H_PAGELAYOUT        =   pagelayout.h $(H_PAGESTUCTURE)
H_INPUTFIELDNAMES	=	inputfieldname.h $(H_HEADER)
H_READINPUTFIELDS	=   readinputfield.h $(H_HEADER) $(H_CGICC)
H_DETAILS           =   inputdetail.h $(H_PAGELAYOUT) $(H_INPUTFIELDNAMES) $(H_READINPUTFIELDS)
H_CLASSDETAILS		=	classdetail.h $(H_DETAILS)
H_ROLNODETAILS		=	rollnodetail.h $(H_DETAILS)

# ====================================================================
#	Variables for definition files (CC_FILENAME)
# ====================================================================

CC_MYSQL			=	mysql.cc
CC_PAGESTRUCTURE	=	pagestructure.cc
CC_PAGELAYOUT		=	pagelayout.cc 
CC_INPUTFIELDNAMES	=	inputfieldname.cc 
CC_READINPUTFIELDS	=	readinputfield.cc
CC_DETAILS			=	inputdetail.cc
CC_CLASSDETAILS		=	classdetail.cc
CC_ROLLNODETAILS	=	rollnodetail.cc
CC_ROOMDETAILS		=	roomdetail.cc

# ====================================================================
#	Variables for main method files (M_FILENAME)
# ====================================================================

M_TOTALCLASSES		=	totalclasses-main.cpp
M_CLASSINFO			=	classinfo-main.cpp

# ====================================================================
#	Variables for object files
# ====================================================================

O_MYSQL				=	mysql.o
O_PAGESTRUCTURE		=	pagestructure.o
O_PAGELAYOUT		=	pagelayout.o
O_INPUTFIELDNAMES	=	inputfieldname.o
O_READINPUTFIELDS	=	readinputfield.o
O_DETAILS			=	inputdetail.o
O_CLASSDETAILS		=	classdetail.o
O_ROLLNODETAILS		=	rollnodetail.o

# Object files of main files

O_TOTALCLASSES_MAIN	=	totalclasses-main.o
O_CLASSINFO_MAIN	=	classinfo-main.o

# ====================================================================
#	Linking Variables (L_EXE_FILENAME)
# ====================================================================

L_PAGELAYOUT	=	$(O_PAGESTRUCTURE) $(O_PAGELAYOUT)
L_FIELDS		=	$(O_INPUTFIELDNAMES) $(O_READINPUTFIELDS)
L_DETAILS		=	$(L_PAGELAYOUT) $(L_FIELDS) $(O_DETAILS)
L_CLASSDETAILS	=	$(L_DETAILS) $(O_CLASSDETAILS)
L_ROLLNODETAILS	=	$(L_DETAILS) $(O_ROLLNODETAILS)

# Linking of main files

L_TOTALCLASSES	=	$(L_CLASSDETAILS) $(O_TOTALCLASSES_MAIN)
L_CLASSINFO		=	$(L_CLASSDETAILS) $(O_CLASSINFO_MAIN)		

# ====================================================================
# 	O/P file names(exe) (E_FILENAME)
# ====================================================================

E_TOTALCLASSES	=	totalclasses.html
E_CLASSINFO		=	classinfo.html

# ====================================================================
#	Main target (1st target)
# ====================================================================

all: $(E_TOTALCLASSES) $(E_CLASSINFO)

# ====================================================================
#	targets for compiling .cc or .cpp files
# ====================================================================

$(O_MYSQL):	$(CC_MYSQL) $(H_MYSQL)
	$(CC) $(CFLAG) $(CC_MYSQL)

$(O_PAGESTRUCTURE): $(CC_PAGSTRUCTURE) $(H_PAGESTRUCTURE) 
	$(CC) $(CFLAG) $(CC_PAGESTRUCTURE)

$(O_PAGELAYOUT): $(CC_PAGELAYOUT) $(H_PAGELAYOUT)
	$(CC) $(CFLAG) $(CC_PAGELAYOUT)

$(O_INPUTFIELDNAMES): $(CC_INPUTFIELDNAMES) $(H_INPUTFIELDNAMES)
	$(CC) $(CFLAG) $(CC_INPUTFIELDNAMES)

$(O_READINPUTFIELDS): $(CC_READINPUTFIELDS) $(H_READINPUTFIELDS)
	$(CC) $(CFLAG) $(CC_READINPUTFIELDS) $(LCGICC)

$(O_DETAILS): $(CC_DETAILS) $(H_DETAILS)
	$(CC) $(CFLAG) $(CC_DETAILS)

$(O_CLASSDETAILS): $(CC_CLASSDETAILS) $(H_CLASSDETAILS)
	$(CC) $(CFLAG) $(CC_CLASSDETAILS)

$(O_TOTALCLASSES_MAIN): $(M_TOTALCLASSES) $(H_CLASSDETAILS)
	$(CC) $(CFLAG) $(M_TOTALCLASSES)

$(O_CLASSINFO_MAIN): $(M_CLASSINFO) $(H_CLASSDETAILS)
	$(CC) $(CFLAG) $(M_CLASSINFO)

# ====================================================================
# 	Targets of o/p files(exe)
# ====================================================================

$(E_TOTALCLASSES): $(L_TOTALCLASSES)
	$(CC) $(OFLAG) $(E_TOTALCLASSES) $(L_TOTALCLASSES) $(LCGICC)

$(E_CLASSINFO): $(L_CLASSINFO)
	$(CC) $(OFLAG) $(E_CLASSINFO) $(L_CLASSINFO) $(LCGICC)

# ====================================================================
# 	Clean .o, .html files
# ====================================================================

clean:
	rm *.o *.html
