#include "expand-rollno.h"

class ArrangeRollNo : public ExapandRollNo
{
   protected:
      int rno[MAX_SIZE], l, m;
      string prefix_roll_no[MIN_SIZE][MIN_SIZE][MAX_SIZE];
   
   public:
   
//      void arrangeInput();
      ArrangeRollNo(){}//cout << "Content-type:text/html\n\n";}
      void readRollNoRow(int, int);
      void setRollNoRow(int, int);
      void sortRollNo();
      void removeRedundancy();
      void removeNonEligibleRollNo();
      void addPrefixWithRollNo();
      void showArrangedRollNo();
      void Main(string projectID);
};
