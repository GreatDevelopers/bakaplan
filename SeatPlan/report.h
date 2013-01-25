#include "seatplan.h"

class Report : public SeatPlan
{
    protected:
        string rollno[MIN_SIZE][MIN_SIZE][MAX_SIZE], branch_name[MIN_SIZE],
               subject_name[MIN_SIZE][MIN_SIZE], subject_code[MIN_SIZE][MIN_SIZE];
        int total_rollno[MIN_SIZE][MIN_SIZE], total_branches, 
            total_subject[MIN_SIZE];
    
    public:
        void readInputRollNo(string);
        void readSeatPlan(string);
        void Main();
};

class RoomReport : public Report
{
    public:
        void Main();
};

class BranchReport : public RoomReport
{
    public:
        void Main();
};
