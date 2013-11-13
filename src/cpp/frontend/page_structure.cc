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
    cout << "<link href=\"" << href << "\"" 
         << " rel=\"stylesheet\" media=\"screen\" type=\"text/css\">"
         << endl;
}

/**
 *      \fn     PageStructure :: Javascript(string)
 *      \brief  Adding Javascript file in HTML Page
 *      \param  src source link
 */
void PageStructure :: Javascript(string src)
{
    cout << "<script src=\"" << src << "\"></script>" << endl;
}

/**
 *      \fn     PageStructure :: SideMenu()
 *      \brief  Side Menu Bar
 */
void PageStructure :: SideMenu()
{
    cout << " <nav class=\"side-menu\"> "
         << " <span id=\"toggle-menu\"> <p id=\"toggle-menu-circle\"> "
         << "Show Menu </p> </span> "
         << " <h3> Ba<span class=\"ka\">ka</span> Plan</h3>"
         << "<a href=\"main\"> Home </a>"
//         << "<a href=\"../../BaKaPlan/about.html\"> About </a>"
//         << "<a href=\"contribute.html\"> Contribute </a>"
//         << "<a href=\"../../BaKaPlan/contact.html\">Contact  </a>"
         << "<a href=\"main?log_out=yes\"> Log Out </a>"
         << "</nav> ";
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

