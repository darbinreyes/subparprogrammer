// Implement itoa()
// input = 123, output = "123"
// input = 235, output = "235"
// input = -13, output = "-13"
// input = 0, output = "0"

#include <stdio.h>

void reverse_str(char *s) {
  char *e;
  char t;

  if(s == NULL){
    return;
  }

  if(*s == '\0'){
    return; // empty string.
  }

  e = s;

  while(*e != '\0') {
    e++; // find the end of the string
  }

  // back up one char.
  e--;

  while(s < e) {
    t = *s; // swap chars
    *s = *e;
    *e = t;
    s++; // advance pointers.
    e--;
  }

  return;
}
// returns 0 if successful, != 0 on error.
int myitoa(char *s, int i) {
  // Precondition: s points to a buffer sufficiently large to store the string
  // representation of i.
  char c;
  char *t;

  t = s;

  if(s == NULL) {
    return 1;
  }

  if(i < 0) {
    // If i is negative, add a sign char, and make i positive to prepare for
    // the conversion to a string.
    i = -i;
    *s = '-';
    s++;
  }

  if(i == 0) {
    *s = '0';
    s++;
  } else {
    while(i > 0) {
      // Extract the right-most digit.
      // i = 10, 10%10 = 0, ok.
      //  i = 11, 11 % 10 = 1, ok.
      // i = 9, 9 % 10 = 9, ok.
      c = '0' + (i % 10);
      *s = c;
      s++;
      i /= 10;
    }
  }

  // TODO: NULL terminate s.
  *s = '\0';

  // TODO: reverse s.

  if(*t == '-') {
    reverse_str(t + 1);
  } else {
    reverse_str(t);
  }

  return 0;
}

// Is it possible to implement this without reversing the string at the end.

/*

 i = 123
 123 / 100 = 1
 1 % 10 = 1

 123 / 10 = 12
 12 % 10 = 2

 123 / 1 = 123
 123 % 10 = 3

 ANS: Yes, if I am given the value of the left-most digit place, i.e. for 123 the "1" has a value of 100.

*/
/*

 How to compute the value of the left-most digit place if it is not given?
i = 123
power = 1;
t = i
while(t > 0){
  t /= power;
  power *= 10;
}
// expect power = 100
123 > 0
t = 123 / 1
power = 1 * 10 = 10

123 > 0
t = 123 / 10 = 12
power = 10 * 10 = 100;

12 > 0
t = 12 / 100 = 0
power = 1000;

0 > 0. Done. WRONG!
///////
i = 123
power = 1
while(i / power > 0) {
  power *= 10;
}

123 / 1 = 123
123 > 0
power = 1 * 10 = 10

123 / 10 = 12
12 > 0
power = 10 * 10 = 100

123 / 100 = 1
1 > 0
power = 100 * 10 = 1000 // WRONG!

// FIX - change the guard of the while loop.

while(i / power > 1) {
  power *= 10;
}
*/
int myitoav2(char *s, int i, int power) {

  if(s == NULL) {
    return 1;
  }

  if(i == 0) { // Handle case i == 0
    *s = '0';
    s++;
    *s = '\0';
    return 0;
  }

  if(i < 0) { // Handle case negative i.
    *s = '-';
    s++;
    i = -i;
  }

  while(power > 0) {
    *s = '0' + (i/power) % 10;
    s++;
    power /= 10;
  }

  *s = '\0';

  return 0;
}

int myitoav3(char *s, int i) {
  int power;
  int t;
  t = i;
  power = 1;

  if(t < 0) {
    t = -t;
  }

  while(t / power > 1) {
    power *= 10;
  }

  return myitoav2(s, i, power);
}

int main(void) {
  int i;
  char s[100];

  i = -1;
  myitoa(s, i);
  printf("i = %d, s = %s\n", i, s);

  i = 123;
  myitoa(s, i);
  printf("i = %d, s = %s\n", i, s);

  i = -13;
  myitoa(s, i);
  printf("i = %d, s = %s\n", i, s);

  i = 0;
  myitoa(s, i);
  printf("i = %d, s = %s\n", i, s);

  // v2

  i = 123;
  myitoav2(s, i, 100);
  printf("v2. i = %d, s = %s\n", i, s);

  i = -13;
  myitoav2(s, i, 10);
  printf("v2. i = %d, s = %s\n", i, s);

  i = 7;
  myitoav2(s, i, 1);
  printf("v2. i = %d, s = %s\n", i, s);

  // v3

  i = 123;
  myitoav3(s, i);
  printf("v3. i = %d, s = %s\n", i, s);

  i = -13;
  myitoav3(s, i);
  printf("v3. i = %d, s = %s\n", i, s);

  i = 7;
  myitoav3(s, i);
  printf("v3. i = %d, s = %s\n", i, s);
  return 0;
}