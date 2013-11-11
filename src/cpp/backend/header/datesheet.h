/**
 *       \file       datesheet.h
 *
 *       \brief      Datesheet class definition
 *
 *       \version    0.8
 *       \date       Sunday 31 March 2013 09:38:54  IST\n
 *       Compiler    g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

/**
 *  Include arrangerollno.h header file 
 */
#include "arrangerollno.h"

/**
 *      \class  DateSheet
 *      \brief  DateSheet class for reading datesheet detail, class
 *              detail and create datesheet.out file for seating plan
 */

class DateSheet : public ArrangeRollNo
{
    protected:
    
    public:
        /** Constructor */
        DateSheet();
        
        /** Adding roll nos with date sheet */
        void AddRollNoWithDateSheet();

        /** Writing datesheet.out file i.e. used for seating plan */
        void WriteDateSheet(string projectID);

        /** Main function to call other functions */
        void Main(string pID);

        /** Desructor */
        ~DateSheet();
};
