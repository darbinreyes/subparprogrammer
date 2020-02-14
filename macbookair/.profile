# !!!!!!!!!!!! This is NOT a bash script, its a config file !!!!!! see Evernote notes on this
# !!! Don't forget to push changes to .profile to /Users/darbinreyes/dev/private_dev/misc/my_bash/profiles/ local git repo.
#####################
# My PATH additions
#####################
# MacPorts Installer addition on 2014-04-18_at_15:25:40: adding an appropriate PATH variable for use with MacPorts.
export PROXYHOME=TRUE
export GITHOME=TRUE
export MAC_PORTS_PATH_RM=#TRUE ## hides macports binaries.

if [ "$MY_BASH_PROFILE_CALLED" = TRUE ]; then
    echo donezo path = $PATH
else
    if [ "$MAC_PORTS_PATH_RM" = TRUE ]; then
        echo Mac Ports Path Removed.
    else
        echo Using Mac Ports path
        export PATH="~/bin:/opt/local/include:/opt/local/bin:/opt/local/sbin:/opt/:$PATH" # !!! dont forget the ":" delimiter BITCH!
    fi
    echo my path = $PATH
    echo my python path = $PYTHONPATH
fi

export MY_BASH_PROFILE_CALLED=TRUE # prevent PATH env. var. from being appended to on each call to sbash.

# Make all GUI programs that are opened from my bash use my custom PATH. Fixes svn gui and sublimetext path issues.
launchctl setenv PATH $PATH

#####################
# END My PATH additions
#####################
#######################
# bash config. related
#######################
alias sbash='source ~/.profile'
alias ebash='subl ~/.profile'
#######################
# subl config. projects
#######################
alias emacportscfg='subl /Users/darbinreyes/dev/private_dev/subl_config_projects/macportsconfig/macportsconfig.sublime-project'
alias egitcfg='subl /Users/darbinreyes/dev/private_dev/subl_config_projects/gitconfig/gitconfig.sublime-project'
alias esvncfg='subl /Users/darbinreyes/dev/private_dev/subl_config_projects/svnconfig/svnconfig.sublime-project'
#######################
# END bash config. related
#######################
#######################
# Misc. OS related
#######################
alias guid='uuidgen'
alias flashstk500='avrdude -c stk500 -p m644 -e  -U flash:w:lab0.hex -P /dev/cu.usbserial-FTGFF0GH -v'
alias buildstk500='make'
alias ll='ls -l -a -G'
alias where='which'
alias find-filename='find . -name '
alias myrmdir='rm -drf'
# run a speed test from bash per http://osxdaily.com/2013/07/31/speed-test-command-line/
alias speedtest='curl -o /dev/null http://speedtest.wdc01.softlayer.com/downloads/test10.zip'
## Recursively searches current directory for file names that match *.txt.
## and prints any lines in those txt files which match the word "RIS"
#find . -name "*.txt" -print | xargs grep "RIS" 

# Find a specific process by name
alias grep-proc='ps -ax | grep '
# make sublimetext the default system text editor
# Python version override.
# alias python='python2.7'
#######################
# END Misc. OS related
#######################
#######################
# SublimeText related
#######################
alias sublgui='sudo open /Applications/Sublime\ Text.app/'
export EDITOR='subl -w'
#######################
# END SublimeText related
#######################
#######################
# Network related
#######################
alias myip='curl -4 icanhazip.com'
alias restart-apache='sudo /opt/local/apache2/bin/apachectl -k restart'
# Export no_proxy=localhost,127.0.0.0/8,*.local
# Add mysql to path https://trac.macports.org/wiki/howto/MAMP
export PATH=$PATH:/opt/local/lib/mysql51/bin
export MY_SSH_HOSTS_FILE='/Users/darbinreyes/.ssh/known_hosts'
alias rmsshh='rm $MY_SSH_HOSTS_FILE'
#######################
# Network related
#######################

if [ "$PROXYHOME" = TRUE ]; then
    export http_proxy=
    export https_proxy=
    echo Proxy set for home. $http_proxy $https_proxy
