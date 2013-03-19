/*
 * ===================================================================
 *
 *       Filename:  rollnodetails.h
 *
 *    Description:  Declaration of RollNoDetail class for getting
 *    roll no details of classes.
 *
 *        Version:  0.6
 *        Created:  Saturday 16 February 2013 11:17:00  IST
 *       Compiler:  gcc
 *
 *         Author:  Mandeep Kaur, meghasimak@gmail.com
 *        License:  GNU General Public License
 *      Copyright:  Copyright (c) 2013, Great Developers
 *
 * ===================================================================
 */

/**-------------------------------------------------------------------
 *  Include required header files
 *------------------------------------------------------------------*/

#include "inputdetail.h"

/**
 * ===================================================================
 *        Class:  RollNoDetail
 *  Description:  RollNoDetail class for 
 * ===================================================================
 */

class RollNoDetail : public InputDetail
{
    protected:
        /// for storing values of roll detail
        string prefix[MIN_SIZE],
               startRollNo[MIN_SIZE],
               endRollNo[MIN_SIZE],
               notIncluded[MIN_SIZE],
               tableHeading[MIN_SIZE];
        int totalClasses;

        // For class detail
        
        int totalBranches, totalSubjects[MIN_SIZE];
        
        string className[MIN_SIZE],
               subjectName[MIN_SIZE][MIN_SIZE],
               subjectCode[MIN_SIZE][MIN_SIZE];
        //  for splitSujects 
        string subCode[MIN_SIZE],
               subName[MIN_SIZE];

    public:
        /// Constructor
        RollNoDetail();

        /// Reading class details from previous page using cgicc
        void ReadClassDetail();

        /** For creating input file class detail */
        void WriteClassDetail();

        /** spliting subject name and subject codes */
        void SplitSubject();
        
        /** RollNoDetailPage for getting rollnos */
        void RollNoDetailPage();

};
