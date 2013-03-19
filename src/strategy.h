/**
 *       \file       strategy.h
 *
 *       \brief      Strategy class for taking strategy detail from
 *                   user. 
 *
 *       \version    0.6
 *       \date       Sunday 17 March 2013 10:54:33  IST\n
 *       Compiler    gcc
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

/**
 *  Include inputdetail.h file for basic variables and functions
 */

#include "inputdetail.h"
//#include "inputfile.h"

/**
 *      \class  Strategy
 *      \brief  Strategy class for taking strategy option from user
 *              and storing room details into database.
 */

class Strategy : public InputDetail
{
    protected:
        
        string centreName[MIN_SIZE],
               roomNo[MIN_SIZE],
               rows[MIN_SIZE],
               columns[MIN_SIZE],
               strategyName[MIN_SIZE];

        int totalRooms;
        
//        InputFile inputFile;

    public:
        /** Constructor */
        Strategy();

        /** Reading room details and storing them into database */
        void ReadRoomDetail();

        /** Writing room detail into file as I/p File  */
        void WriteRoomDetail();

        /** strategy page */
        void StrategyPage();
    
        /** destuctor */
        ~Strategy();
};
