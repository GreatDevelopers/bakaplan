/**
 *       \file       project-mail.cpp
 *
 *       \brief      Main method to call ProjectDetail class function
 *                   for project.html page
 *
 *       \version    0.7
 *       \date       Sunday 07 April 2013 03:41:32  IST\n
 *       Compiler    g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

/**
 *  Include projectdetail.h 
 */
#include "header/project.h"

/** 
 *      \fn     main(void)
 *      \brief  Main function to call functions of ProjectDetail Class
 */

int main(void)
{
    ProjectDetail project;
    project.AuthorizeUser();

    return 0;
}

