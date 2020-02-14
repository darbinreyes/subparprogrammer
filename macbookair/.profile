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
        export PATH="/opt/local/include:/opt/local/bin:/opt/local/sbin:/opt/:$PATH" # !!! dont forget the ":" delimiter BITCH!
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
# Export no_proxy=localhost,127.0.0.0/8,*.local
# Add mysql to path https://trac.macports.org/wiki/howto/MAMP
export PATH=$PATH:/opt/local/lib/mysql51/bin
#######################
# Network related
#######################

if [ "$PROXYHOME" = TRUE ]; then
    export http_proxy=
    export https_proxy=
    echo Proxy set for home. $http_proxy $https_proxy
else
    export http_proxy=
    export https_proxy=
    echo Proxy set for work. $http_proxy $https_proxy
fi

export HTTP_PROXY=$http_proxy
export HTTPS_PROXY=$https_proxy

# Example usage of curl: https://www.drupal.org/node/1795770

# Make-bash-alias-that-takes-parameter: http://stackoverflow.com/questions/7131670/make-bash-alias-that-takes-parameter

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

# Svn copy <trunk-branch-url> ^relative-url-new-feature-branch 
# http://svnbook.red-bean.com/en/1.7/svn.branchmerge.using.html

alias sbr='svn copy '
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
    git config --global user.email
    git config --global sendemail.smtpserver
    git config --global sendemail.from
    git config --global http.proxy
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
# Finished adapting your PATH environment variable for use with MacPorts.
