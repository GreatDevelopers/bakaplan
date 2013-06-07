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
#	Main target (1st target)
# ====================================================================

all: source

# ====================================================================
# 	Targets
# ====================================================================

source:
	make -C src

# ====================================================================
# 	Clean .o, .html files
# ====================================================================

clean:
	make -C src clean

clean-IO:
	rm -f input/*.in output/*.out ~/public_html/SeatPlan/*.html
