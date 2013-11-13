/**
 *       \file       bakaplan.cc
 *
 *       \brief      Main Class for calling all pages and executing
 *                   functions accoding to it flow \n
 *
 *       \compiler   g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com \n
 *       \license    GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

#include "header/bakaplan.h"

/**
 *      \fn     BaKaPlan :: BaKaPlan()
 *      \brief  constructor
 */
BaKaPlan :: BaKaPlan()
{
    // constructor
}

/**
 *      \fn     BaKaPlan :: Main(int)
 *      \brief  Main Program
 *      \param  step Step to identify part of work flow
 */
void BaKaPlan :: Main(int step)
{
    switch(step)
    {
        case 0:
            project.ProjectDetailPage();
            break;

        default:
            project.ProjectDetailPage();
    }
}

/**
 *      \fn     BaKaPlan :: ~BaKaPlan()
 *      \brief  Desrtuctor 
 *      \param
 */
BaKaPlan :: ~BaKaPlan()
{
    // destructor
}

/*
 * Local Variables:
 * tab-width: 4
 * expandtab
 * ex: shiftwidth=4 tabstop=4
 */

