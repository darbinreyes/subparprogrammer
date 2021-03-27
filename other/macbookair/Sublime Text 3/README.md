Symlinks to my Sublime Text 3 configuration files. Also serves are a record of installed packages.

Link target: `/Users/darbinreyes/Library/Application Support/Sublime Text 3/Packages/User/`

FYI, you must use a hard link so that changes are seen by git. (don't use the -s flag).

`sudo ln "/Users/darbinreyes/Library/Application Support/Sublime Text 3/Packages/User/"* Sublime\ Text\ 3/Packages/User`