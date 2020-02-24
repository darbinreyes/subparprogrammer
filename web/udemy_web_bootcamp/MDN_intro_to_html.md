# Introduction to HTML
* In this module
	* [x] Getting started with HTML
	* [x] What’s in the head? Metadata in HTML
	* [ ] HTML text fundamentals
	* [ ]	Creating hyperlinks
	* [ ]	Advanced text formatting
	* [ ]	Document and website structure
	* [ ]	Debugging HTML
	* [ ]	Marking up a letter
	* [ ]	Structuring a page of content

## [Introduction to HTML / Getting started](https://developer.mozilla.org/en-US/docs/Learn/HTML/Introduction_to_HTML/Getting_started)


* Tools.
  * https://glitch.com/
  * http://jsbin.com/?html,output



### What is HTML?
15
15
15
15
15
15
15
15
15
15

A notation for defining the structure (= lists, paragraph) of information (= mostly text) on paper, or on a screen as if it were paper.

* element = open tag + content + closing tag.

* nesting allowed

* block-level elements vs. inline elements.

  * new line before and after - paragraphs, lists, navigation menus, footers, and so on. wouldn't be nested inside an inline element
  * vs
  * go inside block elements. no new line. links, em, strong.
* the amount of spacing that a new line takes up is part of the **default** CSS styling.
* html5 introduced more categories besides inline vs block
* in CSS, block vs inline means something unrelated and different.
* empty element (aka void elements) = open tag only. e.g \<img>.

#### Attributes

* Additional information associated with a tag that is not part of the content. e.g. class attribute
* attribute = space + name + "=" + " + value + " + space
* \<a> = a is for "anchor". title attribute = tool tip.

* attributes without values a.k.a. boolean attributes. can have a value, only have one value, the value can be omitted e.g.
* \<input type="text" disabled="disabled"\>
* \=
* \<input type="text" disabled>
* disabled makes things greyed out.

* quotes around attribute values
  * can sometimes be omitted, but this tends to cause errors so don't do it.
  * "caca" or 'caca' is allowed and equivalent, like in python strings, stick to one, don't mix.
    * single quotes can occur inside double, and vice versa, like in python, as in 
    * "caca's" vs 'caca"' // WORKS.
    * but 
    * 'caca's' // INVALID.
    * fix is to use "HTML entities" e.g.
    * 'caca\&#39;' // WORKS.
    
#### Anatomy of an HTML document

* \<!DOCTYPE html> tells the browser what flavor of html rules subsequent text follows.
* \<html> = root element = this is the beginning of my html.
* \<head> = container of certain non-content information. e.g. analogous to C includes, include CSS, statement of char set, search engine keywords, author, browser tab title,
* \<meta> = goes inside \<head> . good practice is to always include char set here.
* \<title> = goes inside \<head>. sets browser tab title.
* \<body> = all content container.

##### Whitespace in HTML

* Browser removes consecutive spaces and new lines e.g.
* \<p>cats "space space space newline newline" are better\</p>
* becomes
* "cats are better"

#### Entity references: Including special characters in HTML

* entity references = character references = references to characters that are part of the HTML syntax like "\<" to use these characters literally HTML has an escape mechanism like in C.
* character escapes start with "&" end with ";"
* e.g. < = "\&lt;" 

#### HTML comments

* \<!-- caca -->

## [Introduction to HTML / The head metadata in HTML](https://developer.mozilla.org/en-US/docs/Learn/HTML/Introduction_to_HTML/The_head_metadata_in_HTML)

* \<title> = browser tab text, default bookmark name. used in search results.
* \<meta> . many uses. common: set char set
  * attributes:
      * name = meta information type
      * content = meta information
          * e.g.

