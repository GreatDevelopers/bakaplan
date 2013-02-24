# ====================================================================
# 
#        Filename:  Makefile
# 
#     Description:  Makefile to compile and execute cc/cpp files in
#     src/ folder.
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
# 	Variables
# ====================================================================

MAKE			=	cd src && make && cd ..
CLEAN			=	cd src && make clean && cd ..
COPY_HOMEPAGE	=	cp -r BaKaPlan ~/public_html/
COPY_DOC 		=	cp -r Documentation ~/public_html/BaKaPlan/
COPY			=	$(COPY_HOMEPAGE) && $(COPY_DOC)

# Target Names

T_MAKE_SRC		=	make_src
T_COPY			=	copy
T_CLEAN			=	clean

# ====================================================================
#	Main target (1st target)
# ====================================================================

all: $(T_MAKE_SRC)

# ====================================================================
# 	Targets
# ====================================================================

$(T_MAKE_SRC): 
	$(MAKE)

$(T_COPY):
	$(COPY)	

# ====================================================================
# 	Clean .o, .html files
# ====================================================================

$(T_CLEAN):
	$(CLEAN)
