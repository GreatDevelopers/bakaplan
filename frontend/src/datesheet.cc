/**
 *       \file       datesheet.cc
 *
 *       \brief      Function definition of datesheet class
 *
 *       \version    0.6
 *       \date       Sunday 07 April 2013 07:59:55  IST\n
 *       Compiler    g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

/**
 *  include datesheet.h 
 */
#include "header/datesheet.h"

/**
 *      \class  DateSheet
 *      \fn     DateSheet :: DateSheet()
 *      \brief  Constructor
 */

DateSheet :: DateSheet()
{
    // constructor
}

/**
 *      \class  DateSheet
 *      \fn     DateSheet :: ReadRollNoDetail()
 *      \brief  Reading roll no details filled by user
 */

void DateSheet :: ReadRollNoDetail()
{
    page.ContentType();

    projectID = readField.ReadFieldValue(fieldName.projectID);
    projectType = readField.ReadFieldValue(fieldName.projectType);
    totalClasses = StringToInt(readField.ReadFieldValue(
                               fieldName.totalClasses));

    className.resize(totalClasses);
    subjectCode.resize(totalClasses);
    prefix.resize(totalClasses);
    startRollNo.resize(totalClasses);
    endRollNo.resize(totalClasses);
    notIncluded.resize(totalClasses);

    for(i = 0; i < totalClasses; i++)
    {
        j = i + 1;
        className[i] = readField.ReadFieldValue(fieldName.className,
                                                j);

        subjectCode[i] = readField.ReadFieldValue(
                         fieldName.subjectCode, j);
        
        prefix[i] = readField.ReadFieldValue(fieldName.prefix, j);

        startRollNo[i] = readField.ReadFieldValue(
                         fieldName.startRollNo, j);

        endRollNo[i] = readField.ReadFieldValue(
                       fieldName.endRollNo, j);

        notIncluded[i] = readField.ReadFieldValue(
                         fieldName.notIncluded, j);
    }
 
    if(projectType == "Old")
    {
        where = "ProjectID = " + projectID;
        database.SelectColumn(vecTemp, "Prefix", "RollNoDetail",
                              where);

        if(vecTemp.size() > 0 )
        {
//            database.SelectSum
            where = "ProjectID = " + projectID;
            database.DeleteQuery("RollNoDetail", where);
        }
       
/*        database.SelectColumn(prefix, "Prefix", "RollNoDetail", where);

        if(prefix.size() <= 0)
        {
            prefix.resize(totalClasses);
            startRollNo.resize(totalClasses);
            endRollNo.resize(totalClasses);
            notIncluded.resize(totalClasses);

//            SetDefaultValue(totalClasses);
            for(i = 0; i < totalClasses; i++)
            {
                prefix[i]       =   "";
                startRollNo[i]  =   "";
                endRollNo[i]    =   "";
                notIncluded[i]  =   "";
            }
        }
        else
        {
            database.SelectColumn(startRollNo, "StartRollNo", 
                                  "RollNoDetail", where);
            database.SelectColumn(endRollNo, "EndRollNo",
                                  "RollNoDetail", where);
            database.SelectColumn(notIncluded, "NotIncluded",
                                  "RollNoDetail", where);
        }
    */        
    }
    else
    {
        SetDefaultValue();
    }
    WriteRollNoDetail();

}

/**
 *      \class  DateSheet
 *      \fn     DateSheet :: WriteRollNoDetail()
 *      \brief  Writing rol no details into database
 */

void DateSheet :: WriteRollNoDetail()
{

}

/**
 *      \class  DateSheet
 *      \fn     DateSheet :: SetDefaultValue()
 *      \brief  Setting default values for i/p field of datesheet
 */

void DateSheet :: SetDefaultValue()
{

}

/**
 *      \class  DateSheet
 *      \fn     DateSheet :: DateSheetPage()
 *      \brief  DateSheet Page for taking I/P from user
 */

void DateSheet :: DateSheetPage()
{

}

/**
 *      \class  DateSheet
 *      \fn     DateSheet :: ~DateSheet()
 *      \brief  DEstructor
 */

DateSheet :: ~DateSheet()
{
    // destructor
}
