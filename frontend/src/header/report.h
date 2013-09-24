/**
 *       \file       report.h
 *
 *       \brief      Report class for generating reports
 *
 *       \version    0.8
 *       \date       Sunday 07 April 2013 08:27:13  IST\n
 *       Compiler    g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

#ifndef REPORT_H
#define REPORT_H

#include "inputdetail.h"

class Report : InputDetail
{
    public:
        Report();
        void ReadValidationDetail();
        void ReportPage();
        ~Report();
};

#endif
