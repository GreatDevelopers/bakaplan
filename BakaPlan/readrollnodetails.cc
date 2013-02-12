#include "roomdetails.h"

ReadRollNoDetails :: ReadRollNoDetails(){}

void ReadRollNoDetails :: readRollNoDetails()
{
    infile.open(TotalFields);
    infile >> totalFields;
    infile.close();
    
    for(i = 0; i < totalFields; i++)
    {  
        rnoPrefix[i]         =   readField(prefix, i);
        startRollNo[i]       =   readField(start_rollno, i);
        endRollNo[i]         =   readField(end_rollno, i);
        notIncludedRollNo[i] =   readField(not_included, i);   
    }
}

string ReadRollNoDetails :: readField(string fieldname, int i)
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

void ReadRollNoDetails :: writeRollNoDetails()
{
    outfile.open(RollNoDetails_in);
    
    for(i = 0; i < totalFields; i++)
    {
        outfile << rnoPrefix[i] << endl
                << startRollNo[i] << "-" << endRollNo[i] << endl
                << notIncludedRollNo[i] << endl;
    }
    
    outfile.close();
}

void ReadRollNoDetails :: Main()
{
    readRollNoDetails();
    writeRollNoDetails();
}
