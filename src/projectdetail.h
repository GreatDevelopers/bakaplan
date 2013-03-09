/*
 * ===================================================================
 *
 *       Filename:  projectdetail.h
 *
 *    Description:  ProjectDetail class definition for getting project
 *                  name and project ID
 *
 *        Version:  0.6
 *        Created:  Friday 01 March 2013 02:25:42  IST
 *       Compiler:  gcc
 *
 *         Author:  Mandeep Kaur, meghasimak@gmail.com
 *        License:  GNU General Public License
 *      Copyright:  Copyright (c) 2013, GreatDevelopers
 *                  https://github.com/GreatDevelopers
 *
 * ===================================================================
 */

/**-------------------------------------------------------------------
 *  Include login.h header files
 *------------------------------------------------------------------*/

#include "login.h"

/**
 * ===================================================================
 *        Class:  ProjectDetail
 *  Description:  For getting project name and giving unique project
 *                ID.
 * ===================================================================
 */

class ProjectDetail : public Login
{
    protected:
        

    public:
        /** ProjectDetail Consructor */
        ProjectDetail();

        /** Display Page for project details */
        void ProjectDetailPage();

        /** Checking user login details valid or not */
        void AuthorizeUser();

        /** Destructor */
        ~ProjectDetail();
};
