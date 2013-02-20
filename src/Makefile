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

# ====================================================================
#   Variables for header files (H_HEADER_FILE_NAME)
# ====================================================================

H_CONSTANTS				=	constants.h
H_FILENAMES				=	filenames.h
H_HEADER				=   header.h
H_CGICC                 =   cgicc.h
H_HTMLTAGS              =   htmltags.h $(H_HEADER) $(H_FILENAMES) $(H_CONSTANTS)
H_PAGELAYOUT            =   pagelayout.h $(H_HTMLTAGS)
H_INPUTFIELDNAMES		=	inputfieldnames.h  $(H_HEADER)
H_READINPUTDETAILS      =   readinputdetails.h $(H_HEADER) $(H_CGICC)
H_CLASSDETAILS			=	classdetails.h $(H_PAGELAYOUT) $(H_INPUTFIELDNAMES)

# ====================================================================
#	Variables for definition files (CC_FILENAME)
# ====================================================================

CC_HTMLTAGS				=	htmltags.cc
CC_PAGELAYOUT			=	pagelayout.cc 
CC_INPUTFIELDNAMES		=	inputfieldnames.cc 
CC_READINPUTFIELDS		=	readinputfields.cc
CC_CLASSDETAILS			=	classdetails.cc
CC_ROLLNODETAILS		=	rollnodetails.cc
CC_ROOMDETAILS			=	roomdetails.cc

# ====================================================================
#	Variables for main method files (M_FILENAME)
# ====================================================================

M_TOTALCLASSES			=	totalclasses-main.cpp
M_CLASSINFO				=	classinfo-main.cpp

# ====================================================================
#	Variables for object files
# ====================================================================

O_HTMLTAGS				=	htmltags.o
O_PAGELAYOUT			=	pagelayout.o
O_INPUTFIELDNAMES		=	inputfieldnames.o
O_READINPUTFIELDS		=	readinputfields.o
O_CLASSDETAILS			=	classdetails.o
O_TOTALCLASSES_MAIN		=	totalclasses-main.o
O_CLASSINFO_MAIN		=	classinfo-main.o

# ====================================================================
#	Linking Variables (L_EXE_FILENAME)
# ====================================================================

L_PAGELAYOUT	=	$(O_HTMLTAGS) $(O_PAGELAYOUT)
L_CLASSDETAILS	=	$(L_PAGELAYOUT) $(O_INPUTFIELDNAMES) $(O_CLASSDETAILS)
L_TOTALCLASSES	=	$(O_READINPUTFIELDS) $(L_CLASSDETAILS) $(O_TOTALCLASSES_MAIN)
L_CLASSINFO		=	$(O_READINPUTFIELDS) $(L_CLASSDETAILS) $(O_CLASSINFO_MAIN)		

# ====================================================================
# 	O/P file names(exe) (E_FILENAME)
# ====================================================================

E_TOTALCLASSES			=	totalclasses.html
E_CLASSINFO				=	classinfo.html

# ====================================================================
#	Main target (1st target)
# ====================================================================

all: $(E_TOTALCLASSES) $(E_CLASSINFO)

# ====================================================================
#	targets for compiling .cc or .cpp files
# ====================================================================

$(O_HTMLTAGS): $(CC_HTMLTAGS) $(H_HTMLTAGS) 
	$(CC) $(CFLAG) $(CC_HTMLTAGS)

$(O_PAGELAYOUT): $(CC_PAGELAYOUT) $(H_PAGELAYOUT)
	$(CC) $(CFLAG) $(CC_PAGELAYOUT)

$(O_INPUTFIELDNAMES): $(CC_INPUTFIELDNAMES) $(H_INPUTFIELDNAMES)
	$(CC) $(CFLAG) $(CC_INPUTFIELDNAMES)

$(O_READINPUTFIELDS): $(CC_READINPUTFIELDS) $(H_READINPUTFIELDS)
	$(CC) $(CFLAG) $(CC_READINPUTFIELDS) $(LCGICC)

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
