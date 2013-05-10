/**
 *       \file       room.h
 *
 *       \brief      RoomDetail class
 *
 *       \version    0.6
 *       \date       Sunday 07 April 2013 08:14:54  IST\n
 *       Compiler    g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

#ifndef ROOM_H
#define ROOM_H

/**
 *  include inpudetail.h 
 */

#include "inputdetail.h"
#include "../backend/header/datesheet.h"

class RoomDetail : public InputDetail
{
    protected:

    DateSheet dateWiseRollNo;

    public:
        /** Constructor */
        RoomDetail();

        /** Set Default Value */
        void SetDefaultValue();

        /** Reading Datesheet */
        void ReadDateSheet();

        /** Writing DateSheet */
        void WriteDateSheet();

        /** Room DEtail page for taking I/P from user */
        void RoomDetailPage();

        /** Desctructor */
        ~RoomDetail();
};

#endif
