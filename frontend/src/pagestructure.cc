/*
 * ===================================================================
 *
 *       Filename:  pagestructure.cc
 *
 *    Description:  Function definitions of PageStructureMaker Class
 *
 *        Version:  0.7
 *        Created:  Friday 15 February 2013 05:27:13  IST
 *       Compiler:  g++
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

#include "header/pagestructure.h"

/**
 *--------------------------------------------------------------------
 *       Class:  PageStructureMaker
 *      Method:  PageStructureMaker :: PageStructureMaker()
 * Description:  Constructor
 *--------------------------------------------------------------------
 */

PageStructureMaker :: PageStructureMaker()
{
//    cout << "Content-type:text/html\n\n" << endl;
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
    startTD     =       "<td align = \"center\">";/* TD(Table Data) */
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
    cout << "<HTML lang=\"en\">" << endl;
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
    cout << "<HEAD>" << endl
         << "<meta charset=\"UTF-8\">" << endl;
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
         << " rel=\"stylesheet\" media=\"screen\" type=\"text/css\">"
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
    cout << "<BODY  class=\"coloredBody\" >" << endl;
/*     
    cout << " <nav class=\"side-menu\"> "
         << " <span id=\"toggle-menu\"> <p id=\"toggle-menu-circle\"> "
         << "Show Menu </p> </span> "
         << " <h3> Ba<span class=\"ka\">ka</span> Plan</h3>"
         << "<a href=\"index.html\"> Home </a>"
         << "<a href=\"about.html\"> About </a>"
         << "<a href=\"contribute.html\"> Contribute </a>"
         << "<a href=\"contact.html\">Contact  </a>"
         << "<a href=\"login.html\"> Log Out </a>"
         << "</nav> ";
*/
    DivStart("page-wrap", "");                    /* (id, classname) */
//    cout << "<h1>~</h1>" << endl;
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
/*    cout <<"<SCRIPT>"
         << "var loginValidator = new FormValidator('FormLogin', [{"
         << "name: 'EmailID',"
         << "rules: 'valid_email'"
         << "}, {"
         << "  name: 'Password',"
         << "  display: 'Password',"
         << "      rules: 'min_length[8]'"
         << "}], function(errors, event) {"
        << "if (errors.length > 0) {"
        << "alert(\"error\");"
        << " }"
        <<"    });"
        <<" </SCRIPT>"; */
          string js ="../../BaKaPlan/javascript/validateit.js" ;
          Javascript(js);
/*           cout << "<script type=\"text/javascript\" "
               << "src=\"../../BaKaPlan/js/sidemenu.js\"></script>";*/
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

void PageStructureMaker :: FormStart(string name, // cssClass
                                     string action, string method, 
                                     string onSubmit)
{
    
    cout << "<form "//class = \"" << cssClass
         << "\" name = \"" << name 
         << "\" action = \"" << action
         << "\" method = \"" << method << "\"";
    if (onSubmit != "")
        cout << " onsubmit = \'" << onSubmit << "\'";
    else
        cout << " >" << endl;
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
    string js;
    cout << "</form>" << endl;
    js = "../../BaKaPlan/javascript/validate.min.js";
//    js = "http://rickharrison.github.io/validate.js/validate.min.js";
    Javascript(js);
     
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
         << "\" align = \"center\">" << endl;
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
 *--------------------------------------------------------------------\n
 *       Class:  PageStructureMaker \n
 *      Method:  PageStructureMaker :: Label(string forValue, 
 *                                           string value) \n
 * Description:  For adding label in html page \n
 *--------------------------------------------------------------------
 */

void PageStructureMaker :: Label(string forField, string value)
{
    cout << "<label for=\"" << forField << "\" >" 
         << value << "</label>";
}

/**
 *--------------------------------------------------------------------\n
 *       Class:  PageStructureMaker \n
 *      Method:  PageStructureMaker :: InputField(string type, 
 *               string name, string value) \n
 * Description:  For creating input field with 3 arguments \n
 *--------------------------------------------------------------------
 */

void PageStructureMaker :: InputField(string type, 
                                      string name, string placeholder,
                                      string value,
                                      string onFocus)
{
    cout << "<input "//class = \"" << className << "\" "
         << "type=\"" << type << "\" name=\"" << name;
    cout << "\" id = \"" << name << "\" ";

    if(type == "hidden" || type == "radio")
    {
        cout << "value = \"" << placeholder << "\" ";
    }
    else if(type == "button")
    {
        cout << "value = \"" << value << "\" "
             << "onclick = \"" << placeholder << "\" ";
    }
    else
    {
        cout << "placeholder = \"" << placeholder << "\" ";
        if(value != "")    
        {
            cout << "value = \"" << value << "\" ";
        }
    }
    if(onFocus == "date" && type == "text")
    {
        cout << "onfocus = \"showCalendarControl(this);\" ";
    }
    cout << "required=\"yes\" />" << endl;
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
                                      int nameNo, string placeholder,
                                      string value)
{
    stringstream ss;
    //ss.str(name);

    string onFocus;
    if(name == "Date")
        onFocus = "date";
    else 
        onFocus = "";
 
    ss << nameNo;
    name += ss.str();   
    
    if(value == "")
        InputField(type, name, placeholder, value, onFocus);
    else
        InputField(type, name, placeholder, value, onFocus);
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
                            string className, string value, 
                            string onClick)
{
    cout << "<button id = \"" << id << "\" type = \"" << type 
         << "\" class=\"" << className << "\" ";

    if(onClick != "")
        cout << "onClick = \"" << onClick << "\" ";
         
    cout << ">" << value
         << "</button>" << endl;
}
