/*
 * ===================================================================
 *
 *       Filename:  readinputfields.h
 *
 *    Description:  Declaration of ReadInputField i.e. used to read
 *    value of any field using cgicc library.
 *
 *        Version:  0.7
 *        Created:  Saturday 16 February 2013 02:31:27  IST
 *       Compiler:  g++
 *
 *         Author:  Mandeep Kaur, meghasimak@gmail.com
 *        License:  GNU General Public License
 *      Copyright:  Copyright (c) 2013, Great Developers
 *
 * ===================================================================
 */

#ifndef READINPUTFIELD_H
#define READINPUTFIELD_H

/**-------------------------------------------------------------------
 *  Include required header files
 *------------------------------------------------------------------*/

#include "header.h"                         /* Header File */
#include "cgicc.h"                          /* CGICC Header Files */

/**
 * ===================================================================
 *        Class:  ReadInputField
 *  Description:  For reading values of fields like textbox, select,
 *                etc.
 * ===================================================================
 */

class ReadInputField
{
    protected:
        // For storing value of field
        string fieldValue;

        // Variables used in reading input fields
        Cgicc formData;                         /**< Read Form Data */
        form_iterator fi;                       /**< Form Iterator */

        /*Cgicc cgi; 
        const_cookie_iterator cci;*/

    public:
        /** Constructor */
        ReadInputField(){}

        /* Public Member Functions */
        
        /** Read Field's Value with one argument fieldName */
        string ReadFieldValue(string fieldName);

        /** Read Field's value with two arguments fieldName and field
         no.) */
        string ReadFieldValue(string fieldName, int fieldNo);

        /** Read cookies */
        //string ReadCookie(string cookieName);
};

#endif
