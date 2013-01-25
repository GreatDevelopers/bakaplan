#include "arrange-rollno.h"

//void ArrangeRollNo :: arrangeInput()
//{
//   infile.open(Rollno_Expand_out);
//   infile >> total_branches;
//   for(i = 0; i < total_branches; i++)
//   {
//      infile >> roll_size[i];
//      for(j = 0; j < roll_size[i]; j++)
//         infile >> roll_no[i][j];
//   }
//}

void ArrangeRollNo :: readRollNoRow(int i, int m)
{
//   for(m = 0; m < total_subject[i]; m++)
//   {
      for(j = 0; j < roll_size[i][m]; j++)
      {
         rno[j] = roll_no[i][m][j];
      }
//   }
}

void ArrangeRollNo :: setRollNoRow(int i, int m)
{
//   for(m = 0; m < total_subject[i]; m++)
//   {
      for(j = 0; j < roll_size[i][m]; j++)
      {
         roll_no[i][m][j] = rno[j];
      }
//   }
}

void ArrangeRollNo :: sortRollNo()
{
   for(i = 0; i < total_branches; i++)
   {
      for(m = 0; m < total_subject[i]; m++)
      {
         readRollNoRow(i,m);      
         sort(rno, rno + roll_size[i][m]);
         setRollNoRow(i,m);
      }
   }
}

void ArrangeRollNo :: removeRedundancy()
{
   for(i = 0; i < total_branches; i++)
   {
      for(m = 0; m < total_subject[i]; m++)
      {
         readRollNoRow(i,m);
               
         for(j = 0; j < roll_size[i][m]; j++)
         {	
            // Removing duplicate values
            if(rno[j] == rno[j+1])// || rno[j+1]==rno[j+2])
            {
               for(k = j; k <= roll_size[i][m]; k++) 
               {
                     rno[k] = rno[k+1];  //shifts each element one position above
        			}
               roll_size[i][m]--;
               j=0;
            }
         }
      
         setRollNoRow(i,m);
      }
   }
}

void ArrangeRollNo :: removeNonEligibleRollNo()
{

   for(i = 0; i < total_branches; i++)
   {
      for(j = 0; j < total_subject[i]; j++)
      {
         for(k = 0; k < not_roll_size[i][j]; k++)
         {
            for(l = 0; l < roll_size[i][j]; l++)
            {
               if(not_roll_no[i][j][k] == roll_no[i][j][l])
               {
                  for(m = l; m < roll_size[i][j]; m++)
                  {
                     roll_no[i][j][m] = roll_no[i][j][m+1]; 
                  }
                  roll_size[i][j]--;
               }
            }
         }
      }
   }

//   for(i = 0; i < total_branches; i++)
//   {
//      readRollNoRow(i);
//            
//      for(j = 0; j < roll_size[i][m]; j++)
//      {
//         if(rno[j] < 0)	
//         {
//            int a,b;
//            a = rno[j];
//            b = -1 * a;
//         
//            for(k = 0; k < roll_size[i][m]; k++)
//            {
//               if(rno[k] == a || rno[k] == b)
//               {
//                  for (l = k; l <= roll_size[i][m]; l++) 
//                     rno[l] = rno[l+1];  //shifts each element one position above
//                     
//                  roll_size[i][m]--;
//               }
//            }
//            j--;
//         }      
//      }
//      
//      setRollNoRow(i);
//   }
}

void ArrangeRollNo :: addPrefixWithRollNo()
{
   for(i = 0; i < total_branches; i++)
   {
      for(j = 0; j < total_subject[i]; j++)
      {
         for(k = 0; k < roll_size[i][j]; k++)
         {
            std::stringstream srno;
            srno << roll_no[i][j][k];
            prefix_roll_no[i][j][k] = prefix[i][j] + srno.str();
         }
      }
   }
}

void ArrangeRollNo :: showArrangedRollNo()
{
   outfile.open(Rollno_Arranged_out);
   outfile << total_branches << endl;
   for(i = 0; i < total_branches; i++)
   {
      for(j = 0; j < total_subject[i]; j++)
      {
         outfile << roll_size[i][j] << endl;
         for(k = 0; k < roll_size[i][j]; k++)
            outfile << prefix_roll_no[i][j][k] << " ";
         outfile << endl;
      }
   }
   outfile.close();
   
   outfile.open(Input_Rollno_out);
   outfile << total_branches << endl;
   for(i = 0; i < total_branches; i++)
   {
      outfile << branch_name[i] << endl << total_subject[i] << endl;
      for(j = 0; j < total_subject[i]; j++)
      {
         outfile << subject_name[i][j] << endl;
         outfile << subject_code[i][j] << endl;
         outfile << roll_size[i][j] << endl;
         for(k = 0; k < roll_size[i][j]; k++)
            outfile << prefix_roll_no[i][j][k] << " ";
         outfile << endl;
      }
   }
   outfile.close();
   
}

void ArrangeRollNo :: Main()
{
   ExapandRollNo::Main();
   sortRollNo();
   removeRedundancy();
   removeNonEligibleRollNo();
   addPrefixWithRollNo();
   showArrangedRollNo();
}
