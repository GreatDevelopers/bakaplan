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
}

/**
 *--------------------------------------------------------------------\n
 *       Class:  RoomDetail \n
 *      Method:  RoomDetail :: ReadTotalRoom() \n
 * Description:  Read total rooms in each cetre \n
 *--------------------------------------------------------------------
 */

void RoomDetail :: ReadTotalRoom()
{

}

/**
 *--------------------------------------------------------------------\n
 *       Class:  RoomDetail \n
 *      Method:  RoomDetail :: ReadRoomDetail() \n
 * Description:  Read room details like rows, columns of room \n
 *--------------------------------------------------------------------
 */

void RoomDetail :: ReadRoomDetail()
{

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
        InputField("text", fieldName.centreName, (i+1), "");
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

}

RoomDetail :: ~RoomDetail()
{
    // Destructor
}

