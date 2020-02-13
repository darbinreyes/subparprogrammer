The http server I currently have in use is called apache2, in particular, the
built in apache2 installation on Mac OS X version 10.12.6. On Mac OS X, apache2
can also be installed using "mac ports”, I may switch to that installation in
case I want to take advantage of apache2 extension modules which is greatly
simplified by using mac ports.

To begin with this will contain the configuration files I had to touch in order
to get the server running. The configuration files will be placed under
directory names that reflect exactly the default location of those files on the
system.

I will add configuration files to this repo in the same order as the [guide I used](https://medium.com/@JohnFoderaro/how-to-set-up-apache-in-macos-sierra-10-12-bca5a5dfffba)

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
* http://darbinreyes.com/~darbinreyes/darbinreyes.com/ points to http://localhost/~darbinreyes/darbinreyes.com/
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
* Main doc page for [apache](http://httpd.apache.org/docs/2.4/).
* List of all [modules](http://httpd.apache.org/docs/2.4/mod/).
* List of all [directives](http://httpd.apache.org/docs/2.4/mod/directives.html).

* /etc/apache2/users/darbinreyes.conf

 * Note use of xml style syntax in each .conf file. 
 * Meaning of [\<Directory>](http://httpd.apache.org/docs/2.4/mod/core.html#directory)
   * Apply the 3 given "directives" to the specified directory ONLY (includes the whole dir. subtree). Note that "directives" have "contexts" within which they apply. In this case, the context is server config and virtual host.
     * [Directive 1. allowoverride](http://httpd.apache.org/docs/2.4/mod/core.html#allowoverride)
         * When the server finds an .htaccess file (as specified by AccessFileName), it needs to know which directives declared in that file can override earlier configuration directives.
         * When this directive is set to All, then any directive which has the .htaccess Context is allowed in .htaccess files.
       * [What is an .htaccess file? ANS:](http://httpd.apache.org/docs/2.4/mod/core.html#accessfilename)
          * It is the default name of a file called a "distributed configuration file". The default file name can be overridden using the "AccessFileName" directive. It tells the server where to look for directives when it receives a request.
     
     * [Directive 2. options](http://httpd.apache.org/docs/2.4/mod/core.html#options)
     
         * The Options directive controls which server features are available in a particular directory.

           * Indexes If a URL which maps to a directory is requested and there is no DirectoryIndex (e.g., index.html) in that directory, then mod_autoindex will return a formatted listing of the directory.

           * MultiViews Content negotiated "MultiViews" are allowed using mod_negotiation.

               * mod_negotiation. Content negotiation, or more accurately content selection, is the selection of the document that best matches the clients capabilities, from one of several available documents. There are two implementations of this.  (1. A type map, 2. multiviews search).


               * A Multiviews search is enabled by the Multiviews Options. If the server receives a request for /some/dir/foo and /some/dir/foo does not exist, then the server reads the directory looking for all files named foo.*

               * FollowSymLinks. The server will follow symbolic links in this directory. This is the default setting.

     * [Directive 3. require](http://httpd.apache.org/docs/2.4/mod/mod_authz_core.html#require)
         * This directive tests whether an authenticated user is authorized according to a particular authorization provider and the specified restrictions. mod_authz_core provides the following generic authorization providers:
         * Require all granted. Access is allowed unconditionally.

* /etc/apache2/httpd.conf

  * This is the **main** Apache HTTP server configuration file. It contains the configuration **directives** that give the server its instructions.
  * ServerRoot. Prepended to control file paths. Directory tree under which the server's configuration, error, and log files are kept.
  * Listen.
  * LoadModule. to use the functionality of a module.
  * \<IfModule unixd_module>. User/Group setting.
  * 'Main' server configuration. defaults for any <VirtualHost> containers. All of these directives may appear inside <VirtualHost> containers. default settings will be overridden.
  * ServerAdmin.
  * ServerName.
  * \<Directory />. AllowOverride none. Require all denied. Deny access to the entirety of your server's filesystem.
  * DocumentRoot: The directory out of which you will serve your documents.
  * Require all granted. Controls who can get stuff from this server.
  * DirectoryIndex index.html. sets the file that Apache will serve if a directory is requested.
  * Apple specific filesystem protection.
  * ErrorLog: The location of the error log file.
  * LogLevel: Control the number of messages logged to the error_log.
  * \<IfModule log_config_module>. format nicknames. The location and format of the access logfile. 
  * Redirect: Allows you to tell clients about documents that used to exist in your server's namespace, but do not anymore.
  * Alias: Maps web paths into filesystem paths and is used to access content that does not live under the DocumentRoot.
  * ScriptAlias: This controls which directories contain server scripts. documents in the target directory are treated as applications.
  * ScriptSock: On threaded servers. socket used to communicate with the CGI daemon of mod_cgid.
  * \<IfModule headers_module>.
  * \<IfModule mime_module>. AddType allows you to add to or override the MIME configuration. AddEncoding allows you to have certain browsers uncompress information on the fly. AddType define those extensions to indicate media types. AddHandler allows you to map certain file extensions to "handlers". Filters allow you to process content before it is sent to the client.
  * MIMEMagicFile. The mod_mime_magic module allows the server to use various hints from the contents of the file itself to determine its type.
  * [ErrorDocument](http://httpd.apache.org/docs/2.4/mod/core.html#errordocument) 500 "The server made a boo boo." **Customizable error responses come in three flavors: 1) plain text 2) local redirects 3) external redirects**
  * MaxRanges: Maximum number of Ranges in a request before returning the entire resource.
  * EnableMMAP and EnableSendfile. This usually improves server performance.
  * TraceEnable. TraceEnable off causes the core server and mod_proxy to return a 405 (Method not allowed) error to the client.
     * Doc for this directive mentions RFC2616(=HTTP). Recall request headers, request body, request method.
  * Supplemental configuration. The configuration files in the /private/etc/apache2/extra/ directory can be included. or you may simply copy their contents here and change as necessary.
    * Server-pool management (MPM specific)
    * Multi-language error messages
    * Fancy directory listings
    * Language settings
    * User home directories
    * Real-time info on requests and configuration
    * Virtual hosts
    * Local access to the Apache HTTP Server Manual
    * Distributed authoring and versioning (WebDAV)
    * Various default settings
    * Configure mod_proxy_html to understand HTML4/XHTML1
    * Secure (SSL/TLS) connections
  * END of httpd.conf.
 
* /etc/apache2/extra/httpd-userdir.conf
  * UserDir: The name of the directory that is appended onto a user's home directory if a ~user request is received. 
     * **Note that you must also set the default access control for these directories, as in the example below.**
     * This note is almost certainly the sole purpose of /etc/apache2/users/darbinreyes.conf.
  * Include /private/etc/apache2/users/*.conf. Control access to UserDir directories. The following is an example for a site where these directories are restricted to read-only.
    * \<IfModule bonjour_module>. What is this module? It's not listed in the module list. It seems to be some sort of apple specific apache module.
      * https://habilis.net/mod-bonjour-fix/
      * https://opensource.apple.com/source/apache_mod_bonjour/apache_mod_bonjour-9/
      * https://developer.apple.com/bonjour/
   * END of httpd-userdir.conf.
  
* /etc/apache2/extra/httpd-vhosts.conf

  * If you want to maintain multiple domains/hostnames on your machine you can setup VirtualHost containers for them.
  * Most configurations use only name-based virtual hosts so the server doesn't need to worry about IP addresses. This is indicated by the asterisks in the directives below.
    * \<VirtualHost \*:80>
  * Almost any Apache directive may go into a VirtualHost container.
  *  The first VirtualHost section is used for all requests that do not match a ServerName or ServerAlias in any \<VirtualHost> block.
  * END of httpd-vhosts.conf.
 
* /etc/hosts

  * I don't think this is an apache conf file but rather a system file. But the guide asked me to change it so I'll decode it here.
  * Host Database.
  * localhost is used to configure the loopback interface **when** the system is booting. **Do not change this entry.**
    * WTF is loopback interface?
      * Maybe it refers to the fact that a request to localhost (a.k.a. 127.0.0.1) is a request to the same machine that sent the request instead of say, a remote server's machine. The request loops back to the sender.
        * 127.0.0.1	localhost // self evident
        * 255.255.255.255	broadcasthost
        * ::1             localhost
        * fe80::1%lo0	localhost
        * 127.0.0.1       darbinreyes.com.localhost // This is based on the tutorial.
 * END of hosts.

# Creating symbolic links for apache conf files and darbinreyes.com web directory.

* Here we have to make the decision wether the git repo should contain the symbolic link or wether the git repo should contain the actual file. It seems reasonable to choose one or the other and not a mix. In either case, I will be able to modify the files in the git repo and affect the apache server without having to copy files to keep them in sync. I choose to make the git repo contain the links and keep the original files where they currently are.

* Potential problem. By using hard links, I can now modify my original apache conf files and have any changes to those files be reflected as changes in my git repo. But git cannot distinguish the hard link to the conf files from the from the original files in the repository, it appears as the same file. This means that the result of changes those files is different on my MBP vs. my MBA. On my MBP, a change to the conf files in the repo will have an immediate affect on apache. On my MBA, the same changes will only affect the copy of the file in the repo. This is OK, but since it appears that git does not allow symbolic links to directories to be tracked (git add errors out) I will have to break the above "no mixing" rule. For my web content, the symbolic link will be from the Sites/darbinreyes.com directory to the files in the git repo at subparprogrammer/web/darbinreyes.com/. For the .conf files and hosts file, it is the opposite, I created a hard link is from the git repo to the original files.


* [x] link from 
* /Users/darbinreyes/Sites/darbinreyes.com
* to
* subparprogrammer/web/darbinreyes.com/

```bash
$ ln -s original_directory link_directory
```

* [x] link from 
* subparprogrammer/servers/http/etc/hosts
* to
* /etc/hosts

```bash
$ ln originalfile
```
```bash
$ pwd
/Users/darbinreyes/Sites
$ ln -s /Users/darbinreyes/dev/private_dev/subparprogrammer/web/darbinreyes.com/ darbinreyes.com
```
```bash
$ pwd
/Users/darbinreyes/dev/private_dev/subparprogrammer/servers/http/etc
$ ln ./../../../../../../../../etc/hosts
```

* [x] link from
* subparprogrammer/servers/http/etc/apache2/extra/httpd-vhosts.conf
* to
* /etc/apache2/extra/httpd-vhosts.conf

* [x] link from
* subparprogrammer/servers/http/etc/apache2/extra/httpd-userdir.conf
* to
* /etc/apache2/extra/httpd-userdir.conf

* [x] link from
* subparprogrammer/servers/http/etc/apache2/httpd.conf
* to
* /etc/apache2/httpd.conf

* [x] link from
* subparprogrammer/servers/http/etc/apache2/users/darbinreyes.conf
* to
* /etc/apache2/users/darbinreyes.conf

# Pointing darbinreyes.com to /Users/darbinreyes/Sites/darbinreyes.com

* Trial and error.

* Added the following to httpd-vhosts.conf and restarting apache.

```xml
#Virtual Host Entry for darbinreyes.com
<VirtualHost *:80>
  DocumentRoot "/Users/darbinreyes/Sites/darbinreyes.com"
  ServerName darbinreyes.com
  ErrorLog "/private/var/log/apache2/darbinreyes.com-error_log"
  CustomLog "/private/var/log/apache2/darbinreyes.com-access_log" common
</VirtualHost>
```

* Result: Works over my WIFI but not over LTE.

* Will adding the following to the hosts file fix it over LTE?

127.0.0.1  darbinreyes.com

* Result: Yes, that fixed it.

# TODO
* [ ] Read [getting started.](http://httpd.apache.org/docs/2.4/getting-started.html)
* [ ] URL [mapping.](http://httpd.apache.org/docs/2.4/urlmapping.html)
* [ ] Virtual [hosts.](http://httpd.apache.org/docs/2.4/vhosts/)
* [x] Add a custom 403 error response.
* [x] Point darbinreyes.com to index.html.
* [x] Since /etc/apache2/users/darbinreyes.conf contains "FollowSymLinks", it seems I should be able to make my current site directory /Users/darbinreyes/Sites/darbinreyes.com into a symbolic link which points to index.html in my git repo. This way I can change index.html in one place (the git repo on my MBP) instead of two. Can I do this for the conf files by telling apache to use the conf files in my git repo?
    * I just discovered that when apache is restarted it copies /etc/apache2/users/darbinreyes.conf to /private/etc/apache2/users/darbinreyes.conf
* [x] Add a vitualhost under devtest.localhost. This will point to the copy of my website that I will make changes to and test. When I complete a change I can copy the completed and stable change to the main website directory. Remove symbolic link from Sites/darbinreyes.com.
* [ ] Add a vitualhost under devtest.darbinreyes.com. 

# Using the nano editor.

* ^ represents the control key.
* Close and save this file, using control + X, followed by Y, then Enter.
* If a file doesn't exists, to create it specify the new file’s name while using nano.
* control+W = text search a file. = control+F in GUI editors.


