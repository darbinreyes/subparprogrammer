```
  /\/\
 /- - \
 \ i  /
 /    \
/||  ||\_
\\\  ///))
 \\\/////
  UOOU//
      V
```

This directory contains code I wrote as part of studying the Operating System
Concepts textbook.


The initial commit is the unmodified source code provided with the textbook.
After that initial commit it is code I have written to complete the programming
problems and programming projects.


The unmodified source code and a Linux VM can be found
[here](https://www.os-book.com/OS9/).

For my detailed notes on using the Linux VM see these Evernote:
* Chapter 2 - Operating System Structures - Operating System Concepts - by S&G&G
* Programming Project 3.2.1 README.md Draft 0 - Operating System Concepts - by S&G&G

# linux-headers-3.16.0-4-common/

This directory contains a copy of the code obtained from the directory `/usr/src/linux-headers-3.16.0-4-common/` inside of the Debian Linux VirtualBox VM that is provided with the Operating System Concepts textbook 9th edition. This is useful for completing the exercises in chapter 2, to see all the definitions in list.h. It is also a good reference for C code in general. The way in which the list is implemented is instructive. There appear to be corresponding man pages e.g. `man list_head` (inside the Linux VM).

* To get this code explicitly from inside the Linux VM:


Update list of available packages
`sudo apt-get update`

List all versions of the Linux headers - pick the one that matches your system (`uname -r`).
`apt list *linux-headers*`

Download the headers (xxx = your choice above):
`sudo apt-get source xxx`

For my detailed notes on using the Linux VM see these Evernote:
* Chapter 2 - Operating System Structures - Operating System Concepts - by S&G&G
* Programming Project 3.2.1 README.md Draft 0 - Operating System Concepts - by S&G&G

# linux-3.16.81/

For detailed notes on how to get this source code from within the Linux VM see Evernote:
* Programming Project 3.2.1 README.md Draft 0 - Operating System Concepts - by S&G&G
* Chapter 2 - Operating System Structures - Operating System Concepts - by S&G&G