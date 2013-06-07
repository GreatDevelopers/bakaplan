/**
 *       \file       arrangerollno.h
 *
 *       \brief      ArrangeRollNo class for arranging roll no,
 *                   sorting, and removing roll nos that are not 
 *                   required for seating plan
 *
 *       \version    0.7
 *       \date       Sunday 31 March 2013 06:33:39  IST\n
 *       Compiler    g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

/**
 *  Include expandrollno.h file 
 */
#include "expandrollno.h"

/**
 *      \class  ArrangeRollNo
 *      \brief  Arrange roll no class for sorting, removing redundant
 *              roll nos and also excludeing roll nos that are not 
 *              for seating plan
 */

class ArrangeRollNo : public ReadInput
{
    protected:

        INT_VEC rollNo,                       /**< Reading roll nos */
                notIncludedRNo,               /**< stroring rollnos 
                                              that are not included */
                rollNoSize,
                notIncludedRNoSize;

        STRING_VEC prefix;                      /**< Storing prefix of 
                                                roll nos */

        STRING_2DVEC prefixRollNo;         /**< Roll no with prefix */

        ExpandRollNo expandRNo;   /**< Object of ExpandRollNo class */

    public:


        /** Constructor */
        ArrangeRollNo();
        
        /** Sorting Roll nos */
        void SortRollNo(INT_VEC & rollno);

        /** Removing redundancy from roll nos*/
        void RemoveRedundancy(INT_VEC & rollno);

        /** Removing non eligible roll nos */
        void RemoveNonEligibleRollNo(INT_VEC & rollno, 
                                     INT_VEC & notIncludedRNo);

        /** Adding prefix with roll nos */
        void AddPrefixWithRollNo(INT_VEC & rollno, STRING_VEC & prefix);

        /** Writing arranged roll no's into file  */
        void WriteArrangedRollNo();

        /** Main method to call all function in order/sequence  */
        void Main(string pID);

        /** Desrtuctor */
        ~ArrangeRollNo();
};
