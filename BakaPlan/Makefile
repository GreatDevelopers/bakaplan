CC      =   g++           
CFLAG   =   -c  -g      # Compilation Flag
OFLAG   =   -o          # O/p Flag
LCGICC  =   -lcgicc     # cgicc lib flag

#--------------------------------------------------------------------------
#                    Header files(pages)
#--------------------------------------------------------------------------

FILENAMES           =   file-names.h
HEADER              =   header.h $(FILENAMES)
HTMLTAGS_HEADER     =   htmltags.h $(HEADER)
HOME_HEADER         =   home.h $(HTMLTAGS_HEADER)
BRANCH_HEADER       =   branchdetails.h $(HTMLTAGS_HEADER)
ROLLNO_HEADER       =   rollnodetails.h $(HTMLTAGS_HEADER)  #$(READBRANCH_HEADER)
ROOM_HEADER         =   roomdetails.h $(HTMLTAGS_HEADER)
STRATEGY_HEADER     =   strategy.h $(HTMLTAGS_HEADER) $(SUBJECT_HEADER)
VALIDATION_HEADER   =   validation.h $(HTMLTAGS_HEADER) $(SeatPlan_STRATEGY)
EXAM_HEADER         =   examdetails.h $(HTMLTAGS_HEADER)
REPORT_HEADER       =   report.h $(HTMLTAGS_HEADER) SeatPlan/seatplan.h SeatPlan/header.h SeatPlan/file-names.h SeatPlan/report.h

SUBJECT_HEADER      =   SeatPlan/subject-wise-rollno.h SeatPlan/arrange-rollno.h SeatPlan/expand-rollno.h SeatPlan/read-input.h
SeatPlan_STRATEGY   =   SeatPlan/strategy.h SeatPlan/seatplan.h SeatPlan/header.h SeatPlan/file-names.h     

#--------------------------------------------------------------------------
#                           Header files(CSS)
#--------------------------------------------------------------------------

CSS_HEADER = css.h $(HEADER)

#--------------------------------------------------------------------------
#                        Linking of object files
#--------------------------------------------------------------------------

HTMLTags    =   htmltags.o # htmltags-main.o
Home        =   $(HTMLTags) home.o home-main.o
CSS         =   css.o css-main.o
Branch      =   $(HTMLTags) branchdetails.o branchdetails-main.o
RollNo      =   $(HTMLTags) readbranchdetails.o rollnodetails.o rollnodetails-main.o
Room        =   $(HTMLTags) readrollnodetails.o roomdetails.o roomdetails-main.o
Strategy    =   $(HTMLTags) readroomdetails.o $(Subject) strategy.o strategy-main.o
Validation  =   $(HTMLTags) $(SeatPlan_Strategy) validation.o validation-main.o
Exam        =   $(HTMLTags) examdetails.o examdetails-main.o
Report      =   $(HTMLTags) SeatPlan/room-report.o readexamdetails.o report.o report-main.o

Subject     =   SeatPlan/subject-wise-rollno.o SeatPlan/arrange-rollno.o SeatPlan/expand-rollno.o SeatPlan/read-input.o
SeatPlan_Strategy   =   SeatPlan/strategy.o SeatPlan/seatplan.o 

#--------------------------------------------------------------------------
#                           All Targets
#--------------------------------------------------------------------------

all: home.css home.html branchdetails.html rollnodetails.html roomdetails.html strategy.html validation.html examdetails.html report.html make-SeatPlan

#--------------------------------------------------------------------------
#                         COMMON HTML TAGS
#--------------------------------------------------------------------------

htmltags.o: htmltags.cc $(HEADER)
	$(CC) $(CFLAG) htmltags.cc

htmltags-main.o: htmltags-main.cpp $(HEADER)
	$(CC) $(CFLAG) htmltags-main.cpp

htmltags: $(HTMLTags)
	$(CC) $(OFLAG) htmltags $(HTMLTags)

htmltags-run: htmltags
	./htmltags

#--------------------------------------------------------------------------
#                           Home Page
#--------------------------------------------------------------------------

home.o: home.cc $(HOME_HEADER)
	$(CC) $(CFLAG) home.cc

home-main.o: home-main.cpp $(HOME_HEADER)
	$(CC) $(CFLAG) home-main.cpp

home.html: $(Home)
	$(CC) $(OFLAG) home.html $(Home)

home-run: home.html
	./home.html

#--------------------------------------------------------------------------
#                           CSS File
#--------------------------------------------------------------------------

css.o: css.cc $(CSS_HEADER)
	$(CC) $(CFLAG) css.cc

css-main.o: css-main.cpp $(CSS_HEADER)
	$(CC) $(CFLAG) css-main.cpp

home.css: $(CSS)
	$(CC) $(OFLAG) home.css $(CSS)

css-run: home.css
	./home.css

#--------------------------------------------------------------------------
#                           Branch Details
#--------------------------------------------------------------------------

branchdetails.o: branchdetails.cc $(BRANCH_HEADER)
	$(CC) $(CFLAG) branchdetails.cc

branchdetails-main.o: branchdetails-main.cpp $(BRANCH_HEADER)
	$(CC) $(CFLAG) branchdetails-main.cpp

branchdetails.html: $(Branch)
	$(CC) $(OFLAG) branchdetails.html $(Branch)

branch-run: branchdetails.html
	./branchdetails.html

