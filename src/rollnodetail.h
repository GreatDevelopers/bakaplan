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

#include "details.h"

/**
 * ===================================================================
 *        Class:  RollNoDetail
 *  Description:  RollNoDetail class for 
 * ===================================================================
 */

class RollNoDetail : public Details
{
    protected:
        /// for storing values of class details
        string prefix[MIN_SIZE],
               startRollNo[MIN_SIZE],
               endRollNo[MIN_SIZE],
               notIncluded[MIN_SIZE];
        int totalClasses;

    public:
        /// Constructor
        RollNoDetail();

        /// Reading class details from previous page using cgicc
        ReadClassDetails();
        WriteClassDetails();
};
