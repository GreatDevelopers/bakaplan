/*
 * ===================================================================
 *
 *       Filename:  rollnodetail.cc
 *
 *    Description:  Definition of RollNoDetail's member functions.
 *
 *        Version:  0.6
 *        Created:  Saturday 16 February 2013 11:17:41  IST
 *       Compiler:  gcc
 *
 *         Author:  Mandeep Kaur, meghasimak@gmail.com
 *        License:  GNU General Public License
 *      Copyright:  Copyright (c) 2013, Great Developers
 *
 * ===================================================================
 */

/**-------------------------------------------------------------------
 *  Include rollnodetails.h for RollNoDetail class declaration
 *------------------------------------------------------------------*/

#include "rollnodetail.h"

/**-------------------------------------------------------------------
 *  Definition of functions RollNoDetail Class
 *------------------------------------------------------------------*/

/**
 *--------------------------------------------------------------------
 *       Class:  RollNoDetail
 *      Method:  RollNoDetail :: RollNoDetail()
 * Description:  Constructor
 *--------------------------------------------------------------------
 */

RollNoDetail :: RollNoDetail()
{
    tableHeading[0] = "Class Name";
    tableHeading[1] = "Subject Code";
    tableHeading[2] = "Prefix";
    tableHeading[3] = "Start Roll No";
    tableHeading[4] = "End Roll No";
    tableHeading[5] = "Not Included";
}

/**
 *--------------------------------------------------------------------
 *       Class:  RollNoDetail
 *      Method:  RollNoDetail :: ReadClassDetails()
 * Description:  For reading class details from previous page
 *--------------------------------------------------------------------
 */

void RollNoDetail :: ReadClassDetail()
{

    projectID = readField.ReadFieldValue(fieldName.projectID);
    
    string where = "ProjectID = ";
    where += projectID;
    database.SelectQuery("TotalClasses", "TotalClasses", temp, where); 
    
    totalClasses = StringToInt(temp);

    for(i = 0; i < totalClasses; i++)
    {
        j = i + 1;
        
        className[i] = readField.ReadFieldValue(fieldName.className, 
                                                j);

        subName[i] = readField.ReadFieldValue(fieldName.subjectName, 
                                              j);
      
        subCode[i] = readField.ReadFieldValue(fieldName.subjectCode, 
                                              j);
    }
    
    SplitSubject();

    for(i = 0; i < totalClasses; i++)
    {
        database.InsertClassDetail(projectID, className[i], 
                                   IntToString(totalSubjects[i]), 
                                   subName[i], subCode[i]);
    }
    
}

/**
 *--------------------------------------------------------------------\n
 *       Class:  RollNoDetail \n
 *      Method:  RollNoDetail :: SplitSubject() \n
 * Description:  Split subjects \n
 *--------------------------------------------------------------------
 */

void RollNoDetail :: SplitSubject()
{
    //totalClasses = 1;
    for(i = 0; i < totalClasses; i++)
    {
        int size = subName[i].size() + 1;
        char largchar[size];
        j = 0; 
        strcpy(largchar, subName[i].c_str());
        char* chars_array = strtok(largchar, ",");
        while(chars_array)
        {
            subjectName[i][j] =  chars_array;
            chars_array = strtok(NULL, ",");
            j++;
            totalSubjects[i] = j;
        }
    }

    for(i = 0; i < totalClasses; i++)
    {
        int size = subCode[i].size() + 1;
        char largchar[size];
        j = 0; 
        strcpy(largchar, subCode[i].c_str());
        char* chars_array = strtok(largchar, ",");
        while(chars_array)
        {
            if(j <= totalSubjects[i])
                subjectCode[i][j] =  chars_array;
            chars_array = strtok(NULL, ",");
            j++;
        }
    }
}

/**
 *--------------------------------------------------------------------\n
 *       Class:  RollNoDetail \n
 *      Method:  RollNoDetail :: RollNoDetailPage() \n
 * Description:   \n
 *--------------------------------------------------------------------
 */

void RollNoDetail :: RollNoDetailPage()
{
    //ReadClassDetail();
    ContextType();
    Header("Total Classes");
    
    DivStart("totalclasses", "");               /* (id, classname) */
    ReadClassDetail();
    LogoutLink();
    
    

    for (i = 0; i < totalClasses; i++)
    {
        cout << "Class Name: " << className[i] << brk;
         for (j = 0; j < totalSubjects[i]; j++)
        {
            cout << "subejct Name : " << subjectName[i][j] << brk
                 << "subject code : " << subjectCode[i][j] << brk;
        }
    }

    DivEnd();

    Footer();
 
}
