/**
 *       \file       inputfile.h
 *
 *       \brief      For creating input files like i/p roll nos, class
 *                   details, room detail, etc by reading data from
 *                   databse.
 *
 *       \version    0.6
 *       \date       Monday 18 March 2013 02:21:37  IST\n
 *       Compiler    gcc
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

/**
 *  Include inputdetail.h file
 */

#include "inputdetail.h"

/**
 *      \class  InputFile
 *      \brief  For creating input files from database
 */

class InputFile
{
    protected:

        InputDetail input;
        ofstream outfile;

        string pID,                      /**< starting of file name */
               fileName,            /**< file name for opening file */
               inputFileName[MIN_SIZE];             /**< File names */

        int i, j, k;                         /**< looping variables */

        int totalClasses, totalCentres, totalRooms;
        vector<int> totalSubjects;

        vector<string> temp,                /**< Temporary variable */
                       className,                  /**< Class Names */
                       subjectCode,               /**< Subejct Code */
                       subjectName;               /**< subject Name */

    public:
        /** Constructor*/
        InputFile();

        /** For creating input files */
        void Input(string projectID);

        /** create RollNo detail file */
        void RollNoDetail(string projectID);

        /** create Class detail file */
        void ClassDetail(string projectID);

        /** create roomdetail I/P file */
        void RoomDetail(string projectID);

        /** create strategy file */
        void Strategy(string projectID);

        /** Destructor */
        ~InputFile();
};

