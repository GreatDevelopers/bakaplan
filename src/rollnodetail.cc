/*
 * ===================================================================
 *
 *       Filename:  rollnodetail.cc
 *
 *    Description:  Definition of RollNoDetail's member functions.
 *
 *        Version:  0.6
 *        Created:  Saturday 16 February 2013 11:17:41  IST
 *       Compiler:  gcc
 *
 *         Author:  Mandeep Kaur, meghasimak@gmail.com
 *        License:  GNU General Public License
 *      Copyright:  Copyright (c) 2013, Great Developers
 *
 * ===================================================================
 */

/**-------------------------------------------------------------------
 *  Include rollnodetails.h for RollNoDetail class declaration
 *------------------------------------------------------------------*/

#include "rollnodetail.h"

/**-------------------------------------------------------------------
 *  Definition of functions RollNoDetail Class
 *------------------------------------------------------------------*/

/**
 *--------------------------------------------------------------------
 *       Class:  RollNoDetail
 *      Method:  RollNoDetail :: RollNoDetail()
 * Description:  Constructor
 *--------------------------------------------------------------------
 */

RollNoDetail :: RollNoDetail()
{
    i = 0;
    tableHeading[i++] = "Class Name";
    tableHeading[i++] = "Subject Code";
    tableHeading[i++] = "Prefix";
    tableHeading[i++] = "Start Roll No";
    tableHeading[i++] = "End Roll No";
    tableHeading[i++] = "Not Included";
    
    i = 0;
    prefix[i++] = "IT";
    prefix[i++] = "CSE";
    prefix[i++] = "101";
    prefix[i++] = "2001";
    prefix[i++] = "E 11";
    prefix[i++] = "MBA";
    prefix[i++] = "Mtech";
    prefix[i++] = "A";
    prefix[i++] = "B";
    prefix[i++] = "D1";
    prefix[i++] = "P1";
    prefix[i++] = "P2";
    prefix[i++] = "P3";
    prefix[i++] = "P4";
    prefix[i++] = "P5";

    i = 0;
    startRollNo[i++] = "101";
    startRollNo[i++] = "201";
    startRollNo[i++] = "301";
    startRollNo[i++] = "401";
    startRollNo[i++] = "501";
    startRollNo[i++] = "601";
    startRollNo[i++] = "701";
    startRollNo[i++] = "801";
    startRollNo[i++] = "901";
    startRollNo[i++] = "1001";
    startRollNo[i++] = "1201";
    startRollNo[i++] = "1301";
    startRollNo[i++] = "1401";
    startRollNo[i++] = "1501";
    startRollNo[i++] = "1101";
    
    i = 0;
    endRollNo[i++] = "110";
    endRollNo[i++] = "210";
    endRollNo[i++] = "310";
    endRollNo[i++] = "410";
    endRollNo[i++] = "510";
    endRollNo[i++] = "610";
    endRollNo[i++] = "710";
    endRollNo[i++] = "810";
    endRollNo[i++] = "910";
    endRollNo[i++] = "1010";
    endRollNo[i++] = "1110";
    endRollNo[i++] = "1210";
    endRollNo[i++] = "1310";
    endRollNo[i++] = "1410";
    endRollNo[i++] = "1510";

    i = 0;
    notIncluded[i++] = "105";
    notIncluded[i++] = "206";
    notIncluded[i++] = "305, 307";
    notIncluded[i++] = "405";
    notIncluded[i++] = "505";
    notIncluded[i++] = "605";
    notIncluded[i++] = "";
    notIncluded[i++] = "802-805";
    notIncluded[i++] = "905";
    notIncluded[i++] = "1005";
    notIncluded[i++] = "1105";
    notIncluded[i++] = "1205";
    notIncluded[i++] = "0";
    notIncluded[i++] = "1405";
    notIncluded[i++] = "1505";

}

/**
 *--------------------------------------------------------------------
 *       Class:  RollNoDetail
 *      Method:  RollNoDetail :: ReadClassDetails()
 * Description:  For reading class details from previous page
 *--------------------------------------------------------------------
 */

