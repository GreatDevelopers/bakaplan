/**
 *       \file       exam.cc
 *
 *       \brief      ExamDetail Class func. definition
 *
 *       \version    0.7
 *       \date       Sunday 07 April 2013 08:04:21  IST\n
 *       Compiler    g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

/**
 *  Include exam.h 
 */
#include "header/exam.h"

/**
 *      \class  ExamDetail
 *      \fn     ExamDetail :: ExamDetail()
 *      \brief  Constructor
 */

ExamDetail :: ExamDetail()
{
    // constructor
    totalCols = 6;
    tableHeading.resize(totalCols);
    i = 0;
    tableHeading[i++] = "Date";
    tableHeading[i++] = "Name";
    tableHeading[i++] = "Session";
    tableHeading[i++] = "Start Time";
    tableHeading[i++] = "End Time";
    tableHeading[i++] = "Venue";
}

/**
 *      \class  ExamDetail
 *      \fn     ExamDetail :: SetDefaultValue()
 *      \brief  Setting Default values for exam fields if projecy is
 *              new or old project has empty detail in database
 */

void ExamDetail :: SetDefaultValue()
{
    where = "ProjectID = " + projectID;
    database.SelectColumn(examName, "ExamName", "ExamDetail", 
                          where);

    if(projectType == "Old" && examName.size() > 0)
    {
        database.SelectColumn(examSession, "ExamSession", 
                              "ExamDetail", where);
        database.SelectColumn(examTime, "ExamTime", 
                              "ExamDetail", where);
        database.SelectColumn(examVenue, "ExamVenue", 
                              "ExamDetail", where);
        if(examName.size() < unsigned(totalDays))
        {
            j = totalDays - examName.size() + 1;
            
            examName.resize(totalDays);
            examSession.resize(totalDays);
            examTime.resize(totalDays);
            examVenue.resize(totalDays);
            date.resize(totalDays);
//            cout << totalDays;
            for(i = j; i < totalDays; i++)
            {
                examName[i] = "";
                examSession[i] = "";
                examTime[i] = "";
                examVenue[i] = "";
            }
           
        }
    }
    else
    {
        examName.resize(totalDays);
        examSession.resize(totalDays);
        examTime.resize(totalDays);
        examVenue.resize(totalDays);
        date.resize(totalDays);

        for(i = 0; i < totalDays; i++)
        {
            examName[i] = "Examination Name";
            examSession[i] = "M/E";
            examTime[i] = "9:30 am - 12:30 pm";
            examVenue[i] = "Venue/Place of Exam";
        }
    }
}

/**
 *      \class  ExamDetail
 *      \fn     ExamDetail :: ReadRoomDetail()
 *      \brief  Reading room details from previous page
 */

void ExamDetail :: ReadRoomDetail()
{
    page.ContentType();

    projectID = readField.ReadFieldValue(fieldName.projectID);
    projectType = readField.ReadFieldValue(fieldName.projectType);
    totalDays = StringToInt(readField.ReadFieldValue(
                            fieldName.totalDays));
    sameDetail = readField.ReadFieldValue(fieldName.sameDetail);
 
    totalCentres.resize(totalDays);
    centreName.resize(totalDays);
    roomNo.resize(totalDays);
    rows.resize(totalDays);
    columns.resize(totalDays);
    date.resize(totalDays);
    roomInfo.resize(totalDays);

    for(i = 0; i < totalDays; i++)
    {
        j = i + 1;
        totalCentres[i] = StringToInt(readField.ReadFieldValue(
                          fieldName.totalCentres, j ));
        if(sameDetail == "No")
            date[i] = readField.ReadFieldValue("Date", j);

        rowIndex = readField.ReadFieldValue(fieldName.rowIndex, j);
        STRING_VEC index;
//      index.resize(totalDays);
        SplitString(index, rowIndex, ",");

        for(j = 0; j < totalCentres[i]; j++)
        {
            temp1 = IntToString(i + 1) + index[j];//IntToString(j + 1);

            centreName[i].resize(totalCentres[i]);
            roomInfo[i].resize(totalCentres[i]);
            roomNo[i].resize(totalCentres[i]);
            rows[i].resize(totalCentres[i]);
            columns[i].resize(totalCentres[i]);
 
            temp  = fieldName.centreName + temp1;
            centreName[i][j] = readField.ReadFieldValue(temp);
 
            temp = fieldName.roomNo + temp1;
            roomInfo[i][j] = readField.ReadFieldValue(temp);
            
/*            temp = fieldName.rows + temp1;
            rows[i][j] = readField.ReadFieldValue(temp);

            temp = fieldName.columns + temp1;
            columns[i][j] = readField.ReadFieldValue(temp);*/
//            SplitString(roomInfo[i], roomNo[i][j], ",");
        }
    }

    // Split roomInfo to roomNo, row and column

    for(i = 0; i < totalDays; i++)
    {
        for(j = 0; j < totalCentres[i]; j++)
        {
/*             roomNo[i][j] = "";
            rows[i][j] = "";
            columns[i][j] = "";*/
            temp = roomInfo[i][j];  // R1:6x6, R2:6x8
//            cout << temp;
            STRING_VEC room1;
            int a = 0, b = 0;
            SplitString(room1, temp, ",");
            for(unsigned k = 0; k < room1.size(); k++)
            {
                temp = room1[k];
                STRING_VEC room2;
                SplitString(room2, temp, ":");  // R1:6x6
                for(unsigned l = 0; l < room2.size(); l++)
                {
                    
                    if((l % 2) == 0)
                    {
                        if(a != 0 )
                            roomNo[i][j] += ",";
                        a++;
                        roomNo[i][j] += room2[l];
                    }
                    else
                    {
                        STRING_VEC size;
                        temp = room2[l];
                        SplitString(size, temp, "x");   // 6x6
                        
                        for(unsigned int m = 0; m < size.size(); m++)
                        {                          
                            if(b != 0)
                            {
                                rows[i][j] += ",";
                                columns[i][j] += ",";
                            }
                            b++;
                            rows[i][j] += size[m++];
                            columns[i][j] += size[m];
 
                        }
                    }
                    
                }
            }
        }
    }
/*    
    SetDefaultValue();
    WriteRoomDetail();
    ExamDetailPage();*/
}

/**
 *      \class  ExamDetail
 *      \fn     ExamDetail :: WriteRoomDetail()
 *      \brief  After Reading, saving details in Database
 */

void ExamDetail :: WriteRoomDetail()
{
    where = "ProjectID = " + projectID;
    database.SelectColumn(vecTemp, "CentreName", "RoomDetail",
                          where);

    if(vecTemp.size() > 0 )
    {
        where = "ProjectID = " + projectID;
        database.DeleteQuery("RoomDetail", where);
    }
        
    vecTemp.clear();

    for(i = 0; i < totalDays; i++)
    {
        k = i + 1;
        for(j = 0; j < totalCentres[i]; j++)
        {
            database.InsertRoomDetail(projectID, IntToString(k), 
                                      centreName[i][j], roomInfo[i][j],
                                      roomNo[i][j],
                                      rows[i][j], columns[i][j]);
        }
    }

    /* Writing room details into file */
    
    totalRooms.resize(totalDays);
    rmNo.resize(totalDays);
    row.resize(totalDays);
    col.resize(totalDays);

    for(i = 0; i < totalDays; i++)
    {
        totalRooms[i].resize(totalCentres[i]);
        rmNo[i].resize(totalCentres[i]);
        row[i].resize(totalCentres[i]);
        col[i].resize(totalCentres[i]);
        
        for(j = 0; j < totalCentres[i]; j++)
        {
            SplitString(rmNo[i][j], roomNo[i][j], ",");
            SplitString(row[i][j], rows[i][j], ",");
            SplitString(col[i][j], columns[i][j], ",");
            totalRooms[i][j] = rmNo[i][j].size();
        }
    }
 
    where = "ProjectID = " + projectID;
    database.SelectColumn(vecTemp, "Date", "DateSheet", where);
    int total = vecTemp.size();
    int Days = 1;
    vecTemp.clear();
   
    temp = FileName(ROOM_DETAIL, projectID, 1);
    outFile.open(temp.c_str());
    
    outFile << total << endl;

    for(i = 0; i < totalDays; i++)
    {
        outFile << totalCentres[i] << endl;
        for(j = 0; j < totalCentres[i]; j++)
        {
            trim(centreName[i][j]);
            
            outFile << centreName[i][j] << endl
                    << totalRooms[i][j] << endl;
            for(k = 0; k < totalRooms[i][j]; k++)
            {
                trim(rmNo[i][j][k]);
                trim(row[i][j][k]);
                trim(col[i][j][k]);

                outFile << rmNo[i][j][k] << endl
                        << row[i][j][k]  << " "
                        << col[i][j][k]  << endl;
            }
        }
        if(total > totalDays)
        {
            if(Days < total)
            {
                i--;
                Days++;
            }

        }
    }

    outFile.close();
}

