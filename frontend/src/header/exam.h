/**
 *       \file       exam.h
 *
 *       \brief      ExamDetail class for exam detail
 *
 *       \version    0.8
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

#include "inputdetail.h"

/**
 *      \class  ExamDetail
 *      \brief  ExamDetail class for getting examimation information 
 *              from user.
 */

class ExamDetail : public InputDetail
{
    public:
        ExamDetail();
        void ReadRoomDetail();
        void WriteRoomDetail();
        void SetDefaultValue();
        void ExamDetailPage();
        ~ExamDetail();
};

#endif
