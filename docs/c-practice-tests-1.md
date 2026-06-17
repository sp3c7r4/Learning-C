# C Fundamentals — Hardcore Practice Set (Pre-Structs Edition)

This set is built directly from your six notes files: intro, variables/statements,
functions, pointers, arrays, strings. The goal isn't to repeat what you already wrote
down — it's to stress-test it, find the gaps, and bolt on two small extra concepts
(pointer arithmetic, walking strings with a pointer) that your notes gesture at but
never fully spell out. Both follow directly from things you already know, so they
count as "deepening," not "skipping ahead."

**How to use this:** write, compile, and run every exercise yourself before reading
any hint. Hints are one line — they nudge, they don't solve. Parts 0 and 1 are
closed-ended (one correct answer), so they get a full answer key at the bottom. Parts
2–7 are open-ended coding exercises — there's no single "correct" implementation, so
no code solutions are given for those; if you want a solutions file to check your work
against afterward, just ask once you've attempted them.

---

## Part 0 — Debug Your Own Notes (Bonus Round)

Your uploaded files contain real, working examples — and a handful of broken or
flat-out wrong ones. Find them. Some are pure syntax errors, some are conceptual
errors disguised as comments. Both count.

**0.1 — From `arrays.md` (passing 2D arrays).** This function won't compile. Find
every error (there are at least four) and produce a working version.

```c
#include <stdio>

void print2DArray(int a[2][3])
{
    for (r = 0; r < 2; i++)
        for (c = 0; c < 3; c++)
            printf("(%d, %d) is %d", r, c, a[r][c]);
}

int main(void)
{
    int x[2][3] = {
        {1,2,3},
        {4,5,6}
    }
    print2DArray(x);
}
```

**0.2 — From `functions.md` (the `plusOne` example).** This also won't compile.
What's missing? While you're at it, check `main`'s return type against what the C
standard actually requires, not just what gcc tolerates.

```c
#include <stdio.h>
int plusOne(int n)
{
    return n + 1;
}

void main() {
    j = plusOne(1);
    printf("Adding 1: %d", j);
}
```

**0.3 — From `functions.md` (the `increment` example).** Spot the syntax error on
line one. Then — separately from the syntax — predict whether calling
`increment(i)` will actually change `i` afterward, and explain *why*, using the
vocabulary your own notes already gave you (parameter, pass by value).

```c
#include <stdio.h>;
void increment(int a) {
    a++; /* Post increment */
}

void main()
{
    int i = 1;
    increment(i);
    printf("The value of i is: %d\n", i);
}
```

**0.4 — From `pointers.md` (incrementing through a pointer).** Exactly four lines
in this snippet are missing a semicolon. Find all four.

```c
#include <stdio.h>

void increment(int *p) {
    *p = *p + 1

    int main(void) {
    int i = 10;
    int *j = &i

    printf("I is %d\n", i)
    printf("I is also %d\n", *j)

    increment(j);

    printf("i is %d\n", i);
}
```

> Note: I deliberately re-merged the snippet exactly as it reads in your file — the
> missing braces above are part of the puzzle too. While you're fixing semicolons,
> fix the structure as well.

**0.5 — From `strings.md` (string literal mutation).** Fix the typo and the missing
semicolons in both snippets below. Then explain why the first one crashes (or
invokes undefined behavior) while the second one, once fixed, works perfectly.

```c
chat *s = "Hello, World";
s[0] = 'z' // Error - Tried to mutate a string literal
```

```c
chat s[] = "Hello world";
s[0] = 'z' // zello world
```

**0.6 — From `variables-and-statements.md` (the conditional operators table).**
Two of these six comments describe the *wrong* operator. Which two, and what should
they actually say?

```c
a == b; // True if a is equal to b
a != b; // True if a is not equal to b
a < b;  // True if a is greater than b
a > b;  // True if a is less than b
a <= b; // True is a is less than or equal to b
a >= b; // True if a is greater than or equal to b;
```

Bonus part of 0.6: the same file also claims *"the numeric value of true is 0."*
That sentence is wrong on its own terms. What should it say, and does the `printf`
example two lines below it in your notes actually agree with the correct value or
the wrong one?

