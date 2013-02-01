#include "rollnodetails.h"

ReadBranchDetails :: ReadBranchDetails()
{
    
}

void ReadBranchDetails :: readBranchDetails()
{    
    fi = formData.getElement(total_branches);  

    if( !fi->isEmpty() && fi != (*formData).end()) 
    {  
        temp = **fi;
        totalBranches = atoi(temp.c_str());  
    }
    
    for(i = 0; i < totalBranches; i++)
    {  
        branchName[i] = readField(branch_name, i);
        totalSubjects[i] = atoi(readField(total_subjects, i).c_str());
        subjectcode[i] = readField(subject_code, i);
        subjectname[i] = readField(subject_name, i);   
    }
    
}

string ReadBranchDetails :: readField(string fieldname, int i)
{
    std::stringstream no;
    string result;
    no << (i+1);
    temp = fieldname + no.str();
    fi = formData.getElement(temp);  
    if( !fi->isEmpty() &&fi != (*formData).end()) 
    {  
        result = **fi;  
    }
    else
    {
        result = " "; 
    }
    return result;
}

void ReadBranchDetails :: splitSujects()
{
    for(i = 0; i < totalBranches; i++)
    {
        int size = subjectcode[i].size() + 1;
        char largchar[size]; // = roll[i].c_str();//"1-10 12 34 15 20 25-30";
        j = 0; 
        strcpy(largchar, subjectcode[i].c_str());
        char* chars_array = strtok(largchar, ",");
        while(chars_array)
        {
           if(j < totalSubjects[i])
               subjectCode[i][j] =  chars_array;//atoi (chars_array));//n++;
           chars_array = strtok(NULL, ",");
           j++;
        }
    }
    
    for(i = 0; i < totalBranches; i++)
    {
        int size = subjectname[i].size() + 1;
        char largchar[size]; // = roll[i].c_str();//"1-10 12 34 15 20 25-30";
        j = 0; 
        strcpy(largchar, subjectname[i].c_str());
        char* chars_array = strtok(largchar, ",");
        while(chars_array)
        {
           if(j < totalSubjects[i])
               subjectName[i][j] =  chars_array;//atoi (chars_array));//n++;
           chars_array = strtok(NULL, ",");
           j++;
        }
    }
}

void ReadBranchDetails :: writeBranchDetails()
{
    outfile.open(BranchDetails_in);
    
    outfile << totalBranches << endl;
    
    for(i = 0; i < totalBranches; i++)
    {
        outfile << branchName[i] << endl
                << totalSubjects[i] << endl;
        for(j = 0; j < totalSubjects[i]; j++)
            outfile << subjectName[i][j] << endl
                    << subjectCode[i][j] << endl;
    }
    
    outfile.close();
}

void ReadBranchDetails :: Main()
{
    readBranchDetails();
    splitSujects();
    writeBranchDetails();
}
