/**
 *       \file       room.cc
 *
 *       \brief      RoomDetail class definition
 *
 *       \version    0.6
 *       \date       Sunday 07 April 2013 08:17:36  IST\n
 *       Compiler    g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

/**
 *  Include room.h 
 */
#include "header/room.h"

/**
 *      \class  RoomDetail
 *      \fn     RoomDetail :: RoomDetail()
 *      \brief  Constructor
 */

RoomDetail :: RoomDetail()
{
    // constructor
}

/**
 *      \class  RoomDetail
 *      \fn     RoomDetail :: SetDEfaultValue()
 *      \brief  Setting default values for room detail if projec is
 *              new or old project ha no room detail in database
 */

void RoomDetail :: SetDefaultValue()
{

}

/**
 *      \class  RoomDetail
 *      \fn     RoomDetail :: ReadDateSheet()
 *      \brief  Reading Date sheet I/P given by user
 */

void RoomDetail :: ReadDateSheet()
{
    page.ContentType();

    projectID = readField.ReadFieldValue(fieldName.projectID);
    projectType = readField.ReadFieldValue(fieldName.projectType);
    totalDays = StringToInt(readField.ReadFieldValue(
                            fieldName.totalDays));
    date.resize(totalDays);
    examCode.resize(totalDays);

    for(i = 0; i < totalDays; i++)
    {
        j = i + 1;
        date[i] = readField.ReadFieldValue(fieldName.date, j);
        examCode[i] = readField.ReadFieldValue(fieldName.examCode, j);
    }

    if(projectType == "Old")
    {
        where = "ProjectID = " + projectID;
        database.SelectColumn(vecTemp, "Date", "DateSheet",
                              where);

        if(vecTemp.size() > 0 )
        {
//            database.SelectSum
            where = "ProjectID = " + projectID;
            database.DeleteQuery("DateSheet", where);
        }
       
/*        database.SelectColumn(date, "Date", "DateSheet", where);

        if(date.size() <= 0)
        {
            SetDefaultValue();
        }
        else
        {
            database.SelectColumn(date, "Date", "DateSheet", where);
            database.SelectColumn(examCode, "ExamCode",
                                  "DateSheet", where);
            totalDays = date.size();
        } */
    }
    else
    {
        SetDefaultValue();
    }

    WriteDateSheet();
}

/**
 *      \class  RoomDetail
 *      \fn     RoomDetail :: WriteDateSheet()
 *      \brief  Writing Date Sheet into database
 */

void RoomDetail :: WriteDateSheet()
{
    for(i = 0; i < totalDays; i++)
    {
        database.InsertDateSheet(projectID, date[i], examCode[i]);
    }
}

/**
 *      \class  RoomDetail
 *      \fn     RoomDetail :: ~RoomDetail()
 *      \brief  Destructor to de-allocate objects
 */

RoomDetail :: ~RoomDetail()
{
    // destructor
}
