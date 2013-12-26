/**
 *       \file       page_structure.cc
 *
 *       \brief      Definition of Page Structure class functions \n
 *
 *       \compiler   g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com \n
 *       \license    GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

#include "header/page_structure.h"

/**
 *      \fn     PageStructure :: PageStructure()
 *      \brief  Constructor
 */
PageStructure :: PageStructure()
{
    // constructur
}

/**
 *      \fn     PageStructure :: CSS(string)
 *      \brief  Adding CSS file in HTML Content
 *      \param  href reference link
 */
void PageStructure :: CSS(string href)
{
    cout << "<link href=\"../../bakaplan/" << href << "\"" 
         << " rel=\"stylesheet\" media=\"all\" type=\"text/css\">"
         << endl;
}

/**
 *      \fn     PageStructure :: JS(string)
 *      \brief  Adding Javascript file in HTML Page
 *      \param  src source link
 */
void PageStructure :: JS(string src)
{
    cout << "<script src=\"../../bakaplan/" << src << "\"></script>" << endl;
}

/**
 *      \fn     PageStructure :: SideMenu()
 *      \brief  Side Menu Bar
 */
void PageStructure :: SideMenu(int sid)
{
    cout << " <nav class=\"side-menu\"> "
         << " <span id=\"toggle-menu\"> <p id=\"toggle-menu-circle\"> "
         << "Show Menu </p> </span> "
         << " <h3> Ba<span class=\"ka\">ka</span> Plan</h3>"
         << "<a href=\"bakaplan\"> Home </a>"
//         << "<a href=\"../../BaKaPlan/about.html\"> About </a>"
//         << "<a href=\"contribute.html\"> Contribute </a>"
//         << "<a href=\"../../BaKaPlan/contact.html\">Contact  </a>"
         << "<a href=\"bakaplan?LogOut=yes\"> Log Out </a>"
         << "</nav> ";
}

/**
 *      \fn     PageStructure :: CommonCSSFiles()
 *      \brief  Adding css files for all pages
 */
void PageStructure :: CommonCSSFiles()
{
    // Fonts from google fonts, Roboto and Arvo
//    CSS("http://fonts.googleapis.com/css?family=Roboto+Slab:400,300,700");
    cout << "<link href='http://fonts.googleapis.com/css?family="
            "Roboto+Slab:400,300,700' rel='stylesheet' type='text/css'>";
    // CSS files for our pages layout
    CSS("styles/general.css");
    CSS("styles/pages.css");
    CSS("styles/opentip.css");
}

/**
 *      \fn     PageStructure :: CommonJSFiles()
 *      \brief  Adding JS files for all pages
 */
void PageStructure :: CommonJSFiles()
{
    // Open Tooltip Javascript and css framework for adding tooltips
    cout << "<script src=\"http://"
            "ajax.googleapis.com/ajax/libs/jquery/2.0.0/jquery.min.js\""
            "></script>";

    JS("js/opentip-jquery.min.js");
    JS("js/opentip-myStyles.js");
    JS("js/validate.min.js");
    //JS("js/sidemenu.js");
    JS("js/opentip-myStyles.js");
}

/**
 *      \fn     PageStructure :: ~PageStructure()
 *      \brief  Destructor
 */
PageStructure :: ~PageStructure()
{
    // destructor
}

/*
 * Local Variables:
 * tab-width: 4
 * expandtab
 * ex: shiftwidth=4 tabstop=4
 */

