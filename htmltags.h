#include "header.h"

// Base class containong Basic Html Tags and methods
class HTMLTags
{
    protected:
    
    string ProjectName;
    int i, j, k;
    
    // branch field names
    string branch_name, total_subjects, subject_code, subject_name,
           total_branches;
    
    // roll no field names
    string prefix, start_rollno, end_rollno, not_included;
    
    // room field names
    string total_centres, centre_no, total_rooms, room_no, rows, cols;
    
    // strategy option
    string strategy;
    
    // Exam Details
    string exam_name, exam_time, exam_date, exam_venue;
    
    ifstream infile;
    ofstream outfile;
        
    public:
    
        HTMLTags();
        void HTMLStart();
        void HTMLEnd();
        void HeadStart();
        void HeadEnd();
        void BodyStart();
        void BodyEnd();
        void Title(string title);
        void ContentType();
        void Header();
        void CSS();
};
