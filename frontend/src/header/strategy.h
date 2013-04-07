/**
 *       \file       strategy.h
 *
 *       \brief      Strategy Class
 *
 *       \version    0.6
 *       \date       Sunday 07 April 2013 08:18:55  IST\n
 *       Compiler    g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

#ifndef STRATEGY_H
#define STRATEGY_H

/**
 *  include inputdetail.h 
 */
#include "inputdetail.h"

class Strategy : InputDetail
{
    protected:

    public:
        Strategy();

        ~Strategy();
};

#endif

