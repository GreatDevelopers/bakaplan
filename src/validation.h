/**
 *       \file       validation.h
 *
 *       \brief      Declaration of Validation Class for creating page
 *                   validation.html 
 *
 *       \version    0.6
 *       \date       Wednesday 20 March 2013 04:59:52  IST\n
 *       Compiler    gcc
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

/**
 *  Include inputdetail.h file 
 */
#include "inputdetail.h"
#include "backend/strategy.h"

/**
 *      \class  Validation
 *      \brief  This class is for checking total seats and total
 *              students.
 */

class Validation : public InputDetail
{
    protected:

        string strategyChoice;
        Strategy strategy;

    public:

    /** Constructor */
    Validation();
    
    /** Read Strategy */
    void ReadStrategyDetail();

    /** Write startegy detail */
    void WriteStrategyDetail();

    /** Validation Page */
    void ValidationPage();

    /** Destuctor */
    ~Validation();
};
