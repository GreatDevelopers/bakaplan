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

/**
 *  Include login.h header file
 */

#include "header/login.h"

/**
 *      \class  Login
 *      \fn     Login :: Login()
 *      \brief  Comstructor
 */

Login :: Login()
{
    // constructor
}

/**
 *      \class  Login
 *      \fn     Login :: SelectLoginDetail()
 *      \brief  For reading email Id and password from User table in
 *              database
 */
 
void Login :: SelectLoginDetail()
{
//    database.SelectQuery("EmailID", "User", emailID);
//    database.SelectQuery("Password", "User", password);

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
 *      \class  Login
 *      \fn     Login :: ReadLoginDetail()
 *      \brief  Reading login detail from text fields filled by user
 *      \param
 */

void Login :: ReadLoginDetail()
{
//    userEmailID  = readField.ReadFieldValue(fieldName.emailID);
//    userPassword = readField.ReadFieldValue(fieldName.password);
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
    page.ContentType();
    Header("Login");

    page.DivStart("login", "");

    cout << page.brk;

    page.FormStart("login", "projectdetail.html", "POST");

    cout << page.startH1 << "Login" << page.endH1 << page.brk;
    
    if(msg != "")
    {   
        page.DivStart("msg", "error");
        cout <<  msg << page.brk << page.brk;
        page.DivEnd();
    }

    page.Label(fieldName.emailID, "Email ID");
    page.InputField("email", fieldName.emailID, emailID);
    cout << page.brk << page.brk;

    page.Label(fieldName.password, " Password ");
    page.InputField("password", fieldName.password, password);
    
    cout << page.brk << page.brk;
    
    page.Button("next", "submit", "btn", "Login");

    cout << page.brk << page.brk << page.startB;
    page.Anchor("register.html", "Register Here");
    cout << page.endB;

    page.FormEnd();
    page.DivEnd();

    Footer();
}

/**
 *      \class  Login
 *      \fn     Login :: RegistrationPage()
 *      \brief  For registering new user
 */

void Login :: RegisterationPage(string msg, string emailID, 
                                string password)
{
     
    page.ContentType();
    Header("Register");
    
    page.DivStart("register", "");
    cout << page.brk;

    page.Anchor("login.html", "Login");

    page.FormStart("register", "newuser.html", "POST");
    
    cout << page.startH1 << " Register New User " << page.endH1 
         <<  page.brk;

    if(msg != "")                                                     
    {
        page.DivStart("msg", "error");
        cout << msg << page.brk << page.brk;
        page.DivEnd();
    }
    
    //cout << " Email ID ";
    page.Label(fieldName.emailID, "Email ID");
    page.InputField("email", fieldName.emailID, emailID);
/*     
    cout << page.brk << page.brk
         << " Password ";
    page.InputField("password", fieldName.password, password);
    
    cout << page.brk << page.brk
         << " Re-type Password ";
    page.InputField("password", fieldName.retypePassword, password);
*/
    cout << page.brk << page.brk;

    page.Button("register", "submit", "btn", "Register");

    page.FormEnd();

    page.DivEnd();

    Footer();
    
}

/**
 *      \class  Login
 *      \fn     Login :: AddNewUser()
 *      \brief  Adding new user into database and if user already
 *              exists then move back to register page for unique 
 *              email id.
 */

void Login :: NewUser()
{
    page.ContentType();
    userEmailID = readField.ReadFieldValue(fieldName.emailID);

    sendMail.RegistrationMail(userEmailID, "fd324cr3rc3cr4c334dui");

    Header("New User");
    
    page.DivStart("newuser", "");
    cout << page.brk;

    page.Anchor("login.html", "Login");

    cout << page.startH1 << " Check mail in Junk/Trash " << userEmailID 
         << page.endH1 <<  page.brk;

    page.DivEnd();

    Footer();
 
    /* 
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
        if( retypePassword != userPassword )
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
    }*/
}

/**
 *      \class  Login
 *      \fn     Login :: LogoutPage()
 *      \brief  Page for logging out
 */

void Login :: LogoutPage()
{
    page.SetCookies("", "");
    //string s = readField.ReadCookie("SessionID");
/*    userEmailID = readField.ReadFieldValue(fieldName.emailID);
    temp  = "delete from Session where EmailID = \"" + userEmailID;
    temp += "\";";
    database.DeleteQuery(temp);*/
    LoginPage();
}
