# ====================================================================
# 
#        Filename:  Makefile
# 
#     Description:  Makefile to compile and execute cc/cpp files in
#     				src/ folder.
# 
#         Version:  1.0
#         Created:  Saturday 13 July 2013 11:15:42  IST
#        Compiler:  g++
# 
#          Author:  Mandeep Kaur, meghasimak@gmail.com
#         License:  GNU General Public License
#       Copyright:  Copyright (c) 2013, Great Developers
# 
# ====================================================================

# ====================================================================
# 	Variables
# ====================================================================

# Target Names

BACKEND	=	cpp
CLEAN	=	clean

# ====================================================================
#	Main target (1st target)
# ====================================================================

all: $(BACKEND)

# ====================================================================
# 	Targets
# ====================================================================

$(BACKEND):
	make -C src/cpp/frontend

# ====================================================================
# 	Clean .o, .html files
# ====================================================================

$(CLEAN):
	make -C src/cpp/frontend clean
