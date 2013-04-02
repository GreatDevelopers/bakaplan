/**
 *       \file       strategy.cc
 *
 *       \brief      Function definition of Strategy class
 *
 *       \version    0.6
 *       \date       Tuesday 02 April 2013 03:02:04  IST\n
 *       Compiler    g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

/**
 *  include strategy.h 
 */

#include "header/strategy.h"

/**
 *      \class  Strategy
 *      \fn     Strategy :: Strategy()
 *      \brief  Constructor
 */

Strategy :: Strategy()
{
    // constructor
}

/**
 *      \class  Strategy
 *      \fn     Strategy :: Main(string pID)
 *      \brief  Main Function to call all other functions
 *      \param  pID project ID of user's project
 */

void Strategy :: Main(string pID)
{
   projectID = pID; 

   ReadDateSheetOut(projectID);
   ReadRoomDetail(projectID);
   ReadStrategy(projectID);
}

/**
 *      \class  Strategy
 *      \fn     Strategy :: ~Strategy()
 *      \brief  Destructor
 */

Strategy :: ~Strategy()
{
    // destructor
}
