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

MAKE		=	cd src && make && cd ..
CLEAN		=	cd src && make clean && cd ..
MAKE_SRC	=	make_src

# ====================================================================
#	Main target (1st target)
# ====================================================================

all: $(MAKE_SRC)

# ====================================================================
# 	Targets
# ====================================================================

$(MAKE_SRC): 
	$(MAKE)

# ====================================================================
# 	Clean .o, .html files
# ====================================================================

clean:
	$(CLEAN)
