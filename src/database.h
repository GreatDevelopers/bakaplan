/*
 * ===================================================================
 *
 *       Filename:  database.h
 *
 *    Description:  Declaring Database class for using database.
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
 *  Include header.h and database.h
 *------------------------------------------------------------------*/

#include "header.h"
#include "database-detail.h"
#include <mysql.h>

/**
 * ===================================================================
 *        Class:  Database
 *  Description:  Database class for database accessability
 * ===================================================================
 */

class Database
{
    protected:
        /** MySQL connectivity Variables */
        MYSQL *connect;
        MYSQL_RES *res_set;
        MYSQL_ROW row;
        
        /** Table names tTablename */
        string tLogin, tRegister, tProjectDetail;

        int i, j;
        string query;

    public:
        /** Database Constructor */
        Database();

        /** Select MySQL command with 2 arguments */
        void Select(string column, string tableName);

        /** Select command with 3 arguments */
        void Select(string column, string tableName, 
                    string whereClause);
        
        /** Insert into ProjectName */
        void Insert(int projectID, string projectName, string tableName);

        /** Database Destructor */
        ~Database();
};
