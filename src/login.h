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

/**-------------------------------------------------------------------
 *  Include required header files
 *------------------------------------------------------------------*/

#include "inputdetail.h"

/**
 * ===================================================================
 *        Class:  Login
 *  Description:  Login class for user login
 * ===================================================================
 */

class Login : public InputDetail, Database
{
    protected:
        /** For stroting email and password of users */
        string emailID[MIN_SIZE],              /* Email ID - unique */
               password;                                /* Password */

    public:
        /** Constructor */
        Login();

        /** Creating login page */
        void LoginPage();

        /** For selecting emial and password fron user table */
        void SelectLoginDetail();

        /** Destructor */
        ~Login(){}
};
