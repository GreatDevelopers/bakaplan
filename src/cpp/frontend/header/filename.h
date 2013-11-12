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

/* Input/Output file names */

namespace filename
{
    
    std::map<string, string> name =
    {
        {"input", "../input"},
        {"output", "../output/"},
        {"in", ".in"},
        {"out", ".out"},

        {"classDetail", "class-detail-"},
        {"rollNoDetail", "rollno-detail-"},
        {"datesheet", "datesheet-"},
        {"examDetail", "exam-detail-"},
        {"roomDetail", "room-detail-"},
        {"strategy", "strategy-"},

        {"expandRollNo", "expand-rollno-"},
        {"arrangeRollNo", "arrange-rollno-"},
        {"validation", "validation-"},
        {"seatplan", "seatplan-"},

        {"temp", "temp-"}
    };
}

#endif

/*
 * Local Variables:
 * tab-width: 4
 * expandtab
 * ex: shiftwidth=4 tabstop=4
 */


