/**
 *       \file       seatplan.h
 *
 *       \brief      Declaration of SeatPlan class for generating
 *                   seating plan
 *
 *       \version    0.6
 *       \date       Tuesday 02 April 2013 02:05:39  IST\n
 *       Compiler    g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

/**
 *  include readinput.h 
 */
#include "readinput.h"

/**
 *      \class  SeatPlan
 *      \brief  SeatPlan CLass for generating seating plan
 */

class SeatPlan : public ReadInput
{
    protected:

    public:
        /** Constructor */
        SeatPlan();


        /** Destructor */
        ~SeatPlan();

};
