/**
 *       \file       rollno.cc
 *
 *       \brief      RollNo detail Class definition
 *
 *       \version    0.6
 *       \date       Sunday 07 April 2013 07:53:57  IST\n
 *       Compiler    g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

/**
 *  include rollno.h 
 */
#include "header/rollno.h"

/**
 *      \class  RollNoDetail
 *      \fn     RollNoDetail :: RollNoDetail()
 *      \brief  Constructor
 */

RollNoDetail :: RollNoDetail()
{
    // constructor
    totalCols = 6;
    tableHeading.resize(totalCols);

    i = 0;
    tableHeading[i++] = "Class Name";    
    tableHeading[i++] = "Subject Code";
    tableHeading[i++] = "Prefix";
    tableHeading[i++] = "Start Roll No.";
    tableHeading[i++] = "End Roll No.";
    tableHeading[i++] = "Not Included";
}

/**
 *      \class  RollNoDetail
 *      \fn     RollNoDetail :: ReadClassDetail()
 *      \brief  Reading class details from previous page and store
 *              them into database
 */

void RollNoDetail :: ReadClassDetail()
{

//    page.ContentType();

    projectID = readField.ReadFieldValue(fieldName.projectID);
    projectType = readField.ReadFieldValue(fieldName.projectType);
    totalClasses = StringToInt(readField.ReadFieldValue(
                               fieldName.totalClasses));

    className.resize(totalClasses);
    subjectName.resize(totalClasses);
    subjectCode.resize(totalClasses);

    for(i = 0; i < totalClasses; i++)
    {
        j = i + 1;
        className[i] = readField.ReadFieldValue(fieldName.className,
                                                j);

        subjectName[i] = readField.ReadFieldValue(
                         fieldName.subjectName, j);
        
        subjectCode[i] = readField.ReadFieldValue(
                         fieldName.subjectCode, j);
    }
 
    if(projectType == "Old")
    {
        where = "ProjectID = " + projectID;
        database.SelectColumn(vecTemp, "ClassName", "ClassDetail",
                              where);
/*       for(unsigned i = 0; i < vecTemp.size(); i++)
            cout << vecTemp[i]; 
*/

        if(vecTemp.size() > 0 )
        {
//            database.SelectSum
            where = "ProjectID = " + projectID;
            database.DeleteQuery("ClassDetail", where);
        }
        
        database.SelectColumn(prefix, "Prefix", "RollNoDetail", where);

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
            
    }
    else
    {
        SetDefaultValue(totalClasses);
    }
    WriteClassDetail();
}

/**
 *      \class  RollNoDetail
 *      \fn     RollNoDetail :: SetDefaultValue(int totalClasses)
 *      \brief  Setting default valued of i/p fields for taking i/p
 *              from user
 *      \param  totalClasses Total no. of rows/classes
 */

void RollNoDetail :: SetDefaultValue(int totalClasses)
{
    prefix.resize(totalClasses);
    startRollNo.resize(totalClasses);
    endRollNo.resize(totalClasses);
    notIncluded.resize(totalClasses);

    for(i = 0; i < totalClasses; i++)
    {
        prefix[i]       =   "Roll No Prefix";
        startRollNo[i]  =   "101";
        endRollNo[i]    =   "200";
        notIncluded[i]  =   "101-103, 190, 199";
    }
}

/**
 *      \class  RollNoDetail
 *      \fn     RollNoDetail :: WriteClassDetail()
 *      \brief  Write class details into database
 */

void RollNoDetail :: WriteClassDetail()
{
    for(i = 0; i < totalClasses; i++)
    {
        database.InsertClassDetail(projectID, className[i], 
                                   subjectName[i], subjectCode[i]);
    }
}

/**
 *      \class  RollNoDetail
 *      \fn     RollNoDetail :: RollNoDetailPage(string msg)
 *      \brief  RollNo detail page for taking i/p from user
 *      \param  msg For displaying error msg if any
 */

void RollNoDetail :: RollNoDetailPage(string msg)
{
    page.ContentType();

    ReadClassDetail();

    Header("Roll No Detail");

    page.DivStart("DivRollNo", "");

    cout << page.brk;

    page.FormStart("FormRollNo", "datesheet.html", "POST");

    cout << page.startH1 << "Roll No Detail" << page.endH1 << page.brk;
    
    ErrorMessage(msg);

    page.InputField("hidden", fieldName.projectID, projectID);
    page.InputField("hidden", fieldName.totalClasses, 
                    IntToString(totalClasses));
    page.InputField("hidden", fieldName.projectType, projectType);

    page.TableStart("TableRollNo", "");

    cout << page.startTR;
    for(i = 0; i < totalCols; i++)
    {   
        cout << page.startTH << tableHeading[i] << page.endTH;
    }
    cout << page.endTR;

    if(projectType == "Old")// && (prefix.size() > 1 || 
//       subjectName.size() >1 || subjectCode.size() > 1 ))
    {
        for(i = 0; i < totalClasses; i++)
        {
            cout << page.startTR;
        
            cout << page.startTD;
            page.InputField("text", fieldName.className, (i + 1),
                            className[i], className[i]);
            cout << page.endTD;
       
            cout << page.startTD;
            page.InputField("text", fieldName.subjectCode, (i + 1),
                            subjectCode[i], subjectCode[i]);
            cout << page.endTD;
        
            cout << page.startTD;
            page.InputField("text", fieldName.prefix, (i + 1),
                            prefix[i], prefix[i]);
            cout << page.endTD;
         
            cout << page.startTD;
            page.InputField("text", fieldName.startRollNo, (i + 1),
                            startRollNo[i], startRollNo[i]);
            cout << page.endTD;
         
            cout << page.startTD;
            page.InputField("text", fieldName.endRollNo, (i + 1),
                            endRollNo[i], endRollNo[i]);
            cout << page.endTD;
         
            cout << page.startTD;
            page.InputField("text", fieldName.notIncluded, (i + 1),
                            notIncluded[i], notIncluded[i]);
            cout << page.endTD;
 
            cout << page.endTR;
        }
    }
    else
    {
        for(i = 0; i < totalClasses; i++)
        {
            cout << page.startTR;
        
            cout << page.startTD;
            page.InputField("text", fieldName.className, (i + 1),
                            className[i], className[i]);
            cout << page.endTD;
        
            cout << page.startTD;
            page.InputField("text", fieldName.subjectCode, (i + 1),
                            subjectCode[i], subjectCode[i]);
            cout << page.endTD;
        
            cout << page.startTD;
            page.InputField("text", fieldName.prefix, (i + 1),
                            prefix[i]);
            cout << page.endTD;
         
            cout << page.startTD;
            page.InputField("text", fieldName.startRollNo, (i + 1),
                            startRollNo[i]);
            cout << page.endTD;
         
            cout << page.startTD;
            page.InputField("text", fieldName.endRollNo, (i + 1),
                            endRollNo[i]);
            cout << page.endTD;
         
            cout << page.startTD;
            page.InputField("text", fieldName.notIncluded, (i + 1),
                            notIncluded[i]);
            cout << page.endTD;
 
            cout << page.endTR;
        }
    }
 
    page.TableEnd();

    cout << page.brk << page.brk;
    
    page.Button("next", "submit", "btn", "Next");

    page.FormEnd();
    page.DivEnd();

    Footer();
}

/**
 *      \class  RollNoDetail
 *      \fn     RollNoDetail :: ~RollNoDetail()
 *      \brief  Destructor
 */

RollNoDetail :: ~RollNoDetail()
{
    // destructor
}
