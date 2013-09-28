/**
 *       \file       user.cc
 *
 *       \brief      Function definition of user class. See header
 *                   file for more detail.
 *
 *       \version    1.0
 *       \date       07/16/2013 01:04:18 AM\n
 *       Compiler    g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com\n
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

#include "header/user.h"

/**
 *      \fn     User :: User()
 *      \brief  Contructor
 */

User :: User()
{
    // Constructor
}

/**
 *      \fn     User :: ReadSignUpForm()
 *      \brief  Reading Sign up detail fields filled by user.
 */

void User :: ReadSignUpForm()
{
    userEmailID  = readField.ReadFieldValue("email-signup");
}

/**
 *      \fn     User :: ReadLoginForm()
 *      \brief  Reading login detail form filled by user.
 */

void User :: ReadLoginForm()
{
    userEmailID  = readField.ReadFieldValue("email-login");
    userPassword = readField.ReadFieldValue("password-login");
}

/**
 *      \fn     User :: SelectUserDetail()
 *      \brief  Select user's email id and password from database.
 */

void User :: SelectUserDetail()
{
    database.SelectColumn(emailID, "EmailID", "User");
    database.SelectColumn(password, "Password", "User");
}

/**
 *      \fn     User :: LoginUser()
 *      \brief  Login user if entered email and password matched with
 *              values in database.
 */

void User :: LoginUser()
{
    cout << HTTPHTMLHeader() << endl;
    ReadLoginForm();
    SelectUserDetail();

    /** Matching user details with values in database */
    if ( ( find(emailID.begin(), emailID.end(), userEmailID) 
         != emailID.end() ) )                /**< If Email ID valid */
    {
        temp = md5(userPassword);
        
        where = "EmailID = \"" + userEmailID + "\"";
        database.SelectColumn(vecTemp, "Password", "User", where);

        if( temp == vecTemp[0] )   /**< If Password Correct */
        {
            /* 
            sessionID  = md5(userEmailID);
            currentTime = Time();
            sessionID += md5(currentTime);
            database.InsertSessionDetail(userEmailID, sessionID);
            page.SetCookies(userEmailID, sessionID);
            */

            msg = "true"; // Redirect to next page
        }
        else                             /**< If Password Incorrect */
        {
            msg = "Incorrect Password!";
        }
    }
    else                                   /**< If Email ID invalid */
    {
        msg = "Incorrect Email ID!";
    }
    cout << msg << endl;
}

/**
 *      \fn     User :: SignUpUser()
 *      \brief  Sign Up new user. If already registered then show
 *              error message.
 */

void User :: SignUpUser()
{
    ReadSignUpForm();
    SelectUserDetail();

    cout << HTTPHTMLHeader() << endl;

    if ( find(emailID.begin(), emailID.end(), userEmailID)
         != emailID.end() )
    {
        msg = "User already exists. Try another email ID";
    }
    else
    {
        database.SelectColumn(emailID, "EmailID", "Registeration");

        if ( find(emailID.begin(), emailID.end(), userEmailID)
             != emailID.end() )
        {
            msg = "User already registered. Check mail";
        }
        else 
        {
            currentTime = Time();
            currentTime = md5(currentTime);

            database.InsertRegistrationDetail(userEmailID, 
                                              currentTime);
            sendMail.RegistrationMail(userEmailID, currentTime);
    
            msg = "Check mail for verification";
     //       msg = "true";
        }
    }
    cout << msg << endl;
}

/**
 *      \fn     User :: Time()
 *      \brief  For finding current time using boost library
 */

string User :: Time()
{
    time_t currentTime = time(NULL);
//    cout << asctime(localtime(&currentTime));

    return asctime(localtime(&currentTime));
}

/**
 *      \fn     User :: ~User()
 *      \brief  Destructor
 */

User :: ~User()
{
    // Destructor
}