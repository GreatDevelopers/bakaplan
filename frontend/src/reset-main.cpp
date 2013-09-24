/**
 *       \file       register-main.cpp
 *
 *       \brief      Main method for register.html
 *
 *       \version    0.8
 *       \date       Friday 05 April 2013 10:56:56  IST\n
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
 *  Main method for creating register.html page using functions of
 *  Login class 
 */

int main(void)
{
    Login user;
    string type = user.readField.ReadFieldValue("type");
    user.ResetPasswordPage(type);

    return 0;
}
