#include "htmltags.h"

class Validation : public HTMLTags
{
    protected:
        string strategyChoice;
        
        // cgicc variables nd objts
        Cgicc formData;
        form_iterator fi;
    
    public:
        Validation();
        void Head();
        void Javascript();
        void Body();
        void BodyContent();
        void readStrategy();
        void Main();
};
