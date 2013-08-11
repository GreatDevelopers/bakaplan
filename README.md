BaKa Plan
=========

This software creates seating plan for examinations. It provides five 
different strategies to create seat plan.

REQUIREMENTS:
-------------

    1) GNU G++ Compiler
    2) Configure public_html and cgi-bin in home
    3) CGICC Library
    4) MySQL Connector for C++
    5) Boost Library
    6) jwSMTP Library
    7) libharu PDF Library
    8) exim4 mail server

Installation of requirements

1) GNU G++ Compiler
    
Run following command in terminal to install
    
    $ sudo apt-get install g++

2) Configure public_html/cgi-bin folder for executing files on browser.<br>
Assuming you already installed apache if not then run following
command in terminal

    $ sudo apt-get install apache2
    
**Steps to configure public_html**
        
    $ mkdir ~/public_html
    
    $ sudo a2enmod userdir
        
    $ sudo service apache2 restart
        
Give 755 permissions to public_html directory
        
    $ chmod -R 755 ~/public_html
        
Now open http://localhost/~username in browser.
Here username is your login name.
    
**Steps to configure cgi-bin in public_html**
    
    $ sudo a2enmod cgi
    
    $ sudo a2enmod cgid
    
    $ sudo service apache2 restart
     
    $ cd ~/public_html
    
    $ mkdir cgi-bin
    
    $ cd /etc/apache2
    
    $ sudo vim sites-available/default
    
Add following text in file:
    
    ScriptAlias /cgi-bin/ /home/*/public_html/cgi-bin/
    <Directory "/home/*/public_html/cgi-bin">
        AllowOverride None
        Options +ExecCGI -MultiViews +SymLinksIfOwnerMatch
        SetHandler cgi-script
        Order allow,deny
        Allow from all
    </Directory>
    
Save it and then restart apache

    $ sudo service apache2 restart
    
3) CGICC Library<br>

Run following command in terminal
    
    $ sudo apt-get install libcgicc-dev

OR

Download any latest package from http://ftp.gnu.org/gnu/cgicc/<br>
    
Then run following commands in terminal
    
    $ tar xzf cgicc-X.X.X.tar.gz 
    
    $ cd cgicc-X.X.X/ 
  
    $ ./configure --prefix=/usr 
    
    $ make
    
    $ sudo make install
    
<!--    NOTE: If you got permission error then use sudo with command.-->

4) MySQL and MySQL Connector for C++

Run following commands in terminal

    $ sudo apt-get install mysql-server mysql-client
    
    $ sudo apt-get install libmysql++

    $ sudo apt-get install libmysql++-dev

5) Boost Library

Run following command in terminal

    $ sudo apt-get install libboost1.53-dev 

6) jwSMTP Library

Download
[jwSMTP](http://sourceforge.net/projects/jwsmtp/files/latest/download) Library

Follow steps to install

    $ cd ~/Downloads
    $ tar -xzf jwsmtp-X.X.X.tar.gz
    $ cd jwsmtp-X.X.X
    $ ./configure
    $ make
    $ sudo make install

    NOTE: If you got error in */mailer.cpp or */demo2.cpp file then
    include string header file in that. And again run make
    
7) libharu PDF Library

Download
[libharu](https://github.com/libharu/libharu/tarball/master)
Library

Follow the steps to install

    $ cd ~/Downloads
    $ tar -xzf libharu-libharu-RELEASE_2_3_0RC2-61-g22e741e.tar.gz
    $ cd libharu-libharu-22e741e
    $ cmake -G 'Unix Makefiles'
    $ make
    $ sudo make install
    
    NOTE: If you get any error regarding cmake, then run
    $ sudo apt-get install cmake
    to install cmake
    
8) exim4 Mail Server

Run the following commands in terminal

    $ sudo apt-get install exim4
    $ sudo dpkg-reconfigure exim4-config
    
A Mail Server Configuration window will appear.<br>
Follow the following instructions to configure the mail server.

    1) The first page is just and introduction. Press ENTER
    2) On the second page choose the second option i.e 
       mail sent by smarthost; received via SMTP or fetchmail and 
       press ENTER.
    3) Next Keep the system mail name as it is and press ENTER.
    4) Just Press Enter for the next page.
    5) The next page asks you to enter IP addresses to listen on
       incoming SMTP connections. Leave it as it is and Press ENTER
    6) Even on the next page let the value be the default one and 
       Press ENTER.
    7) Leave the next page as it is and Press ENTER.
    8) The next page asks you for IP address or host name of the outgoing
       smarthost. Enter “smtp.example.com::587″. Where example refers to
       gmail, yahoo or any other mail service provider and 587 is port number.
    9) The Next page asks you if you want to hide local mail name in 
       outgoing mail? Choose “No”.
    10)The Next asks you if you want to keep number of DNS-queries minimal?
       Choose “No”.
    11)On the next page choose the  delivery method for local mail as
       mbox format in /var/mail/.
    12)Next page asks you if you want to split configuration into small
       files? Choose “No”. 
    13)Next keep root and postmaster mail recipient empty.

Now terminal will show that MTA is being restarted.<br>
After this is done, run the following command in terminal

    $ sudo vim /etc/exim4/passwd.client

Add following in the file

    *:USERNAME@example.com:PASSWORD.

    Where, USERNAME is  a valid email address and PASSWORD is  password for USERNAME.



INSTALLATION:
-------------
Check [INSTALLATION](https://github.com/GreatDevelopers/bakaplan/blob/master/INSTALLATION.txt) steps for using this software.

AUTHORS:
--------
<b>Mentor and Manager</b>

Dr. Hardeep Singh Rai

Website: http://gndec.ac.in/~hsrai

<b>[Developers](https://github.com/GreatDevelopers/bakaplan/wiki/Contributors)</b>

Mandeep Kaur

Website: http://mandeepsimak.wordpress.com

Email: baithnekaplan \[AT\] gmail.com

