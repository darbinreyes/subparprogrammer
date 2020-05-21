// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED

#include <stdio.h> // NULL
#include "realq2.h"

/*
******* Original Scratch work.

 cut films into scenes = take a video file, and break it up in smaller video files, break up at points in the video called scenes.
automate - breaking up - individual shots
individual shots = short video, from a particular camera angle.
break up _individual shots_ into _scenes_
scenes = a _sequence of shots_
given helper function - film.breakup_into_shots_and_letter_label().
duplicate shots get the same letter label.

todo - partition(sequence_of_labels) into scenes.
in a scene, no shot labels appear in more than 1 scene. ??? // I don't understand this.

Output scene.length for each scene.

******* Output

WTF is up with that struct def. its formated all wonKy!

Most of the work here is figuring out what the problem statement means.

*/

/*

******* Scratch Work

film, broken up into shots and labeled.

given - an array of letters - each letter is a label for a shot - same label = same shot.

do - partition the array of labels into scenes, no shot labels appear in more than one scene.

output - length of each scene.

******** Input

array of characters container letters.

******* Output

array of integers - element = length of scene.
in the order "in which it appears in the sequence of shots"

******* Example 1:
Input:
inputList=

{'a','b','a','b','c','b','a','c','a','d','e','f','e','g','d','e','h','i','j','h','k','l','i','j'}

[
0 a
1 b
2  a
3   b
4 c
5 b
6  a
7 c
8 a
9  d
10   e
11 f
12 e
13  g
14   d
15 e
16 h
17  i
18   j
19 h
20 k
21  l
22   i
23    j
] // Remark: Length = 24

Output:
[9,7,8]

Explanation:
1st scene - shots a b c
2nd scene - shots d e f g
3rd scene - shots h i j k

9, 7, 8
because a b c only appear in the first 9 chars
d e f g appear in the NEXT 7 chars
last 8 chars consists entirely of h i j k

// Remark: 9 + 7 + 8 = 16 + 8 = 24 = length of inputList.


******* Example 2:
Input:
inputList=
{'a','b','c'}
[
0 a
1 b
2 c
] // Length = 3

Output:
[1,1,1]

Explanation:
Because no shot label occurs more than once, all shots can be in a length 1 subsequence.

******* Example 3:
Input:
inputList=
{'a','b','c','a'}
[
0 a
1 b
2 c
3 a
] // Length = 4

Output:
[4]

Explanation:
'a' occurs more than once, everything between first and last appearance of 'a'
must be in the same list.

*/

/*
******* Scratch Work

*******

inputList=
  0   1   2   3
{'a','b','c','a'}
// Can I compute the answer given first occurrence + last occurrence for each letter.
// first we need to identify the individual letters that occur.
{a,b,c} // individual letters
{0,1,2}// first occurrence
{3,1,2}// last occurrence
{3,0,0}// last - first
{4,1,1}// last - first + 1 = sublen

Output:
[4]

*******

inputList
  0   1   2
{'a','b','c'}

{a,b,c} // individual letters
{0,1,2}// first occurrence
{0,1,2}// last occurrence
{0,0,0} // last - first
{1,1,1} // last - first + 1 = sublen

Output:
[1,1,1]

*******

inputList=
  0   1   2   3   4   5   6   7   8   9   10
{'a','b','a','b','c','b','a','c','a','d','e',

 11  12  13  14  15  16  17  18  19  20  21  22  23
'f','e','g','d','e','h','i','j','h','k','l','i','j'}

{a,b,c,d,e, f, g, h, i, j, k, l} // individual letters
{0,1,4,9,10,11,13,16,17,18,20,21}// first occurrence

{a,b,c,d, e, f, g, h, i, j, k, l} // individual letters
{8,5,7,14,15,11,13,19,22,23,20,21}// last occurrence

{8,4,3,5 ,5, 0, 0, 3, 5, 5, 0, 0} // last occurrence minus first occurrence. Where this array == 0, we need not worry about the letter occurring more than once.

d = l - f // diff = last - first

f + d = l // first + diff = last

d + 1 = length of subsequence containing all occurrence of a letter.
d + 1 // diff + 1 = sublen

{9,5,4,6 ,6, 1, 1, 4, 6, 6, 1, 1} // sublen = last occurrence minus first occurrence + 1.

Output:
[9,7,8]
"because a b c only appear in the first 9 chars
d e f g appear in the NEXT 7 chars
last 8 chars consists entirely of h i j k"

******* Observations

The sum of the output array == length of inputList.
any adjacent letters that occur only once (l - f == 0) can be grouped into the same scene

Let us consider the largest subsequence, max(sublen)
'a' // letter
 9 // sublen
 0 // first
 8 // last

 Let us do the obvious, create a subset
 starting at a.first == 0
 ending at a.last == 8
 a.sublen == 9.

 The next largest subsequence is 6
 (note there is more than one letter with this subsequence
  length) let us take the first, which is 'd'
  'd' // letter
  6  // sublen
  9  // first
  14 // last

Let us now say that we will merge the current subsequence
with the previous subsequence if there is any overlap.
// pseudo code for overlap test.

prev_subsequence
current_subsequence

if prev_subsequence.first <= current_subsequence.first
    lower_subsequence = prev_subsequence
    upper_subsequence = current_subsequence
else
    lower_subsequence = current_subsequence
    upper_subsequence = prev_subsequence

// lower_subsequence is the subsequence that starts at the lesser index.
// upper_subsequence is the subsequence that starts at the greater index.

// Note all subsequences have length >= 1

// ways the sequences can overlap
// 1. they are the same.
lower.start == upper.start && lower.end == upper.end

*---*
*---*

// 2. partial overlap
upper.start > lower.start && upper.start < lower.end

*---*
  *---*

// 3. single point overlap
*---*
    *---*

// 4. no overlap
*---*
        *---*

// They certainly don't overlap if
if(upper.start > lower.end) {
    // no overlap
    // let this be a new subsequence.
    new_subsequence.start = current_subsequence.start
    new_subsequence.end = current_subsequence.end
    subsequences.append(new_subsequence)
}
else {
    //yes overlap
    // merge upper and lower into a single subsequence.
    prev_subsequence.start = lower.start
    prev_subsequence.end = MAX(upper.end, lower.end); // !!! max is essential here.
}

// Move on to the next largest subsequence and repeat above until every subsequence length has been processed

// By inspection, this solves Example 2.

*/

