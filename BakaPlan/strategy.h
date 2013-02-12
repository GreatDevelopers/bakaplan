#include "htmltags.h"

class ReadRoomDetails : public HTMLTags
{
    protected:
        int totalCentres, totalRooms[MINS_SIZE];
        
        string centreNo[MINS_SIZE], roomNo[MINS_SIZE][MINS_SIZE], 
               roomRows[MINS_SIZE][MINS_SIZE], roomCols[MINS_SIZE][MINS_SIZE]; 
        
        // cgicc variables nd objts
        Cgicc formData;
        form_iterator fi;
        
        // temp
        string temp;    
        
        // Strategy Name
        string strategyName[MINS_SIZE];
        
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