```
<meta name="author" content="doo doo">
<meta name="description" content="suck my balls.">
```
##### The description's use in search engines

  * author and description are used by web apps e.g. search engines.
  * search engines use title and meta description for result link and result preview. 
  * using important keywords in the meta description can help your site get a higher ranking in search results.
  * sub-links under search engine results. configurable using "google's webmaster tools."
  * beware of no longer popular meta like name="keywords" which is valid but not really used anymore. spammer abuse.
  
#### Other types of metadata


* "Proprietary creations"
  * e.g. facebook open graph data.
  * \<meta property="og:title" content="Mozilla Developer Network"> // specially handle by facebook if you share a link to your website with facebook.
  * e.g. twitter cards
  * \<meta name="twitter:title" content="Mozilla Developer Network"> // similar to facebook example above.
  
### Adding custom icons to your site

* custom icons
* "favicon"
  * 16 pixels square.
  * displayed in browser tab, bookmarks
  * .ico file extension most supported.
  * but modern browsers can use .gif, .png.
  * to add one:
  
```
  <link rel="icon" href="favicon.ico" type="image/x-icon">
```

* other icon type
  * 1 icon type for each device.
  * e.g.
  
```
<!-- non-Retina iPhone, iPod Touch, and Android 2.1+ devices: -->
<link rel="apple-touch-icon-precomposed" href="https://developer.cdn.mozilla.net/static/img/favicon57.a2490b9a2d76.png">
```

### Applying CSS and JavaScript to HTML

* \<link> can be used to add external CSS file styling.
  * can only go inside \<head>.
* \<script> to add JS code.
  * usually placed at the bottom before closing body. 
    * can go elsewhere but you might get an error if your JS tries to access an element that hasn't been parsed yet.
    
### Setting the primary language of the document

* done by adding the lang attribute to the opening HTML tag 
* another "always include this"
* \<html lang="en-US">
* improves search engine results.
* helps blind people using screen text to speech.
* to handle multiple human languages set lang attribute in a \<span> e.g.

```
<p>Japanese example: <span lang="ja">ご飯が熱い。</span>.</p>
```

## [Introduction to HTML/HTML text fundamentals](https://developer.mozilla.org/en-US/docs/Learn/HTML/Introduction_to_HTML/HTML_text_fundamentals)

15
15
12

* best practices with \<h1-6>
  * only use h1 once PER PAGE
  * use them in the right order h1 h2 h3 not h1 h3 h2.
  * aim to use 3/6 of them PER PAGE. Instead of deep hierarchy use separate pages.

*  <span> element. It has no semantics = no op on the content by default. You use it to wrap content when you want to apply CSS to it (or do something to it with JavaScript)  
  * You can use this to make the styling of its contents look like an \<h1> but it only looks that way, whereas by convention h1 has the meaning of top level information.
  
### Lists

* unordered
* ordered
* can be nested.

### Emphasis and importance

* \<em> is for true emphasis, not just making something italic. If all you want is italic styling, use \<span> + CSS. or use  \<i>.
* \<strong> also for true emphasis. For just bold style, use \<span> or \<b>.
* \<em> + \<strong> can be used together nested

### Italic, bold, underline...

* practically deprecated. pre CSS. avoid use.
* underlines \<u> can be confused with links. avoid.

## [Introduction to HTML/Creating hyperlinks](https://developer.mozilla.org/en-US/docs/Learn/HTML/Introduction_to_HTML/Creating_hyperlinks)

### What is a hyperlink?

href = hypertext reference.
title = tool tip.

#### Document fragments = linking to a specific section on a page.

add id attribute to a tag. Then use \# in href links. Works on current or other pages.

id="This_section"
href="index.html#This_section"
href="#This_section" // Called a doc frag ref.


### Anatomy of a link

### A quick primer on URLs and paths

### Link best practices

keep accessibility in mind. Blind folks. Don't be redundant.

Links in the same site should be relative.

download attribute sets default save file name.

### E-mail links

href="mailto:nowhere@mozilla.org"

use "query term/notation" ?x=1&y=0 to set cc, bcc, subject, etc..

## Advanced text formatting

#NEXT:

