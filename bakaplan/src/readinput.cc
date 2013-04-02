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
 *      \fn     ReadInput :: ReadDateSheetOut(string projectID)
 *      \brief  Reading datesheet.out file 
 *      \param  projectID ProjectID
 */

void ReadInput :: ReadDateSheetOut(string projectID)
{
    temp = FileName(DATESHEET, projectID, 0);

    inFile.open(temp.c_str());

    inFile >> totalDays;
    
    // Resizing variables size for reading datesheet detail

    date.resize(totalDays);
    totalExams.resize(totalDays);
    examSubCode.resize(totalDays);
    examSubName.resize(totalDays);
    dateSheetRNoSize.resize(totalDays);
    dateSheetRNo.resize(totalDays);

    getline(inFile, temp, '\n');
    for(i = 0; i < totalDays; i++)
    {
        getline(inFile, date[i], '\n');
        inFile >> totalExams[i];

        getline(inFile, temp, '\n');
        
        for(j = 0; j < totalExams[i]; j++)
        {
            examSubCode[i].resize(totalExams[i]);
            examSubName[i].resize(totalExams[i]);
            dateSheetRNoSize[i].resize(totalExams[i]);
            dateSheetRNo[i].resize(totalExams[i]);
        }
        
        for(j = 0; j < totalExams[i]; j++)
        {
            getline(inFile, examSubCode[i][j], '\n');
            getline(inFile, examSubName[i][j], '\n');

            inFile >> dateSheetRNoSize[i][j];

            getline(inFile, temp, '\n');

            for(k = 0; k < dateSheetRNoSize[i][j]; k++)
            {
                dateSheetRNo[i][j].resize(dateSheetRNoSize[i][j]);
            }

            for(k = 0; k < dateSheetRNoSize[i][j]; k++)
            {
                getline(inFile, dateSheetRNo[i][j][k], '\n');
//                cout << dateSheetRNo[i][j][k] << " ";
            }
  //          cout << "\n ====\n ";
        }
    }

    inFile.close();
}

/**
 *      \class  ReadInput
 *      \fn     ReadInput :: ReadRoomDetail(string projectID)
 *      \brief  Reading room details
 *      \param  projectID projectId of user's project
 */

void ReadInput :: ReadRoomDetail(string projectID)
{
    temp = FileName(ROOM_DETAIL, projectID, 1);

    inFile.open(temp.c_str());
    
    int t;
    
    inFile >> t;
    
    totalCentres.resize(t);
    centreName.resize(t);
    totalRooms.resize(t);
    roomNo.resize(t);
    rows.resize(t);
    cols.resize(t);

    for(i = 0; i < t; i++)
    {
        inFile >> totalCentres[i];
    
        // Resizing vector array
        for(j = 0; j < totalCentres[i]; j++)
        {
            centreName[i].resize(totalCentres[i]);
            totalRooms[i].resize(totalCentres[i]);
            roomNo[i].resize(totalCentres[i]);
            rows[i].resize(totalCentres[i]);
            cols[i].resize(totalCentres[i]);
        }

        getline(inFile, temp, '\n');
        for(j = 0; j < totalCentres[i]; j++)
        {
            getline(inFile, centreName[i][j], '\n');
    
            inFile >> totalRooms[i][j];
    
            for(k = 0; k < totalRooms[i][j]; k++)
            {
                roomNo[i][j].resize(totalRooms[i][j]);
                rows[i][j].resize(totalRooms[i][j]);
                cols[i][j].resize(totalRooms[i][j]);
            }
         
            getline(inFile, temp, '\n');
            for(k = 0; k < totalRooms[i][j]; k++)
            {
                getline(inFile, roomNo[i][j][k], '\n');

                inFile >> rows[i][j][k] >> cols[i][j][k];

                getline(inFile, temp, '\n');
            }
        }
    }

    inFile.close();
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
    examSubCode.resize(totalDays);
     
    getline(inFile, temp, '\n');
    for(i = 0; i < totalDays; i++)
    {
        getline(inFile, date[i], '\n');
        inFile >> totalExams[i];

        getline(inFile, temp, '\n');
        for(j = 0; j < totalExams[i]; j++)
        {
            examSubCode[i].resize(totalExams[i]);
        }
        
        for(j = 0; j < totalExams[i]; j++)
        {
            getline(inFile, examSubCode[i][j], '\n');
//            cout << examCode[i][j] << " " ;
        }
    }

    inFile.close();
   
}

/**
 *      \class  ReadInput
 *      \fn     ReadInput :: ReadStrategy(string projectID)
 *      \brief  Function for reading strategy
 *      \param  projectID projectId of user's project
 */

void ReadInput :: ReadStrategy(string projectID)
{
    temp = FileName(STRATEGY, projectID, 1);

    inFile.open(temp.c_str());
    int t;
    inFile >> t;
    
    strategyOption.resize(t);
    getline(inFile, temp, '\n');
    
    for(i = 0; i < t; i++)
        getline(inFile, strategyOption[i], '\n');

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
