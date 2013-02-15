/*
 * ===================================================================
 *
 *       Filename:  htmltags.h
 *
 *    Description:  This file includes basic HTML tags that included
 *    for all pages like <HTML>, <HEAD>, </HEAD>, etc.
 *
 *        Version:  0.6
 *        Created:  Friday 15 February 2013 05:08:42  IST
 *       Compiler:  gcc
 *
 *         Author:  Mandeep Kaur, meghasimak@gmail.com
 *        License:  GNU General Public License
 *      Copyright:  Copyright (c) 2013, Great Developers
 *
 * ===================================================================
 */

/** Include Header file */
#include "header.h"                        

/**
 * ===================================================================
 *        Class:  HTMLTags
 *  Description:  Declaration
 * ===================================================================
 */

class HTMLTags
{
    private:

    protected:

    public:
        /** Constructor */
        HTMLTags();                         

        /** <HTML>  */ 
        void HTMLStart();                   
        
        /** </HTML> */
        void HTMLEnd();                     
        
        /** <HEAD>  */
        void HeadStart();                   
        
        /** </HEAD> */
        void HeadEnd();                     
        
        /** <TITLE> </TITLE>*/
        void Title(string pageTitle);       
        
        /** Add External CSS */
        void CSS(string href);              
        
        /** Add Javascript File */
        void Javascript(string src);        
        
        /** <BODY> */
        void BodyStart();                   
        
        /** </BODY> */
        void BodyEnd();                     
};
