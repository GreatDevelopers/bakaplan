/**
 *
 *       \file       filename.h
 *
 *       \brief      Input/Output file names for class, room, roll no
 *                   detail, etc.
 *
 *       \compiler   g++\n
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       \license    GNU General Public License\n
 *       \copyright  Copyright (c) 2013, GreatDevelopers\n
 *                   https://github.com/GreatDevelopers
 */

#ifndef FILENAME_H
#define FILENAME_H

#include <iostream>
#include <map>
#include <string>

using namespace std;

/* Input/Output file names */

namespace filename
{
    
    map<string, string> name;
    
    name["input"]   =   "../input";
    name["output"]  =   "../output/";
    name["in"]      =   ".in";
    name["out"]     =   ".out";

    name["classDetail"]     =   "class-detail-";
    name["rollNoDetail"]    =   "rollno-detail-";
    name["datesheet"]       =   "datesheet-";
    name["examDetail"]      =   "exam-detail-";
    name["roomDetail"]      =   "room-detail-";
    name["strategy"]        =   "strategy-";

    name["expandRollNo"]    =   "expand-rollno-";
    name["arrangeRollNo"]   =   "arrange-rollno-";
    name["validation"]      =   "validation-";
    name["seatplan"]        =   "seatplan-";

    name["temp"]            =   "temp-";
}

#endif

/*
 * Local Variables:
 * tab-width: 4
 * expandtab
 * ex: shiftwidth=4 tabstop=4
 */

