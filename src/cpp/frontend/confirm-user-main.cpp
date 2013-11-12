/**
 *
 *       \file       confirm-user-main.cpp
 *
 *       \brief      Confirming user email id and resetting password
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
 *      \brief  main function for declaring object of User class to
 *              register new user.
 */

int main(void)
{
    User user;
    user.ConfirmUser();
    
    return 0;
}

/*
 * Local Variables:
 * tab-width: 4
 * expandtab
 * ex: shiftwidth=4 tabstop=4
 */

