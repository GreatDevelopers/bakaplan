/**
 *       \file       main.cpp
 *
 *       \brief      Main Method
 *
 *       \version    0.6
 *       \date       Sunday 31 March 2013 08:13:40  IST\n
 *       Compiler    g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

//#include "readinput.cc"
#include "header/arrangerollno.h"

int main(void)
{
    ArrangeRollNo rNo;
    rNo.ReadClassDetail("1");
    rNo.ReadDateSheet("1");
//    rNo.expandRNo.ExpandRollNos("1");
    rNo.Main("1");

    return 0;
}
