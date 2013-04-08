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

    totalClasses = 3;
}

void ClassDetail :: ProjectType()
{
//    page.ContentType();

    projectType = readField.ReadFieldValue(fieldName.projectType);
  //  cout <<  projectType;
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
        className.resize(10);
        subjectCode.resize(10);
        subjectName.resize(10);
 
        //maxClasses      =   10;
        i = 0;
        className[i++]      =   "Info. Tech.";
        className[i++]      =   "IT 2nd Yr";
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
            SetDefaultValue();

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

    page.DivStart("classdetail", "");

    page.LogoutLink();

    cout << page.brk;
   

    page.FormStart("classdetail", "rollno.html", "POST");

    cout << page.startH1 << "Class Detail" << page.endH1 << page.brk;
    
    ErrorMessage(msg);
/* 
    page.Label(fieldName.projectName, " Project Name ");
    page.InputField("text", fieldName.projectName, projectName);
    page.InputField("hidden", fieldName.emailID, userEmailID);

    cout << page.brk << page.brk
         << " Project Type ";
    page.InputField("radio", fieldName.projectType, "New");
    page.Label(fieldName.projectType, "New");

    page.InputField("radio", fieldName.projectType, "Old");
    page.Label(fieldName.projectType, "Old");
*/

    page.TableStart("classdetails", "");
    
    cout << page.startTR;
    for(i = 0; i < 3; i++)
    {   
        cout << page.startTH << tableHeading[i] << page.endTH;
    }
    cout << page.endTR;

    for(i = 0; i < totalClasses; i++)
    {
        cout << page.startTR;
        
        cout << page.startTD;
        page.InputField("text", fieldName.className, (i+1),
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
