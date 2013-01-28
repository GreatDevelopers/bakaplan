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
    
    /////////////////////////////////////////
    
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
    
    
}

void Report :: readSeatPlan(string file)
{
    infile.open("SeatPlan.out");//file.c_str());
    infile >> total_centres;
//    cout << total_centres;
    getline(infile, centre_no[0], '\n');
    for(centre = 0; centre < total_centres; centre++)
    {
//        getline(infile, centre_no[centre], '\n');
        getline(infile, centre_no[centre], '\n');
        infile >> total_rooms[centre];
        for(room = 0; room < total_rooms[centre]; room++)
        {
            getline(infile, room_no[centre][room], '\n');
            //getline(infile, room_no[centre][room], '\n');

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
    
    outfile.open("test.txt");
    outfile << "total centres : " << total_centres << endl;
    for(centre = 0; centre < total_centres; centre++)
    {
        outfile << "centre no: " << centre_no[centre] << endl
                << "total rooms: " << total_rooms[centre] << endl;
        for(room = 0; room < total_rooms[centre]; room++)
        {
            outfile << room_no[centre][room] << endl;
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
    
    outfile.open("SeatPlan.html");
    outfile << "<html><head><title>BaKa Plan</title>"
            << "<style> @media print { div {page-break-before:always} } </style> </head>"
            << "<body align = \"center\" > <pre>"
            //<< "<br><br> " //<h2> Seating Plan </h2> <br>";//" <b> Total Centres: "
            
            << endl;
//            << total_centres << "</b> " << endl;
    for(centre = 0; centre < total_centres; centre++)
    {
                
        for(room = 0; room < total_rooms[centre]; room++)
        {
            outfile << "<h3>"
                    << "Examination :   " << exam_name << "<br>"
                    << "Date : " << exam_date << "<br>"
                    << "Time : " << exam_time << "<br>"
                    << "Venue : " << exam_venue << "<br>"
                    << "</h3>";
            
            outfile << "<b><br> Centre Name: </b>" << centre_no[centre] << endl;
//                <<  "<b>     Total Rooms: </b>" << total_rooms[centre] 
            outfile << "<br><b>Room No: </b>" << room_no[centre][room] << endl << "<br>"
                    << "<table align = \"center\" cellpadding = \"8\""
                    << " cellspacing = \"1\" border = \"1\">";
            outfile << "<tr>";
                j = 65 + cols[centre][room];
                for(i = 64; i < j; i++)
                {
                    char a;
                    if (i==64)
                        a = ' ';
                    else
                        a = i;
                    outfile << "<th width = \"80\" height = \"30\""
                            << " align = \"center\" valign = \"center\">" 
                            << a << "</th>";
                }
                outfile << "</tr>";
            for(row = 0; row < rows[centre][room]; row++)
            {
                
                outfile << "<tr><td width = \"80\" height = \"30\" "
                        << "align = \"center\" valign = \"center\">"
                        << row+1
                        << "</td>";
                for(col = 0; col < cols[centre][room]; col++)
                {
                    outfile << "<td width = \"80\" height = \"30\" "
                            << "align = \"center\" valign = \"center\">" 
                            << seat[centre][room][row][col] 
                            << "</td>";
                }
                outfile << "</tr>";
            }
            outfile << "</table>";
            outfile << "<div>  </div>";
        }
    }
    outfile.close();
    
}

void Report :: Main()
{
    readInputRollNo("input_rollno.out");//Input_Rollno_out);
    readSeatPlan(SeatPlan_out);
}
