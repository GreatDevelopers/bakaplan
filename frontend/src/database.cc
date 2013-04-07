/*
 * ===================================================================
 *
 *       Filename:  database.cc
 *
 *    Description:  Definition of Database Class for accessing database
 *
 *        Version:  0.6
 *        Created:  Friday 22 February 2013 02:07:49  IST
 *       Compiler:  g++
 *
 *         Author:  Mandeep Kaur, meghasimak@gmail.com
 *        License:  GNU General Public License
 *      Copyright:  Copyright (c) 2013, Great Developers
 *
 * ===================================================================
 */

/**-------------------------------------------------------------------
 *  Include database.h file local header file(declaration of class)
 *------------------------------------------------------------------*/

#include "header/database.h"

/**
 *--------------------------------------------------------------------
 *       Class:  Database
 *      Method:  Database :: Database()
 * Description:  Constructor to initialize database conectivity
 *--------------------------------------------------------------------
 */

Database :: Database()
{
    connect = mysql_init(NULL);

    if ( !connect )
    {
        cout << "MySQL Initialization Failed";
    }   

    connect = mysql_real_connect(connect, SERVER, USER, PASSWORD, 
                                 DATABASE, 0, NULL, 0);
    
    if ( connect == NULL )
    {
        cout << "Connection Failed\n";
    }
}

/**
 *      \class  Database
 *      \fn     Database :: Query(string query)
 *      \brief  Function to execute any query
 */

void Database :: Query(string query)
{
    if ( mysql_query( connect, query.c_str() ) == 0)
        cout << "";
    else
        cout << " Query not executed ";
}

/**
 *      \class  Database
 *      \fn     Database :: SelectQuery(string query, 
 *              STRING_VEC & result)
 *      \brief  Select Query for selecting single column from table
 *      \param  query   Select query
 *      \param  result  For storing selected column valued in result
 *              variable
 */

void Database :: SelectQuery(string query, STRING_VEC & result)
{
    if ( mysql_query( connect, query.c_str() ) == 0 )
    {
        res_set = mysql_store_result( connect );

        while ( ( ( row = mysql_fetch_row( res_set ) ) != NULL ) )
        {
            result.push_back( row[0] );
        }
     }
     else
        cout << " Not Selected ";
}

/**
 *      \class  Database
 *      \fn     Database :: InsertQuery(string query)
 *      \brief  Function for executing InsertQuery
 *      \param  query   query for inserting into value
 */

void Database :: InsertQuery(string query)
{
    Query(query);
}

/**
 *      \class  Database
 *      \fn     Database :: DeleteQuery(string row, string table,
 *                          string where="")
 *      \brief  Delete Query
 *      \param
 */

void Database :: DeleteQuery(string table, string where = "")
{
    query = "delete row from " + table + " where " + where + ";";
    Query(query);
}

/**
 *      \class  Database
 *      \fn     Database :: SelectQuery(SELECT_VEC & result, 
 *                          string column, string table, 
 *                          string where = "")
 *      \brief  Selecting column from table
 *      \param  result
 *      \param  column
 *      \param  table
 *      \param  where
 */

void Database :: SelectColumn(STRING_VEC & result, string column,
                              string table, string where)
{
    query  = "select " + column + " from " + table;

    if(where != "")
    {
        query += " where " + where + ";";
    }
    else
    {
        query += ";";
    }
//    cout << query;
    SelectQuery(query, result);
}

void Database :: SelectProjectID(string & projectID)
{
    query  = "Select ProjectID from ProjectName ORDER BY ProjectID ";
    query += "DESC LIMIT 1;";
    
    SelectQuery(query, vecTemp);
    projectID = vecTemp[0];     // last project Id in table
}

void Database :: InsertUserDetail(string emailID, string password)
{
    query = "insert into User(EmailID, Password) values(\"" + emailID
            + "\", \"" + password + "\");";

    InsertQuery(query);
}

void Database :: InsertRegistrationDetail(string emailID,
                                          string registrationKey)
{
    query  = "insert into Registeration(EmailID, RegistrationKey) ";
    query += "values(\"" + emailID + "\", \"" + registrationKey;
    query += "\");";

    InsertQuery(query);
}

void Database :: InsertProjectDetail(string projectID, string emailID,
                                     string projectName)
{
    query  = "insert into ProjectDetail(ProjectID, EmailID, ";
    query += "ProjectName) values(" + projectID + ", \"" + emailID + 
             "\", \"" + projectName + "\");";

    InsertQuery(query);
}

