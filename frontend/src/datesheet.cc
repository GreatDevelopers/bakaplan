/**
 *       \file       datesheet.cc
 *
 *       \brief      Function definition of datesheet class
 *
 *       \version    0.7
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
    totalCols = 3;
    tableHeading.resize(totalCols);
    i = 0;
    tableHeading[i++] = "Date";
    tableHeading[i++] = "Exams Code";
    tableHeading[i++] = "Delete Row";
}

/**
 *      \class  DateSheet
 *      \fn     DateSheet :: ReadRollNoDetail()
 *      \brief  Reading roll no details filled by user
 */

void DateSheet :: ReadRollNoDetail()
{
//    page.ContentType();

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
        database.SelectColumn(date, "Date", "DateSheet", where);

        if(date.size() <= 0)
        {
            SetDefaultValue();
        }
        else
        {
            database.SelectColumn(examCode, "ExamCode",
                                  "DateSheet", where);
            totalDays = date.size();
        } 
    }
    else
    {
        SetDefaultValue();
    }

    WriteRollNoDetail();
//    DateSheetPage();
}

/**
 *      \class  DateSheet
 *      \fn     DateSheet :: WriteRollNoDetail()
 *      \brief  Writing rol no details into database
 */

void DateSheet :: WriteRollNoDetail()
{
    where = "ProjectID = " + projectID;
    database.SelectColumn(vecTemp, "Prefix", "RollNoDetail",
                          where);

    if(vecTemp.size() > 0 )
    {
        where = "ProjectID = " + projectID;
        database.DeleteQuery("RollNoDetail", where);
    }

    for(i = 0; i < totalClasses; i++)
    {
        where = "ProjectID = " + projectID + " AND SubjectCode =\"" +
                subjectCode[i] + "\" AND ClassName =\"" + className[i] 
                + "\"";

        database.SelectColumn(classID, "ClassID", "ClassDetail",
                              where);
        database.InsertRollNoDetail(projectID, classID[i], prefix[i],
                                    startRollNo[i], endRollNo[i],
                                    notIncluded[i]);
    }

    /* write roll no detail into file */

    temp = FileName(ROLLNO_DETAIL, projectID, 1);
    outFile.open(temp.c_str());

    outFile << totalClasses << endl;
    for(i = 0; i < totalClasses; i++)
    {
        trim(prefix[i]);
        trim(startRollNo[i]);
        trim(endRollNo[i]);

        erase_all(notIncluded[i], " ");

        outFile << prefix[i] << "-" << endl
                << startRollNo[i] << "-" << endRollNo[i] << endl;
        if(notIncluded[i].length() == 0)
            outFile << "0" << endl;
        else
            outFile << notIncluded[i] << endl;
    }

    outFile.close();
}

/**
 *      \class  DateSheet
 *      \fn     DateSheet :: SetDefaultValue()
 *      \brief  Setting default values for i/p field of datesheet
 */

void DateSheet :: SetDefaultValue()
{
    totalDays = 1;
    date.resize(totalDays);
    examCode.resize(totalDays);

    date[0] = "2013-05-10";
    examCode[0] = "IT-102, CSE 120";
}

/**
 *      \class  DateSheet
 *      \fn     DateSheet :: DateSheetPage()
 *      \brief  DateSheet Page for taking I/P from user
 */

