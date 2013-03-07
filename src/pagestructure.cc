/*
 * ===================================================================
 *
 *       Filename:  pagestructure.cc
 *
 *    Description:  Function definitions of PageStructureMaker Class
 *
 *        Version:  0.6
 *        Created:  Friday 15 February 2013 05:27:13  IST
 *       Compiler:  gcc
 *
 *         Author:  Mandeep Kaur, meghasimak@gmail.com
 *        License:  GNU General Public License
 *      Copyright:  Copyright (c) 2013, Great Developers
 *
 * ===================================================================
 */

/**-------------------------------------------------------------------
 *  Include htmltags.h header files
 *------------------------------------------------------------------*/

#include "pagestructure.h"

/**
 *--------------------------------------------------------------------
 *       Class:  PageStructureMaker
 *      Method:  PageStructureMaker :: PageStructureMaker()
 * Description:  Constructor
 *--------------------------------------------------------------------
 */

PageStructureMaker :: PageStructureMaker()
{
    cout << "Content-type:text/html\n\n" << endl;
    SetHTMLVariables();
}

/**
 *--------------------------------------------------------------------
 *       Class:  PageStructureMaker
 *      Method:  PageStructureMaker :: SetHTMLVariables()
 * Description:  Set values of common HTML tags in respective
 *               variables.
 *--------------------------------------------------------------------
 */

void PageStructureMaker :: SetHTMLVariables()
{
    startH1     =       "<h1>";                 /* H1 tag */
    endH1       =       "</h1>";                
    startH3     =       "<h3>";                 /* H3 tag */
    endH3       =       "</h3>";                
    startTD     =       "<td>";                 /* TD(Table Data) */
    endTD       =       "</td>";
    startTH     =       "<th>";                 /* TH(Table Header) */
    endTH       =       "</th>";
    startTR     =       "<tr>";                 /* TR(Table Row) */
    endTR       =       "</tr>";
    startB      =       "<b>";                  /* Bold */
    endB        =       "</b>";
    brk         =       "</br>";                /* Break Tag */
}

/**
 *--------------------------------------------------------------------
 *       Class:  PageStructureMaker
 *      Method:  PageStructureMaker :: HTMLStart()
 * Description:  Display \<HTML\> Tag 
 *--------------------------------------------------------------------
 */

void PageStructureMaker :: HTMLStart()
{
    cout << "<HTML>" << endl;
}

/**
 *--------------------------------------------------------------------
 *       Class:  PageStructureMaker
 *      Method:  PageStructureMaker :: HTMLEnd()
 * Description:  Display \</HTML\>
 *--------------------------------------------------------------------
 */

void PageStructureMaker :: HTMLEnd()
{
    cout << "</HTML>" << endl;
}

/**
 *--------------------------------------------------------------------
 *       Class:  PageStructureMaker
 *      Method:  PageStructureMaker :: HeadStart()
 * Description:  Display \<HEAD\>
 *--------------------------------------------------------------------
 */

void PageStructureMaker :: HeadStart()
{
    cout << "<HEAD>" << endl;
}

/**
 *--------------------------------------------------------------------
 *       Class:  PageStructureMaker
 *      Method:  PageStructureMaker :: HeadEnd()
 * Description:  Display \</HEAD\>
 *--------------------------------------------------------------------
 */

void PageStructureMaker :: HeadEnd()
{
    cout << "</HEAD>" << endl;
}

/**
 *--------------------------------------------------------------------
 *       Class:  PageStructureMaker
 *      Method:  PageStructureMaker :: Title(string pageTitle)
 * Description:  Display Page Tile
 *--------------------------------------------------------------------
 */

void PageStructureMaker :: Title(string pageTitle)
{
    cout << "<TITLE>" << pageTitle << "</TITLE>" << endl;
}

/**
 *--------------------------------------------------------------------
 *       Class:  PageStructureMaker
 *      Method:  PageStructureMaker :: CSS(string href)
 * Description:  Add External CSS file
 *--------------------------------------------------------------------
 */

void PageStructureMaker :: CSS(string href)
{
    cout << "<link href=\"" << href << "\"" 
         << " rel=\"stylesheet\" media=\"screen\">"
         << endl;
}

