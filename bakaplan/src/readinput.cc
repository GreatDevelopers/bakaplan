/**
 *       \file       readinput.cc
 *
 *       \brief      Function Definition of ReadInput Class
 *
 *       \version    0.6
 *       \date       Sunday 31 March 2013 06:48:51  IST\n
 *       Compiler    g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

/**
 *  Include readinput.h file 
 */
#include "header/readinput.h"

/**
 *      \class  ReadInput
 *      \fn     ReadInput :: ReadInput()
 *      \brief  Constructor
 */

ReadInput :: ReadInput()
{
    // constructor
}

/**
 *      \class  ReadInput
 *      \fn     ReadInput :: FileName(string projectID, string file,
 *                                    string io)
 *      \brief  For creating filename w.r.t to projectID
 *
 *      \param  projectID Unique ID i.e. used to read file of user
 *      \param  file I/O file Name
 *      \param  fileType For defining file type i.e I/P or O/P file.
 *              If fileType == 1, Input file
 *              If fileType == 0(else), Output File
 *
 *      \return fileName This function will return file name with
 *              project ID
 */

string ReadInput :: FileName(string file, string projectID, 
                             int fileType)
{
    temp = file + projectID;

    if(fileType == 1)
        fileName = INPUT + temp + IN;
    else
        fileName = OUTPUT + temp + OUT;

    return fileName;
}

/**
 *      \class  ReadInput
 *      \fn     ReadInput :: ReadRollNoDetail(string fileName)
 *      \brief  Reading Roll No detail from file
 *      \param  projectID Name of I/P file for roll nos.
 */

void ReadInput :: ReadRollNoDetail(string projectID)
{
    temp = FileName(ROLLNO_DETAIL, projectID, 1);

    inFile.open(temp.c_str());

    inFile >> totalClasses;
    
    // Resizing vector's size
    prefix.resize(totalClasses);
    rollNo.resize(totalClasses);
    notIncluded.resize(totalClasses);

    getline(inFile, temp, '\n');

    for(i = 0; i < totalClasses; i++)
    {
        getline(inFile, prefix[i], '\n');
        getline(inFile, rollNo[i], '\n');
        getline(inFile, notIncluded[i], '\n');
    }

    inFile.close();
}

/**
 *      \class  ReadInput
 *      \fn     ReadInput :: ~ReadInput()
 *      \brief  Destructor
 */

ReadInput :: ~ReadInput()
{
    // destructor
}