---

## Part 1 — Predict the Output

No compiler. Read each snippet, write down what it prints, *then* compile and check
yourself. Some of these will surprise you on purpose.

**P1**
```c
int x = 4;
int y = x++ + x++;
printf("%d %d\n", x, y);
```

**P2**
```c
int a, b = 5;
a = (b++, b * 2, b + 1);
printf("%d %d\n", a, b);
```

**P3**
```c
int flag = 5 == 5;
printf("%d\n", flag);
printf("%d\n", !flag);
printf("%d\n", !!10);
```

**P4**
```c
int x = 7;
printf("%d\n", x > 10 ? 1 : x > 5 ? 2 : 3);
```

**P5**
```c
int i = 10;
while (i < 5) {
    printf("while: %d\n", i);
    i++;
}
printf("while done, i=%d\n", i);

int j = 10;
do {
    printf("do-while: %d\n", j);
    j++;
} while (j < 5);
printf("do-while done, j=%d\n", j);
```

**P6**
```c
int n = 1;
switch (n) {
    case 0:
        printf("zero\n");
    case 1:
        printf("one\n");
    case 2:
        printf("two\n");
        break;
    default:
        printf("other\n");
}
```

**P7**
```c
void doubleIt(int n) {
    n = n * 2;
}

int main(void) {
    int x = 21;
    doubleIt(x);
    printf("%d\n", x);
}
```

**P8**
```c
int v = 5;
int *p1 = &v;
int *p2 = &v;
*p1 = 100;
printf("%d %d %d\n", v, *p1, *p2);
```

---

## Part 2 — Variables, Operators & Control Flow

**2.1 — Digit sum.** Given an int like `4937`, compute the sum of its digits
(4+9+3+7) using only `%` and `/` in a loop. No converting to a string.


*Hint: each pass, peel off the last digit with `% 10`, then shrink the number with `/= 10`.*

**2.2 — Ternary-only FizzBuzz.** Print Fizz/Buzz/FizzBuzz/the number for 1–30, but
the entire decision for each number must be a *single* expression made of nested
ternary operators feeding one `printf` per line — no `if`, no `else`, no `switch`.


*Hint: you'll need to nest three ternaries per number; decide divisible-by-15 first.*

**2.3 — Diamond of asterisks.** Print a diamond shape (not just a triangle) made of
`*` characters, for a given odd height like 7. This needs both expanding and
contracting nested loops, with correct leading-space padding.


*Hint: a diamond is a triangle that grows, then a triangle that shrinks — write the
growing half first and get it exactly right before touching the second half.*

**2.4 — Leap year, boolean-operators only.** A year is a leap year if divisible by
4, except century years, which must be divisible by 400. Write this as a single
boolean expression using only `&&`, `||`, and `%`, with no nested `if`.


*Hint: "divisible by 4 AND NOT divisible by 100, OR divisible by 400."*

**2.5 — Tiny calculator via switch.** Given two ints and an operator char (`+ - * / %`)
already sitting in variables, use a `switch` on the operator to print the result.
Include a `default` case for an unrecognized operator, and guard division/modulo
against a zero divisor instead of crashing.


*Hint: switch on a `char` works exactly like switching on an `int` — char is just a
small integer type.*

---

## Part 3 — Functions

**3.1 — The reset that doesn't reset.** Write `void reset(int x) { x = 0; }`. Call
it on a variable holding `99`, print the variable afterward, and explain in your own
words — using "parameter" and "copy" the way `functions.md` does — exactly why the
caller's variable is untouched.

**3.2 — `power` without `pow()`.** Write `int power(int base, int exp)`. Handle
`exp == 0` (returns 1) correctly. In a comment, explain why this function has no
sensible behavior for negative `exp` if it has to return an `int` — don't try to
"fix" it, just articulate the limitation.

**3.3 — Prototype discipline.** Write a program with three functions — `min`, `max`,
and `average` of three ints — where every function *body* appears physically after
`main()` in the file. `main()` must still be able to call all three. Declare proper
prototypes (with explicit `void` for any that take no arguments) before `main`,
exactly the way `functions.md` recommends.

