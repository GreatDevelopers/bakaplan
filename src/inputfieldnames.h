/*
 * ===================================================================
 *
 *       Filename:  inputfieldnames.h
 *
 *    Description:  Declaration of InputFieldNames Class ie used to
 *    store input field names.
 *
 *        Version:  0.6
 *        Created:  Saturday 16 February 2013 02:28:58  IST
 *       Compiler:  gcc
 *
 *         Author:  Mandeep Kaur, meghasimak@gmail.com
 *        License:  GNU General Public License
 *      Copyright:  Copyright (c) 2013, Great Developers
 *
 * ===================================================================
 */

/**-------------------------------------------------------------------
 *  Include local header file that has global header files
 *------------------------------------------------------------------*/

#include "header.h"
                                                
/**
 * ===================================================================
 *        Class:  InputFieldNames
 *  Description:  This class has variable names for all fields that
 *                are used to take input from user.
 * ===================================================================
 */

class InputFieldNames
{
    public:
        /// Field Names
        
        /// Class Details Value                 /* Field Name */

        string className,                       /* ClassName */
               totalClasses,                    /* TotalClasses */
               totalSubjects,                   /* TotalSubjects */
               subjectCode,                     /* SubjectCode */
               subjectName,                     /* SubjectName */
        /// Roll No details fields
                prefix,                         /* Prefix of rollno */
                startRollNo,                    /* starting roll no */
                endRollNo,                      /* ending rollno */
                notIncluded;                    /* roll that are not 
                                                    included in seating 
                                                    plan */
    public:
        InputFieldNames();
        void SetFieldNames();
};