else
    export http_proxy=web-proxy.houston.hpecorp.net:8080 #proxy.houston.hpecorp.net:8080 #web-proxy.houston.hpecorp.net:8080      #web-proxy.houston.hpecorp.net:8080 # http://autocache.hpecorp.net/
    export https_proxy=web-proxy.houston.hpecorp.net:8080 #proxy.houston.hpecorp.net:8080 #web-proxy.houston.hpecorp.net:8080    #web-proxy.houston.hpecorp.net:8080
    echo Proxy set for work. $http_proxy $https_proxy
fi

export HTTP_PROXY=$http_proxy
export HTTPS_PROXY=$https_proxy

# aliases for using curl as a HP REST client.
# Example usage of curl: https://www.drupal.org/node/1795770

# Make-bash-alias-that-takes-parameter: http://stackoverflow.com/questions/7131670/make-bash-alias-that-takes-parameter

# My CURL examples/notes
# For iLO redfish , DONT FORGET THE / AT the end of URL else you get no response
# note 2 cmds - restget + restgetb // getb is for outputing just the JSON body.
# restput/patch example. NOTE: for rest writes, escape double quotes in JSON body. Outer most double quotes not required unless it contains whitespace.
## restpatch systems/1/bios/settings/ {\"Attributes\":{\"AdminName\":\"drizzy\"}}
## restput <sub-uri e.g. systems/1/bios/boot/settings/> <json-body>
## restgetbf schemastore/en/hpescalablepmem.v1_0_0.hpescalablepmem/ /private/tmp/t10.gz # write a .gzipped schema to a file
## TIP: echo arguments to a function to help debugging.
## TIP: How to decompress a .gz file and print to stdout. "gzip -d -c sa_schema.gz"
DoRestGet() {
  curl -i -H "Authorization: Basic QWRtaW5pc3RyYXRvcjpjb21wYXE=" -H "OData-Version: 4.0" --insecure --get $MY_ILO_HOSTNAME/redfish/v1/$1
}

DoRestGetBody() {
  curl -H "Authorization: Basic QWRtaW5pc3RyYXRvcjpjb21wYXE=" -H "OData-Version: 4.0" --insecure --get $MY_ILO_HOSTNAME/redfish/v1/$1
}

DoRestGetBodyFile() {
  curl -o $2 -H "Authorization: Basic QWRtaW5pc3RyYXRvcjpjb21wYXE=" -H "OData-Version: 4.0" --insecure --get $MY_ILO_HOSTNAME/redfish/v1/$1
}

alias restget='DoRestGet'
alias restgetb='DoRestGetBody'
alias restgetbf='DoRestGetBodyFile'

# Same as "restgetb" but with the _BIOS_ provider ID in the request header.
# Example: #> restgetb_bios_provider_id providers/ | jq . #
DoRestGetBodyBiosProvId() {
  curl -H "X-CHRP-RIS-Provider-ID : 5D7AD9AF2A4245468C650C652DD4B6E9" -H "Authorization: Basic QWRtaW5pc3RyYXRvcjpjb21wYXE=" -H "OData-Version: 4.0" --insecure --get $MY_ILO_HOSTNAME/redfish/v1/$1
}

alias restgetb_bios_provider_id='DoRestGetBodyBiosProvId'

# Same as restgetb_bios_provider_id above but the provider ID is taken from argument $2.
# Example: #> restgetb_provider_id providers/ 0001900591GS158GJW9JOJ3R | jq . "
DoRestGetBodyProvId() {
  curl -H "X-CHRP-RIS-Provider-ID : $2" -H "Authorization: Basic QWRtaW5pc3RyYXRvcjpjb21wYXE=" -H "OData-Version: 4.0" --insecure --get $MY_ILO_HOSTNAME/redfish/v1/$1
}

alias restgetb_provider_id='DoRestGetBodyProvId'

