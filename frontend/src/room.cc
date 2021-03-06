/**
 *       \file       room.cc
 *
 *       \brief      RoomDetail class definition
 *
 *       \version    0.8
 *       \date       Sunday 07 April 2013 08:17:36  IST\n
 *       Compiler    g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

/**
 *  Include room.h 
 */
#include "header/room.h"

/**
 *      \class  RoomDetail
 *      \fn     RoomDetail :: RoomDetail()
 *      \brief  Constructor
 */

RoomDetail :: RoomDetail()
{
    // constructor
    totalCols = 3;
    i = 0;
    tableHeading.resize(totalCols);
    tableHeading[i++] = "Centre Name";
    tableHeading[i++] = "Room No : Rows x Columns";
//    tableHeading[i++] = "Rows";
//    tableHeading[i++] = "Columns";
    tableHeading[i++] = "Delete Row";
}

/**
 *      \class  RoomDetail
 *      \fn     RoomDetail :: SetDEfaultValue()
 *      \brief  Setting default values for room detail if projec is
 *              new or old project ha no room detail in database
 */

void RoomDetail :: SetDefaultValue()
{
    totalCentres.resize(totalDays);
    centreName.resize(totalDays);
/*    roomNo.resize(totalDays);
    rows.resize(totalDays);
    columns.resize(totalDays);*/
    roomInfo.resize(totalDays);
    date.resize(totalDays);
    examCode.resize(totalDays);
 
    where = "ProjectID = " + projectID;      
    database.SelectColumn(vecTemp, "CentreName", 
                          "RoomDetail", where);
   
    if(projectType == "Old" && vecTemp.size() > 0)
    {
        {       
            for(i = 0; i < totalDays; i++)
            {
                vecTemp.clear();
                where = "ProjectID = " + projectID;
                where += " AND DateSheetID = " + IntToString(i + 1);
                database.SelectColumn(vecTemp, "CentreName",
                                      "RoomDetail", where);
                if(vecTemp.size() > 0)
                {
                    totalCentres[i] = vecTemp.size();
                    centreName[i].assign(vecTemp.begin(), 
                                         vecTemp.end());
                }
                else
                {
                    totalCentres[i] = 1;
                    centreName[i].resize(totalCentres[i]);
                    roomInfo[i].resize(totalCentres[i]);
/*                    roomNo[i].resize(totalCentres[i]);          
                    rows[i].resize(totalCentres[i]);
                    columns[i].resize(totalCentres[i]);*/
                }
                vecTemp.clear();
                database.SelectColumn(vecTemp, "RoomInfo",
                                      "RoomDetail", where);
                if(vecTemp.size() > 0)
                {
                    roomInfo[i].assign(vecTemp.begin(), 
                                         vecTemp.end());
                }
                vecTemp.clear();
                

/*                for(unsigned j = 0; j < centreName[i].size(); j++)
                {
                   // centreName[i][j] = vecTemp[j];
                    cout << centreName[i][j] << " "
                         << roomNo[i][j] << " "
                         << rows[i][j] << " "
                         << columns[i][j] << page.brk;
                }*/
            }
        }     
    }
    else
    {
        for(i = 0; i < totalDays; i++)
        {
            totalCentres[i] = 1;
        }
        for(i = 0; i < totalDays; i++)
        {
            for(j = 0; j < totalCentres[i]; j++)
            {
                centreName[i].resize(totalCentres[i]);
/*                 roomNo[i].resize(totalCentres[i]);
                rows[i].resize(totalCentres[i]);
                columns[i].resize(totalCentres[i]);*/
                roomInfo[i].resize(totalCentres[i]);
                centreName[i][j] = "Centre 1";
                roomInfo[i][j]   = "R1:6x6, R2:6x6";
/*                roomNo[i][j] =  "Room 1, Room 2";
                rows[i][j]   =  "6, 6";
                columns[i][j]=  "8, 8";*/
            }
        }
    }
}

/**
 *      \class  RoomDetail
 *      \fn     RoomDetail :: ReadDateSheet()
 *      \brief  Reading Date sheet I/P given by user
 */

void RoomDetail :: ReadDateSheet()
{
    page.ContentType();
 
    projectID = readField.ReadFieldValue(fieldName.projectID);
    projectType = readField.ReadFieldValue(fieldName.projectType);
    totalDays = StringToInt(readField.ReadFieldValue(
                            fieldName.totalDays));
    sameDetail = readField.ReadFieldValue(fieldName.sameDetail);
 
    rowIndex = readField.ReadFieldValue(fieldName.rowIndex);
    STRING_VEC index;
    SplitString(index, rowIndex, ",");
 
    date.resize(totalDays);
    examCode.resize(totalDays);
    centreName.resize(totalDays);
    roomNo.resize(totalDays);
    rows.resize(totalDays);
    columns.resize(totalDays);
  
    for(i = 0; i < totalDays; i++)
    {
        j = StringToInt(index[i]);
        date[i] = readField.ReadFieldValue(fieldName.date, j);
        examCode[i] = readField.ReadFieldValue(fieldName.examCode, j);
    }
   
    SetDefaultValue();
    WriteDateSheet();
    if(sameDetail == "Yes")// && projectType == "New")
    {
        totalDays = 1;
    }

    dateWiseRollNo.Main(projectID);
    RoomDetailPage(false);
}

