#include "examdetails.h"

ExamDetails :: ExamDetails()
{
    ContentType();
}

void ExamDetails :: Head()
{
    HeadStart();
    Title("Exam Details");
    CSS();
    HeadEnd();
}

void ExamDetails :: BodyContent()
{
    cout << "<div id = \"body\" class = \"center\">" << endl;
         
    Header();
    
    cout << "<div id = \"content\" class = \"content\">" << endl
    
         << "<pre>"
         << "<h3><br><br>Enter Examimation Details</h3></br> " << endl
         
         << "<form name=\"branch\" action=\"report.html\" method=\"post\">"
         
//         exam_name, exam_time, exam_date, exam_venue;
         
         << "<br> <br> Examination Name  "
         << "<input type=\"text\" name=\"" << exam_name << "\""
         << "value = \" May 2013 \">"
         
         << "<br> <br> Examination Date  "
         << "<input type=\"text\" name=\"" << exam_date << "\""
         << "value = \" 12-05-2013 \">"
         
         << "<br> <br> Examination Time  "
         << "<input type=\"text\" name=\"" << exam_time << "\""
         << "value = \" 9:30am - 12:30pm \">"
         
         << "<br> <br> Examination Venue  "
         << "<input type=\"text\" name=\"" << exam_venue << "\""
         << "value = \" MBA Block \">"
         
         
         << endl;         
        
    cout << "<br> <br> <button id = \"next\" class=\"btn\" type=\"submit\">NEXT</button>"//<input type=\"submit\" value=\"NEXT\">"
         
         << "</form>"
         << "</pre>"
         << "</div>" << endl
         << "</div>" << endl;
}

void ExamDetails :: Body()
{
    BodyStart();
    BodyContent();
    BodyEnd();
}


void ExamDetails :: Main()
{
    HTMLStart();    
    
    Head();
    Body();
    
    HTMLEnd();
}
