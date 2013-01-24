#include "htmltags.h"

class ReadRollNoDetails : public HTMLTags
{
    protected:
        int totalFields;
        
        string rnoPrefix[MINS_SIZE], startRollNo[MINS_SIZE], endRollNo[MINS_SIZE],
               notIncludedRollNo[MINS_SIZE];
               
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
