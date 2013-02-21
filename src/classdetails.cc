/*
 * ===================================================================
 *
 *       Filename:  classdetails.cc
 *
 *    Description:  Definition of ClassDetails's member functions.
 *
 *        Version:  0.6
 *        Created:  Saturday 16 February 2013 11:15:42  IST
 *       Compiler:  gcc
 *
 *         Author:  Mandeep Kaur, meghasimak@gmail.com
 *        License:  GNU General Public License
 *      Copyright:  Copyright (c) 2013, Great Developers
 *
 * ===================================================================
 */

/**-------------------------------------------------------------------
 *  Incude header file which has ClassDetails's declaration
 *------------------------------------------------------------------*/

#include "classdetails.h"

/**-------------------------------------------------------------------
 *  Defnition of member functions
 *------------------------------------------------------------------*/

/**
 *--------------------------------------------------------------------
 *       Class:  ClassDetails
 *      Method:  ClassDetails :: ClassDetails()
 * Description:  Constructor
 *--------------------------------------------------------------------
 */

ClassDetails :: ClassDetails()
{
    //maxClasses      =   10;

/*     className[maxClasses] = {"Info. Tech.", "10th", "ECE", 
                              "Mech. Engg.", "Production Engg.", 
                              "Electrical Engg.", "IT", 
                              "Electronics Engg.", "Comp. Sci. Engg.", 
                              "MBA"};
    
    subjectName[maxClasses] = {"DBMS, SAD", "Maths,Physics", 
                                "OS, EVS", "Java, C++", "EVS", 
                                "Chem.", "ED", "Maths", 
                                "Maths,DBMS, Physics", 
                                "Multimedia, Dot Net, ED"};
    
    subjectCode[maxClasses] = {"IT-101, IT-102", "ME-10,CE-252", 
                                "EVS, ED-10", "ED-10, IT-102", 
                                "IT-102", "IT-203", "CE-120",
                                "ME-140", "EE-109, 1234S, IT-203", 
                                "ME-101,ME-501,IT-101" };

    tableHeading[4] = {"Class Name", "Total Subjects", "Subject Name",
                       "Subject Code"};
*/
}

/**
 *--------------------------------------------------------------------
 *       Class:  ClassDetails
 *      Method:  ClassDetails :: Header()
 * Description:  Includes menu, logo, header of page
 *--------------------------------------------------------------------
 */

void ClassDetails :: Header()
{
    HTMLStart();
    Head("Class Details");
    PageLayout :: Header();
    BodyStart();
    Logo("BaKaPlan");
}

/**
 *--------------------------------------------------------------------
 *       Class:  ClassDetails
 *      Method:  ClassDetails :: Footer()
 * Description:  Footer of page
 *--------------------------------------------------------------------
 */

void ClassDetails :: Footer()
{
    BodyEnd();
    HTMLEnd();
}

/**
 *--------------------------------------------------------------------
 *       Class:  ClassDetails
 *      Method:  ClassDetails :: TotalClasses()
 * Description:  Get Total classes from user
 *--------------------------------------------------------------------
 */

void ClassDetails :: TotalClasses()
{
    Header();
    
    DivStart("totalclasses", "");               /* (id, classname) */
    FormStart("totalclasses", "classinfo.html", "POST");

    cout << startH1 << " Select Total Classes " << endH1 << brk;
    
    cout << " Total Branches ";
    SelectFieldStart(fieldName.totalClasses);
    
    for(i = 1; i <= maxClasses; i++)
    {
        stringstream ss;
        ss << i;
        if(i == 5)
            SelectOptionStart(ss.str(), "Y");
        else
            SelectOptionStart(ss.str(), "n");
        cout << i;
        SelectOptionEnd();
    }

    SelectFieldEnd();

    cout << brk << brk;

    Button("next", "submit", "btn", "NEXT");

    FormEnd();
    DivEnd();

    Footer();
}

/**
 *--------------------------------------------------------------------
 *       Class:  ClassDetails
 *      Method:  ClassDetails :: ClassInfo()
 * Description:  Get class name, subject code and subject name from
 * user.
 *--------------------------------------------------------------------
 */

void ClassDetails :: ClassInfo()
{
    temp = readField.ReadFieldValue(fieldName.totalClasses); 
    totalClasses = readField.StringToInt(temp);
    
    Header();

    DivStart("classinfo", "");                  /* (id, classname) */
    FormStart("classinfo", "rollnodetails.html", "POST");
    
    cout << startH1 << "Enter Branch Details" << endH1 << brk;
    TableStart("classdetails", "");
    
    cout << startTR;
    for(i = 0; i < 4; i++)
    {
        cout << startTH << tableHeading[i] << endTH;
    }
    cout << endTR;

    for(i = 0; i < totalClasses; i++)
    {
        cout << startTR;
        
        cout << startTD;
        InputField("text", fieldName.className, (i+1), className[i]);
        cout << endTD;
        
        cout << startTD;
        SelectFieldStart(fieldName.totalSubjects);
        for(j = 1; j <= 3; j++)
        {
            stringstream ss;
            ss << j;
            
            if(i >= 0 && i <= 3 && j == 2)
                SelectOptionStart(ss.str(), "y");  
            if(i >= 4 && i <= 7 && j == 1)
                SelectOptionStart(ss.str(), "y");  
            if(i == 8 || i == 9 && j == 3)
                SelectOptionStart(ss.str(), "y");  
            
            cout << j;
            SelectOptionEnd();
        }
        SelectFieldEnd();
        cout << endTD;
        
        cout << startTD;
        InputField("text", fieldName.subjectName, (i+1), subjectName[i]);
        cout << endTD;
        
        cout << startTD;
        InputField("text", fieldName.subjectCode, (i+1), subjectCode[i]);
        cout << endTD;

        cout << endTR;
    }
    
    TableEnd();
    
    cout << brk << brk;                                                                         
    Button("next", "submit", "btn", "NEXT");

    FormEnd();
    DivEnd();

    Footer();
}
