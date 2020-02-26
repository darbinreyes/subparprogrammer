# Using a debugger to debug euclid.c

Debugging with print statements is my natural tendency. But using a debugger is more efficient. These are my notes on using lldb, the current debugger on Mac OS X, it replaces gdb.

I currently have an assertion at euclid.c line 274. As an exercise, I want to stop execution before that assert and print the values of local variables.

## [lldb tutorial](https://lldb.llvm.org/use/tutorial.html)

### Command Structure

noun verb

"--" for option termination.


`breakpoint set --file foo.c --line 12` // breakpoint @ line 12

`breakpoint set --name foo` // breakpoint @ function foo

`breakpoint set --name foo --name bar` // breakpoint @ 2 functions.

`breakpoint set --shlib foo.dylib --name foo` // breakpoint @ specific executable image 

tab completion.

`help` command.

`apropos` command - search help docs.

custom alias support.

lldb reads the file `~/.lldbinit` at startup - customize lldb’s command set.
 
 “raw” commands -  rest of the command string is passed uninterpreted to the command - “`expression`” command. - if your command string has dashes in it, put - after it.
 
built-in Python interpreter - “`script`” command. - All the functionality of the debugger

### Loading a Program into lldb

the stages of a standard debug session.

Setting the executable.

```
$ lldb example
(lldb) target create "example"
Current executable set to 'example' (x86_64).
(lldb)
```

```
$ lldb
(lldb) file example
Current executable set to 'example' (x86_64).
(lldb)
```

Quitting lldb.

```
(lldb) quit 
```

Asking for help.

```
(lldb) help breakpoint 
```

Show me my current breakpoints

`breakpoint list`

`breakpoint set --name measures_v0`

By default - logical breakpoint, which could resolve to one or more locations.

```
(lldb) breakpoint list
Current breakpoints:
1: name = 'measures_v0', locations = 1
  1.1: where = example`measures_v0, address = example[0x0000000100002500], unresolved, hit count = 0 
```

logical breakpoints remain **live** - if another shared library were to be loaded - new locations added to existing breakpoint.

whether the breakpoint location was resolved or not - resolved when the file address it corresponds to gets loaded into the program you are debugging. - shared library that then gets unloaded - location becomes **unresolved**.

lldb will always make a breakpoint from your specification, even if it couldn’t find any locations that match the specification. - **pending**.

```
(lldb) breakpoint set --file foo.c --line 12
Breakpoint created: 2: file ='foo.c', line = 12, locations = 0 (pending)
WARNING: Unable to resolve breakpoint to any actual locations.
```

You can specify things on all locations or one location of a logical breakpoint. e.g. print a backtrace when bp 1.1. is hit.

```
(lldb) breakpoint command add 1.1
Enter your debugger command(s). Type 'DONE' to end.
> bt
> DONE
```

`-command`
`-script`

anything is in the help output in angle brackets has help text.

`(lldb) help break command add`

### Breakpoint Names

bp info = location + options.

`(lldb) breakpoint set -N SelfNil`

### Setting Watchpoints

```
(lldb) watch set var global
(lldb) watch modify -c '(global==5)'
(lldb) watch list
(lldb) c
(lldb) bt
(lldb) frame var global
(int32_t) global = 5
(lldb) watch list -v
```

### Starting or Attaching to Your Program

```
(lldb) process launch
(lldb) run
(lldb) r
```

You can also attach to a process by process ID or process name.

```
(lldb) process attach --pid 123
(lldb) process attach --name Sketch
(lldb) process attach --name Sketch --waitfor
```

### Controlling Your Program

After launching, we can continue until we hit our **breakpoint**.

`(lldb) thread continue`

ll the stepping commands have easy aliases. So “thread continue” is just “c”, etc.

```
(lldb) thread step-in    // The same as gdb's "step" or "s"
(lldb) thread step-over  // The same as gdb's "next" or "n"
(lldb) thread step-out   // The same as gdb's "finish" or "f"
```

```
(lldb) thread until 100
```

when the process is running anything you type will go to the STDIN of the inferior process.

To interrupt your inferior program, type CTRL+C.

launch a process with the “–no-stdin” option, 

work while running include interrupting the process to halt execution (“process interrupt”), getting the process status (“process status”), breakpoint setting and clearing (” breakpoint [set|clear|enable|disable|list] …”), and memory reading and writing (” memory [read|write] …”).

`(lldb) settings set target.process.disable-stdio true`

`settings list` 

### Examining Thread State

`(lldb) thread list`

`(lldb) thread backtrace`

`(lldb) thread backtrace all`

`(lldb) thread select 2`

frame’s arguments and local variables is to use the “`frame variable`”

`(lldb) frame variable`

`(lldb) frame variable self`

`(lldb) frame variable self.isa`

support a few simple operations like &, *, ->, [] (no overloaded operators)

array brackets can be used on pointers to treat pointers as arrays

`(lldb) frame variable *self`

`(lldb) frame variable &self`

`(lldb) frame variable argv[0]`

You can also move up and down the stack by passing the “`–relative`” (“-r”) option. And we have built-in aliases “`u`” and “`d`”

### After compiling with cc vs gcc and using -O0 -g compiler options. But gcc works too.

```
MacBook-Air:euclid darbinreyes$ lldb example
(lldb) target create "example"
Current executable set to 'example' (x86_64).
(lldb) breakpoint set --name measures_v0
Breakpoint 1: where = example`measures_v0 + 14 at euclid.c:268:11, address = 0x000000010000250e
(lldb) r
Process 2282 launched: '/Users/darbinreyes/dev/private_dev/subparprogrammer/C/euclid/example' (x86_64)
-------------------------- test_suite_one.c --------------------------
I'm done before every single test in the suite
I'm done after every single test in the suite
I'm done before every single test in the suite
I'm done after every single test in the suite
I'm done before every single test in the suite
I'm done after every single test in the suite
                           3 run  0 failed                            

-------------------------- test_suite_two.c --------------------------
I'm done before every single test in the suite
a = 12, b = 4. rp = 0. expect rp = 0.
a = 13, b = 4. rp = 1. expect rp = 1.
a = 54, b = 85. rp = 1. expect rp = 1.
a = 31, b = 85. rp = 1. expect rp = 1.
I'm done after every single test in the suite
I'm done before every single test in the suite
a = 884, b = 3009. gcm = 17. expect gcm = 17.
a = 32, b = 4. gcm = 4. expect gcm = 4.
a = 32, b = 5. gcm = 1. expect gcm = 1.
I'm done after every single test in the suite
I'm done before every single test in the suite
Process 2282 stopped
* thread #1, queue = 'com.apple.main-thread', stop reason = breakpoint 1.1
    frame #0: 0x000000010000250e example`measures_v0(b=8, a=4) at euclid.c:268:11
   265 	  unsigned int a
   266 	  )
   267 	{
-> 268 	  if (!(a > 1 && b > 1)) {
   269 	    assert(0);
   270 	    return -1;
   271 	  }
Target 0: (example) stopped.
(lldb) frame variable
(unsigned int) b = 8
(unsigned int) a = 4
(lldb) 
```

