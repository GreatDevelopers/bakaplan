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

void Database :: InsertIntoUser(string userEmailID, 
                                string userPassword)
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

void Database :: InsertIntoSession(string emailID, string sessionID)
{
    query  = "insert into Session(EmailID, SessionID) values (\"";
    query += emailID;
    query += "\", \"";
    query += sessionID;
    query += "\");";

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
