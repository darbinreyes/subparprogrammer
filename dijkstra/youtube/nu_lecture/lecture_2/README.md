International Computers Limited

and

The University of Newcastle Upon Tyne

Department of Computing Science

25th Joint International Seminar

on the Teaching of Computing Science

7th - 11th September 1992

[NU Lecture 2](https://www.youtube.com/watch?v=U_zcIgNNjbw&t=00m06s)

---

The problem I would like to deal with in this hour is interesting as an example of a possible interplay between mathematics and computing science, programming as a matter of fact. The history of this problem is interesting in the sense that Sylvester conjectured it in 1893, he and his contemporaries could do nothing with it. It remained dormant until 1933 when Erdüs revived interest in the problem.

![b.0](imgs/b.0.png)

And some time later a proof was given by T. Gallai.

![b.1](imgs/b.1.png)

I have not seen that proof, but it is a proof that even Coxeter describes rather complicated. And we had to wait until 1948, until L.M. or L.N. I'm not quite sure so I omit it. Until Kelly, came, it is L.M., OK. Until L.M. Kelly came with a palatable proof.

![b.2](imgs/b.2.png)

Now let me first state the theorem, and that is, for any finite number of distinct points, in the real euclidian plane, and with real we mean that the coordinates are not complex, we can assert the following: all the points are collinear, or their exists a straight line, through exactly two of them, with exactly two I mean not three.

[Video bookmark](https://www.youtube.com/watch?v=U_zcIgNNjbw&t=02m55s)

* // BB (= BlackBoard)
  * 1893
  * 1933 Erdüs
  * 1948 L. M. Kelly
  * finite number of distinct points in the real Euclidian plane.
  * all the points are **collinear** or their exists a straight line through exactly 2 points

Now one of the things that may indicate that the theorem is possible and not completely trivial is that this is not a combinatorial theorem. You see because, oh yea sorry, for the sake of brevity, in the remaining of this hour, I will say points, I mean **distinct points**, and when I say line, I mean **straight line**.

Well the Euclidian **axiom** that connects points and lines is that any two points uniquely determine a line through them.

* // BB
  * any 2 points determine uniquely a line through them

Now let us translate the formulation of all these properties and theorems a little bit. Let us call, let us translate, points into persons, lines into clubs, a point lies on a line is that person is a member of the club.

In that case, the axiom about club membership is that any two persons uniquely determine the club of which they are a member. That's the translation of this one.


* // BB
  * any 2 persons uniquely determine the club of which they are a member

However, the conjecture of Sylvester would be that, in a finite population, where this club membership rule holds, either all persons are members of the same club, or there exists a club with exactly two members.

[Video bookmark](https://www.youtube.com/watch?v=U_zcIgNNjbw&t=05m40s)

In terms of members and clubs the theorem is not true. It is not too difficult to construct a counter example. Place a population of seven, yes, yea, place a population of seven persons in a regular fashion around a ring,

![a.0](imgs/a.0.png)

* // BB
  * 7 clubs of 3 members

and now I'm going to create seven clubs, of three members.

![a.1](imgs/a.1.png)

![a.2](imgs/a.2.png)

And I do that by putting these three members in one club. The remaining six clubs, you get by rotation of that **triangle**. Any **pair** of the complete 7 graph. The complete 7 graph has 7 times 6 over 2 is 21 edges.

* // BB
  * 7×6/2


That is, in the complete, in the population of 7 persons, you can isolate 21 pairs, each pair uniquely determines the triangle to, each edge uniquely determines the triangle to which it belongs, however you see that with these 7 clubs of 3 members it is not true that all persons belong to the same club, because each club has at most 3 members, and it is not true that there exists a club with exactly two members.

[Video bookmark](https://www.youtube.com/watch?v=U_zcIgNNjbw&t=07m41s)

So we know from this counter example that somewhere along the proof we have to use more of euclidian geometry, more properties of the euclidian plane, than just that any two points uniquely determine the line straight line through them. Now what I propose to do is to approach this problem as a programming exercise, and what I shall do is show that if the given points are not collinear, that then there exists a line through exactly two of those points. And I will show the existence of such a line by **designing** an algorithm that computes that line.

Well, I need one function, "nopo" that is short for the "number of points on".

![b.10](imgs/b.10.png)

We will have one variable, q, of type line. I may need a little bit more space, I will develop the program here. We have one variable q of type line.

![b.11](imgs/b.11.png)


And what can we do with. We have to initialize that variable, now since lines are determined by two points, my proposal is that the program initializes q such that upon initialization P holds.

![b.12](imgs/b.12.png)

And what will be P be,

![b.13](imgs/b.13.png)

well, there is no point in considering lines that go through no points or go through one point, so we shall **initialize** q in such a way, that the number of points on q, well ideally of course its exactly two, but I cannot guarantee that, it may larger.

[Missing second conjunct, since variable E of type point has not been introduced yet, see image b.4.]
![b.14](imgs/b.14.png)

* // BB
  * nopo = # of points on.
  * P : nopo.q ≥ 2

But in any case, we can confine our attention to q's that go through at least two points. So that's being done. Next is the test,

![b.15](imgs/b.15.png)

we are now going to create a repetition, wether this q is acceptable, well, it is acceptable if the number of points on q equals 2, however if that number is larger than two, then **something** has to be done.

![b.16](imgs/b.16.png)

![b.18](imgs/b.17.png)

Well, upon completion of this loop, we know P, and the falsity of the guard, that is that nopo of q is at most 2,

![b.18](imgs/b.18.png)

well, P says that nopo of q is at least 2, so hence the number of points on q equals 2 and we are **done**.

![b.19](imgs/b.19.png)

Well the only thing of course is that here, as the repeatable statement, we have to **change q**, under **invariance** of P.

![b.9](imgs/b.9.png)

![b.20](imgs/b.20.png)

[Video bookmark](https://www.youtube.com/watch?v=U_zcIgNNjbw&t=12m15s)



So this is the program and it's OK and does the job, provided that we can demonstrate that this program **terminates**.


Now, in order to prove termination of this program we might have to do two things. First of all, we might have to take into account things that we didn't know, secondly, that are given but we haven't used yet, secondly [sic], we may have to resolve some of the non-determinism. Alia [sic, audio not clear] sort of vagueness in the statement that changes q. One thing that I have omitted to point out, and that is that here, we are confining our situation to the case that the points are **not collinear**.

![b.5](imgs/b.5.png)

Because that was the circumstance under which we were going to show the presence of a line q so that nopo of q equals two. The fact that the points are not collinear implies that there are at least **three** points, and therefore it's possible to initialize q such that P holds. You see because, to see to it that the initial value of q is such that at least two points lie at q you need at least two points. So here we are, now we have here made a very **meager**  use of the fact that it is given that the points are not collinear, we have only used the consequence that there are at least two [did he mean 3?] points. Now, question, what general conclusion can we draw with respect to q and the points from the fact that the points are not collinear?

![b.3](imgs/b.3.png)

There is a point not on q, yes. So my proposal is, to take that into **account** by introducing a variable of type point. Variable E will be of type point, E will also be initialized,

![b.6](imgs/b.6.png)

![b.7](imgs/b.7.png)

and the fact that the points are not collinear, I can celebrate that by seeing to it that when q goes through two points, E lies not on q.

![b.30](imgs/b.30.png)

![b.31](imgs/b.31.png)

![b.32](imgs/b.32.png)

![b.4](imgs/b.4.png)

* // BB
  * P : nopo.q ≥ 2 ∧ E lies not on q.

[Video bookmark](https://www.youtube.com/watch?v=U_zcIgNNjbw&t=16m10s)

I'm going to. The fact that this possibility, to assign to variable E a point that lies not on q, and to maintain that invariance, that is the way in which I exploit the non-linearity of the given points. Notice that the possibility to assign to E such a value is the only possible conclusion that we can directly draw from the non-linearity. That is, the maintenance of this invariant extracts out of the fact that the points are not collinear everything that can be extracted from it. Now, not surprisingly in the change of q, we will have to change E as well,

![b.8](imgs/b.8.png)

now let us inspect a little bit what kind of freedom we have. Well, what do we know?

![b.21](imgs/b.21.png)

Well, more than two points lie on q, so we can point to at least 3 points that lie on q. Let us name them A, B, and C, lie on q, and E lies not on q.


![b.22](imgs/b.22.png)

![b.23](imgs/b.23.png)

![b.24](imgs/b.24.png)

And I will make a picture, I promise to you that, that will be the only picture I make. But I wait a little bit. We have to change q. Now what possibilities do we have? As it is, well I will make two pictures. q, OK, here are A, B, and C, and here is E.

![a.3](imgs/a.3.png)

The claim is that we have only three possibilities for the new value of q, and that's from E through this one [A], from E through that one [B], and from E through that one [C]. Because these four points are the only points the **existence** of which we can guarantee. Through two of those [A, B, C] is excluded because then we don't change q. So the new q has to go through the old E, and through one of those three. Now, the one it goes through, is, I will call, now I will rub it out, I will call A, I am free in naming here. So the new value of q, becomes the line E, A. And now I must, yah so eh, now I rub this out again, I'm going to make a new picture, this is q, and this is E,

![b.25](imgs/b.25.png)

and I put an A here, and this will be my new q, yah.

![a.4](imgs/a.4.png)

Now, the existence of E has been used to show the, possibility of introducing E and keeping this second term of the invariant, invariant. [The invariant being "P : nopo.q ≥ 2 ∧ E lies not on q", the second term being "E lies not on q"].

Now we have to think about a termination argument. Now listen, in the original statement of the theorem we have a finite number of points, this means that our state space that consists of a q and an E, has a finite number of possible values. There is a finite number of values, possible values for q, and for each value of q there is a finite possible number of values for E. And it is in this finite space that have to find a termination argument.

[Video bookmark](https://www.youtube.com/watch?v=U_zcIgNNjbw&t=21m40s)

How do we find the termination argument? Well, the standard way is that you define a natural function on the state space which in each step of the repetition is decreased by at least 1, however, since our **space consists of a finite number of states** we can **drop** the constraint of the **variant** function being **integer**, it suffices to define an **integer [did he mean real?] function of the state** of which subsequently we can prove that it's **bounded from below** and **decreases** in each step. Now our current state **always exists** of a line q, and a point E, not on that line. Can anybody think of a **real function** of a point and a line that is bounded from below? The euclidian distance, yes, thank you very much. But if we do take the Euclidian distance, then I know which of the other two B and C, will be taken as our new E, the choice which **minimizes** the distance to the new q as much as possible.


So here, we put of B and C,

![b.26](imgs/b.26.png)

the nearest to our new q. And now,

![b.27](imgs/b.27.png)

of the six[why 6?] possibilities that we had here, there are still three left and that is in the choice of capital A. Because the choice which new point has been settled by this. So now our only obligation is, to see to it, to prove, possibly by resolving the remaining non-determinacy, that our algorithm terminates. That is, that, the distance from E to q, actually decreases. So here we are, this was our old E and this was our old q.

![a.6](imgs/a.6.png)

And we call this distance h

![a.7](imgs/a.7.png)

![a.8](imgs/a.8.png)

And well, B is somewhere, the new distance,

![a.9](imgs/a.9.png)

the distance from B to the new q is that

![a.10](imgs/a.10.png)

And I call that little b.

![a.11](imgs/a.11.png)


![a.12](imgs/a.12.png)


And I will do the same for capital C, which has a distance little c to the new q, only I don't make that drawing because that **invokes a case analysis** because there are all sorts of places where C might lie and I'm not going to do that. My **proof** obligation for the **termination** is, that I can demonstrate, that the **minimum** of little b and little c is **actually** less than h.

![b.28](imgs/b.28.png)

* //BB
  * b min c < h

And if I can show that, I have satisfied my proof obligation, [it] means that **the distance from E to q will actually decrease in each step**.

[Video bookmark](https://www.youtube.com/watch?v=U_zcIgNNjbw&t=26m18s)

Now, I have to show this, I'm going to simplify that, the very first thing is that I wish to eliminate, that operator that takes the minimum, so without changing the value of this boolean expression, I wish to **eliminate the minimum function**,




![b.29](imgs/b.29.png)

* //BB
  * b min c < h
  * = {elimination of min}

![a.13](imgs/a.13.png)

and the minimum of b and c, less than h, is according to the rules of my game, is b is less than h or c is less h.

![a.14](imgs/a.14.png)


[Pause and think](https://www.youtube.com/watch?v=U_zcIgNNjbw&t=27m37s)


Everrrybody agrees?

* //BB
  * b min c < h
  * = {elimination of min}
  * b < h ∨ c < h

Huh? No sir, because for the termination argument I need actual decrease, so the minimum of these, of this, if this value has to be less h, then b, then b is less than h or c is less than h. And this is an equivalence because, these two boolean expressions have the **same value**.



Now, the next thing I wish to do, is to eliminate the lower case letters, obviously, obviously, because little b and h and little c, they only occur in that picture,



and the sooner I liberate myself from that **picture**, the better. Now, ehh, my claim is that there is a simple expression, that has the **same value** as b less than h. Is anybody willing to make a suggestion? The length of BA or AB, yes, is less than EA, yah, and that follows from similar **triangles**.



![a.15](imgs/a.15.png)

* //BB
  * b min c < h
  * = {elimination of min}
  * b < h ∨ c < h
  * = {similar triangles}
  * BA < EA

These two triangles are similar, because they both have that right angle there and they share that one, so these two sides, the **ratio** of them is the same as the ratio of the hypotenuses.

[Video bookmark](https://www.youtube.com/watch?v=U_zcIgNNjbw&t=30m15s)

So BA less than EA is the one. Is that OK? Yes, apparently. Am I a little bit amazed. Well according to the rules of the game, the other condition yields me that CA less than EA

* //BB
  * b min c < h
  * = {elimination of min}
  * b < h ∨ c < h
  * = {similar triangles}
  * BA < EA ∨ CA < EA

![a.16](imgs/a.16.png)

Let me check. Will you check wether I have made an error? Yes. A, AB. [Audience member says something] ... Ehh, this does not hold because the space is finite. But I did make an error. I did make an error. I did make an **error**. Yes, yes, yes. There is a one bit rabbit in this proof. And I made the wrong choice, I chose, the line, but I shouldn't do that. [*Erases picture a.16*]. Here we go. This by the way was very instructive and I leave it that way. But, [*Erases the repeatable statement in the program, "q, E := ..." *]

![b.33](imgs/b.33.png)

![b.34](imgs/b.34.png)

![b.35](imgs/b.35.png)

the remark is, that I have to choose a new E, and let that be A,

![b.36](imgs/b.36.png)

![b.37](imgs/b.37.png)

that is my new E, and now the question is will the new q go through B or will it go through C,

![b.38](imgs/b.38.png)

so my new E becomes A and my new q becomes, of the lines sorry BC and, sorry, of the lines BE and CE the nearest to A,

[notice in the image below that point E is assigned point A]

![b.39](imgs/b.39.png)

so and now I will have P again.

[P being the invariant of the repetition.]

![b.40](imgs/b.40.png)

![a.17](imgs/a.17.png)

![a.18](imgs/a.18.png)

Yes. No, no, no. One of the three, one of the three, now here is our drawing. Here was q, here was the old E,

![b.41](imgs/b.41.png)

here is, my A,

![b.42](imgs/b.42.png)

here is for instance my B,

![b.43](imgs/b.43.png)

now this,

![b.44](imgs/b.44.png)

now I'm interested in this distance,

![b.45](imgs/b.45.png)

the distance from A to the new q.

![b.46](imgs/b.46.png)

Because this will be my new E.

![a.19](imgs/a.19.png)

Now we have the same picture, we call this b and we call this h

![a.20](imgs/a.20.png)

Only now it becomes a little bit different here

![a.21](imgs/a.21.png)

![a.22](imgs/a.22.png)

because b less than h is now, AB less than BE, **similarly** [Substitute C in place of B], c less than h, will be that AC less than CE.

![a.23](imgs/a.23.png)

[Video bookmark](https://www.youtube.com/watch?v=U_zcIgNNjbw&t=35m20s)

So, oops, OK. Ehh, next step, what does this follow from? Do we have a way to derive this? What does this follow from? Now have a look, if, ohh this is very funny, if x is larger than y and x prime is larger than y prime. What you are you willing to conclude? In general, x is larger than y and x prime is larger than y prime. Can you draw an obvious conclusion from that?

![a.24](imgs/a.24.png)

Yes, for instance, x plus x prime, is at least, I can even put at least here, yes. x plus x prime is at least y plus y prime.



![a.25](imgs/a.25.png)

![a.26](imgs/a.26.png)

Monotonicity of the addition. Write now down the **contrapositive** of this relation. x less than y or x prime less than y prime follows from x plus x prime less than y plus y prime.



![a.27](imgs/a.27.png)

And therefore, here you see the form of exactly this relation, and on account of monotonicity

![a.28](imgs/a.28.png)

this follows from AB + AC is less than BE + CE. OK.

![a.29](imgs/a.29.png)

So far so good. Now listen, we will, b and c are distances, so the minimum of them is at least 0, we have to demonstrate that that minimum is less than h, we can never prove that for h is 0, so we have to take into account something, some statement of the fact that h differs from 0.

[Video bookmark](https://www.youtube.com/watch?v=U_zcIgNNjbw&t=37m46s)

Now h differs from 0, tells us because the points A, B, and C are all different, h differs from 0 tells us that A [I think he meant "E" not "A" but I'm not sure] does not lie on q, but since E only occurs in connection with B and C, we now characterize the line q as the line through B and C, and h differs from 0 we now formulate as triangle E, B, C is not degenerate. But if triangle EBC is not degenerate, hence, BC is **actually** less BE plus EC.

# next read through, draw some examples.



![a.31](imgs/a.31.png)

![a.30](imgs/a.30.png)

![a.32](imgs/a.32.png)

[Video bookmark](https://www.youtube.com/watch?v=U_zcIgNNjbw&t=39m40s)

The **triangular inequality** that the sum of two sides is larger than the third side. [... audience member says something]. I don't know. I'm looking at this. And on account of **monotonicity** I conclude that this follows from AB plus AC is at most BC.

[COD Definition of monotonicity: "Of a function or quantity, varying in such a way that it either never decreases or never increases." So the plot goes up up up up .... forever, or down down down down, forever.]

[Wiki Definition of monotonicity: "In mathematics, a monotonic function is a function between ordered sets that **preserves** or reverses the given order. The concept first arose in calculus and was later generalized to the more abstract setting of order theory."]

![a.33](imgs/a.33.png)

Yah, from monotonicity, from this. Huh? But for this transformation replacing this by the smaller BC, I don't need to take A into account, you are rushing ahead, your conclusion is correct. Again, on account of the triangular inequality, AB plus AC is at least BC.

![a.34](imgs/a.34.png)

Hence this is equivalent to AB plus AC equals BC.

![a.35](imgs/a.35.png)

And these are all non-negative, all positive, distances and the only way in which this can be is if A lies between B and C. So we have concluded that it is OK with A between B and C.

![a.36](imgs/a.36.png)

Of course this is the only symmetric choice so it's not surprising. But what is charming is that, that fact, is forced upon us by the calculation that shows that the minimum of little b and c is less than h. **End of proof**.

Why is this very nice? You see, if you compare it with Kelly's proof that contains the same element, Kelly says, well, consider all, lines, and all possible combinations for q and E. All possible pairs of a line and a point not on that line. Finite collection, at least one such pair contains the **minimum** distance. And then he says well OK suppose that that, of course Kelly in 1948 proved it by a contradiction, so immediately he says, suppose that there are three points on the line q and then he derives a contradiction, we don't need to do that. Now, at the time, Kelly's introduction of the euclidian distance was greeted as a great invention, original idea that only a genius can have, because of course it is a foreign element because the problem statement itself has nothing to do with euclidian metric, its the, the theorem is a affine invariant. So it is a foreign element, but we know that given a program with a repetition we know that whereas the invariant of the repetition is uniquely determined by the program itself, the variant function, the decreasing thing that one invents to prove the termination argument, that's not determined at all, if you have some function "t" that decreases, any monotonic function of it will do it as well, of t, will do it as well. So we know, that if in arguments like that any inventiveness is required, it is at the choice of the variant function. Now I have taken extensive experiments with this problem at oral examinations and I have also shown this a number of times lecturing to an audience. At the critical moment, that the euclidian distance between q and E has to be invented. It has always been the audience that supplied this foreign body to the argument. In short, as soon as you regard this as a programming exercise, Kelly's invention becomes the most natural thing to do. So there has been progress. As a final mark of progress, I would like to read to you, because it's a little bit long to write down.

[Video bookmark](https://www.youtube.com/watch?v=U_zcIgNNjbw&t=46m14s)

Sylvester's original statement of the problem. And that will give you another aspect of progress in century of mathematics.

"Prove that it is not possible to arrange any finite number of real points, so that a right line through every two of them shall pass through a third unless they all lie on the same right line."

When I tried to read that I discovered that I couldn't, there were too many negations and unless's etc. And in utter despair finally I took the concise oxford dictionary, because I now wanted to know very precisely what "unless" means. Yah, I am a modest man and I am not afraid of going to the authorities. It was very illuminating because, the C.O.D. gives two meanings for unless, one is "if-not", now "if" is a follows from, and "not" is negation, this is or.


And the other one it gives is "except when". And if you start analyzing what "except when" means then you will come to not equivalent [≢]. So even the statement of, the theorem, is already ambiguous. Coxeter makes it worse in the sense that, he does not give, to begin with, the formulation of Sylvester, he gives his own definition, or statement of the theorem, but thereby he drops the requirement that the points are distinct, and then the theorem is false, you see, you can easily construct a counter example. OK that is what I wanted to say about how a once deep theorem, these days, is a trivial programming exercise. Any questions? "[D. Knuth?] Do you know of a corresponding three dimensional theorem?" Yes, yes, and that is, that depends on how you, generalize distinct points. One way of defining distinctness in the plane, is that any two points uniquely determine, the line through them. The generalization for three dimensions is that any three points, uniquely determine the plane through them. And then, what you then can do is take one point, project the other points in the plane, prove the theorem in the plane, and then restore the lines in the planes again. My guess is that Coxeter has missed that generalization, because he never took the trouble of stating explicitly that the points should be distinct, or he didn't care. I mean that's the other possibility. Yes, sir. "...". Untrained mathematicians find it very difficult, no not necessarily, the program is short, I think the correctness proof simple, but what is certainly true is that in general, a program is a very compact deposit of our intellectual labors, sure. Yes, sir. "...". Yes. Yes. Real euclidian plane. Yah. Finite number of points, each point is red or blue, there exists a line that contains more than one point of homogenous color. Ahh hah, ahh hah, yeah, OK. Its not an open it is a closed problem. OK well, I might try it, tonight in bed.

Well, thinking horizontally is a nice place. "...". No, same argument. Yea, yea, well, you use this step. You may use the implication in the other sense, in which it's very common. I find, there is another comment, the way in which we have an influence by our **education**. Everybody knows the monotonicity of the addition in this form.

[Video bookmark](https://www.youtube.com/watch?v=U_zcIgNNjbw&t=54m20s)

And immediately if you suggest this, you say well what can you conclude, people come up with the sum. To do it the other way around, it's just a form that we don't know it, it's logically equivalent. I find that a little bit frightening. OK. Thank you.