void RollNoDetail :: ReadClassDetail()
{

    projectID = readField.ReadFieldValue(fieldName.projectID);

    string where = "ProjectID = ";
    where += projectID;
    database.SelectQuery("TotalClasses", "TotalClasses", temp, where); 
    
    totalClasses = StringToInt(temp);

    for(i = 0; i < totalClasses; i++)
    {
        j = i + 1;
        
        className[i] = readField.ReadFieldValue(fieldName.className, 
                                                j);

        subName[i] = readField.ReadFieldValue(fieldName.subjectName, 
                                              j);
      
        subCode[i] = readField.ReadFieldValue(fieldName.subjectCode, 
                                              j);
    }
    
    SplitSubject();
           
    /*        temp  = "Select ProjectID from ClassDetails ";
        temp += "where ProjectID = " + projectID + ";";
        string t;
        database.Select(t);
          if(temp == "T")
          { //projectID = "3";
            temp  = "Delete from ClassDetails where ProjectID = ";
            temp += projectID + ";";

            database.DeleteQuery(temp);
        }
     */
    for(i = 0; i < totalClasses; i++)
    {
        database.InsertClassDetail(projectID, className[i], 
                                   IntToString(totalSubjects[i]), 
                                   subName[i], subCode[i]);
    }

    WriteClassDetail();
}

/**
 *      \class  RollNoDetail
 *      \fn     RollNoDetail :: WriteClassDetail()
 *      \brief  For creating I/P file of class details
 */

void RollNoDetail :: WriteClassDetail()
{
    fileName  = FOLDER;
    fileName += PID + projectID + CLASS_DETAILS_IN;
    outFile.open(fileName.c_str());

    outFile << totalClasses << endl;

    for(i = 0; i < totalClasses; i++)
    {
        
        outFile << className[i] << endl
                << totalSubjects[i] << endl;
        for(j = 0; j < totalSubjects[i]; j++)
        {
            outFile << subjectName[i][j] << endl
                    << subjectCode[i][j] << endl;
        }

    }

    outFile.close();
}

/**
 *--------------------------------------------------------------------\n
 *       Class:  RollNoDetail \n
 *      Method:  RollNoDetail :: SplitSubject() \n
 * Description:  Split subjects \n
 *--------------------------------------------------------------------
 */

void RollNoDetail :: SplitSubject()
{
    //totalClasses = 1;
    for(i = 0; i < totalClasses; i++)
    {
        int size = subName[i].size() + 1;
        char largchar[size];
        j = 0; 
        strcpy(largchar, subName[i].c_str());
        char* chars_array = strtok(largchar, ",");
        while(chars_array)
        {
            subjectName[i][j] =  chars_array;
            chars_array = strtok(NULL, ",");
            j++;
            totalSubjects[i] = j;
        }
    }

    for(i = 0; i < totalClasses; i++)
    {
        int size = subCode[i].size() + 1;
        char largchar[size];
        j = 0; 
        strcpy(largchar, subCode[i].c_str());
        char* chars_array = strtok(largchar, ",");
        while(chars_array)
        {
            if(j <= totalSubjects[i])
                subjectCode[i][j] =  chars_array;
            chars_array = strtok(NULL, ",");
            j++;
        }
    }
}

/**
 *--------------------------------------------------------------------\n
 *       Class:  RollNoDetail \n
 *      Method:  RollNoDetail :: RollNoDetailPage() \n
 * Description:   \n
 *--------------------------------------------------------------------
 */

void RollNoDetail :: RollNoDetailPage()
{
    //ReadClassDetail();
    ContextType();
    Header("Roll No Detail");
    
    DivStart("totalclasses", "");               /* (id, classname) */
    ReadClassDetail();
    LogoutLink();
    
    cout << brk;

    FormStart("rollno", "totalcentre.html", "POST");

    InputField("hidden", fieldName.projectID, projectID);

    cout << startH1 << " Roll No. Detail " << endH1 << brk;
    
    TableStart("rollno", "");
    
    cout << startTR;
    for( i = 0; i < 6; i++)
    {
        cout << startTH << tableHeading[i] << endTH;
    }
    cout << endTR;
    k = 1;
    for(i = 0; i < totalClasses; i++)
    {        
        for(j = 0; j < totalSubjects[i]; j++)
        {
            cout << startTR;
            cout << startTD << className[i];
            InputField("hidden", fieldName.className, (k), 
                       className[i]);
            
            cout << endTD;
                 
            cout << startTD << subjectCode[i][j];
            InputField("hidden", fieldName.subjectCode, (k), 
                       subjectCode[i][j]);

            cout << endTD;
            
            cout << startTD;
            InputField("text", fieldName.prefix, (k), prefix[k-1]);
            cout << endTD;

            cout << startTD;
            InputField("text", fieldName.startRollNo, k, 
                        startRollNo[k-1]);
            cout << endTD;
            
            cout << startTD;
            InputField("text", fieldName.endRollNo, k, endRollNo[k-1]);
            cout << endTD; 

            cout << startTD;
            InputField("text", fieldName.notIncluded, k, 
                        notIncluded[k-1]);
            cout << endTD;
            cout << endTR;
            k++;
        }
    }
    
    TableEnd();

    cout << brk << brk;

    Button("next", "submit", "btn", "NEXT");

    FormEnd();
    DivEnd();

    Footer();
 
}
