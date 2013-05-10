/**
 *       \file       report.cc
 *
 *       \brief      func. definition
 *
 *       \version    0.6
 *       \date       Sunday 07 April 2013 08:28:46  IST\n
 *       Compiler    g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

#include "header/report.h"

Report :: Report()
{
    // constructor
    totalCols = 3;
    tableHeading.resize(totalCols);
    i = 0;
    tableHeading[i++] = "Date";
    tableHeading[i++] = "Subject Code";
    tableHeading[i++] = "Report";
}

/**
 *      \class  Report
 *      \fn     Report :: ReadValidationDetail()
 *      \brief  Reading hidden fields of validation page
 */

void Report :: ReadValidationDetail()
{
    page.ContentType();

    projectID = readField.ReadFieldValue(fieldName.projectID);
    projectType = readField.ReadFieldValue(fieldName.projectType);
    totalDays = StringToInt(readField.ReadFieldValue(
                            fieldName.totalDays));

    sameDetail = readField.ReadFieldValue(fieldName.sameDetail);

    where = "ProjectID = " + projectID;
    database.SelectColumn(date, "Date", "DateSheet", where);
    database.SelectColumn(examCode, "ExamCode", "DateSheet", where);

    ReportPage();

}

/**
 *      \class  Report
 *      \fn     Report :: ReportPage()
 *      \brief  Report Page
 */

void Report :: ReportPage()
{
//    page.ContentType();

    Header("Report");

    page.DivStart("DivReport", "");

    page.LogoutLink();

    cout << page.brk;

    page.FormStart("FormReport", "", "post");

    cout << page.startH1 << "Seating Plan" 
         << page.endH1 << page.brk;
    
    page.InputField("hidden", fieldName.projectID, projectID);
    page.InputField("hidden", fieldName.totalDays, 
                    IntToString(totalDays));
    page.InputField("hidden", fieldName.projectType, projectType);
    page.InputField("hidden", fieldName.sameDetail, sameDetail);

    page.TableStart("TableReport", "");
    
    cout << page.startTR;
    for(i = 0; i < totalCols; i++)
    {   
        cout << page.startTH
             << tableHeading[i] 
             << page.endTH;
    } 
    cout << page.endTR;
    for(unsigned i = 0; i < date.size(); i++)
    {
        cout << page.startTR;
        cout << page.startTD
             << date[i]
             << page.endTD

             << page.startTD
             << examCode[i]
             << page.endTD;

         temp = "../../SeatPlan/seatplan-" + projectID +
                "-" + IntToString(i + 1) + ".html";
         cout << page.startTD;
         page.Anchor(temp, "View Report");
         cout << page.endTD;
         cout << page.endTR;
    }

    page.TableEnd();

    cout << page.brk << page.brk;
    
    page.FormEnd();
    page.DivEnd();

    Footer();
}

Report :: ~Report()
{
    // destructor
}
