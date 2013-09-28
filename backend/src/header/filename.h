/**
 *       \file       filename.h
 *
 *       \brief      Input/Output file names for class, room, roll no
 *                   detail, etc.
 *
 *       \version    1.0
 *       \date       07/15/2013 09:43:29 PM\n
 *       Compiler    g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

#ifndef FILENAME_H
#define FILENAME_H

#include "constant.h"

/* Input/Output file names */

const auto INPUT[FILE_SIZE]   =   "../input/";
const auto OUTPUT[FILE_SIZE]  =   "../output/";
const auto IN[FILE_SIZE]      =   ".in";
const auto OUT[FILE_SIZE]     =   ".out";

const auto CLASS_DETAIL[FILE_SIZE]   = "class-detail-";
const auto ROLLNO_DETAIL[FILE_SIZE]  = "rollno-detail-";
const auto DATESHEET[FILE_SIZE]      = "datesheet-";
const auto EXAM_DETAIL[FILE_SIZE]    = "exam-detail-";
const auto ROOM_DETAIL[FILE_SIZE]    = "room-detail-";
const auto STRATEGY[FILE_SIZE]       = "strategy-";

const auto EXPAND_ROLLNO[FILE_SIZE]  = "expand-rollno-";
const auto ARRANGE_ROLLNO[FILE_SIZE] = "arrange-rollno-";
const auto VALIDATION[FILE_SIZE]     = "validation-";
const auto SEATPLAN[FILE_SIZE]       = "seatplan-";

const auto TEMP[FILE_SIZE] = "temp-";

#endif
