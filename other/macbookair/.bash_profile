# command line tips:START

# Make-bash-alias-that-takes-parameter:
# http://stackoverflow.com/questions/7131670/make-bash-alias-that-takes-parameter

# Example usage of curl: https://www.drupal.org/node/1795770

# EXAMPLE `find` command that recursively searches current directory for file
# names that match *.txt and prints any lines inside those txt files which match
# the word "RIS" `find . -name "*.txt" -print | xargs grep "RIS"`
# If you get an error like "find: ./sbin/authserver: Permission denied", don't
# use this alias. Use `sudo find . -name`.

# command line tips:END

echo '#########################################################################'
echo "Hello from .bash_profile, FYI, I'm only run for login shells and I have
priority over .profile."
echo '#########################################################################'

# important PATH stuff:START

# XXXHOME variables: Currently I don't use my personal machine for work anymore
PROXYHOME=TRUE
GITHOME=TRUE
MAC_PORTS_PATH_RM= # TRUE # hides macports binaries.

if [ "$MY_BASH_PROFILE_CALLED" = TRUE ]; then
	echo "Already run"
else
	if [ "$MAC_PORTS_PATH_RM" = TRUE ]; then
		echo "Mac Ports removed from PATH"
		PATH="$HOME/bin:.:$PATH"
	else
		echo "Mac Ports prepended to PATH"
		# Add python 2.7 bin directory to path.
		PATH="/opt/local/Library/Frameworks/Python.framework/Versions/2.7/bin:$PATH"
		# IMPORTANT using a ~ character does NOT work here, you must use $HOME instead.
		# !!! dont forget the ":" delimiter BITCH!
		PATH="$HOME/bin:.:/opt/local/include:/opt/local/bin:/opt/local/sbin:/opt/:$PATH"
	fi
	echo "PATH = $PATH"
	echo "PYTHONPATH = $PYTHONPATH"
fi

export PATH

# important PATH stuff:END

# prevent PATH env. var. from being appended to on each call to sbash.
MY_BASH_PROFILE_CALLED=TRUE

# miscelaneous:START

alias sbash='source ~/.bash_profile'
alias ebash='code ~/.bash_profile'

alias find-filename='find . -name '
alias ls='ls -G'
alias ll='ls -l -a -G'
alias where='which'
export EDITOR=vim

# How to play sounds from the terminal
FARTPATH="/Users/darbinreyes/Movies/Wondershare\ Filmora9/Output/south-park/sp-s02e01-clips-for-win10"
alias fart0="afplay $FARTPATH/the-fart.mp3 &"
alias fart1="afplay $FARTPATH/sp-s02e01-clips-for-win10-agree.mp3 &"
alias fart2="afplay $FARTPATH/sp-s02e01-clips-for-win10-relax1.mp3 &"
alias say0="say 'Relax guy' &"

# miscelaneous:END

# network:START

alias myip='curl -4 icanhazip.com'

if [ "$PROXYHOME" = TRUE ]; then
    http_proxy=
    https_proxy=
    echo "Proxy set for home. $http_proxy $https_proxy"
else
    http_proxy=
    https_proxy=
    echo "Proxy set for work. $http_proxy $https_proxy"
fi

export http_proxy
export https_proxy
export HTTP_PROXY=$http_proxy
export HTTPS_PROXY=$https_proxy

# network:END

# git:START

# Reminder : Command to tell git to use the same proxy as bash.
# 'git config --global http.proxy $http_proxy'

# Make it easy to change my git config based on work vs. personal coding.

if [ "$GITHOME" = TRUE ]; then
    echo "Git set for home."
	git config --global user.email 1085688+darbinreyes@users.noreply.github.com
	git config --global sendemail.smtpEncryption tls
	git config --global sendemail.smtpserver smtp.gmail.com
	git config --global sendemail.smtpUser darbin.e.reyes@gmail.com
	git config --global sendemail.from darbin.e.reyes@gmail.com
	git config --global sendemail.smtpServerPort 587
	git config --global http.proxy ""
	git config --global commit.gpgsign true
else
	echo "Git set for work."
	git config --global user.email
	git config --global sendemail.smtpserver
	git config --global sendemail.from
	git config --global http.proxy
fi

# Git settings for both work and home.

git config --global alias.co checkout
git config --global alias.br branch
git config --global alias.ci commit
git config --global alias.st status

# git:END

# Tell node where to look for global modules.
# export NODE_PATH=/opt/local/lib/node_modules

# Github: "paste the text below to add the GPG key to your bash profile"
export GPG_TTY=$(tty)

# [Fix for whatis/apropos](https://apple.stackexchange.com/questions/374025/errors-from-whatis-command-unable-to-rebuild-database-with-makewhatis)
alias apropos='~/workarounds/apropos.macos_10.15.1'
alias whatis='~/workarounds/apropos.macos_10.15.1'
# Explicitly tell makewhatis where to look for man pages.
export MANPATH="/usr/share/man:/usr/local/share/man:/opt/local/share/man:/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/share/man:/Library/Developer/CommandLineTools/usr/share/man"

# brew is useful when Mac Ports fails e.g. originally added to install qemu
eval "$(/opt/homebrew/bin/brew shellenv)"

# private development:START

# Commonly used paths
PRIVATE_DEV="$HOME/dev/private_dev"
SPPREPO="$PRIVATE_DEV/subparprogrammer"
alias cdspp="cd $SPPREPO"

# os161:START
MYOS161="$PRIVATE_DEV/os161"
MYOSROOT="$MYOS161/root"
MYOSSRC="$MYOS161/src"
MYKERNCONF="$MYOS161/src/kern/conf"
MYKERNCC="$MYOS161/src/kern/compile/DUMBVM"
MYOSTOOLS="$MYOS161/tools/bin"
MYOSMAN="$MYOS161/tools/share/man"
alias cdos="cd $MYOS161"
alias cdosr="cd $MYOSROOT"
alias cdoss="cd $MYOSSRC"
alias initos="pushd $MYOS161 && . initos161; popd"
alias reinitos="pushd $MYOS161 && SCRIPT_ALREADY_RUN=; . initos161; popd"
# os161:END

# private development:END

