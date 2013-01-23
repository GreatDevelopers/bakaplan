#include "htmltags.h"

class ReadRoomDetails : public HTMLTags
{
    protected:
        int totalCentres, totalRooms[MIN_SIZE];
        
        string centreNo[MIN_SIZE], roomNo[MIN_SIZE][MIN_SIZE], 
               roomRows[MIN_SIZE][MIN_SIZE], roomCols[MIN_SIZE][MIN_SIZE]; 
        
        // cgicc variables nd objts
        Cgicc formData;
        form_iterator fi;
        
        // temp
        string temp;    
    public:
        ReadRoomDetails(){}
        void readRoomDetails();
        string readField(string, int);
        string readField(string, int, int);
        void writeRoomDetails();
        void Main();
};

class Strategy : public ReadRoomDetails
{
    protected:
    
    public:
        Strategy();
        void Head();
        void Javascript();
        void Body();
        void BodyContent();
        void Main();
};
