/*
 * ===================================================================
 *
 *       Filename:  database.h
 *
 *    Description:  Declaring Database class for using database.
 *
 *        Version:  0.6
 *        Created:  Friday 22 February 2013 12:48:40  IST
 *       Compiler:  g++
 *
 *         Author:  Mandeep Kaur, meghasimak@gmail.com
 *        License:  GNU General Public License
 *      Copyright:  Copyright (c) 2013, Great Developers
 *
 * ===================================================================
 */

#ifndef DATABASE_H
#define DATABASE_H

/**-------------------------------------------------------------------
 *  Include header.h, database-detail.h, mysql.h
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

        /** unsigned int variable  */
        unsigned int numrows;

        STRING_VEC vecTemp;
        
        int i, j;
        string query;

    public:
        /** Database Constructor */
        Database();

        /** Function for executing query ie for insertion or deletion */
        void Query(string query);
        
        /** Select Query */
        void SelectQuery(string query, STRING_VEC & result);

        /** Insert Query */
        void InsertQuery(string query);

        /** Delete Query  */
        void DeleteQuery(string table, string where);

        /** Select single column from table */
        void SelectColumn(STRING_VEC & result, string column, 
                          string table, string where = "" );

        /** Select last Project ID from table  */
        void SelectProjectID(string & projectID);

        /** Insert User Detail into database */
        void InsertUserDetail(string emailID, string password);

        /** Insert Registration Detail */
        void InsertRegistrationDetail(string emailID, 
                                      string registrationKey);

        /** Insert Project Detail  */
        void InsertProjectDetail(string projectID, string emailID,
                               string projectName);

        /** Insert Class Detail  */
        void InsertClassDetail(string projectID, string className,
                               string subjectName, string subjectCode);

        /** Insert RollNo detail  */
        void InsertRollNoDetail(string projectID, string classID, 
                                string prefix, string startRNo, 
                                string endRNo, string notIncluded);

        /** Insert Room Detail */
        void InsertRoomDetail(string projectID, string dateSheetID,
                              string centreName, string roomNo, 
                              string rows, string cols);

        /** Insert Strategy Detail */
        void InsertStrategyDetail(string projectID, string dateSheetID,
                            string strategyName);

        /** Insert DateSheet */
        void InsertDateSheet(string projectID, string date, 
                             string examCode);

        /** Insert Exam Detail  */
        void InsertExamDetail(string projectID, string dateSheetID,
                              string examName, string examSession, 
                              string examTime, string examVenue);
        
        /** Insert Session Detail */
        void InsertSessionDetail(string emailID, string sessionKey);

/*  
        void SelectSum(string column, string table, string projectID, 
                       string & result);
*/
        /** Select last project Id of project name */
        //void SelectQuery(string projectID);

        /** Database Destructor */
        ~Database();
};

#endif
