/**
 *       \file       examdetail-main.cpp
 *
 *       \brief      File having Main method for calling
 *                   ExamDetailPage() function of ExamDetail class and 
 *                   result in examdetail.html
 *
 *       \version    0.6
 *       \date       Wednesday 20 March 2013 03:46:01  IST\n
 *       Compiler    gcc
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

/**
 *  include examdetail.h file  
 */
#include "examdetail.h"

/**
 *  Main method 
 */

int main(void)
{
    ExamDetail exam;
    exam.ExamDetailPage();

    return 0;
}
