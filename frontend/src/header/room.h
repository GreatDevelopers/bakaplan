/**
 *       \file       room.h
 *
 *       \brief      RoomDetail class
 *
 *       \version    0.8
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

#include "inputdetail.h"
#include "../backend/header/datesheet.h"

class RoomDetail : public InputDetail
{
    protected:

    DateSheet dateWiseRollNo;

    public:
        RoomDetail();
        void SetDefaultValue();
        void ReadDateSheet();
        void WriteDateSheet();
        void RoomDetailPage(bool addRoom);
        void AddMoreRooms();
        ~RoomDetail();
};

#endif
