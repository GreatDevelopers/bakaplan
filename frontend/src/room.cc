/**
 *       \file       room.cc
 *
 *       \brief      RoomDetail class definition
 *
 *       \version    0.6
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
    totalCols = 4;
    i = 0;
    tableHeading.resize(totalCols);
    tableHeading[i++] = "Centre Name";
    tableHeading[i++] = "Room No.";
    tableHeading[i++] = "Rows";
    tableHeading[i++] = "Columns";
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
    roomNo.resize(totalDays);
    rows.resize(totalDays);
    columns.resize(totalDays);
 
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
                    roomNo[i].resize(totalCentres[i]);          
                    rows[i].resize(totalCentres[i]);
                    columns[i].resize(totalCentres[i]);
                }
                vecTemp.clear();
                database.SelectColumn(vecTemp, "RoomNo",
                                      "RoomDetail", where);
                if(vecTemp.size() > 0)
                {
                    roomNo[i].assign(vecTemp.begin(), 
                                         vecTemp.end());
                }
                vecTemp.clear();
                database.SelectColumn(vecTemp, "Rows",
                                      "RoomDetail", where);
                if(vecTemp.size() > 0)
                {
                    rows[i].assign(vecTemp.begin(), 
                                         vecTemp.end());
                }
                vecTemp.clear();
                database.SelectColumn(vecTemp, "Columns",
                                      "RoomDetail", where);
                if(vecTemp.size() > 0)
                {
                    columns[i].assign(vecTemp.begin(), 
                                         vecTemp.end());
                }

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
                roomNo[i].resize(totalCentres[i]);
                rows[i].resize(totalCentres[i]);
                columns[i].resize(totalCentres[i]);

                centreName[i][j] = "Centre 1";
                roomNo[i][j] =  "Room 1, Room 2";
                rows[i][j]   =  "6, 6";
                columns[i][j]=  "8, 8";
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

    date.resize(totalDays);
    examCode.resize(totalDays);
    centreName.resize(totalDays);
    roomNo.resize(totalDays);
    rows.resize(totalDays);
    columns.resize(totalDays);
 
    for(i = 0; i < totalDays; i++)
    {
        j = i + 1;
        date[i] = readField.ReadFieldValue(fieldName.date, j);
        examCode[i] = readField.ReadFieldValue(fieldName.examCode, j);
    }
  
    SetDefaultValue();
    WriteDateSheet();
    if(sameDetail == "Yes")// && projectType == "New")
    {
        totalDays = 1;
    }

    RoomDetailPage();
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

void RoomDetail :: RoomDetailPage()
{
//    page.ContentType();

//    ReadDatesheet();

    Header("Room Detail");

    page.DivStart("DivRoom", "");

    page.LogoutLink();

    cout << page.brk;

    page.FormStart("FormRoom", "exam.html", "POST");

    cout << page.startH1 << "Room Detail" 
         << page.endH1 << page.brk;
    
    ErrorMessage(msg);

    page.InputField("hidden", fieldName.projectID, projectID);
    page.InputField("hidden", fieldName.totalDays, 
                    IntToString(totalDays));
    page.InputField("hidden", fieldName.projectType, projectType);
    page.InputField("hidden", fieldName.sameDetail, sameDetail);
    
    for(i = 0; i < totalDays; i++)
    {
  /*      if(projectType == "Old" || 
            (projectType == "New" && sameDetail == "No"))*/
        if(sameDetail == "No")
        {

            cout << page.brk;
            cout << "Date : " << date[i] 
                 << " Exam Code : " << examCode[i];
            page.InputField("hidden", 
                            (fieldName.date + IntToString(i + 1)), 
                             date[i]);
        }

        cout << page.brk << page.brk;       
        temp = "AddRow";
        temp += IntToString(i + 1);

        string table = "addRow('TableRoom" + IntToString(i + 1)
                       + "', 'TotalCentres" + IntToString(i + 1)
                       + "', 'room'," + IntToString(i + 1)
                       + ")";

        page.InputField("button", temp, table, "Add Row");
        temp = "DeleteRow";
        temp += IntToString(i + 1);
        
        table = "deleteRow('TableRoom" + IntToString(i + 1)
                + "', 'TotalCentres" + IntToString(i + 1)
                + "')";
 
        page.InputField("button", temp, table, "Delete Row");


        cout << page.brk << page.brk;
        temp = "TableRoom";
        temp += IntToString(i + 1);

        page.TableStart(temp, "");
        cout << page.startTR;
        for(k = 0; k < totalCols; k++)
        {   
            cout << page.startTH << tableHeading[k] << page.endTH;
        }
        cout << page.endTR;

        temp = fieldName.totalCentres;
        temp += IntToString(i + 1);
        page.InputField("hidden", temp, IntToString(totalCentres[i]));

        for(j = 0; j < totalCentres[i]; j++)
        {
            if(projectType == "Old")
            {
                cout << page.startTR;
        
                cout << page.startTD;
                temp = IntToString(i + 1);
                temp += IntToString(j + 1);
                page.InputField("text", fieldName.centreName, 
                                StringToInt(temp),
                                centreName[i][j], centreName[i][j]);
                cout << page.endTD;
        
                cout << page.startTD;
                temp = IntToString(i + 1);
                temp += IntToString(j + 1);               
                page.InputField("text", fieldName.roomNo,
                                StringToInt(temp),
                                roomNo[i][j], roomNo[i][j]);
                cout << page.endTD;
 
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
                cout << page.endTR;
            }
            else
            {
                cout << page.startTR;
        
                cout << page.startTD;
                temp = IntToString(i + 1);
                temp += IntToString(j + 1);
                page.InputField("text", fieldName.centreName, 
                                StringToInt(temp),
                                centreName[i][j]);
                cout << page.endTD;
        
                cout << page.startTD;
                temp = IntToString(i + 1);
                temp += IntToString(j + 1);               
                page.InputField("text", fieldName.roomNo,
                                StringToInt(temp),
                                roomNo[i][j]);
                cout << page.endTD;
 
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
                cout << page.endTR;
                    
            }

        }
        
        page.TableEnd();
    }

    cout << page.brk << page.brk;

    page.Button("next", "submit", "btn", "NEXT");

    page.FormEnd();
    page.DivEnd();

    Footer();

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
