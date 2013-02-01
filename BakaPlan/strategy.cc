#include "strategy.h"
#include "SeatPlan/subject-wise-rollno.h"

Strategy :: Strategy()
{
    ContentType();
}

void Strategy :: Head()
{
    HeadStart();
    Title("Strategy");
    CSS();
    HeadEnd();
}

void Strategy :: BodyContent()
{
    cout << "<div id = \"body\" class = \"center\">" << endl;
         
    Header();
    
    cout << "<div id = \"content\" class = \"content\">" << endl
    
         << "<form name=\"strategy\" action=\"validation.html\" method=\"post\">"
         
         << "<br> <br><h2> Select Strategy </h2> <br> <br>"
         
         << "<table align = \"center\" cellspacing = \"10\" cellpadding = \"10\">"
         
         << "<tr> <th> A </th> <th> B </th> <th> C </th> <th> D </th> </tr>"
         
         << "<tr> "
         
         << " <td> Subject Code 1 <br> Subject Code 1 <br> Subject Code 1 <br> Subject Code 1</td> "
         
         << " <td> Subject Code 1 <br> Subject Code 2 <br> Subject Code 1 <br> Subject Code 2 </td> "
         
         << " <td> Subject Code 1 <br> Subject Code 2 <br> Subject Code 3 <br> Subject Code 1</td> "
         
         << " <td> Subject Code 1 <br> Subject Code 2 <br> Subject Code 3 <br> Subject Code 4</td> "
         
         << "</tr>"
         
         << "</table>"
         
         << "<br><br>";
        cout << "Select Option <select name=\"" << strategy << "\">"; 
        for(i = 65; i < 69; i++)
        {
            char a = i;
            cout << "<option value=\""
                 << a << "\"";
            cout << " > "
                 << a << "</option>";
        }
        cout << "</select>";
    
    cout << "<br><br>"//"<input type=\"submit\" value=\"NEXT\">"
         << "<button id = \"next\" class=\"btn\" type=\"submit\">NEXT</button>"
         
         << "</form>"
         
         << "</div>" << endl
         << "</div>" << endl;
}

void Strategy :: Body()
{
    BodyStart();
    BodyContent();
    BodyEnd();
}

void Strategy :: Main()
{
    ReadRoomDetails :: Main();
    
    
    SubjectWiseRollNo subject;
    subject.Main();

    HTMLStart();    
    
    Head();
    Body();
    
    HTMLEnd();
}
