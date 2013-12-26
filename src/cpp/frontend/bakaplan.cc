/**
 *       \file       bakaplan.cc
 *
 *       \brief      Main Class for calling all pages and executing
 *                   functions accoding to it flow \n
 *
 *       \compiler   g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com \n
 *       \license    GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

#include "header/bakaplan.h"
#include "header/fieldname.h"

/**
 *      \fn     BaKaPlan :: BaKaPlan()
 *      \brief  constructor
 */
BaKaPlan :: BaKaPlan()
{
    // default constructor
    
    sessionID = "sid";
    
    // Initializing page titles
    pageTitle.push_back("Logout");              // step 0
    pageTitle.push_back("Project Detail");      // step 1
    pageTitle.push_back("Class Detail");        // step 2
    pageTitle.push_back("Roll No Detail");      // step 3
    pageTitle.push_back("Exam Detail");         // step 4
}

/**
 *      \fn     BaKaPlan :: StartPage(string title, int sid)
 *      \brief  Starting of HTML Page(head, body section)
 *      \param  title Title of html page
 *      \param  sid session id
 */
void BaKaPlan :: StartPage(string pageTitle, int sid)
{
    cout << HTTPHTMLHeader() << endl;

    cout << html() 
         << head() << title(pageTitle);

    CommonCSSFiles();
    CommonJSFiles();

    cout << head()
         << body().set("class", "coloredBody");
    
    SideMenu(sid);

    cout << cgicc::div().set("class", "page-wrap");

    cout << h1().set("id", "tipTarget") << "~" << h1()
         << cgicc::div().set("id", "msg") << cgicc::div();
}

/**
 *      \fn     BaKaPlan :: EndPage()
 *      \brief  Ending of html page(close body and html tags)
 */
void BaKaPlan :: EndPage()
{
    cout << cgicc::div();
    JS("js/sidemenu.js");

    cout << body()
         << html();
}

/**
 *      \fn     BaKaPlan :: SessionExpired(int &sid)
 *      \brief  Read session id and then check whether session expired
 *              or not
 *      \param  sid Session ID
 *      \return Return false id session expired else true
 */
bool BaKaPlan :: SessionExpired(int& sid)
{
    sid = StringToInt(readField.ReadFieldValue(sessionID));

    return true;
}

/**
 *      \fn     BaKaPlan :: Logout()
 *      \brief  Logout user
 */
void BaKaPlan :: Logout()
{


}

/**
 *      \fn     BaKaPlan :: Main(int)
 *      \brief  Main Program
 *      \param  step Step to identify part of work flow
 */
void BaKaPlan :: Main(int step)
{
    int sid = 6;
    StartPage(pageTitle[step], sid);
    switch(step)
    {
        case 1:
            project.ProjectDetailPage();
            break;

        case 0:
            // Log out
            Logout();

        default:
            project.ProjectDetailPage();
    }
    EndPage();
}

/**
 *      \fn     BaKaPlan :: ~BaKaPlan()
 *      \brief  Desrtuctor 
 *      \param
 */
BaKaPlan :: ~BaKaPlan()
{
    // destructor
}

/*
 * Local Variables:
 * tab-width: 4
 * expandtab
 * ex: shiftwidth=4 tabstop=4
 */

