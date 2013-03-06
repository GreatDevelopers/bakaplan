/*
 * ===================================================================
 *
 *       Filename:  login.cc
 *
 *    Description:  Definition of LoginPage function of Login class
 *
 *        Version:  0.6
 *        Created:  Sunday 03 March 2013 02:52:49  IST
 *       Compiler:  gcc
 *
 *         Author:  Mandeep Kaur, meghasimak@gmail.com
 *        License:  GNU General Public License
 *      Copyright:  Copyright (c) 2013, GreatDevelopers
 *                  https://github.com/GreatDevelopers
 *
 * ===================================================================
 */

/**-------------------------------------------------------------------
 *  Include login.h header file
 *------------------------------------------------------------------*/
#include "login.h"

/**
 *--------------------------------------------------------------------\n
 *       Class:  Login \n
 *      Method:  Login :: Login() \n
 * Description:  Constructor \n
 *--------------------------------------------------------------------
 */

Login :: Login()
{

}

/**
 *--------------------------------------------------------------------\n
 *       Class:  Login \n
 *      Method:  Login :: SelectLoginDetail() \n
 * Description:  For reading email id's and passwords from user table \n
 *--------------------------------------------------------------------
 */

void Login :: SelectLoginDetail()
{
    database.SelectQuery("EmailID", "User", emailID);

    for(i = 0; i < emailID.size(); i++)
        cout << "email: " << emailID[i];
}

/**
 *--------------------------------------------------------------------\n
 *       Class:  Login \n
 *      Method:  Login :: LoginPage() \n
 * Description:  Form for user login \n
 *--------------------------------------------------------------------
 */

void Login :: LoginPage()
{
    Header("Login");

    DivStart("login", "");
    
    SelectLoginDetail();

    cout << brk;

    FormStart("login", "projectdetail.html", "POST");

    cout << startH1 << "Login" << endH1 << brk;

    cout << " Email ID ";
    InputField("email", fieldName.emailID, 0, "email@abc.com");
    cout << brk << brk;
    cout << " Password ";
    InputField("password", fieldName.password, 0, "123456");
    
    cout << brk << brk;
    
    Button("next", "submit", "btn", "NEXT");

    FormEnd();
    DivEnd();

    Footer();
}
