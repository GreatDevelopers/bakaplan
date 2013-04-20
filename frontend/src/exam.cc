/**
 *       \file       exam.cc
 *
 *       \brief      ExamDetail Class func. definition
 *
 *       \version    0.6
 *       \date       Sunday 07 April 2013 08:04:21  IST\n
 *       Compiler    g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

/**
 *  Include exam.h 
 */
#include "header/exam.h"

/**
 *      \class  ExamDetail
 *      \fn     ExamDetail :: ExamDetail()
 *      \brief  Constructor
 */

ExamDetail :: ExamDetail()
{
    // constructor
}

/**
 *      \class  ExamDetail
 *      \fn     ExamDetail :: SetDefaultValue()
 *      \brief  Setting Default values for exam fields if projecy is
 *              new or old project has empty detail in database
 */

void ExamDetail :: SetDefaultValue()
{

}

/**
 *      \class  ExamDetail
 *      \fn     ExamDetail :: ReadRoomDetail()
 *      \brief  Reading room details from previous page
 */

void ExamDetail :: ReadRoomDetail()
{
    page.ContentType();

    projectID = readField.ReadFieldValue(fieldName.projectID);
    projectType = readField.ReadFieldValue(fieldName.projectType);
    totalDays = StringToInt(readField.ReadFieldValue(
                            fieldName.totalDays));
     
    totalCentres.resize(totalDays);
    centreName.resize(totalDays);
    roomNo.resize(totalDays);
    rows.resize(totalDays);
    columns.resize(totalDays);
    date.resize(totalDays);

    for(i = 0; i < totalDays; i++)
    {
        j = i + 1;
        totalCentres[i] = StringToInt(readField.ReadFieldValue(
                          fieldName.totalCentres, j ));
        if(sameDetail == "No")
            date[i] = readField.ReadFieldValue("Date", j);

        for(j = 0; j < totalCentres[i]; j++)
        {
            temp1 = IntToString(i + 1) + IntToString(j + 1);

            centreName[i].resize(totalCentres[i]);
            roomNo[i].resize(totalCentres[i]);
            rows[i].resize(totalCentres[i]);
            columns[i].resize(totalCentres[i]);

            temp  = fieldName.centreName + temp1;
            centreName[i][j] = readField.ReadFieldValue(temp);

            temp = fieldName.roomNo + temp1;
            roomNo[i][j] = readField.ReadFieldValue(temp);

            temp = fieldName.rows + temp1;
            rows[i][j] = readField.ReadFieldValue(temp);

            temp = fieldName.columns + temp1;
            columns[i][i] = readField.ReadFieldValue(temp);
        }
    }

    WriteRoomDetail();

}

/**
 *      \class  ExamDetail
 *      \fn     ExamDetail :: WriteRoomDetail()
 *      \brief  After Reading, saving details in Database
 */

void ExamDetail :: WriteRoomDetail()
{
    where = "ProjectID = " + projectID;
    database.SelectColumn(vecTemp, "CentreName", "RoomDetail",
                          where);

    if(vecTemp.size() > 0 )
    {
        where = "ProjectID = " + projectID;
        database.DeleteQuery("RoomDetail", where);
    }
        
    vecTemp.clear();

    for(i = 0; i < totalDays; i++)
    {
        if(sameDetail == "No")
        {
            where += " AND Date = \"" + date[i] + "\"";
            database.SelectColumn(vecTemp, "DateSheetID", "DateSheet", 
                                  where);
        }
        else
            vecTemp.push_back("1");

        for(j = 0; j < totalCentres[i]; j++)
        {
            // here vecTemp = DateSheetId w.r.t. ProjectID and Date
            // from DateSheet Table
            database.InsertRoomDetail(projectID, vecTemp[0], 
                                      centreName[i][j], roomNo[i][j],
                                      rows[i][j], columns[i][j]);
        }
        vecTemp.clear();
    }

}

/**
 *      \class  ExamDetail
 *      \fn     ExamDetail :: ExamDetailPage()
 *      \brief  Page for taking exam detail
 */

void ExamDetail :: ExamDetailPage()
{

}

/**
 *      \class  ExamDetail
 *      \fn     ExamDetail :: ~ExamDetail()
 *      \brief  Destructor
 */

ExamDetail :: ~ExamDetail()
{
    //destructor
}

