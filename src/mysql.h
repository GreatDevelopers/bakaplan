/*
 * ===================================================================
 *
 *       Filename:  mysql.h
 *
 *    Description:  For declaring MySQL class for using database.
 *
 *        Version:  0.6
 *        Created:  Friday 22 February 2013 12:48:40  IST
 *       Compiler:  gcc
 *
 *         Author:  Mandeep Kaur, meghasimak@gmail.com
 *        License:  GNU General Public License
 *      Copyright:  Copyright (c) 2013, Great Developers
 *
 * ===================================================================
 */

/**-------------------------------------------------------------------
 *  Include mysql.h and database.h
 *------------------------------------------------------------------*/

#include "header.h"
#include "mysql.h"
#include "database.h"

/**
 * ===================================================================
 *        Class:  MySQL
 *  Description:  MySQL class for database accessability
 * ===================================================================
 */

class MySQL
{
    protected:
        /// MySQL connectivity Variables
        MYSQL *connect;
        MYSQL_RES *res_set;
        MYSQL_ROW row;
        
        /// table names

        int i, j;
        string query;

    public:
        /// MySQL Constructor
        MySQL();

        /// Select MySQL command with 2 arguments
        void Select(string column, string tableName);

        /// Select command with 3 arguments
        void Select(string column, string tableName, 
                    string whereClause);
        
        /// Insert into ProjectName
        Insert(int projectID, string projectName, string tableName);

        /// MySQL Destructor
        ~MySQL();
};
