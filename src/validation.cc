/**
 *       \file       validation.cc
 *
 *       \brief      Definition of member functions of Validation
 *                   class
 *
 *       \version    0.6
 *       \date       Wednesday 20 March 2013 05:05:48  IST\n
 *       Compiler    gcc
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

/**
 *  include validation.h file 
 */
#include "validation.h"

/**
 *      \class  Validation
 *      \fn     Validation :: Validation()
 *      \brief  constructor
 */

Validation :: Validation()
{
    // constructor
}

/**
 *      \class  Validation
 *      \fn     Validation :: ReadStrategyDetail)
 *      \brief  Read strategy option selected by user
 */

void Validation :: ReadStrategyDetail()
{
    strategyChoice = readField.ReadFieldValue(fieldName.strategyChoice);
    projectID = readField.ReadFieldValue(fieldName.projectID);

    database.InsertStrategy(projectID, strategyChoice);

    WriteStrategyDetail();
}

/**
 *      \class  Validation
 *      \fn     Validation :: WriteStrategyDetail()
 *      \brief  Write strategy detail in file as I/p file used by
 *              backend processing.
 */

void Validation :: WriteStrategyDetail()
{
    fileName  = INPUT_FOLDER;
    fileName += PID + projectID + STRATEGY_IN;

    outFile.open(fileName.c_str());

    outFile << strategyChoice;

    outFile.close();
}

/**
 *      \class  Validation
 *      \fn     Validation :: ReadValidation()
 *      \brief  Reading info. from validation file for checing
 *              strategy is valid or not
 */

void Validation :: ReadValidation()
{
    fileName  = OUTPUT_FOLDER;
    fileName += PID + projectID + VALIDATION_OUT;

    inFile.open(fileName.c_str());
    
    while(inFile.good())
    {
        getline(inFile, temp);
        if(temp == "Y")
            next = "Y";
        else
        {
            cout << temp << brk;
        }
    }

    inFile.close();
}

/**
 *      \class  Validation
 *      \fn     Validation :: ValidationPage()
 *      \brief  For creatinf html page for showing validation details
 */

void Validation :: ValidationPage()
{
    ContextType();
    
    Header("Validation");
    
    DivStart("validation", "");               /* (id, classname) */

    LogoutLink();
    
    cout << brk;
    
    ReadStrategyDetail();
    //cout << readField.ReadCookie("SessionID");

    strategy.Main(projectID);

    cout << startH1 << " Validation " << endH1 << brk;

    ReadValidation();

    FormStart("validation", "examdetail.html", "POST");
    
    InputField("hidden", fieldName.projectID, projectID);

    cout << brk << brk;

    if( next == "Y")
        Button("next", "submit", "btn", "NEXT");

    FormEnd();
    DivEnd();

    Footer();
}

/**
 *      \class  Validation
 *      \fn     Validation :: ~Validation()
 *      \brief  Destructor
 */

Validation :: ~Validation()
{
    // destructor
}
