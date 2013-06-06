/**
 *
 *       \file       inputdetail.h
 *
 *       \brief      Base class for all common variable declaration and
 *                   functions that are used by derived classes
 *
 *       \version    0.7
 *       \date       Thursday 06 June 2013 10:20:20  IST\n
 *       Compiler    g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com\n
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

#ifndef INPUTDETAIL_H
#define INPUTDETAIL_H

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
        
        
        int i, j, k, l;                      /**< Looping Variables */

        stringstream ss;          /**< For converting int to string */
        string temp, temp1;             /**< For temporary strorage */
        // For project detail
        string projectID,                           
               emailID,                           
               projectName;                     

        string fileName,            /**< File name for opening file */
               where,                     /**< Temp variable to store 
                                                       where clause */
               msg;                   /**< For Displaying error 
                                                            message */

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
               sameDetail,                      /**< For holding value
                                                yes/no for same detail 
                                                for rest of pages*/
               lastRow,                 /**< Last row id for tables */
               rowIndex;                        /**< Row index for 
                                            defining available rows */

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
                     columns,                  /**< columns of room */
                     roomInfo;      /**< Room Detail filled by user */

        /* Temp variable used for writing details into file */
        INT_VEC totalSubjects;
        INT_2DVEC totalRooms;
        STRING_2DVEC subCode, subName;
        STRING_3DVEC rmNo, row, col;

        STRING_VEC hours, minutes, ampm;

    public:
    
        /* Objects of InputFieldName and ReadFieldsValue class  */

        InputFieldName fieldName;               /**< I/P field name */
        ReadInputField readField;               /**< Read I/P Field */
        Database database;                   /**< Accecing Database */
        PageLayout page;                             /**< HTML Tags */

        InputDetail(); 
        void Header(string titleName);
        void Footer();
        string IntToString(int value);
        int StringToInt(string value);
        void ErrorMessage(string msg = "");
        string Time();
        void SplitString(STRING_VEC & output, 
                         string input, string token);
        string FileName(string file, string projectID, int fileType);
};

#endif
