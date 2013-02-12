#include "roomdetails.h"

RoomDetails :: RoomDetails()
{
    ContentType();
}

void RoomDetails :: Head()
{
    HeadStart();
    Title("Room Details");
    CSS();
    HeadEnd();
}

void RoomDetails :: BodyContent()
{

    string row[9] = {"7", "6", "6", "6", "7", "7", "7", "7", "7"};
    string col[9] = {"3", "6", "4", "6", "6", "6", "6", "4", "4"};

    cout << "<div id = \"body\" class = \"center\">" << endl;
         
    Header();
    
    cout << "<div id = \"content\" class = \"content\">" << endl
         << "<pre>"
         << "<br>"
         << "<form name=\"roomdetails\" action=\"strategy.html\" method=\"post\">" << endl 
         << "<h3> Fill Room Details </h3> <br>" << endl      
         << "<br>"
         << "Total Centres <select name=\"" << total_centres << "\">";
         
    for(i = 1; i <= 3; i++)
    {
         cout << "<option value=\""
              << i << "\" ";
         if(i == 2)
            cout << "selected";     
         cout << " > "
              << i << "</option>";
    }
//    total_centres, centre_no, total_rooms, room_no, rows, cols
    cout << "</select>"
         << "<br><br>";
         
    for(i = 0; i < 3; i++)
    {
        cout << "Centre Name " 
             << "<input type=\"text\" name=\"" << centre_no << (i+1) << "\""
             << "value = \"Centre " << (i+1) << "\">"
             << "    Total Rooms " << "<select name=\"TotalRooms" << (i+1) << "\">";
            for(k = 1; k <= 10; k++)
            {
                cout << "<option value=\""
                     << k << "\" ";
                if(k == 4)
                    cout << "selected";     
                cout << " > "
                     << k << "</option>";
            }   
        cout << "</select>"
             << "<br><br>"
             << "<table align = \"center\" cellpadding=\"5\" >"
         
             << "<tr>"
             << "<th> Room No </th>"
             << "<th> Rows </th>"
             << "<th> Cols </th>"
             << "<tr>";
        for(j = 0; j < 10; j++)
        {
            cout << "<tr>";
            
            cout << "<td><input type=\"text\" name=\"" << room_no << (i+1) << (j+1) 
                 << "\""
                 << " value = \"Room" << (j+1) << "\" "
                 << ">"
                 << "</td>"
                 << "<td><input type=\"text\" name=\"" << rows << (i+1) << (j+1) 
                 << "\""
                 << " value = \"" << row[j] << "\" "
                 << ">"
                 << "</td>"
                 << "<td><input type=\"text\" name=\"" << cols << (i+1) << (j+1) 
                 << "\""
                 << " value = \"" << col[j] << "\" "
                 << ">"
                 << "</td>";
            
            cout << "</tr>";
        }
        cout << "<table>" << endl;
        cout << "<br><br>" << endl;
    }
    cout << "<br>"//"<input type=\"submit\" value=\"Next\">";
         << "<button id = \"next\" class=\"btn\" type=\"submit\">NEXT</button>";
    
    cout << "</form>";
    cout << "</pre>" << endl;    
    cout << "</div>" << endl
         << "</div>" << endl;
}

void RoomDetails :: Body()
{
    BodyStart();
    BodyContent();
    BodyEnd();
}

void RoomDetails :: Main()
{
    ReadRollNoDetails :: Main();    
    
    HTMLStart();    
    
    Head();
    Body();
    
    HTMLEnd(); 
}
