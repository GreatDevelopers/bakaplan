/**
 *
 *       \file       input-fieldname.h
 *
 *       \brief      Declaration and definition of namespace fieldname
 *                   for declaring names of input fields and database
 *                   column names.
 *
 *       \compiler   g++\n
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       \license    GNU General Public License\n
 *       \copyright  Copyright (c) 2013, GreatDevelopers\n
 *                   https://github.com/GreatDevelopers
 */

#ifndef INPUT_FIELDNAME_H
#define INPUT_FIELDNAME_H

#include <iostream>
#include <map>
#include <string>

/**
 *  Defining name map for declaring input field names used in html 
 *  pages and column name of tables in database.
 */

namespace name
{
    // These names can also be used for table columns
    std::map<string, string> field = 
    {

        /* Assign values of class details */

        {"className", "ClassName"},
        {"totalClasses", "TotalClasses"},
        {"totalSubjects", "TotalSubjects"},
        {"subjectCode", "SubjectCode"},
        {"subjectName", "SubjectName"},
        {"classID","ClassID"},
    
        /* variable for roll no fields */

        {"prefix", "Prefix"},
        {"startRollNo", "StartRollNo"},
        {"endRollNo", "EndRollNo"},
        {"notIncluded", "NotIncluded"},

        /* Login page fields */

        {"emailID", "EmailID"},
        {"emailSignUp", "email-signup"},
        {"emailLogin", "email-login"},
        {"passwordLogin", "password-login"},
        {"password", "Password"},
        {"retypePassword", "RetypePassword"},
        {"key","Key"},
        {"user", "User"},
        {"sessionID", "SessionID"},
        {"sessionKey", "SessionKey"},
        {"regKey", "RegKey"},

        /* Project Detail */

        {"projectName", "ProjectName"},
        {"projectID", "ProjectID"},
        {"projectType", "ProjectType"},

        /* Room Detail Variables */

        {"totalCentres", "TotalCentres"},
        {"totalRooms", "TotalRooms"},
        {"centreName", "CentreName"},
        {"roomNo", "RoomNo"},
        {"rows", "Rows"},
        {"columns", "Columns"},

        /* Strategy field */

        {"strategyChoice", "StrategyChoice"},

        /* Examination field's value */

        {"examName", "ExamName"},
        {"examDate", "ExamDate"},
        {"examSession", "ExamSession"},
        {"examTime", "ExamTime"},
        {"examVenue", "ExamVenue"},

        /* Date Sheet field values */

        {"date", "Date"},
        {"examCode", "ExamCode"},
        {"totalDays", "TotalDays"},
    
        /* Variable for holding value of same detail */
        {"sameDetail", "SameDetail"},

        /* Variables for row index and last row in table */
        {"lastRow", "LastRow"},
        {"rowIndex", "RowIndex"}
    };

    std::map<string, string> table = 
    {

        /* Assign values of class details */

        {"user", "User"},
        {"reg", "Registration"},
        {"project", "ProjectDetail"},
        {"session", "SessionDetail"},
        {"contact", "ContactDetail"},
        {"reset","ResetPassword"}
    };
}

#endif

/*
 * Local Variables:
 * tab-width: 4
 * expandtab
 * ex: shiftwidth=4 tabstop=4
 */

