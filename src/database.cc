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
                                   string subjectName, 
                                   string subjectCode)
{
    query  = "Insert into ClassDetails(ProjectID, ClassName, ";
    query += "SubjectName, SubjectCode) values (";
    query += projectID;
    query += ", '";
    query += className + "' ,'" + subjectName + "' ,'" + subjectCode;
    query += "');";

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
