/**
 *
 *       \file       login-main.cpp
 *
 *       \brief      Accessing login form for logging in user.
 *
 *       \compiler   g++\n
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       \license    GNU General Public License\n
 *       \copyright  Copyright (c) 2013, GreatDevelopers\n
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

/*
 * Local Variables:
 * tab-width: 4
 * expandtab
 * ex: shiftwidth=4 tabstop=4
 */

