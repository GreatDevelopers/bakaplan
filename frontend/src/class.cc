/**
 *       \file       class.cc
 *
 *       \brief      ClassDetail function definition
 *
 *       \version    0.6
 *       \date       Sunday 07 April 2013 07:49:18  IST\n
 *       Compiler    g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

/**
 *  Include class.h 
 */
#include "header/class.h"

/**
 *      \class  ClassDetail
 *      \fn     ClassDetail :: ClassDetail()
 *      \brief  Constructor
 */

ClassDetail :: ClassDetail()
{
    // constructor

    i = 0;
    tableHeading.push_back("Class Name");//[i++]   =   "Class Name";
    tableHeading.push_back("Subject Name");//[i++]   =   "Subject Name";
    tableHeading.push_back("Subject Code");//[i++]   =   "Subject Code";

    totalClasses = 1;
}

void ClassDetail :: ProjectType()
{
//    page.ContentType();
//	cout << "Content-type:text/html\n\n\n";

    projectType = readField.ReadFieldValue(fieldName.projectType);
    emailID = readField.ReadFieldValue(fieldName.emailID);
    projectName = readField.ReadFieldValue(fieldName.projectName); 
 
    where = "EmailID = \"" + emailID + "\"";
    database.SelectColumn(oldProject, "ProjectName", "ProjectDetail",
                          where);

    if(projectType == "Old")
        OldProject();
    else
        NewProject();
		
}

void ClassDetail :: SetDefaultValue()
{
    className.resize(totalClasses);
    subjectCode.resize(totalClasses);
    subjectName.resize(totalClasses);
 
    //maxClasses      =   10;
    i = 0;
    className[i++]      =   "Info. Tech.";/*
    className[i++]      =   "IT 2nd Yr";
    className[i++]      =   "ECE";
    className[i++]      =   "Mech. Engg.";
    className[i++]      =   "Production Engg.";
    className[i++]      =   "Electrical Engg.";
    className[i++]      =   "IT";
    className[i++]      =   "Electronics Engg.";
    className[i++]      =   "Comp. Sci. Engg.";
    className[i++]      =   "MBA";*/
    
    i = 0;
    subjectName[i++]    =   "DBMS, SAD";/* 
    subjectName[i++]    =   "Maths,Physics";
    subjectName[i++]    =   "OS, EVS";
    subjectName[i++]    =   "Java, C++";
    subjectName[i++]    =   "EVS";
    subjectName[i++]    =   "Chem.";
    subjectName[i++]    =   "ED";
    subjectName[i++]    =   "Maths";
    subjectName[i++]    =   "Maths,DBMS, Physics";
    subjectName[i++]    =   "Multimedia, Dot Net, ED";
*/
    i = 0;
    subjectCode[i++]    =   "IT-101, IT-102";/*
    subjectCode[i++]    =   "ME-10,CE-252";
    subjectCode[i++]    =   "EVS, ED-10";
    subjectCode[i++]    =   "ED-10, IT-102";
    subjectCode[i++]    =   "IT-102";
    subjectCode[i++]    =   "IT-203";
    subjectCode[i++]    =   "CE-120";
    subjectCode[i++]    =   "ME-140";
    subjectCode[i++]    =   "EE-109, 1234S, IT-203";
    subjectCode[i++]    =   "ME-101,ME-501,IT-101";*/
}

void ClassDetail :: NewProject()
{

    where = "EmailID = \"" + emailID + "\"";
    database.SelectColumn(oldProject, "ProjectName", "ProjectDetail",
                          where);

    if ( ( find(oldProject.begin(), oldProject.end(), projectName) 
         != oldProject.end() ) )                 /**< If projectName 
                                                     already exists */
    {
        msg = "Project already exists.";
        project.ProjectDetailPage(msg); 
    }
    else
    {
        SetDefaultValue();

        database.InsertProjectDetail(emailID, projectName);
        
        ClassDetailPage();
    }
}

