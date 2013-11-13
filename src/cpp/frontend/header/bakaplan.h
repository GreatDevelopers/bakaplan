/**
 *       \file       bakaplan.h
 *
 *       \brief      Main class for calling all other classes \n
 *
 *       \compiler   g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com \n
 *       \license    GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

#ifndef  BAKAPLAN_H
#define  BAKAPLAN_H

#include "header.h"
#include "project_detail.h"

/**
 *      \class  BaKaPlan
 *      \brief  Main Project class
 */
class BaKaPlan : public InputDetail
{
    protected:
        ProjectDetail project;

    public:
        BaKaPlan();

        void Main(int step = 0);

        ~BaKaPlan();
};

#endif

/*
 * Local Variables:
 * tab-width: 4
 * expandtab
 * ex: shiftwidth=4 tabstop=4
 */

