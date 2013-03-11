/*
 * ===================================================================
 *
 *       Filename:  pagelayout.h
 *
 *    Description:  Add Header, Footer, Menus to webpage(output html
 *                  pages. PageLayout Class for this purpose.
 *
 *        Version:  0.6
 *        Created:  Friday 15 February 2013 06:10:40  IST
 *       Compiler:  gcc
 *
 *         Author:  Mandeep Kaur, meghasimak@gmail.com
 *        License:  GNU General Public License
 *      Copyright:  Copyright (c) 2013, Great Developers
 *
 * ===================================================================
 */

/**-------------------------------------------------------------------
 *  Include required header files
 *------------------------------------------------------------------*/

#include "pagestructure.h"                   /* For basic HTML Tags */

/**
 * ===================================================================
 *        Class:  PageLayout : public PageStructureMaker
 *  Description:  For adding header and footer to page
 * ===================================================================
 */

class PageLayout : public PageStructureMaker
{
    protected:
        string projectName;              /* Project Name = BaKaPlan */
        
        ifstream inFile;                        /* For Reading file */
        ofstream outFile;                       /* For writing file */
        string sessionID;                       /**< Session ID */

    public:
        /** Constructor */
        PageLayout();

        /** Header Section of Page */
        void Header();                  

        /** Footer Section of Page */
        void Footer();                  

        /** List/Menu Navigation() */
        void Menu();                    

        /** Logo on Page */
        void Logo(string logoName);    

        /** Head Section of Page */
        void Head(string titleName);

        /** For Cookies after login */
        void SetCookies(string emailID, string sessionID);

        /** Unset cookies  */
        void UnSetCookies();
        
        /** Context-Type header  */
        void ContextType();

        /** Logout link  */
        void LogOutLink();
};
