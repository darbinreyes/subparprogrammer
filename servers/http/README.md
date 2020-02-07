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

# Steps to configure:

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
## Optional steps.
### Optional Step 1: Virtual Hosts
* Currently my index.html is accessed via
* "http://darbinreyes.com/~darbinreyes/darbinreyes.com/" == "http://localhost/~darbinreyes/darbinreyes.com/"
* After this optional step I should be able to access index.html via
* darbinreyes.com.localhost // currently this returns FORBIDDEN.
* After this change you need to edit the Mac host file to add a unique name per project.
* Configuration of virutal hosts.
** Edit /etc/apache2/extra/httpd-vhosts.conf
** A copy of this file is in this repo. under ./servers/http/etc/apache2/extra/

```
# You may use the command line option '-S' to verify your virtual host
# configuration.
```

* "edit the host file to create hostnames for Foo and Bar:"
* edit config file "/etc/hosts"
** A copy of this file is in this repo. under ./servers/http/etc/hosts
* DONE with virtual host configuration. Lastly, restart apache with "sudo apachectl restart".
** CONFIRMED. "http://darbinreyes.com.localhost/" works.

* x Next: read through "Optional Step 2: Configuring PHP". // I won't be using PHP any time soon though.
* Next: read docs/man-pages for conf files. Point darbinreyes.com to index.html.

Currently,

http://darbinreyes.com/~darbinreyes/darbinreyes.com/

http://localhost/~darbinreyes/darbinreyes.com/

http://darbinreyes.com.localhost/

point to

/Users/darbinreyes/Sites/darbinreyes.com/index.html

and

http://darbinreyes.com/

returns "403 Forbidden" "You don't have permission to access / on this server."

and

http://darbinreyes.com.darbinreyes.com/

results in "server IP address could not be found."

### Decoding the apache config files.

* /etc/apache2/users/darbinreyes.conf

 * Note use of xml style syntax in each .conf file.
 
 * List of all directives. http://httpd.apache.org/docs/2.4/mod/directives.html
 
 * Meaning of "\<Directory\>" http://httpd.apache.org/docs/2.4/mod/core.html#directory

	 * Apply the 3 given "directives" to the specified directory ONLY (includes the whole dir. subtree). Note that "directives" have "contexts" within which they apply. In this case, the context is server config and virtual host.

     * Directive 1. http://httpd.apache.org/docs/2.4/mod/core.html#allowoverride
     
	     * When the server finds an .htaccess file (as specified by AccessFileName), it needs to know which directives declared in that file can override earlier configuration directives.
	     
	     * When this directive is set to All, then any directive which has the .htaccess Context is allowed in .htaccess files.
	     
	     * What is an .htaccess file? ANS: http://httpd.apache.org/docs/2.4/mod/core.html#accessfilename
     
			    * It is the default name of a file called a "distributed configuration file". The default file name can be overiden using the "AccessFileName" directive. It tells the server where to look for directives when it receives a request.
     
     
     
     * Directive 2. http://httpd.apache.org/docs/2.4/mod/core.html#options
     
	       * The Options directive controls which server features are available in a particular directory.
	     
	         * Indexes If a URL which maps to a directory is requested and there is no DirectoryIndex (e.g., index.html) in that directory, then mod_autoindex will return a formatted listing of the directory.
	
	         * MultiViews Content negotiated "MultiViews" are allowed using mod_negotiation.
	
	             * mod_negotiation. Content negotiation, or more accurately content selection, is the selection of the document that best matches the clients capabilities, from one of several available documents. There are two implementations of this.  (1. A type map, 2. multiviews search). 
	
	
	             * A Multiviews search is enabled by the Multiviews Options. If the server receives a request for /some/dir/foo and /some/dir/foo does not exist, then the server reads the directory looking for all files named foo.*
	             
	             * FollowSymLinks. The server will follow symbolic links in this directory. This is the default setting.

     * Directive 3. http://httpd.apache.org/docs/2.4/mod/mod_authz_core.html#require
	     * This directive tests whether an authenticated user is authorized according to a particular authorization provider and the specified restrictions. mod_authz_core provides the following generic authorization providers:
	     * Require all granted. Access is allowed unconditionally.


* /etc/apache2/httpd.conf

* /etc/apache2/extra/httpd-userdir.conf

* /etc/apache2/extra/httpd-vhosts.conf

# Using the nano editor.

* ^ represents the control key.
* Close and save this file, using control + X, followed by Y, then Enter.
* If a file doesn't exists, to create it specify the new file’s name while using nano.
* control+W = text search a file. = control+F in GUI editors.


