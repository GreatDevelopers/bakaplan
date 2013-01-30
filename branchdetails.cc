#include "branchdetails.h"

BranchDetails :: BranchDetails()
{
    ContentType();    
}

void BranchDetails :: Head()
{
    HeadStart();
    Title("Branch Details");
    CSS();
    HeadEnd();
}

void BranchDetails :: BodyContent()
{
    const int maxBranches = 10;

    string branchName[maxBranches] = {"Info. Tech.", "CSE", "ECE", "Mech. Engg.", 
                             "Production Engg.", "Electrical Engg.", "IT", 
                             "Electronics Engg.", "Comp. Sci. Engg.", "MBA"};
                                 
    string subjectName[maxBranches] = {"DBMS, SAD", "Maths,Physics", "OS, EVS", 
                              "Java, C++", "EVS", "Chem.", "ED", "Maths",
                              "Maths,DBMS, Physics", "Multimedia, Dot Net, ED"};
        
    string subjectCode[maxBranches] = {"IT-101, IT-102", "ME-10,CE-252", "EVS, ED-10",
                              "ED-10, IT-102", "IT-102", "IT-203", "CE-120",
                              "ME-140", "EE-109, 1234S, IT-203", "ME-101,ME-501,IT-101" };

    cout << "<div id = \"body\" class = \"center\">" << endl;
         
    Header();
    
    cout << "<div id = \"content\" class = \"content\">" << endl
         
         << "<pre>"
         
         // Input fields
         << "<h3><br><br>Enter Branch Details</h3></br> " << endl
         
         << "<form name=\"branch\" action=\"rollnodetails.html\" method=\"post\">"
         
         << "Total Branches <select name=\"TotalBranches\">";
         
    for(i = 1; i <= maxBranches; i++)
    {
        cout << "<option value=\""
             << i << "\"";
        if(i == 6)
            cout << "selected";
        cout << " > "
             << i << "</option>";
    }
    
    cout << "</select>"
         << "<br><br>"
         
         << "<table align = \"center\" cellpadding=\"5\" >"
         
         << "<tr>"
         
//         << "<th>Branch Name</th>"
//         << "<th width = \"30\">Total Subjects</th>"
//         << "<th>Subject Name</th>"
//         << "<th>Subject Code</th>"
         
         << "<th>" << h_branch_name << "</th>"
         << "<th width = \"30\">" << h_total_subjects << "</th>"
         << "<th>" << h_subject_code << "</th>"
         << "<th>" << h_subject_name << "</th>"
         
         << "</tr>";
//         << "<br><br>"
    for(j = 0; j < maxBranches; j++)
    {     
        cout << "<tr>"
             << "<td>"
             << "<input type=\"text\" name=\"" << branch_name << j+1 << "\""
             << "value = \" "<< branchName[j] << "\" size = \"17\">"
             << "</td>"
             
             << "<td>"
             << "<select name=\"" << total_subjects << j+1 << "\">";
             
         
        for(i = 1; i <= 3; i++)
        {
            cout << "<option value=\""
                 << i << "\"";
            if(j >= 0 && j <= 3 && i == 2)
                cout << " selected ";
            if(j >= 4 && j <= 7 && i == 1)
                cout << " selected ";
            if(j == 8 || j == 9 && i == 3)
                cout << " selected ";
            
            cout << " > "
                 << i
                 << "</option>";
        }
        cout << "</select>  "
             << "</td>"
             
             << "<td>"
             << "<input type=\"text\" name=\"" << subject_name << j+1 << "\""
             << "value = \" "<< subjectName[j] << "\">"
             << "</td>"
             
             << "<td>"
             << "<input type=\"text\" name=\"" << subject_code << j+1 << "\""
             << "value = \" "<< subjectCode[j] << "\">"
             << "</td>"
             
             << "</tr>";
//             << "<br><br>";
    }   
    
    cout << "</table>"
         << "<br><br>";
    
    cout << "<input type=\"submit\" value=\"NEXT\">"
         
         << "</form>"
         
         << "</pre>"
         
         << "</div>" << endl
         << "</div>" << endl;
}

void BranchDetails :: Body()
{
    BodyStart();
    BodyContent();
    BodyEnd();
}

void BranchDetails :: Main()
{
    HTMLStart();    
    
    Head();
    Body();
    
    HTMLEnd();
}
