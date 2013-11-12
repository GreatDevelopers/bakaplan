/**
 *       \file       input-detail.h
 *
 *       \brief      Definition of InputDetail class for common
 *                   variables and functions \n
 *
 *       \compiler   g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com \n
 *       \license    GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

#include "header.h"
#include "database.h"
#include "read-inputfield.h"

/**
 *      \class  InputDetail
 *      \brief  For declaring common variables and functions also used
 *              as base class.
 */

class InputDetail
{
    protected:
        /* Common variables and objects */
        
        int i, j, k, l;                      /**< Looping Variables */

        stringstream ss;          /**< For converting int to string */
        string temp, temp1;             /**< For temporary strorage */
        // For project detail
        string projectID,                           
               emailID; 

        string fileName,            /**< File name for opening file */
               where,                     /**< Temp variable to store 
                                                       where clause */
               msg;                   /**< For Displaying error 
                                                            message */

        STRING_VEC vecTemp,        /**< string Vector temporary use */
                   oldProject,                 /**< For stroring old
                                                    projects if any */
                   splitString;            /**< For storing values of 
                                                    splitted string */
 
        ifstream inFile;                      /**< For Reading file */
        ofstream outFile;                     /**< For writing file */
        string sessionID;                       /**< Session ID */

        Database db;                    /**< DataBase class's object*/
        ReadInputField readField;         /**< Reading Inpur fields */


    public:

    InputDetail();
      
    void CSS(string href);              
    void Javascript(string src);

    void CommonJSFiles();
    void CommonCSSFiles();

    string IntToString(int value);
    int StringToInt(string value);
    void SplitString(STRING_VEC & output, 
                     string input, string token);
    string FileName(string file, string projectID, int fileType);

    ~InputDetail();
};

/*
 * Local Variables:
 * tab-width: 4
 * expandtab
 * ex: shiftwidth=4 tabstop=4
 */

