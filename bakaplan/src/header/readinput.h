/**
 *       \file       readinput.h
 *
 *       \brief      Declaration of ReadInput class for reading input
 *                   details from file
 *
 *       \version    0.6
 *       \date       Sunday 31 March 2013 02:33:49  IST\n
 *       Compiler    g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

/**
 *  Include local header file 
 */
#include "header.h"

/**
 *      \class  ReadInput
 *      \brief  Class for reading input files ie reading roll no
 *              details, class detail, room detail, etc.
 */
class ReadInput
{
    protected:

        STRING_VEC prefix,                    /**< Prefix of rollno */
                   rollNo,                        /**< rollno range */
                   notIncluded, /**< Rollno ie not for seating plan */

                   className,          /**< Branch/trade/class Name */
                   date;                  /**< Date for examination */

        STRING_2DVEC subjectCode,               /**< Subject Code */
                     subjectName,               /**< Subject Name */
                     examCode;   /**< Examination code/subject code */

        int totalClasses,        /**< Total classes/branches/trades */
            totalDays;                /**< No. of days in datesheet */

        INT_VEC totalSubjects,         /**< Total subejcts of class */
                totalExams;               /**< Total exams on 1 day */

        ifstream inFile;            /**< For reading data from file */
        ofstream outFile;           /**< for writing data into file */

        string fileName,                         /**< I/O file name */
               temp;                         /**< For temporary use */

        int i, j, k, l, m, n;                      /**< for looping */

        string projectID;         /**< Project id of user's project */

    public:
        ReadInput();                            /**< Constructor */
        
        /** Retruning filename w.r.t. to project ID */
        string FileName(string file, string projectID, int fileType);

        /** Reading Roll No details from I/P file */
        void ReadRollNoDetail(string projectID);

        /** Reading Class details from I/P file */
        void ReadClassDetail(string projectID);

        /** Reading Datesheet */
        void ReadDateSheet(string projectID);
        
        ~ReadInput();                           /**< Desrtuctor */
};
