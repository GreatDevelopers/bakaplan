/*
 * ===================================================================
 *
 *       Filename:  pagelayout.cc
 *
 *    Description:  Definition of member functions of PageLayout
 *                  class. This includes header, footer section of 
 *                  html pages.
 *
 *        Version:  0.7
 *        Created:  Friday 15 February 2013 07:05:50  IST
 *       Compiler:  g++
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
#include "header/pagelayout.h"

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
    cout << logoName << endl;//" <sup>Beta</sup>" << endl;
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
//    Menu();
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
    string js = "../../BaKaPlan/javascript/javascript.js";
    Javascript(js);
//    Javascript("https://ajax.googleapis.com/ajax/libs/jquery/2.0.0/jquery.min.js");
//    Javascript(js);
    js = "../../BaKaPlan/javascript/CalendarControl.js";
    Javascript(js);
    string css = "../../BaKaPlan/css/CalendarControl.css";
    CSS(css);
    css = "../../BaKaPlan/css/default.css";
    CSS(css);
    /*  Include External CSS file path */
   /* js = "https://ajax.googleapis.com/ajax";
    js += "/libs/jquery/1.7.2/jquery.min.js";
    Javascript(js);*/
//    Javascript("javascript.js");

    //CSS("../../BaKaPlan/styles.css");   // ---------- CSS

/* 
    cout << "<!-- jQuery for navigation -->  "
         << "<script>"
         << "$(function() {"
         << "var pull    = $('#pull');"
         << "var menu        = $('nav ul');"
         << "var menuHeight  = menu.height();"
         << "$(pull).on('click', function(e) {"
         << "e.preventDefault();"
         << "menu.slideToggle();"
         << "});"
         << "$(window).resize(function(){"
         << "var w = $(window).width();"
         << "if(w > 600 && menu.is(':hidden')) {"
         << "menu.removeAttr('style');"
         << "}"
         << "});"
         << "});"
         << "</script>";
*/
    // New Look

//	<!-- Fonts from google fonts, Roboto and Arvo -->
    cout << "<link href='http://fonts.googleapis.com/css?family="
         << "Roboto+Slab:400,300,700' rel='stylesheet' type='text/css'>";

//	<!-- CSS files for our pages layout -->
	
    cout << "<link rel=\"stylesheet\" "
         << "href=\"../../BaKaPlan/styles/general.css\" "
         << "type=\"text/css\" media=\"all\">"
         << "<link rel=\"stylesheet\" "
         << "href=\"../../BaKaPlan/styles/pages.css\" "
         << "type=\"text/css\" media=\"all\">"

//	<!-- Open Tooltip Javascript and css framework for adding tooltips -->	

//         << "<script src=\"http://ajax.googleapis.com/ajax/"
//         << "libs/jquery/2.0.0/jquery.min.js\"></script>"
         << "<script src=\"../../BaKaPlanjs/opentip-jquery.min.js\">"
         << "</script>"
         << "<script src=\"../../BaKaPlan/js/opentip-myStyles.js\">"
         << "</script>"
         << "<link rel=\"stylesheet\" "
         << "href=\"../../BaKaPlan/styles/opentip.css\" "
         << "type=\"text/css\" media=\"all\">";

    HeadEnd();
}

/**
 *--------------------------------------------------------------------\n
 *       Class:  PageLayout \n
 *      Method:  PageLayout :: SetCookies(string sessionID) \n
 * Description:  Setting session ID in cookies \n
 *--------------------------------------------------------------------
 */

void PageLayout :: SetCookies(string userEmailID, string sessionID)
{
    cout << "Set-Cookie:EmailID=" << userEmailID << ";\r\n";
    cout << "Set-Cookie:SessionID=" << sessionID << ";\r\n";
}

/**
 *--------------------------------------------------------------------\n
 *       Class:  PageLayout \n
 *      Method:  PageLayout :: ContextType \n
 * Description:  Setting content-type header \n
 *--------------------------------------------------------------------
 */

void PageLayout :: ContentType()
{
    cout << "Content-type:text/html\n\n";
}

/**
 *--------------------------------------------------------------------\n
 *       Class:  PageLayout \n
 *      Method:  PageLayout :: LogOutLink() \n
 * Description:  logout link \n
 *--------------------------------------------------------------------
 */

void PageLayout :: LogoutLink()
{
    /*
    cout << brk;
    Anchor("logout", "Logout");
    cout << " | ";
    Anchor("project", "Home");
    cout << brk;
    */
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
