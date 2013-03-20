/**
 *       \file       report.h
 *
 *       \brief      Report Class declaration for creating reports
 *
 *       \version    0.6
 *       \date       Wednesday 20 March 2013 11:19:17  IST\n
 *       Compiler    gcc
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

/**
 *  include inputdetail.h file 
 */

#include "inputdetail.h"
#include "backend/report.h"

/**
 *      \class  Report
 *      \brief  for creating report of seating plan
 */

class Report : public InputDetail
{
    protected:

        string examName,
               examDate,
               examTime,
               examVenue;

        RoomReport roomReport;

    public:
        
        /** Constructor  */
        Report();

        /** Report Page */
        void ReportPage();

        /** Reading exam details */
        void ReadExamDetail();

        /** Writing Exam Detail */
        void WriteExamDetail();

        /** Destructor  */
        ~Report();
};
