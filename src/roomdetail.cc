/*
 * ===================================================================
 *
 *       Filename:  roomdetails.cc
 *
 *    Description:  Definition of member functions of RoomDetail
 *    Class.
 *
 *        Version:  0.6
 *        Created:  Saturday 16 February 2013 11:19:40  IST
 *       Compiler:  gcc
 *
 *         Author:  Mandeep Kaur, meghasimak@gmail.com
 *        License:  GNU General Public License
 *      Copyright:  Copyright (c) 2013, Great Developers
 *
 * ===================================================================
 */

/**-------------------------------------------------------------------\n
 *  include roomdetail.h \n
 *------------------------------------------------------------------*/

#include "roomdetail.h"

/**
 *--------------------------------------------------------------------\n
 *       Class:  RoomDetail \n
 *      Method:  RoomDetail :: RoomDetail() \n
 * Description:  Constructor \n
 *--------------------------------------------------------------------
 */

RoomDetail :: RoomDetail()
{
    // Constructor
    maxCentres = 5;
}

/**
 *--------------------------------------------------------------------\n
 *       Class:  RoomDetail \n
 *      Method:  RoomDetail :: ReadRollNoDetail() \n
 * Description:  Read roll no details given by user \n
 *--------------------------------------------------------------------
 */

void RoomDetail :: ReadRollNoDetail()
{
    projectID = readField.ReadFieldValue(fieldName.projectID);

    database.SelectSum("TotalSubjects", "ClassDetails", 
                       projectID, temp);

    totalCentre = StringToInt(temp);
  
    for( i = 0; i < totalCentre; i++)
    {
        j = i + 1;
       
        className[i] = readField.ReadFieldValue(
                                              fieldName.className, j);

        subjectCode[i] = readField.ReadFieldValue(
                                            fieldName.subjectCode, j);

        prefix[i] = readField.ReadFieldValue(fieldName.prefix, j);

        startRollNo[i] = readField.ReadFieldValue(
                                            fieldName.startRollNo, j);

        endRollNo[i] = readField.ReadFieldValue(fieldName.endRollNo, 
                                                j);

        notIncluded[i] = readField.ReadFieldValue(
                                            fieldName.notIncluded, j);
  
        database.InsertRollNoDetail(projectID, className[i], 
                                    subjectCode[i], prefix[i], 
                                    startRollNo[i], endRollNo[i],
                                    notIncluded[i]);

    }
}
        
/**
 *--------------------------------------------------------------------\n
 *       Class:  RoomDetail \n
 *      Method:  RoomDetail :: ReadTotalCentre() \n
 * Description:  Read total centres for examination \n
 *--------------------------------------------------------------------
 */

void RoomDetail :: ReadTotalCentre()
{
    temp = readField.ReadFieldValue(fieldName.totalCentres);

    totalCentre = StringToInt(temp);

    projectID = readField.ReadFieldValue(fieldName.projectID);

    database.InsertTotalCentres(projectID, IntToString(totalCentre));

}

/**
 *--------------------------------------------------------------------\n
 *       Class:  RoomDetail \n
 *      Method:  RoomDetail :: ReadCentreDetail() \n
 * Description:  Read total rooms in each cetre \n
 *--------------------------------------------------------------------
 */

void RoomDetail :: ReadCentreDetail()
{
    projectID = readField.ReadFieldValue(fieldName.projectID);
    
    totalCentre = StringToInt(readField.ReadFieldValue(
                              fieldName.totalCentres));
    
    for(i = 0; i < totalCentre; i++)
    {
        j = i + 1;
        centreName[i] = readField.ReadFieldValue(fieldName.centreName, j);
        
        totalRoom[i] = StringToInt(readField.ReadFieldValue(
                            fieldName.totalRooms, j));

        database.InsertTotalRooms(projectID, centreName[i], 
                                IntToString(totalRoom[i]));
    }



}

/**
 *--------------------------------------------------------------------\n
 *       Class:  RoomDetail \n
 *      Method:  RoomDetail :: TotalCentrePage() \n
 * Description:  Page for taking i/p from user \nme
 *--------------------------------------------------------------------
 */

