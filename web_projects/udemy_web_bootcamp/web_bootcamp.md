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

NOTE: I used a form with method="POST" in my independent implementation of the movie API exercise. I did this because I assumed I should use POST whenever you're submitting a form to a website. This assumption is false. The whole point of the form method attribute is that you can choose the appropriate method type. The general rule about when to use a POST request, in forms or elsewhere, is that when the user makes a POST request, then the resulting action on the server side is an action that changes data stored by the server, such as adding a comment to a database of comments. In the movie exercise, form method="GET" is more appropriate because the result of the form submission is simply to fetch some data from a third party and then display it, there is no change to the persistent state of the server. As shown above, when you use form method="GET", the browser automatically adds named form fields to the request URL as query params. In contrast, when form method="POST", named form fields are added to the body of the POST request in x-www-form-urlencoded format.

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

Same note as "275. Note about Serving Custom Assets" above.

### 293. YelpCamp: Layout

Added partials and bootstrap.

### 294. YelpCamp: Creating Campgrounds

POST route to add a campground.

Include body-parser.

Route to show add campground form.

Add unstyled form.

RESTful rule of thumb: A page that shows a list of data upon a GET request, if a user can add to the list, use a POST request to that same URL for doing the add to list operation.

RESTful rule of thumb: 
GET @ /listofdata // displays data on the server
POST @ /listofdata // performs an add operation to data on server, redirects to the same /listofdata
GET @ /listofdata/new // displays the form whose action is POST @ /listofdata.

### 295. Note about YelpCamp: Styling Campgrounds Lecture

* row div with an h3 that says: "Our Most Popular Campgrounds", but when he "heads back over" at 5:19 it's gone.
 
* class name btn-large to style the bootstrap button. The class name should actually be: btn-lg

### 296. YelpCamp: Styling Campgrounds

* jumbotron for main title - then make list entries a grid 

* \<header> .jumbotron // jumbotron is on the /campgrounds URL not home.
  * h1
  * p
  * p
  * btn for add
    
* div . container
* div .row
  * div .col-md-3 .col-sm-6
  * div .thumbnail + img
  * div .caption

* // test responsiveness + many images case + handling of different height images. 
* CSS 
div .row { 
  display: flex; 
  flex-wrap: wrap;
}
* .text-center

### 297. YelpCamp: Styling Nav and Forms 
* Adding Navbar then style the add new entry form.
* make form text vertically stacked.
* // NAVBAR
* nav
  * nav brand
  * login // on right side
  * sign up
  * logout
  * // test hamburger

* // FORM 

* center + vertically stack

* div .container 
* div .row
  * div style=width: 30%; margin: 0 auto;
  * div .form-group per input
  * text input + .form-control
  * button .btn-block

END.

---

# Section 29: Databases

---
 
### 298. What is a Database? 

* DB categories: SQL vs NoSQL
* Keeping your data list around in between server on/off.
* A simple text file can serve the function of a database.
* SQL interface: SELECT ALL FROM TABLE / DROP TABLE.
* NoSQL interface: db.dogs.find() db.dogs.delete(). API to db.
* NoSQL = non-relational DB. SQL = relational.

* SQL DB = relational + table-like + "flat"
  * user table. define what a user looks like. 
  * comments table.  
  * relationships between user + comments = JOIN table. = a third table which describes which user made which comment. 
  * Note user 2 made 2 comments. 

* consider a scenario in which we want to add a favColor column to the user table. Say just for user = Ira. Then we we have to assign some default favColor for all other users like “no fav color set yet”.  
* The guy calls this “not flexible”. 
* With NoSQL we are not required to stick to predefined tables. E.g JSON description of a DB.  
* Note he is calling this JSON object a NoSQL DB. This allows nesting, hence it is not flat. Note the comments is a nested array. BinaryJSON not JSON.  

  
### 299. Note about installing MongoDB

after you're up and running with mongo, be sure to **shut down your mongod server each time** you're done working. You can do this with ctrl + c.

In the Mongo Shell Basics video you'll see Colt use the show collections command which will show something called system.indexes . This will **no longer show up in the latest versions of MongoDB**. 

### 300. Installing MongoDB

MongoDB is a NoSQL DB.

MEAN Stack=Mongo Express Angular Node.
MEN=Mongo Express Node. // No angular.

https://www.mongodb.com/ = .org

`mkdir data`

`echo 'mongod --bind_ip=$IP --dbpath=data --nojournal --rest "$@" > mongod` // echos a command into a script file called "mongod"

`chmod a+x mongod` // make the script file executable.

`./mongod` // starts mongod via the script file.

`mongo` // starts mongo shell.

// my script file. --rest appears to no longer be an option.

MacBook-Air:yelpcamp darbinreyes$ cat mongod 
mongod --bind_ip=127.0.0.1 --dbpath=data --nojournal

### 301. Mongo Shell Basics

* Mongo commands.

* mongod // mongo daemon 

* mongo // shell

* help // haha

* show dbs // show database names

* use \<db_name>// set current database

* insert

* find
	* `db.foo.find()`                list objects in collection foo
	* `db.foo.find( { a : 1 } )`     list objects in foo where `a == 1`
* update

* remove

---

* Examples of using the mongo "shell".
  * use demo // <db_name>=demo set current database, if not exist, then created.

  * show dbs // show database names

  * db.dogs.insert({name: "Cartman", says: "I'm going home."})

  * show collections // see note // show collections in current database

  * db.dogs.find() // list objects in collection foo/dogs

  * // note "_id" // { "_id" : ObjectId("5e84c52d286d3bc2d4545300"), "name" : "Cartman", "says" : "I'm goin home" }

  * db.dogs.insert(... another thing...)

  * db.dogs.find({name: "Cartman"})

  * db.dog.insert(...another...)

  * db.dogs.find()

  * db.dogs.find({name:"Stan"})

* CRUD=Create Read Update Destroy
  * Create. `use demo` `db.southpark.insert({...})`
  * Read. `show collections` `db.southpark.find()` `db.southpark.find({name: ...})`
  * Update. See below.
  * Destroy. See below.

// updating

db.dog.update(selector_obj, update_info_obj) // fully overwrites obj

db.dog.update(selector_obj, update_info_obj)
update_info_obj = {$set: {name: "Kenny"}} // update only what is specified, keep the rest.

// destroy

db.dogs.remove({name: "Cartman"}) // return num removed

db.dogs.remove({name: "Cartman"}).limit(1) // only remove the first match.


### 302. Notes about Mongoose

See here for the official documentation with instructions on how to solve all **deprecation** warnings with mongoose

deprecated mongo interface functions.

.limit() syntax from previous video not correct.

you will learn about an Object Document Modeling (ODM) package for Express called **Mongoose**. More deprecated functions.

### 303. Introduction to Mongoose Pt. 1

* Interacting with mongodb within JS.

http://mongoosejs.com

* Interface from nodeJS to mongoDB. 
  * You can get by without it, like you can get by without JQuery.
  
  
* npm install mongoose

```javascript
require()

mongoose.connect("mongodb://localhost/sp");

var catSchema = new mongoose.Schema({
    name: String,
    age: Number
}); // define a schema for data


var Cat = mongoose.model("Cat", catSchema); // create a cat OBJECT + DB interface for it
```

### 304. Introduction to Mongoose Pt. 2

```javascript

// adding a new cat
    
// instantiate an instance of a cat object.
var sniffles = new Cat({ 
    name: "caca",
    age: 7
});
    

sniffles.save(function(err, cat){    
// on save done callback, err if any, + value saved and returned from the DB, this is distinct from the sniffles object. 
   if(err){
       console.log...
       console.log(err)
   } else {
       console.log...
       console.log(cat)
   }
});
    
// .find(func)
// .remove(func)
// .create(func)

```

```
// in mongo shell
show dbs
use cat_app
show collections
db.cats.find()
```


```javascript
//repeat with different values for sniffles to add more.
```

```javascript

Cat.find({}, function(err, cats) {
// on find done callback
    if(err){
       console.log...
       console.log(err)
   } else {
       console.log...
       console.log(cats)
   }
});

// create and save in one function call.

Cat.create({name: "Poo", age: 8}, function(err, cat) {
// on create done callback.
   if(err){
       console.log...
       console.log(err)
   } else {
       console.log...
       console.log(cat)
   }
});
```

END.

---

# Section 30: YelpCamp: Data Persistence

---

### 305. YelpCamp: Adding Mongoose

* style of requires.
* adding mongoose calls.
  * require
  * connect
  * Schema
  * model
  * create 
  * view in mongo shell
  * create again
  * replace uses of array with DB.
  * GET URI= /campgrounds
    * DB find // get all entries 
  * POST URI= /campgrounds
    * DB create
    
### 306. How to Avoid Potential Issues with Mongoose

* resolving e.g. deprecation warnings.
* remove({}).limit(1) doesn't work
  * ANS: db.collection.remove({}, {justOne: true})
  
