#include "htmltags.h"

class ReadBranchDetails : public HTMLTags
{
    protected:
        // for branch details
        int totalBranches, totalSubjects[MINS_SIZE];
        string branchName[MINS_SIZE], subjectName[MINS_SIZE][MINS_SIZE],
               subjectCode[MINS_SIZE][MINS_SIZE];
        // for splitSujects 
        string subjectcode[MINS_SIZE], subjectname[MINS_SIZE];
        
        // temp string
        string temp;
        
        // cgicc variables nd objts
        Cgicc formData;
        form_iterator fi;
        
        // total fields
        int totalFields;

    public:
        ReadBranchDetails();
        string readField(string, int);
        void readBranchDetails();
        void writeBranchDetails();
        void splitSujects();
        void Main();
};

class RollNoDetails : public ReadBranchDetails
{    
    public:
        RollNoDetails();
        void showTotalFields();
        void Head();
        void Javascript();
        void Body();
        void BodyContent();
        void Main();
};

