/**
 *       \file       projectdetail.h
 *
 *       \brief      ProjectDetail class declaration for creating new
 *                   project for seating plan or using existing 
 *                   project.
 *
 *       \version    0.8
 *       \date       Sunday 07 April 2013 03:24:31  IST\n
 *       Compiler    g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com\n
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

#ifndef PROJECT_H
#define PROJECT_H

#include "login.h"

/**
 *      \class  ProjectDetail
 *      \brief  ProjectDetail class for creating new project for user
 */

class ProjectDetail : public Login
{
    protected:
        
    public:
        ProjectDetail();
        void ProjectDetailPage(string msg = "", 
                               string projectName = "Project Name");
        void AuthorizeUser();
        void OldProject();
        void HomePage();
        ~ProjectDetail();
};

#endif
