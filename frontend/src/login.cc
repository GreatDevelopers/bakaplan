/*
 * ===================================================================
 *
 *       Filename:  login.cc
 *
 *    Description:  Definition of LoginPage function of Login class
 *
 *        Version:  0.7
 *        Created:  Sunday 03 March 2013 02:52:49  IST
 *       Compiler:  g++
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
    database.SelectColumn(emailID, "EmailID", "User");
    database.SelectColumn(password, "Password", "User");

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
    userEmailID  = readField.ReadFieldValue(fieldName.emailID);
    userPassword = readField.ReadFieldValue(fieldName.password);
}

/**
 *      \class  Login
 *      \fn     Login :: LoginPage(string msg, sting emailID, 
 *                                 stirng password)
 *      \brief  Function for creating login Page
 *      \param  msg Show Message if emailID/ password incorrect
 *      \param  emialID user filled email id
 *      \param  password uer password
 */

void Login :: LoginPage(string msg, string emailID, string password)
{
    page.ContentType();

    Header("Login");

    cout << cgicc::div().set("id", "DivLogin")
         << form().set("id", "FormLogin").set("action", "project")
                  .set("method", "POST");

    cout << h1() << "Login" << h1() << br();;
    
    ErrorMessage(msg);
    
    page.Label(fieldName.emailID, " Email ID ");
    page.InputField("email", fieldName.emailID, emailID);
    cout << br() << br();

    page.Label(fieldName.password, " Password ");
    page.InputField("password", fieldName.password, password);
    
    cout << br() << br();
    
    page.Button("next", "submit", "btn", "Login");

    cout << br() << br() << b();
    page.Anchor("register", "Register Here"); 
    cout << " | ";
    
    page.Anchor("reset?type=1", "Reset Password");
    cout << b()

         << form()
         << cgicc::div();

    Footer();
}

/**
 *      \class  Login
 *      \fn     Login :: RegistrationPage()
 *      \brief  For registering new user
 */

void Login :: RegistrationPage(string msg, string emailID)
{
     
    page.ContentType();
    Header("Register");
   
    cout << cgicc::div().set("id", "DivRegister") << br();

    page.Anchor("login", "Login");

    cout << form().set("method", "POST").set("id", "FormEmail")
                  .set("action", "newuser");
    
    cout << h1() << " Register New User " << h1() << br();
    
    ErrorMessage(msg);

    page.Label(fieldName.emailID, "Email ID");
    page.InputField("email", fieldName.emailID, emailID);

    cout << br() << br();

    page.Button("Register", "submit", "btn", "Register");

    cout << form() << cgicc::div();

    Footer();
    
}

/**
 *      \class  Login
 *      \fn     Login :: NewUser()
 *      \brief  Adding new user into database and if user already
 *              exists then move back to register page for unique 
 *              email id.
 */

void Login :: NewUser()
{
    userEmailID = readField.ReadFieldValue(fieldName.emailID);

    database.SelectColumn(emailID, "EmailID", "User");

    if ( find(emailID.begin(), emailID.end(), userEmailID)
         != emailID.end() )
    {
        msg = "User already exists. Try another email ID";
        RegistrationPage( msg, userEmailID );
    }
    else
    {
        currentTime = Time();

        currentTime = md5(currentTime);

        database.InsertRegistrationDetail(userEmailID, currentTime);

        sendMail.RegistrationMail(userEmailID, currentTime);
    
        msg = "Check mail for verification in Junk/Trash.";

        LoginPage(msg);
    }

}

/**
 *      \class  Login
 *      \fn     Login :: ConfirmPage(string msg, string password, 
 *                       string retypePassword)
 *      \brief  Page for validating email ID and setting user's
 *              password
 *      \param  msg Shows error message
 *      \param  password Password filled by user
 *      \param  retypePassword Password filled by user
 */

void Login :: ConfirmPage(string msg, string password, 
                          string retypePassword)
{
    key = readField.ReadFieldValue(fieldName.key);
    
    database.SelectColumn(regKey, "RegistrationKey", "Registeration");
    if ( find(regKey.begin(), regKey.end(), key) != regKey.end() )
    {
       
        page.ContentType();
        Header("Confirm Email");
        
        cout << cgicc::div().set("id", "DivConfirm") << br();

        page.Anchor("login", "Login");

        cout << form().set("id", "FormSetPassword")
                      .set("action", "adduser")
                      .set("method", "POST");
    
        cout << h1() << " Email Confirmed " << h1() << br()
             << b() << " Set Password " << b();
    
        page.InputField("hidden", "Key", key);

        cout << br() << br();

        ErrorMessage(msg);

        page.Label(fieldName.password, " Password ");
        page.InputField("password", fieldName.password, password);
    
        cout << br() << br();
        page.Label(fieldName.retypePassword, " Retype Password ");
        page.InputField("password", fieldName.retypePassword, 
                        retypePassword);

        cout << br() << br();

        page.Button("next", "submit", "btn", "Submit");

        cout << form() << cgicc::div();

        Footer();
    }
    else
    {
        msg = "Invalid Link. Register Again!";
        RegistrationPage(msg);
    }
    
}

/**
 *      \class  Login
 *      \fn     Login :: AddUser()
 *      \brief  Add New user
 */