/**
 *--------------------------------------------------------------------
 *       Class:  PageStructureMaker
 *      Method:  PageStructureMaker :: Javascript(string src)
 * Description:  Add external Javascript file
 *--------------------------------------------------------------------
 */

void PageStructureMaker :: Javascript(string src)
{
    cout << "<script src=\"" << src << "\"></script>" << endl;
}

/**
 *--------------------------------------------------------------------
 *       Class:  PageStructureMaker
 *      Method:  PageStructureMaker :: BodyStart()
 * Description:  Display \<BODY\>
 *--------------------------------------------------------------------
 */

void PageStructureMaker :: BodyStart()
{
    cout << "<BODY align=\"center\">" << endl;
    DivStart("wrapper", "");                    /* (id, classname) */
}

/**
 *--------------------------------------------------------------------
 *       Class:  PageStructureMaker
 *      Method:  PageStructureMaker :: BodyEnd()
 * Description:  Display \</BODY\>
 *--------------------------------------------------------------------
 */

void PageStructureMaker :: BodyEnd()
{
    DivEnd();
    cout << "</BODY>" << endl;
}

/**
 *--------------------------------------------------------------------
 *       Class:  PageStructureMaker
 *      Method:  PageStructureMaker :: DivStart(string id, 
 *               string className)
 * Description:  Start Div Section with id and className(for CSS)
 *--------------------------------------------------------------------
 */

void PageStructureMaker :: DivStart(string id, string className)
{
    cout << "<div id = \"" << id << "\" class = \"" << className
         << " \">" << endl;
}

/**
 *--------------------------------------------------------------------
 *       Class:  PageStructureMaker
 *      Method:  PageStructureMaker :: DivEnd()
 * Description:  Close Div Section
 *--------------------------------------------------------------------
 */

void PageStructureMaker :: DivEnd()
{
    cout << "</div>" << endl;
}

/**
 *--------------------------------------------------------------------
 *       Class:  PageStructureMaker
 *      Method:  PageStructureMaker :: FormStart(string name, 
 *               string action, string method)
 * Description:  Start Form with name, action and method(GET/POST)
 *--------------------------------------------------------------------
 */

void PageStructureMaker :: FormStart(string name, string action, 
                           string method)
{
    cout << "<form name = \"" << name << "\" action = \"" << action
         << "\" method = \"" << method << "\" >" << endl;
}

/**
 *--------------------------------------------------------------------
 *       Class:  PageStructureMaker
 *      Method:  PageStructureMaker :: FormEnd()
 * Description:  Close Form
 *--------------------------------------------------------------------
 */

void PageStructureMaker :: FormEnd()
{
    cout << "</form>" << endl;
}

/**
 *--------------------------------------------------------------------
 *       Class:  PageStructureMaker
 *      Method:  PageStructureMaker :: TableStart(string id, 
 *               string className)
 * Description:  Start Table with id and className(CSS) attributes
 *--------------------------------------------------------------------
 */

void PageStructureMaker :: TableStart(string id, string className)
{
    cout << "<table id = \"" << id << "\" class=\"" << className
         << "\">" << endl;
}

/**
 *--------------------------------------------------------------------
 *       Class:  PageStructureMaker
 *      Method:  PageStructureMaker :: TableEnd()
 * Description:  Close Table tag
 *--------------------------------------------------------------------
 */

void PageStructureMaker :: TableEnd()
{
    cout << "</table>" << endl;
}

/**
 *--------------------------------------------------------------------\n
 *       Class:  PageStructureMaker \n
 *      Method:  PageStructureMaker :: ListStart(string listType) \n
 * Description:  Start any list like ul, ol, etc. \n
 *--------------------------------------------------------------------
 */

void PageStructureMaker :: ListStart(string listType)
{
    cout << "<" << listType << ">";
}

/**
 *--------------------------------------------------------------------\n
 *       Class:  PageStructureMaker \n
 *      Method:  PageStructureMaker :: ListEnd(string listType) \n
 * Description:  Close List Tag \n
 *--------------------------------------------------------------------
 */

void PageStructureMaker :: ListEnd(string listType)
{
    cout << "</" << listType << ">";
}

