/**
 *       \file       sendmail.cc
 *
 *       \brief      Function Definitons of SendMail Class
 *
 *       \version    0.6
 *       \date       Saturday 06 April 2013 07:58:56  IST\n
 *       Compiler    g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

/**
 *   Include sendmail.h
 */

#include "header/sendmail.h"

/**
 *      \class  SendMail
 *      \fn     SendMail :: SendMail()
 *      \brief  Constructor
 */

SendMail :: SendMail()
{
    // Constructor
}

/**
 *      \class  SendMail
 *      \fn     SendMail :: SetMailData()
 *      \brief  Settinf variable that are used to send mail
 */

void SendMail :: SetMailData()
{
    setSender   =   "meghasimak@gmail.com";
    setSubject  =   "BaKaPlan : Account Activation";
    setMessage  =   "Plain text message body";
    setServer   =   "localhost";//"localhost";
}

/**
 *      \class  SendMail
 *      \fn     SendMail :: SetHTMLMessage(string regKey)
 *      \brief  Setting body of mail(message ie send to user)
 *      \param  regKey Registration Key
 */

void SendMail :: SetHTMLMessage(string regKey)
{
    url  = "http://localhost/~mandy/cgi-bin/bakaplan";
    url += "/frontend/src/confirm.html?Key=" + regKey;
              
    htmlMessage  = "<html> <body>";
    htmlMessage += "Thanks for registration. </br></br>";
    htmlMessage += "To complete your registration process, you need ";
    htmlMessage += "to confirm your Email by clicking following link.";
    htmlMessage += "</br></br>" + url + "</br></brk>";
    htmlMessage += "</body> </html>";
}

/**
 *      \class  SendMail
 *      \fn     SendMail :: RegistrationMail(string setRecipient, 
 *                                           string regKey)
 *      \brief  Sending registration mail to user
 *      \param
 */

void SendMail :: RegistrationMail(string setRecipient, string regKey)
{
    SetMailData();

    mailer mail;
    mail.addrecipient(setRecipient);
    mail.setsender(setSender);
    mail.setsubject(setSubject);
    mail.setmessage(setMessage);
    mail.setserver(setServer);

    SetHTMLMessage(regKey);
    
    mail.setmessageHTML(htmlMessage);

    mail.send();

}

/**
 *      \class  SendMail
 *      \fn     SendMail :: ~SendMail()
 *      \brief  Destructor
 */

SendMail :: ~SendMail()
{
    // Destructor
}
