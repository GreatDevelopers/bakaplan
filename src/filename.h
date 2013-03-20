/*
 * ===================================================================
 *
 *       Filename:  filenames.h
 *
 *    Description:  This file includes names of input and output
 *    files.
 *
 *        Version:  0.6
 *        Created:  Saturday 16 February 2013 02:24:08  IST
 *       Compiler:  gcc
 *
 *         Author:  Mandeep Kaur, meghasimak@gmail.com
 *        License:  GNU General Public License
 *      Copyright:  Copyright (c) 2013, Great Developers
 *
 * ===================================================================
 */

/**-------------------------------------------------------------------
 *  Constant Names of I/p and O/P files
 *------------------------------------------------------------------*/

#ifndef FILENAME_H
#define FILENAME_H

const int FILE_SIZE = 35;

/**
 *  Folder name for I/O files
 */

const char INPUT_FOLDER[FILE_SIZE]  =   "input/";
const char OUTPUT_FOLDER[FILE_SIZE] =   "output/";


/**-------------------------------------------------------------------
 *  Input File Names
 *------------------------------------------------------------------*/

const char PID[FILE_SIZE]   =   "PID";        /**< Project ID */
const char CLASS_DETAILS_IN[FILE_SIZE]    =   "-class-details.in";
const char TOTAL_FIELDS[FILE_SIZE]        =   "-total-fields.txt";
const char ROLLNO_DETAILS_IN[FILE_SIZE]   =   "-rollno-details.in";
const char ROOM_DETAILS_IN[FILE_SIZE]     =   "-room-details.in";
const char STRATEGY_IN[FILE_SIZE]         =   "-strategy.in";     
const char EXAM_DETAIL_IN[FILE_SIZE]     =   "-exam-details.in";

/**-------------------------------------------------------------------
 *  Output File Names
 *------------------------------------------------------------------*/

const char VALIDATION_OUT[FILE_SIZE]      =   "-validation.out";

/**
 *  Roll No. exapnading and arranging 
 */

const char RNO_EXPAND_OUT[FILE_SIZE]     =  "-rollno-expand.out";
const char RNO_ARRANGED_OUT[FILE_SIZE]   =  "-rollno-arranged.out";

/**
 *  Re-Arranged I/P file 
 */

const char INPUT_ROLLNO_OUT[FILE_SIZE]  =   "-input-rollno.out";

/**
 *  Subject Wise roll Nos. 
 */

const char SUBJECTWISE_ROLLNO_OUT[FILE_SIZE] = "-subject-rollno.out";

/**
 *  Files used for strategy programs 
 */

const char STRATEGY_RESULT[FILE_SIZE]   =   "-strategy-result.out";
const char SEATPLAN_OUT[FILE_SIZE]      =   "-seatplan.out";

/**
 *  file name for creating html file of seat plan 
 */

const char SEATPLAN_HTML_FILE[FILE_SIZE] = "../../../seatplan.html";

#endif
