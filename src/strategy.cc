/**-------------------------------------------------------------------
 *
 *       \file       strategy.cc
 *
 *       \brief      For defnition of class member functions of
 *                   Strategy Class.
 *
 *       \version    0.6
 *       \date       Sunday 17 March 2013 11:17:20  IST\n
 *       Compiler    gcc
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 *
 *------------------------------------------------------------------*/

/**
 *  Include strategy.h 
 */
#include "strategy.h"

/**
 *      \class  Strategy
 *      \fn     Strategy :: Strategy()
 *      \brief  Constructor
 *      \param
 */

Strategy :: Strategy()
{
    // constructor
}

/**
 *      \class  Strategy
 *      \fn     Strategy :: ReadRoomDetail()
 *      \brief  Read room details from previous page and store them
 *              into database
 *      \param  
 */

void Strategy :: ReadRoomDetail()
{
    projectID = readField.ReadFieldValue(fieldName.projectID);
    
    database.SelectSum("TotalRooms", "TotalRooms", projectID, temp);

    totalRooms = StringToInt(temp);

    cout << totalRooms;
    
    for(i = 0; i < totalRooms; i++)
    {
        j = i + 1;
        centreName[i] = readField.ReadFieldValue(fieldName.centreName,
                                                 j);
        
        roomNo[i] = readField.ReadFieldValue(fieldName.roomNo, j);

        rows[i] = readField.ReadFieldValue(fieldName.rows, j);

        columns[i] = readField.ReadFieldValue(fieldName.columns, j);

        database.InsertRoomDetail(projectID, centreName[i], roomNo[i], 
                                  rows[i], columns[i]);
    }

}

/**
 *      \class  Strategy
 *      \fn     Strategy :: StrategyPage()
 *      \brief  Strategy page got taking i/p from user
 *      \param
 */

void Strategy :: StrategyPage()
{
    ContextType();

    Header("Strategy");
    
    DivStart("strategy", "");
    
    LogoutLink();
    
    cout << brk;

    FormStart("strategy", "validation.html", "POST");
 
    ReadRoomDetail();
    
    
    
    FormEnd();

    

    DivEnd();

    Footer();
}

/**
 *      \class  Strategy
 *      \fn     Strategy :: ~Strategy()
 *      \brief  Desctuctor
 *      \param
 */

Strategy :: ~Strategy()
{
    // Destructor
}