void DateSheet :: DateSheetPage()
{
    page.ContentType();

    ReadRollNoDetail();

    Header("DateSheet");

    cout << cgicc::div().set("id", "DivDateSheet");

//    page.LogoutLink();


    cout << h1() << "Date Sheet" << h1();

/*    page.FormStart("FormDateSheet", "room", "POST",
                   "return ValidateDateSheetForm(\"TotalDays\")");*/
    cout << form().set("id", "FormDateSheet").set("action", "room")
                  .set("method", "POST")
                  .set("onsubmit",
                       "return ValidateDateSheetForm('TotalDays')");
   
    ErrorMessage(msg);

    page.InputField("hidden", fieldName.projectID, projectID);
    page.InputField("hidden", fieldName.totalDays, 
                    IntToString(totalDays));
    page.InputField("hidden", fieldName.projectType, projectType);
    page.InputField("hidden", fieldName.totalClasses, 
                    IntToString(totalClasses));
    page.InputField("hidden", "AddRoom", "False");

    page.InputField("button", "AddRow", 
                    "AddRows('TableDateSheet', 'TotalDays', 'date')",
                    "Add Row");
/*     
    page.InputField("button", "DeleteRow", 
                    "deleteRow('TableDateSheet', 'TotalDays')",
                    "Delete Row");
*/
    cout << br() << br();

//------------- Temp. option -----------------------------------------
    
    where = "ProjectID = " + projectID;
    
    database.SelectColumn(className, "ClassName", 
                          "ClassDetail", where);

    database.SelectColumn(subjectCode, "SubjectCode", 
                         "ClassDetail", where);
    subCode.resize(totalClasses);
    totalSubjects.resize(totalClasses);
    for(j = 0; j < totalClasses; j++)
    {
        SplitString(subCode[j], subjectCode[j], ",");
        
        totalSubjects[j] = subCode[j].size();
    }

    cout << table().set("id", "ClassDetail");

    cout << tr() 
         << th() << "Class Name" << th()
         << th() << "Subject Codes" << th()
         << tr();

    for(i = 0; i < totalClasses; i++)
    {
        cout << tr()
             << td() << className[i] << td()
             << td() << subjectCode[i];
/*        for(j = 0; j < totalSubjects[i]; j++)
        {
            trim(subCode[i][j]);
            cout << subCode[i][j] << " ";
        }*/
        cout << td();
        cout << tr();
    }

    cout << table();

    cout << br() << br();

//--------------------------------------------------------------------
    cout << table().set("id", "TableDateSheet");
   
    cout << tr();

//    cout << page.startTH << "Date" << page.endTH;

    for(i = 0; i < totalCols; i++)
    {   
        cout << th() << tableHeading[i] << th();
    }

//    cout << page.startTH << "Delete Row" << page.endTH;

    cout << tr();

    rowIndex = "";

    for(i = 0; i < totalDays; i++)
    {
        rowIndex += IntToString(i + 1);
        if((i + 1) != totalDays)
            rowIndex += ",";

        if(projectType == "Old")// && (className.size() >= 1 ) || 
//           subjectName.size() >= 1 || subjectCode.size() >= 1 ))
        {
            cout << tr();
        
            cout << td();
            page.InputField("text", fieldName.date, (i + 1),
                            date[i], date[i]);
            cout << td();

/*
            // Adding all subjects w.r.t. to class
            for(j = 0; j < totalClasses; j++)
            {
                cout << page.startTD;
                temp = fieldName.examCode + IntToString(i + 1) 
                       + IntToString(j + 1);
                page.SelectFieldStart(temp);

                page.SelectOptionStart("Select", "y");
                cout << " Select ";    
                page.SelectOptionEnd();

//                outFile << className[j] << endl
                for(k = 0; k < totalSubjects[j]; k++)
                {
                    trim(subCode[j][k]);
//                    outFile << subCode[j][k] << endl
                    page.SelectOptionStart(IntToString(k), "n");
                    cout << subCode[j][k];    
                    page.SelectOptionEnd();
                }
 
                page.SelectFieldEnd();
                cout << page.endTD;
            }*/

         
            cout << td();
            page.InputField("text", fieldName.examCode, (i + 1),
                            examCode[i], examCode[i]);
            cout << td();
        
            cout << td();
            page.InputField("button", "DeleteRow", 
                            "DelRow('RowIndex', 'TotalDays', event)",
                            "Delete Row");
            cout << td();

            cout << td();
        }
        else
        {
            cout << td();
        
            cout << td();
            page.InputField("text", fieldName.date, (i + 1),
                            date[i]);
            cout << td();
/*             // Adding all subjects w.r.t. to class
            for(j = 0; j < totalClasses; j++)
            {
                cout << page.startTD;
                temp = fieldName.examCode + IntToString(i + 1) 
                       + IntToString(j + 1);
                page.SelectFieldStart(temp);

                page.SelectOptionStart("Select", "y");
                cout << " Select ";    
                page.SelectOptionEnd();

//                outFile << className[j] << endl
                for(k = 0; k < totalSubjects[j]; k++)
                {
                    trim(subCode[j][k]);
//                    outFile << subCode[j][k] << endl
                    page.SelectOptionStart(IntToString(k), "n");
                    cout << subCode[j][k];    
                    page.SelectOptionEnd();
                }
 
                page.SelectFieldEnd();
                cout << page.endTD;
            }*/
       
            cout << td();
            page.InputField("text", fieldName.examCode, (i + 1),
                            examCode[i]);
            cout << td();

            cout << td();
            page.InputField("button", "DeleteRow", 
                            "DelRow('RowIndex', 'TotalDays', event)",
                            "Delete Row");
            cout << td();

            cout << tr();
        }
    }
    lastRow = IntToString(totalDays);

    cout << table();
  
    cout << br() << br()
         << " Same room and exam details for each day ";
    page.InputField("radio", fieldName.sameDetail, "Yes");
    cout << " Yes ";
//    page.Label(fieldName.sameDetail, "Yes");

    page.InputField("radio", fieldName.sameDetail, "No");
    cout << " No ";
//    page.Label(fieldName.sameDetail, "No");
   
    page.InputField("hidden", fieldName.lastRow, lastRow);
    page.InputField("hidden", fieldName.rowIndex, rowIndex);

    cout << br() << br();

    page.Button("next", "submit", "btn", "NEXT");

    cout << form()
         << cgicc::div();

    Footer();
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
