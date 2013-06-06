/**
 *
 *       \file       pagestructure.h
 *
 *       \brief      Definition of class PageStructureMaker. This file 
 *                   includes basic HTML tags that included for all 
 *                   pages like <HTML>, <HEAD>, </HEAD>, etc.
 *
 *       \version    0.7
 *       \date       Thursday 06 June 2013 11:02:25  IST\n
 *       Compiler    g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com\n
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

#ifndef PAGESTRUCTURE_H
#define PAGESTRUCTURE_H

#include "header.h"

/**
 *      \class  PageStructureMaker
 *      \brief  For declaring input tags or required tags that are
 *              used again and again.
 */

class PageStructureMaker
{
    public:
        /* HTML Tag Variables for td, th, bold, etc */
        string startH1, endH1, 
               startH3, endH3, 
               startTD, endTD, 
               startTH, endTH, 
               startTR, endTR, 
               startB, endB, 
               brk;

        PageStructureMaker();
        void SetHTMLVariables();
        void HTMLStart();                   
        void HTMLEnd();                     
        void HeadStart();                   
        void HeadEnd();                     
        void Title(string pageTitle);       
        void CSS(string href);              
        void Javascript(string src);        
        void BodyStart();                   
        void BodyEnd();
        void DivStart(string id, string className);
        void DivEnd();
        void FormStart(string name, string action, string method,
//                       string classId = "",
                       string onSubmit = "");
        void FormEnd();
        void TableStart(string id, string className);
        void TableEnd();
        void ListStart(string listType);
        void ListEnd(string listType);
        void ListItem(string listItem);
        void Anchor(string href, string target);
        void InputField( string type, string name, 
                        string placeholder, string onfocus = "",
                        string value = "");
        void InputField(string type, string name, 
                        int nameNo, string placeholder, 
                        string value = "");
        void Label(string forField, string value);
        void SelectFieldStart(string name);
        void SelectFieldEnd();
        void SelectOptionStart(string value, string selected);
        void SelectOptionEnd();
        void Button(string id, string type, string className, 
                    string value, string onClick = "");
};

#endif
