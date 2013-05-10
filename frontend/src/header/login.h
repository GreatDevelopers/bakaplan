/*
 * ===================================================================
 *
 *       Filename:  login.h
 *
 *    Description:  Login class definition for user login 
 *
 *        Version:  0.6
 *        Created:  Sunday 03 March 2013 01:13:08  IST
 *       Compiler:  gcc
 *
 *         Author:  Mandeep Kaur, meghasimak@gmail.com
 *        License:  GNU General Public License
 *      Copyright:  Copyright (c) 2013, GreatDevelopers
 *                  https://github.com/GreatDevelopers
 *
 * ===================================================================
 */

#ifndef LOGIN_H
#define LOGIN_H

/**-------------------------------------------------------------------
 *  Include required header files
 *------------------------------------------------------------------*/

#include "inputdetail.h"
#include "md5.h"
#include "sendmail.h"

/**
 * ===================================================================
 *        Class:  Login
 *  Description:  Login class for user login
 * ===================================================================
 */

class Login : public InputDetail
{
    protected:
        /** For storting email and password of users */

        STRING_VEC emailID,                 /**< Email ID as vector */
                   password,       /**< password as vector variable */
                   regKey;                    /**< Registration key */

        string userEmailID,  /**< For reading emailID in text field */
               userPassword, /**< For reading password in text field*/
               retypePassword;            /**< For reading password */

        string currentTime,                      /**< Currennt Time */
               key;

        SendMail sendMail;

    public:
        /** Constructor */
        Login();

        /** Creating login page */
        void LoginPage(string msg = "", 
                       string emailID = "abc@you.com",
                       string password = "123456");

        /** Read Login Detail */
        void ReadLoginDetail();

        /** Register user page  */
        void RegistrationPage(string msg = "", 
                               string emailID = "abc@you.com");

        /** Add new user in database */
        void NewUser();

        /** For selecting emial and password fron user table */
        void SelectLoginDetail();

        void ConfirmPage(string msg = "", string password = "123456",
                         string retypePassword = "123456");

        void AddUser();

        /** Logout Page */
        void LogoutPage();

        /** Destructor */
        ~Login(){}
};

#endif
