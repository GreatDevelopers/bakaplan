#include "htmltags.h"

class BranchDetails : public HTMLTags
{
    protected:
//        string branchName[10] = {"Info. Tech.", "CSE", "ECE", "Mech. Engg.", 
//                                 "Production Engg.", "Electrical Engg.", "IT", 
//                                 "Electronics Engg.", "Comp. Sci. Engg.", "MBA"};
//                                 
//        string subjectCode[10] = {"DBMS, SAD", "Maths,Physics", "OS, EVS", 
//                                  "Java, C++", "EVS", "Chem.", "ED", "Maths",
//                                  "Maths,DBMS, Physics", "Multimedia, Dot Net, ED"};
//        
//        string subjectName[10] = {"IT-101, IT-102", "ME-10,CE-252", "EVS, ED-10",
//                                  "ED-10, IT-102", "IT-102", "IT-203", "CE-120",
//                                  "ME-140", "EE-109, 1234S, IT-203", "ME-101,ME-501,IT-101" };
        
    public:
        BranchDetails();
        void Head();
        void Javascript();
        void Body();
        void BodyContent();
        void Main();
};
