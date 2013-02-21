/*
 * ===================================================================
 *
 *       Filename:  classdetails.h
 *
 *    Description:  Declaration of ClassDetails class to getting
 *    details like total classes, classname, subjects its code and
 *    name, etc.
 *
 *        Version:  0.6
 *        Created:  Saturday 16 February 2013 11:14:34  IST
 *       Compiler:  gcc
 *
 *         Author:  Mandeep Kaur, meghasimak@gmail.com
 *        License:  GNU General Public License
 *      Copyright:  Copyright (c) 2013, Great Developers
 *
 * ===================================================================
 */

/**-------------------------------------------------------------------
 *  Include Required Header Files
 *------------------------------------------------------------------*/

#include "pagelayout.h"
#include "inputfieldnames.h"
#include "readinputfields.h"

/**-------------------------------------------------------------------
 *  Constant varibles
 *------------------------------------------------------------------*/

const int maxClasses = 10;

/**
 * ===================================================================
 *        Class:  ClassDetails
 *  Description:  This class is used to get details of class from 
 *  user. Like class name, total classes, subject details etc.
 * ===================================================================
 */

class ClassDetails : public PageLayout
{
    protected:
//        const int maxClasses = 15;     /* max. classes for user i/p */
        int totalClasses;              /* storing total classes */
        
        /* string className[maxClasses],           
               subjectCode[maxClasses],
               subjectName[maxClasses],
               tableHeading[maxClasses];*/
        
        string className[maxClasses] = {"Info. Tech.", "10th", 
                                        "ECE", "Mech. Engg.", 
                                        "Production Engg.", 
                                        "Electrical Engg.", "IT",             
                                        "Electronics Engg.", 
                                        "Comp. Sci. Engg.", "MBA"};           

        string subjectName[maxClasses] = {"DBMS, SAD", "Maths,Physics",
                                          "OS, EVS", "Java, C++", "EVS",
                                          "Chem.", "ED", "Maths",       
                                          "Maths,DBMS, Physics",
                                          "Multimedia, Dot Net, ED"};

        string subjectCode[maxClasses] = {"IT-101, IT-102", 
                                          "ME-10,CE-252", "EVS, ED-10", 
                                          "ED-10, IT-102", "IT-102", 
                                          "IT-203", "CE-120", "ME-140", 
                                          "EE-109, 1234S, IT-203",    
                                          "ME-101,ME-501,IT-101" };

        string tableHeading[4] = {"Class Name", "Total Subjects", 
                                  "Subject Name", "Subject Code"};

        InputFieldNames fieldName;     /* For accessing filenames */
        ReadInputFields readField;     /* for reading field name */

        int i, j, k;                   /* for loop variables */

        stringstream ss;            /* for converting int to string */
        string temp;                /* Tempprary Variable */

    public:
        /// Constructor
        ClassDetails();

        /// Get total classes 
        void TotalClasses();

        /// Get class details like class name, subject name and
        /// subject code
        void ClassInfo();

        /// Header of page
        void Header();

        /// Footer of page
        void Footer();
};
