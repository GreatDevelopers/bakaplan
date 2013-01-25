#include "strategy.h"

void ReadRoomDetails :: readRoomDetails()
{
    fi = formData.getElement(total_centres);
    
    if( !fi->isEmpty() && fi != (*formData).end()) 
    {
        temp = **fi;
        totalCentres = atoi(temp.c_str());
    }

//    i = 0; j = 0;
    for(i = 0; i < totalCentres; i++)
    {
        centreNo[i] = readField(centre_no, i);
        totalRooms[i] = atoi(readField(total_rooms, i).c_str());
        for(j = 0; j < totalRooms[i]; j++)
        {
            roomNo[i][j]    =   readField(room_no, i, j);
            roomRows[i][j]  =   readField(rows, i, j);
            roomCols[i][j]  =   readField(cols, i, j);
        }
    }
}

string ReadRoomDetails :: readField(string fieldname, int i)
{
    std::stringstream no;
    string result;
    no << (i+1);
    temp = fieldname + no.str();
    fi = formData.getElement(temp);  
    if( !fi->isEmpty() &&fi != (*formData).end()) 
    {  
        result = **fi;  
    }
    else
    {
        result = " "; 
    }
    return result;
}

string ReadRoomDetails :: readField(string fieldname, int i, int j)
{
    std::stringstream no1, no2;
    string result;
    no1 << (i+1);
//    temp = fieldname + no1.str();
    no2 << (j+1);
    temp = fieldname + no1.str() + no2.str();
    fi = formData.getElement(temp);  
    if( !fi->isEmpty() &&fi != (*formData).end()) 
    {  
        result = **fi;  
    }
    else
    {
        result = " "; 
    }
    return result;
}

void ReadRoomDetails :: writeRoomDetails()
{
    outfile.open(RoomDetails_in);
    
    outfile << totalCentres << endl;
    
    for(i = 0; i < totalCentres; i++)
    {
        outfile << centreNo[i] << endl
                << totalRooms[i] << endl;
        for(j = 0; j < totalRooms[i]; j++)
        {
            outfile << roomNo[i][j] << endl
                    << roomRows[i][j] << " "
                    << roomCols[i][j] << endl;
        }
    }
    
    outfile.close();
}

void ReadRoomDetails :: Main()
{   
    readRoomDetails();
    writeRoomDetails();
}