#---------------------------------------------------------------------------
#readbranchdetails.o: readbranchdetails.cc $(READBRANCH_HEADER) $(BRANCH_HEADER)
#	$(CC) $(CFLAG) readbranchdetails.cc $(LCGICC)

#readbranchdetails-main.o: readbranchdetails-main.cpp $(READBRANCH_HEADER) $(BRANCH_HEADER)
#	$(CC) $(CFLAG) readbranchdetails-main.cpp

#readbranchdetails: $(ReadBranchMain)
#	$(CC) $(OFLAG) readbranchdetails $(ReadBranchMain) $(LCGICC)
#---------------------------------------------------------------------------

#--------------------------------------------------------------------------
#                           Roll No. Details
#--------------------------------------------------------------------------

rollnodetails.o: rollnodetails.cc $(ROLLNO_HEADER)
	$(CC) $(CFLAG) rollnodetails.cc $(LCGICC)

readbranchdetails.o: readbranchdetails.cc $(ROLLNO_HEADER)
	$(CC) $(CFLAG) readbranchdetails.cc $(LCGICC)

rollnodetails-main.o: rollnodetails-main.cpp $(ROLLNO_HEADER)
	$(CC) $(CFLAG) rollnodetails-main.cpp $(LCGICC)

rollnodetails.html: $(RollNo)
	$(CC) $(OFLAG) rollnodetails.html $(RollNo) $(LCGICC)

rollno-run: rollnodetails.html
	./rollnodetails.html

#--------------------------------------------------------------------------
#                           Room Details
#--------------------------------------------------------------------------

roomdetails.o: roomdetails.cc $(ROOM_HEADER)
	$(CC) $(CFLAG) roomdetails.cc $(LCGICC)

readrollnodetails.o: readrollnodetails.cc $(ROOM_HEADER)
	$(CC) $(CFLAG) readrollnodetails.cc $(LCGICC)

roomdetails-main.o: roomdetails-main.cpp $(ROOM_HEADER)
	$(CC) $(CFLAG) roomdetails-main.cpp $(LCGICC)

roomdetails.html: $(Room)
	$(CC) $(OFLAG) roomdetails.html $(Room) $(LCGICC)

room-run: rollnodetails.html
	./rollnodetails.html

#--------------------------------------------------------------------------
#                           Strategy
#--------------------------------------------------------------------------

strategy.o: strategy.cc $(STRATEGY_HEADER)
	$(CC) $(CFLAG) strategy.cc $(Subject) $(LCGICC)

readroomdetails.o: readroomdetails.cc $(STRATEGY_HEADER)
	$(CC) $(CFLAG) readroomdetails.cc $(LCGICC)

strategy-main.o: strategy-main.cpp $(STRATEGY_HEADER)
	$(CC) $(CFLAG) strategy-main.cpp $(LCGICC)

strategy.html: $(Strategy)
	$(CC) $(OFLAG) strategy.html $(Strategy) $(LCGICC)

strategy-run: strategy.html
	./strategy.html

#--------------------------------------------------------------------------
#                           Validation
#--------------------------------------------------------------------------

validation.o: validation.cc $(VALIDATION_HEADER)
	$(CC) $(CFLAG) validation.cc $(LCGICC)

validation-main.o: validation-main.cpp $(VALIDATION_HEADER)
	$(CC) $(CFLAG) validation-main.cpp $(LCGICC)

validation.html: $(Validation)
	$(CC) $(OFLAG) validation.html $(Validation) $(LCGICC)

validation-run: validation.html
	./validation.html

#--------------------------------------------------------------------------
#                              Exam Details
#--------------------------------------------------------------------------

examdetails.o: examdetails.cc $(EXAM_HEADER)
	$(CC) $(CFLAG) examdetails.cc

examdetails-main.o: examdetails-main.cpp $(EXAM_HEADER)
	$(CC) $(CFLAG) examdetails-main.cpp

examdetails.html: $(Exam)
	$(CC) $(OFLAG) examdetails.html $(Exam)

exam-run: examdetails.html
	./examdetails.html

#--------------------------------------------------------------------------
#                           Generate Reports
#--------------------------------------------------------------------------

report.o: report.cc $(REPORT_HEADER)
	$(CC) $(CFLAG) report.cc $(LCGICC)

readexamdetails.o: readexamdetails.cc $(REPORT_HEADER)
	$(CC) $(CFLAG) readexamdetails.cc $(LCGICC)	

report-main.o: report-main.cpp $(REPORT_HEADER)
	$(CC) $(CFLAG) report-main.cpp $(LCGICC)

report.html: $(Report)
	$(CC) $(OFLAG) report.html $(Report) $(LCGICC)

report-run: report.html
	./report.html

#--------------------------------------------------------------------------
#                       Run make inside SeatPlan
#--------------------------------------------------------------------------

make-SeatPlan: 
	cd SeatPlan && make && cd ..

#--------------------------------------------------------------------------
#                      Copy BaKaPlan to ~/public_html
#--------------------------------------------------------------------------

cp-BaKaPlan: 
	cp -r BaKaPlan/ ~/public_html/

#--------------------------------------------------------------------------
#                      First make after download
#--------------------------------------------------------------------------

install: all cp-BaKaPlan

#--------------------------------------------------------------------------
#                  remove exe. files and o/p files
#--------------------------------------------------------------------------

clean:
	rm *.html *.o && cd SeatPlan && make clean && cd .. && rm ~public_html/seatplan.html
	
