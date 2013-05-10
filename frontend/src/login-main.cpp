/**
 *       \file       login-main.cpp
 *
 *       \brief      Main Function for create login.html page
 *
 *       \version    0.6
 *       \date       Friday 05 April 2013 07:30:10  IST\n
 *       Compiler    g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

/**
 *  Include login.h file 
 */
#include "header/login.h"

/** 
 *      \fn     int main(void)
 *      \brief  Main function for calling functions of Login class to
 *              create login.html page
 */

int main(void)
{
    Login login;
    login.LoginPage();

    return 0;
}