void RoomDetail :: TotalCentrePage()
{
    maxCentres = 5;

    ContextType();

    Header("Total Centre");
    
    DivStart("totalcentre", "");               /* (id, classname) */

    LogoutLink();
    
    cout << brk;

    ReadRollNoDetail();

    FormStart("totalcemtre", "centredetail.html", "POST");
    
    InputField("hidden", fieldName.projectID, projectID);

    cout << startH1 << " Select Total Centres " << endH1 << brk;
    
    cout << " Total Centres ";

    SelectFieldStart(fieldName.totalCentres);
        
    for(i = 1; i <= maxCentres; i++)
    {
        temp = IntToString(i);
        if(i == 3)
            SelectOptionStart(temp, "Y");
        else
            SelectOptionStart(temp, "n");
        cout << i;
        SelectOptionEnd();
    }

    SelectFieldEnd();

    cout << brk << brk;

    Button("next", "submit", "btn", "NEXT");

    FormEnd();
    DivEnd();



    Footer();
}

/**
 *--------------------------------------------------------------------\n
 *       Class:  RoomDetail \n
 *      Method:  RoomDetail :: CentreDetailPage() \n
 * Description:  Page for getting total  \n
 *--------------------------------------------------------------------
 */
void RoomDetail :: CentreDetailPage()
{
    maxCentres = 5;
    ContextType();

    Header("Centre Detail");
    
    DivStart("totalroom", "");               /* (id, classname) */

    LogoutLink();

    ReadTotalCentre();
    
    cout << brk;

    FormStart("totalroom", "roomdetail.html", "POST");
    
    InputField("hidden", fieldName.projectID, projectID);
    InputField("hidden", fieldName.totalCentres, 
               IntToString(totalCentre));

    cout << startH1 << " Centre Detail " << endH1 << brk;
    
    TableStart("centredetail", "");
   
    cout << startTH << "Centre Name" << endTH
         << startTH << "Total Rooms" << endTH;
   
    for(i = 0; i < totalCentre; i++)
    {
        cout << startTR;
        cout << startTD;
        temp  = "C";
        temp += IntToString((i+1));
        InputField("text", fieldName.centreName, (i+1), temp);
        cout << endTD;
        
        cout << startTD;
        temp = fieldName.totalRooms;
        temp += IntToString((i+1));
        SelectFieldStart(temp);
        
        for(j = 1; j <= maxCentres; j++)
        {
            temp = IntToString(j);
            if(j == 3)
                SelectOptionStart(temp, "Y");
            else
                SelectOptionStart(temp, "n");
            cout << j;
            SelectOptionEnd();
        }

        SelectFieldEnd();
        cout << endTD;
        cout << endTR;

    }
    TableEnd();

    cout << brk << brk;

    Button("next", "submit", "btn", "NEXT");

    FormEnd();
    DivEnd();

    Footer();

}

/**
 *--------------------------------------------------------------------\n
 *       Class:  RoomDetail \n
 *      Method:  RoomDetail :: RoomDetailPage() \n
 * Description:  Page for taking i/p from user about room details \n
 *--------------------------------------------------------------------
 */

void RoomDetail :: RoomDetailPage()
{
    maxCentres = 5;
    ContextType();

    Header("Room Detail");
    
    DivStart("roomdetail", "");               /* (id, classname) */

    LogoutLink();

    ReadCentreDetail();
    
    cout << brk;

    FormStart("roomdetail", "strategy.html", "POST");
    
    InputField("hidden", fieldName.projectID, projectID);

    cout << startH1 << " Room Detail " << endH1 << brk;
    
    TableStart("roomdetail", "");
   
    cout << startTH << " Centre Name " << endTH
         << startTH << " Room No. " << endTH
         << startTH << " Rows " << endTH
         << startTH << " Columns " << endTH;
    k = 1;

    for(i = 0; i < totalCentre; i++)
    {
        for( j = 0; j < totalRoom[i]; j++)
        {
            cout << startTR;
            
            cout << startTD;
            cout << centreName[i];
            InputField("hidden", fieldName.centreName, k, 
                        centreName[i]);
            cout << endTD;

            cout << startTD;
            temp  = "R";
            temp += IntToString(k);
            InputField("text", fieldName.roomNo, k, temp);
            cout << endTD;

            cout << startTD;
            InputField("text", fieldName.rows, k, "6");
            cout << endTD;

            cout << startTD;
            InputField("text", fieldName.columns, k, "8");
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

RoomDetail :: ~RoomDetail()
{
    // Destructor
}

