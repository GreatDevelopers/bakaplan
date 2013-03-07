/*
 * ===================================================================
 *
 *       Filename:  register-main.cpp
 *
 *    Description:  For creating register.html page. Adding new user
 *                  in database if valid otherwise add unique email
 *                  id.
 *
 *        Version:  0.6
 *        Created:  Friday 08 March 2013 01:14:28  IST
 *       Compiler:  gcc
 *
 *         Author:  Mandeep Kaur, meghasimak@gmail.com
 *        License:  GNU General Public License
 *      Copyright:  Copyright (c) 2013, GreatDevelopers
 *                  https://github.com/GreatDevelopers
 *
 * ===================================================================
 */

/**-------------------------------------------------------------------\n
 *  Include login.h for calling RegisterPage function \n
 *------------------------------------------------------------------*/

#include "login.h"

/**-------------------------------------------------------------------\n
 *  Main Method \n
 *------------------------------------------------------------------*/

int main(void)
{
    Login registerUser;
    registerUser.RegisterPage();

    return 0;
}
