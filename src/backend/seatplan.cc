#include "seatplan.h"

void SeatPlan :: readRoomDetails(string file)
{
    infile.open(file.c_str());
    infile >> total_centres;
//   getline(infile, centre_no[0], '\n');
    for(i = 0; i < total_centres; i++)
    {
       getline(infile, centre_no[i], '\n');
       getline(infile, centre_no[i], '\n');
       infile >> total_rooms[i];
//      getline(infile, room_no[i][0], '\n');
       for (j = 0; j < total_rooms[i]; j++)
       {
          getline(infile, room_no[i][j], '\n');
          getline(infile, room_no[i][j], '\n');
          infile >> rows[i][j] >> cols[i][j];
       }
    }
    infile.close();
}

void SeatPlan :: readSubjectWiseRollNo(string file)
{
    infile.open(file.c_str());
    infile >> total_code;
    //getline(infile, sub_subcode[0], '\n');
    for(i = 0; i < total_code; i++)
    {
        getline(infile, sub_subcode[i], '\n');
        getline(infile, sub_subcode[i], '\n');
        infile >> sub_totalrno[i];
       
        for(j = 0; j < sub_totalrno[i]; j++)
            infile >> sub_rollno[i][j];
    }
    infile.close();
}

void SeatPlan :: setRollNo(int strategy)
{
    int stra;
    if(strategy == 5)
        stra = 1;
    else
        stra = strategy;
    s = 0;
    for(i = 0; i < strategy; i++)
    {
        seat_size[i] = 0;
    }
    
    for(i = 0; i < total_code; i++)
    {
        if(s == stra)
            s = 0;
        
        start = seat_size[s];
        index = index_value[i];
        end = sub_totalrno[index];
        
        for(j = 0; j < end; j++)
        {
            seat_rollno[s][start + j] = sub_rollno[index][j];
        }
        
        seat_size[s] = start + end;
        s++;
    }    
}

void SeatPlan :: seatingPlan(int strategy)
{
    int from, to, next, stra;
    
    setRollNo(strategy);
    
    if(strategy == 5)
        stra = 1;
    else
        stra = strategy;
    
    for(i = 0; i < stra; i++)
    {
        size[i] = 0;
    }
    
    // centre = total centre, room = total room[], row = rows[][], col = cols[][]
    
    for(centre = 0; centre < total_centres; centre++)
    {
        for(room = 0; room < total_rooms[centre]; room++)
        {
            for(row = 0; row < cols[centre][room]; row++)
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
                        for(col = rows[centre][room]-1; col >= 0 ; col--)
                        {
                            if(s == stra)
                                s = 0;
                            seat[centre][room][col][row] = rollNo(s);
                            s++;
                        }
                    }
                    else
                    {
                        for(col = 0; col < rows[centre][room]; col++)
                        {
                            if(s == stra)
                                s = 0;
                            seat[centre][room][col][row] = rollNo(s);
                            s++;
                        }
                    }
                }
                else
                {          
                    for(col = 0; col < rows[centre][room]; col++)
                    {
                        if(s == strategy)
                            s = 0;
                        seat[centre][room][col][row] = rollNo(s);
                        s++;
                    }
                }
            }
        }
    }
}

string SeatPlan :: rollNo(int s)
{
    string rno;
    
    if(seat_size[s] == size[s])
        rno = "-";
    else
    {
        rno = seat_rollno[s][size[s]];
        size[s]++;
    }
    return rno;
}

void SeatPlan :: showSeatPlan()
{
    outfile.close();
  fileName  = "";//"../";
    fileName += OUTPUT_FOLDER;
    fileName += PID + projectID + SEATPLAN_OUT;

    outfile.open(fileName.c_str());
    outfile << total_centres << endl;
    for(centre = 0; centre < total_centres; centre++)
    {
        outfile << centre_no[centre] << endl
                << total_rooms[centre] << endl;
        for(room = 0; room < total_rooms[centre]; room++)
        {
            outfile << room_no[centre][room] << endl
                    << rows[centre][room] << " "
                    << cols[centre][room] << endl;
                    
            for(row = 0; row < rows[centre][room]; row++)
            {
                for(col = 0; col < cols[centre][room]; col++)
                {
                    outfile << seat[centre][room][row][col] << "\t";
                }
                outfile << "\n";
            }
        }
    }
    outfile.close();
}
