#include "rollnodetails.h"

RollNoDetails :: RollNoDetails()
{
    ContentType();
    totalFields = 0;
}

void RollNoDetails :: Head()
{
    HeadStart();
    Title("RollNo Details");
    CSS();
    HeadEnd();
}

void RollNoDetails :: BodyContent()
{

    string rnoprefix[20] = {"IT", "CSE", "ECE", "ME", 
                             " ", "EE", " ", 
                             "E E", "CSci", "MBA", "P1", "p2", "P3", "P4", "p5"
                             "p6", "p7", " ", "p9", "910"};
                                 
    string startRollNo[20] = {"101", "201", "301", "401", "501", "601", "801", 
                              "901", "1001", "2001", "3001", "4001", "5001",
                              "6001", "7001", "8001", "9001", "10001"};
        
    string endRollNo[20] = {"121", "231", "351", "466", "509", "611", "851", 
                              "906", "1018", "2034", "3012", "4022", "5011",
                              "6013", "7035", "8075", "9012", "10011"};
                              
    string notIncluded[20] = {"111 120", "230", "311-320", "419 435", "503", "0", "840-844", 
                              "903", "1008", "2024", "3010", "4011-4014 4020", "5004",
                              "0", "7035", "8075", "9002 9005", "10008"};

    cout << "<div id = \"body\" class = \"center\">" << endl;
         
    Header();
    
    cout << "<div id = \"content\" class = \"content\">" << endl
         
         << "<br> <h3> Fill Roll No Details</h3> <br>"
         
         << "<form name=\"rollnodetails\" action=\"roomdetails.html\" method=\"post\">"         
         
         << "<table align = \"center\" cellpadding=\"5\" >"
         
         << "<tr>"
         << "<th> Branch Name </th>"
         << "<th> Subject Code </th>"
         << "<th> Prefix </th>"
         << "<th> Start Roll No. </th>"
         << "<th> End Roll No </th>"
         << "<th> Not Included </th>"
         << "<tr>";
         
    for(i = 0; i < totalBranches; i++)
    {
        for(j = 0; j < totalSubjects[i]; j++)
        {
            k = j + 1;
            cout << "<tr>";
            cout << "<td>" << branchName[i] << "</td>"
                 << "<td>" << subjectCode[i][j] << "</td>";
            
            cout << "<td><input type=\"text\" name=\"" << prefix << totalFields+1 << "\""
                 << " value = \"" << rnoprefix[totalFields] << "\" "
                 << " size = \"10\" >"
                 << "</td>"
                 << "<td><input type=\"text\" name=\"" << start_rollno << totalFields+1 << "\""
                 << " value = \"" << startRollNo[totalFields] << "\" "
                 << " size = \"10\" >"
                 << "</td>"
                 << "<td><input type=\"text\" name=\"" << end_rollno << totalFields+1 << "\""
                 << " value = \"" << endRollNo[totalFields] << "\" "
                 << " size = \"10\" >"
                 << "</td>"
                 << "<td><input type=\"text\" name=\"" << not_included << totalFields+1 << "\""
                 << " value = \"" << notIncluded[totalFields] << "\" "
                 << " size = \"10\" >"
                 << "</td>";
            
            cout << "</tr>";
            totalFields++;
        } 
    }     
    
    cout << "</table>";
    
    cout << "<br><input type=\"submit\" value=\"Next\">";
    
    cout << "</form>";
     
    cout << "</div>" << endl
         << "</div>" << endl;
    showTotalFields();
}

void RollNoDetails :: showTotalFields()
{
    outfile.open(TotalFields);
    outfile << totalFields;
    outfile.close();
}

void RollNoDetails :: Body()
{    
    BodyStart();
    BodyContent();
    BodyEnd();
}


void RollNoDetails :: Main()
{
    ReadBranchDetails :: Main();
    HTMLStart();    
    
    Head();
    Body();
    
    HTMLEnd();
}