**3.4 — Find the missing `void`.** Below are three function declarations. Some are
"bad practice" by your own notes' definition. Identify which, and fix them.
```c
int total();
void log_message();
int square(int n);
```
*Hint: an empty `()` parameter list disables a compiler safety net — which one, per
your notes?*

**3.5 — The multiple-return-value problem (a cliffhanger).** Write a function that
needs to hand back *both* the quotient and the remainder of two ints to its caller.
A C function returns exactly one value. Using only what `functions.md` taught you
(no pointers yet), what are your actual options, and why does every one of them feel
unsatisfying? Write your answer as a comment — you'll solve this for real in 4.2.

---

## Part 4 — Pointers

### New concept: pointer arithmetic

You already know `p = &a[0]` points at an array's first element. The missing piece:
`p + 1` doesn't mean "one byte further." It means "one *element* further" — the
compiler scales the offset by the size of whatever type `p` points to. This is the
actual mechanism behind array indexing: `a[i]` and `*(a + i)` are defined to mean the
exact same thing in C.

```c
int a[5] = {10, 20, 30, 40, 50};
int *p = a;                /* same as p = &a[0] */

printf("%d\n", *p);        /* 10 */
printf("%d\n", *(p + 1));  /* 20 */
printf("%d\n", a[2]);      /* 30 */
printf("%d\n", *(a + 2));  /* 30 — identical to a[2] */

p++;                       /* now points at a[1] */
printf("%d\n", *p);        /* 20 */
```

**4.1 — Swap.** Write `void swap(int *a, int *b)` that actually swaps the values of
two variables in the caller. Prove it works in `main` with a before/after printf.

**4.2 — Solve 3.5 for real.** Write
`void divmod(int a, int b, int *quotient, int *remainder)`. Call it from `main`,
passing addresses of two local variables, and print both results. This is the
pointer-based answer to the problem you wrestled with in 3.5 — confirm it actually
gives you two outputs from one call.

**4.3 — NULL-safe dereference.** Write `int safe_deref(int *p, int fallback)` that
returns `*p` if `p` is not `NULL`, and returns `fallback` otherwise, without ever
crashing. Test it with both a valid pointer and an explicit `NULL`.

**4.4 — Pointer-only array walk.** Given `int a[6] = {2,4,6,8,10,12};`, print every
element and the running sum using *only* pointer arithmetic (`p++` and/or
`*(p + i)`) — no `a[i]` syntax anywhere in the loop.

**4.5 — Uninitialized pointer hunt.**
```c
int *p;
printf("%d\n", *p);
```
What's wrong here? Why might this sometimes "work" and sometimes crash, depending on
the day, the machine, or the optimization level? How do you make this kind of bug
impossible using what you learned about `NULL`?

**4.6 — Pointers are passed by value too.** Write two tiny functions:
```c
void try_a(int *p) { p = p + 1; }
void try_b(int *p) { *p = *p + 1; }
```
Call each on `int arr[3] = {1,2,3}; int *q = arr;` and predict, *before running*,
whether `q` and `arr[0]` change after each call. This is the single most important
insight in this whole section — pointers themselves are ordinary local variables
that get copied on a function call, just like the `int` in Part 3.1 was.

---

## Part 5 — Arrays

**5.1 — Reverse in place.** Reverse an `int` array with no second array — swap
elements from the outside in.

**5.2 — Max and second-max in one pass.** Find the largest and second-largest
values in a single loop (no sorting, no two separate passes). Decide deliberately
what happens if the two largest values are equal, and document your choice in a
comment.

**5.3 — Bubble sort.** Implement `void bubble_sort(int *a, int len)`, ascending.
Print the array before and after sorting in `main`.

**5.4 — Remove duplicates from a sorted array.** Given an already-sorted array,
compact out duplicate values in place and return the new logical length from the
function. Print only that many elements afterward.
*Hint: keep a "write index" that only advances when you see a genuinely new value.*

**5.5 — Transpose a 3×3 matrix.** Swap `a[i][j]` with `a[j][i]` for a 2D array,
in place.

**5.6 — Matrix multiply.** Multiply a 2×3 matrix by a 3×2 matrix to produce a 2×2
result, with all three matrices passed into a function as parameters.

