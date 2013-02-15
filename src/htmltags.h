/**
 * ===================================================================
 *
 *       Filename:  htmltags.h
 *
 *    Description:  This file includes basic HTML tags that included
 *    for all pages like <HTML>, <HEAD>, </HEAD>, etc.
 *
 *        Version:  0.6
 *        Created:  Friday 15 February 2013 05:08:42  IST
 *       Compiler:  gcc
 *
 *         Author:  Mandeep Kaur, meghasimak@gmail.com
 *        License:  GNU General Public License
 *      Copyright:  Copyright (c) 2013, Great Developers
 *
 * ===================================================================
 */


/**
 * ===================================================================
 *        Class:  HTMLTags
 *  Description:  Declaration
 * ===================================================================
 */

class HTMLTags
{
    private:

    protected:

    public:
        HTMLTags();                             /** Constructor */
        void HTMLStart();                       /** <HTML>  */
        void HTMLEnd();                         /** </HTML> */
        void HeadStart();                       /** <HEAD>  */
        void HeadEnd();                         /** </HEAD> */
        void Title(string pageTitle);           /** <TITLE> </TITLE>*/
        void CSS(string href);                  /** Add External CSS */
        void Javascript(string src);            /** Add Javascript File */
        void BodyStart();                       /** <BODY> */
        void BodyEnd();                         /** </BODY> */
};
