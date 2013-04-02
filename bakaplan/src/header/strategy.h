/**
 *       \file       strategy.h
 *
 *       \brief      Strategy class for checking selected strategy is
 *                   valid for seating plan or not.
 *
 *       \version    0.6
 *       \date       Tuesday 02 April 2013 02:09:24  IST\n
 *       Compiler    g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

/**
 *  include seatplan.h file 
 */

#include "seatplan.h"

/**
 *      \class  Strategy
 *      \brief  Strategy class to check selected strategy is valid or
 *              not for seating plan
 */

class Strategy : public SeatPlan
{
    protected:
/*         
        string rollno[MIN_SIZE][MIN_SIZE][MAX_SIZE], 
               branch_name[MIN_SIZE],
               subject_name[MIN_SIZE][MIN_SIZE], 
               subject_code[MIN_SIZE][MIN_SIZE];
        int total_rollno[MIN_SIZE][MIN_SIZE], total_branches, 
            total_subject[MIN_SIZE];
 */
    public:
        /** Constructor */
        Strategy();

        void ChooseStrategy();
        void TotalSeats(int);
        void TotalStudents();
        void CheckValidation(int strategy);
        void TotalGroupStudents(int);
        void GroupCondition(int);

        void Main(string pID);

        /** Destructor */
        ~Strategy();
};
