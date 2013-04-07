/**
 *       \file       projectdetail.h
 *
 *       \brief      ProjectDetail class declaration for creating new
 *                   project for seating plan or using existing 
 *                   project.
 *
 *       \version    0.6
 *       \date       Sunday 07 April 2013 03:24:31  IST\n
 *       Compiler    g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

#ifndef PROJECT_H
#define PROJECT_H

/**
 *  Include login.h 
 */
#include "login.h"

/**
 *      \class  ProjectDetail
 *      \brief  ProjectDetail class for creating new project for user
 */

class ProjectDetail : public Login
{
    protected:
        
        STRING_VEC oldProject;                  /**< For stroring olde 
                                                    projects if any */
    
    public:
        /** ProjectDetail Consructor */
        ProjectDetail();

        /** Display Page for project details */
        void ProjectDetailPage(string msg = "", 
                               string projectName = "Project Name");

        /** Checking user login details valid or not */
        void AuthorizeUser();

        /** Old projects */
        void OldProject();

        /** Home Page */
        void HomePage();

        /** Destructor */
        ~ProjectDetail();
};

#endif
