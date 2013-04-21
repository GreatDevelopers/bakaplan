/**
 *       \file       validation.h
 *
 *       \brief      Validation class
 *
 *       \version    0.6
 *       \date       Sunday 07 April 2013 08:24:00  IST\n
 *       Compiler    g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

#ifndef VALIDATION_H
#define VALIDATION_H

/**
 *  include inpudetail.h 
 */
#include "inputdetail.h"

class Validation : public InputDetail
{
    protected:

    public:
        /** Constructor */
        Validation();

        /** Read Strategy Detail */
        void ReadStrategyDetail();

        /** Write Strategy Detail */
        void WriteStrategyDetail();

        /** Validation Page */
        void ValidationPage();
    
        /** desrtuctor  */
        ~Validation();
};

#endif
