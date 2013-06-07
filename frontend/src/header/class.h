/**
 *       \file       class.h
 *
 *       \brief      ClassDetail Class declaration for displaying form
 *                   for taking values from user. Input details like
 *                   class/branch name, subject code and subject
 *                   names.
 *
 *       \version    0.7
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

#include "project.h"

/**
 *      \class  ClassDetail
 *      \brief  For getting class details and reading project detail
 *              filled by user.
 */

class ClassDetail : public InputDetail
{
    protected:
        ProjectDetail project;
        STRING_VEC value;

    public:
        ClassDetail();
        void SetDefaultValue();
        void ProjectType();
        void OldProject();
        void NewProject();
        void ClassDetailPage(string msg = "");
        ~ClassDetail();
};

#endif
