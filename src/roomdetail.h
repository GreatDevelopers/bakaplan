/*
 * ===================================================================
 *
 *       Filename:  roomdetails.h
 *
 *    Description:  Declaration of RoomDetail Class for getting
 *                  information about rooms, its rows and columns, 
 *                  also total centres and its names.
 *
 *        Version:  0.6
 *        Created:  Saturday 16 February 2013 11:18:34  IST
 *       Compiler:  gcc
 *
 *         Author:  Mandeep Kaur, meghasimak@gmail.com
 *        License:  GNU General Public License
 *      Copyright:  Copyright (c) 2013, Great Developers
 *
 * ===================================================================
 */

/**-------------------------------------------------------------------\n
 *  Include inputdetail.h file \n
 *------------------------------------------------------------------*/

#include "inputdetail.h"

/**
 * ===================================================================\n
 *        Class:  RoomDetail \n
 *  Description:  For creating roondetail pages and reading
 *                rollnodetail and store then into database\n
 * ===================================================================\n
 */

class RoomDetail : public InputDetail
{
    protected:
    
        // for reading rollno detail
        int totalRollNo;                   /**< Total rollno fields */

        string className[MIN_SIZE],
               subjectCode[MIN_SIZE],
               prefix[MIN_SIZE],
               startRollNo[MIN_SIZE],
               endRollNo[MIN_SIZE],
               notIncluded[MIN_SIZE];
         // for reading totalcentres

         int totalCentre, totalRoom[MIN_SIZE], maxCentres;
         string rows[MIN_SIZE], columns[MIN_SIZE], 
                centreName[MIN_SIZE];

    public:
        /** RoomDetail Constructor */
        RoomDetail();
        
        /** Reading RollNo detail */
        void ReadRollNoDetail();
        
        /** Reading total centres */
        void ReadTotalCentre();

        /** Reading centre details */
        void ReadCentreDetail();

        /** Read room detail */
        void ReadRoomDetail();

        /** Total centre page */
        void TotalCentrePage();

        /** Centre Detail detail */
        void CentreDetailPage();

        /** Room detail */
        void RoomDetailPage();

        /** RoomDetail Destructor */
        ~RoomDetail();
};
