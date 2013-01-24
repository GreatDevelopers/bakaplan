#include "validation.h"
#include "SeatPlan/strategy.h"

Validation :: Validation()
{
    ContentType();
}

void Validation :: readStrategy()
{
    fi = formData.getElement(strategy);  
    if( !fi->isEmpty() &&fi != (*formData).end()) 
    {  
        strategyChoice = **fi;  
    }
    
    outfile.open(Strategy_in);
    outfile << strategyChoice;
    outfile.close();
}

void Validation :: Head()
{
    HeadStart();
    Title("Validation");
    CSS();
    HeadEnd();
}

void Validation :: BodyContent()
{
    string next;
    cout << "<div id = \"body\" class = \"center\">" << endl;
         
    Header();
    
    cout << "<div id = \"content\" class = \"content\">" << endl
         
         << "<br><br><b>";
   
    infile.open(Validationout);
    
    string valid;
    while(infile.good())
    {
        getline(infile, valid);
        if(valid == "Y")
            next = "Y";
        else
        {
            cout << valid << "<br>" << endl;
        }
    }
    infile.close();
    
    if(next == "Y")
    {
        cout << "<br> <br>" 
             << "<form name=\"validation\" action=\"examdetails.html\" method=\"post\">" << endl 
             
             << "<br><input type=\"submit\" value=\"Next\">";
        
        cout << "</form>";
    }
    else
    {
        cout << "<br> <br>" 
             << "<form name=\"validation\" action=\"roomdetails.html\" method=\"post\">" << endl 
             
             << "<br><input type=\"submit\" value=\"Back\">";
        
        cout << "</form>";
    }
         
    cout << "</div>" << endl
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
    readStrategy();
    
    Strategy strat;
    strat.Main();
    
    HTMLStart();    
    
    Head();
    Body();
    
    HTMLEnd();
}
