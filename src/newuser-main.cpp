/*
 * ===================================================================
 *
 *       Filename:  newuser-main.cpp
 *
 *    Description:  For adding new user in database. If user already
 *                  exists then load register.html page again for
 *                  getting unique email id.
 *
 *        Version:  0.6
 *        Created:  Friday 08 March 2013 01:18:13  IST
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
 *  Include login.h for AddNewuser function \n
 *------------------------------------------------------------------*/

#include "login.h"

/**-------------------------------------------------------------------\n
 *  Main Mathod \n
 *------------------------------------------------------------------*/

int main(void)
{
    Login newUser;
    newUser.AddNewUser();

    return 0;
}
