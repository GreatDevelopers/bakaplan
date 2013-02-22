/*
 * ===================================================================
 *
 *       Filename:  rollnodetails.h
 *
 *    Description:  Declaration of RollNoDetails class for getting
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

#include "pagelayout.h"
#include "inputfieldnames.h"
#include "readinputfields.h"

/**
 * ===================================================================
 *        Class:  RollNoDetails
 *  Description:  RollNoDetails class for 
 * ===================================================================
 */

class RollNoDetails : public PageLayout
{
    protected:
        /// for storing values of class details
        string prefix[MIN_SIZE],
               startRollNo[MIN_SIZE],
               endRollNo[MIN_SIZE],
               notIncluded[MIN_SIZE];
        int totalClasses;

        InputFieldNames fieldName;
        ReadInputFields readField;

    public:
        /// Constructor
        RollNoDetails();

        /// Reading class details from previous page using cgicc
        ReadClassDetails();
        WriteClassDetails();
};
