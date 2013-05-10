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

#include "header/readinputfield.h"

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
    no << fieldNo;
    fieldName = fieldName + no.str();
    fieldValue = ReadFieldValue(fieldName);
    return fieldValue;
}

/**
 *--------------------------------------------------------------------\n
 *       Class:  ReadInputField \n
 *      Method:  ReadInputField :: ReadCookie(string cookieName) \n
 * Description:  Read cookies - email id and session id \n
 *--------------------------------------------------------------------
 */
 /*
string ReadInputField :: ReadCookie(string cookieName)
{
    // get environment variables                                       
    const CgiEnvironment& env = cgi.getEnvironment();                  
    
    string cookie = cookieName;

    for( cci = env.getCookieList().begin();                            
         cci != env.getCookieList().end();                             
         ++cci )                                                       
    {                                                                  
        if(cci->getName() == cookie)
        {                     
            fieldValue =  cci->getValue();
            return fieldValue;
        }                                                              
    }
    return fieldValue;
        
}*/
