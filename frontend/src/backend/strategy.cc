/**
 *       \file       strategy.cc
 *
 *       \brief      Function definition of Strategy class
 *
 *       \version    0.7
 *       \date       Tuesday 02 April 2013 03:02:04  IST\n
 *       Compiler    g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

/**
 *  include strategy.h 
 */

#include "header/strategy.h"

/**
 *      \class  Strategy
 *      \fn     Strategy :: Strategy()
 *      \brief  Constructor
 */

Strategy :: Strategy()
{
    // constructor
    totalStrategy = 5;
    strategyName.resize(totalStrategy);
    i = 0;
    strategyName[i++] = "1";
    strategyName[i++] = "2";
    strategyName[i++] = "3";
    strategyName[i++] = "4";
    strategyName[i++] = "5";

    totalSeats = totalStudents = totalGroupSeats = 0;
}

void Strategy :: TotalSeats(int strategy, int i)
{
    roomSize.resize(totalDays);
    roomSize[i].resize(totalCentres[i]);
 
    for(j = 0; j < totalCentres[i]; j++)
    {   
        roomSize[i][j].resize(totalRooms[i][j]);
    }
    for(j = 0; j < totalCentres[i]; j++)
    {
        for(k = 0; k < totalRooms[i][j]; k++)
        {
            roomSize[i][j][k] = rows[i][j][k] * cols[i][j][k];
            totalSeats = totalSeats + roomSize[i][j][k];
            totalGroupSeats += roomSize[i][j][k] / strategy;
        }
    }
}
 
void Strategy :: TotalStudents(int i)
{ 
    for(j = 0; j < totalExams[i]; j++)
    {
        totalStudents += dateSheetRNoSize[i][j];
    }
}

void Strategy :: TotalGroupStudents(int strategy, int i)
{
    iTemp.resize(totalExams[i]);
    indexValue.resize(totalExams[i]);

    if(strategy == 5)
        strategy = 1;
    s = 0;
    for(j = 0; j < totalExams[i]; j++)
    {
        iTemp[j] = dateSheetRNoSize[i][j];
        indexValue[j] = 0;
    }
    
    groupStudentSize.resize(strategy);

    for(j = 0; j < strategy; j++)
    {
        groupStudentSize[j] = 0;
    }
    
    sort(iTemp.begin(), iTemp.end());
    
    for(j = 0; j < totalExams[i]; j++)
    {
        for(k = 0; k < totalExams[i]; k++)
        {
            if(iTemp[k] == dateSheetRNoSize[i][j])
            {
                if(indexValue[k] == 0)
                {
                    indexValue[k] = j;
                    break;
                }
                
            }
        }
    }
    
    for(j = 0; j < totalExams[i]; j++)
    {
        if(s == strategy)
            s = 0;
        groupStudentSize[s] += dateSheetRNoSize[i][indexValue[j]];
        s++;
               
    }
    sort(groupStudentSize.begin(), groupStudentSize.end());
}

void Strategy :: GroupCondition(int strategy, int i)
{ 
    if(groupStudentSize[strategy-1] > totalGroupSeats)
    {
        int extra = (groupStudentSize[strategy-1] - totalGroupSeats);
        
        extra = extra * strategy;
        
        outFile << "N" << endl;
        outFile << extra << endl;
/*        outFile << "\t condition invalid" << endl
                << "\t Add " << extra << " more seats." << endl;*/
        
        outFile.close();    
    }
    else
    {
        outFile << "Y" << endl;
//        outFile << "\t condition is valid" << endl;
        outFile.close();
        SeatingPlan(strategy, i);
        
        WriteSeatPlan(projectID, i);
//        WriteHTMLFile(projectID, i);
    }
}

void Strategy :: CheckValidation(int strategy, int i)
{
    temp = FileName(VALIDATION, projectID, 0);

    outFile.open(temp.c_str(), ios::app);
    
    TotalSeats(strategy, i);
    TotalStudents(i);
    TotalGroupStudents(strategy, i);
    
/*    outFile << " Date " << date[i] << endl
            << " Total Exams " << totalExams[i] << endl
            << " Selected Strategy " << strategy << endl;
    outFile << " Total Seats = " << totalSeats << endl
            << " Total Students = " << totalStudents << endl
            << " Total Strategy Group Seats = " 
            << totalGroupSeats << endl
            << " Max Strategy Group Students = " 
            << groupStudentSize[strategy-1] 
            << endl;*/
    outFile << date[i] << endl;
    outFile << strategy << endl
            << totalSeats << endl
            << totalStudents << endl
            << totalGroupSeats << endl
            << groupStudentSize[strategy-1] << endl;

    db.InsertValidStrategy(projectID, IntToString(i + 1), date[i], 
                           IntToString(strategy), 
                           IntToString(totalSeats),
                           IntToString(totalStudents), 
                           IntToString(totalGroupSeats), 
                           IntToString(groupStudentSize[strategy-1]));

    if(totalSeats < totalStudents)
    {
        outFile << "N" << endl;
        //outFile << "\t Add More rooms!" << endl;
        outFile.close();
    }
    else
        GroupCondition(strategy, i);
    
}  

/**
 *      \class  Strategy
 *      \fn     Strategy :: ChooseStrategy()
 *      \brief  Select Strategy
 */

void Strategy :: ChooseStrategy()
{
    int choice;

    temp = FileName(VALIDATION, projectID, 0);
    outFile.open(temp.c_str());
    outFile.close();
 
    STRING_VEC vecTemp;
    string where = "ProjectID = " + projectID;                               
    db.SelectColumn(vecTemp, "TotalSeats",                    
                          "ValidStrategy", where);                   
    if(vecTemp.size() > 0)                                            
    {                                                                 
        db.DeleteQuery("ValidStrategy", where);                
    } 
   
    for(i = 0; i < totalDays; i++)
    {
        totalSeats = totalStudents = totalGroupSeats = 0;
        for(int str = 0; str < totalStrategy; str++)
        {
            if(strategyOption[i] == strategyName[str])
            {
                choice = (str + 1);
                CheckValidation(choice, i);
            }
        }
    }
}

/**
 *      \class  Strategy
 *      \fn     Strategy :: Main(string pID)
 *      \brief  Main Function to call all other functions
 *      \param  pID project ID of user's project
 */

void Strategy :: Main(string pID)
{
    projectID = pID; 
    
    ReadClassDetail(projectID);
    ReadDateSheetOut(projectID);
    ReadRoomDetail(projectID);
    ReadExamDetail(projectID);
    ReadStrategy(projectID);

    ChooseStrategy();
}

string Strategy :: IntToString(int value)
{
    ss.clear(); ss.str("");          /*   Empty stringstream object */
    ss << value;                                                     
    return ss.str();
}

/**
 *      \class  Strategy
 *      \fn     Strategy :: ~Strategy()
 *      \brief  Destructor
 */

Strategy :: ~Strategy()
{
    // destructor
}
