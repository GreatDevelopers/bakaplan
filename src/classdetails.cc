/*
 * ===================================================================
 *
 *       Filename:  classdetails.cc
 *
 *    Description:  Definition of ClassDetails's member functions.
 *
 *        Version:  0.6
 *        Created:  Saturday 16 February 2013 11:15:42  IST
 *       Compiler:  gcc
 *
 *         Author:  Mandeep Kaur, meghasimak@gmail.com
 *        License:  GNU General Public License
 *      Copyright:  Copyright (c) 2013, Great Developers
 *
 * ===================================================================
 */

/**-------------------------------------------------------------------
 *  Incude header file which has ClassDetails's declaration
 *------------------------------------------------------------------*/

#include "classdetails.h"

/**-------------------------------------------------------------------
 *  Defnition of member functions
 *------------------------------------------------------------------*/

/**
 *--------------------------------------------------------------------
 *       Class:  ClassDetails
 *      Method:  ClassDetails :: ClassDetails()
 * Description:  Constructor
 *--------------------------------------------------------------------
 */

ClassDetails :: ClassDetails()
{
    maxClasses      =       15;
}

/**
 *--------------------------------------------------------------------
 *       Class:  ClassDetails
 *      Method:  ClassDetails :: Header()
 * Description:  Includes menu, logo, header of page
 *--------------------------------------------------------------------
 */

void ClassDetails :: Header()
{
    HTMLStart();
    Head("Class Details");
    BodyStart();
    PageLayout :: Header();
}

/**
 *--------------------------------------------------------------------
 *       Class:  ClassDetails
 *      Method:  ClassDetails :: Footer()
 * Description:  Footer of page
 *--------------------------------------------------------------------
 */

void ClassDetails :: Footer()
{
    BodyEnd();
    HTMLEnd();
}

/**
 *--------------------------------------------------------------------
 *       Class:  ClassDetails
 *      Method:  ClassDetails :: TotalClasses()
 * Description:  Get Total classes from user
 *--------------------------------------------------------------------
 */

void ClassDetails :: TotalClasses()
{
    Header();
    
    DivStart("totalclasses", "");               /* (id, classname) */
    FormStart("totalclasses", "classinfo.html", "POST");

    cout << startH1 << " Select Total Classes " << endH1 << brk;
    
    SelectFieldStart(fieldName::totalClasses);
    
    for(i = 0; i < maxClasses; i++)
    {
        if(i == 5)
            SelectOptionStart(i, "y");
        else
            SelectOptionStart(i, "n");
        cout << i;
        SelectOptionEnd();
    }

    SelectFieldEnd();

    FormEnd();
    DivEnd();

    Footer();
}

/**
 *--------------------------------------------------------------------
 *       Class:  ClassDetails
 *      Method:  ClassDetails :: ClassInfo()
 * Description:  Get class name, subject code and subject name from
 * user.
 *--------------------------------------------------------------------
 */

void ClassDetails :: ClassInfo()
{
    Header();

    DivStart("classinfo", "");                  /* (id, classname) */
    FormStart("classinfo", "rollnodetails.html", "POST");

    FormEnd();
    DivEnd();

    Footer();
}
