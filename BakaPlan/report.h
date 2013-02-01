#include "htmltags.h"

class ReadExamDetails : public HTMLTags
{
    protected:
    
        // exam details 
        string examName, examDate, examTime, examVenue;
    
        // cgicc variables nd objts
        Cgicc formData;
        form_iterator fi;
        
        // temp
        string temp;
        
    public:
    
        void readExamDetails();
        void writeExamDetails();
        string readField(string);
        void Main();
    
};

class Report : public ReadExamDetails
{
    protected:
    
    public:
        Report();
        void Head();
        void Javascript();
        void Body();
        void BodyContent();
        void Main();
};
