/**
 *
 *       \file       input-fieldname.h
 *
 *       \brief      Declaration and definition of namespace fieldname
 *                   for declaring names of input fields
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
 *  name map for declaring input field names used in html pages. 
 */

namespace fieldname
{
    map<string, string> name;

    /* Assign values of class details */

    name["className"]       =   "ClassName";
    name["totalClasses"]    =   "TotalClasses";
    name["totalSubjects"]   =   "TotalSubjects";
    name["subjectCode"]     =   "SubjectCode";
    name["subjectName"]     =   "SubjectName";
    name["classID"]         =   "ClassID";
    
    /* variable for roll no fields */

    name["prefix"]          =   "Prefix";
    name["startRollNo"]     =   "StartRollNo";
    name["endRollNo"]       =   "EndRollNo";
    name["notIncluded"]     =   "NotIncluded";

    /* Login page fields */

    name["emailID"]         =   "EmailID";
    name["password"]        =   "Password";
    name["retypePassword"]  =   "RetypePassword";
    name["key"]             =   "Key";

    /* Project Detail */

    name["projectName"]     =   "ProjectName";
    name["projectID"]       =   "ProjectID";
    name["projectType"]     =   "ProjectType";

    /* Room Detail Variables */

    name["totalCentres"]    =   "TotalCentres";
    name["totalRooms"]      =   "TotalRooms";
    name["centreName"]      =   "CentreName";
    name["roomNo"]          =   "RoomNo";
    name["rows"]            =   "Rows";
    name["columns"]         =   "Columns";

    /* Strategy field */

    name["strategyChoice"]  =   "StrategyChoice";

    /* Examination field's value */

    name["examName"]        =   "ExamName";
    name["examDate"]        =   "ExamDate";
    name["examSession"]     =   "ExamSession";
    name["examTime"]        =   "ExamTime";
    name["examVenue"]       =   "ExamVenue";

    /* Date Sheet field values */

    name["date"]            =   "Date";
    name["examCode"]        =   "ExamCode";
    name["totalDays"]       =   "TotalDays";
    
    /* Variable for holding value of same detail */
    name["sameDetail"]      =   "SameDetail";

    /* Variables for row index and last row in table */
    name["lastRow"]         =   "LastRow";
    name["rowIndex"]        =   "RowIndex";
}

#endif

/*
 * Local Variables:
 * tab-width: 4
 * expandtab
 * ex: shiftwidth=4 tabstop=4
 */

