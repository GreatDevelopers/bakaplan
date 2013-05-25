/**
 *       \file       validation.cc
 *
 *       \brief      validation func. definition
 *
 *       \version    0.7
 *       \date       Sunday 07 April 2013 08:25:24  IST\n
 *       Compiler    g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

#include "header/validstrategy.h"

/**
 *      \class  ValidStrategy
 *      \fn     ValidStrategy :: ValidStrategy()
 *      \brief  Constructor
 */

ValidStrategy :: ValidStrategy()
{
    // constructor
    totalCols = 7;
    tableHeading.resize(totalCols);
    i = 0;
    tableHeading[i++] = " Date";
    tableHeading[i++] = " Selected <br> Strategy ";
    tableHeading[i++] = " Total <br> Seats ";
    tableHeading[i++] = " Total <br> Students ";
    tableHeading[i++] = " Total Strategy <br> Group Seats ";
    tableHeading[i++] = " Total Strategy <br> Group Students ";
    tableHeading[i++] = " Valid";
    addRoom = false;
}

/**
 *      \class  ValidStrategy
 *      \fn     ValidStrategy :: ReadStrategyDetail()
 *      \brief  Reading strategy value from last page
 */

void ValidStrategy :: ReadStrategyDetail()
{
    page.ContentType();
 
    projectID = readField.ReadFieldValue(fieldName.projectID);
    projectType = readField.ReadFieldValue(fieldName.projectType);
    totalDays = StringToInt(readField.ReadFieldValue(
                            fieldName.totalDays));

    sameDetail = readField.ReadFieldValue(fieldName.sameDetail);
    
    strategyChoice.resize(totalDays);

    for(i = 0; i < totalDays; i++)
    {
        j = i + 1;
        strategyChoice[i] = readField.ReadFieldValue(
                            fieldName.strategyChoice, j);
    }
    WriteStrategyDetail();
    
    validStrategy.Main(projectID);

    ReadValidStrategy();

    ValidStrategyPage();
}

void ValidStrategy :: ReadRoomDetail()
{
     ExamDetail::ReadRoomDetail();
     ExamDetail::WriteRoomDetail();
     validStrategy.Main(projectID);
     ReadValidStrategy();
     ValidStrategyPage();
}

/**
 *      \class  ValidStrategy
 *      \fn     ValidStrategy :: WriteStrategyDetail()
 *      \brief  Write strategy detail into DB
 */

void ValidStrategy :: WriteStrategyDetail()
{
    where = "ProjectID = " + projectID;
    database.SelectColumn(vecTemp, "StrategyName", 
                          "StrategyDetail", where);
    if(vecTemp.size() > 0)
    {
        database.DeleteQuery("StrategyDetail", where);
    }
    for(i = 0; i < totalDays; i++)
    {
        temp = IntToString(i + 1);
        database.InsertStrategyDetail(projectID, temp, 
                                      strategyChoice[i]);
    }
    vecTemp.clear();
    /* Writing I/P file for strategy detail */
    where = "ProjectID = " + projectID;
    database.SelectColumn(vecTemp, "Date", "DateSheet", where);
    int total = vecTemp.size();
    int Days = 1;
    vecTemp.clear();

    temp = FileName(STRATEGY, projectID, 1);
    outFile.open(temp.c_str());

    outFile << total << endl;

    for(i = 0; i < totalDays; i++)
    {
        outFile << strategyChoice[i] << endl;
        if(total > totalDays)
        {
            if(Days < total)
            {
                i--;
                Days++;
            }
        }
    }

    outFile.close();
}

/**
 *      \class  ValidStrategy
 *      \fn     ValidStrategy :: ReadValidStrategy()
 *      \brief  Reading validation file for checking strategy is valid
 *              or not
 */

