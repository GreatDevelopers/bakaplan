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
    // constructor
}

/**
 *--------------------------------------------------------------------\n
 *       Class:  Login \n
 *      Method:  Login :: SelectLoginDetail() \n
 * Description:  For reading email id's and passwords from User table \n
 *--------------------------------------------------------------------
 */
 
void Login :: SelectLoginDetail()
{
    database.SelectQuery("EmailID", "User", emailID);
    database.SelectQuery("Password", "User", password);

/*      
    vector<string>::iterator v = emailID.begin();
    while( v != emailID.end()) 
    {
        cout << "Email ID: " << *v << brk;
        v++;
    }*/

   /*  for(unsigned i = 0; i < emailID.size(); i++)
    {
        cout << "Email: " << emailID[i] << brk
             << "Password: " << password[i] << brk;
    }*/
}

/**
 *--------------------------------------------------------------------\n
 *       Class:  Login \n
 *      Method:  Login :: ReadLoginDetail() \n
 * Description:  Reading login detail from text fileds given by user \n
 *--------------------------------------------------------------------
 */

void Login :: ReadLoginDetail()
{
    userEmailID  = readField.ReadFieldValue(fieldName.emailID);
    userPassword = readField.ReadFieldValue(fieldName.password);
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

    cout << brk;

    FormStart("login", "projectdetail.html", "POST");

    cout << startH1 << "Login" << endH1 << brk;

    cout << " Email ID ";
    InputField("email", fieldName.emailID, "email@abc.com");
    cout << brk << brk;
    cout << " Password ";
    InputField("password", fieldName.password, "123456");
    
    cout << brk << brk;
    
    Button("next", "submit", "btn", "Login");

    cout << brk << brk << startB;
    Anchor("register.html", "Register Here");
    cout << endB;

    FormEnd();
    DivEnd();

    Footer();
}

/**
 *--------------------------------------------------------------------\n
 *       Class:  Login \n
 *      Method:  Login :: Register() \n
 * Description:  Register new user \n
 *--------------------------------------------------------------------
 */

void Login :: Register()
{
    Header("Register");
    
    DivStart("register", "");
    
    FormStart("register", "user.html", "POST");

    FormEnd();

    DivEnd();

    Footer();
}
