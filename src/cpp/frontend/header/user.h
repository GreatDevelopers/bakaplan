/**
 *       \file       user.h
 *
 *       \brief      Sign up and login module. Authenticate user for
 *                   logging in or registration of new user.\n
 *
 *       Compiler    g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com\n
 *       \license    GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

#include "header.h"
#include "database.h"
#include "read_inputfield.h"
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
        Database database;                                     /**< DataBase */
        ReadInputField readField;
        SendMail sendMail;
        
        STRING_VEC emailID,                          /**< Email ID as vector */
                   regID,                               /**< Registration ID */
                   password,                /**< password as vector variable */
                   regKey,                             /**< Registration key */
                   activeLink,          /**< Confirmation link active or not */
                   vecTemp;                        /**< Vector temp variable */

        string userEmailID,           /**< For reading emailID in text field */
               userRegID,                         /**< User registration key */
               userPassword,          /**< For reading password in text field*/
               retypePassword;                     /**< For reading password */

        string currentTime,                               /**< Currennt Time */
               sessionID,                                   /**< Session Key */
               key,                                /** Confirmation Link Key */
               msg,                            /**< Store error/info Message */
               temp,                                 /**< Temporary variable */
               where;                                      /**< where clause */

        vector<string> :: iterator vecStringIt;     /**< Iterator for vector */

    public:
        User();
        void ReadSignUpForm();
        void ReadLoginForm();
        void SelectUserDetail();
        void LoginUser();
        void SignUpUser();
        void ConfirmUser();
        void SetPassword();
        string Time();
        ~User();
};