/**
 *      \class  RoomDetail
 *      \fn     RoomDetail :: WriteDateSheet()
 *      \brief  Writing Date Sheet into database
 */

void RoomDetail :: WriteDateSheet()
{
    where = "ProjectID = " + projectID;
    database.SelectColumn(vecTemp, "Date", "DateSheet",
                          where);

    if(vecTemp.size() > 0 )
    {
        where = "ProjectID = " + projectID;
        database.DeleteQuery("DateSheet", where);
    }
        
    vecTemp.clear();
 
    for(i = 0; i < totalDays; i++)
    {
        database.InsertDateSheet(projectID, date[i], examCode[i]);
    }

    /* Write date sheet detail to i/p file */
    subCode.resize(totalDays);
    totalSubjects.resize(totalDays);
    for(i = 0; i < totalDays; i++)
    {
        SplitString(subCode[i], examCode[i], ",");
        totalSubjects[i] = subCode[i].size();
    }
    temp = FileName(DATESHEET, projectID, 1);
    outFile.open(temp.c_str());

    outFile << totalDays << endl;

    for(i = 0; i < totalDays; i++) 
    {
        trim(date[i]);
        
        outFile << date[i] << endl
                << totalSubjects[i] << endl;
        for(j = 0; j < totalSubjects[i]; j++)
        {
            trim(subCode[i][j]);
            outFile << subCode[i][j] << endl;
        }
    }

    outFile.close();
}

/**
 *      \class  RoomDetail
 *      \fn     RoomDetail :: RoomDetailPage()
 *      \brief  For Taking I/P from user of room details
 */

