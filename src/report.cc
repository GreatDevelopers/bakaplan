/**
 *       \file       report.cc
 *
 *       \brief      For definition of memver func. of Report Class
 *
 *       \version    0.6
 *       \date       Wednesday 20 March 2013 11:26:30  IST\n
 *       Compiler    gcc
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

/**
 *  include report.h file 
 */

#include "report.h"

/**
 *      \class  Report
 *      \fn     Report :: Report()
 *      \brief  constructor
 */

Report :: Report()
{
    // constructor
}

/**
 *      \class  Report
 *      \fn     Report :: ReadExamDetail()
 *      \brief  For reading exam details, storing values into database
 *              and creating I/P file
 */

void Report :: ReadExamDetail()
{
    projectID = readField.ReadFieldValue(fieldName.projectID);

    examName = readField.ReadFieldValue(fieldName.examName);
    examDate = readField.ReadFieldValue(fieldName.examDate);
    examTime = readField.ReadFieldValue(fieldName.examTime);
    examVenue = readField.ReadFieldValue(fieldName.examVenue);

    database.InsertExamDetail(projectID, examName, examDate, examTime,
                              examVenue);

    WriteExamDetail();

}

/**
 *      \class  Report
 *      \fn     Report :: WrietExamDetail()
 *      \brief  Creating I/P file for exam detail
 */

void Report :: WriteExamDetail()
{
    fileName  = INPUT_FOLDER;
    fileName += PID + projectID + EXAM_DETAIL_IN;

    outFile.open(fileName.c_str());
    
    outFile << examName << endl
            << examDate << endl
            << examTime << endl
            << examVenue << endl;

    outFile.close();
}

/**
 *      \class  Report
 *      \fn     Report :: ReportPage()
 *      \brief  For creating page for report generation
 */

void Report :: ReportPage()
{
    ContextType();
    
    Header("Report");
    
    DivStart("report", "");               /* (id, classname) */

    LogoutLink();
    
    cout << brk;

    ReadExamDetail();
    
    roomReport.Main(projectID);
    
    cout << startH1 << " Report " << endH1 << brk;

    FormStart("report", SEATPLAN_HTML_FILE, "POST");
    
    InputField("hidden", fieldName.projectID, projectID);
    
    cout << brk << brk;

    Button("next", "submit", "btn", "NEXT");

    FormEnd();
    DivEnd();

    Footer();

}

/**
 *      \class  Report
 *      \fn     Report :: ~Report()
 *      \brief  Destructor
 */

Report :: ~Report()
{
    // destructor
}
