/**
 *
 *       \file       readinputfield.cc
 *
 *       \brief      Read Input Fields using CGICC Library 
 *
 *       \version    1.0
 *       \date       07/15/2013 11:51:01 PM\n
 *       Compiler    g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com\n
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

#include "header/readinputfield.h"

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
