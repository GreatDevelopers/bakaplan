/*
 * ===================================================================
 *
 *       Filename:  inputdetail.cc
 *
 *    Description:  Definition of member functions of InputDetail class
 *
 *        Version:  0.6
 *        Created:  Sunday 24 February 2013 01:31:21  IST
 *       Compiler:  gcc
 *
 *         Author:  Mandeep Kaur, meghasimak@gmail.com
 *        License:  GNU General Public License
 *      Copyright:  Copyright (c) 2013, Great Developers
 *
 * ===================================================================
 */

/**-------------------------------------------------------------------
 *  Include detail.h file
 *------------------------------------------------------------------*/

#include "inputdetail.h"

/**-------------------------------------------------------------------
 *  Definition of member functions
 *------------------------------------------------------------------*/

/**
 *--------------------------------------------------------------------
 *       Class:  InputDetail
 *      Method:  InputDetail :: InputDetail()
 * Description:  Constructor
 *--------------------------------------------------------------------
 */

InputDetail :: InputDetail()
{

}

/**
 *--------------------------------------------------------------------
 *       Class:  InputDetail
 *      Method:  InputDetail :: Header(string titleName)
 * Description:  common header for all pages(start html, head, body)
 *--------------------------------------------------------------------
 */

void InputDetail :: Header(string titleName)
{
    
    HTMLStart();
    Head(titleName);
    PageLayout :: Header();
    BodyStart();
    Logo("BaKaPlan");
}

/**
 *--------------------------------------------------------------------
 *       Class:  InputDetail
 *      Method:  InputDetail :: Footer()
 * Description:  Common for all pages(end body, html)
 *--------------------------------------------------------------------
 */

void InputDetail :: Footer()
{
    BodyEnd();
    HTMLEnd();
}

/**
 *--------------------------------------------------------------------
 *       Class:  InputDetail
 *      Method:  InputDetail :: IntToString(int value)
 * Description:  Convert Int to String using stringstream object
 *--------------------------------------------------------------------
 */

string InputDetail :: IntToString(int value)
{
     ss.clear(); ss.str("");          /*  Empty stringstream object */
     ss << value;
     return ss.str();
}

/**
 *--------------------------------------------------------------------
 *       Class:  ReadInputField
 *      Method:  ReadInputField :: StringToInt(string value)
 * Description:  Converts string value to integer
 *--------------------------------------------------------------------
 */

int InputDetail :: StringToInt(string value)
{
    return atoi(value.c_str());
}
