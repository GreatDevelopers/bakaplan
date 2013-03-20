#include "header.h"

class SeatPlan
{
    protected:
        int total_seats, total_students, room_size[MIN_SIZE][MIN_SIZE],
            total_group_seats, temp[MIN_SIZE], 
            index_value[MIN_SIZE], group_student_size[MIN_SIZE];
            
        string seat[MIN_SIZE][MIN_SIZE][MIN_SIZE][MIN_SIZE]; // seatplan array
        string seat_rollno[MIN_SIZE][MAX_SIZE], strategy_choice;
        
        int seat_size[MIN_SIZE];
        
        // Room Variables
        int total_centres, total_rooms[MIN_SIZE], rows[MIN_SIZE][MIN_SIZE], 
            cols[MIN_SIZE][MIN_SIZE];
        string room_no[MIN_SIZE][MIN_SIZE], centre_no[MIN_SIZE];
        
        // subject wise roll no 
        int total_code, sub_totalrno[MIN_SIZE],
            subject_size;
    
        string sub_subcode[MIN_SIZE], sub_rollno[MIN_SIZE][MAX_SIZE];
        
        // for loop variables
        int centre, room, row, col;
        int s, start, end, index; // temp
        
        int i, j, k, l;
        
        int size[MIN_SIZE];
        
        ifstream infile;
        ofstream outfile;

        string projectID, fileName;
        
        // exam details
        string exam_name, exam_date, exam_time, exam_venue;
    
    public:
//        SeatPlan(){cout << "Content-type:text/html\n\n";}
        void readRoomDetails(string file);
        void readSubjectWiseRollNo(string file);
        void setRollNo(int);
        string rollNo(int);
        void seatingPlan(int);
        void createFile();  
        void showSeatPlan();    
        ~SeatPlan(){}
};
