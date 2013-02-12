#include "expand-rollno.h"

void ExapandRollNo :: expandInput()
{
   readBranchDetails(Input_BranchDetails);
   readRoomsInput(Input_Rooms);
   readRollNoInput(Input_Rollno);
}

void ExapandRollNo :: addSeperator()
{
   string a="0";
   
   for(i = 0; i < total_branches; i++)
   {
      for(j = 0; j < total_subject[i]; j++)
      {
        { // adding seperratotr in rollno
            int size = string_rollno[i][j].size() + 1;
            char largchar[size]; // = roll[i].c_str();//"1-10 12 34 15 20 25-30";
            
            strcpy(largchar, string_rollno[i][j].c_str());
            char* chars_array = strtok(largchar, " ");
            a="0";
            while(chars_array)
            {
               if(chars_array!="-")
                  {
                  a.append(",");
                  a.append(chars_array);//atoi (chars_array));//n++;
               }
               chars_array = strtok(NULL, " ");
            }
            string_rollno[i][j] = a;
         }
         
         // adding seperratotr in not included roll nos.
         if(str_not_included_rollno[i][j].compare("0") != 0)
         {
            int size = str_not_included_rollno[i][j].size() + 1;
            char largchar[size]; // = roll[i].c_str();//"1-10 12 34 15 20 25-30";
            
            strcpy(largchar, str_not_included_rollno[i][j].c_str());
            char* chars_array = strtok(largchar, " ");
            a="0";
            while(chars_array)
            {
               if(chars_array!="-")
               {
                  a.append(",");
                  a.append(chars_array);//atoi (chars_array));//n++;
               }
               chars_array = strtok(NULL, " ");
            }
            str_not_included_rollno[i][j] = a;
         }
      }
   }
}

void ExapandRollNo :: expandRollNo()//string rollno)
{
   outfile.open(Rollno_Expand_out);
   
   // expanding roll nos
   for(i = 0; i < total_branches; i++)
   {
      for(j = 0; j < total_subject[i]; j++)
      {
         istringstream rollno(string_rollno[i][j]);
         deque<int> v;
         
         bool success = expandRollNumberList(rollno, back_inserter(v));
         
         if (success)
         {
            roll_size[i][j] = v.size()-1;
            copy(v.begin(), v.end()-1, ostream_iterator<int>(outfile, " "));
   
            outfile << v.back() << endl;
            }
         else
            outfile << "an error occured." << endl;
            
         // expanding not included roll nos
//         if(str_not_included_rollno[i][j] != " ")
         {
            istringstream rollno(str_not_included_rollno[i][j]);
            deque<int> v;
            
            bool success = expandRollNumberList(rollno, back_inserter(v));
            
            if (success)
            {
               not_roll_size[i][j] = v.size()-1;
               copy(v.begin(), v.end()-1, ostream_iterator<int>(outfile, " "));
      
               outfile << v.back() << endl;
            }
            else
               outfile << "an error occured." << endl;
         }
      }
   }
   outfile.close();
}

template<typename OutIter>
bool ExapandRollNo :: expandRollNumberList(istream& is, OutIter out)
{
   int number;
   // the list always has to start with a number
   while (is >> number)
   {
      *out++ = number;

      char c;
      if (is >> c)
         switch(c)
         {
            case ',':
               continue;
            case '-':
            {
               int number2;
               if (is >> number2)
               {
                  if (number2 < number)
                     return false;
                  while (number < number2)
                     *out++ = ++number;
                  char c2;
                  if (is >> c2)
                     if (c2 == ',')
                        continue;
                     else
                        return false;
                  else
                     return is.eof();
               }
               else
                  return false;
            }
            default:
               return is.eof();
         }
      else
         return is.eof();
   }
   // if we get here, something went wrong (otherwise we would have
   // returned from inside the loop)
   return false;
}

void ExapandRollNo :: removeZero()
{
   infile.open(Rollno_Expand_out);
   
   for(i = 0; i < total_branches; i++)
   {
      for(j = 0; j < total_subject[i]; j++)
      {
         for(k = 0; k < roll_size[i][j] + 1; k++)
            infile >> roll_no[i][j][k];
            
         for(k = 0; k < not_roll_size[i][j] + 1; k++)
            infile >> not_roll_no[i][j][k];
      }
   }
   
   infile.close();
   
   for(i = 0; i < total_branches; i++)
   {
      for(j = 0; j < total_subject[i]; j++)
      {
         for(k = 0; k < roll_size[i][j]; k++)
         {
            roll_no[i][j][k] = roll_no[i][j][k+1];
         }
//         roll_size[i][j]--;
         
         for(k = 0; k < not_roll_size[i][j]; k++)
         {
            not_roll_no[i][j][k] = not_roll_no[i][j][k+1];
         }
//         not_roll_size[i][j]--;
      }
   }
}

void ExapandRollNo :: showExpandRollNo()
{
   outfile.open(Rollno_Expand_out);
   outfile << total_branches << endl;
   for(i = 0; i < total_branches; i++)
   {
      for(j = 0; j < total_subject[i]; j++)
      {
         outfile << roll_size[i][j] << endl;
         for(k = 0; k < roll_size[i][j]; k++)
            outfile << roll_no[i][j][k] << " ";
         outfile << endl;
         
         outfile << not_roll_size[i][j] << endl;
         
         if(not_roll_size[i][j] != 0)
         {  
            for(k = 0; k < not_roll_size[i][j]; k++)
               outfile << not_roll_no[i][j][k] << " ";
            outfile << endl;
         }
         
      }
   }
   outfile.close();
}

void ExapandRollNo :: Main()
{
//   ReadInput :: Main();
    expandInput();
   addSeperator();
   expandRollNo();
   removeZero();
   showExpandRollNo();
}
