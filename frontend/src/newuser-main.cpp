/**
 *       \file       newuser.cpp
 *
 *       \brief      Main method for creating newuser.html page
 *
 *       \version    0.8
 *       \date       Saturday 06 April 2013 08:51:23  IST\n
 *       Compiler    g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

/**
 *  Include login.h
 */
#include "header/login.h"

/** 
 *      \fn     int main(void)
 *      \brief  Main method to call NewUser function of Login class
 */

int main(void)
{
    Login user;
    user.NewUser();

    return 0;
}
