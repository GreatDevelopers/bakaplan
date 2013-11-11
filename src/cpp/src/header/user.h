/**
 *       \file       user.h
 *
 *       \brief      Sign up and login module. Authenticate user for
 *                   logging in or registration of new user.
 *
 *       \version    1.0
 *       \date       07/16/2013 12:48:13 AM\n
 *       Compiler    g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com\n
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

#include "header.h"
#include "database.h"
#include "read-inputfield.h"
#include "sendmail.h"
#include "md5.h"

/**
 *      \class  User
 *      \brief  User class for registration of new user and login if
 *              user already registered.
 */

class User
{
    protected:
        Database database;                            /**< DataBase */
        ReadInputField readField;
        SendMail sendMail;
        
        STRING_VEC emailID,                 /**< Email ID as vector */
                   password,       /**< password as vector variable */
                   regKey,                    /**< Registration key */
                   vecTemp;               /**< Vector temp variable */

        string userEmailID,  /**< For reading emailID in text field */
               userPassword, /**< For reading password in text field*/
               retypePassword;            /**< For reading password */

        string currentTime,                      /**< Currennt Time */
               key,
               msg,                   /**< Store error/info Message */
               temp,                        /**< Temporary variable */
               where;                             /**< where clause */

    public:
        User();
        void ReadSignUpForm();
        void ReadLoginForm();
        void SelectUserDetail();
        void LoginUser();
        void SignUpUser();
        string Time();
        ~User();
};
