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

## 82. Bootstrap Image Gallery Pt. 1	 .navbar-inverse

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
## 87. Note about making bootstrap responsive on mobile devices 



