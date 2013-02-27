/*
 * ===================================================================
 *
 *       Filename:  readinputfields.cc
 *
 *    Description:  Definition of ReadInputField's member functions.
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
 *  Include Header file of ReadInputField class declaration
 *------------------------------------------------------------------*/

#include "readinputfields.h"

/**-------------------------------------------------------------------
 *  Definition of member functions of ReadInputField Class
 *------------------------------------------------------------------*/

/**
 *--------------------------------------------------------------------
 *       Class:  ReadInputField
 *      Method:  ReadInputField :: ReadFieldValue(string fieldName)
 * Description:  Read field's value and return it as string
 *--------------------------------------------------------------------
 */

string ReadInputField :: ReadFieldValue(string fieldName)
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
 *       Class:  ReadInputField
 *      Method:  ReadInputField :: ReadFieldValue(string fieldName, 
 *               int fieldNo)
 * Description:  Read field's value and return it as string
 *--------------------------------------------------------------------
 */

string ReadInputField :: ReadFieldValue(string fieldName, int fieldNo)
{
    std::stringstream no;
    no << (fieldNo + 1);
    fieldName = fieldName + no.str();
    fieldValue = ReadFieldValue(fieldName);
    return fieldValue;
}

/**
 *--------------------------------------------------------------------
 *       Class:  ReadInputField
 *      Method:  ReadInputField :: StringToInt(string value)
 * Description:  Converts string value to integer
 *--------------------------------------------------------------------
 */

int ReadInputField :: StringToInt(string value)
{
    return atoi(value.c_str());
}
