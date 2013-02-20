/*
 * ===================================================================
 *
 *       Filename:  readinputfields.cc
 *
 *    Description:  Definition of ReadInputFields's member functions.
 *
 *        Version:  0.6
 *        Created:  Saturday 16 February 2013 02:32:31  IST
 *       Compiler:  gcc
 *
 *         Author:  Mandeep Kaur, meghasimak@gmail.com
 *        License:  GNU General Public License
 *      Copyright:  Copyright (c) 2013, Great Developers
 *
 * ===================================================================
 */

/**-------------------------------------------------------------------
 *  Include Header file of ReadInputFields class declaration
 *------------------------------------------------------------------*/

#include "readinputfields.h"

/**-------------------------------------------------------------------
 *  Definition of member functions of ReadInputFields Class
 *------------------------------------------------------------------*/

/**
 *--------------------------------------------------------------------
 *       Class:  ReadInputFields
 *      Method:  ReadInputFields :: ReadFieldValue(string fieldName)
 * Description:  Read field's value and return it as string
 *--------------------------------------------------------------------
 */

string ReadInputFields :: ReadFieldValue(string fieldName)
{
    fi = formData.getElement(fieldName);  
 
    if( !fi->isEmpty() && fi != (*formData).end()) 
    {  
        fieldValue = **fi;  
    }
    else
        fieldValue = " ";

    return fieldValue;
}

/**
 *--------------------------------------------------------------------
 *       Class:  ReadInputFields
 *      Method:  ReadInputFields :: ReadFieldValue(string fieldName, 
 *               int fieldNo)
 * Description:  Read field's value and return it as string
 *--------------------------------------------------------------------
 */

string ReadInputFields :: ReadFieldValue(string fieldName, int fieldNo)
{
    std::stringstream no;
    no << (fieldNo + 1);
    fieldName = fieldName + no.str();
    fieldValue = ReadFieldValue(fieldName);
    return fieldValue;
}

/**
 *--------------------------------------------------------------------
 *       Class:  ReadInputFields
 *      Method:  ReadInputFields :: StringToInt(string value)
 * Description:  Converts string value to integer
 *--------------------------------------------------------------------
 */

int ReadInputFields :: StringToInt(string value)
{
    return atoi(value.c_str());
}
