/**
 *
 *       \file       readinputfield.h
 *
 *       \brief      Declaration of ReadInputField i.e. used to read
 *                   value of any field using cgicc library.
 *
 *       \version    0.8
 *       \date       Thursday 06 June 2013 11:07:13  IST\n
 *       Compiler    g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com\n
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

#ifndef READINPUTFIELD_H
#define READINPUTFIELD_H

#include "header.h"                         /* Header File */
#include "cgicc.h"                          /* CGICC Header Files */

/**
 *      \class  ReadInputField
 *      \brief  For reading values of fields like textbox, select,
 *              etc.
 */

class ReadInputField
{
    protected:
        string fieldValue;                   /**< Input Field Value */

        // Variables used in reading input fields
        Cgicc formData;                         /**< Read Form Data */
        form_iterator fi;                       /**< Form Iterator */

        /*Cgicc cgi; 
        const_cookie_iterator cci;*/

    public:
        ReadInputField(){}

        /* Public Member Functions */
        
        string ReadFieldValue(string fieldName);
        string ReadFieldValue(string fieldName, int fieldNo);

        /* Read cookies */
        //string ReadCookie(string cookieName);
};

#endif
