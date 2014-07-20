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
#include "header/css_class.h"

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
 *      \brief  Writing Project detail into database
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
    cout << cgicc::div().set("id", "DivProject");

    cout << h1() << "Project Detail" << h1();
    cout << form().set("id", "FormProject").set("action", "")
                  .set("method", "POST");

    cout << input().set("type", "text").set("class", css::className["text"]);

    cout << form();
    cout << cgicc::div();
}

/**
 *      \fn     ProjectDetail :: ~ProjectDetail()
 *      \brief  Desrtuctor
 */
ProjectDetail :: ~ProjectDetail()
{
    // desrtuctor
}