void RoomDetail :: RoomDetailPage(bool addRoom)
{
//    page.ContentType();

//    ReadDatesheet();

    Header("Room Detail");
    
    cout << cgicc :: div().set("id", "DivRoom")
                          .set("align", "center");
//    page.LogoutLink();

//    cout << page.brk;
    cout << h1() << "Room Detail" << h1();// << page.brk;
 
    if(addRoom == true)
    {
        cout << form().set("id", "FormRoom")
                      .set("action", "validstrategy")
                      .set("method", "POST")
                      .set("onsubmit", 
                           "return ValidateRoomForm('TotalDays')");

    }
    else
    {
        cout << form().set("id", "FormRoom")
                      .set("action", "exam")
                      .set("method", "POST")
                      .set("onsubmit", 
                           "return ValidateRoomForm('TotalDays')");

    }

   
    ErrorMessage(msg);

    page.InputField("hidden", fieldName.projectID, projectID);
    page.InputField("hidden", fieldName.totalDays, 
                    IntToString(totalDays));
    page.InputField("hidden", fieldName.projectType, projectType);
    page.InputField("hidden", fieldName.sameDetail, sameDetail);
    
    if(addRoom == true)
        page.InputField("hidden", "AddRoom", "True");

    for(i = 0; i < totalDays; i++)
    {
  /*      if(projectType == "Old" || 
            (projectType == "New" && sameDetail == "No"))*/
        if(sameDetail == "No")
        {

            cout << br();
            cout << "Date : " << date[i] 
                 << " Exam Code : " << examCode[i];
            page.InputField("hidden", 
                            (fieldName.date + IntToString(i + 1)), 
                             date[i]);
        }

        cout << br() << br();       
        temp = "AddRow";
        temp += IntToString(i + 1);

        string table = "AddRow('TableRoom" + IntToString(i + 1)
                       + "', 'TotalCentres" + IntToString(i + 1)
                       + "', 'room'," + IntToString(i + 1)
                       + ")";

        page.InputField("button", temp, table, "Add Row");
/*        temp = "DeleteRow";
        temp += IntToString(i + 1);
        
        table = "deleteRow('TableRoom" + IntToString(i + 1)
                + "', 'TotalCentres" + IntToString(i + 1)
                + "')";
 
        page.InputField("button", temp, table, "Delete Row");

*/
        cout << br() << br();
        temp = "TableRoom";
        temp += IntToString(i + 1);

        cout << cgicc :: table().set("id", temp.c_str());
        cout << tr();
        for(k = 0; k < totalCols; k++)
        {   
            cout << th() << tableHeading[k] << th();
        }
        cout << tr();

        temp = fieldName.totalCentres;
        temp += IntToString(i + 1);
        page.InputField("hidden", temp, IntToString(totalCentres[i]));
    
        rowIndex = "";

        for(j = 0; j < totalCentres[i]; j++)
        {
            rowIndex += IntToString(j + 1);
            if((j + 1) != totalCentres[i])
                rowIndex += ",";

            if(projectType == "Old")
            {
                cout << tr();
        
                cout << td();
                temp = IntToString(i + 1);
                temp += IntToString(j + 1);
                page.InputField("text", fieldName.centreName, 
                                StringToInt(temp),
                                centreName[i][j], centreName[i][j]);
                cout << td();
        
                cout << td();
                temp = IntToString(i + 1);
                temp += IntToString(j + 1);            
//                string roomValue = roomNo[i][j]// + " : " + rows[i][j] +
//                                   " x " + columns[i][j];

                page.InputField("text", fieldName.roomNo,
                                StringToInt(temp),
                                roomInfo[i][j], roomInfo[i][j]);
                cout << td();
 /*
                cout << page.startTD;
                temp  = IntToString(i + 1);
                temp += IntToString(j + 1);
                page.InputField("text", fieldName.rows,
                                StringToInt(temp),
                                rows[i][j], rows[i][j]);
                cout << page.endTD;
        
                cout << page.startTD;
                temp = IntToString(i + 1);
                temp += IntToString(j + 1);
                page.InputField("text", fieldName.columns, 
                                StringToInt(temp),
                                columns[i][j], columns[i][j]);
                cout << page.endTD;       
 */               
                cout << td();
                temp = "DelRow('" 
                       + (fieldName.rowIndex + IntToString(i + 1))  
                       + "', 'TotalCentres" 
                       + IntToString(i + 1) + "', event)";
                page.InputField("button", IntToString(j + 1), 
                                temp,
                                "Delete Row");
                cout << td();


                cout << tr();
            }
            else
            {
                cout << tr();
        
                cout << td();
                temp = IntToString(i + 1);
                temp += IntToString(j + 1);
                page.InputField("text", fieldName.centreName, 
                                StringToInt(temp),
                                centreName[i][j]);
                cout << td();
        
                cout << td();
                temp = IntToString(i + 1);
                temp += IntToString(j + 1);               
                page.InputField("text", fieldName.roomNo,
                                StringToInt(temp), roomInfo[i][j]);
                cout << td();
 /*
                cout << page.startTD;
                temp = IntToString(i + 1);
                temp += IntToString(j + 1);
                page.InputField("text", fieldName.rows,
                                StringToInt(temp),
                                rows[i][j]);
                cout << page.endTD;
        
                cout << page.startTD;
                temp = IntToString(i + 1);
                temp += IntToString(j + 1);
                page.InputField("text", fieldName.columns, 
                                StringToInt(temp),
                                columns[i][j]);
                cout << page.endTD;       
*/
                cout << td();
                temp = "DelRow('" 
                       + (fieldName.rowIndex + IntToString(i + 1))  
                       + "', 'TotalCentres" 
                       + IntToString(i + 1) + "', event)";
                
                page.InputField("button", IntToString(i + 1), 
                                temp,
                                "Delete Row");
                cout << td();

                cout << tr();
                    
            }
        }

        lastRow = IntToString(totalCentres[i]);
        page.InputField("hidden", 
                        (fieldName.lastRow + IntToString(i + 1)), 
                        lastRow);
        page.InputField("hidden", 
                        (fieldName.rowIndex + IntToString(i + 1)), 
                        rowIndex);
       
        cout << cgicc :: table();
    }

    cout << br() << br();

    page.Button("next", "submit", "btn", "NEXT");

    cout << form() << cgicc :: div();

    Footer();

}

void RoomDetail :: AddMoreRooms()
{
    page.ContentType();
 
    projectID = readField.ReadFieldValue(fieldName.projectID);
//    projectType = readField.ReadFieldValue(fieldName.projectType);
    totalDays = StringToInt(readField.ReadFieldValue(
                            fieldName.totalDays));
    sameDetail = readField.ReadFieldValue(fieldName.sameDetail);
    
    projectType = "Old";
    vecTemp.clear();
    where = "ProjectID = " + projectID;
    database.SelectColumn(date, "Date", "DateSheet", where);
    
    vecTemp.clear();
    database.SelectColumn(examCode, "ExamCode", "DateSheet", where);
    vecTemp.clear();
    SetDefaultValue();
    RoomDetailPage(true);
}

/**
 *      \class  RoomDetail
 *      \fn     RoomDetail :: ~RoomDetail()
 *      \brief  Destructor to de-allocate objects
 */

RoomDetail :: ~RoomDetail()
{
    // destructor
}
