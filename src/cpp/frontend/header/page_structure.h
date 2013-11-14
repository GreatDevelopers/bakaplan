/**
 *       \file       page_structure.h
 *
 *       \brief      functions for HTML tags which are commonly used
 *                   and icluding common css and js files \n
 *
 *       \compiler   g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com \n
 *       \license    GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

#ifndef  PAGE_STRUCTURE_H
#define  PAGE_STRUCTURE_H

#include <iostream>
#include <string>

using namespace std;

/**
 *      \class  PageStructure
 *      \brief  Declaring functions for common html tags and adding
 *              css and javascript files
 */
class PageStructure
{
    protected:

    public:
        PageStructure();

        void CSS(string href);              
        void JS(string src);

        void CommonJSFiles();
        void CommonCSSFiles();

        void SideMenu();
        ~PageStructure();
};

#endif

/*
 * Local Variables:
 * tab-width: 4
 * expandtab
 * ex: shiftwidth=4 tabstop=4
 */

