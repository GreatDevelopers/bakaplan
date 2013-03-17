/*
 * ===================================================================
 *
 *       Filename:  database.cc
 *
 *    Description:  Definition of Database Class for accessing database
 *
 *        Version:  0.6
 *        Created:  Friday 22 February 2013 02:07:49  IST
 *       Compiler:  gcc
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

#include "database.h"

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
 *--------------------------------------------------------------------\n
 *       Class:  Database \n
 *      Method:  Database :: SelectQuery(string column, string table) \n
 * Description:  Executing MySQL Select Query and returns string value \n
 *--------------------------------------------------------------------
 */

void Database :: SelectQuery(string column, string table, 
                             vector<string> & result)
{
    query  = "Select ";
    query += column;
    query += " from ";
    query += table;
    query += ";";
    
    SelectColumn(query, result);
}

/**
 *--------------------------------------------------------------------\n
 *       Class:  Database \n
 *      Method:  Database :: SelectQuery(column, table, result, where) \n
 * Description:  Select column value with where clause \n
 *--------------------------------------------------------------------
 */

void Database :: SelectQuery(string column, string table, 
                             string & result, string where)
{
    query  = "Select ";
    query += column;
    query += " from ";
    query += table;
    query += " where ";
    query += where;
    query += ";";
    
    vector<string> ID;
    SelectColumn(query, ID);
    result = ID[0];
}

void Database :: SelectProjectID(string & projectID)
{
    query  = "Select ProjectID from ProjectName ORDER BY ProjectID ";
    query += "DESC LIMIT 1;";
    
    vector<string> ID;
    SelectColumn(query, ID);
    projectID = ID[0];
}

/**
 *--------------------------------------------------------------------\n
 *       Class:  Database \n
 *      Method:  Database :: SelectSum(column, table, result) \n
 * Description:  Select sum of totalSubjects from ClassDetail table \n
 *--------------------------------------------------------------------
 */

void Database :: SelectSum(string column, string table, 
                           string projectID, string & result)
{
    query  = "Select sum(" + column + ") as sum from " + table;
    query += " where ProjectID = " + projectID + ";";
    vector<string> res;
    SelectColumn(query, res);
    result = res[0];
}
/**
 *--------------------------------------------------------------------\n
 *       Class:  Database \n
 *      Method:  Database :: SelectColumn \n
 * Description:  Select column from table \n
 *--------------------------------------------------------------------
 */
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


/**
 *      \class  Database
 *      \fn     Database :: Select(string & result)
 *      \brief  check select query is executed or not
 *      \param  result 
 */

void Database :: Select(string & result)
{
    if ( mysql_query( connect, query.c_str() ) == 0 )
        result = "T";    
    else
        result = "F";
}

/**
 *--------------------------------------------------------------------\n
 *       Class:  Database \n
 *      Method:  Database :: InsertQuery(string query) \n
 * Description:  Insrting value in database \n
 *--------------------------------------------------------------------
 */

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

/**
 *--------------------------------------------------------------------\n
 *       Class:  Database \n
 *      Method:  Database :: InsertQuery(string column, string value, 
 *                           string table) \n
 * Description:  For inserting values in database \n
 *--------------------------------------------------------------------
 */

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

/**
 *--------------------------------------------------------------------\n
 *       Class:  Database \n
 *      Method:  Database :: InsertIntoUser(string userEmailID, 
 *                                          string userPassword) \n
 * Description:  Inserting new user details into database \n
 *--------------------------------------------------------------------
 */

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

/**
 *--------------------------------------------------------------------\n
 *       Class:  Database \n
 *      Method:  Database :: InsertIntoSession(string emailID, 
 *               string sessionID) \n
 * Description:  Inserting Session information in database \n
 *--------------------------------------------------------------------
 */

void Database :: InsertSession(string emailID, string sessionID)
{
    query  = "insert into Session(EmailID, SessionID) values (\"";
    query += emailID;
    query += "\", \"";
    query += sessionID;
    query += "\");";

    InsertQuery(query);
}

/**
 *--------------------------------------------------------------------\n
 *       Class:  Database \n
 *      Method:  Database :: InsertIntoProjectName() \n
 * Description:  Insert project name into ProjectName table \n
 *--------------------------------------------------------------------
 */

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

/**
 *--------------------------------------------------------------------\n
 *       Class:  Database \n
 *      Method:  Database :: InsertTotalClasses(projectID, 
 *                                              totalClasses) \n
 * Description:  Inserting total classes into table with project ID \n
 *--------------------------------------------------------------------
 */
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

/**
 *--------------------------------------------------------------------\n
 *       Class:  Database \n
 *      Method:  Database :: InsertClassDetail(projectID, className, 
 *                                           subjectName, subjectCode) \n
 * Description:  Inserting class detail into table \n
 *--------------------------------------------------------------------
 */
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

/**
 *--------------------------------------------------------------------\n
 *       Class:  Database \n
 *      Method:  Database :: InsertRollNoDetail() \n
 * Description:  Insert roll no details into database \n
 *--------------------------------------------------------------------
 */

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

/**
 *--------------------------------------------------------------------\n
 *       Class:  Database \n
 *      Method:  Database :: InserttotalCentres(projectID,totalcentre) \n
 * Description:  Inserting into table total centrres \n
 *--------------------------------------------------------------------
 */

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

/**
 *--------------------------------------------------------------------\n
 *       Class:  Database \n
 *      Method:  Database :: InsertRoomDetail(projectID, centreName, 
 *                                            roomNo, rows, columns) \n
 * Description:  Inserting room detail into table \n
 *--------------------------------------------------------------------
 */
void Database :: InsertRoomDetail(string projectID, string centreName,
                                  string roomNo, string rows,
                                  string columns)
{
    query  = "insert into RoomDetail(ProjectID, CentreName, RoomNo,"; 
    query += "Rows, Columns) values (";
    query += projectID;
    query += ", '";
    query += centreName;
    query += "', '";
    query += roomNo;
    query += ", ";
    query += rows;
    query += ", ";
    query += columns;
    query += ");";

    InsertQuery(query);
}

/**
 *--------------------------------------------------------------------\n
 *       Class:  Database \n
 *      Method:  Database :: InsertTotalRooms(projectID, centreName, 
 *                                            totalrooms) \n
 * Description:  Inserting into total rooms \n
 *--------------------------------------------------------------------
 */
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

/**
 *--------------------------------------------------------------------\n
 *       Class:  Database \n
 *      Method:  Database :: InsertTotalRooms(projectID, examName, 
 *                                            examDate, examTime, 
 *                                            examVenue) \n
 * Description:  store data into exam detail \n
 *--------------------------------------------------------------------
 */
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

/**
 *--------------------------------------------------------------------\n
 *       Class:  Database \n
 *      Method:  Database :: InsertTotalRooms(projectID, strategy) \n
 * Description:  Strategy value into table \n
 *--------------------------------------------------------------------
 */
void Database :: InsertStrategy(string projectID, string strategy)
{
    query  = "insert into Strategy(ProjectID, Strategy) values(";
    query += projectID;
    query += ", '";
    query += strategy;
    query += "');";

    InsertQuery(query);
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