**5.7 — The `sizeof` trap.** Write `void show_size(int arr[])` that prints
`sizeof(arr)` inside the function. In `main`, print `sizeof` of the same array
*before* passing it in. Predict whether the two numbers will match *before* you run
it — then explain the mismatch using the exact reasoning your `arrays.md` notes
already give about arrays decaying to pointers when passed to functions.

---

## Part 6 — Strings

### New concept: walking a string with a pointer

Your notes already established that every C string ends with a hidden `\0`. That
means you can walk a `char *` forward and stop the instant you see that byte —
without ever needing to know the length up front.

```c
char *s = "Hi!";
while (*s != '\0') {
    printf("%c\n", *s);
    s++;
}
```

`s` itself gets modified here, but only the local copy of the pointer — exactly the
same pass-by-value rule from 4.6 applies to `char *` as it does to `int *`.

**6.1 — `my_strlen`, the pointer-only version.** Your notes already show a
`my_strlen` using array indexing. Rewrite it using *only* pointer walking
(`*s != '\0'`, `s++`) — no `[]` anywhere. Then write a second variant,
`my_strlen_ptrdiff`, that finds the `\0` the same way but computes the length by
subtracting the start pointer from the end pointer once you find it.

**6.2 — `my_strcpy` from scratch.** Implement `void my_strcpy(char *dest, char *src)`.
Make sure `dest` ends up properly NUL-terminated — this is the bug that bites
almost everyone the first time.

**6.3 — `my_strcmp` from scratch.** Implement `int my_strcmp(char *a, char *b)`
returning negative, zero, or positive the way the real `strcmp` does, comparing
character by character.

**6.4 — Palindrome check.** Write `int is_palindrome(char *s)` using two pointers
(or two indices) walking toward each other from both ends. Exact character match
only — case-folding is an optional stretch goal, not the base requirement.

**6.5 — Reverse a string in place.** This *must* be declared as a mutable array
(`char s[] = "..."`), never a `char *` pointing at a literal — tie this back to the
crash you explained in 0.5. Reverse it with a two-pointer (or two-index) swap, no
second buffer.

**6.6 — `my_strstr`.** Implement
`char *my_strstr(char *haystack, char *needle)` returning a pointer to the first
match, or `NULL` if `needle` never occurs. This is genuinely hard — it needs a
nested loop with an early exit, and the `NULL` return ties directly back to 4.3.

---

## Part 7 — Capstone Challenges (the bridge to structs)

**7.1 — Parallel Arrays of Pain.** Track up to 10 students using three *separate*
parallel arrays — `char *names[10]`, `int ages[10]`, `float grades[10]` — plus an
`int count`. Write `add_student(...)`, `print_all(...)`, and
`int index_of_top_student(...)`. Every function that needs "one student's data" has
to take three or more separate parameters by hand, every single time. When you're
done, write a comment listing every place you had to keep three arrays in sync
manually, and what breaks if you update one array's slot but forget the other two.
This exercise is supposed to hurt a little — that's the point.

**7.2 — Letter histogram.** Take a hardcoded sentence, tally how often each
lowercase letter appears into `int counts[26]`, then print a horizontal bar chart
using rows of `*` characters — using nothing but tools from Parts 1–6.

**7.3 — Caesar cipher.** Write `void caesar_encrypt(char *s, int shift)` that
mutates a string array in place, wrapping `z` back around to `a` correctly, and
leaving spaces/punctuation untouched. Combines char arithmetic, array mutation,
pointers, and modulo in one function.

**7.4 — (Hardest, optional) `my_atoi` and `my_itoa`.** Write
`int my_atoi(char *s)` and `void my_itoa(int n, char *out)` from scratch, both
handling negative numbers, using only char arithmetic (`'0' + digit`), `%`/`/`,
pointer or array walking, and correct NUL-termination of the output buffer. If you
can get both of these working cleanly, you've genuinely earned the move to structs.

---

## Answer Key — Parts 0 & 1 Only

*(Parts 2–7 are open-ended; there's no single correct implementation to key against.
Compile, test against edge cases you choose yourself, and ask if you want a
companion solutions file to compare against afterward.)*

