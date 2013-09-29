/**
 *
 *       \file       sendmail.cc
 *
 *       \brief      Definitions of functions for sending emails to
 *                   user and developer.
 *
 *       \compiler   g++\n
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       \license    GNU General Public License\n
 *       \copyright  Copyright (c) 2013, GreatDevelopers\n
 *                   https://github.com/GreatDevelopers
 */

#include "header/sendmail.h"

/**
 *      \fn     SendMail :: SendMail()
 *      \brief  Constructor
 */

SendMail :: SendMail()
{
    // Constructor
}

/**
 *      \fn     SendMail :: SetMailData()
 *      \brief  Settinf variable that are used to send mail
 */

void SendMail :: SetMailData()
{
    setSender   =   SENDER_EMAILID;
    setMessage  =   "Plain text message body";
    setServer   =   "localhost";
}

/**
 *      \fn     SendMail :: SetHTMLMessage(string regKey)
 *      \brief  Setting body of mail(message ie send to user)
 *      \param  regKey  Registration Key
 *      \param  mail    Mail type - regiter/confirm/reset-password
 */

void SendMail :: SetHTMLMessage(string regKey, string mail)
{
    url  = "http://";
    url += SERVER_MAIL;
    url += "/~"; 
    url += USERNAME; 
    url += "/cgi-bin/NBP/backend/bp/";
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
    else if(mail == "reset")
    {
        htmlMessage += "To rest your password, you need ";
        htmlMessage += "to confirm your Email by clicking following link.";
        htmlMessage += "</br></br>" + url + "</br></br>";
    }
    else if(mail == "contact")
    {
        htmlMessage += regKey;
    }

    htmlMessage += "</body> </html>";
}

/**
 *      \fn     SendMail :: RegistrationMail(string setRecipient, 
 *                                           string regKey)
 *      \brief  Sending registration mail to user
 *      \param  setRecipient    Reciever's email id
 *      \param  regKey          Registration key
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

/**
 *      \fn     SendMail :: ResetPasswordMail(string setRecipient, 
 *                                            string regKey)
 *      \brief  Sending mail to user for changing password.
 *      \param  setRecipient    Reciever's email id
 *      \param  regKey          Registration key
 */
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
 *      \fn     SendMail :: ContactMail(string setSender, string msg)
 *      \brief  Sending mail to developer from user.
 *      \param  setSender    Sender's email id.
 *      \param  msg          Message send by user for developer.
 */
void SendMail :: ContactMail(string setSender, string msg)
{
    SetMailData();

    setSubject  =   "BaKaPlan : Feedback";
    string setRecipient = SENDER_EMAILID;

    mailer mail;
    mail.addrecipient(setRecipient);
    mail.setsender(setSender);
    mail.setsubject(setSubject);
    mail.setmessage(setMessage);
    mail.setserver(setServer);

    SetHTMLMessage(msg, "contact");
    
    mail.setmessageHTML(htmlMessage);

    mail.send();

}

/**
 *      \fn     SendMail :: ~SendMail()
 *      \brief  Destructor
 */
SendMail :: ~SendMail()
{
    // Destructor
}

/*
 * Local Variables:
 * tab-width: 4
 * expandtab
 * ex: shiftwidth=4 tabstop=4
 */

