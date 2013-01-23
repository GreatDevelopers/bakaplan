#include "htmltags.h"

class ReadRollNoDetails : public HTMLTags
{
    protected:
        int totalFields;
        
        string rnoPrefix[MIN_SIZE], startRollNo[MIN_SIZE], endRollNo[MIN_SIZE],
               notIncludedRollNo[MIN_SIZE];
               
        // cgicc variables nd objts
        Cgicc formData;
        form_iterator fi;
        
        // temp
        string temp;
    
    public:
        ReadRollNoDetails();
        void readRollNoDetails();
        string readField(string fieldname, int i);
        void writeRollNoDetails();
        void Main();
};

class RoomDetails : public ReadRollNoDetails
{
    protected:
    
    public:
        RoomDetails();
        void Head();
        void Javascript();
        void Body();
        void BodyContent();
        void Main();
};