void Database :: InsertClassDetail(string projectID, string className,
                                   string subjectName, 
                                   string subjectCode)
{
    query  = "insert into ClassDetail(ProjectID, ClassName, ";
    query += "SubjectName, SubjectCode) values(" + projectID + 
             ", \"" + className + "\", \"" + subjectName + "\", \"" + 
             subjectCode + "\");";

    InsertQuery(query);
}

void Database :: InsertRollNoDetail(string projectID, string classID,
                                    string prefix, string startRNo,
                                    string endRNo, string notIncluded)
{
    query  = "insert into RollNoDetail(ProjectID, ClassID, Prefix, ";
    query += "StartRNo, EndRNo, NotIncluded) values(" + projectID + 
             ", " + classID + ", \"" + prefix + "\", " + startRNo +
             ", " + endRNo + ", \"" + notIncluded +"\");";

    InsertQuery(query);
}

void Database :: InsertRoomDetail(string projectID, string dateSheetID,
                                  string centreName, string roomNo,
                                  string rows, string cols)
{
    query  = "insert into RoomDetail(ProjectID, DateSheetID, ";
    query += "CentreName, RoomNo, Rows, Columns) values(" + 
             projectID + ", " + dateSheetID + ", \"" + centreName +
             "\", \"" + roomNo + "\", \"" + rows + "\", \"" + cols +
             "\");";

    InsertQuery(query);
}

void Database :: InsertStrategyDetail(string projectID, 
                                      string dateSheetID, 
                                      string strategyName)
{
    query  = "insert into StrategyDetail(ProjectID, DateSheetID, ";
    query += "StrategyName) values(" + projectID + ", " + dateSheetID 
             + ", \"" + strategyName + "\");";

    InsertQuery(query);
}

void Database :: InsertDateSheet(string projectID, string date, 
                                 string examCode)
{
    query  = "insert into DateSheet(ProjectID, Date, ExamCode), ";
    query += "values(" + projectID + ", \"" + date + "\", \"" +
             examCode + ");";

    InsertQuery(query);
}

void Database :: InsertExamDetail(string projectID, string dateSheetID,
                                  string examName, string examSession,
                                  string examTime, string examVenue)
{
    query  = "insert into ExamDetail(ProjectID, DateSheetID, ";
    query += "ExamName, ExamSession, ExamTime, ExamVenue)";
    query += " values(" + projectID + ", " + dateSheetID + ", \"" +
             examName + "\", \"" + examSession + "\", \"" + examTime +
             "\", \"" + examVenue + "\");";

    InsertQuery(query);
}

void Database :: InsertSessionDetail(string emailID, string sessionKey)
{
    query  = "insert into SessionDetail(EmailID, SessionKey) values(";
    query += "\"" + emailID + "\"" + sessionKey + "\");";

    InsertQuery(query);
}

