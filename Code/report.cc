#include "report.h"

void Report :: readInputRollNo(string file)
{
    infile.open(file.c_str());
    
    infile >> total_branches;
    getline(infile, branch_name[0], '\n');
    for(i = 0; i < total_branches; i++)
    {
        getline(infile, branch_name[i], '\n');
        infile >> total_subject[i];
        getline(infile, subject_name[i][0], '\n');
        for(j = 0; j < total_subject[i]; j++)
        {
            getline(infile, subject_name[i][j], '\n');
            getline(infile, subject_code[i][j], '\n');
            infile >> total_rollno[i][j];
            for(k = 0; k < total_rollno[i][j]; k++)
            {
                infile >> rollno[i][j][k];
            }
            getline(infile, subject_name[i][j+1], '\n');
        }
    }
    
    infile.close();
    
/*    /////////////////////////////////////////
    
    outfile.open("report.txt");
    
    outfile << total_branches << endl;
    for(i = 0; i < total_branches; i++)
    {
        outfile << branch_name[i] << endl;
        outfile << total_subject[i] << endl;
        for(j = 0; j < total_subject[i]; j++)
        {
            outfile << subject_name[i][j] << endl;
            outfile << subject_code[i][j] << endl;
            outfile << total_rollno[i][j] << "\t";
            for(k = 0; k < total_rollno[i][j]; k++)
            {
                outfile << rollno[i][j][k] << "\t";
            }
            outfile << endl;
        }
    }
    
    outfile.close();
    
    /////////////////////////////////////////
    */
    
}

void Report :: readSeatPlan(string file)
{
    infile.open(file.c_str());
    infile >> total_centres;
    for(centre = 0; centre < total_centres; centre++)
    {
        infile >> centre_no[centre];
        infile >> total_rooms[centre];
        for(room = 0; room < total_rooms[centre]; room++)
        {
            infile >> room_no[centre][room];
            for(row = 0; row < rows[centre][room]; row++)
            {
                for(col = 0; col < cols[centre][room]; col++)
                {
                    infile >> seat[centre][room][row][col];
                }
            }
        }
    }
    infile.close();
    
    /////////////////////////////////////////////////////
    
    
    
    /////////////////////////////////////////////////////
}

void Report :: Main()
{
    readInputRollNo(Input_Rollno_out);
    readSeatPlan(Seat_Plan_out);
}
