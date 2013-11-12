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
    
            msg = "Check verification mail in your inbox "
                  "(or Junk/Spam)";
     //       msg = "true";
        }
    }
    cout << msg << endl;
}

/**
 *      \fn     Login :: ConfirmUser(string msg, string password, 
 *                       string retypePassword)
 *      \brief  Page for validating email ID and setting user's
 *              password
 *      \param  msg Shows error message
 *      \param  password Password filled by user
 *      \param  retypePassword Password filled by user
 */

void User :: ConfirmUser(string msg, string password, 
                          string retypePassword)
{
    cout << HTTPHTMLHeader() << endl;

    key = readField.ReadFieldValue(field::name["key"]);
    
    database.SelectColumn(regKey, "RegistrationKey", "Registeration");
    if ( find(regKey.begin(), regKey.end(), key) != regKey.end() )
    {
       
        cout << "true";
/*        
        cout << cgicc::div().set("id", "DivConfirm") << br();

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
        */
    }
    else
    {
        cout << "false";
//        RegistrationPage(msg);
    }

//    cout << msg;
    
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
