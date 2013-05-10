/**
 *       \file       adduser-main.cpp
 *
 *       \brief      Adding new user and setting its password
 *
 *       \version    0.6
 *       \date       Sunday 07 April 2013 01:15:32  IST\n
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
    user.AddUser();

    return 0;
}
