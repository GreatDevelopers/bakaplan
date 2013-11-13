/**
 *       \file       input-detail.cc
 *
 *       \brief      Definition of functions \n
 *
 *       \compiler   g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com \n
 *       \license    GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

#include "header/input_detail.h"
#include "header/filename.h"

namespace fn = filename;           /**< Shortname for namespace */

/**
 *      \fn     InputDetail :: InputDetail()
 *      \brief  Constructor
 */
InputDetail :: InputDetail()
{
    // Default Values
}



/**
 *      \fn     InputDetail :: IntToString(int)
 *      \brief  Converting integer to string
 *      \param  value Value to be converted into string
 */
string InputDetail :: IntToString(int value)
{
     ss.clear(); ss.str("");          /*  Empty stringstream object */
     ss << value;
     return ss.str();
}

/**
 *      \fn     InputDetail :: StringToInt(string)
 *      \brief  Converting String to Int
 *      \param  value String value to be converted into int
 */
int InputDetail :: StringToInt(string value)
{
    return atoi(value.c_str());
}

/**
 *      \fn     InputDetail :: SplitString(STRING_VEC & output,
 *              string input, string token)
 *      \brief  Split string using boost library func.
 *      \param  output  Stores result of splitted string
 *      \param  input   string for spliting
 *      \param  token   eg , or . or - any char to split string
 */

void InputDetail :: SplitString(STRING_VEC & output, string input,
                                string token)
{
    split( output, input, is_any_of(token), token_compress_on ); 
}

/**
 *      \fn     InputDetail :: FileName(string projectID, string file,
 *                                    string io)
 *      \brief  For creating filename w.r.t to projectID
 *
 *      \param  projectID Unique ID i.e. used to read file of user
 *      \param  file I/O file Name
 *      \param  fileType For defining file type i.e I/P or O/P file.
 *              If fileType == 1, Input file
 *              If fileType == 0(else), Output File
 *
 *      \return fileName This function will return file name with
 *              project ID
 */

string InputDetail :: FileName(string file, string projectID, 
                             int fileType)
{
    temp = file + projectID;

    if(fileType == 1)
        fileName = fn::name["input"] + temp + fn::name["in"];
    else
        fileName = fn::name["output"] + temp + fn::name["out"];

    return fileName;
}

/**
 *      \fn     InputDetail :: ~InputDetail()
 *      \brief  Destructor
 */
InputDetail :: ~InputDetail()
{
    // Release Objects
}

/*
 * Local Variables:
 * tab-width: 4
 * expandtab
 * ex: shiftwidth=4 tabstop=4
 */

