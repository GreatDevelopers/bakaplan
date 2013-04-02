/**
 *       \file       strategy.h
 *
 *       \brief      Strategy class for checking selected strategy is
 *                   valid for seating plan or not.
 *
 *       \version    0.6
 *       \date       Tuesday 02 April 2013 02:09:24  IST\n
 *       Compiler    g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

/**
 *  include seatplan.h file 
 */

#include "seatplan.h"

/**
 *      \class  Strategy
 *      \brief  Strategy class to check selected strategy is valid or
 *              not for seating plan
 */

class Strategy : public SeatPlan
{
    protected:
        
    public:
        /** Constructor */
        Strategy();

        void Main(string pID);

        /** Destructor */
        ~Strategy();
};
