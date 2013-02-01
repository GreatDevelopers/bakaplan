BaKa Plan
============

This software creates seating plan for examinations. It provides four different
strategies to create seat plan.

REQUIREMENTS:
----------------------------
1) GNU G++ Compiler
    
    Run following command in terminal to install
    
    $ sudo apt-get install g++

2) Configure public_html/cgi-bin folder for executing files on browser.<br>
    
    **Steps to configure public_html** May 2013 
    
        $ mkdir public_html
    
        $ cd /etc/apache2/mods-enabled
    
        $ sudo ln -s ../mods-available/userdir.conf userdir.conf
    
        $ sudo ln -s ../mods-available/userdir.load userdir.load
    
        $ sudo /etc/init.d/apache2 restart
    
    Now open http://localhost/~username in browser.
    Here username is your login name.
    
    **Steps to configure cgi-bin in public_html**
    
        $ sudo a2enmod cgi
    
        $ sudo a2enmod cgid
    
        $ sudo a2enmod userdir
    
        $ sudo /etc/init.d/apache2 restart
     
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

    Download any latest package from http://ftp.gnu.org/gnu/cgicc/<br>
    
    Then run following commands in terminal
    
    $ tar xzf cgicc-X.X.X.tar.gz 
    
    $ cd cgicc-X.X.X/ 
  
    $ ./configure --prefix=/usr 
    
    $ make
    
    $ sudo make install
<!--    NOTE: If you got permission error then use sudo with command.-->

INSTALLATION:
----------------------------
Check [INSTALLATION](https://github.com/GreatDevelopers/bakaplan/blob/master/INSTALLATION) steps for using this software.

INPUT FORMAT:
----------------------------
[USER GUIDE](https://github.com/GreatDevelopers/bakaplan/blob/master/USER%20GUIDE)

AUTHORS:
----------------------------
<b>Mentor and Manager</b>

Dr. Hardeep Singh Rai

Website: http://gndec.ac.in/~hsrai

<b>[Developers](https://github.com/GreatDevelopers/bakaplan/wiki/Contributors)</b>

Mandeep Kaur

Website: http://mandeepsimak.wordpress.com

Email: baithnekaplan@gmail.com

