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
## 151. Scope Quiz
## 152. Higher Order Functions Code Along 
# TODO - my web site.
* [x] FIX SIGNUP AND LOGIN POSITION @ BREAKPOINT AROUND SMALL. http://devtest.localhost/bs_startup_landing.html

Test above with default nav. If same problem occurs it might  be my custom CSS. Maybe font size.

ANS: Fixed by removing the CONTACT tab. Navbar content was too wide so the elements on the right were pushed to a new row.


