/*
 * ===================================================================
 *
 *       Filename:  rollnodetails.cc
 *
 *    Description:  Definition of RollNoDetail's member functions.
 *
 *        Version:  0.6
 *        Created:  Saturday 16 February 2013 11:17:41  IST
 *       Compiler:  gcc
 *
 *         Author:  Mandeep Kaur, meghasimak@gmail.com
 *        License:  GNU General Public License
 *      Copyright:  Copyright (c) 2013, Great Developers
 *
 * ===================================================================
 */

/**-------------------------------------------------------------------
 *  Include rollnodetails.h for RollNoDetail class declaration
 *------------------------------------------------------------------*/

#include "rollnodetils.h"

/**-------------------------------------------------------------------
 *  Definition of functions RollNoDetail Class
 *------------------------------------------------------------------*/

/**
 *--------------------------------------------------------------------
 *       Class:  RollNoDetail
 *      Method:  RollNoDetail :: RollNoDetail()
 * Description:  Constructor
 *--------------------------------------------------------------------
 */

RollNoDetail :: RollNoDetail()
{

}

/**
 *--------------------------------------------------------------------
 *       Class:  RollNoDetail
 *      Method:  RollNoDetail :: ReadClassDetails()
 * Description:  For reading class details from previous page
 *--------------------------------------------------------------------
 */

void RollNoDetail :: ReadClassDetails()
{
   temp = readField.ReadFieldValue(fieldName.totalClasses);
   totalClasses = readField.StringToIn(temp);

   for(i = 0; i < totalClasses; i++)
   {
       prefix[i] = readField.ReadFieldValue(fieldName.prefix, (i + 1));
       startRollNo[i] = readField.ReadFieldValue(fieldName.startRollNo,
                                                  (i + 1));
       endRollNo[i] = readField.ReadFieldValue(fieldName.endRollNo, 
                                                (i + 1));
       notIncluded[i] = readField.ReadFieldValue(fieldName.notIncluded);
   }
}

void RollNoDetail :: WriteClassDetails()
{
    outFile.open(CLASS_DETAILS_IN);
    
    for(i = 0; i < totalClasses; i++)
    {
        outFile << totalClasses << endl
                << className[i] << endl
                << subjectName[i] << endl
                << subjectCode[i] << endl;
    }

    outFile.close();
}
