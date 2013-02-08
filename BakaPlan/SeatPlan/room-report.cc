#include "report.h"

void RoomReport :: readInputRollNo(string file)
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
}

void RoomReport :: readSeatPlan(string file)
{
    infile.open(file.c_str());
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
            getline(infile, room_no[centre][room], '\n');
            infile >> rows[centre][room]
                   >> cols[centre][room]; 
            for(row = 0; row < rows[centre][room]; row++)
            {
                for(col = 0; col < cols[centre][room]; col++)
                {
                    infile >> seat[centre][room][row][col];
                }
            }
        }
        getline(infile, centre_no[centre+1], '\n');
    }
    infile.close();
}

void RoomReport :: readExamDetails(string file)
{
    infile.open(file.c_str());
    getline(infile, exam_name, '\n');
    getline(infile, exam_date, '\n');
    getline(infile, exam_time, '\n');
    getline(infile, exam_venue, '\n');
    infile.close();
}

void RoomReport :: writeSeatPlan(string file)
{
    outfile.open(file.c_str());
    outfile << "<html><head><title>BaKa Plan</title>"
            << "<style> @media print { div {page-break-before:always} } "
//            
            << "td {font-size:130%; font-weight:bold;}"
//            << "b {font-size:150%}"
//            << "th {font-size:150%}"
//            << "p {font-size:130%;}"
            << "h1 {font-size:300%; font-family: }"
            << "body{font-family:\"Open Sans\";}"
//            
            << "</style> "
//            << "<link href=\"BaKaPlan/bootstrap/css/bootstrap.min.css\""
//            << " rel=\"stylesheet\" media=\"screen\">"
            << "<link href='http://fonts.googleapis.com/css?family=Open+Sans' rel='stylesheet' type='text/css'>"
//            << "<link href='http://fonts.googleapis.com/css?family=Bitter' rel='stylesheet' type='text/css'>"
            << "<link href=\"BaKaPlan/output.css\""
            << " rel=\"stylesheet\" media=\"screen print\">"
            << "</head>"
            << "<body align = \"center\" > "
            //<< "<br><br> " //<h2> Seating Plan </h2> <br>";//" <b> Total Centres: "
            
            << endl;
//            << total_centres << "</b> " << endl;
    for(centre = 0; centre < total_centres; centre++)
    {        
        for(room = 0; room < total_rooms[centre]; room++)
        {
            total_students[0] = total_students[1] = total_students[2] = total_students[3] = total = 0;
            int rno;
            start_rno[0] = start_rno[1] = start_rno[2] = start_rno[3] = 35675;
            end_rno[0] = end_rno[1] = end_rno[2] = end_rno[3] = 0;
            
            outfile << "<h1 style = \" line-height:20%; font-family:arial; font-size: 170%;\"> " << exam_name  <<"</h1>"
                    << "<h2 style=\"font-size: 120%;\"> " << exam_date << " | at " << exam_time << " |&nbsp Venue : " << exam_venue
                    << "</h2>";
                    
            outfile << "<h2 style=\"line-height:20%;\" >Centre : " << centre_no[centre] << "&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp Room : " << room_no[centre][room] << "</h2>";
            
//            outfile << "<h1 style = \"font-size: 250%;\"> " << exam_name << "</h1><br>";
//            outfile << "<table align = \"center\" class=\"table\" width = \"800px\" cellpadding = \"0\" style=\"line-height:-4px;\">"
////                    << "<tr>"
////                    << "<td>"
////                    << "<h1> " << exam_name << " </h1></td></tr> "
//                    << "<tr width = \"300\">"
//                    << "<td>"
//                    << "<h1 style = \"font-size: 150%\">Date : " << exam_date << "</b></td>"
//    
//                    << "<td>"
//                    << "<h1 style = \"font-size: 150%\">Time : " << exam_time << "</b></td></tr>"
//                    << "<tr width = \"150\" colspan=\"2\">"
//                    << "<td>"
//                    << "<h1 style = \"font-size: 150%\">Venue : " << exam_venue << "</b></td></tr>"
//                    << "<tr width = \"300\">"
//                    << "<td>";
//            
//            outfile << "<h1 style = \"font-size: 150%;\"> Centre Name : " << centre_no[centre] << "</b></td>"
//                    << endl
//                    
//                    << "<td>";
////                <<  "<b>     Total Rooms: </b>" << total_rooms[centre] 
//            outfile << "<h1 style = \"font-size: 150%\">Room No : " << room_no[centre][room] << endl 
//                    << "</b></td></tr>"
//                    << "</table><br><br>"
                    
                outfile    << "<table align = \"center\" cellpadding = \"2\""
                    << " cellspacing = \"1\" border = \"1\" width = \"800px\">";
            
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
                            << addPrefix(seat[centre][room][row][col]) 
                            << seat[centre][room][row][col] 
                            << "</td>";
                }
                outfile << "</tr>";
            }
            outfile << "</table><p>";
            
            // students info
            for(int t = 0; t < 4; t++)
            {
                if(total_students[t] != 0)
                    outfile << prefix[t] << "{ " << start_rno[t]  << " - "
                            << end_rno[t] << " }"<< " = " << total_students[t] 
                            << "<br>" << endl;
            }
            
            outfile << " Total Students : " << total;
            
            outfile << "<br> Seating Plan generated by "
                    << "<b>BaKaPlan</b> (http://freecode.com/projects/bakaplan)</p>";
            
            outfile << "<div>  </div>";
        }
    }
    outfile.close();
}

void RoomReport :: range(int rno, int r)
{
    if(rno < start_rno[r])
        start_rno[r] = rno;
    if(rno > end_rno[r])
        end_rno[r] = rno;
}

string RoomReport :: addPrefix(string roll)
{
    string rollno;
    prefix[0] = "CS8171";
    prefix[1] = "PI8171";
    prefix[2] = "ME8171";
    prefix[3] = "EC8171";
    
    int rno;
    rno = atoi(roll.c_str());
    
    if(rno >= 1001 && rno <= 1289)
    {
        rollno = prefix[0];      // 0 index
        total_students[0]++;
        range(rno, 0);
        total++;
//        even = " ";
//        odd = " ";
    }
    else if(rno >= 1290 && rno <= 1457)
    {
        if( rno % 2 == 0)
        {
            if(rno >= 1290 && rno <= 1439)
            {
                rollno = prefix[1];      // 1 index
                total_students[1]++;
                range(rno, 1);
            }
            else
            {
                rollno = prefix[2];      // 2 index
                total_students[2]++;
                range(rno, 2);
            }
//            even = " (Even Roll No.)";
        }    
        else
        {
            rollno = prefix[0];      // 0 index
            total_students[0]++;
            range(rno, 0);
//            odd = " (Odd Roll No.)";
        }
        total++;
    }
    else if(rno >= 2001 && rno <= 2298)
    {
        rollno = prefix[3];      // 3 index 
        total_students[3]++;
        range(rno, 3);
        total++;
    }
    else
    {
        rollno = " ";
        even = " ";
        odd = " ";
    }
    
    return rollno;
}

void RoomReport :: Main()
{
    readInputRollNo(Input_Rollno_out);
    readSeatPlan(SeatPlan_out);
    readExamDetails(Input_ExamDetails);
    writeSeatPlan(SeatPlan_HTMLFile);
}
