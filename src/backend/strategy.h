#include "seatplan.h"
//#include "report.h"

class Strategy : public SeatPlan
{
    protected:
        string rollno[MIN_SIZE][MIN_SIZE][MAX_SIZE], branch_name[MIN_SIZE],
               subject_name[MIN_SIZE][MIN_SIZE], subject_code[MIN_SIZE][MIN_SIZE];
        int total_rollno[MIN_SIZE][MIN_SIZE], total_branches, 
            total_subject[MIN_SIZE];
    
    public:
        
        Strategy();
        void chooseStrategy();
        void totalSeats(int);
        void totalStudents();
        void checkValidation(int);
        void totalGroupStudents(int);
        void groupCondition(int);
        void Main(string);
};