/**
 *      \class  ExamDetail
 *      \fn     ExamDetail :: ExamDetailPage()
 *      \brief  Page for taking exam detail
 */

void ExamDetail :: ExamDetailPage()
{
//    page.ContentType();

    ReadRoomDetail();
    WriteRoomDetail();
    SetDefaultValue();

    Header("Exam Detail");
/*    cout << "<link href=\"../../BaKaPlan/css/jquery.timepicker.css\""
         << "rel=\"stylesheet\" type=\"text/css\" />";
    page.Javascript("../../BaKaPlan/javascript/jquery-1.7.1.js");
    page.Javascript("../../BaKaPlan/javascript/jquery.timepicker.js");
    page.Javascript("../../BaKaPlan/javascript/main.js");
  */  
    cout << cgicc::div().set("id", "DivExam").set("align", "center");
    
    cout << h1() << "Exam Detail" << h1();
//    page.LogoutLink();

//    cout << page.brk;

    cout << form().set("id", "FormExam").set("action", "strategy")
                  .set("method", "POST")
                  .set("onsubmit", 
                       "return ValidateExamForm('TotalDays')");
    ErrorMessage(msg);

    page.InputField("hidden", fieldName.projectID, projectID);
    page.InputField("hidden", fieldName.totalDays, 
                    IntToString(totalDays));
    page.InputField("hidden", fieldName.projectType, projectType);
    page.InputField("hidden", fieldName.sameDetail, sameDetail);
    
    cout << table().set("id", "TableExam").set("align", "center");
    
    cout << tr();
    
    if(sameDetail == "Yes")
        j = 1;
    else
        j = 0;

    for(k = j; k < totalCols; k++)
    {   
        cout << th() << tableHeading[k] << th();
    }
    cout << tr();

    for(i = 0; i < totalDays; i++)
    {
        j = i + 1;
/*       
        if(projectType == "Old")
        {
            cout << page.startTR;
            if(sameDetail == "No")
            {
                cout << page.startTD;
                cout << date[i];
                page.InputField("hidden", fieldName.date, j, date[i]);
                cout << page.endTD;
            }
            cout << page.startTD;
            page.InputField("text", fieldName.examName, j, 
                            examName[i], examName[i]);
            cout << page.endTD;
            cout << page.startTD;
            page.InputField("text", fieldName.examSession, j, 
                             examSession[i], examSession[i]);
            cout << page.endTD;
            cout << page.startTD;
            page.InputField("text", fieldName.examTime, j, 
                            examTime[i], examTime[i]);
            cout << page.endTD;
            cout << page.startTD;
            page.InputField("text", fieldName.examVenue, j, 
                             examVenue[i], examVenue[i]);
            cout << page.endTD;
            cout << page.endTR;           
        }
        else*/
        {
            cout << tr();
            if(sameDetail == "No")
            {
                cout << td();
                cout << date[i];
                page.InputField("hidden", fieldName.date, j, date[i]);
                cout << td();
            }
            cout << td();
            page.InputField("text", fieldName.examName, j, 
                            examName[i]);
            cout << td();
            cout << td();
            
            temp = fieldName.examSession + IntToString(j);
            page.SelectFieldStart(temp);
        
            page.SelectOptionStart(" ", "y");
            cout << "Select";
            page.SelectOptionEnd();
            page.SelectOptionStart("Morming", "n");
            cout << "Morning";
            page.SelectOptionEnd();
            page.SelectOptionStart("Evening", "n");
            cout << "Evening";
            page.SelectOptionEnd();
            page.SelectFieldEnd();

/*            page.InputField("text", fieldName.examSession, j, 
                             examSession[i]);*/
            cout << td();
           
// Timing
/*             for(k = 0; k < 2; k++)
            {
                cout << page.startTD;
                if(k == 0)
                    temp = "F";
                else
                    temp = "T";

                page.SelectFieldStart((temp +"Hours" + IntToString(j)));
                page.SelectOptionStart("select", "y");
                cout << "Hours";
                page.SelectOptionEnd();               
            
                for(unsigned l = 0; l < hours.size(); l++)
                {
                    page.SelectOptionStart(hours[l], "n");
                    cout << hours[l];
                    page.SelectOptionEnd();
                }
                
                page.SelectFieldEnd();   

                page.SelectFieldStart((temp + "Minutes" + IntToString(j)));
                page.SelectOptionStart("select", "y");
                cout << "Minutes";
                page.SelectOptionEnd();               
            
                for(unsigned l = 0; l < minutes.size(); l++)
                {
                    page.SelectOptionStart(minutes[l], "n");
                    cout << minutes[l];
                    page.SelectOptionEnd();
                }
                
                page.SelectFieldEnd();  

                page.SelectFieldStart((temp + "AMPM" + IntToString(j)));
                page.SelectOptionStart("select", "y");
                cout << "AM/PM";
                page.SelectOptionEnd();               
            
                for(unsigned l = 0; l < ampm.size(); l++)
                {
                    page.SelectOptionStart(ampm[l], "n");
                    cout << ampm[l];
                    page.SelectOptionEnd();
                }
                
                page.SelectFieldEnd();   
                cout << page.endTD;
            }*/
 
            string startTime[10] = {"9:00 AM", "9:30 AM", "10:30 AM",
                                  "11:00 AM", "11:30 AM", "12:00 PM",
                                  "1:00 PM", "1:30 PM", "2:00 PM", 
                                  "2:30 PM"};

            string endTime[15] = {"9:30 AM", "10:30 AM", "11:00 AM", 
                                "11:30 AM", "12:00 PM", "12:30 PM",
                                "1:00 PM", "1:30 PM", "2:00 PM", 
                                "2:30 PM", "3:00 PM", "3:30 PM",
                                "4:00 PM", "4:30 PM", "5:00 PM"};
            cout << td();

            page.SelectFieldStart("StartTime"+ IntToString(j));
            page.SelectOptionStart(" ", "y");
            cout << "Select";
            page.SelectOptionEnd();
            for(l = 0; l < 10; l++)
            {
                page.SelectOptionStart(startTime[l], "n");
                cout << startTime[l];
                page.SelectOptionEnd();
            }
            page.SelectFieldEnd();

/*
//            page.InputField("time", "StartTime", j, "Start Time");
            cout << "<input id=\"myPicker\" class=\"time\" "
                 << "name=\"StartTime\" type=\"text\" />";*/
            cout << td();
            
            cout << td();
            page.SelectFieldStart("EndTime"+ IntToString(j));
            page.SelectOptionStart(" ", "y");
            cout << "Select";
            page.SelectOptionEnd();
            for(l = 0; l < 15; l++)
            {
                page.SelectOptionStart(endTime[l], "n");
                cout << endTime[l];
                page.SelectOptionEnd();
            }
            page.SelectFieldEnd();

/*            page.InputField("time", "EndTime", j, "End Time");
            cout << "<input id=\"myPicker\" class=\"time\" "
                 << "name=\"EndTime\" type=\"text\" />";*/
            cout << td();
           
            cout << td();
            page.InputField("text", fieldName.examVenue, j, 
                             examVenue[i]);
            cout << td();
            cout << tr();
        }
    }
/*    cout << "<script> $(function() {"
         << " $('#EndTime').timepicker"
         << "({ 'scrollDefaultNow': true }); });  </script>";*/

    cout << table();

    cout << br() << br();

    page.Button("next", "submit", "btn", "NEXT");

    cout << form()
         << cgicc :: div();

    Footer();

}

/**
 *      \class  ExamDetail
 *      \fn     ExamDetail :: ~ExamDetail()
 *      \brief  Destructor
 */

ExamDetail :: ~ExamDetail()
{
    //destructor
}

