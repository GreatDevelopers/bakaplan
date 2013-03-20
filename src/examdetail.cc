/**
 *       \file       examdetail.cc
 *
 *       \brief      Definition of member functions of ExamDetail
 *                   class
 *
 *       \version    0.6
 *       \date       Wednesday 20 March 2013 03:39:24  IST\n
 *       Compiler    gcc
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

/**
 *  Include examdetail.h file
 */
#include "examdetail.h"

/**
 *      \class  ExamDetail
 *      \fn     ExamDetail :: ExamDetail()
 *      \brief  Constructor
 */

ExamDetail :: ExamDetail()
{
    // constructor
}

/**
 *      \class  ExamDetail
 *      \fn     ExamDetail :: ExamDetailPage()
 *      \brief  Page for getting exam details
 */

void ExamDetail :: ExamDetailPage()
{

    ContextType();
    
    Header("Exam Detail");
    
    DivStart("examdetail", "");               /* (id, classname) */

    LogoutLink();
    
    cout << brk;
    
    cout << startH1 << " Exam Detail " << endH1 << brk;

    FormStart("examdetail", "report.html", "POST");

    projectID = readField.ReadFieldValue(fieldName.projectID);
    
    InputField("hidden", fieldName.projectID, projectID);
    
    TableStart("examdetail", "");

    cout << startTR << startTD << " Exam Name " << endTD
         << startTD;
    InputField("text", fieldName.examName, " Examination " );
    cout << endTD
         << endTR;

    cout << startTR << startTD << " Exam Date " << endTD
         << startTD;
    InputField("text", fieldName.examDate, " 12-4-2013 " );
    cout << endTD
         << endTR;

    cout << startTR << startTD << " Exam Time " << endTD
         << startTD;
    InputField("text", fieldName.examTime, " 9:00 am - 12:30 pm " );
    cout << endTD
         << endTR;

    cout << startTR << startTD << " Exam Venue " << endTD
         << startTD;
    InputField("text", fieldName.examVenue, " Venue " );
    cout << endTD
         << endTR;
    
    TableEnd();

    cout << brk << brk;

    Button("next", "submit", "btn", "NEXT");

    FormEnd();
    DivEnd();

    Footer();
}

/**
 *      \class  ExamDetail
 *      \fn     ExamDetail :: ~ExamDetail()
 *      \brief  Destructor
 */

ExamDetail :: ~ExamDetail()
{
    // destructor
}
