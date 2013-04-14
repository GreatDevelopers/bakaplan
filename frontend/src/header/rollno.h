/**
 *       \file       rollno.h
 *
 *       \brief      RollNo class declaration for taking roll no
 *                   detail
 *
 *       \version    0.6
 *       \date       Sunday 07 April 2013 07:51:45  IST\n
 *       Compiler    g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

#ifndef ROLLNO_H
#define ROLLNO_H

/**
 *  include class.h 
 */

#include "inputdetail.h"


/**
 *      \class  RollNoDetail
 *      \brief  RollNoDetail class for taking roll no detail from user
 */

class RollNoDetail : public InputDetail
{
    protected:

        int totalClasses;                      /**< No. of classes for 
                                                       seating plan */

        string projectType;               /**< Project Type Old/New */

        STRING_VEC className,                /**< Class/Branch Name */
                   subjectName,                  /**< Subject Names */
                   subjectCode,                  /**< Subject Codes */
                   tableHeading;             /**< For table heading */

    public:
        /** Roll No detail Constructor*/
        RollNoDetail();

        /** Read Class Details */
        void ReadClassDetail();

        /** Write class details in database */
        void WriteClassDetail();

        /** RollNo detail page */
        void RollNoDetailPage(string msg="");

        /** Destructor */
        ~RollNoDetail();
};

#endif