void ClassDetail :: OldProject()
{
    if ( ( find(oldProject.begin(), oldProject.end(), projectName) 
         != oldProject.end() ) )                 /**< If projectName 
                                                     already exists */
    {
        where  = "EmailID = \"" + emailID + "\" AND ProjectName =\"";
        where += projectName + "\"";

        database.SelectColumn(vecTemp, "ProjectID", "ProjectDetail", 
                              where);
    
        if(vecTemp.size() != 0)
            projectID = vecTemp[0];

        where = "ProjectID = " + projectID;

        database.SelectColumn(className, "ClassName", "ClassDetail", 
                              where);
        database.SelectColumn(subjectName, "SubjectName", "ClassDetail",
                              where);
        database.SelectColumn(subjectCode, "SubjectCode", "ClassDetail",
                              where);
        
        if(className.size() <= 0)
        {
/*             className.resize(1);
             subjectCode.resize(1);
             subjectName.resize(1);
             className[0] = "Info. Tech.";
             subjectCode[0] = "IT-102, IT 104";
             subjectName[0] = "DBMS, OOPS";
			 */
            SetDefaultValue();
        }
      
        ClassDetailPage();
    }
    else
    {
        msg = "Project doesn't exists.";
        project.ProjectDetailPage(msg); 
    }
}

void ClassDetail :: ClassDetailPage(string msg)
{
    page.ContentType();

    Header("Class Detail");

    page.DivStart("DivClass", "");

    page.LogoutLink();

    cout << page.brk;

    page.FormStart("FormClass", "rollno.html", "POST");

    cout << page.startH1 << "Class/Branch/Trade Detail" 
         << page.endH1 << page.brk;
    
    ErrorMessage(msg);

    page.InputField("hidden", fieldName.projectID, projectID);
    page.InputField("hidden", fieldName.totalClasses, 
                    IntToString(totalClasses));
    
//    cout << page.brk;
    cout << "<input type=\"button\" value=\"Add Row\" onclick=\""
         << "addRow('TableClass', 'TotalClasses', 'class')\" />";

    cout << "<input type=\"button\" value=\"Delete Row\" onclick=\""
         << "removeRow('TableClass', 'TotalClasses')\" />" 
         << page.brk << page.brk;

    page.TableStart("TableClass", "");
   
    cout << page.startTR;
    for(i = 0; i < 3; i++)
    {   
        cout << page.startTH << tableHeading[i] << page.endTH;
    }
    cout << page.endTR;

    if(projectType == "Old" && (className.size() > 1 || 
       subjectName.size() >1 || subjectCode.size() > 1 ))
    {
        for(i = 0; i < totalClasses; i++)
        {
            cout << page.startTR;
        
            cout << page.startTD;
            page.InputField("text", fieldName.className, (i + 1),
                            className[i], className[i]);
            cout << page.endTD;
        
            cout << page.startTD;
            page.InputField("text", fieldName.subjectName, (i + 1),
                            subjectName[i], subjectName[i]);
            cout << page.endTD;
        
            cout << page.startTD;
            page.InputField("text", fieldName.subjectCode, (i + 1),
                            subjectCode[i], subjectCode[i]);
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
                            className[i]);
            cout << page.endTD;
        
            cout << page.startTD;
            page.InputField("text", fieldName.subjectName, (i + 1),
                             subjectName[i]);
            cout << page.endTD;
        
            cout << page.startTD;
            page.InputField("text", fieldName.subjectCode, (i + 1),
                            subjectCode[i]);
            cout << page.endTD;

            cout << page.endTR;
        }
    }
    
    page.TableEnd();
    
    cout << page.brk << page.brk;

    page.Button("next", "submit", "btn", "NEXT");

    page.FormEnd();
    page.DivEnd();

    Footer();
}

/**
 *      \class  ClassDetail
 *      \fn     ClassDetail :: ~ClassDetail()
 *      \brief  Destructor
 */

ClassDetail :: ~ClassDetail()
{
    // destructor
}
