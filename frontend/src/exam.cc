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
    totalCols = 5;
    tableHeading.resize(totalCols);
    i = 0;
    tableHeading[i++] = "Date";
    tableHeading[i++] = "Name";
    tableHeading[i++] = "Session";
    tableHeading[i++] = "Time";
    tableHeading[i++] = "Venue";
}

/**
 *      \class  ExamDetail
 *      \fn     ExamDetail :: SetDefaultValue()
 *      \brief  Setting Default values for exam fields if projecy is
 *              new or old project has empty detail in database
 */

void ExamDetail :: SetDefaultValue()
{
    where = "ProjectID = " + projectID;
    if(projectType == "Old")
    {
        database.SelectColumn(examName, "ExamName", "ExamDetail", 
                              where);
        if(examName.size() > 0)
        {
            database.SelectColumn(examSession, "ExamSession", 
                                  "ExamDetail", where);
            database.SelectColumn(examTime, "ExamTime", 
                                  "ExamDetail", where);
            database.SelectColumn(examVenue, "ExamVenue", 
                                  "ExamDetail", where);
        }
    }
    if((projectType == "Old" && examName.size() <= 0) || 
        projectType == "New")
    {
        examName.resize(totalDays);
        examSession.resize(totalDays);
        examTime.resize(totalDays);
        examVenue.resize(totalDays);
        date.resize(totalDays);

        for(i = 0; i < totalDays; i++)
        {
            examName[i] = "Examination Name";
            examSession[i] = "M/E";
            examTime[i] = "9:30 am - 12:30 pm";
            examVenue[i] = "Venue/Place of Exam";
        }
    }
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
    sameDetail = readField.ReadFieldValue(fieldName.sameDetail);
      
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
            columns[i][j] = readField.ReadFieldValue(temp);
        }
    }
    
    SetDefaultValue();
    WriteRoomDetail();
    ExamDetailPage();
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
        k = i + 1;
        for(j = 0; j < totalCentres[i]; j++)
        {
            database.InsertRoomDetail(projectID, IntToString(k), 
                                      centreName[i][j], roomNo[i][j],
                                      rows[i][j], columns[i][j]);
        }
    }

}

/**
 *      \class  ExamDetail
 *      \fn     ExamDetail :: ExamDetailPage()
 *      \brief  Page for taking exam detail
 */

void ExamDetail :: ExamDetailPage()
{
    Header("Exam Detail");

    page.DivStart("DivExam", "");

    page.LogoutLink();

    cout << page.brk;

    page.FormStart("FormExam", "strategy.html", "POST");

    cout << page.startH1 << "Exam Detail" 
         << page.endH1 << page.brk;
    
    ErrorMessage(msg);

    page.InputField("hidden", fieldName.projectID, projectID);
    page.InputField("hidden", fieldName.totalDays, 
                    IntToString(totalDays));
    page.InputField("hidden", fieldName.projectType, projectType);
    page.InputField("hidden", fieldName.sameDetail, sameDetail);

    page.TableStart("TableExam", "");
    cout << page.startTR;
    
    if(totalDays == 1)
        j = 1;
    else
        j = 0;

    for(k = j; k < totalCols; k++)
    {   
        cout << page.startTH << tableHeading[k] << page.endTH;
    }
    cout << page.endTR;

    for(i = 0; i < totalDays; i++)
    {
        cout << page.startTR;
        j = i + 1;
        if(sameDetail == "No")
        {
            cout << page.startTD;
            cout << date[i];
            page.InputField("hidden", fieldName.date, j, date[i]);
            cout << page.endTD;
        }
        cout << page.startTD;
        page.InputField("text", fieldName.examName, j, examName[i]);
        cout << page.endTD;
        cout << page.startTD;
        page.InputField("text", fieldName.examSession, j, 
                         examSession[i]);
        cout << page.endTD;
        cout << page.startTD;
        page.InputField("text", fieldName.examTime, j, examTime[i]);
        cout << page.endTD;
        cout << page.startTD;
        page.InputField("text", fieldName.examVenue, j, 
                         examVenue[i]);
        cout << page.endTD;
        cout << page.endTR;
    }

    page.TableEnd();

    cout << page.brk << page.brk;

    page.Button("next", "submit", "btn", "NEXT");

    page.FormEnd();
    page.DivEnd();

    Footer();

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

