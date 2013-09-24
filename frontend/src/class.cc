/**
 *       \file       class.cc
 *
 *       \brief      ClassDetail function definition
 *
 *       \version    0.8
 *       \date       Sunday 07 April 2013 07:49:18  IST\n
 *       Compiler    g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

#include "header/class.h"

/**
 *      \class  ClassDetail
 *      \fn     ClassDetail :: ClassDetail()
 *      \brief  Constructor
 */

ClassDetail :: ClassDetail()
{
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
    if(projectName == "Select")
    {
        msg = "Select Existing Project";
        project.ProjectDetailPage(msg); 
    }
    else
    {
    int pn = StringToInt(projectName);
    projectName = oldProject[pn];
   
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

    cout << cgicc::div().set("id", "DivClass");

//    page.LogoutLink();
//
    cout << h1() << "Branch/Trade Detail" << h1();

//    page.FormStart("FormClass", "rollno", "POST", 
//                   "return ValidateClassForm(\"TotalClasses\")");

    cout << form().set("id", "FormClass").set("action", "rollno")
                  .set("method", "POST")
                  .set("onsubmit",
                       "return ValidateClassForm('TotalClasses')");

    page.InputField("hidden", fieldName.projectType, projectType);
    page.InputField("hidden", fieldName.totalClasses, 
                    IntToString(totalClasses));
  
    page.InputField("hidden", fieldName.projectID, projectID);
    page.InputField("button", "AddRow", 
                    "AddRows('TableClass', 'TotalClasses', 'class')",
                    "Add Row");
/*    
    page.InputField("button", "DeleteRow", 
                    "DeleteRow('TableClass', 'TotalClasses')",
                    "Delete Row");
*/
    cout << br() << br();

    ErrorMessage(msg);
    
    cout << table().set("id","TableClass");
   
    cout << tr();
    for(i = 0; i < totalCols; i++)
    {   
        cout << th() << tableHeading[i] << th();
    }
    cout << tr();

    rowIndex = "";

    for(i = 0; i < totalClasses; i++)
    {
        rowIndex += IntToString(i + 1);
        if((i + 1) != totalClasses)
            rowIndex += ",";

        if(projectType == "Old" && (className.size() >= 1 || 
           subjectName.size() >= 1 || subjectCode.size() >= 1 ))
        {
        
            cout << tr();
        
            cout << td();

            page.InputField("text", fieldName.className, (i + 1),
                            className[i], className[i]);
            cout << td();
        
            cout << td();
            page.InputField("text", fieldName.subjectName, (i + 1),
                            subjectName[i], subjectName[i]);
            cout << td();
        
            cout << td();
            page.InputField("text", fieldName.subjectCode, (i + 1),
                            subjectCode[i], subjectCode[i]);
            cout << td();

            cout << td();
            page.InputField("button", IntToString(i + 1), 
//                            "classSubjects('TotalClasses')",
//                            "Check Subs");
            
                            "DelRow('RowIndex', 'TotalClasses', event)",
                            "Delete Row");
            cout << td();

            cout << tr();
        
        }
        else
        {
            cout << tr();
        
            cout << td();
            page.InputField("text", fieldName.className, (i + 1),
                            className[i]);
            cout << td();
        
            cout << td();
            page.InputField("text", fieldName.subjectName, (i + 1),
                             subjectName[i]);
            cout << td();
        
            cout << td();
            page.InputField("text", fieldName.subjectCode, (i + 1),
                            subjectCode[i]);
            cout << td();

            cout << td();
            page.InputField("button", IntToString(i + 1), 
                            "DelRow('RowIndex', 'TotalClasses', event)",
                            "Delete Row");
            cout << td();

            cout << tr();
        }
    }

    lastRow = IntToString(totalClasses);

    cout << table();
    
    page.InputField("hidden", fieldName.lastRow, lastRow);
    page.InputField("hidden", fieldName.rowIndex, rowIndex);
   
    cout << br() << br();

    page.Button("next", "submit", "btn", "NEXT" );
//                "javascript:classSubjects('TotalClasses')");
//    page.InputField("submit", "submit", "", "Next");

//    page.FormEnd();
    cout << form();    
    cout << cgicc::div();

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