void Login :: AddUser()
{
    retypePassword = readField.ReadFieldValue(fieldName.retypePassword);

    userPassword = readField.ReadFieldValue(fieldName.password);

    key = readField.ReadFieldValue(fieldName.key);

    database.SelectColumn(regKey, "RegistrationKey", "Registeration");
    
    temp = "RegistrationKey = \"" + key + "\"";

    database.SelectColumn(emailID, "EmailID", "Registeration", temp);
    userEmailID = emailID[0];

    if ( find(regKey.begin(), regKey.end(), key) != regKey.end() )
    {
        if( retypePassword != userPassword )
        {
            msg = "Password doesn't match";
            ConfirmPage( msg );
        }
        else
        {
            userPassword = md5(userPassword);
            database.InsertUserDetail( userEmailID, userPassword );
            LoginPage();
        }
    }
    else
    {
        msg = "Invalid Link";
        RegistrationPage( msg );
    }
}

/**
 *      \class  Login
 *      \fn     Login :: LogoutPage()
 *      \brief  Page for logging out
 */

void Login :: LogoutPage()
{
    page.SetCookies("", "");
//    string s = readField.ReadCookie("SessionID");
/*    userEmailID = readField.ReadFieldValue(fieldName.emailID);
    temp = "SessionID = \"" + s + "\"";
    database.DeleteQuery("SessionDetail", temp);*/
    LoginPage();
}
 
void Login :: ResetPasswordPage(string type, string msg, string emailID)
{
     
    page.ContentType();

    Header("Reset Password");
    
    cout << cgicc::div().set("id", "DivResetPass") << br();

    page.Anchor("login", "Login");
/*
    if(type != "1")
    {
        type = readField.ReadFieldValue("type");
    }*/
    ResetPasswordForm(type, msg, emailID);

    cout << cgicc::div();
    Footer();    
}

void Login :: ResetPasswordForm(string type, string msg, string emailID)
{
    if(type == "1")
    {
        cout << form().set("id", "FormEmail")
                      .set("action", "reset?type=2")
                      .set("method", "POST");
    
        cout << h1() << " Enter email to reset pssword " 
             << h1() << br();
    
        ErrorMessage(msg);

        page.Label(fieldName.emailID, "Email ID");
        page.InputField("email", fieldName.emailID, emailID);
    
        cout << br() << br();

        page.Button("Send", "submit", "btn", "Send");

        cout << form();
    }
    else if(type == "2")
    {
        userEmailID = readField.ReadFieldValue(fieldName.emailID);

        database.SelectColumn(vecTemp, "EmailID", "User");

        if ( find(vecTemp.begin(), vecTemp.end(), userEmailID)
             != vecTemp.end() )
        {
            currentTime = Time();
            currentTime = md5(currentTime);

            database.InsertResetPassword(userEmailID, currentTime);

            sendMail.ResetPasswordMail(userEmailID, currentTime);
    
            msg = "Check mail to reset password in Junk/Trash.";

            ResetPasswordForm("1", msg, userEmailID);
        }
        else
        {
            msg = "User not registered ";
            ResetPasswordForm( "1", msg, userEmailID );
        }

    }
    else if(type == "3")
    {
        key = readField.ReadFieldValue(fieldName.key);

        database.SelectColumn(regKey, "ResetKey", "ResetPassword");

        if ( find(regKey.begin(), regKey.end(), key) != regKey.end() )
        {
            cout << form().set("id", "FormSetPassword")
                          .set("action", "reset?type=4")
                          .set("method", "POST");
       
            cout << h1() << " Email Confirmed " << h1() << br()
                 << b() << " Reset Password " << b();
    
            page.InputField("hidden", "Key", key);

            cout << b() << b();

            ErrorMessage(msg);

            page.Label(fieldName.password, " Password ");
            page.InputField("password", fieldName.password, "");
    
            cout << br() << br();
            page.Label(fieldName.retypePassword, " Retype Password ");
            page.InputField("password", fieldName.retypePassword, "");

            cout << br() << br();

            page.Button("next", "submit", "btn", "Submit");
    
            cout << form();

        }
    }
    else if(type == "4")
    {
        retypePassword = readField.ReadFieldValue(
                         fieldName.retypePassword);

        userPassword = readField.ReadFieldValue(fieldName.password);

        key = readField.ReadFieldValue(fieldName.key);

        database.SelectColumn(regKey, "ResetKey", "ResetPassword");
        
        temp = "ResetKey = \"" + key + "\"";

        database.SelectColumn(vecTemp, "EmailID", "ResetPassword", temp);

        userEmailID = vecTemp[0];

        if ( find(regKey.begin(), regKey.end(), key) != regKey.end() )
        {
            if( retypePassword != userPassword )
            {
                msg = "Password doesn't match";
                ResetPasswordForm("3", msg, "");
            }
            else
            {
                userPassword = md5(userPassword);
                where = "EmailID = \"" + userEmailID + "\"";
                database.UpdateQuery("User", "Password", userPassword,
                                     where);
                //cout << HTTPRedirectHeader("login");
            }
        }
        else
        {
            msg = "Invalid Link";
            RegistrationPage( msg );
        }

    }
}
