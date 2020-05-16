# https://getbootstrap.com/docs/4.4/layout/overview/

.container expected behaviour. 

if screen size <= 576px, width = 100%. Therefore the CSS inspector should show that the parent of the container, which is the body, will have the same width as the container.

if  768px > screen size >= 576px, max-width=width=540px. I expect the body and the container to have this same width.

and similarly for the consecutive breakpoints.

// test case. .container with screen size = xs 
screensize = 500px // hence we are in the xs range
body width = 500px
.container width = 500px = 15px + 470 + 15

// test case. .container with screen size = sm

screensize = 631px
body width = 631px
.container width = 15px + 510 + 15 = 540! Yes! So my assumption above is slightly wrong. The body takes on the width = screensize, the container takes on the bootstrap4 fixed width of 540px.

So the table in this doc page lets you compute the .container size given a screensize, and screensize = body size/width.

# https://getbootstrap.com/docs/4.4/utilities/spacing/

margin and padding control.

size range 0 to 5 = .25rem to 3rem // what is a "Sass" map?

### Notation.

No breakpoint means : apply to all.

{property}{sides}-{breakpoint}-{size}

e.g.

mt-md-5

Are the class examples a way to increase the margin? ANS: yes. 

e.g. to overide the default 3rem mt-5 use.

.mt-5 {
  margin-top: 6rem!important;
}


### Horizontal centering

an .mx-auto class for horizontally centering fixed-width block level content

### Negative margin

"for customizing grid column gutters" // what is "column gutter"?

with the addition of n before the requested size.

e.g.

mt-n5 // does precisely the opposite of positive margin, it lets things elements overlap instead of adding space.


# https://getbootstrap.com/docs/4.4/utilities/shadows/

div.shadow

# https://getbootstrap.com/docs/4.4/utilities/colors/

color behaviour is different when applied to anchor tags.

### Background gradient

to enable - need to know how to set Sass options. // This tutorial seems good, but the its not a quick process the first time around. https://www.mugo.ca/Blog/How-to-customize-Bootstrap-4-using-Sass

"Sometimes contextual classes cannot be applied due to the **specificity** of another **selector**. In some cases, a sufficient workaround is to **wrap** your element’s content in a \<div> with the class."

