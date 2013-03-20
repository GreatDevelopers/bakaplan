/**
 *       \file       report-main.cpp
 *
 *       \brief      Main for creating report.html page
 *
 *       \version    0.6
 *       \date       Wednesday 20 March 2013 11:36:37  IST\n
 *       Compiler    gcc
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

/**
 *  include report.h file 
 */

#include "report.h"

/** 
 *      \fn     main(void)
 *      \brief  main method to call function of Report Class
 */

int main(void)
{
    Report report;
    report.ReportPage();

    return 0;
}
