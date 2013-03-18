/**
 *       \file       inputfile.cc
 *
 *       \brief      Definition of member functions of InputFile Class
 *
 *       \version    0.6
 *       \date       Monday 18 March 2013 02:41:25  IST\n
 *       Compiler    gcc
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

/**
 *  Include inputfile.h for class declaration 
 */
#include "inputfile.h"

/**
 *      \class  InputFile
 *      \fn     InputFile :: InputFile()
 *      \brief  Constructor
 */

InputFile :: InputFile()
{
    // constructor
    i = 0;
    pID = "PID";
    inputFileName[i++] = "-classdetail";
    inputFileName[i++] = "-rollnodetail";
    inputFileName[i++] = "-roomdetail";
    inputFileName[i++] = "-strategy";
}

/**
 *      \class  InputFile
 *      \fn     InputFile :: ClassDetail(string projectID)
 *      \brief  Creating input file for class details
 *      \param  projectID For identifying class details in table
 */

void InputFile :: ClassDetail(string projectID)
{

}

/**
 *      \class  InputFile
 *      \fn     InputFile :: RollNoDetail(string projectID)
 *      \brief  Creating input file for roll no details
 *      \param  projectID for unique identification from table
 */

void InputFile :: RollNoDetail(string projectID)
{

}

/**
 *      \class  InputFile
 *      \fn     InputFile :: RoomDetail(string projectID)
 *      \brief  Creating input file for room details
 *      \param  projectID For identifying room details in table
 */

void InputFile :: RoomDetail(string projectID)
{

}

/**
 *      \class  InputFile
 *      \fn     InputFile :: Strategy(string projectID)
 *      \brief  For creating input file for selected strategy
 *      \param  projectID for unique identification
 */

void InputFile :: Strategy(string projectID)
{

}

/**
 *      \class  InputFile
 *      \fn     InputFile :: ~InputFile()
 *      \brief  Constructor
 */

InputFile :: ~InputFile()
{
    // destructor
}
