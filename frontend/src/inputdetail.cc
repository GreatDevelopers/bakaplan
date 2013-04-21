/*
 * ===================================================================
 *
 *       Filename:  inputdetail.cc
 *
 *    Description:  Definition of member functions of InputDetail class
 *
 *        Version:  0.6
 *        Created:  Sunday 24 February 2013 01:31:21  IST
 *       Compiler:  gcc
 *
 *         Author:  Mandeep Kaur, meghasimak@gmail.com
 *        License:  GNU General Public License
 *      Copyright:  Copyright (c) 2013, Great Developers
 *
 * ===================================================================
 */

/**-------------------------------------------------------------------
 *  Include detail.h file
 *------------------------------------------------------------------*/

#include "header/inputdetail.h"

/**-------------------------------------------------------------------
 *  Definition of member functions
 *------------------------------------------------------------------*/

/**
 *--------------------------------------------------------------------
 *       Class:  InputDetail
 *      Method:  InputDetail :: InputDetail()
 * Description:  Constructor
 *--------------------------------------------------------------------
 */

InputDetail :: InputDetail()
{
    // constructor
}

/**
 *--------------------------------------------------------------------
 *       Class:  InputDetail
 *      Method:  InputDetail :: Header(string titleName)
 * Description:  common header for all pages(start html, head, body)
 *--------------------------------------------------------------------
 */

void InputDetail :: Header(string titleName)
{
    
    page.HTMLStart();
    page.Head(titleName);
    page.PageLayout :: Header();
    page.BodyStart();
    page.Logo("BaKaPlan");
}

/**
 *--------------------------------------------------------------------
 *       Class:  InputDetail
 *      Method:  InputDetail :: Footer()
 * Description:  Common for all pages(end body, html)
 *--------------------------------------------------------------------
 */

void InputDetail :: Footer()
{
    page.BodyEnd();
    page.HTMLEnd();
}

/**
 *--------------------------------------------------------------------
 *       Class:  InputDetail
 *      Method:  InputDetail :: IntToString(int value)
 * Description:  Convert Int to String using stringstream object
 *--------------------------------------------------------------------
 */

string InputDetail :: IntToString(int value)
{
     ss.clear(); ss.str("");          /*  Empty stringstream object */
     ss << value;
     return ss.str();
}

/**
 *--------------------------------------------------------------------
 *       Class:  ReadInputField
 *      Method:  ReadInputField :: StringToInt(string value)
 * Description:  Converts string value to integer
 *--------------------------------------------------------------------
 */

int InputDetail :: StringToInt(string value)
{
    return atoi(value.c_str());
}

/**
 *      \class  InputDetail
 *      \fn     InputDetail :: Message(string msg)
 *      \brief  For dispaying message if user fill wrong info in field 
 *      \param  msg Message string
 */

void InputDetail :: ErrorMessage(string msg)
{
    if(msg != "")
    {   
        page.DivStart("msg", "error");
        cout <<  msg << page.brk << page.brk;
        page.DivEnd();
    }
}

/**
 *      \class  Login
 *      \fn     Login :: Time()
 *      \brief  For finding current time nd date of system
 *      \retun  Return string having result
 */

string InputDetail :: Time()
{
    ostringstream time;
    const boost::posix_time::ptime now=                             
    boost::posix_time::second_clock::local_time();                  
    boost::posix_time::time_facet*const f = new                     
    boost::posix_time::time_facet("%H-%M-%S");                      
    time.imbue(std::locale(time.getloc(),f));                         
    time << now;

    return time.str();
}

/**
 *      \class  InputDetail
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
