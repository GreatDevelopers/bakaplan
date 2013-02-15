/*
 * ===================================================================
 *
 *       Filename:  htmltags.cc
 *
 *    Description:  Function definitions of HTMLTags Class
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

/**
 *--------------------------------------------------------------------
 *       Class:  HTMLTags
 *      Method:  HTMLTags :: HTMLTags()
 * Description:  Constructor
 *--------------------------------------------------------------------
 */

HTMLTags :: HTMLTags()
{
    cout << "Content-type:text/html\n\n" << endl;
}

/**
 *--------------------------------------------------------------------
 *       Class:  HTMLTags
 *      Method:  HTMLTags :: HTMLStart()
 * Description:  Display <HTML> Tag 
 *--------------------------------------------------------------------
 */

void HTMLTags :: HTMLStart()
{
    cout << "<HTML>" << endl;
}

/**
 *--------------------------------------------------------------------
 *       Class:  HTMLTags
 *      Method:  HTMLTags :: HTMLEnd()
 * Description:  Display </HTML>
 *--------------------------------------------------------------------
 */

void HTMLTags :: HTMLEnd()
{
    cout << "</HTML>" << endl;
}

/**
 *--------------------------------------------------------------------
 *       Class:  HTMLTags
 *      Method:  HTMLTags :: HeadStart()
 * Description:  Display <HEAD>
 *--------------------------------------------------------------------
 */

void HTMLTags :: HeadStart()
{
    cout << "<HEAD>" << endl;
}

/**
 *--------------------------------------------------------------------
 *       Class:  HTMLTags
 *      Method:  HTMLTags :: HeadEnd()
 * Description:  Display </HEAD>
 *--------------------------------------------------------------------
 */

void HTMLTags :: HeadEnd()
{
    cout << "</HEAD>" << endl;
}

/**
 *--------------------------------------------------------------------
 *       Class:  HTMLTags
 *      Method:  HTMLTags :: Title(string pageTitle)
 * Description:  Display Page Tile
 *--------------------------------------------------------------------
 */

void HTMLTags :: Title(string pageTitle)
{
    cout << "<TITLE>" << pageTitle << "</TITLE>" << endl;
}

/**
 *--------------------------------------------------------------------
 *       Class:  HTMLTags
 *      Method:  HTMLTags :: CSS(string href)
 * Description:  Add External CSS file
 *--------------------------------------------------------------------
 */

void HTMLTags :: CSS(string href)
{
    cout << "<link href=\"" << href << "\"" 
         << " rel=\"stylesheet\" media=\"screen\">"
         << endl;
}

/**
 *--------------------------------------------------------------------
 *       Class:  HTMLTags
 *      Method:  HTMLTags :: Javascript(string src)
 * Description:  Add external Javascript file
 *--------------------------------------------------------------------
 */

void HTMLTags :: Javascript(string src)
{
    cout << "<script src=\"" << src << "\"></script>" << endl;
}

/**
 *--------------------------------------------------------------------
 *       Class:  HTMLTags
 *      Method:  HTMLTags :: BodyStart()
 * Description:  Display <BODY>
 *--------------------------------------------------------------------
 */

void HTMLTags :: BodyStart()
{
    cout << "<BODY>" << endl;
}

/**
 *--------------------------------------------------------------------
 *       Class:  HTMLTags
 *      Method:  HTMLTags :: BodyEnd()
 * Description:  Display </BODY>
 *--------------------------------------------------------------------
 */

void HTMLTags :: BodyEnd()
{
    cout << "</BODY>" << endl;
}

/**
 *--------------------------------------------------------------------
 *       Class:  HTMLTags
 *      Method:  HTMLTags :: DivStart(string id, string className)
 * Description:  Start Div Section with id and className(for CSS)
 *--------------------------------------------------------------------
 */

void HTMLTags :: DivStart(string id, string className)
{
    cout << "<div id = \"" << id << "\" class = \"" << className
         << " \">" << endl;
}

/**
 *--------------------------------------------------------------------
 *       Class:  HTMLTags
 *      Method:  HTMLTags :: DivEnd()
 * Description:  Close Div Section
 *--------------------------------------------------------------------
 */

void HTMLTags :: DivEnd()
{
    cout << "</div>" << endl;
}

/**
 *--------------------------------------------------------------------
 *       Class:  HTMLTags
 *      Method:  HTMLTags :: FormStart(string name, string action,
 *               string method)
 * Description:  Start Form with name, action and method(GET/POST)
 *--------------------------------------------------------------------
 */

void HTMLTags :: FormStart(string name, string action, string method)
{
    cout << "<form name = \"" << name << "\" action = \"" << action
         << "\" method = \"" << method << "\" >" << endl;
}

/**
 *--------------------------------------------------------------------
 *       Class:  HTMLTags
 *      Method:  HTMLTags :: FormEnd()
 * Description:  Close Form
 *--------------------------------------------------------------------
 */

void HTMLTags :: FormEnd()
{
    cout << "</form>" << endl;
}

/**
 *--------------------------------------------------------------------
 *       Class:  HTMLTags
 *      Method:  HTMLTags :: TableStart(string id, string className)
 * Description:  Start Table with id and className(CSS) attributes
 *--------------------------------------------------------------------
 */

void HTMLTags :: TableStart(string id, string className)
{
    cout << "<table id = \"" << id << "\" class=\"" << className
         << "\">" << endl;
}

/**
 *--------------------------------------------------------------------
 *       Class:  HTMLTags
 *      Method:  HTMLTags :: TableEnd()
 * Description:  Close Table tag
 *--------------------------------------------------------------------
 */

void HTMLTags :: TableEnd()
{
    cout << "</table>" << endl;
}

/**
 *--------------------------------------------------------------------
 *       Class:  HTMLTags
 *      Method:  HTMLTags :: InputField(string type, string name, 
 *               string value)
 * Description:  Create Input fields like text field, submit
 *               button, etc.
 *--------------------------------------------------------------------
 */

void HTMLTags :: InputField(string type, string name, string value)
{
    cout << "<input type=\"" << type << "\" name=\"" << name << "\""
         << "value = \" "<< value << "\" >" << endl;
}

/**
 *--------------------------------------------------------------------
 *       Class:  HTMLTags
 *      Method:  HTMLTags :: SelectFieldStart(string name)
 * Description:  Create Select Field
 *--------------------------------------------------------------------
 */

void HTMLTags :: SelectFieldStart(string name)
{
    cout << "<select name=\"" << name << "\">";
}

/**
 *--------------------------------------------------------------------
 *       Class:  HTMLTags
 *      Method:  HTMLTags :: SelectFieldEnd()
 * Description:  Close select field
 *--------------------------------------------------------------------
 */

void HTMLTags :: SelectFieldEnd()
{
    cout << "</select>" << endl;
}

/**
 *--------------------------------------------------------------------
 *       Class:  HTMLTags
 *      Method:  HTMLTags :: SelectOptionStart(string value, 
 *               string selected)
 * Description:  Options for select 
 *--------------------------------------------------------------------
 */

void HTMLTags :: SelectOptionStart(string value, string selected)
{
    cout << "<option value=\"" << value << "\" ";
    if(selected == 'y' || selected == 'Y')
        cout << "selected";
    cout << " > ";// << value << "</option>";
}

/**
 *--------------------------------------------------------------------
 *       Class:  HTMLTags
 *      Method:  HTMLTags :: SelectOptionEnd()
 * Description:  Close select option
 *--------------------------------------------------------------------
 */

void HTMLTags :: SelectOptionEnd()
{
    cout << "</option>";
}
