/**
 *       \file       datesheet.h
 *
 *       \brief      Datesheet class for taking i/p from user about
 *                   datesheet.
 *
 *       \version    0.8
 *       \date       Sunday 07 April 2013 07:56:07  IST\n
 *       Compiler    g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

#ifndef DATESHEET_H
#define DATESHEET_H

#include "inputdetail.h"

/**
 *      \class  DateSheet
 *      \brief  Datesheet class for taking datesheet detail from user.
 */

class DateSheet : public InputDetail
{
    protected:

    public:
        DateSheet();
        void ReadRollNoDetail();
        void WriteRollNoDetail();
        void SetDefaultValue();
        void DateSheetPage();
        ~DateSheet();
};

#endif
