/**
 *
 *       \file       read-inputfield.h
 *
 *       \brief      Declaration of ReadInputField i.e. used for
 *                   reading value of any input field using cgicc 
 *                   library.
 *
 *       \compiler   g++\n
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       \license    GNU General Public License\n
 *       \copyright  Copyright (c) 2013, GreatDevelopers\n
 *                   https://github.com/GreatDevelopers
 */

#ifndef READ_INPUTFIELD_H
#define READ_INPUTFIELD_H

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

/*
 * Local Variables:
 * tab-width: 4
 * expandtab
 * ex: shiftwidth=4 tabstop=4
 */

