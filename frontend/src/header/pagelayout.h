/**
 *
 *       \file       pagelayout.h
 *
 *       \brief      Add Header, Footer, Menus to webpage(output html
 *                   pages. PageLayout Class for this purpose.
 *
 *       \version    0.8
 *       \date       Thursday 06 June 2013 11:00:26  IST\n
 *       Compiler    g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com\n
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

#ifndef PAGELAYOUT_H
#define PAGELAYOUT_H

#include "pagestructure.h"                   /* For basic HTML Tags */

/**
 *      \class  PageLayout
 *      \brief  For adding header and footer to page
 */

class PageLayout : public PageStructureMaker
{
    protected:
        string projectName;              /* Project Name = BaKaPlan */
        
    public:
        PageLayout();
        void Header();                  
        void Footer();                  
        void Menu();                    
        void Logo(string logoName);    
        void Head(string titleName);
        void SetCookies(string emailID, string sessionID);
        void ContentType();
        void LogoutLink();
};

#endif
