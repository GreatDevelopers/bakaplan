#include "subject-wise-rollno.h"

void SubjectWiseRollNo :: setSubCode()
{
   subject_size = 0;
   for(i = 0; i < total_branches; i++)
   {
      subject_size += total_subject[i];
   }
   i = 0;
   // Putting values of subject code into another array sub_subcode
   //for(i = 0; i < subject_size; i++)
   {
      for(j = 0; j < total_branches; j++)
      {
         for(k = 0; k < total_subject[j]; k++)
          {
            sub_subcode[i] = subject_code[j][k];
            i++;
         }
      }
   }
    
}

void SubjectWiseRollNo :: removeRedundantSubCode()
{
   // Removing redundancy from sub_subcode array
   total_code = total_branches;
       
   for(k = 0; k < total_code; k++)
   {
      for(i = k+1; i < total_code; i++)
      {
         if(sub_subcode[i] == sub_subcode[k])
         {
            for(j = i; j < total_code; j++)
            {
               sub_subcode[j] = sub_subcode[j+1];   
            }
            total_code--;  
         }
      }
   }
}

void SubjectWiseRollNo :: subjectWiseRollNo()
{
   setSubCode();
          
   removeRedundantSubCode();
       
   for(i = 0; i < total_code; i++)
   {
      sub_totalrno[i] = 0;
   }
    
   // Adding roll nos
   for(i = 0; i < total_branches; i++)
   {
      for(j = 0; j < total_code; j++)
      {
         for(l = 0; l < total_subject[i]; l++)
         {
            if(sub_subcode[j] == subject_code[i][l])
            {
               for(k = 0; k < roll_size[i][l]; k++)
               {
                  sub_rollno[j][(k + sub_totalrno[j])] = prefix_roll_no[i][l][k];
               }
               sub_totalrno[j] += roll_size[i][l];
            }
         }
      }
   }
    
}

void SubjectWiseRollNo :: showSubjectWiseRollNo()
{
   outfile.open(Subjectwise_Rollno_out);
   outfile << total_code << endl;
   for(i = 0; i < total_code; i++)//SizeOfArray(sub_rollno)
   {
      //        outfile<<'\n'<<sub_subcode[i]<<endl;
      outfile << sub_subcode[i] << endl << sub_totalrno[i] << ' ';
      
      for(j = 0; j < sub_totalrno[i]; j++)//SizeOfArray(sub_rollno[0])
         outfile<<sub_rollno[i][j]<<"\t";
      outfile<<endl;
   }
   outfile.close();
}

void SubjectWiseRollNo :: Main()
{
   ArrangeRollNo :: Main();
   subjectWiseRollNo();
   showSubjectWiseRollNo();
}