/* 
void Database :: SelectSum(string column, string table, 
                           string projectID, string & result)
{
    query  = "Select sum(" + column + ") as sum from " + table;
    query += " where ProjectID = " + projectID + ";";
    vector<string> res;
    SelectColumn(query, res);
    result = res[0];
}
void Database :: SelectColumn(string query, vector<string> & result)
{

    if ( mysql_query( connect, query.c_str() ) == 0 )
    {
        res_set = mysql_store_result( connect );

        while ( ( ( row = mysql_fetch_row( res_set ) ) != NULL ) )
        {
            result.push_back( row[0] );
        }
     }
     else
        cout << "";
}

void Database :: Select(string & result)
{
    if ( mysql_query( connect, query.c_str() ) == 0 )
        result = "T";    
    else
        result = "F";
}

void Database :: InsertQuery(string query)
{
    if ( mysql_query( connect, query.c_str() ) == 0)
        cout << "";
    else
        cout << "</br>Not insterted</br>";
}

void Database :: DeleteQuery(string query)
{
    if ( mysql_query( connect, query.c_str() ) == 0)
        cout << "";
    else
        cout << "</br>Not deleted</br>";
}

void Database :: InsertQuery(string column, string value, 
                             string table)
{
    query  = "insert into ";
    query += table;
    query += "(";
    query += column;
    query += ") values ( \"";
    query += value;
    query += "\");";

    InsertQuery(query);
}

void Database :: InsertUser(string userEmailID, string userPassword)
{
    query  = "Insert into User(EmailID, Password) values ";
    query += "(\"";
    query +=  userEmailID;
    query += "\", \"";
    query += userPassword; 
    query += "\");";

    InsertQuery(query);

}

void Database :: InsertSession(string emailID, string sessionID)
{
    query  = "insert into Session(EmailID, SessionID) values (\"";
    query += emailID;
    query += "\", \"";
    query += sessionID;
    query += "\");";

    InsertQuery(query);
}

void Database :: InsertProjectName(string emailID, string projectName)
{
    query  = "Insert into ProjectName(EmailID, ProjectName) values ";
    query += "(\"";
    query += emailID;
    query += "\", \"";
    query += projectName;
    query += "\");";

    InsertQuery(query);
}

void Database :: InsertTotalClasses(string projectID, 
                                    string totalClasses)
{
    query  = "Insert into TotalClasses(ProjectID, TotalClasses) ";
    query += "values (";
    query += projectID;
    query += ", ";
    query += totalClasses;
    query += ")";

    InsertQuery(query);
}

void Database :: InsertClassDetail(string projectID, string className,
                                   string totalSubjects, 
                                   string subjectName, 
                                   string subjectCode)
{
    query  = "Insert into ClassDetails(ProjectID, ClassName, ";
    query += "TotalSubjects, SubjectName, SubjectCode) values (";
    query += projectID + ", \"";
    query += className + "\" ,\"" + totalSubjects + "\", \"";
    query += subjectName + "\" ,\"" + subjectCode;
    query += "\");";

    InsertQuery(query);

}

void Database :: InsertRollNoDetail(string projectID, string className, 
                                string subjectCode, string prefix,
                                string startRollNo, string endRollNo,
                                string notIncluded)
{
    query  = "Insert into RollNoDetail(ProjectID, ClassName, ";
    query += "SubjectCode, Prefix, StartRollNo, EndRollno, ";
    query += "NotIncluded) values (" + projectID + ",\"" +
             className + "\", \"" + subjectCode + "\", \"" +
             prefix + "\", " + startRollNo + ", " + endRollNo +
             ", \"" + notIncluded + "\");";
    
    InsertQuery(query);
}

void Database :: InsertTotalCentres(string projectID, 
                                    string totalCentre)
{
    query  = "insert into TotalCentres(ProjectID, TotalCentres) ";
    query += "values (";
    query += projectID;
    query += ", ";
    query += totalCentre;
    query += ");";

    InsertQuery(query);
}

void Database :: InsertRoomDetail(string projectID, string centreName,
                                  string roomNo, string rows,
                                  string columns)
{
    query  = "insert into RoomDetail(ProjectID, CentreName, RoomNo,"; 
    query += "Rows, Columns) values (";
    query += projectID;
    query += ", \"";
    query += centreName;
    query += "\", \"";
    query += roomNo;
    query += "\", ";
    query += rows;
    query += ", ";
    query += columns;
    query += ");";

    InsertQuery(query);
}

void Database :: InsertTotalRooms(string projectID, string centreName,
                                  string totalRooms)
{
    query  = "insert into TotalRooms(ProjectID, CentreName, ";
    query += "TotalRooms) values(";
    query += projectID;
    query += ", '";
    query += centreName;
    query += "', ";
    query += totalRooms;
    query += ");";

    InsertQuery(query);
}

void Database :: InsertExamDetail(string projectID, string examName, 
                                  string examDate, string examTime,
                                  string examVenue)
{
    query  = "insert into ExamDetail(ProjectID, ExamName, ExamDate, ";
    query += "ExamVenue) values (";
    query += projectID;
    query += ", '";
    query += examName;
    query += "', '";
    query += examDate;
    query += "', '";
    query += examTime;
    query += "', '";
    query += examVenue;
    query += "');";

    InsertQuery(query);
}

void Database :: InsertStrategy(string projectID, string strategy)
{
    query  = "insert into Strategy(ProjectID, StrategyName) values(";
    query += projectID;
    query += ", \"";
    query += strategy;
    query += "\");";

    InsertQuery(query);
}
*/
/**
 *--------------------------------------------------------------------
 *       Class:  Database
 *      Method:  Database :: ~Database()
 * Description:  Destructor for closing database connectivity
 *--------------------------------------------------------------------
 */

Database :: ~Database()
{
    mysql_close (connect);
}
