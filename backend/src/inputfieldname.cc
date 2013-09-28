/**
 *
 *       \file       inputfieldname.cc
 *
 *       \brief      InputFieldName class for initializing input field
 *                   names.
 *
 *       \version    1.0
 *       \date       07/15/2013 11:42:23 PM\n
 *       Compiler    g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com\n
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

#include "header/inputfieldname.h"

/**
 *--------------------------------------------------------------------
 *       Class:  InputFieldName
 *      Method:  InputFieldName :: InputFieldName()
 * Description:  Constructor calls SetFieldNames()
 *--------------------------------------------------------------------
 */

InputFieldName :: InputFieldName()
{
    SetFieldNames();
}

/**
 *--------------------------------------------------------------------
 *       Class:  InputFieldName
 *      Method:  InputFieldName :: SetFieldNames()
 * Description:  Assign Values of field names in its respective
 * variables.
 *--------------------------------------------------------------------
 */

void InputFieldName :: SetFieldNames()
{
    /* Assign values of class details */

    className       =   "ClassName";
    totalClasses    =   "TotalClasses";
    totalSubjects   =   "TotalSubjects";
    subjectCode     =   "SubjectCode";
    subjectName     =   "SubjectName";
    classID         =   "ClassID";
    
    /* variable for roll no fields */

    prefix          =   "Prefix";
    startRollNo     =   "StartRollNo";
    endRollNo       =   "EndRollNo";
    notIncluded     =   "NotIncluded";

    /* Login page fields */

    emailID         =   "EmailID";
    password        =   "Password";
    retypePassword  =   "RetypePassword";
    key             =   "Key";

    /* Project Detail */

    projectName     =   "ProjectName";
    projectID       =   "ProjectID";
    projectType     =   "ProjectType";

    /* Room Detail Variables */

    totalCentres    =   "TotalCentres";
    totalRooms      =   "TotalRooms";
    centreName      =   "CentreName";
    roomNo          =   "RoomNo";
    rows            =   "Rows";
    columns         =   "Columns";

    /* Strategy field */

    strategyChoice  =   "StrategyChoice";

    /* Examination field's value */

    examName        =   "ExamName";
    examDate        =   "ExamDate";
    examSession     =   "ExamSession";
    examTime        =   "ExamTime";
    examVenue       =   "ExamVenue";

    /* Date Sheet field values */

    date            =   "Date";
    examCode        =   "ExamCode";
    totalDays       =   "TotalDays";
    
    /* Variable for holding value of same detail */
    sameDetail      =   "SameDetail";

    /* Variables for row index and last row in table */
    lastRow         =   "LastRow";
    rowIndex        =   "RowIndex";
}
