/*
 * ===================================================================
 *
 *       Filename:  projectdetail.cc
 *
 *    Description:  Definition of member functions of ProjectDetail 
 *                  class. It's for getting project details and if
 *                  user login details are in valid then login.html
 *                  page will be loaded again.
 *
 *        Version:  0.6
 *        Created:  Wednesday 06 March 2013 04:50:25  IST
 *       Compiler:  gcc
 *
 *         Author:  Mandeep Kaur, meghasimak@gmail.com
 *        License:  GNU General Public License
 *      Copyright:  Copyright (c) 2013, GreatDevelopers
 *                  https://github.com/GreatDevelopers
 *
 * ===================================================================
 */

/**-------------------------------------------------------------------\n
 *  Include projectdetail.h for definition of class ProjectDetail \n
 *------------------------------------------------------------------*/

#include "projectdetail.h"

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
    SelectLoginDetail();
    ReadLoginDetail();
    
    userPassword = md5(userPassword);
    
    /** Matching user details with values in database */
    if ( ( find(emailID.begin(), emailID.end(), userEmailID) 
         != emailID.end() ) && 
         ( find(password.begin(), password.end(), userPassword ) 
         != password.end() ) )          /**< If login details valid */
    {
        sessionID  = md5(userEmailID);
        
        /* For current date */

        time_t t = time(0);   // get time now
        
        struct tm * now = localtime( & t );
        
        currentDate  = IntToString(now->tm_year + 1900);
        currentDate += IntToString(now->tm_mon + 1);
        currentDate += IntToString(now->tm_mday);
        
        sessionID += md5(currentDate);
        database.InsertIntoSession(userEmailID, sessionID);
       // cout << "<br>" << currentDate << "<br>";

        ProjectDetailPage();
    }
    else                              /**< If login details invalid */
    {
        msg = "Incorrect Email ID or Password!";
        
        LoginPage( msg );
    }
}

/**
 *--------------------------------------------------------------------\n
 *       Class:  ProjectDetail \n
 *      Method:  ProjectDetail :: ProjectDetailPage() \n
 * Description:  Diplaying page for project details \n
 *--------------------------------------------------------------------
 */

void ProjectDetail :: ProjectDetailPage()
{
    Header("Project Detail");

    DivStart("projectdetail", "");
    
    //InputField("hidden", fieldName.emailID, userEmailID);

    LogOutLink();

    cout << brk;

    FormStart("projectdetail", "totalclasses.html", "POST");
    
    cout << startH1 << "Project Detail" << endH1 << brk;

    cout << " Project Name ";
    InputField("text", fieldName.projectName, "Project Name");

    cout << brk << brk;

    Button("next", "submit", "btn", "NEXT");

    FormEnd();
    DivEnd();

    Footer();
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
