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

