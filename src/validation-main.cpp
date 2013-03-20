/**
 *       \file       validation-main.cpp
 *
 *       \brief      Main method for creating Validation Class's
 *                   object and calling its function to create 
 *                   validation.html page.
 *
 *       \version    0.6
 *       \date       Wednesday 20 March 2013 05:23:24  IST\n
 *       Compiler    gcc
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

/**
 *  Include validation.h file 
 */
#include "validation.h"

/** 
 *      \fn     main(void)
 *      \brief  main method
 *      \param  void
 */

int main(void)
{
    Validation valid;
    valid.ValidationPage();

    return 0;
}
