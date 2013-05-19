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
    totalCols = 8;
    tableHeading.resize(totalCols);
    i = 0;
    tableHeading[i++] = "Date";
    tableHeading[i++] = "Selected Strategy";
    tableHeading[i++] = "Total Seats";
    tableHeading[i++] = "Total Students";
    tableHeading[i++] = "Total Strategy Group Seats";
    tableHeading[i++] = "Total Strategy Group Students";
    tableHeading[i++] = "Valid";
    tableHeading[i++] = "Add Extra Rooms";
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

    page.LogoutLink();

    cout << page.brk;

    page.FormStart("FormValid", "report", "post");

    cout << page.startH1 << "ValidStrategy Detail" 
         << page.endH1 << page.brk;
    
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

    for(i = j; i < totalCols; i++)
    {   
        cout << page.startTR;
        cout << page.startTD << page.startB
             << tableHeading[i] 
             << page.endB << page.endTD
             << page.startTD << vecTemp[i] << page.endTD;
        
        if(vecTemp[i] == "Y")
            i = i + 1;
        else if(vecTemp[i] == "N")
            i = totalCols;
        else
            //-
        cout << page.endTR;
    }

    page.TableEnd();

    cout << page.brk << page.brk;
    
    if(vecTemp[6] == "Y")
        page.Button("next", "submit", "btn", "NEXT");
    else
        cout << page.startB << "Add More Rooms" << page.endB;

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

