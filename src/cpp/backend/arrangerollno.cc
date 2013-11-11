/**
 *       \file       arrangerollno.cc
 *
 *       \brief      Function definition of ArrangeRollNo class
 *
 *       \version    0.8
 *       \date       Sunday 31 March 2013 06:50:00  IST\n
 *       Compiler    g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

/**
 *   Include arrangerollno.h file
 */
#include "header/arrangerollno.h"

/**
 *      \class  ArrangeRollNo
 *      \fn     ArrangeRollNo :: ArrangeRollNo()
 *      \brief  Constructor
 */

ArrangeRollNo :: ArrangeRollNo()
{
    // constructor
}

/**
 *      \class  ArrangeRollNo
 *      \fn     ArrangeRollNo :: SortRollNo(INT_VEC & rollNo)
 *      \brief  Function for sorting roll no vector array
 *      \param  rollNo For sorting array
 */

void ArrangeRollNo :: SortRollNo(INT_VEC & rollNo)
{
    sort(rollNo.begin(), rollNo.end());
}

/**
 *      \class  ArrangeRollNo
 *      \fn     ArrangeRollNo :: RemovingRedundancy(INT_VEC & rollNo)
 *      \brief  Function for removing redundant roll nos.
 *      \param  rollNo list of roll nos
 */
 
void ArrangeRollNo :: RemoveRedundancy(INT_VEC & rollNo)
{
    for( j = 0; j < rollNoSize[i]; j++)
    {	
        // Removing duplicate values
        if(rollNo[j] == rollNo[j+1])// || rno[j+1]==rno[j+2])
        {
            for( k = j; k < rollNoSize[i]; k++) 
            {
                //shifts each element one position above
                rollNo[k] = rollNo[k+1];  
            }
            rollNoSize[i]--;
            j=0;
         }
     }
}

/**
 *      \class  ArrangeRollNo
 *      \fn     ArrangeRollNo :: RemoveNonEligibleRollNo(INT_VEC & rollNo, 
 *                               INT_VEC & notIncludedRNo)
 *      \brief  Removing roll no that are not eligible
 *      \param  rollNo roll nos for seating plan
 *      \param  notIncludedRNo Roll no list that is not eligible for
 *              seating plan
 */

void ArrangeRollNo :: RemoveNonEligibleRollNo(INT_VEC & rollNo, 
                                              INT_VEC & notIncludedRNo)
{
    for(k = 0; k < notIncludedRNoSize[i]; k++)
    {
        for(int l = 0; l < rollNoSize[i]; l++)
        {
            if(notIncludedRNo[k] == rollNo[l])
            {
                for(int m = l; m < rollNoSize[i]; m++)
                {
                    rollNo[m] = rollNo[m+1]; 
                }
                rollNoSize[i]--;
            }
         }
     }
}

/**
 *      \class  ArrangeRollNo
 *      \fn     ArrangeRollNo :: AddPrefixWithRollNo(INT_VEC & rollNo, 
 *                               STRING_VEC & prefix)
 *      \brief  Adding prefix with roll nos
 *      \param  rollNo List of eligible roll nos
 *      \param  prefix Prefix ie added with roll nos
 */

void ArrangeRollNo :: AddPrefixWithRollNo(INT_VEC & rollNo, 
                                          STRING_VEC & prefix)
{
    for(k = 0; k < rollNoSize[i]; k++)
    {
        std::stringstream srno;
        srno << rollNo[k];
        prefixRollNo[i][k] = prefix[i] + srno.str();
    }
}

/**
 *      \class  ArrangeRollNo
 *      \fn     ArrangeRollNo :: WriteArrangedRollNo()
 *      \brief  Writing arranged roll nos to file as O/p file
 */

void ArrangeRollNo :: WriteArrangedRollNo()
{
    temp = FileName(ARRANGE_ROLLNO, projectID, 0);

    outFile.open(temp.c_str());

    outFile << totalClasses << endl;

    for(i = 0; i < totalClasses; i++)
    {
        outFile << rollNoSize[i] << endl;
        for(j = 0; j < rollNoSize[i]; j++)
        {
            outFile << prefixRollNo[i][j] << endl;
        }
    }

    outFile.close();
}

/**
 *      \class  ArrangeRollNo
 *      \fn     ArrangeRollNo :: Main(string pID)
 *      \brief  Main function to call all functions
 *      \param  pID Project ID
 */

void ArrangeRollNo :: Main(string pID)
{
    projectID = pID;

    expandRNo.ExpandRollNos(pID);

    temp = FileName(EXPAND_ROLLNO, projectID, 0);

    inFile.open(temp.c_str());


    inFile >> totalClasses;

    rollNoSize.resize(totalClasses);
    notIncludedRNoSize.resize(totalClasses);
    prefix.resize(totalClasses);
    prefixRollNo.resize(totalClasses);
    
    for(i = 0; i < totalClasses; i++)
    {
        getline(inFile, prefix[i], '\n');
        getline(inFile, prefix[i], '\n');
        inFile >> rollNoSize[i];
        rollNo.resize(rollNoSize[i]);
        for(j = 0; j < rollNoSize[i]; j++)
        {
            inFile >> rollNo[j];
        }
        
        SortRollNo(rollNo);
        
        RemoveRedundancy(rollNo);
 
        inFile >> notIncludedRNoSize[i];
        notIncludedRNo.resize(notIncludedRNoSize[i]);
        for(j = 0; j < notIncludedRNoSize[i]; j++)
        {
            inFile >> notIncludedRNo[j];
        }
        
        RemoveNonEligibleRollNo(rollNo, notIncludedRNo);
        
        for(j = 0; j < rollNoSize[i]; j++)
        {
            prefixRollNo[i].resize(rollNoSize[i]);
        }

        AddPrefixWithRollNo(rollNo, prefix);
    }

    inFile.close();

    WriteArrangedRollNo();
}

/**
 *      \class  ArrangeRollNo
 *      \fn     ArrangeRollNo :: ~ArrangeRollNo()
 *      \brief  Destructor
 */

ArrangeRollNo :: ~ArrangeRollNo()
{
    // Destructor
}
