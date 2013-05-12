/**
 *       \file       main.cpp
 *
 *       \brief      Main Method
 *
 *       \version    0.7
 *       \date       Sunday 31 March 2013 08:13:40  IST\n
 *       Compiler    g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

//#include "readinput.cc"
#include "header/datesheet.h"
#include "header/strategy.h"

int main(void)
{
    DateSheet rNo;
//    rNo.ReadClassDetail("1");
//    rNo.ReadDateSheet("1");
//    rNo.expandRNo.ExpandRollNos("1");
    string pid = "20";
    rNo.Main(pid);
    Strategy str;
    str.Main(pid);

    return 0;
}
