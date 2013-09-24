/**
 *       \file       report.cc
 *
 *       \brief      func. definition
 *
 *       \version    0.8
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
    tableHeading[i++] = "View Report";
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

    cout << cgicc::div().set("id", "DivReport").set("align", "center");

//    page.LogoutLink();

//    cout << page.brk;
    cout << h1() << "Seating Plan" << h1();

    page.FormStart("FormReport", "", "post");

    cout << form().set("id", "FormReport").set("method", "POST");
    
    page.InputField("hidden", fieldName.projectID, projectID);
    page.InputField("hidden", fieldName.totalDays, 
                    IntToString(totalDays));
    page.InputField("hidden", fieldName.projectType, projectType);
    page.InputField("hidden", fieldName.sameDetail, sameDetail);

    cout << table().set("id", "TableReport");
    
    cout << tr();
    for(i = 0; i < totalCols; i++)
    {   
        cout << th()
             << tableHeading[i] 
             << th();
    } 
    cout << tr();
    for(unsigned i = 0; i < date.size(); i++)
    {
        cout << tr();
        cout << td()
             << date[i]
             << td()

             << td()
             << examCode[i]
             << td();

         temp = "../../SeatPlan/seatplan-" + projectID +
                "-" + IntToString(i + 1) + ".html";
         cout << td();
         page.Anchor(temp, "HTML");
         cout << td();
         temp = "../../SeatPlan/seatplan-" + projectID +
                "-" + IntToString(i + 1) + ".pdf";
         cout << td();
         page.Anchor(temp, "PDF");
         cout << td(); 
         cout << tr();
    }

    cout << table();

    cout << br() << br()
         << form()
         << cgicc::div();
    
    Footer();
}

Report :: ~Report()
{
    // destructor
}
