/**
 *
 *       \file       user.cc
 *
 *       \brief      Function definition of user class. See header
 *                   file for more detail.
 *
 *       \compiler   g++\n
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       \license    GNU General Public License\n
 *       \copyright  Copyright (c) 2013, GreatDevelopers\n
 *                   https://github.com/GreatDevelopers
 */

#include "header/user.h"
#include "header/fieldname.h"

namespace field = fieldname;           /**< Shortname for namespace */

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
    userEmailID  = readField.ReadFieldValue(field::name["emailSignUp"]);
}

/**
 *      \fn     User :: ReadLoginForm()
 *      \brief  Reading login detail form filled by user.
 */

void User :: ReadLoginForm()
{
    userEmailID  = readField.ReadFieldValue(field::name["emailLogin"]);
    userPassword = readField.ReadFieldValue(field::name["passwordLogin"]);
}

/**
 *      \fn     User :: SelectUserDetail()
 *      \brief  Select user's email id and password from database.
 */

void User :: SelectUserDetail()
{
    database.SelectColumn(emailID, field::name["emailID"], 
                          field::name["user"]);
    database.SelectColumn(password, field::name["password"], 
                          field::name["user"]);
}

/**
 *      \fn     User :: LoginUser()
 *      \brief  Login user if entered email and password matched with
 *              values in database.
 */

void User :: LoginUser()
{

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
             
            sessionID  = md5(userEmailID);
            currentTime = Time();
            sessionID += md5(currentTime);
            database.InsertSessionDetail(userEmailID, sessionID);
            readField.SetCookie(field::name["sessionID"], sessionID);
           
            where = "SessionKey = \"" + sessionID + "\"";
            string sID;
            STRING_VEC vSID;
            database.SelectColumn(vSID, "SessionID", "SessionDetail",
                                  where);

            sID = vSID[0];

            msg = sID; // Redirect to next page
        }
        else                             /**< If Password Incorrect */
        {
            msg = "false";
        }
    }
    else                                   /**< If Email ID invalid */
    {
        msg = "false";
    }
    cout << HTTPHTMLHeader() << endl;
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
    
            msg = "Check verification mail in your inbox "
                  "(or Junk/Spam)";
     //       msg = "true";
        }
    }
    cout << msg << endl;
}

/**
 *      \fn     Login :: ConfirmUser()
 *      \brief  Page for validating email ID and setting user's
 *              password
 */

void User :: ConfirmUser()
{
    cout << HTTPHTMLHeader() << endl;

    key = readField.ReadFieldValue(field::name["key"]);

    database.SelectColumn(regKey, "RegistrationKey", "Registeration");
    if ( find(regKey.begin(), regKey.end(), key) != regKey.end() )
    {
        where = "RegistrationKey =\"" + key + "\"";
        database.SelectColumn(emailID, "EmailID", "Registeration");
        
        msg = emailID[0];
    }
    else
    {
        msg = "false";
    }
    cout << msg;
}


/**
 *      \fn     Login :: SetPassword()
 *      \brief  Set Password for new user
 *      \param
 */

void User :: SetPassword()
{
    cout << HTTPHTMLHeader() << endl;

    userEmailID = readField.ReadFieldValue(field::name["emailID"]);
    userPassword = readField.ReadFieldValue(field::name["password"]);
    retypePassword = readField.ReadFieldValue(field::name["retypePassword"]);

    if(userPassword == retypePassword)
    {
        database.InsertUserDetail(userEmailID, md5(userPassword));
        cout << "true";
    }
    else
    {
        cout << "false";
    }
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
