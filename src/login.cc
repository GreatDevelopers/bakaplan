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

void Login :: LoginPage(string msg, string emailID, string password)
{
    ContextType();
    Header("Login");

    DivStart("login", "");

    cout << brk;

    FormStart("login", "projectdetail.html", "POST");

    cout << startH1 << "Login" << endH1 << brk;
    
    if(msg != "")
    {   
        DivStart("msg", "error");
        cout <<  msg << brk << brk;
        DivEnd();
    }

    cout << " Email ID ";
    InputField("email", fieldName.emailID, emailID);
    cout << brk << brk;
    cout << " Password ";
    InputField("password", fieldName.password, password);
    
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
 *      Method:  Login :: RegisterPage() \n
 * Description:  Register new user \n
 *--------------------------------------------------------------------
 */

void Login :: RegisterPage(string msg, string emailID, string password)
{
    ContextType();
    Header("Register");
    
    DivStart("register", "");
    cout << brk;
    FormStart("register", "newuser.html", "POST");
    
    cout << startH1 << " Register New User " << endH1 <<  brk;

    if(msg != "")                                                     
    {
        DivStart("msg", "error");
        cout << msg << brk << brk;
        DivEnd();
    }
    
    cout << " Email ID ";
    InputField("text", fieldName.emailID, emailID);
    
    cout << brk << brk
         << " Password ";
    InputField("password", fieldName.password, password);
    
    cout << brk << brk
         << " Re-type Password ";
    InputField("password", fieldName.retypePassword, password);

    cout << brk << brk;

    Button("register", "submit", "btn", "Register");

    FormEnd();

    DivEnd();

    Footer();
}

/**
 *--------------------------------------------------------------------\n
 *       Class:  Login \n
 *      Method:  Login :: AddNewUser() \n
 * Description:  Adding new user into database and if user already
 *               exists then move back to register page for unique 
 *               email id \n
 *--------------------------------------------------------------------
 */

void Login :: AddNewUser()
{
    SelectLoginDetail();
    
    retypePassword = readField.ReadFieldValue(fieldName.retypePassword);

    ReadLoginDetail();

    if ( find(emailID.begin(), emailID.end(), userEmailID)
         != emailID.end() )
    {
        msg = "User already exists. Try another email ID";
        RegisterPage( msg, userEmailID );
    }
    else
    {
        if( retypePassword == userPassword )
        {
            msg = "Password doesn't match";
            RegisterPage( msg, userEmailID );
        }
        else
        {
            userPassword = md5(userPassword);
            database.InsertUser( userEmailID, userPassword );
            LoginPage();
        }
    }
}

/**
 *--------------------------------------------------------------------\n
 *       Class:  Login \n
 *      Method:  Login :: LogoutPage() \n
 * Description:  Logout Page \n
 *--------------------------------------------------------------------
 */

void Login :: LogoutPage()
{
    SetCookies("", "");
    LoginPage();
}

/**
 *--------------------------------------------------------------------\n
 *       Class:  Login \n
 *      Method:  Login :: AlreadyLoggedIn() \n
 * Description:  Check if user already logged in not allow to log in \n
 *--------------------------------------------------------------------
 */

void Login :: AlreadyLoggedIn()
{

}
