/**
 *       \file       datesheet-main.cpp
 *
 *       \brief      main method
 *
 *       \version    0.8
 *       \date       Sunday 07 April 2013 09:00:37  IST\n
 *       Compiler    g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

/**
 *  include header file 
 */

#include "header/datesheet.h"


/** 
 *      \fn     main(void)
 *      \brief  Main method for creating.html page
 */

int main(void)
{
    DateSheet dateSheet;
//    dateSheet.ReadRollNoDetail();
    dateSheet.DateSheetPage();    

    return 0;
}
