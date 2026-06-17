# Functions
Functions can accept a variety of arguments and return a value.
Though the arguments and return value types are predeclared - That's how C likes it 

- Example source code 
```c
    #include <stdio.h>
    int plusOne(int n)
    {
        return n + 1;
    }
    
    int main(void) 
    {
        int j = plusOne(1);
        printf("Adding 1: %d", j);
    }
```

*Note:* Things to take note of
- The `int` before the plusOne indicates the return type
- The `int n` indicates this function takes one integer argument stored in parameter `n`
- `plusOne(1)` - Here we're calling the function with an argument of `1`
-

Parameter: This is a special type of local variable into which arguments are copied
## Passing by value
If an argument is a variable and it's passed into a function. The value get's copied as the argument and the expression is evaluated leaving the original value remaining unmodified.

```c
#include <stdio.h>
void increment(int a) {
    a++; /* Post increment */
}

int main(void)
{
    int i = 1;
    increment(i);
    printf("The value of i is: %d\n", i);
}
```

## Function Prototypes
You can notify the compiler in advance that you'll be using a function of a certain type that has a certain parameter list. That way the function can be defined anywhere (even in a different file), as long as the _function prototype_ has been declared before you call that function.

- Example source code
```c
#include <stdio.h>

int foo(void); /* This is a function protype */

int main(void)
{
    int i;
    i = foo();

    printf("%d\n", i);
}

int foo(void) {
    return 3490;
}
```

## Empty parameter Lists
Don't ever code with an empty parameter list. Always use void to indicate the fucntion takes no parameter

```c
void foo() {} // Bad
void foo(void) {} // Good practice
```

*Note:* While defining a prototype always use the `void` type in the parameter list to indicate no parameters will be expected. Why are we doing this? Good question! So in order to have our type checkings in check if we leave it out it will disable the type checks for us and we'll not be able to debug properly
