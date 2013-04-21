/**
 *
 *       \file       seatplan.cc
 *
 *       \brief      Function definition of SeatPlan Class
 *
 *       \version    0.6
 *       \date       Tuesday 02 April 2013 02:44:21  IST\n
 *       Compiler    g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

/**
 *  include seatplan.h file 
 */
#include "header/seatplan.h"

/**
 *      \class  SeatPlan
 *      \fn     SeatPlan :: SeatPlan()
 *      \brief  Constructor
 */

SeatPlan :: SeatPlan()
{
    // constructor
}

void SeatPlan :: SetRollNo(int strategy, int i)
{ 
    int stra;
    if(strategy == 5)
        stra = 1;
    else
        stra = strategy;
    s = 0;
    for(j = 0; j < strategy; j++)
    {
        seatSize[j] = 0;
    }
   
    seatRollNo.resize(strategy);
    for(j = 0; j < totalExams[i]; j++)
    {
        if(s == stra)
            s = 0;
        
        start = seatSize[s];
        index = indexValue[j];
        end = dateSheetRNoSize[i][index];
        seatRollNo[s].resize(start + end);
        for(k = 0; k < end; k++)
        {
            seatRollNo[s][start + k] = dateSheetRNo[i][index][k];
        }
        
        seatSize[s] = start + end;
        s++;
    }
}

void SeatPlan :: SeatingPlan(int strategy, int i)
{  
    int stra;
  
    seatSize.resize(strategy);

    SetRollNo(strategy, i);
    
    if(strategy == 5)
        stra = 1;
    else
        stra = strategy;
    
    size.resize(stra);

    for(j = 0; j < stra; j++)
    {
        size[j] = 0;
    }

    seat.resize(totalCentres[i]);
    for(centre = 0; centre < totalCentres[i]; centre++)
    {
        seat[centre].resize(totalRooms[i][centre]);
        for(room = 0; room < totalRooms[i][centre]; room++)
        {
            seat[centre][room].resize(rows[i][centre][room]);
            for(row = 0; row < rows[i][centre][room]; row++)
            {
                seat[centre][room][row].resize(cols[i][centre][room]);
            }
        }
    }

    for(centre = 0; centre < totalCentres[i]; centre++)
    {
        for(room = 0; room < totalRooms[i][centre]; room++)
        {
            for(row = 0; row < cols[i][centre][room]; row++)
            {
                if((row % 2) != 0)
                {
                    if(strategy == 2)
                        s = 1;
                    if(strategy > 2)
                        s = 2;
                    if(strategy == 5)
                    {
                        s = 0;
                    }
                }
                else
                    s = 0;
                  
                if(strategy == 5)
                {
                    if((row % 2) != 0)
                    {
                        for(col = rows[i][centre][room]-1; col >= 0; col--)
                        {
                            if(s == stra)
                                s = 0;
                            seat[centre][room][col][row] = RollNo(s);
                            s++;
                        }
                    }
                    else
                    {
                        for(col = 0; col < rows[i][centre][room]; col++)
                        {
                            if(s == stra)
                                s = 0;
                            seat[centre][room][col][row] = RollNo(s);
                            s++;
                        }
                    }
                }
                else
                {
                    for(col = 0; col < rows[i][centre][room]; col++)
                    {
                        if(s == strategy)
                            s = 0;
                        seat[centre][room][col][row] = RollNo(s);
                        s++;
                    }
                }
                
            }
        }
    }

   // WriteSeatPlan(projectID, i);
}
 
string SeatPlan :: RollNo(int s)
{
    string rno;
     
    if(seatSize[s] == size[s])
        rno = "-";
    else
    {
        rno = seatRollNo[s][size[s]];
        size[s]++;
    }
    return rno;
    
}

void SeatPlan :: WriteSeatPlan(string projectID, int i)
{ 
    stringstream ss;

    ss << (i + 1);

    projectID += "-" + ss.str();
    
    temp = FileName(SEATPLAN, projectID, 0);
    
    outFile.open(temp.c_str());
    
    outFile << totalCentres[i] << endl;
    
    for(centre = 0; centre < totalCentres[i]; centre++)
    {
        outFile << centreName[i][centre] << endl
                << totalRooms[i][centre] << endl;
        
        for(room = 0; room < totalRooms[i][centre]; room++)
        {
            outFile << roomNo[i][centre][room] << endl
                    << rows[i][centre][room] << " "
                    << cols[i][centre][room] << endl;

            for(row = 0; row < rows[i][centre][room]; row++)
            {
                for(col = 0; col < cols[i][centre][room]; col++)
                {
                    outFile << seat[centre][room][row][col] << "\t";
                }
                outFile << "\n";
            }
        }
    }
    outFile.close();
}

/**
 *      \class  SeatPlan
 *      \fn     SeatPlan :: ~SeatPlan()
 *      \brief  DEstructor
 */

SeatPlan :: ~SeatPlan()
{
    // destructor
}