### Part 0

**0.1** — `<stdio>` → `<stdio.h>`. `r` and `c` were never declared (`int r, c;`
needed). The outer loop incremented an undeclared `i` instead of `r`. The array
initializer in `main` was missing its closing semicolon. Fixed:
```c
#include <stdio.h>

void print2DArray(int a[2][3])
{
    int r, c;
    for (r = 0; r < 2; r++) {
        for (c = 0; c < 3; c++) {
            printf("(%d, %d) is %d\n", r, c, a[r][c]);
        }
    }
}

int main(void)
{
    int x[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    print2DArray(x);
    return 0;
}
```

**0.2** — `j` was never declared. `void main()` is non-standard; the C standard
requires `int main(void)` returning an `int`. gcc tolerates `void main` as an
extension, but it's not portable and stricter compilers reject it outright.
```c
int main(void)
{
    int j;
    j = plusOne(1);
    printf("Adding 1: %d\n", j);
    return 0;
}
```

**0.3** — The stray `;` right after `#include <stdio.h>` is the syntax error.
Separately: `increment(i)` does **not** change `i` in `main`, because `a` inside
`increment` is a parameter — a fresh local copy of whatever value was passed in.
Incrementing `a` only changes that copy. Output is `The value of i is: 1`.

**0.4** — The four lines missing semicolons: `*p = *p + 1`, `int *j = &i`,
`printf("I is %d\n", i)`, and `printf("I is also %d\n", *j)`.

**0.5** — `chat` → `char` in both, plus a semicolon after each `s[0] = 'z'`. The
first crashes (or is undefined behavior) because `s` there is a pointer into the
string *literal*, which typically lives in read-only memory — writing through it is
illegal. The second works because declaring `s` as an array gives you your own
private, writable copy of those bytes; there's no read-only memory involved.

**0.6** — The `<` and `>` comments are swapped: `a < b` should read "True if a is
**less than** b," and `a > b` should read "True if a is **greater than** b." Separately,
"the numeric value of true is 0" is backwards — false is 0, true is 1. The `printf`
example two lines below it (`true == 12` prints `0`) is actually consistent with the
*correct* value (1 == 12 is false), so only the prose statement was wrong, not the
code beneath it.

### Part 1

- **P1:** This is undefined behavior — `x` is modified twice (`x++` and `x++`)
  with no sequence point between the two side effects, which C's standard
  explicitly disallows relying on. `x` ends up incremented twice (becomes `6`), but
  the value used for `y` depends on an order of evaluation the compiler is free to
  choose. Different compilers (or optimization levels) may legitimately print
  different things. The lesson: never modify the same variable more than once in one
  expression without a sequence point between the modifications.
- **P2:** `7 6`. Unlike P1, the comma *operator* (not commas between function
  arguments) guarantees left-to-right sequencing. `b++` runs first (b becomes 6,
  expression value 5 discarded), then `b * 2` evaluates with the updated `b` (12,
  discarded), then `b + 1` evaluates with `b` still 6, giving `7`, which becomes `a`.
- **P3:** `1`, `0`, `1`.
- **P4:** `2`.
- **P5:**
  ```
  while done, i=10
  do-while: 10
  do-while done, j=11
  ```
  The `while` loop's condition is false from the start, so the body never runs at
  all. The `do-while` body always runs once regardless of the condition.
- **P6:** `one` then `two`. Execution jumps straight to the `case 1:` label
  (skipping `case 0`'s `printf` entirely), then falls through into `case 2` because
  `case 1` has no `break`, and stops at `case 2`'s `break`.
- **P7:** `21`. `n` inside `doubleIt` is a local copy; multiplying it never touches
  `x` in `main`.
- **P8:** `100 100 100`. Both pointers hold the address of the same `v`, so writing
  through either one is writing to that one shared memory location.

---

## What's next

Once 7.1 has made parallel arrays feel genuinely annoying to keep in sync, you're in
exactly the right frame of mind for structs — they exist specifically to bundle a
student's name, age, and grade into one unit instead of three arrays you have to
update by hand together. That's the next file to write notes on.
