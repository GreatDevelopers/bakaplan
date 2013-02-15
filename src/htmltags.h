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

        /// Start Div Section
        void DivStart(string id, string className);

        /// End div section
        void DivEnd();

        /// Start Form
        void FormStart(string name, string action, string method);

        /// End Form
        void FormEnd();

        /// Start Table
        void TableStart(string id, string className);

        /// End Table
        void TableEnd();

        /// Input Field
        void InputField(string type, string name, string value);

        /// Select Field Start
        void SelectFieldStart(string name);

        /// End Select Field
        void SelectFieldEnd();

        /// Select Option Start
        void SelectOptionStart(string value);

        /// Selct Option End
        void SelectOptionEnd();

        /// Button 
        void Button(string id, string type, string className, 
                    string value);

};