/*
******* Scratch Work

******* Does above work on this input?

inputList=
  0   1   2   3
{'a','b','c','a'}
// Can I compute the answer given first occurrence + last occurrence for each letter.
// first we need to identify the individual letters that occur.
{a,b,c} // individual letters
{0,1,2}// first occurrence
{3,1,2}// last occurrence
{3,0,0}// last - first
{4,1,1}// last - first + 1 = sublen

Output:
[4]

*******
largest subsequence length = 4, corresponding to letter 'a'.
subsequences = []
prev_subsequence = NULL.
current_subsequence.start = first['a'] = 0
current_subsequence.end = last['a'] = 3

subsequences.append(current_subsequence)
prev_subsequence = current_subsequence

current_subsequence = next largest subsequence length, resolving duplicates by lower index. In this case 'b'.
current_subsequence.start = first['b'] = 1
current_subsequence.end = last['b'] = 1

if prev_subsequence.first <= current_subsequence.first // 0 <= 1 // true
    lower = prev_subsequence , 0, 3
    upper = current_subsequence , 1, 1

if(upper.start > lower.end) { // 1 > 3 // false
  // no overlap
else
  // yes overlap
  // merge upper and lower
  prev_subsequence.start = lower.start = 0
  prev_subsequence.end = max(upper.end, lower.end) = max(1, 3) = 3 // !!! max is essential here.

current_subsequence = next largest subsequence length, resolving duplicates by lower index. In this case 'c'.
current_subsequence.start = first['c'] = 2
current_subsequence.end = last['c'] = 2

if prev_subsequence.first <= current_subsequence.first // "first:=start" // 0 <= 2 // true
    lower = prev_subsequence , 0, 3
    upper = current_subsequence , 2, 2

if(upper.start > lower.end) { // 2 > 3 // false
  // no overlap
else
  // yes overlap
  // merge upper and lower
  prev_subsequence.start = lower.start = 0
  prev_subsequence.end = max(upper.end, lower.end) = max(2, 3) = 3

DONE!
And we have terminated with subsequences = [{0,3}] which we can transform
into the desired output format by converting the range into a length

output = []
for subsequence in subsequences
  output.append(subsequence.end - subsequence.start + 1)

return output; // As an extra correctness check note that sum([4]) == len(inputList) == len({'a','b','c','a'}) ==4

*/

// FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
boundedarray* lengthEachScene(charboundedarray* inputList)
{
    // WRITE YOUR CODE HERE
    return NULL;
}
// FUNCTION SIGNATURE ENDS