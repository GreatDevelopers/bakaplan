/*
 * ===================================================================
 *
 *       Filename:  classdetail.cc
 *
 *    Description:  Definition of ClassDetail's member functions.
 *
 *        Version:  0.6
 *        Created:  Saturday 16 February 2013 11:15:42  IST
 *       Compiler:  gcc
 *
 *         Author:  Mandeep Kaur, meghasimak@gmail.com
 *        License:  GNU General Public License
 *      Copyright:  Copyright (c) 2013, Great Developers
 *
 * ===================================================================
 */

/**-------------------------------------------------------------------
 *  Incude header file which has ClassDetail's declaration
 *------------------------------------------------------------------*/

#include "classdetail.h"

/**-------------------------------------------------------------------
 *  Defnition of member functions
 *------------------------------------------------------------------*/

/**
 *--------------------------------------------------------------------
 *       Class:  ClassDetail
 *      Method:  ClassDetail :: ClassDetail()
 * Description:  Constructor
 *--------------------------------------------------------------------
 */

ClassDetail :: ClassDetail()
{
    //maxClasses      =   10;
    i = 0;
    className[i++]      =   "Info. Tech.";
    className[i++]      =   "10th";
    className[i++]      =   "ECE";
    className[i++]      =   "Mech. Engg.";
    className[i++]      =   "Production Engg.";
    className[i++]      =   "Electrical Engg.";
    className[i++]      =   "IT";
    className[i++]      =   "Electronics Engg.";
    className[i++]      =   "Comp. Sci. Engg.";
    className[i++]      =   "MBA";
    
    i = 0;
    subjectName[i++]    =   "DBMS, SAD";
    subjectName[i++]    =   "Maths,Physics";
    subjectName[i++]    =   "OS, EVS";
    subjectName[i++]    =   "Java, C++";
    subjectName[i++]    =   "EVS";
    subjectName[i++]    =   "Chem.";
    subjectName[i++]    =   "ED";
    subjectName[i++]    =   "Maths";
    subjectName[i++]    =   "Maths,DBMS, Physics";
    subjectName[i++]    =   "Multimedia, Dot Net, ED";

    i = 0;
    subjectCode[i++]    =   "IT-101, IT-102";
    subjectCode[i++]    =   "ME-10,CE-252";
    subjectCode[i++]    =   "EVS, ED-10";
    subjectCode[i++]    =   "ED-10, IT-102";
    subjectCode[i++]    =   "IT-102";
    subjectCode[i++]    =   "IT-203";
    subjectCode[i++]    =   "CE-120";
    subjectCode[i++]    =   "ME-140";
    subjectCode[i++]    =   "EE-109, 1234S, IT-203";
    subjectCode[i++]    =   "ME-101,ME-501,IT-101";
    
    i = 0;
    tableHeading[i++]   =   "Class Name";
    tableHeading[i++]   =   "Total Subjects";
    tableHeading[i++]   =   "Subject Name";
    tableHeading[i++]   =   "Subject Code";
}

/**
 *--------------------------------------------------------------------\n
 *       Class:  ClassDetail \n
 *      Method:  ClassDetail :: ProjectDetail() :: ProjectDetail() \n
 * Description:  Reading project detail and store it into database \n
 *--------------------------------------------------------------------
 */

void ClassDetail :: ProjectDetail()
{
    projectName = readField.ReadFieldValue(fieldName.projectName);
    emailID     = readField.ReadFieldValue(fieldName.emailID);

    database.InsertProjectName(emailID, projectName);
    database.SelectProjectID(projectID);
}

/**
 *--------------------------------------------------------------------\n
 *       Class:  ClassDetail \n
 *      Method:  ClassDetail :: TotalClasses() \n
 * Description:  Inserting totalClasses value ito database \n
 *--------------------------------------------------------------------
 */

void ClassDetail :: TotalClasses()
{
    projectID = readField.ReadFieldValue(fieldName.projectID);
    temp = readField.ReadFieldValue(fieldName.totalClasses); 
    totalClasses = StringToInt(temp);
    
    database.InsertTotalClasses(projectID, IntToString(totalClasses));
}

