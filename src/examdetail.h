/**
 *       \file       examdetail.h
 *
 *       \brief      Declaration of ExamDetail Class for reading exam
 *                   detail, write into file and save into database.
 *
 *       \version    0.6
 *       \date       Wednesday 20 March 2013 03:35:20  IST\n
 *       Compiler    gcc
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

/**
 *  include inputdetail.h file 
 */
#include "inputdetail.h"

/**
 *      \class  ExamDetail
 *      \brief  Class for getting exam detail from user
 */

class ExamDetail : public InputDetail
{
    protected:


    public:
        /** constructor */
        ExamDetail();

        /** ExamDetail Page */
        void ExamDetailPage();

        /** Destructor */
        ~ExamDetail();

};
