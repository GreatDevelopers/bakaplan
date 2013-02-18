/*
 * ===================================================================
 *
 *       Filename:  pagelayout.cc
 *
 *    Description:  Definition of member functions of PageLayout
 *    class. This includes header, footer section of html pages.
 *
 *        Version:  0.6
 *        Created:  Friday 15 February 2013 07:05:50  IST
 *       Compiler:  gcc
 *
 *         Author:  Mandeep Kaur, meghasimak@gmail.com
 *        License:  GNU General Public License
 *      Copyright:  Copyright (c) 2013, Great Developers
 *
 * ===================================================================
 */

/**-------------------------------------------------------------------
 *  Include local header file
 *------------------------------------------------------------------*/
#include "pagelayout.h"

/**-------------------------------------------------------------------
 *  Function Definitions of PageLayout Class
 *------------------------------------------------------------------*/

/**
 *--------------------------------------------------------------------
 *       Class:  PageLayout
 *      Method:  PageLayout :: PageLayout()
 * Description:  Constructor
 *--------------------------------------------------------------------
 */

PageLayout :: PageLayout()
{
    projectName = "BaKaPlan";
}

/**
 *--------------------------------------------------------------------
 *       Class:  PageLayout
 *      Method:  PageLayout :: Menu()
 * Description:  Add Menu on pages(for navigation)
 *--------------------------------------------------------------------
 */

void PageLayout :: Menu()
{
    cout << "<nav class=\"clearfix fullwidth\">"
         << "<ul class=\"clearfix\">"
         << " <li><a href=\"#\">About</a></li>"
         << "<li><a href=\"https://github.com/GreatDevelopers"
         << "/bakaplan#readme\">How to use?</a></li>"
         << "<li><a href=\"https://github.com/GreatDevelopers"
         << "/bakaplan/issues/new#\">Add Feature/Bug</a></li>"
         << "<li><a href=\"https://github.com/GreatDevelopers"
         << "/bakaplan#authors\">Contact</a></li>"
         << "   </ul>   <a href=\"#\" id=\"pull\">Menu</a></nav>"
         << endl;
}

/**
 *--------------------------------------------------------------------
 *       Class:  PageLayout
 *      Method:  PageLayout :: Logo(string logoName)
 * Description:  Logo to project
 *--------------------------------------------------------------------
 */

void PageLayout :: Logo(string logoName)
{
    DivStart("slogo", "logo");
    cout << logoName << " <sup>Beta</sup>" << endl;
    DivEnd();
}

/**
 *--------------------------------------------------------------------
 *       Class:  PageLayout
 *      Method:  PageLayout :: Header()
 * Description:  Call Menu Function
 *--------------------------------------------------------------------
 */

void PageLayout :: Header()
{
    cout << "<header>";
    Menu();
    cout << "</header>";
//    Logo(projectName);
}

/**
 *--------------------------------------------------------------------
 *       Class:  PageLayout
 *      Method:  PageLayout :: Head(string titleName)
 * Description:  Head Section of page, titlaName pass to Title
 * function.
 *--------------------------------------------------------------------
 */

void PageLayout :: Head(string titleName)
{
    HeadStart();
    Title(titleName);
    CSS("");                      /* Include External CSS file path */
    HeadEnd();
}

/**
 *--------------------------------------------------------------------
 *       Class:  PageLayout
 *      Method:  PageLayout :: Footer()
 * Description:  Footer of pages
 *--------------------------------------------------------------------
 */

void PageLayout :: Footer()
{
    // Footer    
}
