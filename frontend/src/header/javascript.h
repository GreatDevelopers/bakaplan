/*
 * ===================================================================
 *
 *       Filename:  javascript.h
 *
 *    Description:  For creating .js files, Javascript class
 *                  definition
 *
 *        Version:  0.6
 *        Created:  Sunday 03 March 2013 04:25:09  IST
 *       Compiler:  gcc
 *
 *         Author:  Mandeep Kaur, meghasimak@gmail.com
 *        License:  GNU General Public License
 *      Copyright:  Copyright (c) 2013, GreatDevelopers
 *                  https://github.com/GreatDevelopers
 *
 * ===================================================================
 */

/**-------------------------------------------------------------------
 *  Include header.h file
 *------------------------------------------------------------------*/
#include "header.h"

/**
 * ===================================================================
 *        Class:  JavaScript
 *  Description:  For creating .js files
 * ===================================================================
 */

class JavaScript
{
    protected:

    public:
        /** Constructor */
        JavaScript();

        /** For input fields(onfocus action) */
        void OnFocusEvent();
        
        /** onchange func. of javascript for i/p fields */
        void OnChangeEvent();

        ~JavaScript(){}
};