DoRestPut() {
  curl -i -H "Content-Type: application/json" -H "Authorization: Basic QWRtaW5pc3RyYXRvcjpjb21wYXE=" -H "OData-Version: 4.0" --insecure  $MY_ILO_HOSTNAME/redfish/v1/$1 -d $2 -X PUT
}

alias restput='DoRestPut'

DoRestPatch() {
  echo $2
  curl -i -H "Content-Type: application/json" -H "Authorization: Basic QWRtaW5pc3RyYXRvcjpjb21wYXE=" -H "OData-Version: 4.0" --insecure  $MY_ILO_HOSTNAME/redfish/v1/$1 -d $2 -X PATCH
}

alias restpatch='DoRestPatch'

############## curl POST aliases ##############


# Same as "restput/patch" but for the HTTP POST method.
# Example #> restpost providers/ {\"AdminName\":\"drizzy\"} #
DoRestPost() {
  curl -i -H "Content-Type: application/json" -H "Authorization: Basic QWRtaW5pc3RyYXRvcjpjb21wYXE=" -H "OData-Version: 4.0" --insecure  $MY_ILO_HOSTNAME/redfish/v1/$1 -d $2 -X POST
}

alias restpost='DoRestPost'

# Same "restpost" above but takes the body of from a file read from $2.
# FYI: For meaning of "@" sign in "-d" arg. curl man page. Search for --data-binary.
# Example: #> restpostbf providers/ cats_ext_prov_registration.json #
DoRestPostBodyFile() {
  curl -i -H "Content-Type: application/json" -H "Authorization: Basic QWRtaW5pc3RyYXRvcjpjb21wYXE=" -H "OData-Version: 4.0" --insecure  $MY_ILO_HOSTNAME/redfish/v1/$1 -d @$2 -X POST
}

alias restpostbf='DoRestPostBodyFile'

# Same "restpostbf" above but takes an provider's ID read from $2; takes the body from a file read from $3.
# FYI: For meaning of "@" sign in "-d" arg. curl man page. Search for --data-binary.
# Example: #> restpostbf providers/ cats_ext_prov_registration.json #
DoRestPostBodyFileProvId() {
  curl -i -H "X-CHRP-RIS-Provider-ID : $2" -H "Content-Type: application/json" -H "Authorization: Basic QWRtaW5pc3RyYXRvcjpjb21wYXE=" -H "OData-Version: 4.0" --insecure  $MY_ILO_HOSTNAME/redfish/v1/$1 -d @$3 -X POST
}

alias restpostbf_provider_id='DoRestPostBodyFileProvId'

############## curl DELETE aliases ##############
# hard coded delete provider registration. TODO: add args.
alias restdelprov='curl -i -H "Content-Type: application/json" -H "Authorization: Basic QWRtaW5pc3RyYXRvcjpjb21wYXE=" -H "OData-Version: 4.0" -H "X-CHRP-RIS-Provider-ID : 5D7AD9AF2A4245468C650C652DD4B6E0"  --insecure  $MY_ILO_HOSTNAME/redfish/v1/providers/5/  -X DELETE'

# curl alias to delete BIOS rest external provider. Uses hard-coded provider ID.
# Example: #>  #
DoRestDeleteBiosProvId() {
  curl -i -H "Content-Type: application/json" -H "Authorization: Basic QWRtaW5pc3RyYXRvcjpjb21wYXE=" -H "OData-Version: 4.0" -H "X-CHRP-RIS-Provider-ID : 5D7AD9AF2A4245468C650C652DD4B6E9"  --insecure  $MY_ILO_HOSTNAME/redfish/v1/$1  -X DELETE
}

alias restdel_bios_provider_id='DoRestDeleteBiosProvId'

# Same as "restdel_bios_provider_id" but the provider ID is read from $2.
# Example: #>  #
DoRestDeleteProvId() {
  curl -i -H "Content-Type: application/json" -H "Authorization: Basic QWRtaW5pc3RyYXRvcjpjb21wYXE=" -H "OData-Version: 4.0" -H "X-CHRP-RIS-Provider-ID : $2"  --insecure  $MY_ILO_HOSTNAME/redfish/v1/$1  -X DELETE
}