### 307. YelpCamp: Campground Show Page Part 1
* RESTful routes conventions
  * index. GET /dogs  // list n entries
  * new.  GET /dogs/new // add form
  * create. POST /dogs // add action
  * show-individual. GET /dogs/:id // single entry + details
    * e.g. .get("/campgrounds/:id", ...)
      * beware of collision with /campgrounds/new, should go first.
      * Adding description to camp schema.
      * Add new camp with description. Verify in mongo shell.

* Add description field

* DB drop()
  * use yelp_camp
  * db.campgrounds.find()
  * db.campgrounds.drop()
  * db.campgrounds.find()

* add show route
  * e.g. .get("/camgrounds/:id", ...)
    * create show.ejs.
    * rename campgrounds.ejs to index.ejs.
    * in index.ejs add button "more info" as \<a>, use campground._id for :id
      * :id = req.params.id
      * DB Campground.findById(params.id, function...)
      * render("show.ejs", {camp: foundCamp})
    * update /campgrounds/new form 
      * Add description text input.

### 308. Yelp Camp: Campground Show Page Part 2

* See above.

END.

---

# Section 31: RESTful Routing

---

### 309. Intro to REST 
* 7 RESTful routes/conventions for CRUD-like implementations.

1. index   GET    /dogs          // list all entries
2. new     GET    /dogs/new      // show new entry form
3. create  POST   /dogs          // add new entry to DB. Redirect.
4. show    GET    /dogs/:id      // Show individual DB entry.
5. edit    GET    /dogs/:id/edit // Show edit form
6. update  PUT    /dogs/:id      // revise existing DB entry. Redirect.
7. destroy DELETE /dogs/:id      // remove entry from DB. Redirect.

* Blog site project.
 * "Semantic UI" instead of bootstrap. https://semantic-ui.com/
 
### 310. RESTful Blog App: INDEX 
* 1 video per restful route.
* DON'T forget "ejs" is its own npm package.
* Using 1 file for teaching but other source file organizations may be better.
* create init app.js
  * blog = title, image, body, date=now.
  * default schema values
    * .Schema( created: {type: Data, default: Date.now} )
  * GET / // redirects to /blogs
  * GET /blogs // index.ejs
  * in app.get("/blogs", ...) DB.find().
  * blogs.forEach()

### 311. Note about Blog App: Layout 
* ejs include syntax changed
* navbar spacing issue resolved later. NEW and CREATE video.

### 312. Blog App: Layout 
* add header and footer partials
* add semantic UI CDN.
  * navbar = menu
  * icon for navbar brand.
  * mkdir public/stylesheets/app.css - i.icon font-size: 2em
### 313. Note about RESTful Blog App: New and Create 
* New syntax for form name attribute.
* Now Colt will write it like this:
\<input type="text" name="blog[title]">  
What this will do is, instead of making the value for title available directly from req.body.title it will put it inside of an object, like so: req.body.blog.title 
* TL;DR: this syntax is specific to body-parser.

### 314. RESTful Blog App: NEW and CREATE 
* add app.get("/blogs/new", ...)

* new.ejs.
* just a form.


* icon becomes small again issue. - path "/" - check JS console.
  * My notes on this issue.
  * The error on the console is is not that the .css file isn't found but 
  * "Refused to apply style from 'http://localhost:3000/blogs/stylesheets/index.css' because its MIME type ('text/html') is not a supported stylesheet MIME type, and strict MIME checking is enabled."
  * I only know the fix is a change in the path because the guy said so. I also tested that placing the .css file under /public/blogs/stylesheets/index.css fixes the error.
  * The error doesn't occur on http://localhost:3000/blogs .
  * It only occurs on http://localhost:3000/blogs/new .
  * Even though both URLs render index.ejs/new.ejs which exist in the same directory. 
  * This implies that relative href paths are affected by the URL.
  * URL=localhost/blogs maps "stylesheets/index.css" to project/public/stylesheets
  * URL=localhost/blogs/new maps "stylesheets/index.css" to project/public/blogs/stylesheets
  * **Is it simply backing up by one URL node** and taking the remaining URL paths as a path into /public?
    * If yes, then URL=localhost/blogs/new/other should map to project/public/blogs/new/stylesheets/
    * ANS: Yes, that's exactly what's happening.
  * **LESSON**: 
    * "Refused to apply .css" could actually be a incorrect .css file href path in \<link>.
    * relative paths for href attributes are affected by the URL and not the path to the .ejs file.
    * With Express as your HTTP server, use absolute paths if possible, especially for .css files.

* fix navbar overlap issue. .container.main. margin.
* add \<form> action=/blogs, method=POST.
  * inputs name=blog[title]
* add app.post("/blogs",...)
  * create new blog entry
    * Blog.create(...)
  * redirect to /blogs
  * request.body.blog
* style form using semantic-ui.
  * for blog text use
    * \<textarea name="blog[body]">\</textarea>

### 315. Note about RESTful Blog App: SHOW 
* a way to shorten text with the .substring() method.
  * Blog post(s) in the database that don't have a body property. 
  * This can be fixed by removing the existing blogs
  * You can also add client side validation to the form to ensure that the body property
  
### 316. RESTful Blog App: SHOW 
* add app.get("/blogs/:id", ...);
* under blogs add links to show page.
  * after body \<a href=blogs/id>
  * Blog.findById(req.params.id, ...)
  * if err, redirect to /blogs.
  * else response.render("show.ejs")
    * header blog.title. ui hige header // see semantic-ui/item
    * image // ui centered rounded image.
    * body
    * .segment // adds border.
   * Date formating. blog.created.toDateString()
 *  allow HTML input for body.
   * Use .ejs syntax <%- blog.body %> 
     * FYI this also evaluates \<script>. Later we will use a package for "sanitizing".
     *  on /blogs page, limit body with .substring(0, 100) + "...";
### 317. RESTful Blog App: EDIT AND UPDATE 
* Edit route = add app.get("/blogs/:id/edit", ...)
  * edit.ejs
  * copy form from new.ejs.
  * h1 Edit blog.
  * form action eventually = "blog/id", method=POST for now.
  * need id
  * need pre-filled form
  * blog.findById().
  * h1 Edit blog.title
  * to prefill input value="blog.val"
    * textarea has no value attribute, insert blog.val between tags.
