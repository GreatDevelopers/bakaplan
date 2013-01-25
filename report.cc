#include "report.h"

Report :: Report()
{
    ContentType();
}

void Report :: Head()
{
    HeadStart();
    Title("Report");
    CSS();
    HeadEnd();
}

void Report :: BodyContent()
{
    cout << "<div id = \"body\" class = \"center\">" << endl;
         
    Header();
    
    cout << "<div id = \"content\" class = \"content\">" << endl
         
         << " <br> <br> <h2> Check File</h2> <br> <br>"
         
         << "<form name=\"report\" action=\"../../SeatPlan.html\" method=\"post\">"
         
         << "<br><input type=\"submit\" value=\"Check File\">"
         
         << "</form>"
         
         << "</div>" << endl
         << "</div>" << endl;
}

void Report :: Body()
{
    BodyStart();
    BodyContent();
    BodyEnd();
}


void Report :: Main()
{
    ReadExamDetails :: Main();
    HTMLStart();    
    
    Head();
    Body();
    
    HTMLEnd();
}
