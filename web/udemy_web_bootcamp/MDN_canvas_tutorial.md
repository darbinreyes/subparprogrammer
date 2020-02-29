# Goals

* Animate drawing a single line.

## [Canvas tutorial](https://developer.mozilla.org/en-US/docs/Web/API/Canvas_API/Tutorial)

Apparently CSS cannot be used to set the style of the canvas element. You must inline attributes like height and width.

"The **default** size of the canvas is 300 pixels × 150 pixels (width × height). But custom sizes can be defined using the **HTML** height and width property." // NOT CSS.

Here's a list of methods for the canvas object: https://developer.mozilla.org/en-US/docs/Web/API/HTMLCanvasElement

Unclear:

The element can be sized arbitrarily by CSS, but during rendering the image is scaled to fit its layout size: if the CSS sizing doesn't respect the ratio of the initial canvas, it will appear distorted.

See here for styling the canvas. https://developer.mozilla.org/en-US/docs/Web/API/Canvas_API/Tutorial/Basic_usage

Suddenly my canvas CSS started working. Maybe it was a caching problem? 

ANS: Yes it was a caching problem. I determined this be opening my index.html in safari after noticing that my CSS changes were not taking effect in chrome. Reloading the page and opening a new tab in chrome does not fix the problem.

FIX: In chrome, do a full reload using **shift+cmd+r**.

**Next time use element inspector to debug this, look at the CSS.**

## 1.	Basic usage
## 2.	Drawing shapes
## 3.	Applying styles and colors
## 4.	Drawing text
##	5.	Using images
##	6.	Transformations
##	7.	Compositing and clipping
##	8.	[Basic animations](https://developer.mozilla.org/en-US/docs/Web/API/Canvas_API/Tutorial/Basic_animations)

You can't just use a for-loop.

We need a mechanism to draw things periodically.

#next

### An animated solar system



