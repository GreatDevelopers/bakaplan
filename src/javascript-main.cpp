/*
 * ===================================================================
 *
 *       Filename:  javascript-main.cpp
 *
 *    Description:  Main method to call JavaScript class's functions
 *                  and for creating javascript.js file for input
 *                  field's events like onclick, onfocus, etc.
 *
 *        Version:  0.6
 *        Created:  Sunday 03 March 2013 05:05:40  IST
 *       Compiler:  gcc
 *
 *         Author:  Mandeep Kaur, meghasimak@gmail.com
 *        License:  GNU General Public License
 *      Copyright:  Copyright (c) 2013, GreatDevelopers
 *                  https://github.com/GreatDevelopers
 *
 * ===================================================================
 */

/**-------------------------------------------------------------------
 *  Include javascript.h file
 *------------------------------------------------------------------*/

#include "javascript.h"

/**-------------------------------------------------------------------
 *  main Method for creating object of JavaScript Class
 *------------------------------------------------------------------*/

int main(void)
{
    JavaScript js;
    js.OnFocusEvent();

    return 0;
}
