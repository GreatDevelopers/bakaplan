/**
 *
 *       \file       login.h
 *
 *       \brief      Login class declaration for user login,
 *                   registration and reset password.
 *
 *       \version    0.7
 *       \date       Thursday 06 June 2013 10:40:55  IST\n
 *       Compiler    g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com\n
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

#ifndef LOGIN_H
#define LOGIN_H

#include "inputdetail.h"
#include "md5.h"
#include "sendmail.h"

/**
 *      \class  Login
 *      \brief  
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
                       string password = "");

        /** Read Login Detail */
        void ReadLoginDetail();

        /** Register user page  */
        void RegistrationPage(string msg = "", 
                               string emailID = "abc@you.com");

        /** Add new user in database */
        void NewUser();

        /** For selecting emial and password fron user table */
        void SelectLoginDetail();

        void ConfirmPage(string msg = "", string password = "",
                         string retypePassword = "");
        /** Add new user */
        void AddUser();
    
        /** Reset password of existing user */
        void ResetPasswordPage(string type = "1", string msg = "", 
                           string emailID = "abc@you.com");

        /** Reset Password Forms  */
        void ResetPasswordForm(string type, string msg, string emailID);

        /** Logout Page */
        void LogoutPage();

        /** Destructor */
        ~Login(){}
};

#endif
