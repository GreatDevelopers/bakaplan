#include "validation.h"

Validation :: Validation()
{
    ContentType();
}

void Validation :: readStrategy()
{
    
}

void Validation :: Head()
{
    HeadStart();
    Title("Branch Details");
    CSS();
    HeadEnd();
}

void Validation :: BodyContent()
{
    cout << "<div id = \"body\" class = \"center\">" << endl;
         
    Header();
    
    cout << "<div id = \"content\" class = \"content\">" << endl
         
         
         
         << "</div>" << endl
         << "</div>" << endl;
}

void Validation :: Body()
{
    BodyStart();
    BodyContent();
    BodyEnd();
}


void Validation :: Main()
{
    HTMLStart();    
    
    Head();
    Body();
    
    HTMLEnd();
}
