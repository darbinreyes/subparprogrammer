# [VII.4](https://mathcs.clarku.edu/~djoyce/java/elements/bookVII/propVII4.html)

"Any number is either a part or parts of any number, the less of the greater."

![VII.4 figure](VII.4.png)

### TODO

* [x] Be neat. On paper. In text.
* [x] Read the guide. Note Joyce’s notational conventions e.g. formal vs informal numbers. Divides. Measures.
* [x] Read the proposition proof. Note comments for clarification.
* [x] Write max 3 sentence proof summary. Use EWD notation for brevity and notation practice.
* [x] Specify. What the program does. Design. Very high level pseudo code.
* [ ] Implement on paper, in C. 
  * [x] v0 
  * [] v1
* [ ] Implement in EWD notation, on paper.
  * [x] v0 
  * [] v1
* [ ] Write down 3 test cases.
* [ ] Test on paper. Use table method.
* [ ] Implement in C on computer. Fully commented. Handle all function call errors and asserts gracefully.
* [ ] Add and run test cases on computer. Use gdb debugging if needed.
* [ ] Verify test case answers in python. Add results as comment in test.



## Guide 

Modern phrasing:

For **b** < **a**, 
**b** is either a unit fraction of **a** or a proper fraction of **a**.
a.k.a. part or parts.

**Example**: "2 is one part of 6, namely, one third part; but 4 is parts of 6, namely, 2 third parts of 6."

In the case ¬relatively_prime.(b, a) ∧ ¬(b|a) the proof finds the "least number of parts".

Distinction with the case relatively_prime.(b, a).

**Notation**: "b is one nth part of a as the equation b = a/n, and a statement such as b consists of m one-nth parts of a as the equation b = (m/n)a."

## Proof 

* Relavent definitions.

 * VII.Def.3. "A number is a part of a number, the less of the greater, when it measures the greater;”

 * VII.Def.4. "But parts when it does not measure it.”
 
b < a

relativelyprime.(b, a) ∨ ¬relativelyprime.(b, a)

Case relatively_prime.(b, a). Derive parts. b = (m/n)a.

Case ¬relatively_prime.(b, a) ∧ b|a. Derive part. b = a/n.

Case ¬relatively_prime.(b, a) ∧ ¬(b|a). Derive parts. b = (m/n)a.


## Proof Summary

See above.

## Specification and Design

Determines if the lesser number is part or parts of the greater number.

Check if the given numbers are relatively prime. If yes, return parts.
Else if no, then check if b|a, if yes, return part. Else return parts.

## Implementation in EWD notation.

On paper.