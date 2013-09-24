/**
 *       \file       confirm-main.cpp
 *
 *       \brief      Main method to call ConfirmPage of Login class
 *                   and creating confirm.html page
 *
 *       \version    0.8
 *       \date       Sunday 07 April 2013 07:40:31  IST\n
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
 *      \brief  Main method
 *      \param  void no arguments
 */

int main(void)
{
    Login user;
    user.ConfirmPage();

    return 0;
}
