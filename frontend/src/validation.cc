/**
 *       \file       validation.cc
 *
 *       \brief      validation func. definition
 *
 *       \version    0.6
 *       \date       Sunday 07 April 2013 08:25:24  IST\n
 *       Compiler    g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

#include "header/validation.h"

/**
 *      \class  Validation
 *      \fn     Validation :: Validation()
 *      \brief  Constructor
 */

Validation :: Validation()
{
    // constructor
   
}

/**
 *      \class  Validation
 *      \fn     Validation :: ReadStrategyDetail()
 *      \brief  Reading strategy value from last page
 */

void Validation :: ReadStrategyDetail()
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
}

/**
 *      \class  Validation
 *      \fn     Validation :: WriteStrategyDetail()
 *      \brief  Write strategy detail into DB
 */

void Validation :: WriteStrategyDetail()
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

    temp = FileName(STRATEGY, projectID, 1);
    outFile.open(temp.c_str());

    outFile << totalDays << endl;

    for(i = 0; i < totalDays; i++)
    {
        outFile << strategyChoice[i] << endl;
    }

    outFile.close();
}

/**
 *      \class  Validation
 *      \fn     Validation :: ValidationPage()
 *      \brief  Validation.html page
 */

void Validation :: ValidationPage()
{
    page.ContentType();

}

/**
 *      \class  Validation
 *      \fn     Validation :: ~Validation
 *      \brief  Destructor
 */

Validation :: ~Validation()
{
    // destructor
}

