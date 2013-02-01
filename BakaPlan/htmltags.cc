#include "htmltags.h"

HTMLTags :: HTMLTags()
{
    // branch field names
    branch_name     =    "BranchName";
    total_subjects  =    "TotalSubjects";
    subject_code    =    "SubjectCode";
    subject_name    =    "SubjectName";
    total_branches  =    "TotalBranches";
    
    // table header branch field names
    h_branch_name     =    "Branch Name";
    h_total_subjects  =    "Total Subjects";
    h_subject_code    =    "Subject Code";
    h_subject_name    =    "Subject Name";
    h_total_branches  =    "Total Branches";
    
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
    cout << "<body>" << endl;
}

void HTMLTags :: BodyEnd()
{
    cout << "</body>" << endl;
    
//    cout << "<script src=\"http://code.jquery.com/jquery-latest.js\"></script>"
//         << "<script src=\"~public_html/BaKaPlan/bootstrap/js/bootstrap.min.js\"></script>";  
}

void HTMLTags :: Title(string title)
{
    ProjectName = "BaKa Plan-Beta";
    cout << "<title>" << ProjectName << ": " << title << "</title>";
}

void HTMLTags :: CSS()
{
    cout << "<link href=\"~/public_html/BaKaPlan/bootstrap/css/bootstrap.css\""
         << " rel=\"stylesheet\" media=\"screen\">" 
//    cout << "<link rel=\"stylesheet\" type=\"text/css\" href=\"home.css\">" 
         << endl;
}


void HTMLTags :: Header()
{
    cout << "<div id = \"header\" class=\"page-header\">" << endl
//         << "<a class=\"brand\" href=\"#\"> Baka Plan<sup>Beta</sup> </a>"
         << "<h1> Baka Plan<sup>Beta</sup> </h1>" << endl
         << "</div>" << endl;
}
