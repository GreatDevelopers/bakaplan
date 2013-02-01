#include "report.h"
#include "SeatPlan/report.h"

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
         
         << " <br> <br> <h2> HTML File for Room Report </h2> <br> <br>"
         
         << "<form name=\"report\" action=\"../../../seatplan.html\" method=\"post\">"
         
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
    RoomReport report;
    report.Main();
    
    HTMLStart();    
    
    Head();
    Body();
    
    HTMLEnd();
}
