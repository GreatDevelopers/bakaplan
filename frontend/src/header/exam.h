/**
 *       \file       exam.h
 *
 *       \brief      ExamDetail class for exam detail
 *
 *       \version    0.6
 *       \date       Sunday 07 April 2013 08:01:53  IST\n
 *       Compiler    g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

#ifndef EXAM_H
#define EXAM_H

/**
 *  Include inputdetail.h 
 */
#include "inputdetail.h"

/**
 *      \class  ExamDetail
 *      \brief  ExamDetail class for getting exam from user
 */

class ExamDetail : public InputDetail
{
    protected:

    public:
        /** Constroctor  */
        ExamDetail();

        /** Reading room detail */
        void ReadRoomDetail();

        /** Writing room details into database */
        void WriteRoomDetail();

        /** Setting default values */
        void SetDefaultValue();

        /** Exam Detail Page */
        void ExamDetailPage();

        /** Destructor */
        ~ExamDetail();
};

#endif
