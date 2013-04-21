/**
 *       \file       expandrollno.cc
 *
 *       \brief      Function definition of ExpandRollNo class
 *                   defintion
 *
 *       \version    0.6
 *       \date       Sunday 31 March 2013 06:49:23  IST\n
 *       Compiler    g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

/**
 *  include expandrollno.h 
 */
#include "header/expandrollno.h"

ExpandRollNo :: ExpandRollNo()
{
    // constructor
}

/**
 *      \class  ExpandRollNo
 *      \fn     ExpandRollNo :: ExpandRollNos(string projectID)
 *      \brief  Expanding Roll nos
 *      \param  projectID Project ID of user's project
 */

void ExpandRollNo :: ExpandRollNos(string projectID)
{
    ReadRollNoDetail(projectID);
    temp = FileName(TEMP, projectID, 0);
   
    outFile.open(temp.c_str()); // expand rollno
   
    rollNoSize.resize(totalClasses);
    notIncludedRNoSize.resize(totalClasses);

    // expanding roll nos
    for(i = 0; i < totalClasses; i++)
    {
        istringstream rollno(rollNo[i]);
        deque<int> v;
         
        bool success = ExpandRollNoList(rollno, back_inserter(v));
         
        if (success)
        {
            rollNoSize[i] = v.size();//-1;
            copy(v.begin(), v.end()-1, ostream_iterator<int>(outFile, " "));
   
            outFile << v.back() << endl;
        }
        else
            outFile << "an error occured." << endl;
            
        // expanding not included roll nos
        if(notIncluded[i] != " ")
        {
            istringstream rollno(notIncluded[i]);
            deque<int> v;
            
            bool success = ExpandRollNoList(rollno, back_inserter(v));
            
            if (success)
            {
                notIncludedRNoSize[i] = v.size();//-1;
                copy(v.begin(), v.end()-1, ostream_iterator<int>(outFile, " "));
      
                outFile << v.back() << endl;
            }
            else
                outFile << "an error occured." << endl;
        }
    }
    outFile.close();
    
    WriteExpandRollNo(projectID);
}

/**
 *      \class  ExpandRollNo
 *      \fn     ExpandRollNo :: ExpandRollNoList(istream& is, 
 *              OutIter out)
 *      \brief  Templete for expanding roll nos
 */

template<typename OutIter>
bool ExpandRollNo :: ExpandRollNoList(istream& is, OutIter out)
{
    int number;
    // the list always has to start with a number
    while (is >> number)
    {
        *out++ = number;

        char c;
        if (is >> c)
            switch(c)
            {
                case ',':
                    continue;
                case '-':
                {
                    int number2;
                    if (is >> number2)
                    {
                        if (number2 < number)
                            return false;
                        while (number < number2)
                            *out++ = ++number;
                        char c2;
                        
                        if (is >> c2)
                            if (c2 == ',')
                                continue;
                            else
                                return false;
                        else
                            return is.eof();
                    }
                    else
                        return false;
                }
                
                default:
                    return is.eof();
            }
        else
            return is.eof();
    }
    // if we get here, something went wrong (otherwise we would have
    // returned from inside the loop)
    return false;
}

/**
 *      \class  ExpandRollNo
 *      \fn     ExpandRollNo :: WriteExpandRollNo(string projectID)
 *      \brief  Write expanded roll nos into file
 *      \param  projectID Project ID of user's project
 */

void ExpandRollNo :: WriteExpandRollNo(string projectID)
{
    temp = FileName(TEMP, projectID, 0);

    inFile.open(temp.c_str());
    outFile.open((FileName(EXPAND_ROLLNO, projectID, 0)).c_str());

    outFile << totalClasses << endl;

    for(i = 0; i < totalClasses; i++)
    {
        outFile << prefix[i] << endl;

        rollNo.resize(rollNoSize[i]);

        outFile << rollNoSize[i] << endl;

        for(j = 0; j < rollNoSize[i]; j++)
        {
            inFile >> rollNo[j];
            outFile << rollNo[j] << " ";
        }
        outFile << endl;

        notIncluded.resize(notIncludedRNoSize[i]);

        outFile << notIncludedRNoSize[i] << endl;

        for(j = 0; j < notIncludedRNoSize[i]; j++)
        {
            inFile >> notIncluded[j];
            outFile << notIncluded[j] << " ";
        }
        outFile << endl;
    }

    inFile.close();
    outFile.close();
}

/**
 *      \class  ExpandRollNo
 *      \fn     ExpandRollNo :: ~ExpandRollNo()
 *      \brief  Destructor
 */

ExpandRollNo :: ~ExpandRollNo()
{
    // destructor
}
