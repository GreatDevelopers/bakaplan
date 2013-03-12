/*
 * ===================================================================
 *
 *       Filename:  classinfo.cpp
 *
 *    Description:  Main method file for getting class info like class
 *    name, subject code and subject names required for seating plan.
 *
 *        Version:  0.6
 *        Created:  Wednesday 20 February 2013 03:20:37  IST
 *       Compiler:  gcc
 *
 *         Author:  Mandeep Kaur, meghasimak@gmail.com
 *        License:  GNU General Public License
 *      Copyright:  Copyright (c) 2013, Great Developers
 *
 * ===================================================================
 */

/**-------------------------------------------------------------------
 *  Include classdetails.h header file for calling ClassInfo function  
 *------------------------------------------------------------------*/

#include "classdetail.h"
                                                
/**-------------------------------------------------------------------
 *  Main method
 *------------------------------------------------------------------*/

int main(void)
{
   ClassDetail classInfo;
   classInfo.ClassInfoPage();

   return 0;
}
