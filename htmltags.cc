#include "htmltags.h"

HTMLTags :: HTMLTags()
{
    // branch field names
    branch_name     =    "BranchName";
    total_subjects  =    "TotalSubjects";
    subject_code    =    "SubjectCode";
    subject_name    =    "SubjectName";
    total_branches  =    "TotalBranches";
    
    // rollno field names
    prefix          =    "Prefix";
    start_rollno    =    "StartRollNo";
    end_rollno      =    "EndRollNo";
    not_included    =    "NotIncluded";
    
    // room field names
    total_centres   =    "TotalCentres";
    centre_no       =    "CentreNo";
    total_rooms     =    "TotalRooms";
    room_no         =    "RoomNo";
    rows            =    "Rows";
    cols            =    "Cols";
    
    // Strategy option
    strategy        =    "Strategy";
    
    // Exam Details
    exam_name       =    "ExamName";
    exam_time       =    "ExamTime";
    exam_date       =    "ExamDate";
    exam_venue      =    "ExamVenue";
       
}

void HTMLTags :: ContentType()
{
    cout << "Content-type:text/html\n\n";
}

void HTMLTags :: HTMLStart()
{
    cout << "<html>" << endl;
}

void HTMLTags :: HTMLEnd()
{
    cout << "</html>" << endl;
}

void HTMLTags :: HeadStart()
{
    cout << "<head>" << endl;
}

void HTMLTags :: HeadEnd()
{
    cout << "</head>" << endl;
}

void HTMLTags :: BodyStart()
{
    cout << "<body align = \"center\">" << endl;
}

void HTMLTags :: BodyEnd()
{
    cout << "</body>" << endl;
}

void HTMLTags :: Title(string title)
{
    ProjectName = "BaKaPlan-Beta";
    cout << "<title>" << ProjectName << ": " << title << "</title>";
}

void HTMLTags :: CSS()
{
    cout << "<link rel=\"stylesheet\" type=\"text/css\" href=\"home.css\">" 
         << endl;
}


void HTMLTags :: Header()
{
    cout << "<div id = \"header\" >" << endl
//         << "<h1><a href=\"http://localhost/~mandy/cgi-bin/SP/home.html\"> BeSeated </h1></a>" << endl
         << "<h1> BakaPlan </h1>" << endl
         << "<div id = \"image\">" << endl
         << "<img src=\"../../SeatPlan/images/image.jpg\" "
         << "width=\"100%\" height=\"200\" alt=\"some_text\">" << endl
         << "</div>" << endl
         << "</div>" << endl;
}
