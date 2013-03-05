/*
 * ===================================================================
 *
 *       Filename:  javascript.cc
 *
 *    Description:  Definition of JavaScript Class functions
 *
 *        Version:  0.6
 *        Created:  Sunday 03 March 2013 04:31:11  IST
 *       Compiler:  gcc
 *
 *         Author:  Mandeep Kaur, meghasimak@gmail.com
 *        License:  GNU General Public License
 *      Copyright:  Copyright (c) 2013, GreatDevelopers
 *                  https://github.com/GreatDevelopers
 *
 * ===================================================================
 */

/**-------------------------------------------------------------------\n
 *  Include javascript.h file \n
 *------------------------------------------------------------------*/

#include "javascript.h"

/**
 *--------------------------------------------------------------------\n
 *       Class:  JavaScript \n
 *      Method:  JavaScript :: JavaScript() \n
 * Description:  Constructor \n
 *--------------------------------------------------------------------
 */

JavaScript :: JavaScript()
{
    cout << "Content-type:text/html\n\n ";
}

/**
 *--------------------------------------------------------------------\n
 *       Class:  JavaScript \n
 *      Method:  JavaScript :: OnFocusEvent() \n
 * Description:  method for onfocus function in jascript \n
 *--------------------------------------------------------------------
 */

void JavaScript :: OnFocusEvent()
{
    cout << "function OnFocus(value, name, text) "
         << "{"
         << "   var val = document.getElementByName(name);"
         << "   if ( val.value.length)// != \"\" && value == text )"
         << "   {"
         << "       document.getElementByName(name).innerHTML = \"\";"
         << "       alert(\"if\");"
         << "   }"
         << "   else"
         << "       alert(\"else\")"
         << "}"
         << endl;
}
