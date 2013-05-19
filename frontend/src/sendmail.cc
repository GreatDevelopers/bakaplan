/**
 *       \file       sendmail.cc
 *
 *       \brief      Function Definitons of SendMail Class
 *
 *       \version    0.7
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
    setSender   =   SENDER_EMAILID;
    setMessage  =   "Plain text message body";
    setServer   =   SERVER_MAIL;//"localhost";//"202.164.53.122";
}

/**
 *      \class  SendMail
 *      \fn     SendMail :: SetHTMLMessage(string regKey)
 *      \brief  Setting body of mail(message ie send to user)
 *      \param  regKey Registration Key
 */

void SendMail :: SetHTMLMessage(string regKey, string mail)
{
    url  = "http://" + setServer  + "/~mandeep/cgi-bin/bp/";
    if(mail == "register")
        url += "confirm?Key=" + regKey;
    else
        url += "reset?type=3&Key=" + regKey;
              
    htmlMessage  = "<html> <body>";
    if(mail == "register")
    {
        htmlMessage += "Thanks for registration. </br></br>";
        htmlMessage += "To complete your registration process, you need ";
        htmlMessage += "to confirm your Email by clicking following link.";
        htmlMessage += "</br></br>" + url + "</br></br>";
    }
    else
    {
        htmlMessage += "To rest your password, you need ";
        htmlMessage += "to confirm your Email by clicking following link.";
        htmlMessage += "</br></br>" + url + "</br></br>";
    }

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

    setSubject  =   "BaKaPlan : Account Activation";

    mailer mail;
    mail.addrecipient(setRecipient);
    mail.setsender(setSender);
    mail.setsubject(setSubject);
    mail.setmessage(setMessage);
    mail.setserver(setServer);

    SetHTMLMessage(regKey, "register");
    
    mail.setmessageHTML(htmlMessage);

    mail.send();

}
void SendMail :: ResetPasswordMail(string setRecipient, string regKey)
{
    SetMailData();

    setSubject  =   "BaKaPlan : Reset Password";

    mailer mail;
    mail.addrecipient(setRecipient);
    mail.setsender(setSender);
    mail.setsubject(setSubject);
    mail.setmessage(setMessage);
    mail.setserver(setServer);

    SetHTMLMessage(regKey, "reset");
    
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
