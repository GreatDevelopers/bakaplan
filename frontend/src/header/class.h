/**
 *       \file       class.h
 *
 *       \brief      ClassDetail Class declaration
 *
 *       \version    0.6
 *       \date       Sunday 07 April 2013 07:45:59  IST\n
 *       Compiler    g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

#ifndef CLASS_H
#define CLASS_H

/**
 *  Include project.h 
 */

#include "project.h"

/**
 *      \class  ClassDetail
 *      \brief  For getting class details nd reading projectdetail
 */

class ClassDetail : public InputDetail
{
    protected:
        ProjectDetail project;

    public:
        /** Constructor */
        ClassDetail();

        void SetDefaultValue();

        /** Type of project */
        void ProjectType();

        /** Existing project */
        void OldProject();

        /** New project */
        void NewProject();

        /** Class detail page */
        void ClassDetailPage(string msg = "");

        /** DEstructor */
        ~ClassDetail();
};

#endif
