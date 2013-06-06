/**
 *       \file       rollno.h
 *
 *       \brief      RollNo class declaration for taking roll no
 *                   detail
 *
 *       \version    0.7
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

#include "inputdetail.h"

/**
 *      \class  RollNoDetail
 *      \brief  RollNoDetail class for taking roll no detail from user
 */

class RollNoDetail : public InputDetail
{
    public:
        RollNoDetail();
        void ReadClassDetail();
        void WriteClassDetail();
        void SetDefaultValue(int totalClasses);
        void RollNoDetailPage(string msg="");
        ~RollNoDetail();
};

#endif
