/**
 *       \file       strategy.cc
 *
 *       \brief      Function definition of Strategy class
 *
 *       \version    0.6
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
    totalSeats = totalStudents = totalGroupSeats = 0;
}

void Strategy :: TotalSeats(int strategy)
{
    roomSize.resize(totalCentres);
    for(i = 0; i < totalCentres; i++)
    {
        roomSize[i].resize(totalRooms[i]);
    }

    for(i = 0; i < totalCentres; i++)
    {
        for(j = 0; j < totalRooms[i]; j++)
        {
            roomSize[i][j] = rows[i][j] * cols[i][j];
            totalSeats += roomSize[i][j];
            totalGroupSeats += roomSize[i][j] / strategy;
        }
    }
}
/* 
void Strategy :: totalStudents()
{
    for(i = 0; i < total_code; i++)
    {
        total_students += sub_totalrno[i];
    }
}

void Strategy :: totalGroupStudents(int strategy)
{
    if(strategy == 5)
        strategy = 1;
    s = 0;
    for(i = 0; i < total_code; i++)
    {
        temp[i] = sub_totalrno[i];
        index_value[i] = 0;
    }
//    cout << "total code " << total_code << endl;
    
    for(i = 0; i < strategy; i++)
    {
        group_student_size[i] = 0;
    }
    
    sort(temp, temp + total_code);
    
    for(i = 0; i < total_code; i++)
    {
        for(j = 0; j < total_code; j++)
        {
            if(temp[j] == sub_totalrno[i])
            {
                if(index_value[j] == 0)
                {
                    index_value[j] = i;
                    break;
                }
                
            }
        }
    }
    
    for(i = 0; i < total_code; i++)
    {
        if(s == strategy)
            s = 0;
        group_student_size[s] += sub_totalrno[index_value[i]];
        s++;
               
    }
    sort(group_student_size, group_student_size + strategy);
}

void Strategy :: groupCondition(int strategy)
{
    if(group_student_size[strategy-1] > total_group_seats)
    {
        int extra = (group_student_size[strategy-1] - total_group_seats);
        extra = extra * strategy;
        outfile << "\t condition invalid" << endl
                << "\t Add " << extra << " more seats." << endl;
        
        outfile.close();    
    }
    else
    {
        outfile << "Y" << endl;
        outfile << "\t condition is valid" << endl;
        outfile.close();
        seatingPlan(strategy);
        showSeatPlan();
//        Report :: Main();
    }
}
*/
void Strategy :: CheckValidation(int strategy)
{/*
    temp = FileName(VALIDATION, projectID, 0);

    outfile.open(temp.c_str());
    
    TotalSeats(strategy);
    TotalStudents();
    TotalGroupStudents(strategy);
    
    outfile << "\n\t Total Seats = " << total_seats << endl
            << "\t Total Students = " << total_students << endl
            << "\t Total Group Seats = " << total_group_seats << endl
            << "\t Max Group Students = " << group_student_size[strategy-1] 
            << endl;
    
    // Showing values while console
//    cout << "\n\t Total Seats = " << total_seats << endl
//         << "\t Total Students = " << total_students << endl
//         << "\t Total Group Seats = " << total_group_seats << endl
//         << "\t Max Group Students = " << group_student_size[strategy-1] << endl;
//    
    if(total_seats < total_students)
    {
        outfile << "\t Add More rooms!" << endl;
//        cout << "\t Add More rooms!" << endl;
        outfile.close();
    }
        
    else
        groupCondition(strategy);
        
    //outfile.close();
    */
}  

/**
 *      \class  Strategy
 *      \fn     Strategy :: ChooseStrategy()
 *      \brief  Select Strategy
 */

void Strategy :: ChooseStrategy()
{
    int choice;
   
    if(strategyOption == "1")//"Continual Strategy")
        choice = 1;
    if(strategyOption == "2")//"Strategy 2")
        choice = 2;
    if(strategyOption == "3")//"Strategy 3")
        choice = 3;
    if(strategyOption == "4")//"Strategy 4")
        choice = 4;
    if(strategyOption == "5")//"Serpentine Strategy")
        choice = 5;
        
    CheckValidation(choice);
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

    ReadDateSheetOut(projectID);
    ReadRoomDetail(projectID);
    ReadStrategy(projectID);

    ChooseStrategy();
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
