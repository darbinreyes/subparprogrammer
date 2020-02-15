# What is the best documentation for HTML?

On 28 May 2019, the W3C announced that WHATWG would be the sole publisher of the HTML and DOM standards.

https://en.wikipedia.org/wiki/HTML#Transition_of_HTML_Publication_to_WHATWG

https://whatwg.org/

ANS:

https://html.spec.whatwg.org/multipage/

# For CSS, it's another organization.

The World Wide Web Consortium (W3C), former maintainer of the HTML and current maintainer of the CSS standards,

https://www.w3.org/standards/webdesign/htmlcss

# What is w3schools.com?

The site derives its name from the World Wide Web (W3), but is not affiliated with the W3C.

# Thoughts

There are so many different languages involved with web development. It's difficult to decide where to start and also what to use as a reliable reference. 

For now, I can simply review the definitions of the html tags in my simple web site. After that, I probably need to set a small goal and use that as a guide on what languages I should learn/review.

This official whatwg documentation is 1200 pages!

https://html.spec.whatwg.org/print.pdf

# Tags in my index.html.

Using this as a reference. https://www.w3schools.com/tags/default.asp.

```html

<!DOCTYPE html> 
<!-- 
must be the very first thing in your HTML document, before the <html> tag.

The <!DOCTYPE> declaration is not an HTML tag;

It's instruction to the web browser about what version of HTML the page is written in.  

<!DOCTYPE html> indicates HTML5.

Tip: To check if the HTML of your Web documents is valid, go to W3C's validation service. http://validator.w3.org/

-->

<!-- http://www.w3schools.com/html/html_intro.asp -->

<html lang="en-US">
<!--
tells the browser that this is an HTML document.

represents the **root** of an HTML document.

tag is the container for **all** other HTML elements (except for the <!DOCTYPE> tag).

lang
Specifies the language of the element's content

Global attributes - supported by all tags. The global attributes below can be used on any HTML element.

https://www.w3schools.com/tags/ref_standardattributes.asp

-->

<head>
<!--
 container for all the head elements.
 
  can include a title for the document, scripts, styles, meta information, and more.
  
  can go inside the <head> element:
	•	<title> (this element is **required** in an HTML document)
	•	<style>
	•	<base>
	•	<link>
	•	<meta>
	•	<script>
	•	<noscript>

-->
<title>
<!--

The <title> tag is **required in all** HTML documents and it defines the title of the document.
The <title> element:
	•	defines a title in the browser toolbar
	•	provides a title for the page when it is added to favorites
	•	displays a title for the page in search-engine results

-->

<meta charset="utf-8"/>
<!--
Defines metadata about an HTML document

Metadata will not be displayed on the page, but will be machine parsable.

viewport = (the user's visible area of a web page). See below.

Note: The content attribute MUST be defined if the name or the http-equiv attribute is defined.

charset

character_set
Specifies the character encoding for the HTML document

-->
<meta name="viewport" content="width=device-width, initial-scale=1"/>
<!--
HTML5 introduced a method to let web designers take control over the viewport, through the <meta> tag.

The viewport is the user's visible area of a web page. It varies with the device, and will be smaller on a mobile phone than on a computer screen.

viewport element gives the browser instructions on how to control the page's dimensions and scaling.

The width=device-width part sets the width of the page to follow the screen-width of the device (which will vary depending on the device).

The initial-scale=1.0 part sets the initial zoom level when the page is first loaded by the browser.

name

application-name
author
description
generator
keywords
viewport
Specifies a name for the metadata

content

text
Gives the value associated with the http-equiv or name attribute

-->

<link rel="stylesheet" href="http://maxcdn.bootstrapcdn.com/bootstrap/3.2.0/css/bootstrap.min.css"/>
<!--
Defines the relationship between a document and an external resource (most used to link to style sheets)

used to link to external style sheets.

href
URL
Specifies the location of the linked document

rel

alternate
author
dns-prefetch
help
icon
license
next
pingback
preconnect
prefetch
preload
prerender
prev
search
stylesheet
Required. Specifies the relationship between the current document and the linked document

type

media_type
Specifies the media type of the linked document

supports the Event Attributes in HTML.

HTML has the ability to let events trigger actions in a browser, like starting a JavaScript when a user clicks on an element.

-->
<style>
img.subparlogo {
 width:10%;
 float:right;
}
</style>
<!--
Defines style information for a document

Alternative to linking a css file.
This is clearly stating that a sublclass of the img element should have the listed style, width = 10% of the page. float = right. I use this for the logo image.


-->
<body>
<!--
Defines the document's body

contains **all the contents** of an HTML document, such as text, hyperlinks, images, tables, lists, etc.

-->
<div class="container">
<!--
Defines a section in a document

often used as a container for other HTML elements to style them with CSS or to perform certain tasks with JavaScript.

-->
<h2>
<!--
Defines HTML headings

The six different HTML headings.

-->
<p>
<!--
Defines a paragraph

-->
<a href="https://www.linkedin.com/pub/darbin-reyes/34/32b/305">@LinkedIn</a>
<!--
Defines a hyperlink

href

URL
Specifies the URL of the page the link goes to

target

_blank // opens link in new browser tab.
_parent
_self
_top
framename
Specifies where to open the linked document


-->
<ul class="nav nav-tabs" role="tablist">
<!--
Defines an unordered list

-->
<li class="active"><a href=".">Home</a></li>
<!--
Defines a list item
-->

<pre>
<!--
Defines preformatted text
Text in a pre element is displayed in a fixed-width font, and it preserves both spaces and line breaks.

-->
<script>
<!--
used to define a **client**-side script **(JavaScript)**.


either contains scripting statements, or it points to an external script file through the src attribute.

If the "src" attribute is present, the <script> element must be empty.

If neither async or defer is present: The script is fetched and executed immediately, before the browser continues parsing the page

src

URL
Specifies the URL of an external script file

-->
<script src="https://ajax.googleapis.com/ajax/libs/jquery/1.11.1/jquery.min.js"></script>
<script src="http://maxcdn.bootstrapcdn.com/bootstrap/3.2.0/js/bootstrap.min.js"></script>
```



