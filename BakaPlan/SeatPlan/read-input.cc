#include "read-input.h"

void ReadInput :: readRollNoInput(string file)
{
   infile.open(file.c_str());
//   infile >> total_branches;
   for(i = 0; i < total_branches; i++)
   {
      for(j = 0; j < total_subject[i]; j++)
      {
         getline(infile, prefix[i][j], '\n'); 
         getline(infile, string_rollno[i][j], '\n');
         getline(infile, str_not_included_rollno[i][j], '\n');
      }
   }
   infile.close();
}

void ReadInput :: readRoomsInput(string file)
{
   infile.open(file.c_str());
   infile >> total_centres;
//   getline(infile, centre_no[0], '\n');
   for(i = 0; i < total_centres; i++)
   {
      getline(infile, centre_no[i], '\n');
      getline(infile, centre_no[i], '\n');
      infile >> total_rooms[i];
//      getline(infile, room_no[i][0], '\n');
      for (j = 0; j < total_rooms[i]; j++)
      {
         getline(infile, room_no[i][j], '\n');
         getline(infile, room_no[i][j], '\n');
         infile >> rows[i][j] >> cols[i][j];
      }
   }
   infile.close();
}

void ReadInput :: readBranchDetails(string file)
{
   infile.open(file.c_str());
   infile >> total_branches;
   getline(infile, branch_name[0], '\n');
   for(i = 0; i < total_branches; i++)
   {
      getline(infile, branch_name[i], '\n');
      infile >> total_subject[i];
      getline(infile, subject_name[i][0], '\n');   
      for(j = 0; j < total_subject[i]; j++)
      {
         getline(infile, subject_name[i][j], '\n');
         getline(infile, subject_code[i][j], '\n');
      }
   }
   infile.close();
}


void ReadInput :: showDetails()
{
   outfile.open(Checking);
   outfile << "total_branches" << endl;
//   cout << total_branches;
   outfile << total_branches << endl;
   for(i = 0; i < total_branches; i++)
   {
      outfile << branch_name[i] << endl;
      outfile << total_subject[i] << endl;
      for(j = 0; j < total_subject[i]; j++)
      {
         outfile << subject_code[i][j] << endl;
      }
   }
   
   // room_no
   outfile << "----------------room details--------------------" << endl;
   outfile << total_centres << endl;
   for(i = 0; i < total_centres; i++)
   {
      outfile << centre_no[i] << endl;
      outfile << total_rooms[i] << endl;
      for (j = 0; j < total_rooms[i]; j++)
      {
         outfile << room_no[i][j];
         outfile << " " << rows[i][j] << " " << cols[i][j] << endl;
      }
   }
   
   outfile << "================roll no===============" << endl;
   for(i = 0; i < total_branches; i++)
   {
      for(j = 0; j < total_subject[i]; j++)
      {
         outfile << prefix[i][j] << endl;
         outfile << string_rollno[i][j] << endl;
         outfile << str_not_included_rollno[i][j] << endl;
      }
   }
   
   outfile.close();
}

void ReadInput :: Main()
{
   readBranchDetails(Input_BranchDetails);
   readRoomsInput(Input_Rooms);
   readRollNoInput(Input_Rollno);
//   showDetails();  // For Checking purpose
}
