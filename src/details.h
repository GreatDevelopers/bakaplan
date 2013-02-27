/*
 * ===================================================================
 *
 *       Filename:  detail.h
 *
 *    Description:  Base class for all common variable declaration and
 *                  functions that are used by derived classes
 *
 *        Version:  0.6
 *        Created:  Friday 22 February 2013 11:34:29  IST
 *       Compiler:  gcc
 *
 *         Author:  Mandeep Kaur, meghasimak@gmail.com
 *        License:  GNU General Public License
 *      Copyright:  Copyright (c) 2013, Great Developers
 *
 * ===================================================================
 */

/**-------------------------------------------------------------------
 *  Include local header files
 *------------------------------------------------------------------*/

#include "filenames.h"                  /* I/O  File Names */
#include "pagelayout.h"                 /* PageLayout Class */
#include "inputfieldnames.h"            /* InputFieldNames Class */
#include "readinputfields.h"            /* ReadInputFields Class */
#include "constants.h"                  /* Constants for array size */

/**
 * ===================================================================
 *        Class:  Details
 *  Description:  Include common variables, functions that are used by
 *                derived classes
 * ===================================================================
 */

class Detail : public PageLayout
{
    protected:
        /* Common variables and objects */
        
        /** Objects of InputFieldNames and ReadFieldsValue class  */

        InputFieldNames fieldName;
        ReadInputFields readField;
        
        int i, j, k;                           /* Looping Variables */

        stringstream ss;            /* for converting int to string */
        string temp;                      /* for temporary strorage */

    public:

        Detail();       
        void Header(string titleName);
        void Footer();
        string IntToString(int value);
};
