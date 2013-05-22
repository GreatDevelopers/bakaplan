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

    page.DivStart("DivLogin", "");

    page.FormStart("FormLogin", "project", "POST");

    cout << page.startH1 << "Login" << page.endH1 << page.brk;
    
    ErrorMessage(msg);
    
    page.Label(fieldName.emailID, " Email ID ");
    page.InputField("email", fieldName.emailID, emailID);
    cout << page.brk << page.brk;

    page.Label(fieldName.password, " Password ");
    page.InputField("password", fieldName.password, password);
    
    cout << page.brk << page.brk;
    
    page.Button("next", "submit", "btn", "Login");

    cout << page.brk << page.brk << page.startB;
    page.Anchor("register", "Register Here"); 
    cout << page.brk;
    page.Anchor("reset?type=1", "Reset Password");
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

void Login :: RegistrationPage(string msg, string emailID)
{
     
    page.ContentType();
    Header("Register");
    
    page.DivStart("DivRegister", "");
    cout << page.brk;

    page.Anchor("login", "Login");

    page.FormStart("FormEmail", "newuser", "POST");
    
    cout << page.startH1 << " Register New User " << page.endH1 
         <<  page.brk;
    
    ErrorMessage(msg);

    page.Label(fieldName.emailID, "Email ID");
    page.InputField("email", fieldName.emailID, emailID);

    cout << page.brk << page.brk;

    page.Button("Register", "submit", "btn", "Register");

    page.FormEnd();

    page.DivEnd();

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

        RegistrationPage(msg);
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
    
        page.DivStart("DivConfirm", "");
        cout << page.brk;

        page.Anchor("login", "Login");

        page.FormStart("FormSetPassword", "adduser", "POST");
    
        cout << page.startH1 << " Email Confirmed " << page.endH1 
             <<  page.brk
             << page.startB << " Set Password " << page.endB;
    
        page.InputField("hidden", "Key", key);

        cout << page.brk << page.brk;

        ErrorMessage(msg);

        page.Label(fieldName.password, " Password ");
        page.InputField("password", fieldName.password, password);
    
        cout << page.brk << page.brk;
        page.Label(fieldName.retypePassword, " Retype Password ");
        page.InputField("password", fieldName.retypePassword, 
                        retypePassword);

        cout << page.brk << page.brk;

        page.Button("next", "submit", "btn", "Submit");

        page.FormEnd();

        page.DivEnd();

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
    //string s = readField.ReadCookie("SessionID");
/*    userEmailID = readField.ReadFieldValue(fieldName.emailID);
    temp  = "delete from Session where EmailID = \"" + userEmailID;
    temp += "\";";
    database.DeleteQuery(temp);*/
    LoginPage();
}
 
void Login :: ResetPasswordPage(string type, string msg, string emailID)
{
     
    page.ContentType();

    Header("Reset Password");
    
    page.DivStart("DivResetPass", "");
    cout << page.brk;

    page.Anchor("login", "Login");
/*
    if(type != "1")
    {
        type = readField.ReadFieldValue("type");
    }*/
    ResetPasswordForm(type, msg, emailID);

    page.DivEnd();
    Footer();    
}

void Login :: ResetPasswordForm(string type, string msg, string emailID)
{
    if(type == "1")
    {
        page.FormStart("FormEmail", "reset?type=2", "POST");
    
        cout << page.startH1 << " Enter email to reset pssword " 
             << page.endH1 
             <<  page.brk;
    
        ErrorMessage(msg);

        page.Label(fieldName.emailID, "Email ID");
        page.InputField("email", fieldName.emailID, emailID);
    
        cout << page.brk << page.brk;

        page.Button("Send", "submit", "btn", "Send");

        page.FormEnd();
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
            page.FormStart("FormSetPassword", "reset?type=4", "POST");
        
            cout << page.startH1 << " Email Confirmed " << page.endH1 
                 <<  page.brk
                 << page.startB << " Reset Password " << page.endB;
    
            page.InputField("hidden", "Key", key);

            cout << page.brk << page.brk;

            ErrorMessage(msg);

            page.Label(fieldName.password, " Password ");
            page.InputField("password", fieldName.password, "");
    
            cout << page.brk << page.brk;
            page.Label(fieldName.retypePassword, " Retype Password ");
            page.InputField("password", fieldName.retypePassword, "");

            cout << page.brk << page.brk;

            page.Button("next", "submit", "btn", "Submit");
    
            page.FormEnd();

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
