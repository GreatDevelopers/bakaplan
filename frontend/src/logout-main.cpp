/**
 *       \file       logout-main.cpp
 *
 *       \brief      Log out user account
 *
 *       \version    0.6
 *       \date       Sunday 07 April 2013 04:29:47  IST\n
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
 *      \fn     main(void)
 *      \brief  Main Method
 */

int main(void)
{
    Login user;
    user.LogoutPage();

    return 0;
}
