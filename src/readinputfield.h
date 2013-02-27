/*
 * ===================================================================
 *
 *       Filename:  readinputfields.h
 *
 *    Description:  Declaration of ReadInputFields i.e. used to read
 *    value of any field using cgicc library.
 *
 *        Version:  0.6
 *        Created:  Saturday 16 February 2013 02:31:27  IST
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

#include "header.h"                         /* Header File */
#include "cgicc.h"                          /* CGICC Header Files */

/**
 * ===================================================================
 *        Class:  ReadInputFields
 *  Description:  For reading values of fields like textbox, select,
 *                etc.
 * ===================================================================
 */

class ReadInputFields
{
    protected:
        /// For storing value of field
        string fieldValue;

        /// Variables used in reading input fields
        Cgicc formData;                         /* Read Form Data */
        form_iterator fi;                       /* Form Iterator */

    public:
        /// Constructor
        ReadInputFields(){}

        /// Public Member Functions
        
        /// Read Field's Value with one argument fieldName
        string ReadFieldValue(string fieldName);

        /// Read Field's value with two arguments fieldName and field
        /// no.)
        string ReadFieldValue(string fieldName, int fieldNo);

        /// Convert String to Integer
        int StringToInt(string value);

};
