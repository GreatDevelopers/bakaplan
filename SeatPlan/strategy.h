//#include "seatplan.h"
#include "report.h"

class Strategy : public Report //SeatPlan
{
    protected:
//        int total_seats, total_students, room_size[MIN_SIZE][MIN_SIZE],
//            strategy_choice, total_group_seats, temp[MIN_SIZE], 
//            index_value[MIN_SIZE], group_student_size[MIN_SIZE];
//            
//        // temp
//        int s;
    
    public:
        
        Strategy();
        void chooseStrategy();
        void totalSeats(int);
        void totalStudents();
        void checkValidation(int);
        void totalGroupStudents(int);
        void groupCondition(int);
        void Main();
};
