/**
 *       \file       strategy-main.cpp
 *
 *       \brief      For creating object of Strategy class and result
 *                   in strategy.html page
 *
 *       \version    0.6
 *       \date       Sunday 17 March 2013 11:31:59  IST\n
 *       Compiler    gcc
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

/**
 *  Include strategy.h header file 
 */
#include "strategy.h"


/**
 *  Main method for creating object and calling StrategyPage()
 *  function
 */

int main(void)
{
    //InputFile inputFile;
    Strategy strategy;
    strategy.StrategyPage();

    return 0;
}
