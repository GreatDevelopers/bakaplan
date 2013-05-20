/*
 * ===================================================================
 *
 *       Filename:  database.cc
 *
 *    Description:  Definition of Database Class for accessing database
 *
 *        Version:  0.7
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
        cout << " Query not executed " << query;
}

void Database :: UpdateQuery(string table, string column, string value,
                             string where)
{
    query = "UPDATE " + table + " set " + column + " = \"" + value + 
            "\" where " + where + ";";

    Query(query);
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
        cout << " Not Selected " << query << endl;
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
    query = "delete from " + table + " where " + where + ";";
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

/**
 *      \class  Database
 *      \fn     Database :: SelectProjectID(string & projectID)
 *      \brief  Select project ID from database
 *      \param  projectID   Unique project ID
 */

void Database :: SelectProjectID(string & projectID)
{
    query  = "Select ProjectID from ProjectName ORDER BY ProjectID ";
    query += "DESC LIMIT 1;";
    
    SelectQuery(query, vecTemp);
    projectID = vecTemp[0];     // last project Id in table
}

/**
 *      \class  Database
 *      \fn     Database :: InsertUserDetail(string emailID, 
 *                          string password)
 *      \brief  Insert User detail into User tabele
 *      \param  emailID     Email Id
 *      \param  password    Password of user in encrypted from
 */

void Database :: InsertUserDetail(string emailID, string password)
{
    query = "insert into User(EmailID, Password) values(\"" + emailID
            + "\", \"" + password + "\");";

    InsertQuery(query);
}

/**
 *      \class  Database
 *      \fn     Database :: InsertRegistrationDetail(string emailID, 
 *                          string registrationKey)
 *      \brief  Inserting Registration detail
 *      \param  emailID   emailId of user
 *      \param  registrationKey  Registration Key 
 */

void Database :: InsertRegistrationDetail(string emailID,
                                          string registrationKey)
{
    query  = "insert into Registeration(EmailID, RegistrationKey) ";
    query += "values(\"" + emailID + "\", \"" + registrationKey;
    query += "\");";

    InsertQuery(query);
}
void Database :: InsertResetPassword(string emailID,
                                     string resetKey)
{
    query  = "insert into ResetPassword(EmailID, ResetKey) ";
    query += "values(\"" + emailID + "\", \"" + resetKey;
    query += "\");";

    InsertQuery(query);
}
/**
 *      \class  Database
 *      \fn     Database :: InsertProjectDetail(string emailID, 
 *                          string projectName)
 *      \brief  Inserting Project Detail into database
 */

void Database :: InsertProjectDetail(string emailID, 
                                     string projectName)
{
    query  = "insert into ProjectDetail(EmailID, ";
    query += "ProjectName) values(\"" + emailID + 
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
    query += "StartRollNo, EndRollNo, NotIncluded) values(" + 
             projectID + ", " + classID + ", \"" + prefix + "\", " + 
             startRNo + ", " + endRNo + ", \"" + notIncluded +"\");";

    InsertQuery(query);
}

void Database :: InsertRoomDetail(string projectID, string dateSheetID,
                                  string centreName, string roomInfo,
                                  string roomNo,
                                  string rows, string cols)
{
    query  = "insert into RoomDetail(ProjectID, DateSheetID, ";
    query += "CentreName, RoomInfo, RoomNo, Rows, Columns) values(" + 
             projectID + ", " + dateSheetID + ", \"" + centreName +
             "\", \"" + roomInfo + "\", \"" + roomNo + "\", \"" + 
             rows + "\", \"" + cols + "\");";

    InsertQuery(query);
}

void Database :: InsertValidStrategy(string projectID, string dateID, 
                                     string date, 
                                     string selectedStrategy,
                                     string totalSeats,
                                     string totalStudents,
                                     string totalGroupSeats,
                                     string totalGroupStudents)
{
    query  = "insert into ValidStrategy(ProjectID, DateID, Date, ";
    query += "SelectedStrategy, TotalSeats, TotalStudents, ";
    query += "TotalGroupSeats, TotalGroupStudents) values(" +
             projectID + ", " + dateID + ", \"" + date + "\", \"" +
             selectedStrategy + "\", " + totalSeats + ", " + 
             totalStudents + ", " + totalGroupSeats + ", " +
             totalGroupStudents + ");";

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
    query  = "insert into DateSheet(ProjectID, Date, ExamCode) ";
    query += "values(" + projectID + ", \"" + date + "\", \"" +
             examCode + "\");";

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

void Database :: SelectSum(string column, string table, 
                           string projectID, string & result)
{
    query  = "Select sum(" + column + ") as sum from " + table;
    query += " where ProjectID = " + projectID + ";";
    
    SelectQuery(query, vecTemp);
    result = vecTemp[0];
}

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
