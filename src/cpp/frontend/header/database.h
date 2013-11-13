/**
 *
 *       \file       database.h
 *
 *       \brief      Declaring Database class for creating specific
 *                   functions for accessing database.
 *
 *       \compiler   g++\n
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       \license    GNU General Public License\n
 *       \copyright  Copyright (c) 2013, GreatDevelopers\n
 *                   https://github.com/GreatDevelopers
 */

#ifndef DATABASE_H
#define DATABASE_H

#include "header.h"
#include "database_detail.h"
#include <mysql.h>


/**
 *      \class  Database
 *      \brief  Declaring functions for database comectivity and
 *              accessing database.
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
        
        string i, j;
        string query;

    public:
        
        /**
         *  For making connection with database. 
         */
        Database();
        
        /**
         *  Database Query  
         */
        void Query(string query);
        
        /**
         *  Database Update Query 
         */
        void UpdateQuery(string table, string column, string value, 
                         string where);
        
        /**
         *  Database Select Query 
         */
        void SelectQuery(string query, STRING_VEC & result);
        
        /**
         *   Database Insert Query
         */
        void InsertQuery(string query);
        
        /**
         *   Database Delete Query
         */
        void DeleteQuery(string table, string where);
        
        /**
         *  Select sum for column in table 
         */
        void SelectSum(string column, string table, string projectID,
                       string & result);
        
        /**
         *  Select column from table 
         */
        void SelectColumn(STRING_VEC & result, string column, 
                          string table, string where = "" );
        
        /**
         *  Select Project ID from table 
         */
        void SelectProjectID(string & projectID);
        
        /**
         *  Inserting into User table 
         */
        void InsertUserDetail(string emailID, string password);
        
        /**
         *  Inserting into registration table 
         */
        void InsertRegistrationDetail(string emailID, 
                                      string registrationKey);

        /**
         *  Insert into reset password table 
         */
        void InsertResetPassword(string emailID, 
                                 string resetKey);
        
        /**
         *  Inserting project details 
         */
        void InsertProjectDetail(string emailID,
                               string projectName);

        /**
         *  Inserting class details 
         */
        void InsertClassDetail(string projectID, string className,
                               string subjectName, string subjectCode);

        /**
         *  Inserting roll no details 
         */
        void InsertRollNoDetail(string projectID, string classID, 
                                string prefix, string startRNo, 
                                string endRNo, string notIncluded);

        /**
         *  Inserting room details
         */
        void InsertRoomDetail(string projectID, string dateSheetID,
                              string roomInfo,
                              string centreName, string roomNo, 
                              string rows, string cols);

        /**
         *  Inserting strategy details 
         */
        void InsertStrategyDetail(string projectID, string dateSheetID,
                            string strategyName);

        /**
         *  Inserting validation details for strategy 
         */
        void InsertValidStrategy(string projectID, string dateID, 
                                 string date, string selectedStrategy,
                                 string totalSeats, 
                                 string totalStudents,
                                 string totalGroupSeats,
                                 string totalGroupStudents);

        /**
         *  Inserting datesheet details 
         */
        void InsertDateSheet(string projectID, string date, 
                             string examCode);

        /**
         *  Inserting examimation details 
         */
        void InsertExamDetail(string projectID, string dateSheetID,
                              string examName, string examSession, 
                              string examTime, string examVenue);
        
        /**
         *  Inserting into session detail table 
         */
        void InsertSessionDetail(string emailID, string sessionKey);
        
        /**
         *  For closing database connection 
         */
        ~Database();
};

#endif

/*
 * Local Variables:
 * tab-width: 4
 * expandtab
 * ex: shiftwidth=4 tabstop=4
 */

