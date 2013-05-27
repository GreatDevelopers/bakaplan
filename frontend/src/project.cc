/**
 *       \file       projectdetail.cc
 *
 *       \brief      Function definition of ProjectDetail class
 *
 *       \version    0.7
 *       \date       Sunday 07 April 2013 03:27:02  IST\n
 *       Compiler    g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

/**
 *  include projectdetail.h 
 */
#include "header/project.h"

/**
 *--------------------------------------------------------------------\n
 *       Class:  ProjectDetail \n
 *      Method:  ProjectDetail :: ProjectDetail() \n
 * Description:  Constructor of ProjectDetail \n
 *--------------------------------------------------------------------
 */

ProjectDetail :: ProjectDetail()
{
    // Constructor
}

/**
 *--------------------------------------------------------------------\n
 *       Class:  ProjectDetail \n
 *      Method:  ProjectDetail :: AuthorizeUser() \n
 * Description:  Checking user login details valid or invalid \n
 *--------------------------------------------------------------------
 */

void ProjectDetail :: AuthorizeUser()
{
//    page.ContentType();
    SelectLoginDetail();
    ReadLoginDetail();
    
    /** Matching user details with values in database */
    if ( ( find(emailID.begin(), emailID.end(), userEmailID) 
         != emailID.end() ) )                /**< If Email ID valid */
    {
        temp = md5(userPassword);
        
        where = "EmailID = \"" + userEmailID + "\"";
        database.SelectColumn(vecTemp, "Password", "User", where);

        if( temp == vecTemp[0] )   /**< If Password Correct */
        {
            sessionID  = md5(userEmailID);
        
            currentTime = Time();
            
            sessionID += md5(currentTime);
           
            database.InsertSessionDetail(userEmailID, sessionID);
            
            page.SetCookies(userEmailID, sessionID);

            ProjectDetailPage();
        }
        else                             /**< If Password Incorrect */
        {
            msg = "Incorrect Password!";
            LoginPage( msg, userEmailID, userPassword );
        }
    }
    else                                   /**< If Email ID invalid */
    {
        msg = "Incorrect Email ID!";
        
        LoginPage( msg, userEmailID, userPassword );
    }
}

/**
 *--------------------------------------------------------------------\n
 *       Class:  ProjectDetail \n
 *      Method:  ProjectDetail :: ProjectDetailPage() \n
 * Description:  Diplaying page for project details \n
 *--------------------------------------------------------------------
 */

void ProjectDetail :: ProjectDetailPage(string msg, string projectName)
{
    if(msg != "")
        userEmailID = readField.ReadFieldValue(fieldName.emailID);
    page.ContentType();

    Header("Project Detail");
  
    page.DivStart("DivProject", "");

//    page.LogoutLink();

    cout << page.startH1 << "Project Detail" << page.endH1;// << page.brk;

    page.FormStart("FormProject", "class", "GET");
     
    ErrorMessage(msg);
  
    page.Label(fieldName.projectName, " Project Name ");
    page.InputField("text", fieldName.projectName, projectName);
    page.InputField("hidden", fieldName.projectType, "New"); 
    page.InputField("hidden", fieldName.emailID, userEmailID);

/*  
    if(oldProject.size() > 0)
    {
        cout << page.brk << page.brk
             << " Project Type ";
        page.InputField("radio", fieldName.projectType, "New");
        page.Label(fieldName.projectType, "New");

        page.InputField("radio", fieldName.projectType, "Old");
        page.Label(fieldName.projectType, "Old");
    }
    else
    {
        page.InputField("hidden", fieldName.projectType, "New");
    }
*/

    cout << page.brk << page.brk;
    page.Button("next", "submit", "btn", "Start New Project");

    page.FormEnd();
    OldProject();
    page.DivEnd();

    Footer();
}

/**
 *      \class  ProjectDetail
 *      \fn     ProjectDetail :: OldProject()
 *      \brief  List Existing projects from database
 */

void ProjectDetail :: OldProject()
{
// For getting previous projects of user
    
    where = "EmailID = \"" + userEmailID + "\"";

    database.SelectColumn(oldProject, "ProjectName", "ProjectDetail",
                          where);

    if(oldProject.size() != 0)
    {
        page.FormStart("FormProject", "class", "GET");
//                       "return ValidateProjectForm()");
        page.Label(fieldName.projectName, " Existing Project Name ");
        page.InputField("hidden", fieldName.projectType, "Old"); 
        page.InputField("hidden", fieldName.emailID, userEmailID);

        page.SelectFieldStart(fieldName.projectName);
        
        page.SelectOptionStart("Select", "y");
        cout << "Select";
        page.SelectOptionEnd();

        for(unsigned i = 0; i < oldProject.size(); i++)
        {
            page.SelectOptionStart(IntToString(i), "n");
            cout << oldProject[i];
            page.SelectOptionEnd();
        }
        page.SelectFieldEnd();
        cout << page.brk << page.brk;

        page.Button("next", "submit", "btn", "Start Existing Project");

        page.FormEnd();

    }
    else
//        cout << " <option class=\"theFormTextInput\" >No Previous Projects </option>"; 
        cout << page.brk << page.brk;
}

/**
 *      \class  ProjectDetail
 *      \fn     ProjectDetail :: HomePage()
 *      \brief  Home Page
 */

void ProjectDetail :: HomePage()
{
    page.ContentType();
   
    projectID = readField.ReadFieldValue(fieldName.projectID);

    where = "ProjectID = " + projectID;
    database.SelectColumn(emailID, "EmailID", "ProjectDetail", where);

    userEmailID = emailID[0];
    
    ProjectDetailPage();

}

/**
 *--------------------------------------------------------------------\n
 *       Class:  ProjectDetail \n
 *      Method:  ProjectDetail :: ~ProjectDetail() \n
 * Description:  Destuctor \n
 *--------------------------------------------------------------------
 */

ProjectDetail :: ~ProjectDetail()
{
    // Destructor
}

