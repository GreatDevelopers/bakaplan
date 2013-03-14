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
      string fn = fieldName.className;
    int f = 1;
    fn += IntToString(f);
    className[0] = readField.ReadFieldValue(fn);
    className[2] = readField.ReadFieldValue(fieldName.className, 
                                               (f + 1));
    subName[0] = readField.ReadFieldValue("SubjectName1");
    subCode[0] = readField.ReadFieldValue("SubjectCode1");

   /* 
    for(i = 0; i < totalClasses; i++)
    {
        temp  = fieldName.className;
        temp += IntToString((i+1));

        className[i] = readField.ReadFieldValue(temp);
      
        temp  = fieldName.subjectName;
        temp += IntToString((i+1));  
        
        subName[i] = readField.ReadFieldValue(temp);
      
        temp  = fieldName.subjectCode;
        temp += IntToString((i+1)); 

        subCode[i] = readField.ReadFieldValue(temp);

//        database.InsertClassDetail(projectID, className[i], 
  //                                 subName[i], subCode[i]);
    }
    //className[0] = readField.ReadFieldValue("ClassName1");
    
    SplitSubject();

    for(i = 0; i < totalClasses; i++)
    {
        database.InsertClassDetail(projectID, className[i], 
                                   IntToString(totalSubjects[i]), 
                                   subName[i], subCode[i]);
    }*/

    SplitSubject();
    
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
    totalClasses = 1;
    for(i = 0; i < totalClasses; i++)
    {
        int size = subName[i].size() + 1;
        char largchar[size]; // = roll[i].c_str();//"1-10 12 34 15 20 25-30";
        j = 0; 
        strcpy(largchar, subName[i].c_str());
        char* chars_array = strtok(largchar, ",");
        while(chars_array)
        {
            //if(j < totalSubjects[i])
                subjectName[i][j] =  chars_array;//atoi (chars_array));//n++;
            chars_array = strtok(NULL, ",");
            j++;
            totalSubjects[i] = j;
        }
    }

    for(i = 0; i < totalClasses; i++)
    {
        int size = subCode[i].size() + 1;
        char largchar[size]; // = roll[i].c_str();//"1-10 12 34 15 20 25-30";
        j = 0; 
        strcpy(largchar, subCode[i].c_str());
        char* chars_array = strtok(largchar, ",");
        while(chars_array)
        {
            if(j < totalSubjects[i])
                subjectCode[i][j] =  chars_array;//atoi (chars_array));//n++;
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

/*  
    cout << brk << projectID << brk << className[0] 
         << brk << totalClasses << brk
         << className[2];*/
totalClasses = 1;
//totalSubjects[i] = 1;
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
