/**
 *       \file       strategy.cc
 *
 *       \brief      Function definition
 *
 *       \version    0.6
 *       \date       Sunday 07 April 2013 08:20:41  IST\n
 *       Compiler    g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

/**
 *  include strategy.h 
 */

#include "header/strategy.h"

/**
 *      \class  Strategy
 *      \fn     Strategy :: Strategy()
 *      \brief  Constructor
 */

Strategy :: Strategy()
{
    // constructor
    strategyName.resize(6);
    
    i = 0;
    strategyName[i++] = "Select";
    strategyName[i++] = "Cushy";
    strategyName[i++] = "Flip-Flop";
    strategyName[i++] = "Triplet";
    strategyName[i++] = "Quadlet";
    strategyName[i++] = "Serpentine";

    totalCols = 2;
    tableHeading.resize(totalCols);
    i = 0;
    tableHeading[i++] = "Date";
    tableHeading[i++] = "Select Strategy Option";
}

/**
 *      \class  Strategy
 *      \fn     Strategy :: ReadExamDetail()
 *      \brief  Reading exam detail from last page filled by user
 */

void Strategy :: ReadExamDetail()
{
    page.ContentType();

    projectID = readField.ReadFieldValue(fieldName.projectID);
    projectType = readField.ReadFieldValue(fieldName.projectType);
    totalDays = StringToInt(readField.ReadFieldValue(
                            fieldName.totalDays));

    sameDetail = readField.ReadFieldValue(fieldName.sameDetail);

    examName.resize(totalDays);
    examSession.resize(totalDays);
    examTime.resize(totalDays);
    examVenue.resize(totalDays);
    date.resize(totalDays);
    
    for(i = 0; i < totalDays; i++)
    {
        j = i + 1;
        examName[i] = readField.ReadFieldValue(fieldName.examName, j);
        examSession[i] = readField.ReadFieldValue(
                         fieldName.examSession, j);
        examTime[i] = readField.ReadFieldValue(fieldName.examTime, j);
        examVenue[i] = readField.ReadFieldValue(
                       fieldName.examVenue, j);
        if(sameDetail == "No")
        {
            date[i] = readField.ReadFieldValue(fieldName.date, j);
        }
    }
    SetDefaultValue();
    WriteExamDetail();
    StrategyPage();       
}

/**
 *      \class  Strategy
 *      \fn     Strategy :: SetDefaultValue()
 *      \brief  Setting default or retrieving old values from database
 */

void Strategy :: SetDefaultValue()
{
    where = "ProjectID = " + projectID;
    database.SelectColumn(strategyChoice, "StrategyName", 
                          "StrategyDetail", where);
    if(strategyChoice.size() < unsigned(totalDays))
    {
        j = totalDays - strategyChoice.size() + 1;
        
        strategyChoice.resize(totalDays);
        for(i = j; i < totalDays; i++)
        {
            strategyChoice[i] = "";
        }
    }

}

/**
 *      \class  Strategy
 *      \fn     Strategy :: WriteExamDetail()
 *      \brief  Writing exam detail into DB
 */

void Strategy :: WriteExamDetail()
{
    where = "ProjectID = " + projectID;
    database.SelectColumn(vecTemp, "ExamName", "ExamDetail",
                          where);

    if(vecTemp.size() > 0 )
    {
        where = "ProjectID = " + projectID;
        database.DeleteQuery("ExamDetail", where);
    }
        
    vecTemp.clear();
 
    for(i = 0; i < totalDays; i++)
    {
        temp = IntToString(i + 1);
        database.InsertExamDetail(projectID, temp, examName[i],
                                  examSession[i], examTime[i],
                                  examVenue[i]);
    }

    /* Writing i/p file for date sheet */

    temp = FileName(EXAM_DETAIL, projectID, 1);
    outFile.open(temp.c_str());

    outFile << totalDays << endl;

    for(i = 0; i < totalDays; i++)
    {
        outFile << examName[i] << endl
                << examSession[i] << endl
                << examTime[i] << endl
                << examVenue[i] << endl;
    }

    outFile.close();
}

/**
 *      \class  Strategy
 *      \fn     Strategy :: StrategyPage()
 *      \brief  Strategy Page
 */

void Strategy :: StrategyPage()
{
    Header("Strategy");

    page.DivStart("DivStrategy", "");

    page.LogoutLink();

    cout << page.brk;

    page.FormStart("FormStrategy", "validation.html", "post");

    cout << page.startH1 << "Strategy" 
         << page.endH1 << page.brk;
    
    page.InputField("hidden", fieldName.projectID, projectID);
    page.InputField("hidden", fieldName.totalDays, 
                    IntToString(totalDays));
    page.InputField("hidden", fieldName.projectType, projectType);
    page.InputField("hidden", fieldName.sameDetail, sameDetail);

    page.TableStart("TableStrategy", "");
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
        j = i + 1;

        cout << page.startTR;
        if(sameDetail == "No")
        {
            cout << page.startTD;
            cout << date[i];
            page.InputField("hidden", fieldName.date, j, date[i]);
            cout << page.endTD;
        }
        cout << page.startTD;
        temp = fieldName.strategyChoice + IntToString(j);
        page.SelectFieldStart(temp);
        
        for(unsigned j = 0; j < strategyName.size(); j++)
        {
            temp = IntToString((j));
            if(strategyChoice.size() > 0 && 
               strategyChoice[i] == temp)
            {
                page.SelectOptionStart(temp, "y");
            }
            else
            {
                page.SelectOptionStart(temp, "n");
            }
            cout << strategyName[j];
            page.SelectOptionEnd();
        }

        page.SelectFieldEnd();
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
 *      \class  Strategy
 *      \fn     Strategy :: ~Strategy()
 *      \brief  Destructor
 */

Strategy :: ~Strategy()
{
    // destructor
}