/**
 *--------------------------------------------------------------------\n
 *       Class:  PageStructureMaker \n
 *      Method:  PageStructureMaker :: ListItem(string listItem) \n
 * Description:  List Item  \n
 *--------------------------------------------------------------------
 */

void PageStructureMaker :: ListItem(string listItem)
{
    cout << "<li>" << listItem << "</li>";
}

/**
 *--------------------------------------------------------------------\n
 *       Class:  PageStructureMaker \n
 *      Method:  PageStructureMaker :: Anchor(string href) \n
 * Description:  Anchor Tag \n
 *--------------------------------------------------------------------
 */

void PageStructureMaker :: Anchor(string href, string target)
{
    cout << "<a href = \"" << href << "\">" << target << "</a>";
}

/**
 *--------------------------------------------------------------------
 *       Class:  PageStructureMaker
 *      Method:  PageStructureMaker :: InputField(string type, 
 *               string name, string value)
 * Description:  Create Input fields like text field, submit
 *               button, etc.
 *--------------------------------------------------------------------
 */

void PageStructureMaker :: InputField(string type, string name, 
                            int nameNo, string value)
{
    stringstream ss;
    //ss.str(name);
    ss << nameNo;
    name += ss.str();
    
    InputField(type, name, value);
    /*  
    cout << "<input type=\"" << type << "\" name=\"" << name;
    if( nameNo != 0)
        cout << nameNo;
    cout << "\"" << " value = \"" << value << "\" "
         << " onfocus = \"OnFocus(this.value, this.name, \"" << value 
         << "\")\""
         << ">" << endl;*/
}

/**
 *--------------------------------------------------------------------\n
 *       Class:  PageStructureMaker \n
 *      Method:  PageStructureMaker :: InputField(string type, 
 *               string name, string value) \n
 * Description:  For creating input field with 3 arguments \n
 *--------------------------------------------------------------------
 */

void PageStructureMaker :: InputField(string type, string name, 
                                      string value)
{
    cout << "<input type=\"" << type << "\" name=\"" << name;
    cout << "\"" << " value = \"" << value << "\" " 
         << " onfocus = \"OnFocus(this.value, this.name, \"" << value
         << "\")\""
         << ">" << endl;
}

/**
 *--------------------------------------------------------------------
 *       Class:  PageStructureMaker
 *      Method:  PageStructureMaker :: SelectFieldStart(string name)
 * Description:  Create Select Field
 *--------------------------------------------------------------------
 */

void PageStructureMaker :: SelectFieldStart(string name)
{
    cout << "<select name=\"" << name << "\">";
}

/**
 *--------------------------------------------------------------------
 *       Class:  PageStructureMaker
 *      Method:  PageStructureMaker :: SelectFieldEnd()
 * Description:  Close select field
 *--------------------------------------------------------------------
 */

void PageStructureMaker :: SelectFieldEnd()
{
    cout << "</select>" << endl;
}

/**
 *--------------------------------------------------------------------
 *       Class:  PageStructureMaker
 *      Method:  PageStructureMaker :: SelectOptionStart(string value, 
 *               string selected)
 * Description:  Options for select 
 *--------------------------------------------------------------------
 */

void PageStructureMaker :: SelectOptionStart(string value, string selected)
{
    cout << "<option value=\"" << value << "\" ";
    if(selected == "y" || selected == "Y")
        cout << "selected";
    cout << " > ";// << value << "</option>";
}

/**
 *--------------------------------------------------------------------
 *       Class:  PageStructureMaker
 *      Method:  PageStructureMaker :: SelectOptionEnd()
 * Description:  Close select option
 *--------------------------------------------------------------------
 */

void PageStructureMaker :: SelectOptionEnd()
{
    cout << "</option>";
}

/**
 *--------------------------------------------------------------------
 *       Class:  PageStructureMaker
 *      Method:  PageStructureMaker :: Button(string id, string type, 
 *               string className, string value)
 * Description:  Create button(next, submit, etc)
 *--------------------------------------------------------------------
 */

void PageStructureMaker :: Button(string id, string type, 
                            string className, string value)
{
    cout << "<button id = \"" << id << "\" type = \"" << type 
         << "\" class=\"" << className << "\">" << value
         << "</button>" << endl;
}
