/*
 * ===================================================================
 *
 *       Filename:  details.cc
 *
 *    Description:  Definition of member functions of Details class
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
 *  Include details.h file
 *------------------------------------------------------------------*/

#include "details.h"

/**-------------------------------------------------------------------
 *  Definition of member functions
 *------------------------------------------------------------------*/

/**
 *--------------------------------------------------------------------
 *       Class:  Details
 *      Method:  Details :: Details()
 * Description:  Constructor
 *--------------------------------------------------------------------
 */

Details :: Details()
{

}

/**
 *--------------------------------------------------------------------
 *       Class:  Details
 *      Method:  Details :: Header(string titleName)
 * Description:  common header for all pages(start html, head, body)
 *--------------------------------------------------------------------
 */

void Details :: Header(string titleName)
{
    
    HTMLStart();
    Head(titleName);
    PageLayout :: Header();
    BodyStart();
    Logo("BaKaPlan");
}

/**
 *--------------------------------------------------------------------
 *       Class:  Details
 *      Method:  Details :: Footer()
 * Description:  Common for all pages(end body, html)
 *--------------------------------------------------------------------
 */

void Details :: Footer()
{
    BodyEnd();
    HTMLEnd();
}