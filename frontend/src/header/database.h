/**
 *
 *       \file       database.h
 *
 *       \brief      Declaring Database class for creating specific
 *                   functions for accessing database.
 *
 *       \version    0.8
 *       \date       Thursday 06 June 2013 09:16:48  IST\n
 *       Compiler    g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com\n
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

#ifndef DATABASE_H
#define DATABASE_H

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

        unsigned int numrows;            /**< Unsigned int variable */

        STRING_VEC vecTemp;
        
        int i, j;
        string query;

    public:
        Database();

        void Query(string query);

        void UpdateQuery(string table, string column, string value, 
                         string where);
        
        void SelectQuery(string query, STRING_VEC & result);

        void InsertQuery(string query);

        void DeleteQuery(string table, string where);

        void SelectSum(string column, string table, string projectID,
                       string & result);

        void SelectColumn(STRING_VEC & result, string column, 
                          string table, string where = "" );

        void SelectProjectID(string & projectID);

        void InsertUserDetail(string emailID, string password);

        void InsertRegistrationDetail(string emailID, 
                                      string registrationKey);
        void InsertResetPassword(string emailID, 
                                 string resetKey);

        void InsertProjectDetail(string emailID,
                               string projectName);

        void InsertClassDetail(string projectID, string className,
                               string subjectName, string subjectCode);

        void InsertRollNoDetail(string projectID, string classID, 
                                string prefix, string startRNo, 
                                string endRNo, string notIncluded);

        void InsertRoomDetail(string projectID, string dateSheetID,
                              string roomInfo,
                              string centreName, string roomNo, 
                              string rows, string cols);

        void InsertStrategyDetail(string projectID, string dateSheetID,
                            string strategyName);

        void InsertValidStrategy(string projectID, string dateID, 
                                 string date, string selectedStrategy,
                                 string totalSeats, 
                                 string totalStudents,
                                 string totalGroupSeats,
                                 string totalGroupStudents);

        void InsertDateSheet(string projectID, string date, 
                             string examCode);

        void InsertExamDetail(string projectID, string dateSheetID,
                              string examName, string examSession, 
                              string examTime, string examVenue);
        
        void InsertSessionDetail(string emailID, string sessionKey);

        ~Database();
};

#endif
