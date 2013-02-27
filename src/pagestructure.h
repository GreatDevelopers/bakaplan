/*
 * ===================================================================
 *
 *       Filename:  pagestructure.h
 *
 *    Description:  Definition of class PageStructureMaker. This file 
 *                  includes basic HTML tags that included for all 
 *                  pages like <HTML>, <HEAD>, </HEAD>, etc.
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
 *        Class:  PageStructureMaker
 *  Description:  Declaration
 * ===================================================================
 */

class PageStructureMaker
{
    private:

    protected:
        /** HTML Tag Variables for td, th, bold, etc */
        string startH1, endH1, startH3, endH3, startTD, endTD, startTH,
               endTH, startTR, endTR, startB, endB, brk;

    public:
        /** Constructor */
        PageStructureMaker();

        /** Assingn Values to variables */
        void SetHTMLVariables();

        /** Display <HTML> */
        void HTMLStart();                   
        
        /** Display </HTML> */
        void HTMLEnd();                     
        
        /** Display <HEAD> */
        void HeadStart();                   
        
        /** Display </HEAD> */
        void HeadEnd();                     
        
        /** Display <TITLE> </TITLE> */
        void Title(string pageTitle);       
        
        /** Add External CSS */
        void CSS(string href);              
        
        /** Add Javascript File */
        void Javascript(string src);        
        
        /** Display <BODY> */
        void BodyStart();                   
        
        /** Display </BODY> */
        void BodyEnd();

        /** Start Div Section */
        void DivStart(string id, string className);

        /** End div section */
        void DivEnd();

        /** Start Form */
        void FormStart(string name, string action, string method);

        /** End Form */
        void FormEnd();

        /** Start Table */
        void TableStart(string id, string className);

        /** End Table */
        void TableEnd();

        /** Input Field */
        void InputField(string type, string name, int nameNo, 
                        string value);

        /** Select Field Start */
        void SelectFieldStart(string name);

        /** End Select Field */
        void SelectFieldEnd();

        /** Select Option Start */
        void SelectOptionStart(string value, string selected);

        /** Selct Option End */
        void SelectOptionEnd();

        /** Button */
        void Button(string id, string type, string className, 
                    string value);
};
