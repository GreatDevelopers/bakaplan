/**
 *       \file       rollno.cc
 *
 *       \brief      RollNo detail Class definition
 *
 *       \version    0.6
 *       \date       Sunday 07 April 2013 07:53:57  IST\n
 *       Compiler    g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

/**
 *  include rollno.h 
 */
#include "header/rollno.h"

/**
 *      \class  RollNoDetail
 *      \fn     RollNoDetail :: RollNoDetail()
 *      \brief  Constructor
 */

RollNoDetail :: RollNoDetail()
{
    // constructor
}

/**
 *      \class  RollNoDetail
 *      \fn     RollNoDetail :: ReadClassDetail()
 *      \brief  Reading class details from previous page and store
 *              them into database
 */

void RollNoDetail :: ReadClassDetail()
{

    page.ContentType();

    projectID = readField.ReadFieldValue(fieldName.projectID);
    projectType = readField.ReadFieldValue(fieldName.projectType);
    totalClasses = StringToInt(readField.ReadFieldValue(
                               fieldName.totalClasses));

     className.resize(totalClasses);
    subjectName.resize(totalClasses);
    subjectCode.resize(totalClasses);

     for(i = 0; i < totalClasses; i++)
    {
        j = i + 1;
        className[i] = readField.ReadFieldValue(fieldName.className,
                                                j);

        subjectName[i] = readField.ReadFieldValue(
                         fieldName.subjectName, j);
        
        subjectCode[i] = readField.ReadFieldValue(
                         fieldName.subjectCode, j);
    }
 
    if(projectType == "Old")
    {
        where = "ProjectID = " + projectID;
        database.SelectColumn(vecTemp, "ClassName", "ClassDetail",
                              where);
/*       for(unsigned i = 0; i < vecTemp.size(); i++)
            cout << vecTemp[i]; 
*/

        if(vecTemp.size() > 0 )
        {
//            database.SelectSum
            where = "ProjectID = " + projectID;
            database.DeleteQuery("ClassDetail", where);
        }
            
    }
    
    {
        WriteClassDetail();
    }

}

/**
 *      \class  RollNoDetail
 *      \fn     RollNoDetail :: WriteClassDetail()
 *      \brief  Write class details into database
 */

void RollNoDetail :: WriteClassDetail()
{
    for(i = 0; i < totalClasses; i++)
    {
        database.InsertClassDetail(projectID, className[i], 
                                   subjectName[i], subjectCode[i]);
    }
}

/**
 *      \class  RollNoDetail
 *      \fn     RollNoDetail :: RollNoDetailPage(string msg)
 *      \brief  RollNo detail page for taking i/p from user
 *      \param  msg For displaying error msg if any
 */

void RollNoDetail :: RollNoDetailPage(string msg)
{

}

/**
 *      \class  RollNoDetail
 *      \fn     RollNoDetail :: ~RollNoDetail()
 *      \brief  Destructor
 */

RollNoDetail :: ~RollNoDetail()
{
    // destructor
}
