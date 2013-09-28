/**
 *       \file       signup-main.cpp
 *
 *       \brief      Accessing login form for logging in.
 *
 *       \version    1.0
 *       \date       07/16/2013 08:13:34 AM\n
 *       Compiler    g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com\n
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

#include "header/user.h"

/** 
 *      \fn     main(void)
 *      \brief  main function for declaring object of user class to
 *              register new user.
 */

int main(void)
{
    User user;
    user.LoginUser();
    
    return 0;
}