* Update route PUT not POST = app.PUT("/blogs/:id", ...)
  * change edit form method to PUT.
    * BUT, submitting will not work as-is, you are taken to the show page /blogs/id and the form data is plugged into the URL as query parameters. Even though we have a handler for app.put("/blogs/:id", ...). The method=PUT gets turned into method=GET+URL-form-data-in-query-params.
    * "HTML forms only support GET/POST", "no conclusive answer"
    * solution: method-override npm package. https://www.npmjs.com/package/method-override
      * method=POST, action="/blogs/id?_method=PUT",
      * npm install -g method-override
      * mo = require("method-override")
      * app.use(mo("_method"));
      * note submit now takes you to a URL with "?_method=PUT"
    * blog.findByIdAndUpdate(id, new_val_obj=req.body.blog, function(err, update_entry) ... ;
        * **Where the fuck** are the docs for mongodb methods like .findById() and the method above?
          * I didn't find it where I expected: http://mongodb.github.io/node-mongodb-native/3.4/api/index.html.
          * Googling, I found the docs are here: https://mongoosejs.com/docs/api.html#model_Model.findById
          * Why this other website for the mongodb method docs? 
          * ANS: mongodb != mongoose. oops. mongoose is an npm package that implements an interface to mongodb. They are distinct pieces of software.
      * on error, redirect to /blogs
      * on success, redirect to /blogs/id.
  
### 318. RESTful Blog App: DESTROY 
* app.delete("/blogs/:id" ...)
* form button, action=/blogs/id?_method=DELETE., 
* blog.findByIdAndRemove(req.params.id, function(err)...)
* redirect to /blogs.
* add button for edit.ejs.
* to override form default of block, use CSS "display: inline;" on form tag.

### 319. Note about RESTful Blog App: Final Touches 
* keep, don't cut, the sanitizer code from the create route.
* [Repeated note] if you get a error about the substring() method.
  * add required attribute to the textarea tag.
  
### 320. RESTful Blog App: Final Touches 
* npm install express-sanitizer.
* expreessSan = require("express...
* IMPORTANT
  * app.use(expressSanitizer()); must go AFTER app.use(bodyParser...)
* in create route, sanitize request.body.blog.thetext = request.sanitize(request.body.blog.thetext)
  * test that \<script> tags are removed.
* repeat for update route.
* Later: "middleware" = repeated code for given routes.
* unimportant semantic-ui styling.
* Add mongoose methods like blog.findByIdAndRemove() to the guy's shit table.

---

# Section 32: Data Associations

---
 
### 321. Introduction to Associations 
* e.g. a user is associated with a post. collections that are related to one another.
* a picture associated with an album.
  * 1-1 relationships
  * 1-many "
  * many-many "
* in mongoose
  * 1. embedding data to associate it.
  * 2. referencing data " " ". 
  
### 322. Embedded Data 
* create /associations/embed.js
* require(mongoose)
* connect mongoose. localhost/blog_demo
* create var userSchema { email, name }
* create var postSchema {title, content}
* Add a user to DB.
* Add a post to DB.
  * [ ] TODO: find out where in the mongoose or other docs the callback arguments are listed. Google it.
  * add "posts: [postSchema]" to userSchema.
  * move postSchema up.
  * create new user.
  * newUser.posts.push(newpost)
    * model.save it.
    * observe new entry in DB as a post object inside a nested array.
    * same as above but using model.findOne({name..}, function(err, user)...)
    * in callback on success user.post.push(another post). Save after that. Doubly nested callback.
    * observe user has 2 posts.
    
x create a user DB entry

x create a blog DB entry

x add "posts: [postSchema]" to user schema

x add a user to DB with a blog entry.

x add user to DB, upon successful create .push a post to posts array. user.save() after push.

x find a user and on successful find .push a post to posts array.  user.save() after push.

### 323. Note About Object References 
* if you get this error: TypeError: Cannot read property 'posts' of null 
* the output for referenced objects has changed in the latest versions of mongoose. 

### 324. Object References 
* association by object reference
* copy embed.js to references.js
* change mongo.connect to blog_demo2.
* posts array contains object ids instead of post objects.
* in useSchema. posts: [{ type: mongoose.Schema.Types.ObjectId, ref: "Post"}].
* create a user in DB.
* user.create() without a callback silently add user. 
* Verify new user from mongo shell. 
  * Note posts = empty array [].
* create new post in DB. postSchema  and .model from previous video is still declared above userSchema + model.
* Next: connecting posts with id's.
  * create new post object again, doubly nested callback, findOne(someuser, callback on success, foundUser.posts.push(postjustcreated);
  * tripple nested callback, save user with newly added post.
  * note the user object now has an id inside the posts array, even though we pushed a full post object.
* Next: retrieving full post object from posts id array.
* user.findOne({userfilter}).populate("posts").exec(function(err user){//print user on success.});
  * observe printed user now has full posts objects.
* When to use which type of associations. ANS: It depends on the application. Will see examples in YelpCamp.

* IMPORTANT - See subparprogrammer/web/udemy_web_bootcamp/backend/yelpcamp/Associations/referenced/references.js.
  * `const Blog = mongoose.model("Blog", blogSchema);`
  * `posts: [{type: mongoose.Schema.Types.ObjectId, ref: "Blog"}]` // IMPORTANT! The value of key=ref here should === value of first argument to `.model("Blog", blogSchema)` above, otherwise, see below, `.populate("posts").exec()` will error out.

### 325. Module.exports 
* cleaning up previous files using module.exports.
  * e.g. multiple files using 1 user model.
* references.js
* move post model to mkdir models. touch models/post.js, models/user.js
  * require mongoos again.
* syntax: module.exports = mongoose.model(Post, postSchema);
* references.js
  * var Post = require("./models/post"); // note "./" in path.
* repeat above for user.js.
* Test by creating another post.
* // analogous to C includes.

---

# Section 33: YelpCamp: Comments

---

### 326. YelpCamp: Refactoring App.js 
* move campgroundSchema to models/camground.js
* modules.exports above.
* require("./models/campground")

### 327. Note about Seeding the Database 
* MongoDB and Mongoose have both been updated with breaking changes recently.

* seed.js . remove all campgrounds and comments. Add 3 campgrounds each with 1 identical comment.

* If you run into the Cannot read property 'name' of null  error

### 328. YelpCamp: Seeding the Database 
* create seed.js
* require campground.js
* delete all, Campground.remove({}, function(err))
* in app.js, seedDB = require("./seeds");
  * export seedDB function.
* Add a few campgrounds.
  * create an array to add. 3 campgrounds.
  * add using data.forEach()
  * nest forEach in callback.
  * nest add same comment to each campground
    * Comment model doesn't exist yet.
      * text,
      * author
      * upon successful create comment, push() associated comment.
      * save with comment.
  * add Comment = require("./models/comment")
  
### 329. Note about comment model lecture 
* error: TypeError: Cannot read property 'push' of undefined
* will use reference to the comment model within campground model. 

### 330. YelpCamp: Comment Model 
* finish seeds.js
* display comments on show page.
* touch models/comments.js
  * create and export comments model.
* inspect in mongo shell
  * db.campgrounds
  * db.comments 
* add object id reference to comments.
  * commens: [{type: mongoose.Schema.Types.ObjectId, ref: "Comment"}]
* rename mongoose connect to "_v3"
  * confirm comments id refs added.
* SHOW page- in app.get("/campgrounds/:id", ...)
  * populate("comments").exec(functions(err, foundCampground) comments on campground being shown. 
  * show.ejs
    * loop through comments.
    
### 331. Note about Comments Lecture 
* New MongoDB version. May need to update.

### 332. YelpCamp: Creating Comments Pt. 1 
* comment - nested route.
  * NEW - /camgrounds/:id/comments/new GET
  * CREATE - /campgrounds/:id/comments POST
* app.get("/campgrounds/:id/comments/new", ...)
  * mkdir views/comments
  * mkdir views/campgrounds
  * move files.
  * touch views/comments/new.ejs
  * update paths to response.render("comments/new.ejs").
  * landing.ejs unmoved.
  * update partials paths. "../partials/header.ejs"
  * copy existing new.ejs code to comments/new.ejs.
    * h1 - Add new comment to campground.name
    * form action=/campgrounds/:id/comments method=POST
    * Campground.findById(req.params.id,
    * can't just refresh, seed generates new Id's.
    * update form inputs. name=comment[text], comment[author]
* app.post("/campgrounds/:id/comments", ...)
  * lookup campground, create new comment, connect comment, redirect to campground show page.
  * request.body.comment 
  * Comment.create(..., function...)
  * campgrounds.comment.push(new_comment);
  * campgrounds.save(); // no call back.
  * response.redirect(/campgrounds/id)
  * require comment.js
  * test new comment
  * add comment button - a inside of a p. - /campgrounds/id/comments/new.
    
### 333. YelpCamp: Creating Comments Pt. 2 
See above.

### 334. YelpCamp: Styling Comments Pt 1 
* Styling show page.
* 3 col, 9 col
* mkdir v5.
* div container
* sidebar
  * row 
  * col-md-3
  * list items -  list-group - info 1-active 2 3. 
  * col-md-9
  * price = 9$ / night - hard code.
  * campground.name link to nowhere
  * long description.
  * same column as thumnail - comments. class=well. gray background.
  * leave review button.
  * loop through comments 1 per div.row.
  * comment author -  "10 days ago" span pull-right
  * comment text in \<p>
  * hr under button.
  * bold author
  * make image take up wdith=100% - use chrome inspector
  * padding 0
  * padding around content under image.
  
### 335. Note about YelpCamp: Styling Comments Pt 2 
* guy uses custom CSS for something bootstrap has a class for. .caption-full vs .caption.

### 336. YelpCamp: Styling Comments Pt 2 
* mkdir public
* mkdir public/stylesheets/
  * touch main.css
  * app.use(express.static("public")); // Tell express where to look for CSS files.
  * vs
  * app.use(express.static(__dirname +"/public")); // __dirname = directory that this script was run in.
      * href="/stylesheets/main.css"
  * absolute path is "safer"
  * link stylesheet main.css in partial/header.
  * .thumbnail img w=100%
  * .thumbnail padding 0.
  * .thumbnail .caption-full padding 9px
  
---

# Section 34: Authentication

---
 
### 337. Note about authentication section 
*  pay special attention to the order in which Colt includes various lines of code 
*  if you're wondering what happened to the "Auth From Scratch" lectures, Colt opted not to make them because of potential security risks.
*  However, [this video] dives pretty deep into the inner workings of authentication.

### 338. Introduction to Authentication 
* passportjs.org
  * search for strategies.
  * passport-local, another package/strategy.
* passport-local-mongoose, another package.
* project
    * secret page
    * login
    * staying logged in
        * sessions
        * allow us to add state
        * package express-session 

### 339. Secret Page Code Along Pt. 1 
* mkdir Authentication/AuthDemo,
* npm init.
* install
  * express, mongoose
  * passport, passport-local, passport-local-mongoose
  * body-parser, express-session
* mkdir views, models (will be user only)
* require(express)
* npm install ejs
* app.get("/") render(home.ejs)
* touch views/home.ejs
* app.listen(...).
* test home page.
* app.get(/secret, ... ) , render(secret.ejs)
* touch view/secret.ejs , add img, etc, for secret page.
* test secret page.
* require(mongoose), connect(localhost/auth_demo_app)

### 340. Secret Page Code Along Pt. 2

* require(passport, body-parser,
* LocalStrategy = require(passport-local)
* passportLocalMongoose = require(passport-local-mongoose)
* test requires()
* touch models/user.js
  * require(mongoose)
  * UserSchema = new mongoose.Schema({username, password})
  * exports = mongoose.model("User", UserSchema)
  * test require in app.js
    * User = require(./models/user)
  * passportLocalMongoose = require(passport-local-mongoose)
  * UserSchema.plugin(passportLocalMongoose) // just before exports.
* app.js
  * app.use(passport.initialize()) // tell express to use passport.
  * app.use(passport.session())
  * app.use(require("express-session")( // tell express to use express-session // note inline require()
    * {secret: "Rusty is a cunt", // can be "anything", used to encode and decode sessions.
       resave: false, 
       saveUninitialized: false}
    * )); // call above initialize()
  * // after use.(session() // tell user what methods to use for encoding and decoding sessions.
  * passport.serializeUser(User.serialzeUser()); // "plugin" adds this method to User. 
  * passport.deserializeUser(User.deserializeUser());
  * // after this, come the app.get(/,...)

### 341. Secret Page Code Along Pt. 3 
* GET @ /register
  * shows sign up form.
  * form POSTs @ /register
  * response.render(register.ejs)
  * touch register.ejs.
    * form
    * input type = text, name = username
    * input type = password, name = password
    * submit button
    * action=/register method=POST
 * app.post(/register, ...)
   * app.use(bodyParser.urlencoded({extended: true})
   * req.body.username
   * .password
   * User.register(
     * new User({username: req.body.username}), // note password not included here but below
     * req.body.password, // will be hashed behind the scenes, not stored in plain text.
     * function(err, user){ // new user with all data
     * if err, render(register.ejs)
     * else passport.authenticate("local", req, res, function({
     * redirect("/secret")} // log user in. local|twitter strategy.
     * });
     * test login takes you to /secret
     * mongo shell,
     * db.users.find() // note object has hash and salt
     * add link to signed up page in home page. li+a tag, href=/register
   
### 342. Secret Page Code Along Pt. 4 
* touch views/login.ejs
  * form
  * input type=text, name=username
  * type=password, name=password
  * submit button.
  * action=/login, method=POST
* app.js

```javascript
// middleware = code that runs  before our final route callback. Can be "stacked up".
app.post("/login", 
passport.authenticate("local", // does the login operation
{successRedirect: "/secret", 
failureRedirect: "/login"}), function(req, res){

});

passport.use(new LocalStrategy(User.authenticate())); // before passport.serializeUser(..)
``` 
  
 * Test login redirects .
 
### 343. Secret Page Code Along Pt. 5 
* in home.ejs add link to href=/logout
* add 3 links to all pages. sign-up, login, logout
* app.get(/logout, ...)
  * req.logout();
  * redirect(/)
  * // that's it.
  * test redirect to home.
* // actually hiding the /secret page = middleware.

```javascript

function isLoggedIn(req, res, next) { // next = next thing that needs to be called
    if(req.isAuthenticated() { // if logged in successfully
        return next(); // "move on to the next middleware"
    }
    // else, login failed.
    res.redirect("/login");
}
// update app.get("/secret",..)
app.get("/secret", isLoggedIn, function(req, res){
    render("/secret"); // only executes if user logged in successfully.
});
```

* test login with new user.
* test access to secret after logout.

* In the next section we will use the user login/out for more than just placing pages behind a "wall", we will associate data with users. E.g. User comments.
END.

---

# Section 35: YelpCamp: Adding Authentication

---

### 345. YelpCamp: Adding Auth Pt. 1

* install
  * passport
  * passport-local
  * passport-local-mongoose
  * express-session
* app.js
* require(passport, passport-local
* User = require(./models/user
* touch models/user.js
  * require(mongoose
  * UserSchema = new mongoose.Schema(... // same as AuthDemo
  * test user require.
  * require(passport-local-mongoose
  * plugin(passportLocalMongoose
  * test 

### 346. YelpCamp: Adding Auth Pt. 2

* // passport config
  * app.use(require(express-session)({secret: "ccaca", // Same as AuthDemo
  * app.use(pass.init()
  * app.use(pass.session()
  * passport.use(new LocalStra(User.auth()
  * passport.serial(User.serial()
  * passport.deserial(User.deserial()
* // auth routes
  * app.get("/register" ... ) res.render(register.ejs)// show reg. form
  * form action=/register method=POST
    * inputs - same as AuthDemo.
  * app.post("/register", ...)  // sign up logic
    * User.register() 
      * if err, return res.render(register.ejs)
      * inside passport.auth() redirect to /campgrounds.
      * check user in mongo shell.
      
### 347. YelpCamp: Adding Auth Pt. 3

* app.get("/login", ...) // show login form
* touch views/login.ejs
  * submit value=Login!
* same as /register but with action=/login method=POST 
* app.post("/login", ...) // try to login the user
  * add in middleware
    * passport.authenticate
    * successRedirect: /campgrounds
    * failure: /login, 
    * express callback does nothing.
    * test login redirect.

### 348. YelpCamp: Adding Auth Pt. 4

* app.get(/logout, ...) // logout a user
  * req.logout()
  * redirect(/campgrounds)
* header.ejs
  * Update navbar links
* add header.ejs+footer.ejs to new routes. - adjust include paths relative to login.ejs+register.ejs..

* // logic to prevent user from adding comment if not logged in.
  * if loggedin - show comment form else show login form
  * add isLoggedIn() middleware
  * if(req.isAuth()) return next() // shows comment form
  * ellse redirect(/login
  * add middddleware to app.get(..comment)
  * test comment addition redirect.
  * also want to protect app.post(/camp/comments // add isLoggedIn() arg. // protects POSTman style "attack", all we did was hide the form.
  * test add comment again

### 349. YelpCamp: Adding Auth Pt. 5

* navbar show/hide logic
* if not signed in - login/signup
* if yes, logout - also show username "signed in as Joe"
* header.ejs.
* pass user variable to header.ejs.
* app.get(/campgrounds
  * req.user // has the user info // undef. if not logged
  * pass it to render()
  * index.ejs -  test h4 with current user.
* header.ejs - add if statement - if !currentUser only see login and signup.
* quick way of paasing the user var to all routes.
  * under passport.deserial().
  * app.use(function(req, res, next) // "our own little middleware" // { res.locals.**currentUser** = req.user; next();}); // res.locals makes things available to .ejs
  * test nav links ok on other routes besides /campgrounds.
* // add currently signed in as.
  * header.ejs
  * li - a href=# - Signed In As <%= currentUser.username
  * test comment
  
END.

---

# Section 36: YelpCamp: Cleaning Up

---

### 350. YelpCamp: Refactoring Routes

* groups of routes.
  * auth routes
  * comment routes
  * campground routes
* 3 different routes then require them.

* mkdir routes
* touch routes/campgrounds.js // comments.js // index.js

* campground routes
* x get /campgrounds, post /campgrounds, get campgrounds/new, get /campgrounds/:id,  

* comment routes
* x get /campgrounds/:id/comments/new , post /campgrounds/:id/comments

* x get /, + auth routes, get /register, post /register,  get /login, post /login, get /logout, function isLoggedIn() // note isLoggedIn() is also referenced in the comments route.

* x instead of using `var app = express()` we use the "express router"
  * var express = require(expresss
  * var router = express.Router();
  * app.get replaced by router.get
  * module.exports = router.
  
* x in app.js
  * commentRoutes = require("./routes/comments");
  * campgroundRoutes = require("./routes/campgrounds");
  * indexRoutes = require("./routes/index");
  * under app.use(... res.locals... next();
    * app.use(commentRoutes);
    * ... others
    
* x adding in the models to comments.js
  *  Comment = require("../models/comment");
  * isLoggedIn(), cp to from index.js into commments.js
  * in index.js, require(passport). require User model.
  
* x test that routes still work.

* in app.js, 
  * app.use(indexRoutes) etc.
  * app.use(campgroundRoutes) replaced by app.use("/campgrounds",campgroundRoutes) then in campgrounds.js remove string /campgrounds 
  * app.use("/", indexRoutes)
  * app.use("/campgrounds/:id/comments", commentRoutes)
  * x test add comment - fix error - error related to id route param - fix = var router = express.Router({mergeParams: true});
  * add comments to code in broken out routes.

---
  
* MY FYI: How to run scripts defined in your package.json file. 
  * `npm run test2` where "test2" is defined by:

```JSON
"scripts": {
    "test": "echo \"Error: no test specified\" && exit 1",
    "test2": "echo \"caca\""
  },
```
  
* My FYI: How to set up Javascript error checking like Cloud9 IDE, in which lines containing e.g. an unused var or non-existing var. are marked, hence saving debugging time, fix errors before you run you code.
* https://packagecontrol.io/packages/JavaScript%20Enhancements
* I tried this subl package but hit errors upon creating a "JS project". Also there this a dependency on a "dead" package, TerminalView. The is a dependency on "flow". Seems to provide the features I want but not integrated into subl.
  * Flow: https://flow.org/    

#### Flow initial setup notes. Do this on a per project basis.
* https://flow.org/en/docs/install/
* `npm install --save-dev @babel/core @babel/cli @babel/preset-flow`
* `touch .babelrc`
*  add to .babelrc, the following

```JSON
{
  "presets": ["@babel/preset-flow"]
}
```

* With source files in /src dir. run `./node_modules/.bin/babel src/ -d lib/`
* Add to your package.json:

```json
"scripts": {
    "build": "babel src/ -d lib/",
    "prepublish": "npm run build"
  }
```
* `npm run build` is now equivalent to `./node_modules/.bin/babel src/ -d lib/`
* run `npm install --save-dev flow-bin`
* Add to your package.JSON:

```json
  "scripts": {
    "flow": "flow"
  }
```
* If this is the first use of flow run `npm run flow init`, this creates a .flowconfig file.
* Finally run, `npm run flow`.
* Now you are ready to use flow.

---
 
#### Using flow to check your JS for errors. 

* https://flow.org/en/docs/usage/
* With the above completed, and assuming your code is in /src.
* run `npm run flow status`, this start a background process that does the JS error checking. If already running, this will check your JS code.
* `npm run flow stop` to terminate the process.
* You must mark any JS code you want flow to check with `// @flow` as the first comment.
* "Write flow code". // See below on for what is flow code

```javascript
// @flow
// This is "Flow code". It seems to be JS with type annotations. Here the error is supposed to be that the return type is specified as string but the function sometimes returns a int/number.
function foo(x: ?number): string {
  if (x) {
    return x;
  }
  return "default string";
}

```
* Check your code with `npm run flow`. For the above example the output would be:

```
test.js:5
  5:     return x;
                ^ number. This type is incompatible with the expected return type of
  3: function foo(x: ?number): string {
                               ^^^^^^ string
```

* If you run `npm run build` then the JS files in src/ will be output but without the flow type annotations.
* Remark: JS was designed to be very loose with types but evidently, if you want error free code you end up using a tool like flow for enforcing strict typing. Why not just start with a strictly typed language to begin with.

#### More on using flow

* https://flow.org/en/docs/types/
* flow can be useful without type annotations since it can infer types from your code. But sometimes type annotations are necessary. e.g. "But suppose you only want to allow strings in your function."
* https://flow.org/en/docs/lang/
* When you run `npm run flow` flow appears to be searching in all subdirs.
* In "setup compiler" babel is a compiler with support for stripping out flow type annotations. The initial contents of the .babelrc file seem to be just for telling babel to do expect flow type annotations. After running `npm run build` I now see all the sub-dirs under src/ also occurring in lib/. Maybe now flow will resolve commentRoutes? ANS: No. Apparently flow is indeed checking that the file require("./routes/comments"); exists, because when I remove the "./" it generates an additional error "Cannot resolve **module** routes/comments." after "Cannot resolve **name** commentRoutes." 
* OK, I understand now, the "resolve **name**" error means flow wants me to prefix "var" to the variable name "commentRoutes", this is reasonable, it's like an undeclared identifier compiler error in C.

```text
MacBook-Air:yelpcampv7 darbinreyes$ npm run flow

> yelpcampv1@1.0.0 flow /Users/darbinreyes/dev/private_dev/subparprogrammer/web/udemy_web_bootcamp/backend/yelpcamp/yelpcampv7
> flow

No errors!
```

* I added @flow to routes/comments.js, is flow really checking it? If yes, adding an error in that file will cause flow to report it. ANS: Yes. Also, if I add an error routes/campgrounds.js, which does not have @flow, then I should not get a flow error reported since flow shouldn't be checking that file. ANS: this if is True.

---

* My FYI: Here's the docs for what goes in your package.JSON file. https://docs.npmjs.com/configuring-npm/package-json

---
* Moving yelpcampv7 files under src/
* nodemon works with main=src/app.js but hit error:
```
Error: Failed to lookup view "landing.ejs" in views directory "/Users/darbinreyes/dev/private_dev/subparprogrammer/web/udemy_web_bootcamp/backend/yelpcamp/yelpcampv7/views" 
```
* Notice the expected path = yelpcampv7/views
* So it seems the path is relative to where the app was started from.
* Fix: `cd src/` `nodemon app.js`

---

* getting rid of global installations of npm packages since per project node_module directories seems to be the standard practice with nodeJS development, I can simply use a .gitignore to avoid clutter and space usage in my git repo.

---

* My FYI: the new comment form error fixed by "express.Router({mergeParams: true});" has to do with the fact that without this special argument the ":id" route parameter is not passed to `comments.js->router.get("/new"...`, hence `exp_request.params.id` remains undefined, causing findbyId() to fail, and ultimately new.ejs to fail when we run `<h1>Add a new comment to: <%= entry.name %></h1>`. `entry` is undefined so we hit `Cannot read property 'name' of null`.

### 351. YelpCamp: User Associations: Comment

* Change to be done in this section = When a new comment is created, we automatically set the author form input instead of the user typing in an arbitrary name.
* Plan: On the comment model, add some fields // my first thought was, setting the form input within the new comment .ejs, looks like we are doing something different.
* x in models/comment.js replace `author: String` with `: {id:, username:}` where id = the "_id" member of the associated user in db.users.find(), similarly for "username". The guy makes a remark about how the fact that we are using a non-relational database makes it much easier to edit models in this way. I think this is called an association - YES, correct assoc. by reference.

```javascript
// in models/comment.js
text: String,
author: {
  id: {
    type: mongoose.Schema.Types.ObjectId,
    ref: "User"
  },
  username: String
}
```

* x in seedDB.js comment out everything being done except the remove() all DB entries since that code does not take into account our modified comment model.
* x uncomment out the above, then comment out call to seedDB() in app.js so that the DB remains empty.
* x in `routes/comments.js`, modify `router.post("/", isLoggedIn, ...` . Recall that this is the route that creates a new comment. First it finds the DB entry to which the comment is being added, then appends (push()) the comment to the DB entry.
  * x Before push, add username + id to comment. // id= id of User DB entry. 
  * x // I expect id in exp_request.user._id, and username in exp_request.user.username // created_comment.author.id = exp_request.user._id, created_comment.author.username = exp_request.user.username. // expectation CORRECT.
  * x Remove author field from new comment .ejs.
  * x Test adding a new comment. Observe that the user name for the comment is a big object - instead of a string type for the author, we made author an object - we need to modify the .ejs to account for our changes above // expect author.username. - show.ejs for a campground

### 352. YelpCamp: User Associations: Campground 
* Analogous changes to previous section but for campgrounds. i.e. associating users with campgrounds that are created via the campground form. You can't submit a new campground unless you are signed in. // expect adding isLoggedIn() to campground routes. // Also want to save username+id with a campground DB entry - again, analogous to the comments related changes in previous section. Later these changes will be used in controlling who can delete and update campgrounds. Similarly, later, for delete and update of comments.
* x Prevent not logged in user from creating a campground // expect isLoggedIn() middleware added to create campground form and post campground route.
* x test add new campground is protected. 
* x associating logged in user with campground.
* x campground model - add author like in previous section.
* x again - update save() code for campground analogously to previous section. - don't forget to resave() to DB afterwards, if necessary.
```
// "cleaner" way of setting author in new campground.
var author = {id:, username:}
newcampground.author = author;
// don't forget to save. if necessary.
```
* x test new campground - created -
* x display author in campground show .ejs page. - under description element. - "submitted by ..."

END.

---

# Section 37: YelpCamp: Update and Destroy

---

### 353. Intro to New YelpCamp Features

* delete and update campgrounds and comments
* User authori
* message successfully signed in. - flash message - goes away on refresh
* adding update delete buttons - only if user is aowns the post..


// green flash message 


// don’t show delete/update buttons unless user=owner / creator of camp ground. 


// note orange edit campground button - because user = campground creator. 


// Edit a campground form - note form header + update button. 


// landing page - add change bg image every 5 seconds.+ fade effect. 

// v10 - contains 4 campgrounds to begin with.

// Plan - implement update/delete without regard to current logged in user , 2nd add user auth for those features.

### 354. Campground Edit and Update

* Add the edit button to the campground show page. // expect we will create views/campgrounds/edit.ejs file, with route = GET @ /campgrounnds/:id/edit, use form nearly identical to the new , form will probably do a PUT request @ /campgrounds/:id. Similarly we will use a DELETE @ campgrounds/:id to delete a campground. Expect to use require('method-override'); and possibly require("express-sanitizer");.

* REST table review
* edit /dogs/:id/edit - GET
* update /dogs/:id - PUT
* remove /dogs/:id - DELETE

* require(method override)
* app.use(methover(_method
* add app.get(:id/edit, function

* use CSS id selector to make delete button display: inline.
* next we will prevent users from deleting or editing posts unless they created that post. // expect only display buttons if user is logged-in AND currently logged in user is the same as the owner/author. // changes to campgrounds show.ejs.

### 355. Campground Destroy

* // figured this out on my own.

### 356. Notes about Campground Destroy & Campground Authorization

* note on the fact that we didn't delete associated comments along with the campground entry.
* author comparison with logged in user involves .equals() method.

### 357. Campground Authorization Part 1

* authentication (previously covered) = verify someone is who they say they are.
* vs. authorization = permissions.
* - you can't view the edit form unless you own the campground.
* in edit campground route, if user logged in, is the current user == author, if not redirect, if not logged in redirect.
* if(req.isAuthenticated()) - findbyid callback, on success, foundcamp.author.id.equals(req.user._id) // because author.id is actually an object. if permission, render.edit.ejs. else send(not author) // will he pass args to middleware? or return from middle ware inside campground. checkCampgroundOwnership(). - if not logged in redirect(back) - if author check passes - instead of render edit.ejs, call next() - not return next(); - else redirect(back) -- add new middleware // clearly the call to next() will not return control to the caller. 
* test new campground edit functionality.

### 358. Campground Authorization Part 2

* protect remaining route handlers with middleware - hide buttons if not logged in as owner.

### 359. Comment Edit and Update
* // expect add routes to update and delete comments.
* // add buttons to do update and delete comment.
* // add middleware to protect update and delete unless logged in as owner.

* // next: only allow comment edit ad delete if logged in as author of the comment.
* // only show comment edit and delete buttons for comments owned by currently logged in user.

### 360. Note about Comment Destroy lecture

* "He actually uses this id twice, once on line 24 and again on line 46, which breaks the rule where you're only supposed to use id's once per HTML document."

### 361. Comment Destroy
### 362. Comment Authorization

* Refactor middleware to its own file. 
END.

---

# Section 38: YelpCamp: UI Improvements

---
 
### 363. Refactoring Middleware 
* mkdir v10/middleware, touch index.js - name explained later.
* module.exports = middlewareObj
* Obj.checkCampgroundOwnership = function ....
* cp isLoggedIn() etc. into this file.
* add requires to files that use these function
* if you require a dir, index.js is the default name , index.js is special name.
* update routes/ campground.js, comments.js
* check need requires in middleware/index.js

### 364. Flash Messages: Installation 
* user messages using connect-flash package.
* you logged in, you logged out, user already exists, your don't have permission to do that, you must be signed in.
* mkdir v11.
* Beware of outdated docs on connect-flash.
* npm install connect-flash.
* flash = require
* tell express to use it, app.use(flash())
* usage, e.g. in isLoggedIn(), req.flash("success", "Login first sir"); before redir(/login)
* in get(/login ... pass to render {message: req.flash("error")}

### 365. Note about Flash Messages 
* small bug where you have to click the register button twice to see the flash message.
* be sure that the following line: app.use(flash());  comes before your passport configuration in app.js

### 366. Flash Messages: Adding Bootstrap 
### 367. Flash Messages: Helpful Errors 
### 368. Note about error handling

*  issue with our app in production. The show and edit routes aren't handling errors properly so the application can crash under certain circumstances. //  probably the case of invalid ids in the URL params. 

### 369. Landing Page Refactor - Part One 
* copy given html on github - https://github.com/nax3t/background-slider
* using bootstrap 3.3.5
* create landing.css
* CDN modernizer. - checks browser name+ version - add classes to keep things looking good on old browsers. - cross browser compat.
 
### 370. Landing Page Refactor - Part Two 

* z-index = 1 - position must be = relative for z-index to take effect. static= default position. text-align=center for horiz. align. vertical align - padding top 40vh, vh = view height. I assume 40 must be a percentage . z-index = 1 here since we want the landing text to be on top of the bg images.
* list-style = none - hides the list bullet points.
* no-cssanim CSS class - if old browser - don't animate , just show a single bg image.
* Note use of async for modernizer CDN. script load simultaneously with other assets on the page. Probably a fix for something in case of load on old browser.

### 371. Dynamic Price Feature 
* I already did this.

### 372. Note about further YelpCamp improvements 
* A dozen new features in the form of separate tutorials.

* x center the landing page header. -
* FYI. 1vh = 1% of viewport height. in JS console window.innerHeight prints the viewport height.
* Try using bootstrap 4 carousel component.
  * https://getbootstrap.com/docs/4.5/components/carousel/
  * from the start it tells you images are not automatically sized, you need to use utils or custom css for that.

#### Figuring out how to use bootstrap 4 carousel to reproduce web course version.

* start with course version - esp use their images, note image sizes, are they equal size?.is it responsive? how does it look on iphone ? The images should be such that they look good when they cover the entire page and centered. so you need to create images to have this visual property. Perhaps need to use photoshop .

* // do below after course deploy section

* Test course version, how it looks with my images.

* lookup how to measure pixel distances in chrome. also how to set crop size in preview.

* do not waste time on trial an error, determine how image will look on different size view ports and then after that figure out the CSS/bootstrap4. start with iPhone viewport. how can it look good on iphone and large external screen?

* download given images. use for testing.

* lookup img element height width attributes. test effect.

* using css background image , set desired  position and perhaps scaling.
  
* its hard to imagine a bg image that would look good on both iphone and a big screen. Maybe an image with central region looks good and just center it on all view ports assuming it is large enough. Note the course's version uses black bg and black border images. You can use preview or gimp to add text and a button shape to see how things look without any CSS trial and error. 
  * The course images are all of different sizes, so identical image sizes is not the cause of my failed recreation. I plugged in my images and they look fine on mobile view ports but not good on external monitor full screen, therefore you do have to be careful about images you use. At least now I have a reference for how the bg image should look.
  * The course slideshow also is very responsive. Again, the images you choose for the slideshow need to be tested on the different screen sizes.
  
END.

---

# Section 39: Git and Github

---
 373. Intro To Git
374. Git Init, Add, and Commit
375. Git Log and Checkout	 376. Note about Git lectures 

* Skipped. I already know how to use git. 

END.

---

# Section 40: Deploying

---
 
### 377. Intro to Deploying and Heroku 
* deploying express app.
* moving app to own server.
* adding new features - separation of current version and dev version.
* heroku - hosting company - free plan.
* 
### 378. Deploying a Simple App Part 1 
* Should I deploy my version of yelpcamp? - conflict with apache? 
### 379. Note about Heroku CLI	

* `heroku login -i`
* i = interactive. 
### 380. Deploying a Simple App Part 2 
* heroku.com - sign up for free.
* heroku "toolbelt" is pre-installed on cloud9.
* in cloud9 - `heroku login`
* create a local git repo. in project dir. `git init` `git add ...`
* click - I cloned the app.
* in cloud9 `heroku create`. this generates a random name and prints URLs ......com + .....git // deploy URL + deploy git.  - also adds remote to local git repo. for fetch+push. See `git remote  -v`. name of remote = heroku. (where usually we see origin).
* `git push heroku master` - lots of prints related to heroku - remember you are pushing to heroku, not github.com.
* "debugging heroku" - .com - application error. - check your logs - `heroku logs` - "missing command script "start""
* every time you push to heroku it initializes your app environ. add start script , git commit, git push heroku master.
* View app on heroku dashboard.
* deploying app with mongo DB - little harder. 
### 381. Deploying YelpCamp: Basics 
* initial steps to deploy yelpcamp are same as for simple app above.
* `heroku run ls` - runs ls on current heroku "container".
* `heroku run npm install ...` also works. 
### 382. Note about MongoLab 
* mLab (mongolab) is now MongoDB Atlas, please see ...
* see how Colt adds the mongolab url to the app
* you can ignore the other steps regarding mongolab and supplement them with the instructions linked above. 
### 383. Deploying YelpCamp: MongoLab 
* 1 solution - host mongo somewhere outside of cloud9. 
  * http://mongolab.com // dead
  * https://www.mongodb.com/cloud/atlas/lp/try2?utm_source=bing&utm_campaign=bs_americas_united%20states_search_brand_atlas_desktop&utm_term=mongo&utm_medium=cpc_paid_search&utm_ad=e&msclkid=4b6da8995776119af0e7f624d1d261f1
* harder but possible - run mongodb on heroku.
* create free mongolab account - copy `mongodb://...` URL
* insert in mongoose.connect(".....",)// dbuser, dbpassword) // colt:rusty@xxxx.mongolab.com:3333/yelpcamp
* create mongolab db user.
* he tests this in cloud9 first. - note db initially empty.
* in mongolab - see collections and data.
* note - dont use same DB for deploy and dev.
* confirm deployed app can connect to mongolab DB on heroku. 
### 384. Environment Variables 
* problem - dev code and deployed code are using the same DB. e.g. what if you want to test deleting a DB entry.
* 1 solution - comment out deploy db, use local mongo db. - problem - requires you re-comment before `git push heroku -- `
* solution - use env var to control which DB is used. - e.g. process.env.PORT. 
* in node process.env is the standard place for env variables.
* create e.g. process.env.DATABASEURL - export DATABASEURL="......"
* in heroku GUI - add env. VAR. - also possible with heroku toolbelt
* nice to have - default mongo db URL.

---

# Section 41: JavaScript: The Tricky Stuff

---
 
### 385. Keyword This 1 - Introduction and Global

* this
* determined by exec. context - 4 rules
 * global
 * object/implicit
 * explicit
 * new
 
* global context
 * in browser - global context, this is a reference to a window object
 * by default every var declared is attached to the global object.
 
 ```
 //#0
 // in browser window exists as a global var.
 var person = "caca" // == window.person
 
 ```

* outside of an object this references some default global var.

### 386. Keyword This 2 - Global With Strict 
* this, inside of a function.

```
var data = {}; // declares an object
data.poo = "caca" // adds key=poo, value="caca" to empty object.

///

this.cartman
undefined

var cartman = "eric"
undefined

this.cartman
"eric"

```

* inside of a function, this refers to the global this.
* adding members to the global object makes them accessible as local variables in the global scope, i.e. the inverse of  //#0 above holds.

```
this.poo
undefined

function donothing() { this.poo = "ca";}
undefined

this.poo
undefined

donothing()
undefined

this.poo
"ca"

```
* PITFALL: variables declared inside of a function are only local to the function if the keyword var is used, otherwise that variable is placed in the global scope.

```
// other
undefined

this.kyle
undefined

function donothing() { var mrhankey = "caca"; kyle = "b";}
undefined
mrhankey // local to function
VM3573:1 Uncaught ReferenceError: mrhankey is not defined
    at <anonymous>:1:1
(anonymous) @ VM3573:1

kyle
VM3628:1 Uncaught ReferenceError: kyle is not defined
    at <anonymous>:1:1
(anonymous) @ VM3628:1

donothing()
undefined

mrhankey
VM3683:1 Uncaught ReferenceError: mrhankey is not defined
    at <anonymous>:1:1
(anonymous) @ VM3683:1

kyle
"b"

this.kyle
"b"

window.kyle
"b"
```

* Since this is clearly a PITFALL - Javascript has a feature call "strict mode". To enable add "use strict" at top of source file. The result is that inside of a function this no longer refers to the global object, it remains undefined.

* The behaviour in nodeJS is a bit different.

```
// IN NODEJS

// strict off
function donothing() {
  console.log("this = " + this);
  mrhankey = "poo";
}

// "this = [object global]" != window like in browser
// calling donothing(), does NOT place mrhankey in this.mrhankey, but mrhankey now exists in the global scope.

// strict on
// "this = undefined"
// calling donothing(), and will cause app to crash with error "ReferenceError: mrhankey is not defined"


```

### 387. Keyword This 3 - Implicit	 
* 2nd rule
* this, inside of a declared object.
* refers to the "closest parent object" context.

* nested objects.
* ex. "Hi Colt", true, "Hello undefined", false.

### 388. Keyword This 4 - Call Apply Bind 
* Nested object continued.
* ? UNEXPECTED - these rules are not part of the JS spec. // I think he is referring to his 4 rules.
* explicit setting of this.
* 3rd rule - explicit - call, apply, bind. "can only be used by functions.
* method - `call`(thisArg, a, b, c ...) - imm. invoke. - thisArg = what we want `this` to be.
* method - `apply`(thisArg, [a, b, c ...]) - imm. invoke. - only 2 args. - thisArg = what we want `this` to be.
* method - `bind`(thisArg, a, b, c ...) - NOT imm. invoke. - thisArg = what we want `this` to be. - Returns "a function definition".

### 389. Keyword This 5 - Fixing Our Issue With Call 
* ex. `person.dog.sayHello()` vs. `person.dog.sayHello.call(person)`, `person.dog.determineContext.call(person)`. Notice that call is a method of the method we defined in our object.
* Use case - avoid code duplication.
* ex. `colt.sayHi()` vs. `colt.sayHi.call({firstName: "Ellie"})` 

### 390. Keyword This 6 - Apply 
 * call and apply work the same if the only arg is the thisArg.
* ex. `colt.addNumbers.call({firstName: "Ellie"}, 1,2,3,4)` vs. `colt.addNumbers.apply({firstName: "Ellie"}, [1,2,3,4])`
* later, `bind` - helpful with "asynchronous code".

### 391. Note about Keyword This 7 - Bind 
 * @40secs it says elieCalc(3,4) when it should be elieCalc2(3,4)

### 392. Keyword This 7 - Bind  
* bind works like call in terms of arguments but returns a function definition. - the re-binding for this persists.
* use case, when call args may vary. - "with the context of this bound already".
* e.g.  `var ellieCalc = colt.addNumbers.bind(ellie, 1, 2, 3, 4); ellieCalc();` , e.g. "partial application" `var ellieCalc2 = colt.addNumbers.bind(ellie, 1, 2); ellieCalc2(3, 4);` e.g. `var ellieCalc3 = colt.addNumbers.bind(ellie); ellieCalc3(1, 2, 3, 4);`
* e.g. asynchronous code - in browser - `window.setTimeout(function(){console.log...}, 1000);`

### 393. Keyword This 8 - Bind Pt. 2 
* ex. this === colt since that is the closest parent object. - WRONG - because "since the setTimeout() is called at a later point in time it actually refers to the global object." - it should print "Hi undefined". - also IMPORTANT - setTimeout() is a method on the window object, so it is equivalent to calling setTimeout() outside of the declared parent object. - So - beware of `this` when an asynchronous function is involved and of methods bound to other object, esp. bound to the global object, prefix such function calls e.g. window.setTimeout(). - "the context in which the function is **executed** is actually the global context."
* ex. 

```
var colt = {
    firstName: "Colt",
    sayHi: function() {
        timeoutfunc = function(){console.log("Hi " + this.firstName)};
    setTimeout(timeoutfunc.bind(this), 1000);
    }
}
```
 
### 394. Keyword This 9 - New Keyword & Recap 
* 4th rule
* `new` keyword. used with a function - inside that function `this` refers to the newly created object. Also implicitly adds `return this;` to the function being defined.
* e.g.

```javascript
function Person(firstName, lastName) {
  this.firstName = firstName;
  this.lastName = lastName;
}
// EXPECTATION: With strict off, this adds members firstName, lastName to the default global object that this refers to. With strict on, an error occurs, this is undefined. If we add the keyword, "new" this refers to an empty object, firstName, lastName are added as members to this object.
// The usage of the keyword new is a bit unexpected though. Here it is:
var der = new Person("D", "R");
// So using the new keyword in front of a previously defined function treats the function as a object constructor in which this refers to an empty object and the function implicitly returns this.
```
 
* Recap.
* this refers to a value that is determined by its **declaration+execution** context.
* 4 rules for determining what this refers to. 

### 395. OOP 1 - Introduction	 
* My def. OOP refers to programming using a programming language which has a builtin features for supporting the creation of modular code. Modular code means that related data and functions are grouped together into a single entity called an object. Object are defined by class definitions, they usually extend the builtin types of the language. The language usually provides features around objects that help organize code and reduce the chance of errors. 

* JS is NOT an OOP but we can approximate an OOP using basic JS, i.e. there are no built in class definition features. In JS we use functions and objects.

* JS "constructor functions". Caps Naming conventions.

```
function Person(firstName, lastName) {
  this.firstName = firstName;
  this.lastName = lastName;
}
Person("D","R") // returns undefined.
new Person("D", "R"); // returns object.
```

### 396. OOP 2 - New Keyword	  
* new
 * creates empty object
 * sets this to that object
 * adds return this to end of function.
 * new operates on functions.
 * inserts key="__proto__" with value=discussed later. we say "dunder proto" = "double underscore proto". 
 *  "links the object that was **just** **created** to the prototype property - on the **constructor** function."

```
function Person(fn, ln) {this.fn = fn; this.ln = ln;}
undefined
Person("D","R")
undefined
var p = new Person("D","R")
undefined
p
Person {fn: "D", ln: "R"}
  fn: "D"   ln: "R"   __proto__:
    constructor: ƒ Person(fn, ln)     __proto__: Object 
new p.__proto__.constructor("L","L") // refers to the original contructor, note you still need the new keyword.

```

* ex. 


```javascript
function Dog(name, age) {
    this.name = name;
    this.age = age;
    this.bark = function() { 
        console.log(this.name + " just barked!");
        };
}
```


### 397. OOP 3 - Multiple Constructors

* use case - two constructors with overlapping code. - solution - use .call method inside one of the constructors to do the overlapping work.


```javascript
function Car(make, model, year) {
    ...
    this.numWheels = 4;
}

function Motorcycle(make, model, year) {
    ... // = 
    Car.call(this, make, model, year); // notice we didn't make use of the new keyword here.

    // OR equivalently 
    Car.apply(this, [make, model, year]);    
    // OR equivalently 
    Car.apply(this, arguments); // "arguments" is a JS keyword. "not tecnically an array".
    this.numWheels = 2;
}

// arguments works even if the function is defined without any explicit arguments e.g.
function foo() {
    return arguments;
}

foo(1,2,3); // prints [1,2,3]
```
 
### 398. OOP 4 - Recap 
 ...


### 399. OOP 5 - Prototypes


* Diagram - Circle = constructor function, box = object.
 * Green Circle = Person constructor function.
   * Every constructor function has a .prototype ->, which is an object = Blue Box. 
   * Person.prototype.constructor ->, which is a function, points back to the constructor function = Green Circle.
   * Purple Box = an object created using the `new` keyword. typeof ellie === "object", e.g. `ellie = new Person("Ellie", "Sux");` ->, points to the Blue Box, via .\__proto\__, which is added to ellie by "new". i.e. ellie.\__proto\__ === Person.prototype prints true.
   * Note how the Blue Box = Person.prototype is shared by all instances of new Person as well as the constructor function = Green circle.
   * **Most important observation for me is that in JS, functions are also similar to objects in that they can have members just like objects. As soon as you define a constructor function, it immediately has a member called .prototype, of type object. This object is shared by all instances objects that are created using the new keyword applied to the constructor function. **

```javascript

function Person(fn, ln) {this.fn = fn; this.ln = ln;}

typeof Person // prints "function"
typeof Person.prototype // prints "object"

// Every constructor function has a property with key=prototype, value=object. e.g.

p = new Person("D", "R");

typeof p // prints object

typeof p.__proto__.constructor // prints "function" this is the constructor function

typeof p.__proto__.constructor.prototype // prints "object"

// That prototype object has key=constructor, value= the constructor function (same constructor function as above).

typeof p.__proto__.constructor.prototype.constructor // prints "function" - "points back to the constructor function"

p.__proto__.constructor === p.__proto__.constructor.prototype.constructor // prints true 

// Every time an object is created with "new", the new object gets key="__proto__" added to it. It links the object "p" to the:

p.__proto__.constructor.prototype // prototype property of the constructor function

///////////////////////////////////////////////

// UNEXPECTED - JS allows function types to have members attached to it just like an object can. So typeof p.__proto__.constructor == "function" while p.__proto__.constructor.prototype == "object". Therefore, in JS functions are objects too.

```

* FYI: discussed elsewhere- the .prototype property of constructor functions is involved in inheritance.
* Person.prototype.constructor === Person // prints true , this clearly illustrates a circular reference to the constructor function.

### 400. OOP 6 - Prototype Chain 
* examining .prototype.
* shared by objects created with new.

```javascript
function Person(fn, ln) {this.fn = fn; this.ln = ln;}
var d = Person("D", "R");
var l = Person("L", "L");
// What happens when you add a member under .prototype? e.g.
Person.prototype.isInstructor = true;
// EXPECTATION: All instances should have shared access to .isInstructor .

d.isInstructor // prints true
l.isInstructor // prints true

// I expect d.__proto__.isInstructor prints true, so JS is doing more under the hood to make the above work. //  d.__proto__.isInstructor works too, just like d.isInstructor. // It also works the other way around, from instance object to prototype object.
d.__proto__.notCool = false;
Person.prototype.notCool // prints false.

// This shared access to members inside .prototype is a result of the "way that JS looks for methods and properties". It is called the prototype chain.

// Example

var arr = []; // = empty array.
var arr = new Array(); // Equivalent
var arr = new Array; // Equivalent - parens optional - even though typeof Array "function" // Array is called "a built in constructor"
arr.push(10); // How does JS know where to find the method .push() ? ANS: it looks in .__proto__, if you inspect the contents of arr you will find the push method under, arr.__proto__.push().

// As expected
arr.__proto__ === Array.prototype // true

// JS first looks for a member at the top level of an object and then checks .__proto__

// Q: Can you add a member at the top level as part of the constructor function like arr.length? Clearly yes, since the built in construct Array does it. This is probably the mechanism for per instance private data members. ANS: Any members added outside of .prototype and .__proto__ are private/not-shared.

// When JS doesn't find a member at the top level .__proto__ is searched recursively, hence "prototype chain"

// every object has method .hasOwnProperty(str) , returns true if str is a member of the object.

d.hasOwnProperty("fn"); // true
d.hasOwnProperty("caca"); // true

// NOTE: use dir(Person) to see all properties in chrome console. "Person" hides most properties.

// Example - meaning of prototype chain.

arr.hasOwnProperty("length"); // prints true, but arr does not have a member called hasOwnProperty under arr.__proto__, JS keeps looking for nested .__proto__, in this case it is two levels nested under arr.__proto__.__proto__.hasOwnProperty. 

// NOTE: In chrome JS console, dir(arr) , each __proto__ has a name adjacent to it like Array(0) or Object() - this is clearly the name of the prototype constructor function.

// The recursive search of .__proto__ upon an attempt to access a member continues until the first matching member name, if there is no matching member name the search will ALWAYS terminate at the built in Object.prototype which is the only object in JS that has .__proto__ === null. This is where the "chain" ends.

arr.__proto__.__proto__.__proto__ === null // true.

arr.__proto__.__proto__ // UNEXPECTED: does not show a member name "__proto__" === null in JS console. it does show "get __proto__: ƒ __proto__()"

```
 
### 401. OOP 7 - Exercise 
 * Why "placing methods and properties on the prototype is very efficient."


```javascript
// EXPECT:

function Person(name) {
    this.name = name;
}

Person.prototype.sayHi = function() {
    return "Hi " + this.name;
}

// FYI: Don't forget the "new" keyword before the constructor function call, e.g.
var d = new Person("Darbin");
// Expectation correct.

// The above is more efficient than that below because each time we create an object using the new keyword we create a copy of the sayHi() function, whereas the above makes sayHi() a share function.

function Person(name) {
    this.name = name;
    this.sayHi = function() {
        return "Hi " + this.name;
    };
}

// Exercise

function Vehicle(make, model, year) {
    this.make = make;
    this.model = model;
    this.year = year;
    this.isRunning = false;
}

Vehicle.prototype.turnOn = function() {
    this.isRunning = true;
}

Vehicle.prototype.turnOff = function() {
    this.isRunning = false;
}

Vehicle.prototype.honk = function() {
    if(this.isRunning === true) {
        return "beep";
    }
}

// Main point: put shared methods under Person.prototype. non-share in constructor function this.x = x;
```


### 402. OOP 8 - Solution and Recap 
... 
### 403. Closures 
* used to "emulate private variables"
* definition
  * a function nested inside a function that has access to the local variables of the outer function "after the outer function has returned".
  
```javascript
function outer() {
    var data = "mr hankey";
    return function inner() {
        var innerData = " the christmas poo.";
        return data + innerData;
    }
}

outer(); // returns the function inner()
outer()(); // "mr hankey the christmas poo."

// Another example. This one illustrates the meaning of "after the outer function has returned" as used above. Notice  the only local variables here are the function arguments.

function outer(a) {
    return function inner(b) {
        return a + b;
    }
}

outer(5)(5) // 10

var tmp = outer(5); // returns function inner, with a set to 5

tmp(10) // 15. call above function with b set to 10, 5 + 10 = 15.

// in the above, we say "the function inner is a closure"

// Exercise - do either of the given functions "contain a closure"?. My ANS: There is a closure of there is an inner function that makes use of the variables which are part of the outer function, otherwise its just returning a plain function.

// ANS: no closure in the first function. second function, innerFn is a closure.

// use case - used to "emulate private variables"
// FYI: inner functions need not have a name.
// FYI: JS has supports pre/post-increment support, "++" works just like in C, i.e. increment before/after the value is used in an expression.

function outer() {
    var count = 0;
    return function() { // function name not required.
        return ++count;
    }
}

// EXPECT:
outer()() // 1
outer()() // 2
outer()() // 3
// WRONG
outer()() // 1
outer()() // 1
outer()() // 1 // if you want the local variable count to persist you must save a reference to the inner function e.g.

var tmp = outer(); // returns the inner function.
tmp() // 1
tmp() // 2
tmp() // 3 // the local variable count now has a persistent value, and it cannot be accessed (say incremented or decremented) except for via the inner function, the "closure". Hence, this "emulates private variables".

// Another Example - in this case no function is being returned, no use of the new keyword either. "instructors" emulates a private variable. This illustrates that a closure need not involve an inner function being returned, the defining characteristic is a an inner function making use of variables in the outer function. This example also shows that a function can be a closure even if it does not modify the outer local variables, simply returning a variable from the outer function''s scope is sufficient to call it a closure.

function classRoom() {
    var instructors = ["Bruce", "Kan"]; // emulates a private var.
    return {
        getInstructors: function() {
            return instructors; // outer function local variable. // just returning , not modifying, the instructors array. Still considered a closure.
        },
        addInstructor: function(str) {
            instructors.push(str);
            return instructors;
        }
    }
}

var c1 = classRoom(); // returns a class room object per above.

c1.getInstructors(); // ["Bruce", "Kan"]
c1.addInstructor("Fine"); // ["Bruce", "Kan", "Fine"]

var c2 = classRoom();
c2.getInstructors(); // ["Bruce", "Kan"] , thus c2  gets a fresh private variable for "var instructors".


```




