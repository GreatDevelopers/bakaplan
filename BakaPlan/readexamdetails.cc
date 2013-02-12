#include "report.h"

void ReadExamDetails :: readExamDetails()
{
    examName = readField(exam_name);
    examDate = readField(exam_date);
    examTime = readField(exam_time);
    examVenue = readField(exam_venue);
}

void ReadExamDetails :: writeExamDetails()
{
    outfile.open(ExamDetails_in);
    
    outfile << examName << endl
            << examDate << endl
            << examTime << endl
            << examVenue << endl;
    
    outfile.close();
}

string ReadExamDetails :: readField(string fieldname)
{
    string result;
    temp = fieldname;
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

void ReadExamDetails :: Main()
{
    readExamDetails();
    writeExamDetails();
}
