#include "arrange-rollno.h"

class SubjectWiseRollNo : public ArrangeRollNo
{
   protected:
      
      int total_code, sub_totalrno[MIN_SIZE],
          subject_size;
    
      string sub_subcode[MIN_SIZE], sub_rollno[MIN_SIZE][MAX_SIZE];
      
   public:
      SubjectWiseRollNo(){cout << "Content-type:text/html\n\n"; total_code = 1;}  
      void subjectWiseRollNo();
      void setSubCode();
      void removeRedundantSubCode();
      void showSubjectWiseRollNo();
      void Main();
};
