/**
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
 * Description:  <HTML>
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
 * Description:  </HTML>
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
 * Description:  <HEAD>
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
 * Description:  </HEAD>
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
 * Description:  <BODY>
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
 * Description:  </BODY>
 *--------------------------------------------------------------------
 */

void HTMLTags :: BodyEnd()
{
    cout << "</BODY>" << endl;
}
