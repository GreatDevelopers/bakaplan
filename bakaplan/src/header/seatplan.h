/**
 *       \file       seatplan.h
 *
 *       \brief      Declaration of SeatPlan class for generating
 *                   seating plan
 *
 *       \version    0.6
 *       \date       Tuesday 02 April 2013 02:05:39  IST\n
 *       Compiler    g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

/**
 *  include readinput.h 
 */
#include "readinput.h"

/**
 *      \class  SeatPlan
 *      \brief  SeatPlan CLass for generating seating plan
 */

class SeatPlan : public ReadInput
{
    protected:
        
        int totalSeats,
            totalStudents,
            totalGroupSeats;

        INT_VEC iTemp, 
                indexValue, 
                groupStudentSize,
                seatSize,
                size;

        INT_2DVEC roomSize;
        
        STRING_VEC subSubCode;

        STRING_2DVEC seatRollNo, 
                     subRollNo;

        STRING_4DVEC seat;
      
        // for loop variables
        int centre, room, row, col;
        int s, start, end, index; // temp
        
    public:
        /** Constructor */
        SeatPlan();

        void SetRollNo(int);
        string RollNo(int);
        void SeatingPlan(int);
        void CreateFile(string projectID);
        void WriteSeatPlan(string projectID);

        /** Destructor */
        ~SeatPlan();

};

/* 
        int total_seats, total_students, room_size[MIN_SIZE][MIN_SIZE],
            total_group_seats, temp[MIN_SIZE], 
            index_value[MIN_SIZE], group_student_size[MIN_SIZE];
            
        string seat[MIN_SIZE][MIN_SIZE][MIN_SIZE][MIN_SIZE]; // seatplan array
        string seat_rollno[MIN_SIZE][MAX_SIZE], strategy_choice;
        
        int seat_size[MIN_SIZE];
    
        string sub_subcode[MIN_SIZE], sub_rollno[MIN_SIZE][MAX_SIZE];*/
  