/**
 *--------------------------------------------------------------------
 *       Class:  ClassDetail
 *      Method:  ClassDetail :: TotalClasses()
 * Description:  Get Total classes from user
 *--------------------------------------------------------------------
 */

void ClassDetail :: TotalClassesPage()
{

    ProjectDetail();
    ContextType();
    
    //cout << "project ID" << projectID << endl;
    Header("Total Classes");
    
    DivStart("totalclasses", "");               /* (id, classname) */

    LogoutLink();
    
    cout << brk;

    //cout << readField.ReadCookie("SessionID");

    FormStart("totalclasses", "classinfo.html", "POST");
    
    InputField("hidden", fieldName.projectID, projectID);

    cout << startH1 << " Select Total Classes " << endH1 << brk;
    
    cout << " Total Classes ";
    SelectFieldStart(fieldName.totalClasses);
    
    for(i = 1; i <= maxClasses; i++)
    {
        temp = IntToString(i);
        if(i == 5)
            SelectOptionStart(temp, "Y");
        else
            SelectOptionStart(temp, "n");
        cout << i;
        SelectOptionEnd();
    }

    SelectFieldEnd();

    cout << brk << brk;

    Button("next", "submit", "btn", "NEXT");

    FormEnd();
    DivEnd();

    Footer();
}

/**
 *--------------------------------------------------------------------
 *       Class:  ClassDetail
 *      Method:  ClassDetail :: ClassInfo()
 * Description:  Get class name, subject code and subject name from
 *               user.
 *--------------------------------------------------------------------
 */

void ClassDetail :: ClassInfoPage()
{
    //temp = readField.ReadFieldValue(fieldName.totalClasses); 
    //totalClasses = StringToInt(temp);

    TotalClasses();
    
    ContextType();
    Header("Class Details");

    DivStart("classinfo", "");                  /* (id, classname) */

    LogoutLink();

    cout << brk;

    FormStart("classinfo", "rollnodetail.html", "POST");

    InputField("hidden", fieldName.totalClasses,
               IntToString(totalClasses)); 
    InputField("hidden", fieldName.projectID, projectID);


    cout << startH1 << "Enter Class Details" << endH1 << brk;
    TableStart("classdetails", "");
    
    cout << startTR;
    for(i = 0; i < 4; i++)
    {   
        if(i != 1)
            cout << startTH << tableHeading[i] << endTH;
    }
    cout << endTR;

    for(i = 0; i < totalClasses; i++)
    {
        cout << startTR;
        
        cout << startTD;
        InputField("text", fieldName.className, (i+1), className[i]);
        cout << endTD;
        
        /* 
        cout << startTD;
        SelectFieldStart(fieldName.totalSubjects);
        for(j = 1; j <= 3; j++)
        {
            temp = IntToString(j);

            if(i >= 0 && i <= 3 && j == 2)
                SelectOptionStart(temp, "y");
            else if(i >= 4 && i <= 7 && j == 1)
                SelectOptionStart(temp, "y");
            else if((i == 8 || i == 9) && j == 3)
                SelectOptionStart(temp, "y");
            else
                SelectOptionStart(temp, "n");
            cout << j;
            SelectOptionEnd();
        }
        SelectFieldEnd();
        cout << endTD;
        */
        cout << startTD;
        InputField("text", fieldName.subjectName, (i + 1), 
                    subjectName[i]);
        cout << endTD;
        
        cout << startTD;
        InputField("text", fieldName.subjectCode, (i + 1), 
                    subjectCode[i]);
        cout << endTD;

        cout << endTR;
    }
    
    TableEnd();
    
    cout << brk << brk;          
    Button("next", "submit", "btn", "NEXT");

    FormEnd();
    DivEnd();

    Footer();
}

/**
 *--------------------------------------------------------------------\n
 *       Class:  ClassDetail \n
 *      Method:  ClassDetail :: ~ClassDetail() \n
 * Description:  Destructor \n
 *--------------------------------------------------------------------
 */

ClassDetail :: ~ClassDetail()
{
    // Desrtuctor
}
