# [VII.6](https://mathcs.clarku.edu/~djoyce/java/elements/bookVII/propVII6.html)

If a number is parts of a number, and another is the same parts of another, then the sum is also the same parts of the sum that the one is of the one.

![VII.6](VII.6.png)

## TODO

* [ ] Be neat. On paper. In text.
* [ ] Read the guide. Note Joyce’s notational conventions e.g. formal vs informal numbers. Divides. Measures.
* [ ] Read the proposition proof. Note comments for clarification.
* [ ] Write max 3 sentence proof summary. Use EWD notation for brevity and notation practice.
* [ ] Specify. What the program does. Design. Very high level pseudo code.
* [ ] Implement in EWD notation, on paper.
* [ ] Write down 3 test cases.
* [ ] Test on paper. Use table method.
* [ ] Implement on paper, in C. 
* [ ] Implement in C on computer. Fully commented. Handle all function call errors and asserts gracefully.
* [ ] Add and run test cases on computer. Use gdb debugging if needed.
* [ ] Verify test case answers in python. Add results as comment in test.
* [ ] Check .md for typos.

## Guide

* multiplication by [non-unit] fractions distributes over addition.

* if a = (m/n)b and d = (m/n)e then a + d = (m/n)(b + e)

## Proof 

## Proof Summary

Let parts.(AB, C) = parts.(DE, F).

I say that parts.(AB + DE, C + F) = parts.(AB, C).

[Assuming AB is m, 1-n-th parts of C. We can represent this as AB = (m/n) × C. Then by hypothesis also DE = (m/n) × F.]

[Joyce's proof seems off/may have a typo, using my book's proof below]

"For since" parts.(AB, C) = parts.(DE, F)

"therefore, as many parts of C as there are in AB, so many parts of F are there also in DE."
// m × (C/n) = AB viz. m parts.
// m × (F/n) = DE

"Let AB be divided into the parts of C, namely AG, GB,"

## Specification and Design

## Implementation in EWD notation.

## Misc.

