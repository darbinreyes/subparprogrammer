The http server I currently have in use is called apache2, in particular, the
built in apache2 installation on Mac OS X version 10.12.6. On Mac OS X, apache2
can also be installed using "mac ports”, I may switch to that installation in
case I want to take advantage of apache2 extension modules which is greatly
simplified by using mac ports.

To begin with this will contain the configuration files I had to touch in order
to get the server running. The configuration files will be placed under
directory names that reflect exactly the default location of those files on the
system.

I will add configuration files to this repo in the same order as the guide I used:

https://medium.com/@JohnFoderaro/how-to-set-up-apache-in-macos-sierra-10-12-bca5a5dfffba

Steps to configure:

* Telling Apache where to serve content from.
* Create the config. file.
* The file name should be your username on your Mac and ends with the .conf extension.
* The location of this file should be /etc/apache2/users
** A copy of this file is in this repo. under ./servers/http/etc/apache2/users/
* Set permissions for darbinreyes.conf with "sudo chmod 644 username.conf"
** 644=owner=rw|group=r|other=r.
* Next config. file: /etc/apache2/httpd.conf.
** A copy of this file is in this repo. under ./servers/http/etc/apache2/
** A this point the guide instructs you to comment out several lines in httpd.conf.
* Next config. file: /etc/apache2/extra/httpd-userdir.conf
** A copy of this file is in this repo. under ./servers/http/etc/apache2/extra/
** The comments in this file are useful.
** The guide instructs you to comment out a single line in httpd-userdir.conf.
* DONE with configuration. Lastly, restart apache with "sudo apachectl restart".

# Using the nano editor.

* ^ represents the control key.
* Close and save this file, using control + X, followed by Y, then Enter.
* If a file doesn't exists, to create it specify the new file’s name while using nano.
* control+W = text search a file. = control+F in GUI editors.
