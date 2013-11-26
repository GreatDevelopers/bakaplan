/**
 *       \file       seatplan.h
 *
 *       \brief      Declaration of SeatPlan class for generating
 *                   seating plan
 *
 *       \version    0.8
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
            totalGroupSeats,
            day;

        INT_VEC iTemp, 
                indexValue, 
                groupStudentSize,
                seatSize,
                size;

        INT_3DVEC roomSize;
        
        STRING_VEC subSubCode;

        STRING_2DVEC seatRollNo, 
                     subRollNo;

        STRING_3DVEC rollNoInRoom;

        STRING_4DVEC seat,
                     totalRollNoInRoom;
        
 //       set<set<set<set<string> > > > totalRollNoInRoom;
       // set<string> sortedString;
        
        //PDF variables
        
        int textWidth,textWidth1;
        int rectWidth;
        int x,
            y,
            width, 
            height;
      
        // for loop variables
        int centre, room, room1, row, col;
        int s, start, end, index; // temp
        
    public:
        /** Constructor */
        SeatPlan();

        void SetRollNo(int strategy, int i);
        string RollNo(int s);
        void SeatingPlan(int strategy, int i);
        void CreateFile(string projectID);
        void WriteSeatPlan(string projectID, int i);
        void WriteHTMLFile(string projectID, int i);
        void WritePDFFile(string projectID, int i);
        void AddRollNoInfo(string projectID, int i);

        /** Destructor */
        ~SeatPlan();

};
