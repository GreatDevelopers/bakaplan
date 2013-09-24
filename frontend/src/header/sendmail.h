/**
 *       \file       sendmail.h
 *
 *       \brief      Declaration of SendMail Class usinf jwSMTP
 *                   library
 *
 *       \version    0.8
 *       \date       Saturday 06 April 2013 07:46:27  IST\n
 *       Compiler    g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

#ifndef SENDMAIL_H
#define SENDMAIL_H

#include <iostream>
#include "jwsmtp/jwsmtp.h"

#include "sendmail-detail.h"

using namespace jwsmtp;
using namespace std;

/**
 *      \class  SendMail
 *      \brief  Class for sending mail to user for registeration and
 *              for changing password.
 */

class SendMail
{
    protected:

        string setSender,
               setSubject,
               setMessage,
               setServer,
               htmlMessage,
               url;
    public:
        SendMail();
        void SetMailData();
        void SetHTMLMessage(string regKey, string mail);
        void RegistrationMail(string setRecipient, string regKey);
        void ResetPasswordMail(string setRecipient, string regKey);
        void ContactMail(string setSender, string msg);
        ~SendMail();
    
};

#endif
