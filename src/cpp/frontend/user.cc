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

//namespace field = fieldname;           /**< Shortname for namespace */

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
    userEmailID  = readField.ReadFieldValue(name::field["emailSignUp"]);
}

/**
 *      \fn     User :: ReadLoginForm()
 *      \brief  Reading login detail form filled by user.
 */

void User :: ReadLoginForm()
{
    userEmailID  = readField.ReadFieldValue(name::field["emailLogin"]);
    userPassword = readField.ReadFieldValue(name::field["passwordLogin"]);
}

/**
 *      \fn     User :: SelectUserDetail()
 *      \brief  Select user's email id and password from database.
 */

void User :: SelectUserDetail()
{
    database.SelectColumn(regID, name::field["regID"], name::table["user"]);
 
    for(vecStringIt = regID.begin(); vecStringIt != regID.end(); vecStringIt++)
    {
        where = name::field["regID"] + " = " + *vecStringIt + " ";
        database.SelectColumn(emailID, name::field["emailID"], 
                name::table["reg"], where);
    }

//    database.SelectColumn(emailID, name::field["emailID"], name::table["user"]);
    database.SelectColumn(password, name::field["password"],
            name::table["user"]);
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
         != emailID.end() ) )                  /* If Email ID valid */
    {
        temp = md5(userPassword);
        
        where = name::field["emailID"] + " = \"" + userEmailID + "\"";
        database.SelectColumn(vecTemp, name::field["regID"],    // index = 0
                              name::table["reg"], where);
        string regID = vecTemp[0];

        where = name::field["regID"] + " = " + regID;

        database.SelectColumn(vecTemp, name::field["password"], // index = 1
                              name::table["user"], where);
        database.SelectColumn(vecTemp, name::field["userID"],   // index = 2 
                              name::table["user"], where);
        string userID = vecTemp[2];

        if( temp == vecTemp[1] )   /* If Password Correct */
        {
             
            sessionID  = md5(userEmailID);
            currentTime = Time();
            sessionID += md5(currentTime);
            database.InsertSessionDetail(userID, sessionID);
            readField.SetCookie(name::field["sessionID"], sessionID);
           
            where = name::field["sessionKey"] + " = \"" 
                    + sessionID + "\"";
            string sID;
            STRING_VEC vSID;
            database.SelectColumn(vSID, name::field["sessionID"], 
                                  name::table["session"], where);

            sID = vSID[0];

            msg = sID; // Redirect to next page
        }
        else                             /* If Password Incorrect */
        {
            msg = "false";
        }
    }
    else                                   /* If Email ID invalid */
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
        database.SelectColumn(emailID, name::field["emailID"], 
                              name::table["reg"]);

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

    key = readField.ReadFieldValue(name::field["key"]);

    database.SelectColumn(regKey, name::field["regKey"], 
                          name::table["reg"]);

    if ( find(regKey.begin(), regKey.end(), key) != regKey.end() )
    {
        where = name::field["regKey"] + " =\"" + key + "\"";
        database.UpdateQuery(name::table["reg"], name::field["active"], "YES",
                where);
        database.SelectColumn(regID, name::field["regID"], name::table["reg"], 
                where);
        
        msg = regID[0];
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

    userRegID = readField.ReadFieldValue(name::field["regID"]);
    userPassword = readField.ReadFieldValue(name::field["password"]);
    retypePassword = readField.ReadFieldValue(name::field["retypePassword"]);

    if(userPassword == retypePassword)
    {
        database.InsertUserDetail(userRegID, md5(userPassword));
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
