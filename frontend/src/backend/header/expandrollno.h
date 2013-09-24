/**
 *       \file       expandrollno.h
 *
 *       \brief      ExpandRollNo class declaration for expanding roll
 *                   nos.
 *
 *       \version    0.8
 *       \date       Sunday 31 March 2013 05:45:55  IST\n
 *       Compiler    g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

/**
 *  Include readinput.h  
 */
#include "readinput.h"

/**
 *      \class  ExapandRollNo
 *      \brief  Class for expanding roll nos.
 */

class ExpandRollNo : public ReadInput
{
    protected:

        INT_VEC rollNoSize, notIncludedRNoSize;

    public:

        /** Constructor */
        ExpandRollNo();
        
        /** Template for expanding roll no */
        template<typename OutIter>
        bool ExpandRollNoList(istream& is, OutIter out);
        
        /** For expanding roll no and calling ExpandRollNoList
         * templete */
        void ExpandRollNos(string projectID);

        /** Write expanded roll no's in file */
        void WriteExpandRollNo(string projectID);

        /** Destructor */
        ~ExpandRollNo();
};
