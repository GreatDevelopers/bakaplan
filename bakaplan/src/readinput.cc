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
 *      \fn     ReadInput :: ReadClassDetail(string fileName)
 *      \brief  Reading class details
 *      \param  fileName I/P filename for class detail
 */

void ReadInput :: ReadClassDetail(string projectID)
{
    temp = FileName(CLASS_DETAIL, projectID, 1);

    inFile.open(temp.c_str());

    inFile >> totalClasses;
    
    className.resize(totalClasses);
    totalSubjects.resize(totalClasses);
    subjectCode.resize(totalClasses);
    subjectName.resize(totalClasses);
    
    getline(inFile, temp, '\n');    // For stroring emtpy space
    for(i = 0; i < totalClasses; i++)
    {
        getline(inFile, className[i], '\n');
        inFile >> totalSubjects[i];
//        cout << totalSubjects[i] << endl;
        for(j = 0; j < totalSubjects[i]; j++)
        {
            subjectCode[i].resize(totalSubjects[i]);
            subjectName[i].resize(totalSubjects[i]);
        }
        getline(inFile, temp, '\n');
        for(j = 0; j < totalSubjects[i]; j++)
        {
            getline(inFile, subjectCode[i][j], '\n');
            getline(inFile, subjectName[i][j], '\n');
  //          cout << subjectCode[i][j] << " " 
    //             << subjectName[i][j] << " ";
        }
//        cout << endl;
    }

    inFile.close();
}

/**
 *      \class  ReadInput
 *      \fn     ReadInput :: ReadDateSheet(string fileName)
 *      \brief  Reading datesheet
 *      \param  fileName Name of I/P file
 */

void ReadInput :: ReadDateSheet(string projectID)
{
    temp = FileName(DATESHEET, projectID, 1);

    inFile.open(temp.c_str());
    
    inFile >> totalDays;
//    cout << totalDays;
 
    date.resize(totalDays);
    totalExams.resize(totalDays);
    examCode.resize(totalDays);
     
    getline(inFile, temp, '\n');
    for(i = 0; i < totalDays; i++)
    {
        getline(inFile, date[i], '\n');
        inFile >> totalExams[i];

        getline(inFile, temp, '\n');
        for(j = 0; j < totalExams[i]; j++)
        {
            examCode[i].resize(totalExams[i]);
        }
        
        for(j = 0; j < totalExams[i]; j++)
        {
            getline(inFile, examCode[i][j], '\n');
//            cout << examCode[i][j] << " " ;
        }
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
