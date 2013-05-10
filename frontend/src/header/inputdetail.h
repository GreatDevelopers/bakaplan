/*
 * ===================================================================
 *
 *       Filename:  detail.h
 *
 *    Description:  Base class for all common variable declaration and
 *                  functions that are used by derived classes
 *
 *        Version:  0.6
 *        Created:  Friday 22 February 2013 11:34:29  IST
 *       Compiler:  gcc
 *
 *         Author:  Mandeep Kaur, meghasimak@gmail.com
 *        License:  GNU General Public License
 *      Copyright:  Copyright (c) 2013, Great Developers
 *
 * ===================================================================
 */

#ifndef INPUTDETAIL_H
#define INPUTDETAIL_H

/**
 *  Include Local header files 
 */

#include "filename.h"                            /* I/O  File Names */
#include "pagelayout.h"                         /* PageLayout Class */
#include "inputfieldname.h"                 /* InputFieldName Class */
#include "readinputfield.h"                 /* ReadInputField Class */
#include "constant.h"                   /* Constants for array size */
#include "database.h"                  /* For database connectivity */

/**
 *      \class  InputDetail
 *      \brief  Declare common variables, functions that are used by
 *              derived class.
 */

class InputDetail //: public PageLayout
{
    protected:
        /* Common variables and objects */
        
        /* Objects of InputFieldName and ReadFieldsValue class  */

        InputFieldName fieldName;               /**< I/P field name */
        ReadInputField readField;               /**< Read I/P Field */
        Database database;                   /**< Accecing Database */
        PageLayout page;                             /**< HTML Tags */
        
        int i, j, k, l;                      /**< Looping Variables */

        stringstream ss;          /**< for converting int to string */
        string temp, temp1;             /**< for temporary strorage */
        // For project detail
        string projectID,                           /**< Project ID */
               emailID,                               /**< Email id */
               projectName;                       /**< Project Name */

        string fileName,            /**< file name for opening file */
               where,                     /**< Temp variable to store 
                                                       where clause */
               msg;                   /**< For Displaying error msg */

        STRING_VEC vecTemp,        /**< string Vector temporary use */
                   oldProject,                 /**< For stroring old
                                                    projects if any */
                   splitString;            /**< For storing values of 
                                                    splitted string */
 
        ifstream inFile;                      /**< For Reading file */
        ofstream outFile;                     /**< For writing file */
        string sessionID;                       /**< Session ID */

        int totalClasses,                      /**< No. of classes for 
                                                       seating plan */
            totalCols,                  /**< total Columns in table */
            totalRows,                     /**< total rows in table */
            totalDays;                 /**< No of days in datesheet */

        INT_VEC totalCentres;           /**< No of centres for exam */

        string projectType,               /**< Project Type Old/New */
               sameDetail;                      /**< For holding value
                                                yes/no for same detail 
                                                for rest of pages*/

        STRING_VEC className,                /**< Class/Branch Name */
                   subjectName,                  /**< Subject Names */
                   subjectCode,                  /**< Subject Codes */
                   classID,                   /**< Class Details ID */
                   tableHeading,             /**< For table heading */
        /* Variables for roll no detail*/
                   prefix,                   /**< Prefix of roll no */
                   startRollNo,               /**< starting roll no */
                   endRollNo,                   /**< ending roll no */
                   notIncluded,                /**< roll no's that are 
                                       not included in seating plan */
        /* variables for datsheet detail */
                   date,                   /**< Date of examination */
                   examCode,                    /**< Exam/subject code 
                                                for seating plan*/
        /* Variable for exam detail */
                     examName,                /**< Examination name */
                     examSession,      /**< Session Morning/Evening */
                     examVenue,                     /**< Exam Venue */
                     examTime,                      /**< Exam. Time */
        /* Strategy variables */
                     strategyChoice;                /**< Strategy name 
                                                   selected by user */
        /* Room Detail variables */
        STRING_2DVEC centreName,                   /**< Centre Name */
                     roomNo,            /**< Room no. in one centre */
                     rows,                        /**< Rows of room */
                     columns;                   /**< columns of room */

        /* Temp variable used for writing details into file */
        INT_VEC totalSubjects;
        INT_2DVEC totalRooms;
        STRING_2DVEC subCode, subName;
        STRING_3DVEC rmNo, row, col;

    public:
        /** Constructor */
        InputDetail(); 

        /** Header of page  */
        void Header(string titleName);

        /** Footer of page */
        void Footer();

        /** Convert Integer to string */
        string IntToString(int value);
        
        /** Convert String to Integer */
        int StringToInt(string value);

        /** Shows message if user filled data in field */
        void ErrorMessage(string msg = "");

        /** For locating current time on system */
        string Time();

        /** Spliting string  */
        void SplitString(STRING_VEC & output, 
                         string input, string token);

        /** Retruning filename w.r.t. to project ID */
        string FileName(string file, string projectID, int fileType);
};

#endif
