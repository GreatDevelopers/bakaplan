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

        /** unsigned int variable  */
        unsigned int numrows;
        
        /** Table names tTablename */
        string tLogin, tRegister, tProjectDetail;

        int i, j;
        string query;

    public:
        /** Database Constructor */
        Database();
        
        /** For executing MySQL query */
        void SelectQuery(string column, string table, 
                         vector<string> & result);

        /** Select query with where clause */
        void SelectQuery(string column, string table, string & result,
                         string where);

        /** Seclect Column */
        void SelectColumn(string query, vector<string> & result);

        /** select project id from ProjectName table  */
        void SelectProjectID(string & projectID);

        /** For inserting new user in database */
        void InsertUser(string userEmailID, string userPassword);

        /** Insert query with one argument */
        void InsertQuery(string query);

        /** Insert Query for adding value in one column */
        void InsertQuery(string column, string value, string table);

        /** Insert into Session table */
        void InsertSession(string emailID, string sessionID);

        /** Insert Project detail into ProjectName table */
        void InsertProjectName(string emailID, string projectName);

        /** Insert Into TotalClasses */
        void InsertTotalClasses(string projectID, 
                                string totalClasses);

        /** Insert into ClassDetail */
        void InsertClassDetail(string projectID, string className,
                               string totalSubjects,
                               string subjectName, string subjectCode);

        /** Insert into totalcentres */
        void InsertTotalCentres(string projectID, string totalCentre);

        /** Insert into roomDetail table */
        void InsertRoomDetail(string projectID, string centreName,
                              string roomNo, string rows, 
                              string columns);

        /** Insert Into TotalRooms */
        void InsertTotalRooms(string projectID, string centreName, 
                              string totalrooms);

        /** Insert into exam detail */
        void InsertExamDetail(string projectID, string examName, 
                              string examDate, string examTime,
                              string examVenue);

        /** Insert into strategy */
        void InsertStrategy(string projectID, string strategy);

        /** Select last project Id of project name */
        //void SelectQuery(string projectID);

        /** Database Destructor */
        ~Database();
};
