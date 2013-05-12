/**
 *       \file       datesheet.h
 *
 *       \brief      Datesheet class for taking i/p from user
 *
 *       \version    0.7
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

/**
 *  include inputdetail.h 
 */
#include "inputdetail.h"

/**
 *      \class  DateSheet
 *      \brief  Datesheet class for taking datesheet detail from user
 */

class DateSheet : public InputDetail
{
    protected:

    public:
        /** Constructor */
        DateSheet();

        /** ReadRollNo detail */
        void ReadRollNoDetail();

        /** Write roll no detail into database */
        void WriteRollNoDetail();

        /** Setting dafalut values for datedheet page */
        void SetDefaultValue();
        
        /** DateSheet page for taking I/P from user */
        void DateSheetPage();

        /** Destructor */
        ~DateSheet();
};

#endif
