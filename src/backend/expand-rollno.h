#include "read-input.h"

class ExapandRollNo : public ReadInput
{
   protected:
      int roll_no[MIN_SIZE][MAX_SIZE][MAX_SIZE], roll_size[MIN_SIZE][MIN_SIZE], 
      not_roll_no[MIN_SIZE][MAX_SIZE][MAX_SIZE], not_roll_size[MIN_SIZE][MIN_SIZE];
      
   public:
      void expandInput();
      ExapandRollNo(){}//cout << "Content-type:text/html\n\n";}  
      void addSeperator();
      void expandRollNo();//string);
      template<typename OutIter>
      bool expandRollNumberList(istream& is, OutIter out);
      void removeZero();
      void showExpandRollNo();
      void Main(string);
};
