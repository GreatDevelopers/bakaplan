/**
 *       \file       project_detail.cc
 *
 *       \brief      Function Definition of project detail class \n
 *
 *       \compiler   g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com \n
 *       \license    GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

#include "header/project_detail.h"

/**
 *      \fn     ProjectDetail :: ProjectDetail()
 *      \brief  Constructor
 */
ProjectDetail :: ProjectDetail()
{
    // default definitions
}

/**
 *      \fn     ProjectDetail :: ReadProjectDetail()
 *      \brief  Reading Project detail filled by user
 */
void ProjectDetail :: ReadProjectDetail()
{

}

/**
 *      \fn     ProjectDetail :: WriteProjectDetail()
 *      \brief  Writing Project detail into file and database
 */
void ProjectDetail :: WriteProjectDetail()
{

}

/**
 *      \fn     ProjectDetail :: ProjectDetailPage()
 *      \brief  HTML Project Detail Page
 */
void ProjectDetail :: ProjectDetailPage()
{
    cout << HTTPHTMLHeader() << endl;

    cout << html() 
         << head() << title("Project Detail");

    CommonCSSFiles();
    CommonJSFiles();

    cout << head()
         << body().set("class", "coloredBody");
    
    SideMenu();

    cout << cgicc::div().set("class", "page-wrap");

    cout << h1().set("id", "tipTarget") << "~" << h1()
         << cgicc::div().set("id", "msg") << cgicc::div();

    cout << cgicc::div();

    cout << body()
         << html();

}

/**
 *      \fn     ProjectDetail :: ~ProjectDetail()
 *      \brief  Desrtuctor
 */
ProjectDetail :: ~ProjectDetail()
{
    // desrtuctor
}

