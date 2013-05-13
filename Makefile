# ====================================================================
# 
#        Filename:  Makefile
# 
#     Description:  Makefile to compile and execute cc/cpp files in
#     src/ folder.
# 
#         Version:  0.7
#         Created:  Saturday 16 February 2013 11:15:42  IST
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

MAKE			=	make -C frontend
CLEAN			=	make -C frontend clean
COPY_HOMEPAGE	=	cp -r BaKaPlan ~/public_html/
COPY_DOC 		=	cp -r doc ~/public_html/BaKaPlan/doc
COPY			=	$(COPY_HOMEPAGE) && $(COPY_DOC)
INSTALL         =   $(COPY)

# Target Names

T_COPY			=	copy
T_CLEAN			=	clean
T_INSTALL       =   install
T_FRONTEND      =   front
T_COPY_DOC		=	copy-doc

# ====================================================================
#	Main target (1st target)
# ====================================================================

all: $(T_FRONTEND)

# ====================================================================
# 	Targets
# ====================================================================

$(T_INSTALL):
	$(INSTALL) && $(MAKE)

$(T_COPY):
	$(COPY)	

$(T_COPY_DOC):
	$(COPY_DOC)

# ====================================================================
# 	Clean .o, .html files
# ====================================================================

$(T_CLEAN):
	$(CLEAN)
