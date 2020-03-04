# [VII.5](https://mathcs.clarku.edu/~djoyce/java/elements/bookVII/propVII5.html)

If a number is part of a number, and another is the same part of another, then the sum is also the same part of the sum that the one is of the one.

![VII.5](VII.5.png)

## TODO

* [ ] Be neat. On paper. In text.
* [x] Read the guide. Note Joyce’s notational conventions e.g. formal vs informal numbers. Divides. Measures.
* [x] Read the proposition proof. Note comments for clarification.
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
* "deal with **distributivity** of division and multiplication over addition and subtraction."

If

a = (1/n)×b

d = (1/n)×e

then

a + d = (1/n)×(b + e)

or equivalently

a + d = b/n + e/n = (b + e)/n

* Algebraically, to prove the same result as the proposition, I would have added the two equations for a + d and then factored out the common term (1/n). Hence "distributivity".

* "only stated for the sum of two numbers, it is **used** for sums of arbitrary size."

* Outline and critique of the proof
  * "The argument is completely based in principles of **informal** addition, namely unrestricted **commutativity** and **associativity** of addition where the number of terms n is unrestricted."
  * commutativity means: a + b = b + a.
  * associativity means: ((a + b) + c) = (a + (b + c)).
  * "the foundations of formal number theory in the Elements are principles of informal number theory."
  
## Proof 

"Let the number A be a part of BC, and another number D be the same part of another number EF that A is of BC."

part.(A, BC) = part.(D, EF)

"I say that the sum of A and D is also the same part of the sum of BC and EF that A is of BC."

part.(A + D, BC + EF) = part.(A, BC)

"Since, whatever part A is of BC, D is also the same part of EF, therefore, there are as many numbers equal to D in EF as there are in BC equal to A."

part.(A, BC) = part.(D, EF)

⇒

EF/D = BC/A

"Divide BC into the numbers equal to A, namely BG and GC, and EF into the numbers equal to D, namely EH and HF. Then the multitude of BG and GC equals the multitude of EH and HF."

BC = BG + GC = A + A
EF = EH + HF = D + D
multitude.(BG, GC) = multitude.(EH, HF)

"And, since BG equals A, and EH equals D, therefore the sum of BG and EH also equals the sum of A and D. For the same reason the sum of GC and HF also equals the sum of A and D."

BG = A ∧ EH = D

⇒

BG + EH = A + D

GC = A ∧ HF = D

⇒

GC + HF = A + D

"Therefore there are as many numbers in BC and EF equal to A and D as there are in BC equal to A."

(BC + EF)/(A + D) = BC/A

"Therefore, the sum of BC and EF is the same multiple of the sum of A and D that BC is of A." 

(BC + EF)/(A + D) = m = BC/A

"Therefore, the sum of A and D is the same part of the sum of BC and EF that A is of BC."

part.(A + D, BC + EF) = part.(A, BC)

Therefore etc. 

Q.E.D.

## Proof Summary

Given BC/A = m = EF/D.
Prove BC/A = (BC + EF)/(A + D).

BC/A = m

⇒ {Laws of Arithmetic}

\#0 BC = m×A.

EF/D = m

⇒ {Laws of Arithmetic}

\#1 EF = m×D.

BC + EF

= {\#0, \#1}

m×A + m×D

= {Laws of Arithmetic}

\#2 m×(A + D).

(BC + EF)/(A + D)

= {\#2}

m×(A + D)/(A + D)

= {Laws of Arithmetic}

m

= {Given}

BC/A.

Q.E.D.

## Specification and Design

Given four numbers, checks that the first pair and the second pair are the same part and if so returns the sum per the proposition.

## Implementation in EWD notation.

## Misc.

