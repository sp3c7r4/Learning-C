# Variables and Statements

## Variables
Variables hold values. It's a human readable name that refers to some data in the memory.

Think of the memory as a big array of bytes. Data is stored in this array. If a number is larger than a single byte, it's stored in multiple bytes.

Because a memory is like an array, Each byte stored in the memory can be referred to by its index. THe index in a memory is called an address or a location or a pointer.

When you have a variable in C, the value of that variable is in memory somewhere, at some address, But it's pain to refer to a value by its numberic addresss. Instead we give the numeric address a name that's what a variable is

Pointer variables - They're variables that hold the address of other variables

## Variable Names
Rules of naming a variable
- You can't start with a number E.g `1S` 
- You can't start a varaible with double underscores E.g. `__S`
- You can't start a varaible name with an underscore followed by a capital A-Z E.g `_A`

## Variable Types
All variable types evolve arund this 4 Types
Type                | Example         | C Type
Integer             | 3490            | int
Floating Point      | 3.490           | float
Character (Single)  | 'c'             | char
String              | "Hello, World!" | char *

Before you can use a variable you have to declare thay variable and tell C wat type the variable holds, Once declared the type of the varible cannot be changed later at runtime.

- Example code
```c
#include <stdio.h>

int main() 
{
    /* This is a function declaration, they're both uninitialized. It's when we define them we've assinged a value or data to the variable. */
    int i;    // Holds signed integers: -1, +4, 0, 10
    float f;  // Holds signed floating point numbers E.g. -3.1416

    printf("Hello, World!\n"); 
}
```

Declaration - Occurs when we've initialized a `named` storage address in memory but we've not assigned a value to it E.g. 
```c
int count; // We created a storage i.e. 0xjsjsjsjjs[gave the address a name of count] but we didn't store anything in the storage
```
Definition - Occurs when we declare and assign a value to it directly/store data in the storage address E.g
```c
int i;

i = 2;
```

## Printing a value in c
What we'll do is to pass in two arguments to the `printf()` function. THe first argument is a string that describes what to print and how to print it(called the _format string_), and the secnd is the value to print

printf hunts through the format string for a variety of special sequences that start with the `%` sign and tell's it what to print. For example, if it finds a `%d`, it looks to the next parameter that was passed and outputs it as an integer. If it finds a `%f`, it prints the value out as a float and if it finds a %s, it prints a string

- Example source code 
```c
#include <stdio.h>

int main(void)
{
    int i = 2;
    float f = 3.142;
    char *s = "Hello, world!"; //char * ("char pointer") is the string type in c

    printf("%s i = %d and f = %f!\n", s, i, f)
}
```

## Boolean Data Types

C does have a boolan data type; true or false ?
Historically it doesn't have a Boolean type and some might still argue it still doesn't 
In C 0 meand `false` and non-zero means `true`

- Example source code
```c
int x = 1;
if (x) {
    printf("x is ture!\n");
}

/* Outputs X is true */
```

But in C23 you get actuall `bool` type with `true` and `false`. But before that you'll have to include 
`#include <stdbool.h>` - Which is not needed in c23

- Example Source code
```c
#include <stdio.h>
#include <stdbool.h> /* Not needed in c23 anymore */

int main(void)
{
    bool x = true;
    if (x) {
        printf("X is true!\n");
    }
}
```

*Note:* The numeric value of true is 0
```c
printf("%d\n", true == 12); // Prints "0", false!
```

## Operators and Expressions
Arithmetic
```c
    i = i + 3; // Addition (+) and Assignment (=) operators, add 3 to i
    i = i - 3; // Subtraction, Subtract from the initial operand i
    i = i * 9; // Multiplication
    i = i / 2; // Division
    i = i % 5; // Modulo (Division Remainder)

    /** Shorthand Variants */
    i += 3;
    i -= 8;
    i *= 9;
    i /= 2;
    i %= 5;

    // No exponentiation you'll have to use the `pow()` function from `math.h`
```

### Ternary Operators
- This is an expression whose value depends on the result of a conditional embedded in it.
```c
    /** If x > 10 add 17 to y. Otherwise add 37 to y */
    y += x > 10 ? 17 : 37;

    // What a mess let's try that with if Statements
    if (x > 10)
        y += 17;
    else
        y += 37;

    /** Another Example */
    printf("The number %d is %s.\n", x, x % 2 == 0 ? "even" : "odd");
```

### Pre and Post Increment and Decement
Pre increment&decrement - The value of the variable is incremented before the expression is evaluated.
Post increment&decrement - The expresion is evaluated before the value of the variable is increased

```c
/* Pre */
    int i = 10;
    int j = 5 + ++i;

    printf("%d, %d!", i, j); // 11, 16!
/* Post */
    int i = 10;
    int j = 5 + i++;
    
    printf("%d, %d!", i, j); // 11, 15!
```

### The comma operator
