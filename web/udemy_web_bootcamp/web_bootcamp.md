# https://www.udemy.com/course/the-web-developer-bootcamp/

The only course you need to learn web development - HTML, CSS, JS, Node, and More! // Strong claims. We shall see.

* [x] What you'll learn

* [x] Course content

* No **PHP** or other dated technologies. This course does not cut any corners. // Nice.

* [x] Description

# [Go to Course](https://www.udemy.com/course/the-web-developer-bootcamp/learn/lecture/3861710?components=buy_button%2Cdiscount_expiration%2Cgift_this_course%2Cintroduction_asset%2Cpurchase%2Cdeal_badge%2Credeem_coupon#overview)

---

# Section 1: Introduction to this Course

---

## A Note On Asking For Help

Q&A board search

post a thread of your own.

provide enough context 

share your code with us in a Q&A thread by using the {...} code block button 

ways to share your code with us. tools.

  * Codepen 
  * JS Bin 
  * Github Gists 
  * GoormIDE (once you get to the backend section of the course) 
to share code

a matter of personal preference.

a screenshot sharing app called Gyazo. 

show us how something looks in your browser 

Udemy - the image button (to the left of the code block button

help right away then head over to our course Facebook Group and Discord Channels

 students are hanging
 
 Discord server has a #wdb-codetalk channel specifically for asking questions.
 
 Add bookmarks while watching lectures
 
 Use the keyboard shortcut "b" to create bookmarks while watching video lectures.
 
Youtube Channel for additional free content.

## Introducing Our TA

who will be helping out on the discussion boards and chatrooms

make the most of this awesome community

In the chatrooms

In the Q&A

## Join the Online Community

Discord server and Facebook group.

### Why This Course?
### Syllabus Download

PDF versions of the course slides, here.

### Syllabus Walkthrough
### 8 Lecture Slides

---

# Section 2: Introduction to Front End Development

---

## 9. Unit Objectives

Definitions

* frontend // first half
  * "frontend specific technologies" = HTML , CSS, Javascript.
backend // second half

full stack = frontend+backend // last 


## 10. Note about Setting Up Front-End Developer Environment

 how to setup your front-end environment.
 
## 11. Setting Up Front-End Developer Environment

Two tools.
SublimeText!
Chrome.

## 12. Note about Introduction to the Web

**typo** in the slides in the following lecture around the 7 minute and 50 second mark, "...hoping from server to server" should say "...hopping from server to server".

## 13. Introduction to the Web

60 Hudson street NYC. 
Largest internet hub on the east cost.

Name to IP. = machine location within the network.
Internet - Requests and responses. Clients send requests to a server receive responses.

DHCP - IP assignment.

DNS queries - name servers.

HTTP requests/responses. - APACHE HTTP server sends responses to requests it receives.

figuring out **what to send back** = "when we do **backend** development that will be your job" 

server responds with HTML+CSS+JS.

* Viewing page source in Chrome

  * right-click->View Page Source

  * cmd+option+u

  * prefix the URL with **view-source:**https://www.udemy.com/course/the-web-developer-bootcamp/learn/lecture/3861186#questions
  
## 14. The Front End Holy Trinity

Learning about the frontend = HTML CSS JS.
Backend = everything else.

Web server
database
mongodb
PHP
PYthon
apache
nginx
mysql

HTML

CSS - optional.

JS - client side programming language for manipulating HTML, CSS, telling client's machine to do things within the browser.

codepen.io - like the w3s tutorial examples, this lets you play with live HTML+CSS+JS.

JS + CSS comment syntax = /*

---

# Section 3: Introduction to HTML

---

### 15. Unit Objectives
## 16. HTML Basics

Use **MDN** as reference.

HTML = structure + content.


## 17. Note about Introduction to MDN

for MDN's Introduction to HTML can now be found here.

original version from when Colt recorded the video then see here

## 18. Introduction to MDN

MDN = mozilla development network = reference for HTML, CSS, JS etc.

HOME = https://developer.mozilla.org/en-US/

"Resources for developers, by developers." // Nice.

HTML CSS JS = https://developer.mozilla.org/en-US/docs/Web

google "mdn functions" = JS functions.

also has examples.

---

* [x] Read intro to html. RTFM. https://developer.mozilla.org/en-US/docs/Learn/HTML/Introduction_to_HTML
  * My notes on this are here: ./MDN_intro_to_html.md

---

## 19. HTML Boilerplate and Comments
in subl

html+tab

### 20. Basic Tags
### 21. HTML Lists
### 22. HTML Lists Assignment
### 23. HTML Lists Assignment: SOLUTION
### 24. Divs and Spans
### 25. HTML Attributes
### 26. Recreate Webpage Assignment
### 27. Recreate Webpage Assignment: SOLUTION

END.

---

# Section 4: Intermediate HTML

---
	
Emmet = extension for sublimetext. Paige's rec.

## 29. HTML Tables
	
\<table>
	
\<tr>
	
\<td>
	
\<thead>
	
\<tbody>
		
### 30. Tables Pokemon Exercise
### 31. Tables Pokemon Exercise: SOLUTION
## 32. Introduction to Forms 
\<form action="" method=""\>

\<input type="text" placeholder="">

\<button>

adding name to input appends a URL query upon submit. GET.

### 33. Playing with Inputs
### 34. The Form Tag
### 35. Labels 
\<label> 
\<label for="username">

\<input id="username">

## 36. Form Validations

\<input id="username" required>

\<input id="username" type="email" required>

## 37. Dropdowns and Radio Buttons

\<input type="radio">	// to make mutually exclisive, add common name. add value to override default "on". 
\<input type="checkbox">

\<select name="color"> \<option value="happy"> // dropdown

\<textarea name="usercomment" rows="10" cols="80">

### 38. Form Exercise
### 39. Note about the Form Exercise solution
### 40. Form Exercise: SOLUTION 
END.

---

# Section 5: Introduction to CSS

---

## 42. CSS Basics

csszengarden.com

selector {
  prop: val;
}

element selector e.g. h1 {}.

/**/ css comments 

boiler plate in subl

link+tab
 
### 43. Our First Stylesheet
### 44. Note about CSS Colors and Background and Border (next 2 lectures)
## 45. CSS Colors  
color: #000000;
color: rgb(0,0,0);
color: black;
 
## 46. Background and Border 
* borders have
  * color
  * width 
  * style.
  
### 47. Note about Selectors Basics Todo List
## 48. Selectors Basics Todo List 
* element
* id - all ids should be unique. invalid html if duplicate. #special {}
* class - .theclass {}

text-decoration: line-through; 
## 49. Introduction to Chrome Inspector 
element inspector allows live editing of CSS.

editing works on all sites.

beware of inherited CSS properties.

click on magnify glass tool on upper left. e.g. inspect icon. 
## 50. More Advanced Selectors 
* "*" // selects all elements on page.
* "li a" // descendant  selector - select a tags inside li tags
  * "li .theclass" //  descendant  selector - selects .theclass inside li tags
  * ".thisclass .thatclass" //  descendant  selector -
 
* "h4 + ul" // adjacent selector = sibling selector = all ul after h4

* a[href="darbinreyes.com"]// attribute selector.

* ul:nth-of-type(10) // nth of type. e.g. every 10th ul.
* ul:nth-of-type(even)// nth of type. e.g. every even ul.


## 51. Note about Specificity and the Cascade
 xxx

## 52. Specificity and the Cascade
 inheritance 

use element inspector to view CSS inheritance.


CSS specificity. When multiple styles target an element. The more specific style wins.

https://specificity.keegan.st/

**ANOTHER SELECTOR TYPE = Pseudo-class selectors**

a:hover
input:checked

### 53. Note about Selectors Practice Exercise
### 54. Selectors Practice Exercise
### 55. Selectors Practice Exercise: SOLUTION 
---

# Section 6: Intermediate CSS

---

### 56. Unit Objectives
## 57. Text and Fonts

* font-
  * family
  * size // 2.0em = twice the size of the parent. By default 1.0em = 16px,
  * weight // normal, bold, depending on font numeric values 100, 200, ... 800.

Use live editing of CSS via chrome element inspector e.g. to preview font size look.

## 58. More Text and Fonts
	
* line-height  // 1.5, 2. 2=double default.
* text-align // right, center
* text-decoration // underline, line-through, overline.

## 59. Note about Google Fonts 
Navigate to https://fonts.google.com

## 60. Using Google Fonts 
Not all machines support all fonts. Using google fonts ensures that the font on a page is always available. This is done by essentially fetching a font file from google. You do this by adding a \<link> to your \<head> almost exactly like you do for a CSS file link. Then you set the font-family in CSS using the name of the font fetched from google.

## 61. Introduction to the Box Model 
All html elements have an associated rectangle container. You can see them by setting a border for all elements.

The naming of the dimensions of these rectangles are called the box model.

4 Dimensions/edges

margin edge

border edge

padding edge

content edge

---

Parts of the box

* content
width: 200px;
width: 50%; // of the parent.
height: 100px;

* padding // inside
padding: 10px;
padding-left: ;

* border // middle
border: 1px solid blue;
border-top: ;

* margin // outside
  * margin: 100px;
  * margin: top right bottom left; // clockwise
  * margin: 0 auto 0 auto; // beware, if not 0, must use px for numeric.
  * margin: top_bottom right_left;
  
### 62. Creating a Tic Tac Toe Board
### 63. Creating a Tic Tac Toe Board: SOLUTION
### 64. Note about Image Gallery Code Along Pt. 1
## 65. Image Gallery Code Along Pt. 1
 
```css
div {
float: left; /* make vertically stacked divs horizontally stacked left to right // get rid of spacing between images that is added by the browser and not part of the box model. */
}
```

sublimetext shortcut. **cmd+click lines, start typing.**


### 66. Note about changes to Google Fonts
## 67. Image Gallery Code Along Pt. 2	
text-transform: uppercase;

border-bottom: 2px solid red; 
### 68. CSS Blog From Scratch Exercise Intro
### 69. CSS Blog From Scratch Exercise SOLUTION Pt. 1
### 70. CSS Blog From Scratch Exercise SOLUTION Pt. 2
### 71. CSS Blog From Scratch Exercise SOLUTION Pt. 3 
---

# Section 7: Bootstrap

---

## 72. Unit Objectives

Bootstrap is CSS and JS library.
Nav, inputs.
bootstrap based photo lib.
BS gridsystem. 
## 73. Note about Bootstrap versions 
use the original documentation for version 3 and ensure that you're using version 3.3.7 in your code https://getbootstrap.com/docs/3.3/

 you can use this guide to upgrade your code from Bootstrap 3 to version 4. 
## 74. What is Bootstrap? 
http://getbootstrap.com

Its a framework i.e. it provides a frame within which you must fill in the rest of the construction.

The frame involves HTML CSS JS.

Enables responsiveness = fancy GUI features.

Enables mobile **first** = tailored to iPhones etc.

## 75. Adding Bootstrap to a Project
 Just include two files! For now we just include the CSS, not the JS.

There is indeed no need to create things like nav bars from scratch. Hence bootstrap. You take the ready made part and customized if desired.

* Docs
  * CSS
  * Components
  * Expo 

Example use case of bootstrap. To get a bootstrap style button simply lookup the class names in the CSS docs and add them to the class attribute of a button, a, or input. E.g.

\<button class="btn btn-success bt-lg">Press me\<button>

To customize a bootstrap default use CSS on the classes e.g.

.btn-success {
color: red;
}

Note everything so far has only involved a single CSS file! The bootstrap CSS.

## 76. Forms and Inputs 
Don't be intimidated by the size of the bootstrap docs, you don't need to read all the docs before you can use bootstrap. Its OK to just read about what you need at the moment. If we always read docs in their entirety we would not get much done. Theres a balance to RTFM and quick reference.

Not expert in memorization. In reference. 

---

Jumbotron

Grid system = size control

div 

.container

.form-group
.form-control
.help-block

// classes play main role in using bootstrap. plug and play.
.form-inline

## 77. Nav Bars 
Note window resize behaviour

"Hamburger" = mobile tab menu.

Components->Navbar

```html
<nav class="navbar navbar-default">
  <div class="navbar-header">
  <a href="#" class="navbar-brand">Poo Poo</a>
  </div>
  <ul class="nav navbar-nav">
    <li>
      <a href="#" class="navbar-brand">Caca</a>
    </li>
  </ul>
  <ul class="nav navbar-nav navbar-right">
    <li>
      <a href="#" class="navbar-brand">Pipi</a>
    </li>
  </ul>
</nav>
```
To fix the navbar links being up against the edge of the screen you put a \<div class="container"> immediately inside the \<nav> tag. This centers the nav links. Putting the same div immediately outside the \<nav> tag squeezes the nav bar. In general this div container squeezes its contents.

To make the NAV drop downs to work you need to link the bootstrap JS.

Once you do this you notice a JS error in the chrome JS console. 

"bootstrap.min.js:6 Uncaught Error: Bootstrap's JavaScript requires jQuery"

jQuery is obtained from http://code.jquery.com. or google "jquery cdn"

## 78. Note about The Grid System
## 79. The Grid System 
Components - grid system

12 columns

div .container

div .row

div .col-lg-12 
## 80. Grid System Pt. 2 
.-lg- .-md-
.-sm-
.-xs-

.rows can be nested to sub divide columns.

if you set a col to .-md- and .-sm- the .-lg- gets as many columns as the .-md-

see table for screen px breakpoints.

## 81. Note about Bootstrap Image Gallery Pt. 1 
If you don't mind the images being of varying heights, but want to get rid of the white space bug then see here 

If you're looking for Pinterest-like presentation of thumbnails of varying heights and/or widths, you'll need to use a third-party plugin such as Masonry, Isotope, or Salvattore. 

If you want to crop all of the images to the same size then see an example of this here 
## 82. Bootstrap Image Gallery Pt. 1

.navbar-inverse

vs

.navbar-default

div .thumbnail // scales images

using more than 12 cols in a single row automatically adds (wraps) rows to a new row even if you only have 1 div .row.

span ."glyphicon glyphicon-camera" 

nabar-fixed-top
## 83. Note about Font Awesome 
font/icon library called Font Awesome. Font Awesome can now be found at https://fontawesome.com/

`<link rel="stylesheet" href="https://use.fontawesome.com/releases/v5.11.2/css/all.css">`

## 84. Bootstrap Image Gallery Pt. 2 
Make sure you link your custom CSS after the bootstrap CSS.

fontawesome // more glyphicons 
bootstrap does most of the CSS heavy listing.

use chrome element inspector for CSS specificity battles.

## 85. Creating a Startup Landing Page Code Along
## 86. Creating a Startup Landing Page Code Along Pt. 2 
```
h1, h3 {
  color: white;
}

html {
  height: 100%;
}

hr {
  width: 400px;
  border-bottom: 1px solid rgba(0, 0, 0, 0.2);
}

/*text-shadow: x y radius color */
```
 
## 87. Note about making bootstrap responsive on mobile devices 
If you want your bootstrap styled website to be responsive on mobile then be sure to add the following meta tag to your \<head>  element, above the \<title>  tag:

`<meta name="viewport" content="width=device-width, initial-scale=1">`

---

# Section 8: Bootstrap 4!

---

## 88. A History of Bootstrap 4
## 89. The Bootstrap 4 Documentation 
Documentation

Components on the left. 
## 90. Changes from Bootstrap 3 to 4

Syntax changes to class names.

Migration tab on left. Change list. Per component. Removed added or changed.

* Global changes.
  * Flexbox. Layout features.
  * rem=root em's. Scaling font size. Old default global size 14px new 16px.
  * 5th size added, lg md ..
  * util classes for CSS margins/padding. 
  
* Grid system.
  * flexbox.
  
* Components.
  * thumbnails+, replaced by cards.
  
* Glyphicons removed. Use font awesome.
* Pager component removed.
* Overall unnesting of classes.
  * Per component changes. e.g. btn-default = btn-secondary
  
* New JS cdn file. popper.js. 
## 91. Bootstrap 4 Code/Solutions Download
## 92. Getting Started With Bootstrap 4

* order of JS includes matters.
* Getting started - list of features implemented in JS. 

## 93. Bootstrap 4 Colors and Backgrounds 
* Utils->Colors
  * text-primary ...
  * bg + foreground colors have changed. e.g. .bg-warning
  
* Still start with .container
  * .text-primary .bg-dark
  
* all colors are brighter.

## 94. Typography 
Documentation->Content->Typography.

* Page headings
  * .text- moved to utils.scss.
  * Page-header bsv3 gone. - use .display-n
* Blockquotes
  * new way of doing blockquotes. 
    * mb-0 = margin bottom 0.
    * blockquote-reverse gone. use text-right.
* rem units replace px's. root ems.
  * root = toplevel html element.
  * 1 rem = 16 pxs.  
## 95. New Fancy Spacing Utilities 
New feature in bsv4.

margin, padding spacing shortcuts.

compare to bsv3 "helper classes".

Documentation->Utils->Borders.

* Borders
  * additive
  * subtractive
  * colors
  * shape
  
Documentation->Utils->Spacing. (Non-responsive(=device size features) for this video)

* Spacing [m|p][location]-[size 0-5]
  * p= padding
    * pt-5 = padding top 5(=biggest).
    * pb-1
    * pl-2
    * px-1
    * p-0, p-1, ... . rem based.
    * "$spacer Sass map variable."= multiplier of rems.
    * x=left right
    * y=top bottom
  * m= margin

## 96. Responsive Breakpoints 
Making things respond to device screen size.

New size. xl. default=xs.

Note sr-only, sr= screen reader.

Documentation->Layout->Responsive Breakpoints.

Setting margin and padding by screen size.

* Documentation->Utils->Spacing.
  * Notation
    * {property}{sides}-{breakpoint}-{size} e.g.
    * px-sm-1 // size 1 will be used for screen sizes sm and up.
    * px-lg-3 // size 3 for lg and up.
    * WRONG: px-xs-0 // No effect.
    * RIGHT: px-0 // xs is the default without screen size. 

VScode shortcut. To create a button with class btn. Type button.btn+tab. (Notice the tab completion says **"Emmet Abbreviation"**, the tool Paige mentioned.).

Note the easyness of spacing by screensize(=breakpoints).
 
## 97. Bootstrap4 Navbars 
What's changed.
Look. button look.
Ability to set when hamburger appears easily.

Documentation->Mirgration->Navbar. // full List of changes.

"rewritten in flexbox"
required class. .navbar-expand-{breakpoint}. .navbar-dark.
.navbar-toggle now = navbar-toggler.
No more default margin/border. Use utils.

Note navbar breakpoint for hamburger. .navbar-expand-lg // when the hamburger disapears.

.navbar-dark
.bg-light // must set, default transparent. 
## 98. The New Display Utility 
In bsv3. Showing and hiding content based on screen size.
 .hidden-xs
.visible-lg.

replaced in bsv4 by display=d.

Documentation->Migration->Responsive Utils. // List of removed classes.

Documentation->Utils->Display.

.d-{value} for xs
.d-{breakpoint}-{value} for sm, md, lg, and xl.

Note: chrome CSS inspector has a search feature.

.d-none // none means disappear.

VScode/Emmet Abbreviation. lorem60+tab=insert 60 characters of lorem rand text.

---

# Section 9: Bootstrap 4: Flexbox and Layout

---

## 99. Bootstrap 4: Flexbox and Layout

Flexbox is independent from bsv4, bsv4 uses flexbox.

Documentation->Utils->Flex.

e.g. recall display settings using

.d-none
.d-block
.d-inline
.d-sm-block

flex is another display value e.g.

.d-flex

Flex can be used outside of boot strap, we will use flex within bsv4

## 100. Flexbox Utilities Part 2 

flex allows easy

horiz.+vertical positioning. div.d-flex.

two directions. 
default axis = left-start right-end.
cross axis = top-start bottom-end
We can change direction start end.

.justify-content-end // CSS=justify-content: flex-end;

.justify-content-between

.justify-content-around

cross axis

.align-items-end

.align-items-center

we can set screen size breakpoints for these too. e.g.

justify-content-{breakpoint}-end

changing axis direction default. e.g.

.flex-row-reverse
.flex-column // top to bottom becomes default direction 
.flex-md-row

## 101. Navs and Flexbox 
in bsv4

navs use flex 

styling via unnested classes.

.nav
.navitem
.nav-link

Docs->Components->Nav

Flex classes work on nav.

responsive/breakpoint nav. 
## 102. The Bootstrap 4 Grid 
v3 grid similar

12 cols

New breakpoint xl.

Docs->Layout->Grid

flex built in

.container 
.row
.col-6
.col-sm-6
.col-12 //=default for xm and up
.col // equal spacing if no num cols specified
.col .col-6 .col // 6 for center, equal size other

## 103. PATTERN PROJECT Part 1 
panels, thumbs, wells = cards in bsv4 
\<a> tag can be made to look like a button by setting its class to btn btn-primary.

bg: url() center center / cover no-repeat.


## 104. PATTERN PROJECT Part 2 
Docs->Components->Cards

use chrome element inspector to see what CSS bsv4 adds with simply class applied to a div e.g. div.card. 
.container
.card
img.card-img-top
.card-body
.card-title
.card-text

put your cards inside a grid

To edit multiple lines simultaneously in VScode use option+click.

.mb-4

## 105. The Grid + Flexbox 
Controlling things using flexbox within the grid systems. 
Alt to Inserting empty cols - use flexbox classes. e.g.

.justify-content-between // Much easier

Recall how with flex buttons would be stretched vertically. This is the default .align-items-stretch, using align-items-end|start|center avoids the stretching.

// per column align-items override
.align-self

// works with breakpoints too.
.col-lg-5 
.col-lg-5 // 2 cols empty
.justify-content-between // 2 empty cols space looks nicer.
 
## 106. Museum of Candy Project Part 1 
Something that doesn't look "bootstrappy".

"fictional instagram museum"

responsive
 
## 107. Note about Museum of Candy Project Part 2

in CSS code for the font-size of the navbar, Cole forgets to include it 
## 108. Museum of Candy Project Part 2 
NOTE: in **VScode** hovering over a CSS value shows the MDN docs for it as a tool tip.

.navbar-expand-md // you set when it expands not when it hamburgers.

button.data-target does not need to be an id.

button[aria-label="Toggle Navigation"] // tells people using screen readers what the hamburger button does.

\#mainNavbar .navbar-brand // select id=mainNavbar and inside that id select the class .navbar brand // select the class .navbar-brand nested inside id=mainNavbar

font-size: 1.5rem; // Recall bsv4 uses rem unit, by default 1 rem = 16px. Note that a rem can be a float number.

\#mainNavbar .nav-link:hover // Note we didn't select the \<a> tag but can still specify the pseudo class hover.

navbar .fixed-top // make the nav bar stick as you scroll down.

Making the nav bar change bg color // involves JS to trigger.

## 109. Museum of Candy Project Part 3 
\<section> tag // The guy uses this for separating content.

\<section class="container-fluid px-0"> // making a div.container fill the entire width of the screen instead of having centered content with space on the left and right. // He uses \<section class="container-fluid px-0"> instead of \<div class="container-fluid px-0"> but I think both should work. px-0 is there because by default there is non-0 padding on the left and right.

img .img-fluid // Make an image "responsive". fills its div.row.col-6 only, instead of being huge in the vertical and horizontal directions. Also forces scaling// see Docs->Content->Images
 in chrome inspector - padding is green

Web coding Efficiency // Before you embark on lots of copy pasting of HTML + CSS, think for a bit, think about how you might achieve your goal with more concise HTML+CSS. e.g. using the right CSS selectors

Making the 7 candy headings shrink at size screen small. // Requires "Media query" - a new feature not discussed so far.  // I expected the 7 headings to be scaled like the image on the right but that isn't the case. //  "Media query" = Way to change CSS based on screen size.

 "Media query" notation. In a CSS file:
 
 ```css
 /* When the screen width lies between 0-1200px apply the CSS below */
 @media (max-width: 1200px) {
    body {
      background-color: black;
    }
 }
 ```

To center the text of milk.png WITH space on the left and right // nest a div.row inside the col-md-6, this divides that square with text on the right into further 12 cols. // Not sure why he didn't using padding. It may be because using he bootstrap grid is in general a better way. // Finally add .justify-content-center.

in **VScode** the Emmet abbreviations works for ALL HTML tags including the simplest ones like \<p>. Just type p+TAB to avoid having to type the \<\>. Nice.

Changing ordering at  breakpoints. // .order-2 .order-1 .order-md-1 order-md-2 // I expected he would use row-reverse/column-reverse.

.blurb h2 // "all h2's inside of a class blurb." // The guy reads it out loud this way

## 110. Museum of Candy Project Part 4
## 111. Museum of Candy Project Part 5

.navbar.scrolled // select an element that has both classes .navbar and .scrolled //getting the nav bar bg fill on down scroll effect. // In CSS select a class say, .scrolled, then use JS to add/remove the class from the navbar. 
```
<script>
  $(function () {
    $(document).scroll(function(){ // scroll() is built-in function of document. The argument is a function. On scroll event.
        var $nav = $("#mainNav"); // fetch the element with id=mainNav
        $nav.toggleClass("scrolled", $(this).scrollTop() > $nav.height()); // first arg = class. second arg. is a boolean that specifies when to toggle. $(this) must be the ???. Note that the fact that we are toggling vs. just adding a class handles both turning the bg on and turning it off. Notice that the toggle value is an expression. 
        
        // "THIS IS JS AND JQUERY TOGETHER. "$", scroll(), toggleClass() comes from JQUERY.
        
    }) // End paren of scroll() function call.
}) // End paren of unnamed function.
</script>
```

NOTE element inspector in chrome shows live preview of scroll toggle event change in CSS. Nice.

transition: background 500ms|1s; // when the background property changes apply the change over a time span of the specified time, milliseconds|seconds.  // to add the navbar bg FADE IN effect, one way is just CSS,

In conclusion, we have something not "bootstrappy".

---

# Section 10: Introduction to JavaScript

---

## 112. Unit Objectives
## 113. The JavaScript Console 
works like the python interpreter 
## 114. Primitives 
number

string

boolean

null

undefined

## 115. Primitives Exercises 
1

'h'

5%3 == 2

## 116. Variables 
Syntax:

var identifier = value; // notice absence of type

By convention: camel case.
snake case = caca_poo
dash case = sassy-ho

## 117. Null and Undefined 
Difference

var caca; // undefined

null // you decide what it means when you assign it to a var.

## 118. Useful Built-In Methods 
// this is a comment

clear() // clears console **method**.

alert // alert("caca"); alert(9922); // Print a message to a pop up window.
 console.log // console.log("doodoo"); console.log(777); // print something on the console

prompt("Did you take a dump?"); // Get input from the user with a popup window

TOOL NOTE: the chrome inspector+JS console can be used on any webpage e.g. change the width of the google home page logo.

TOOL NOTE: Emmet abbreviation for script with src = script:src+TAB.

## 119. Writing JavaScript in a Separate File
## 120. JS Stalker Exercise
## 121. JS Stalker Exercise: SOLUTION
## 122. Age Calculator Exercise
## 123. Age Calculator Exercise: SOLUTION 
Notice that a script placed in the \<head> of your html forces the script to execute before the content is loaded. This is the reason that the browser window tab shows a spinner if your script calls alert(), the script doesn't finish executing until you close the alert popup window.

One workaround is to put the script as the last element of the body.

---

# Section 11: Javascript Basics: Control Flow

---

## 124. Unit Objectives
## 125. Boolean Logic 
=== // equal value AND type

in JS == is different from == in C

in JS 5 == "5" is true even though one operand is a number and the other is a string.

this is a consequence of "type coercion", in which JS tries to force its operands to a common type before the operation is evaluated.

true == "1" // true
true == "12" // false 
0 == false // true

null == undefined // true

NaN == NaN // false

## 126. Note about logical operators lecture		
a couple of examples that use an empty string, or two quotes with nothing between them: "" 
## 127. Logical Operators 
// same as in C

&&
||
!

// When evaluating expressions in your head use the predicate calculus. // check your answer in the JS console.

ex2. false 
in JS every expression can be converted to a boolean. I suspect this is also a result of "type coercion" e.g.

!"Hello" // false

!"" // true

!null // true

!0 // true

!-1 // false

!NaN // true

// use the JS console if you are unsure about an expression's value

Explicitly false values:

false
0
""
NaN
undefined
null

Otherwise, the value is true.

ex.3 false

## 128. Conditionals 
```javascript
if(age < 18) {
  console.log("Suck my balls.");
} 
else if (age < 21) { // precond. !(age < 18) == age >= 18
  console.log("The monkey claw is smelly.");
} 
else {
  console.log("A smelly smell that smells.");
}
```

## 129. Conditionals Exercise SOLUTION
## 130. Guessing Game Code Along 
// you can declare a var and initialize it with a function call

`var myinput = prompt("Gimme candy or vodka.");` // returns a string type even if you input a plain number.

`typeof myinput` // built in operator // type = "string" 
=== // out loud "tripple equals"

`Number(myinput)` // convert string to number.


## 131. Note about Introduction to Loops lecture 
**typo** in the slides at 8 minutes and 9 seconds, the slides should say that an infinite loop occurs when the terminating condition never returns false.

## 132. Introduction to Loops 
Just like in C

```javascript
while(true) {
  console.log("Put your feet up, take a load off");
}
```
Just like in C:

count++; // increment
count+=2; // increment by 2

"caca".length // built in string length

Just like in C:

"caca"[2] // 0 based array indexing.


## 133. 3 While Loop Exercises
## 134. While Loops Problem Set
## 135. While Loops Problem Set: SOLUTION
## 136. Annoy-O-Matic Code Along 
You can declare a variable inside a while loop.

```javascript
while(true) {
    var myinput = prompt("You need a rest fellah.");
}
```

!("Not without my anus".indexOf("anus") === -1) // -1 means substring is not in the string. checks if a string contains a specified substring. Note use of camel case for method names.

## 137. Note about Intro to For Loops lecture 
**typo** in the slides around the 56 second mark. It should say count = 1 instead of count = 0
 
## 138. Intro to For Loops		 
VERY similar to C: // is "var" ever require?? seems like python, you never declare variables, you just use them and they are created by context.

```
for(var i = 0; i < 7; i++) { // in his slides he uses var, but it works in the console without it.
    console.log(i + " Only craft dinner can calm my nerves.");
}
```

## 139. For Loops Quick Exercises 
ex.1 "0" "8"

ex.2 "h" "e" "1" "l" "o"

## 140. Loops Problem Set
## 141. Loops Problem Set: SOLUTION

---

# Section 12: Javascript Basics: Functions

---

## 142. Unit Objectives

function declarations vs. function expressions.
function definitions with arguments


## 143. Introduction to Functions

example:

```javascript
// DECLARE a function without args 
function fart() {
  console.log("Initiating fart now.");
}
// calling the function
fart();
```

TOOL NOTE: in chrome JS console typing out the name of a previously declared function echos the function text itself.


## 144. Arguments

```javascript
// a function with 1 arg
function mrhanky(is_poo) {
    if(is_poo === true) {
      console.log("Howdy ho");
    }
    if(is_poo === false) {
      console.log("Where is the christmas poo?");
    }
}

// a function with 2 args
function mrhanky(is_poo, is_christmas) {
// do stuff
}
// IF YOU EXCLUDE AN ARGUMENT from a function call its value is set to undefined, so the following call of the above is valid, but is_christmas === undefined.

mrhanky(true);

```

## 145. Note about Function Declaration vs. Function Expression

Function Declaration vs. Function Expression

whether or not you can **overwrite** both types of functions.

The answer is yes,

it can be overwritten if you assign that same variable to something else

## 146. The Return Keyword

if a function does not use "return" to return a value then by definition the function returns "undefined".

```javascript
// a function returning a value
function cartman(x, y) {
  return x+y;
}

// some built in string functions

"christmas poo".charAt(0); // returns 0th char in str - "c"
"christmas poo".charAt(0).toUpperCase(); // returns 0th char and uppercases it. - "C"
"christmas poo".slice(1); // return the substring starting with the 1st char - "hristmas poo"

// JUST LIKE IN C, "return" causes control to be immediately returned to the caller.

//
// 
//

// how to test that a variable has a specific type - typeof returns a string value

typeof num === "number" // true if num is of type number. else false.

//
//
//

// The above functions are called function declarations
// This is called a function expression:

var myfunc = function (is_poo) { // the function doesn't have a name.
  return !is_poo;
}

// this allows us to call the above function as follows:

myfunc(); // similar to a pointer to a function like in C.

```
## 147. Functions Quiz
ex.1. returns 40 - 10 = 30

ex.3. return 40*2 = 80. No log.


## 148. Functions Problem Set

p1. isEven(n)

p.2. factorial(n)

p.3. kebabToSnake(str) - replace "-" with "_.

e.g.

hello-world >>> hello_world

```javascript

function isEven(n) {

  if(typeof n !== "number") {
    return false;
  }

  return ( n % 2 === 0);
}

function factorial(n) {

// assuming n is a positive integer. if input not valid, return -1, assuming a negative factorial is invalid

  if(typeof n !== "number") {
    return undefined;
  }
  
  if(n < 0) { //  0! = 1 by definition, so allow n = 0.
    return undefined;
  }
  
  if(!(Number.isInteger(n))) {
    return undefined;
  }
  
  var result;

  for(result = 1; n > 1; n--) {
    result = result * n
  }
  
  return result;
  
}

function kebabToSnake(namestr) {
// return undefined if arg is not a string.
  if(typeof namestr !== "string") {
    return undefined;
  }
  
return namestr.replace(/-/g, "_");
}

```
## 149. Functions Problem Set: SOLUTION
## 150. Scope Code Along

JS allows nesting of functions.

function scope vs. global scope.

within a function, we may access variables in the global scope.

Using the "var" keyword inside a function scope, and with a variable name which already exists in the global scope, causes new storage to be allocated for a variable of the same name in the function scope. The two variables now have the same name but in different scopes.

(Lecture is WRONG!) CORRECT: using an undeclared variable name inside a function that also does not exist in the global scope causes a reference error. The error occur wether you just pass the undeclared variable to a function or you use the variable in an expression.



```javascript
function doSomething() {
    console.log(pipi); // pipi does not exist in any scope. 
}

doSomething() // Causes reference error.

pipi // Causes reference error.
```
## 151. Scope Quiz

ex.1. returns true.

## 152. Higher Order Functions Code Along 
 Higher Order Functions = a function that accepts an argument of type function or that returns a function.
 
 ```javascript
 // e.g.
 setInterval(yourfunc, 1000); // 1000msecs
 2 // return value. Use this number as argument to clearInterval(funcNumber);
 // JS allows unnamed functions aka anonymous functions. e.g.
 
 setInterval(function(){console.log("christmas poo")}, 1000); // first arg. is an anonymous function
 
 ```

---
 
# Section 13: Javascript Basics: Arrays

---

## 153. Unit Objectives

our first datastruture

define and add and remove from arrays.

## 154. Introduction to Arrays

// the syntax. square brackets. 0 start index.
var southParkCharacters = ["MrHanky", "Cartman", "Stan", "Kyle"];

// accessing array elements

southParkCharacters[1];

// changing a particular index value

southParkCharacters[0] = "Chef";

// appending to the end of the array

southParkCharacters[4] = "MrKitty";

// appending beyond the end does not cause an error, it fills between with "undefined"

// other array creates

var a0 = [];
var a1 = new Array(); // equivalent. uncommon.

// can hold different types
var a2 = [7, true, "caca", null]; 

// just like strings, arrays have a length member.
a2.length // is = 4.

## 155. Arrays Methods

// built in METHODS - similarity to Java

**push/pop**

var southParkCharacters = ["MrHanky", "Cartman", "Stan", "Kyle"];

southParkCharacters.push("MrKitty"); // adds to the end with the higher index (= adds to the end of the array) // returns new length

southParkCharacters.pop(); // removes from end of array // returns removed item

**shift/unshift**

southParkCharacters.unshift("MrKitty"); // adds to the end with lower index (= adds to the beginning of the array) // returns new length // like enqueue() to a queue

southParkCharacters.shift(); // removes from the beginning of the array // returns removed item // // like dequeue() to a queue

**indexOf**

southParkCharacters.indexOf("Cartman"); // returns 1, the index of the given value in the array. // returns -1 if not in the array // returns lowest index if the array has duplicates.

**slice**

southParkCharacters.slice(1,3); // returns the subarray starting with index 1 up to the 6th index of the array. Note that the item at the end index is excluded from the returned array. // The returned array is a copy not a reference.

southParkCharacters.slice() // with no args, a copy of the array is returned.

// see MDN docs for JS arrays - ALL there.

## 156. Array Quiz

ex.1. prints undefined.

ex.2. prints "Mooney".
// syntax for multidimensional arrays. array of arrays. e.g.

var sqmatrix = [
[2, 5],
[7, 11]
];

## 157. Note about Todo List Code Along

How to circumvent the issue of the prompt function blocking the HTML from loading right away.

## 158. Todo List Code Along Part 1
## 159. Array Iteration

for loop vs forEach loop.

var southParkCharacters = ["MrHanky", "Cartman", "Stan", "Kyle"];

// forEach syntax, note that this is not a keyword of JS but rather a method of the array data type.

southParkCharacters.forEach(function(character){console.log(character)}) // the function arg is an item from the array. // the function arg can be excluded.

## 160. Quick Array Iteration Challenge

ex.1. prints 3, 6, 9
## 161. Note about Todo List Code Along Part 2

.forEach takes a callback function, that callback function is expected to have **at least 1**, but **up to 3**, arguments.

arg1 array item

arg2 item index

arg3 the full array itself.

## 162. Todo List Code Along Part 2

// removing an item from an array.

arr.splice(start, delcount); // returns the removed items in an array. arr has been updated.

southParkCharacters.splice(1, 1); // removes "Cartman" from the array. returns an ARRAY with only i.e. ["Cartman"].

// In JS a function can be called before its definition in a single file. i.e. the following code works without error.

```javascript
printSouthPark(); // works fine. JS knows the function is defined below.

function printSouthPark() {
  console.log("The monkey claw is smelly.");
}
```

## 163. Array Problem Set

```javascript
//
function printReverse(arr) {
  console.log(arr.reverse());
}

// all elements same
function isUniform(arr) {
  if(typeof arr !== "object") {
    return false; // not an arr.
  }
  if(arr.length === 0) {
    return true; // consider an empty array uniform.
  }
  
  var first = arr[0];
  
  for(var i = 1; i < arr.length; i++) {
    if(first !== arr[i]) {
      return false;
    }
  }
  
  return true; 
}

// add numbers, assume numbers
function sumArray(arr) {
  var s = 0;
  
  for(var i = 0; i < arr.length; i++) {
    s += arr[i];  
  }
  
  return s;
}

function arrmax(arr) {
  if(arr.length === 0) {
    return undefined;
  }
  
  var tempMax = arr[0];
  
  for(var i = 1; i < arr.length; i++) {
    if(arr[i] > tempMax) {
        tempMax = arr[i];
    }
  }
  
  return tempMax;
}
```
## 164. Array Problem Set: SOLUTION
## 165. OPTIONAL: Building Our Own ForEach 
example of a function that takes a function as an argument. Works similar to C function pointers except that you can define a function at the same time as you are passing it as an argument.

FYI:  you must use parens around anonymous functions in the JS console. i.e.
\> function(){console.log("Christmas poo")} // syntax error.

\> (function(){console.log("Christmas poo")}) // works fine.

// to call an anonymous function immediately, just append () 
\> (function(){console.log("Christmas poo")})()

// Adding a method to the built in Array object.

Array.prototype.myForEach = function (somefunc) { 
// "this" means the same as in Java.
  for(var i = 0; i < this.length; i++) {
    somefunc(this[i]);
  }
}

// compare to 
arr.forEach(function (item, i, thearr){console.log("poo")})

---

# Section 14: Javascript Basics: Objects 
---

## 166. Introduction to Objects 
// object syntax example
```javascript
var person = {
  name: "Darbin",
  age: 100,
  city: "NY",
  "1MoreThing": "YahYah",
  "A space": "in the member name"
};

// alternatively 

var person = {};
person.name = "Darbin";
person.age = 100;
person.city = "NY";
person["1MoreThing"] = "YahYah";
person["A space"] = "in the member name";

// alternatively 
var person = new Object();
//... same shit as above, RECALL JSON.
```

// two ways to refer to object members.

person.name // dot notation

person["name"] // bracket notation

// syntax quirks - 

// if the member name starts with a number, you must use bracket notation

person["1MoreThing"]

// if you want to use a string to refer to a member, you must use bracket notation

var str = "city"
person[city]

// if the member name has a space in it, you must use bracket notation 

person["A space"]

// member names are case sensitive

person["A Space"] // undefined. "S" should be "s"

// referencing a non-existing member returns undefined.

person["caca"] // undefined. 


## 167. Comparing Objects and Arrays 
array - item access via integer index

vs.

object - item access via member name - members can be added on the fly.

## 168. Nested Objects and Arrays 
we can nest one in the other. 

e.g.

an array whose items are objects.

an object with a member that is an array.

syntax is similar to python. 

## 169. Objects Quiz 
ex.1. "someobject.123 = true" // syntax error - member name starts with a number.

ex.2. someObject.friends[0].name

## 170. Movie Database Exercise 
```javascript
var movieObject = {
hasWatched: false,
title: "None",
rating: 0.0
}

// when you assign objects, does JS create a copy or a reference? i.e.

var m0 = movieObject;
var m1 = movieObject;

// Then setting
movieObject.rating = 5.0; 

// what are the values of m0, m1, movieObject? // all three reference the same object so each has value =

{hasWatched: false, title: "None", rating: 5}

// my guess is a reference. ANS: its a reference, not a copy.

// if a reference, how do you create a new object? My guess is

var m2 = new Object(movieObject) // returns a reference TOO! 
m2.rating = 3.0; // changes all, movieObject, m0, m1.

// ANS: Here's one way to do it

m2 = Object.assign({}, movieObject) // https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Object/assign

// Here's something equivalent to the above. This creates a new copy of MovieObject.
m3 = Object.create(Object.prototype, Object.getOwnPropertyDescriptors(movieObject));

```

The guy uses arr.forEach() here.

## 171. Adding Methods to Objects 
Since in JS functions are treated like values, we can set a object member name to a function definition , this is called a method in JS.

// syntax

var myObj = {
myMethod: function(a,b) {return a + b}
}

myObj.myMethod(7,1) // calling the method.

## 172. The Keyword This

namespaces// The undescore.js library. It exists, and all methods are under an object named "_". e.g. _.find();

this // a contextual reference to an object from within that object, a shorthand notation.

// e.g.

comments = {}

comments.data = ["poo", "caca","pipi"]

comments.print = function() 
{this.data.forEach(function(item){console.log(item)})}

---

# Section 15: DOM Manipulation

---

HTML and CSS + JS
## 173. IMPORTANT NOTE, PLEASE READ!!!

Put your JS \<script> right before the closing \</body>  tag.
This prevents errors caused by references to HTML / CSS that have not yet been loaded by the browser.

## 174. Introduction to the DOM
## 175. Defining the DOM

Its a JS API for manipulating HTML+CSS.

Elements vs. Attributes.

DOM modeled as a tree of nodes

doc->root=html

doc->html

->head

->body

element.text

element.attribute.href

```javascript
document
console.dir(document) // gimme the document as an object.
```

## 176. Select and Manipulate

```javascript

var h1 = document.querySelector("h1");

h1.style.color = "blue";
// element_obj = document.querySelector("element_name/other_selection_syntax");
// element_obj.style.attribute_name = attribute_value.
```
## 177. Note about UI changes in new versions of Chrome

Colt mistakenly refers to the array-like object that comes back from document.getElementsByClassName() as a "NodeList", when in fact it is an `HTMLCollection`. 

## 178. Important Selector Methods

```javascript

document.URL
document.links
document.body
document.head

// selector methods

document.getElementById()
document.getElementsByClassName() // returns an array like object but it is not an array, therefore e.g. there is no forEach() method attached, however the console does print things at in a way that is similar to arrays (using square brackets). JS allows you to create array like object such that you can index into them, in this case the array like object is an instance of an html collection. Also note that "typeof [7,5]" returns "object".
document.getElementsByTagName()
document.querySelector() // similar to methods above but using a CSS-like syntax. e.g. "#myidname" , ".myclassname", "h1" . Instead of returning a collection in the case of multiple matches this method only returns the first matching item. To get all use method below. You can use this method and the one below to simulate the 3 methods above. Another example argument: "li a.special" means gimme the first "a" inside of an "li" that also has class ".special". When there is no match, this method returns null.
document.querySelectorAll()
```

TOOL NOTE: In chrome JS console there is a button on the upper left that lets you see what a page looks like on a mobile device and you can shrink the page in arbitrary ways.

## 179. Selector Exercise

ex.1. 
document.getElementById("first")
document.getElementsByClassName("special")[0]
document.getElementsByTagName("p")[0]
document.querySelector("p")

// again, querySelector() accepts CSS-like selector syntax so "h1 + p" will select h1 adjacent to p.

## 180. Note about next lecture (Manipulating Style):

The heading "An Alterative" should say "An Alternative"

## 181. Manipulating Style

* changing style

`obj.style.CSS_property_name = new_CSS_value;` // all values are strings.

* classes

two ways of setting CSS style. The second is recommended.
```javascript
tag = document.getElementById("mycontent");
tag.style.color = "blue";
tag.style.fontSize = "100px";

//vs

// in CSS .mycontentclass {color: "blue"; font-size: "100px"}

tag.classList.add("mycontentclass");
.remove();
.toggle();
// classList is not an array.
```


## 182. Manipulating Text and Content

* content

`tag.textContent` // all text inside the tag, excluding nested tags.

`tag.textContent` = "Some new content"; // This will remove any nested tags.

// to keep the nested tags

`tag.innerHTML` // returns the text and keeps nested tags.

// setting `textContent` ignores tags in the new value.

// `innerHTML` takes tags in the new value into account.

## 183. Manipulating Attributes

* attributes

`tag.getAttribute("href")`

`tag.setAttribute("href", "www.google.com")` // by default this value is interpreted as a relative path, i.e. it assumes "www.google.com" is a file named "www.google.com"  in the current directory. To get the intended behaviour you must include the protocol prefix "http://" i.e. "http://www.google.com"


## 184. Note about changing the Google logo in next lecture

using the `src attribute` **no longer works**.

use `srcset attribute`

// my comment.

The guy uses myimg.setAttribute() to change the img source. The above refers to using "src" as the attribute name, which indeed doesn't work. You must use "srcset" as the attribute name. But there are two other ways to do the same thing.

myimg.setAttribute("src", "im0.png"); // doesn't work
myimg.setAttribute("srcset", "im0.png"); // works

// both these work too

myimg.src = "im0.png"
myimg.srcset = "im0.png"

## 185. Playing With Google Code Along

END.

---

# Section 16: Advanced DOM Manipulation

---

## 186. Introduction to Events
event = something happened , e.g. user scrolled, user pressed the enter key, etc.

We can attach an "event listener" to things

```javascript
//element.addEventListener("event_name/type", callbackfunction);
var butt = document.querySelector("button");
element.addEventListener("click", function(){});

// element.addEventListener() is additive, meaning that it will retain all event listeners added, so adding two "click" listeners will run two events upon click.

// adding an event listener to an element with nested elements can affect all nested elements.
```
## 187. Note about Introduction to Events

why you get an error when trying to use lis[i] instead of this 

## 188. Color Toggle Exercise

Note that any CSS associated with your html file, including inline CSS in the head because part of the CSS available to you via JS, in particular, the CSS for a class that you might use with `tag.classList.toggle("myclassname")`

## 189. Score Keeper Project Part 1

\<input type="number">

Note that a JS file associated with your HTML only gets processed and executed once as part of the loading of the page.

## 190. Note about Score Keeper Project Part 2

He should have said "..and turn it into a Number". 

difference between the input and change event listeners,

## 191. Score Keeper Project Part 2

```javascript
numinput = document.getElementById("winningscore")

// or

numinput = document.querySelector("input")

// or

numinput = document.querySelector("input[type='number']")

numinput.addEventListener("change", function(){
  // accessing the number value
  this.value // even if this is a number input the value is a string, so you must explicitly convert the number using Number(n) if you really want a number
  // or
  inputelement.value 
});
```

## 192. Other Types of Events: Todo List

MDN event reference

"mouseover" // = hover
"mouseout" 

## 193. Note regarding counting events exercise
## 194. Counting Events Exercise 
END.

---

# Section 17: Color Game Project

---

## 195. Notes regarding color game

make sure that the colors have spaces after the commas in the RGB expression
 
 e.g., 
Correct: "rgb(255, 0, 0)"

Incorrect: "rgb(255,0,0)"

height or width as a percentage, that's a percentage with respect to the element's parent."

## 196. Creating the Color Game Pt. 1

// color phade away.

// random color values.


## 197. Creating the Color Game Pt. 2
## 198. Creating the Color Game Pt. 3
## 199. Creating the Color Game Pt. 4
## 200. Creating the Color Game Pt. 5
## 201. Creating the Color Game Pt. 6
## 202. Creating the Color Game Pt. 7
## 203. Color Game Project Part 8
## 204. Creating the Color Game Pt. 9 
END.

---

# Section 18: Intro to jQuery

---

## 205. What is jQuery?

another API, like Bootstrap. It lets you do thing more easily than without. Abbreviated syntax. aka a library like stdlib in C.

single file. link it.

select elements
manipulate "
create "
add events listeners
animate shit
add "effects"
make HTTP requests (aka AJAX = asynchronous javascript and XML).

## 206. Why Use jQuery?

why not always use Jquery?

* the good
  * better DOM API
  * shorter code
  * easy syntax
  * cross browser support
  * AJAX
  * commonly used
  
* the bad
  * youmightnotneedjquery.com
  * DOM API has been improved
  * everything jquery does can be done without it.
  * if you use a very small subset of jquery, it may not be worth including an entire library. e.g. all you want is animations.
  * performance can be a problem if you are not familiar with using jquery
  * it is becoming less popular
  
* The guy's opine on jquery
  * the guy use to skip into jquery without covering basic JS methods
  * students have reported companies departing from jquery use.

## 207. Including jQuery
## 208. Note about jQuery
## 209. Selecting with jQuery
$ = a jquery function

to select

$("selector_string")

works like document.querySelectorAll("str");

$("h1") // select all h1's.

$("li a")

changing style with jQuery

$("h1").css(property_name, property_value)

// two ways

$("h1").css("border", "2px solid red");

var mystyle = {
 backgroundColor: "pink",
 fontWeight: "bold"
};

$("h1").css(mystyle)

// .css method can act on multiply selected elements e.g. to change color of all li's

$("li").css("color", "red")

// note use of camel case when passing in CSS objects to .css().

## 210. Selector Exercise

```javascript
$("div").css("background", "purple")

$(".highlight").css("width", "200px")

$("#third")[0].css("border", "1px solid orange") // WRONG! .css() is not a method of each list element, only of the whole list.

$("#third").css("border", "1px solid orange") // RIGHT!

$("div")[0].css("color", "pink") // WRONG! see above.

// RIGHT 
$("div")[0].style.color = "pink"
// or
$($("div")[0]).css("color", "pink")
// or - CSS pseudo selector
$("div:first-of-type").css("color", "pink")
// or same as above but jQuery accepts a shorter argument
$("div:first").css("color", "pink")

// checking if jQuery is available/loaded

if(jQuery) {

} else {
// no jQuery
}
```
## 211. Text and HTML

```javascript
// 7 methods - https://api.jquery.com/

// Get the current value of the first element in the set of matched elements or set the value of every matched element.
// for getting input-element values
// gets+sets
val()
val("The new value")
// Get the combined text contents of each element in the set of matched elements, including their descendants, or set the text contents of the matched elements.
// gets+sets
text()
text("new text")
// Get the value of an attribute for the first element in the set of matched elements or set one or more attributes for every matched element.
// gets+sets
attr("src")
attr("src", "gascat.png")
// Get the HTML contents of the first element in the set of matched elements or set the HTML contents of every matched element.
// gets+sets
html()
html("<li>Suck my balls</li>")
// Adds the specified class(es) to each element in the set of matched elements.
addClass()
addClass("thisclass thatclass") // adds two classes
// Remove a single class, multiple classes, or all classes from each element in the set of matched elements.
removeClass("theclasss")
// Add or remove one or more classes from each element in the set of matched elements, depending on either the class’s presence or the value of the state argument.
toggleClass("TheClass")

// Misc. method
$("img").last().attr("src")
$("img").first().attr("src")
```
## 212. Attr and Val

See above. 

## 213. Manipulating Classes

See above.

END.

---

# Section 19: Advanced jQuery

---

## 214. jQuery Events: Click 
```javascript
// events - https://api.jquery.com/category/events/
click()

$("#theid").click(function(){console.log("The monkey claw is smelly")}) // works on collections of elements.
// this keyword requires extra syntax 
$(this) // instead of just "this"

keypress()

$("#theid").keypress(function(){console.log("The monkey claw is smelly")})
// getting the key that was pressed- add arg.
$("#theid").keypress(function(event){console.log("The monkey claw is smelly key = " + event.which)})

on()
// type of event is specified in an arg.

$("#theid").on("click", function(){console.log("The monkey claw is smelly")})

// 1 important difference between on("click") and click(). With on("click") all future nested elements inherit the event listener.
```
## 215. Note about typo in the next lecture
## 216. jQuery Events: Keypress
See above.
## 217. jQuery Events: On
See above.
## 218. jQuery Effects 
fading effects
slide effects.

```javascript
//https://api.jquery.com/category/effects/fading/
.fadeOut(dur, completefunc)
.fadeIn()
.fadeToggle()

.slideDown(dur, completefunc)
.slideUp()
.slideToggle()
// Misc.
$("theelement").remove() // deletes elements from the DOM.
```

---

# Section 20: Todo List Projects

---

### 219. Note About Todo List App Fade and Slide Animations

making use of jQuery's fadeOut and fadeToggle methods, but the slide animation (for the trashcan icon) will be done with **CSS**, not jQuery. 
### 220. Intro to the Todo List App
### 221. Todo List: Folder Structure
### 222. Todo List: Basic HTML
### 223. Todo List: Marking Completion
### 224. Todo List: Deleting Todos
### 225. Note about next lecture (Creating Todos):
### 226. Todo List: Creating Todos
### 227. Todo List: Styling Pt. 1
### 228. Todo List: Styling Pt. 2
### 229. Note about Font Awesome 5 and Toggling the Form
### 230. Todo List: Toggling the Form 
END.

---

# Section 21: OPTIONAL Project: Patatap Clone	 ---

### 231. IMPORTANT NOTE, PLEASE READ!!!
### 232. Project Intro
JS libs
paperjs.org // animation
howler.js // audio

### 233. Note about Paper.js Exercise
### 234. Paper.js Intro
### 235. Paper.js Exercise
### 236. Adding Keypress Events
### 237. Paper.js Animations
### 238. Note about next lecture (Howler.js)
### 239. Adding Howler.js
### 240. Patatap Clone Refactor 
END.

---

# Section 22: Backend Basics

---
 
### 241. Introduction to Backend
HTTP requests and responses.

Static vs. dynamic pages.

backend language. server. database.->HTML+CSS+JS.

stackshare.io // per site backend info.

Our stack. JS Express MongoDB.

* Example backend operations. 
  * is logged in check
  * conditional front end code generation.
  * add / remove things from a DB.
  * sort/rank things.
  * return search results

### 242. Note about Postman (HTTP in Depth)
### 243. HTTP in Depth
HTTP requests and responses.

GET requests with URL query args.

POST requests usually have a body.

### 244. Backend Workflow Pt. 1
Don't take notes on this.
### 245. Backend Workflow Pt. 2
You do not need to understand 99% of this code.
// res=response.
POST request with form-URLencoded body.

```html
<form action="/createDog" method="POST">
<input type="text" name="name" placeholder="">
<input type="text" name="breed" placeholder="">
<input type="submit">
</form>
```
### 246. IMPORTANT!!! Please Read! Note about Cloud9 signup

The original c9.io has been closed down, but we have an awesome alternative cloud based IDE

//GoormIDE Sign Up Instructions

https://gist.github.com/nax3t/d6a9006b338355eba42c4e00144c7417

// My goorm dashboard

https://ide.goorm.io/my

// mac local setup instructions

https://zarkom.net/blogs/mac-local-coding-environment-6283

// Amazon's cloud 9 user guide

https://docs.aws.amazon.com/cloud9/latest/user-guide/ide.html

// to install mongodb in cloud 9 - this didn't work >> https://docs.mongodb.com/manual/tutorial/install-mongodb-on-amazon/

sudo yum install mongodb // this worked

### 247. Introduction to Cloud 9
### 248. Setting Up Cloud9 
END.

---

# Section 23: The Command Line

---
# TODO
READ intro's to

https://www.mongodb.com/

https://nodejs.org/en/

### 249. A NOTE ON SOLUTIONS!

Every single bit of code I type from now until the end of the course is available  on this course's publicly visible github repo: https://github.com/nax3t/webdevbootcamp 

// goorm
// help info hard to find - language issues - how to open file for edit from terminal? no man pages. delay a bit annoying.


// cloud 9 dash board on amazon.
 
https://us-east-2.console.aws.amazon.com/cloud9/home?region=us-east-2

### 250. Introduction to the Command Line
### 251. CD and LS
### 252. Touch and Mkdir
### 253. Removing Files and Folders
### 254. Command Line Exercise
END.

---

# Section 24: Node JS

---

### 255. Introduction to Node
What: a runtime enviromment. Like plain Java. Allows server side JS execution. 
Why use it: popular. Many Libs. Same lang. on front and backend. "Fast".

// Why not use any other backend language
### 256. Using Node

node - starts node interactive mode. - no browser related variables and functions.

irb - starts ruby interactive mode.

REPL = read evaluate print loop.

### 257. Node Echo Exercise
### 258. Node Average Exercise
### 259. Introduction to NPM

NodeJS program for installing libs/apps. Like Python pip, mac ports. Linux Yum.

Express is a npm package.

Analogous to client side JS script includes like jQuery.
 
### 260. Note about Installing NPM Packages
ignore npm WARN.

Now, when you open up the cat-me folder from within the node_modules directory you will find all of the cats inside of cats.JSON (instead of cats.js).

### 261. Installing NPM Packages

npm install cat-me

node_modules dir created locally.

//nodejs include.

var thepkg = require("cat-me") // cat-me/index.js

thepkg();

npm docs // npmjs.com

### 262. Note about NPM Faker Exercise
### 263. NPM Faker Exercise

npm install faker
```javascript
// FYI on Amazon cloud 9 when you run "npm install faker" the install directory != your CD, instead it installs in /home/ec2-user//node_modules // This dir is already in your path.

// FYI asking npm for help - npm help install.

//
var fkr = require("faker");

for(var i = 0; i < 10; i++) {
  console.log("Get me a Ferrari cake!");
  console.log(fkr.commerce.productName() + " " + fkr.commerce.price());
}
```

END.

---

# Section 25: Server Side Frameworks

---
 ### 264. Introduction to Express

lib vs. framework. Both external code. Lib you decide which methods to use. Framework - give up some control - you fill in the gaps - templates - setup work already done.

What is: Express - Web Dev Framework within NodeJS.

Why: Popular, good docs. heavy wight vs light weight - how much work you need to do. Heavy weight means less work for you. Light weight, more work but you have more control. Ruby/Rails is heavy weight - get things done without understanding.

expressjs.com // API ref. 
### 265. Note about Our First Express App

shut the server down by pressing ctrl + c

### 266. Our First Express App

```javascript
// require statements// includes

var express = require("express");

var app = express();

// routes // app.http_method.(URL_REL_PATH, function callbackfunc(request, response) {
//  response.send("The HTML");
//});

// Handling a get request.
app.get("/", function(request, response){
   response.send("home"); 
});

// starting the node server in cloud 9

app.listen(process.env.PORT, process.env.IP, function(){
    console.log("So this is NodeJS?! " + process.env.IP + " " + process.env.PORT);
});
```

TOOL NOTE: in cloud 9 press ctrl+ESC to hide/show console.
TOOL NOTE: To find out your node server URL click Preview->Previous Running APP. Then click on the internal browser url line.

POSTman req doesn't work. - FIX = install this chrome extension. https://chrome.google.com/webstore/detail/postman-interceptor/aicmkgpgakddgnaphhhpliifpcfhicfo/related


 Stuff below wasn't the fix for broken POSTman but it may come in handy later.
 
 --  see here for solution - https://docs.aws.amazon.com/apigateway/latest/developerguide/how-to-use-postman-to-call-api.html -- see here for your AWS auth settings - https://console.aws.amazon.com/iam/home?region=us-east-2#/security_credentials

for AccessKey and SecretKey see my local dic xxx/dev/keyfile.csv

AWS region = us-east-2
Service Name = execute-api

### 267. The Package.JSON

package.JSON files - come with all npm packages - info about a given npm package. - package dependencies. Why git repo doesn't contain a node_modules directory.

// "npm --save" option - saves the package name into our package.JSON file. - to create a package.JSON file use "npm init" - wizard creation too. To add a dependency npm install cat-me --save.

### 268. How to automate server restart

npm i -g nodemon

nodemon myapp.js

// create a package.JSON to avoid having to pass nodemon a file name

### 269. Route Params

* "*" 
  * // catch for 404 NOT found.



* route order 
  * the catch all "*" should be the last one, if its first then it will essentially override all other app.get() callbacks. This implies that the first matching route "wins", once a callback runs execution stops after that request is handled.

* route params aka path variables - special chars in the route.
  * ":" e.g. "/r/:subName" , "/r/:subName1/comments/:subName2" - ":" means accept any path node name here. e.g. the first route would match "/r/caca" "/r/poopoo".
  * To determine the value of :subName, use request.params["subName"]/request.params.subName.
      * "i now have a dynamic web page".

### 270. Express Basics Exercise
### 271. Express Basics Exercise: SOLUTION 
EJS = Embedded Javascript.
 
END.

---

# Section 26: Intermediate Express

--- 
### 272. Note about Templates and EJS 
with npm init, be sure not to **name** the project (or the **folder** that the project lives inside of) the same as any of the node **packages** being used in the project itself. e.g. don't use "ejs" or "express". To fix rename the project on the first line: "name": "project-name-here".

Project names need to be all lowercase and contain url friendly characters, e.g., no spaces, instead use a hyphen.

### 273. Templates and EJS 
EJS = Embedded Javascript.

* using response.render() vs send()
  * `response.render("filename.ejs")`
  * returns filename.ejs under the `./views` directory after processing any EJS.
  * EJS format is `<%= 5+7%>` will embed "12" in the EJS output.
* using EJS
  * default dir for EJS is ./views.
* variables in EJS
  * Pass data to the EJS file using second argument of .render().
  * response.render("filename.ejs", {varname1: varname1value})
  * We can reference the data specified in the second argument using `<%= varname1 %>`.
  
  TOOL NOTE: instead of "c9 app.js" use cmd+P to open files in the editor.
 

### 274. EJS: Conditionals and Loops 
```ejs
<%= %> // tells JS to evaluate the contents as an expression
// v.s.
<% %> // conditional expressions, e.g. if's
//e.g.
<% if(robotName === "walle") { %>
<h1> this is not a star wars robot. </h1>
<% } %>

////////////////////////////
var posts = [/*blah blah*/] //array data
response.render("posts.ejs", {posts: posts})// property name same as variable name is allowed , resolved by JS using context.

// similarly for loops. and [].forEach()
```
### 275. Note about Serving Custom Assets 
including partials in your EJS view:

<% include partials/header %>

vs.

<%- include("partials/header") %>

to update JS in your terminal: `npm i -S ejs`

### 276. Serving Custom Assets 
including CSS and JS with EJS

```ejs
<style>
color: red;
</style>
<link rel="stylesheet" href="app.css"> // app.css should be under ./public/app.css + after - 
var app = express();
app.use(express.static("public")); //  telling express where to look stuff like CSS files.

app.set("view engine", "ejs"); // to avoid writing .ejs file extension on each call to response.render("home") = response.render("home.ejs")

// creating templates aka partials
mkdir views/partials
touch views/partials/header.ejs
touch views/partials/footer.ejs

// include syntax

<%- include("partials/header") %> // includes file at views/partials/header.ejs
// <link rel="stylesheet" type="text/css" "/app.css"> // where the css file is @  project/public/app.css

project_dir
  app.js
  package.JSON
  node_modules
  public
    app.css
  views
    home.ejs
    love.ejs
    posts.ejs
    partials
      footer.ejs
      header.ejs
```

### 277. Post Requests Part 1 
TOOL NOTE REMINDER: When you call console.log("caca") within a node app the prints go to your local terminal not the browser JS console.

Adding a "post route" in the JS.

```javascript
app.post("/addspchars", function(request, response){
  console.log(request.body);
  response.send("This is the post route.")
});

```

Adding a HTML form to an .ejs, just plain HTML.

```HTML
<form action="/addspchars" method="POST"> <!-- NOTE these form tag attributes -->
    <input type="text" name="charname"> <!-- You must provide a name attribute for any input you want to access via the request body. -->
    <input type="submit"> <!-- when you submit the text input above gets placed in the post request body. -->
</form>
```

### 278. Post Requests Pt. 2

```javascript
app.post("/addspchars", function(request, response){
  console.log(request.body); // doesn't work until you install a special package. "sudo npm install -g --save body-parser"
  response.send("This is the post route.")
});
```

```javascript
// after installing body-parser, you must "include" it.
var express = require("express");
var app = express();

var bodyParser = require("body-parser"); // "include" body-parser node package.
app.use(bodyParser.urlencoded({extended: true})); // Tell express to use body-parser
```

```javascript
app.post("/addspchars", function(request, response){
  console.log(request.body); // after the above - request.body is defined. prints "{ charname: 'Jimmy' }" to the console upon hitting the submit button. See HTML below.
  response.send("This is the post route.")
});
```

```HTML
<form action="/addspchars" method="POST"> 
    <input type="text" name="charname">
    <input type="submit">
</form>
```

```javascript
response.send("This is the post route."); // instead of this on the .post() route we can redirect to another page, e.g. to the page where new data has been added by the previous POST request.

// To redirect use:
response.redirect("/spchars");
```

Notice that our array of names in JS is reset each time the app restarts, we will have a persistent array by using a database.

END.

---

# Section 27: Working With API's

--- 
### 279. Intro to API's
API = A set of functions.

API compilations:

https://ifttt.com

https://www.programmableweb.com/

### 280. JSON and XML

https://www.reddit.com/r/Awww/

https://www.reddit.com/r/Awww.json

### 281. Making API Requests with Node

We need a new node package to request data 

e.g. from terminal

curl https://google.com

https://github.com/request/request

// this node package is now deprecated.

// npm WARN deprecated request@2.88.2: request has been deprecated, see https://github.com/request/request/issues/3142


### 282. Note about Sunset Time API Example

Yahoo Weather API.

This API was retired as of January 3rd, 2019.

another free API that you can use in place of the Yahoo API, and it doesn't require any signup. You can find it [here](https://openweathermap.org/current).

### 283. Sunset Time API Example

Do a get request to a URL that returns JSON in the body.

e.g.

https://samples.openweathermap.org/data/2.5/weather?q=London,uk&appid=b6907d289e10d714a6e88b30761fae22

With the "request" node package, the JSON body is passed in as a string, to turn parse that string into a JS object we use the built in JS function JSON.parse(bodystr)

### 284. Note about JSON Placeholder API Example

New node package - for debugging - to install use `npm i -D locus`

WTF is `-D`? From `npm help install`

"`-D, --save-dev`: Package will appear in your `devDependencies`."

Using locus for debugging (https://asciinema.org/a/102735?autoplay=1&speed=1.5)(https://www.npmjs.com/package/locus):

In your .js code, whereever you want to stop execution and inspect variables insert `eval(locus);`

This begins a REPL session, 

type the name of a var to view it, 

you can also modify variables using standard JS syntax.

type `exit` to exit the REPL session, a new REPL session will be started at the next occurrence of `eval(locus);` if another one exists and is encountered during subsequent execution.

tab completion for variable names is supported.

pressing TAB+TAB at an empty REPL line shows a list of all names in the REPL's scope.

require("locus"); // just add this line before any `eval(locus);`

TOOL NOTE: I was unable to install locus in my global node_packages DIR. Doing that caused a segfault when running my .js file that called `eval(locus);`. Installing it in my sec27 project directory works fine.

### 285. JSON Placeholder API Example

Fake Online REST API for Testing and Prototyping

http://jsonplaceholder.typicode.com

**New JS syntax:**

```javascript
// C like "const" var qualifier.
const parsedData = JSON.parse(body)
// "template literal" - similar to Python
console.log(`${parsedData.name} sucks lots of balls`)

//
function(request, response, body) {
// do stuff
}

// "arrow function" equivalent to above
(request, response, body) => {
// do stuff
}

// "promises" instead of callbacks - npm i request-promise
requestpromise = require("request-promise");
requestpromise('URL')
.then( (body) => {/*do something*/}) // in place of callback
.catch( (err) => => {/*do something*/}) // if an error occurs.

```
### 286. Note about Movie API lectures

Movie API has recently gone **private**.

Colt has acquired an API key for **everyone** to use.

making requests with the key:

General search: 

http://www.omdbapi.com/?s=guardians+of+the+galaxy&apikey=thewdb

Search with Movie ID: 

http://www.omdbapi.com/?i=tt3896198&apikey=thewdb

See usage:

http://www.omdbapi.com/

### 287. Movie API App: Introduction
### 288. Movie API App: Results Route
### 289. Movie API App: Displaying Data
### 290. Movie API App: Adding Search 
How to access URL query params from an express route

```javascript
app.get("/", function(request, response){
    console.log("GET @ / bro. " + request.query.str) // <<< HERE IT IS. Prints "cartman" if URL = http://localhost:3000/?str=cartman
    
    response.render("index.ejs");
});
```

FYI a form with method="GET" will automatically add form values to the URL in Query Param format upon submit.

```HTML
<form action="/" method="GET">
    <input type="text" name="str" placeholder="str here"></input>
    <input type="submit"></input>
</form>
```

END.

---

# Section 28: YelpCamp: Basics

---

### 291. YelpCamp: Initial Routes

This project will go on through the remainder of the course. Will have several versions of the site.

To Start:

Landing page.

List camps page.

Camp = Name + Image.

### 292. Note about YelpCamp: Layout
### 293. YelpCamp: Layout
### 294. YelpCamp: Creating Campgrounds
### 295. Note about YelpCamp: Styling Campgrounds Lecture
### 296. YelpCamp: Styling Campgrounds
### 297. YelpCamp: Styling Nav and Forms 


