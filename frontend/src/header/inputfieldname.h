/**
 *
 *       \file       inputfieldname.h
 *
 *       \brief      Declaration of InputFieldName Class ie used to
 *                   store input field names.
 *
 *       \version    0.8
 *       \date       Thursday 06 June 2013 10:24:21  IST\n
 *       Compiler    g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com\n
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

#ifndef INPUTFIELDNAME_H
#define INPUTFIELDNAME_H

#include "header.h"
                                      
/**
 *      \class  InputFieldName
 *      \brief  This class has variable names for all fields that
 *              are used to take input from user.
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
               classID,                               /**< Class id */
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
               examSession,                /**< Exam. Session (M/E) */
               examTime,                      /**< Examination Time */
               examVenue,                    /**< Examination Venue */
        /* Date sheet variables */
               date,                       /**< Date of examination */
               examCode,                   /**< Exam code accord to 
                                                         date sheet */
               totalDays,              /**< Total days in datesheet */
               sameDetail,             /**< Same detail of room, exam, 
                                          strategy for seating plan */
               lastRow,                   /**< Last row index value */
               rowIndex;              /**< Index values of all rows */

    public:
        InputFieldName();                     /**< Constructor */
        void SetFieldNames();                 /**< Set Field Values */
};

#endif
