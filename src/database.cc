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

    connect = mysql_real_connect(connect, SERVER, USER, PASSWORD, DATABASE, 0, NULL, 0);
    
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

string Database :: SelectQuery(string column, string table)
{
    query  = "Select ";
    query += column;
    query += " from ";
    query += table;
    query += ";";
    //cout << "Query" << query;
 
    if (mysql_query (connect, query.c_str())==0)//query.c_str());
    {
        res_set = mysql_store_result(connect);

//    numrows = mysql_num_rows(res_set);

        while (((row = mysql_fetch_row(res_set)) != NULL))
        {
            //cout << row[1];
            return row[0];
        }
    }
    else
    {
        return "0";
    }
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
