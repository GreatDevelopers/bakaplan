/*
 * ===================================================================
 *
 *       Filename:  inputfieldnames.h
 *
 *    Description:  Declaration of InputFieldName Class ie used to
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

#ifndef INPUTFIELDNAME_H
#define INPUTFIELDNAME_H

/**-------------------------------------------------------------------
 *  Include local header file that has global header files
 *------------------------------------------------------------------*/

#include "header.h"
                                                
/**
 * ===================================================================
 *        Class:  InputFieldName
 *  Description:  This class has variable names for all fields that
 *                are used to take input from user.
 * ===================================================================
 */

class InputFieldName
{
    public:
        // Field Names
        
        // Class Details Value                        /* Field Name */

        string className,                            /**< ClassName */
               totalClasses,                      /**< TotalClasses */
               totalSubjects,                    /**< TotalSubjects */
               subjectCode,                        /**< SubjectCode */
               subjectName,                        /**< SubjectName */
        // Roll No details fields
                prefix,                       /**< Prefix of rollno */
                startRollNo,                  /**< starting roll no */
                endRollNo,                       /**< ending rollno */
                notIncluded,                    /**< roll that are not 
                                                   included in seating 
                                                   plan */
        // For project details
                projectName,                      /**< Project Name */
                projectID,                          /**< Project ID */
                projectType;         /**< ProjectType ie new or old */

        /* For login.html page */
        string emailID,                            /**< Email Field */
               password,                        /**< Password field */
               retypePassword,                 /**< Retype Password */
               key,                           /**< Registration Key */

        /* Room detail fields  */
               totalCentres,                     /**< Total centres */
               totalRooms,      /**< Total Rooms w.r.t centers name */
               centreName,                         /**< Center Name */
               roomNo,           /**< Room Nos w.r.t to centre name */
               rows,                              /**< Rows of room */
               columns,                        /**< Columns in room */

        /* Strategy Field */
               strategyChoice, /**< Strategy option selected by user*/

        /* For Examination Details */
               examName,                      /**< Examination Name */
               examDate,                      /**< Examination Date */
               examTime,                      /**< Examination Time */
               examVenue;                    /**< Examination Venue */
               

    public:
        InputFieldName();                     /**< Constructor */
        void SetFieldNames();                 /**< Set Field Values */
};

#endif