void ValidStrategy :: ReadValidStrategy()
{
     
    where = "ProjectID = " + projectID;
//    cout << projectID << page.brk;
    date.clear();
    database.SelectColumn(date, "Date", "ValidStrategy", where);
    database.SelectColumn(totalSeats, "TotalSeats", 
                          "ValidStrategy", where);   
    database.SelectColumn(selectedStrategy, "SelectedStrategy", 
                          "ValidStrategy", where);
    database.SelectColumn(totalStudents, "TotalStudents", 
                          "ValidStrategy", where);
    database.SelectColumn(totalGroupSeats, "TotalGroupSeats", 
                          "ValidStrategy", where);
    database.SelectColumn(totalGroupStudents, "TotalGroupStudents", 
                          "ValidStrategy", where);
 
    valid.resize(date.size());
//    cout << date.size() << " " << totalSeats.size();
    
    for(unsigned i = 0; i < date.size(); i++)
    {
//        cout << totalGroupSeats[i];
        
        if(StringToInt(totalGroupSeats[i]) < StringToInt(totalGroupStudents[i]))
            valid[i] = "No";
        else
            valid[i] = "Yes";

        if(valid[i] == "No")
            addRoom = true;
    }

/*
    temp = FileName(VALIDATION, projectID, 0);
    inFile.open(temp.c_str());

    vecTemp.resize(totalCols);
    
    for(i = 0; i < totalDays; i++)
    {
        for(j = 0; j < totalCols; j++)
        {
            getline(inFile, temp1, '\n');
            vecTemp[j] = temp1;
            if(vecTemp[j] == "N")
                j = totalCols;
        }
    }

    inFile.close();
*/
}

/**
 *      \class  ValidStrategy
 *      \fn     ValidStrategy :: ValidStrategyPage()
 *      \brief  ValidStrategy.html page
 */

void ValidStrategy :: ValidStrategyPage()
{
//    page.ContentType();

    Header("ValidStrategy");

    page.DivStart("DivValidStrategy", "");

//    page.LogoutLink();

//    cout << page.brk;

    cout << page.startH1 << "Valid Strategy Detail" 
         << page.endH1;// << page.brk;

    if(addRoom == true)
    {
        page.FormStart("FormValid", "addroom", "POST");
    }
    else    
        page.FormStart("FormValid", "report", "post");
    
    page.InputField("hidden", fieldName.projectID, projectID);
    page.InputField("hidden", fieldName.totalDays, 
                    IntToString(totalDays));
    page.InputField("hidden", fieldName.projectType, projectType);
    page.InputField("hidden", fieldName.sameDetail, sameDetail);

    ReadValidStrategy();

    page.TableStart("TableValidStrategy", "");

    if(totalDays == 1)
        j = 1;
    else
        j = 0;

    cout << page.startTR;

    for(i = j; i < totalCols; i++)
    {   
        cout << page.startTH
             << tableHeading[i] 
             << page.endTH;        
    } 
    cout << page.endTR;
    for(i = 0; i < totalDays; i++)
    {
        cout << page.startTR;
        if(j == 0)
        {
            cout << page.startTD << date[i] << page.endTD;
        }
        cout << page.startTD << selectedStrategy[i] << page.endTD;
        cout << page.startTD << totalSeats[i] << page.endTD;
        cout << page.startTD << totalStudents[i] << page.endTD;
        cout << page.startTD << totalGroupSeats[i] << page.endTD;
        cout << page.startTD << totalGroupStudents[i] << page.endTD;
        cout << page.startTD << valid[i] << page.endTD;
        cout << page.endTR;
    }

    page.TableEnd();

    cout << page.brk << page.brk;
    
    if(addRoom == false)
        page.Button("next", "submit", "btn", "NEXT");
    else
    {
        page.InputField("hidden", "AddRoom", "True");
        cout << page.startB << "Add More Rooms" << page.endB;
        page.Button("next", "submit", "btn", "Add Rooms");
    }
    page.FormEnd();
    page.DivEnd();

    Footer();
}

/**
 *      \class  ValidStrategy
 *      \fn     ValidStrategy :: ~ValidStrategy
 *      \brief  Destructor
 */

ValidStrategy :: ~ValidStrategy()
{
    // destructor
}

