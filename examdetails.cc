#include "examdetails.h"

ExamDetails :: ExamDetails()
{
    ContentType();
}

void ExamDetails :: Head()
{
    HeadStart();
    Title("Branch Details");
    CSS();
    HeadEnd();
}

void ExamDetails :: BodyContent()
{
    cout << "<div id = \"body\" class = \"center\">" << endl;
         
    Header();
    
    cout << "<div id = \"content\" class = \"content\">" << endl
         
         
         
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
