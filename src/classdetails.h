/*
 * ===================================================================
 *
 *       Filename:  classdetails.h
 *
 *    Description:  Declaration of ClassDetails class to getting
 *    details like total classes, classname, subjects its code and
 *    name, etc.
 *
 *        Version:  0.6
 *        Created:  Saturday 16 February 2013 11:14:34  IST
 *       Compiler:  gcc
 *
 *         Author:  Mandeep Kaur, meghasimak@gmail.com
 *        License:  GNU General Public License
 *      Copyright:  Copyright (c) 2013, Great Developers
 *
 * ===================================================================
 */

/**-------------------------------------------------------------------
 *  Include Required Header Files
 *------------------------------------------------------------------*/

#include "header.h"
#include "pagelayout.h"
#include "inputfieldnames.h"
#include "filenames.h"

/**
 * ===================================================================
 *        Class:  ClassDetails
 *  Description:  This class is used to get details of class from
 *                user. Like class name, total classes, subject 
 *                details etc.
 * ===================================================================
 */

class ClassDetails : public PageLayout
{
    protected:

    public:
        /// Constructor
        ClassDetails();
        /// 
};
