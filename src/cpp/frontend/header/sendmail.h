/**
 *
 *       \file       sendmail.h
 *
 *       \brief      SendMail class declaration for sending mails to
 *                   user for registration or reset password link as
 *                   confirmation mail
 *
 *       \compiler   g++\n
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       \license    GNU General Public License\n
 *       \copyright  Copyright (c) 2013, GreatDevelopers\n
 *                   https://github.com/GreatDevelopers
 */

#ifndef SENDMAIL_H
#define SENDMAIL_H

#include <iostream>
#include "jwsmtp/jwsmtp.h"

#include "sendmail_detail.h"

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

        string setSender,                    /**< Sender's email id */
               setSubject,                     /**< Subject of mail */
               setMessage,                /**< Plain/Rich text mail */
               setServer,     /**< Server: localhost or domain name */
               htmlMessage,               /**< Message in html form */
               url;                   /**< Confirmation link or url */
    public:
        SendMail();
        
        /**
         *  Setting mail information 
         */
        void SetMailData();

        /**
         *  HTML Message of mail 
         */
        void SetHTMLMessage(string regKey, string mail);

        /**
         *  Registration emial for new user 
         */
        void RegistrationMail(string setRecipient, string regKey);

        /**
         *  Sending mail to reset password 
         */
        void ResetPasswordMail(string setRecipient, string regKey);

        /**
         *  Contacl mail to developer send by user 
         */
        void ContactMail(string setSender, string msg);

        ~SendMail();
    
};

#endif

/*
 * Local Variables:
 * tab-width: 4
 * expandtab
 * ex: shiftwidth=4 tabstop=4
 */

