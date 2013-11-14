/**
 *       \file       project-detail.h
 *
 *       \brief      Reading project detail from browser and saving
 *                   into database. \n
 *
 *       \compiler   g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com \n
 *       \license    GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

#ifndef  PROJECT_DETAIL_H
#define  PROJECT_DETAIL_H

#include "input_detail.h"

/**
 *      \class  ProjectDetail
 *      \brief  Reading Project details from database, browser and
 *              save values in database.
 */

class ProjectDetail : public InputDetail
{
    protected:
        // For project detail
        string projectID,                           
               emailID,                           
               projectName;                     
    public:
        ProjectDetail();

        void ReadProjectDetail();
        void WriteProjectDetail();
        void ProjectDetailPage();

        ~ProjectDetail();
};

#endif

/*
 * Local Variables:
 * tab-width: 4
 * expandtab
 * ex: shiftwidth=4 tabstop=4
 */

