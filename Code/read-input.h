#include "header.h"

// Reading input files

class ReadInput
{
   protected:
      
      // Room Variables
      int total_centres, total_rooms[MIN_SIZE], rows[MIN_SIZE][MIN_SIZE], 
          cols[MIN_SIZE][MIN_SIZE];
      string room_no[MIN_SIZE][MIN_SIZE], centre_no[MIN_SIZE];
      
      // Roll No details
      int total_branches;
      string branch_name[MIN_SIZE], string_rollno[MIN_SIZE][MIN_SIZE], 
             str_not_included_rollno[MIN_SIZE][MIN_SIZE],
             prefix[MIN_SIZE][MIN_SIZE];
      
      // Subject Code Variables
      int total_subject[MIN_SIZE];
      string subject_code[MIN_SIZE][MIN_SIZE], subject_name[MIN_SIZE][MIN_SIZE];
      
      // Loop variables
      int i, j, k;
      
      // File variables
      ifstream infile;
      ofstream outfile;
      
   public:
      ReadInput(){cout << "Content-type:text/html\n\n";} 
      void readRoomsInput(string);  // Rooms details
      void readRollNoInput(string); // Roll No Details
      void readBranchDetails(string); // Subject code Details
      void showDetails();  // for checking purpose
      void Main();
};
