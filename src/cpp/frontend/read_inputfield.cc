/**
 *
 *       \file       read-inputfield.cc
 *
 *       \brief      Read input fields using CGICC Library
 *
 *       \compiler   g++\n
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       \license    GNU General Public License\n
 *       \copyright  Copyright (c) 2013, GreatDevelopers\n
 *                   https://github.com/GreatDevelopers
 */

#include "header/read_inputfield.h"

/**
 *      \fn     ReadInputField :: ReadFieldValue(string fieldName)
 *      \brief  Read field's value and return it as string
 *      \param  fieldName   Input field name
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
 *      \fn     ReadInputField :: ReadFieldValue(string fieldName, 
 *                                               int fieldNo)
 *      \brief  Read field's value and return it as string
 *      \param  fieldName   Input field name
 *      \param  fieldNo     Input field no to identify fields
 *                          with same name.
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
 *      \fn     ReadInputField :: SetCookie(string, string)
 *      \brief  Set session cookie
 *      \param  cookieName Name of cookie
 *      \param  value      Value of cookie
 */
void ReadInputField :: SetCookie(string cookieName, string value)
{
    cout << "Set-Cookie:" << cookieName << "=" << value << ";\r\n";
}

/**
 *      \fn     ReadInputField :: ReadCookie(string cookieName)
 *      \brief  Read cookies - email id and session id
 *      \param  cookieName  Name of cookie
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

/*
 * Local Variables:
 * tab-width: 4
 * expandtab
 * ex: shiftwidth=4 tabstop=4
 */

