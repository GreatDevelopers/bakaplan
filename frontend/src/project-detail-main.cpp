/**
 *       \file       project-detail-main.cpp
 *
 *       \brief      Project detail form for starting new or old
 *                   project \n
 *
 *       \compiler   g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com \n
 *       \license    GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

#include "header/project.h"

int main(void)
{
    
    ProjectDetail project;
    string sID = project.readField.ReadFieldValue("sid");

    STRING_VEC sessionID;

    project.database.SelectColumn(sessionID, "SessionID" ,
                                 "SessionDetail");
    /* Matching session id with values in database */
    if ( ( find(sessionID.begin(), sessionID.end(), sID) 
         != sessionID.end() ) )               /* If Session ID valid */
    {
        vector<string> vecTemp;
        string where = "SessionID = \"" + sID + "\"";
        project.database.SelectColumn(vecTemp, "EmailID", "SessionDetail", where);

        string emailID = vecTemp[0];

        project.ProjectDetailPage(emailID);
    }
    else
    {
        cout << "Content-type=text/html\n\n";
    }

}
