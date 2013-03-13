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

#include "filename.h"                            /* I/O  File Names */
#include "pagelayout.h"                         /* PageLayout Class */
#include "inputfieldname.h"                 /* InputFieldName Class */
#include "readinputfield.h"                 /* ReadInputField Class */
#include "constant.h"                   /* Constants for array size */
#include "database.h"                  /* For database connectivity */

/**
 * ===================================================================
 *        Class:  InputDetail
 *  Description:  Include common variables, functions that are used by
 *                derived classes
 * ===================================================================
 */

class InputDetail : public PageLayout
{
    protected:
        /* Common variables and objects */
        
        /** Objects of InputFieldName and ReadFieldsValue class  */

        InputFieldName fieldName;
        ReadInputField readField;
        Database database;
        
        int i, j, k;                           /* Looping Variables */

        stringstream ss;            /* for converting int to string */
        string temp;                      /* for temporary strorage */
        // For project detail
        string projectID,                           /**< Project ID */
               emailID,                               /**< Email id */
               projectName;                       /**< Project Name */

        // For class detail


    public:

        InputDetail();       
        void Header(string titleName);
        void Footer();
        string IntToString(int value);
        
        /// Convert String to Integer
        int StringToInt(string value);
};
