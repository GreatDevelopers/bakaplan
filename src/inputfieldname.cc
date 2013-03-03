/*
 * ===================================================================
 *
 *       Filename:  inputfieldname.cc
 *
 *    Description:  Definition of InputFieldName's member functions.
 *
 *        Version:  0.6
 *        Created:  Saturday 16 February 2013 02:29:48  IST
 *       Compiler:  gcc
 *
 *         Author:  Mandeep Kaur, meghasimak@gmail.com
 *        License:  GNU General Public License
 *      Copyright:  Copyright (c) 2013, Great Developers
 *
 * ===================================================================
 */

/**-------------------------------------------------------------------
 *  Include header file that contains InputFieldName Class's
 *  Declaration
 *------------------------------------------------------------------*/

#include "inputfieldname.h"

/**-------------------------------------------------------------------
 *  Definition of member functions
 *------------------------------------------------------------------*/

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
    /** Assign values of class details */

    className       =   "ClassName";
    totalClasses    =   "TotalClasses";
    totalSubjects   =   "TotalSubjects";
    subjectCode     =   "SubjectCode";
    subjectName     =   "SubjectName";
    
    /** variable for roll no fields */

    prefix          =   "Prefix";
    startRollNo     =   "StartRollNo";
    endRollNo       =   "EndRollNo";
    notIncluded     =   "NotIncluded";
}