alias restdel_provider_id='DoRestDeleteProvId'

# Set the environment variable containing the host name that is used by my curl+iLO aliases.
DoSetMyiLOIP() {
  export MY_ILO_IP=$1
  export MY_ILO_HOSTNAME=https://$1
}

alias setmyiloip='DoSetMyiLOIP'

# 1. REST Example - Command to search for a registry: "restgetb registries/ | jq . | grep Base"
# The schema URI pointer#1 : "@odata.id": "/redfish/v1/Registries/Base/"
# GET @ URI of pointer#1 to get pointer#2 :  "restgetb registries/base/ | jq . "
# Finally GET @ pointer#2 returns the gzipped schema. "extref": "/redfish/v1/RegistryStore/registries/en/base.json/"

# REST Example - Command to search for a registry: "restgetb schemas/ | jq . | grep Computer"
## TIP , with grep, get lines before/after the match with e.g. "grep Computer -A 10 -B 10"

## TIP: How to un-gzip and print a schema to stdout. NOTE: Schema file is under schemaSTORE not SCHEMAS.
## "restgetbf schemastore/en/smartstorageconfig.v2_00.smartstorageconfig/ /dev/stdout/ | gzip -d -c"
## TIP: Redfish schemas on dmtf.org
## http://redfish.dmtf.org/schemas/v1/

#######################
# SVN related
#######################

### SVN command aliases.

#alias svn='colorsvn'
alias swbr='svn switch '
alias sstat='svn status'
alias svdiff='svn diff'
alias slog='svn log -l 3 '
alias supd='svn update '
alias svchout='svn checkout '
alias cdg9='cd $mg9path'
alias cdgn='cd $mgnpathtot'

# Svn copy <trunk-branch-url> ^relative-url-new-feature-branch 
# http://svnbook.red-bean.com/en/1.7/svn.branchmerge.using.html

alias sbr='svn copy '
alias sbrg9='svn copy $g9svnurl '

alias svngui='sudo open /Applications/svnX.app'
#######################
# END SVN related
#######################
#######################
# Git related
#######################

# Reminder : Command to tell git to use the same proxy as bash. 'git config --global http.proxy $http_proxy'

alias gstat='git status'
# git-FYI: how to view a diff via cmd line. run "git diff --cached" in working copy. or use "git gui &"
# Make it easy to change my git config based on work vs. personal coding.

if [ "$GITHOME" = TRUE ]; then
    echo Git set for home.
    git config --global user.email darbin.e.reyes@gmail.com
    git config --global sendemail.smtpEncryption tls
    git config --global sendemail.smtpserver smtp.gmail.com
    git config --global sendemail.smtpUser darbin.e.reyes@gmail.com
    git config --global sendemail.from darbin.e.reyes@gmail.com
    git config --global sendemail.smtpServerPort 587
    git config --global http.proxy ""
    #git config --global -l
else
    echo Git set for work.
    git config --global user.email darbin.emm.reyes@hpe.com
    git config --global sendemail.smtpserver smtp1.hpe.com
    git config --global sendemail.from darbin.emm.reyes@hpe.com
    git config --global http.proxy http://web-proxy.houston.hp.com:8080
    #git config --global -l
fi

### Git settings for both work and home.
# Git Aliases https://git-scm.com/book/en/v2/Git-Basics-Git-Aliases
git config --global alias.co checkout
git config --global alias.br branch
git config --global alias.ci commit
git config --global alias.st status

#######################
# END Git related
#######################

##
# Your previous /Users/darbinreyes/.profile file was backed up as /Users/darbinreyes/.profile.macports-saved_2016-11-11_at_22:18:16
##

# MacPorts Installer addition on 2016-11-11_at_22:18:16: adding an appropriate PATH variable for use with MacPorts.
export PATH="/opt/local/bin:/opt/local/sbin:./:$PATH"
# Finished adapting your PATH environment variable for use with MacPorts.
