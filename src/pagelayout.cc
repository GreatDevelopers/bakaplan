/**
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
 * ===  FUNCTION =====================================================
 *         Name:  PageLayout()
 *  Description:  Constructor to set projectName
 * ===================================================================
 */

PageLayout :: Pagelayout()
{
    projectName = "BaKaPlan";
}

/** 
 * ===  FUNCTION =====================================================
 *         Name:  Menu()
 *  Description:  Add Menus on page(for navigation)
 * ===================================================================
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
 * ===  FUNCTION =====================================================
 *         Name:  Logo(string logoName)
 *  Description:  Logo of project
 * ===================================================================
 */

void PageLayout :: Logo(string logoName)
{
    cout << "<div id = \"slogo\" class = \"logo\">"
         << logoName << " <sup>Beta</sup>" << endl
         << "</div>" << endl;
}

/** 
 * ===  FUNCTION =====================================================
 *         Name:  Header()
 *  Description:  Call Menu and Logo functions
 * ===================================================================
 */

void PageLayout :: Header()
{
    cout << "<header>";
    Menu();
    cout << "</header>";
//    Logo(projectName);
}


/** 
 * ===  FUNCTION =====================================================
 *         Name:  Footer()
 *  Description:  Footer of pages
 * ===================================================================
 */
