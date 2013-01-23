#include "report.h"

Report :: Report()
{
    ContentType();
}

void Report :: Head()
{
    HeadStart();
    Title("Branch Details");
    CSS();
    HeadEnd();
}

void Report :: BodyContent()
{
    cout << "<div id = \"body\" class = \"center\">" << endl;
         
    Header();
    
    cout << "<div id = \"content\" class = \"content\">" << endl
         
         
         
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
    HTMLStart();    
    
    Head();
    Body();
    
    HTMLEnd();
}
