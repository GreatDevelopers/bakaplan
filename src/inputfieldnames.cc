/*
 * ===================================================================
 *
 *       Filename:  inputfieldnames.cc
 *
 *    Description:  Definition of InputFieldNames's member functions.
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
 *  Include header file that contains InputFieldNames Class's
 *  Declaration
 *------------------------------------------------------------------*/

#include "inputfieldnames.cc"

/**-------------------------------------------------------------------
 *  Definition of member functions
 *------------------------------------------------------------------*/

/**
 *--------------------------------------------------------------------
 *       Class:  InputFieldNames
 *      Method:  InputFieldNames :: InputFieldNames()
 * Description:  Constructor calls SetFieldNames()
 *--------------------------------------------------------------------
 */

InputFieldNames :: InputFieldNames()
{
    SetFieldNames();
}

/**
 *--------------------------------------------------------------------
 *       Class:  InputFieldNames
 *      Method:  InputFieldNames :: SetFieldNames()
 * Description:  Assign Values of field names in its respective
 * variables.
 *--------------------------------------------------------------------
 */

void InputFieldNames :: SetFieldNames()
{
    /// Assign values of class details
    className       =   "ClassName";
    totalClasses    =   "TotalClasses";
    totalSubjects   =   "TotalSubjects";
    subjectCode     =   "SubjectCode";
    subjectName     =   "SubjectName";
}
