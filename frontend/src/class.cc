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

    totalCols = 4;
    tableHeading.resize(totalCols);
    i = 0;
    tableHeading[i++]   =   "Class Name";
    tableHeading[i++]   =   "Subject Name";
    tableHeading[i++]   =   "Subject Code";
    tableHeading[i++]   =   "Delete Row";

    totalClasses = 1;
}

/**
 *      \class  ClassDetail
 *      \fn     ClassDetail :: ProjectType()
 *      \brief  For reading project type ie old or new then calling
 *              OldProject and NewProject func. accord to that.
 */

void ClassDetail :: ProjectType()
{
//    page.ContentType();

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

/**
 *      \class  ClassDetail
 *      \fn     ClassDetail :: SetDefaultValue()
 *      \brief  Setting default values of text fields (classname,
 *              subject name, subject code)
 */

void ClassDetail :: SetDefaultValue()
{
    className.resize(totalClasses);
    subjectCode.resize(totalClasses);
    subjectName.resize(totalClasses);
//    value.resize(totalClasses);

    i = 0;
    className[i]    =   "Info. Tech";
    subjectName[i]  =   "DBMS, SAD";
    subjectCode[i]  =   "IT-101, IT 102";   
}

/**
 *      \class  ClassDetail
 *      \fn     ClassDetail :: NewProject()
 *      \brief  This func tis called if ProjectType = New
 */

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
        where = "EmailID = \"" + emailID + "\" AND ProjectName = \"" +
                projectName + "\"";

        database.SelectColumn(vecTemp, "ProjectID", "ProjectDetail",
                              where);
        projectID = vecTemp[0];

        ClassDetailPage();
    }
}

/**
 *      \class  ClassDetail
 *      \fn     ClassDetail :: OldProject()
 *      \brief  This func. is called is project type = Old
 */

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
            SetDefaultValue();
        }
        else
        {
            totalClasses = className.size();
        }
      
        ClassDetailPage();
    }
    else
    {
        msg = "Project doesn't exists.";
        project.ProjectDetailPage(msg); 
    }
}

/**
 *      \class  ClassDetail
 *      \fn     ClassDetail :: ClassDetailPage(string msg)
 *      \brief  function for displaying html page for class details
 *      \param  msg For displaying error message if any
 */

void ClassDetail :: ClassDetailPage(string msg)
{
    page.ContentType();

    Header("Class Detail");

    page.DivStart("DivClass", "");

    page.LogoutLink();

    cout << page.brk;

    page.FormStart("FormClass", "rollno", "POST");

    cout << page.startH1 << "Class/Branch/Trade Detail" 
         << page.endH1 << page.brk;
    
    ErrorMessage(msg);

    page.InputField("hidden", fieldName.projectID, projectID);
    page.InputField("hidden", fieldName.totalClasses, 
                    IntToString(totalClasses));
    page.InputField("hidden", fieldName.projectType, projectType);
    
    page.InputField("button", "AddRow", 
                    "addRows('TableClass', 'TotalClasses', 'class')",
                    "Add Row");
/*    
    page.InputField("button", "DeleteRow", 
                    "deleteRow('TableClass', 'TotalClasses')",
                    "Delete Row");*/

    cout << page.brk << page.brk;

    page.TableStart("TableClass", "");
   
    cout << page.startTR;
    for(i = 0; i < totalCols; i++)
    {   
        cout << page.startTH << tableHeading[i] << page.endTH;
    }
    cout << page.endTR;

    if(projectType == "Old" && (className.size() >= 1 || 
       subjectName.size() >= 1 || subjectCode.size() >= 1 ))
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

            cout << page.startTD;
            page.InputField("button", "DeleteRow", 
                            "delRow('TotalClasses')",
                            "Delete Row");
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

            cout << page.startTD;
            page.InputField("button", "DeleteRow", 
                            "delRow('TotalClasses')",
                            "Delete Row");
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
