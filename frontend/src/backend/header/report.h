/**
 *       \file       report.h
 *
 *       \brief      Report class definition
 *
 *       \version    0.8
 *       \date       Wednesday 03 April 2013 05:05:51  IST\n
 *       Compiler    g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

#ifndef REPORT_H
#define REPORT_H

/**
 *  Include local header file 
 */

#include "seatplan.h"

class RoomReport :: public SeatPlan
{
    protected:

    public:
        /** Constructor */
        RoomReport();

        /** Read Exam Detail */
        void ReadExamDetail(string projectID);

        /** Read Seat Plan */
        void ReadSeatPlan(string projectID);

        /** WriteHTMLFile */
        void WriteHTMLFile(string projectID);
        
        /** Destructor */
        ~RoomReport();
};

#endif
