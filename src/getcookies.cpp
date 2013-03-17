#include <iostream>
#include <vector>  
#include <string>  
#include <stdio.h>  
#include <stdlib.h> 

#include <cgicc/CgiDefs.h> 
#include <cgicc/Cgicc.h> 
#include <cgicc/HTTPHTMLHeader.h> 
#include <cgicc/HTMLClasses.h>

using namespace std;
using namespace cgicc;

#include "login.h"

int main ()
{
   Cgicc cgi;
   const_cookie_iterator cci;
   string pass = "EmailID";
   string emailID, sessionID;

   //cout << "Content-type:text/html\r\n\r\n";
   
   // get environment variables
   const CgiEnvironment& env = cgi.getEnvironment();

   for( cci = env.getCookieList().begin();
        cci != env.getCookieList().end(); 
        ++cci )
   {
       if(cci->getName() == "SessionID")       
       {
            sessionID = cci->getValue();
       }
       else  
       {
            if(cci->getName() == "EmailID")
                emailID = cci->getValue();
       }
   }

   Login login;
    string qry = "delete from Session where EmailID = \"" + emailID;
    qry += "\" and SessionID = \"" + sessionID + "\"";

    login.data.DeleteQuery(qry);

   login.LogoutPage();

   return 0;
}
