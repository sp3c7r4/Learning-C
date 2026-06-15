# Pointers
Pointers are one of the most feared things in C and other Languages.

## Memory and Variables
Compuiter memeory holds data of all kinds, right? float's, int's etc. or whatever you have. Think of a computer memory like an array of bytes and it's indexes as address

A pointer is a variable that holds a memory address. Just like an int can hold the value `42` a pointer variable can hold the address of data

*Address-Of-Operator*
This happens to be an ampersand `&`. It let's us to grep the address of a value in memory.

*Note:* The pointer format specifier is denoted by `%p` we use it to print a pointer. But it will look like a garbage number E.g. Hexadecimal or Decimal.

- Example source code
```c
#include <stdio.h>

int main(void) {
    int i = 10;
    printf("The value of i is %d\n", i);
    printf("And its address is: %p\n", (void *)&i);

    /* Outputs
     * The value of i is 10
     * And its address is: 0x7fff9f6d2f04
     */
}
```
*Note:* The above code contains a `cast` where we coerce the type of the expression `&i` to be type `void*`. This is to keep the compiler from throwing a warning here

The hexadecimal is the memory index where the variable i's data is stored. It's the address, location or a pointer of i.

## Pointer Types
You can identify a pointer type because there's an asterisk `*` before the variable name and after it's type

```c
int main(void)
{
    int i;
    int *p; 
    /*
     * p's type is a "pointer to an int", or "int-pointer"
     * Means p can hold the address that points to other integrers. It can hold the address of other integers
    */
}
```

*Note:* When you do an assignment into a pointer variable, the type of the right hand side of the assignment has to be the same type as the pointer variable
```c
void main(void)
{
    int i;
    int *p;
    p = &i /* We're storing the address of the i variable in a pointer address */
}
```

## Dereferencing
When you have a pointer to a variable i.e. a reference to a variable, you can use the original variable through the pointer by _dereferencing_ the pointer.

```c
#include <stdio.h>
void main(void)
{
    int i;
    int *p; /* Created a pointer variable */

    p = &i; /* Stored i's location in the location storage */
    i = 10; /* Addigned 10 to i variable */

    *p = 20;/* Derefereced the value of i from the pointer variable */

    printf("The value of i is: %d!\n", i);
    printf("[Dereferenced] The value of is is: %d\n", *p);
}
```
*Whats a dereference operator?*
It's actually called the _indirection operator_, because you're accessing values indirectly via the pointer. We use the asterisk operator again `*`. This tells the compiler to _use the object the pointer points to_ instead of using the pointer itself. With that we've sort of turned *p into an alias of i.

## Passing pointers as Arguments.
The real power of pointers comes into play when you start passing them to functions.

- Example source code
```c
    #include <stdio.h>

    void increment(int *p) { /* Declares a pointer address */
        *p = *p + 1 /* Adds one to the thing p points to */
    }

    int main(void) {
        int i = 10;
        int *j = &i /* Using the Address-Of operator `&` we grabbed and stored the address of the variable i */

        printf("I is %d\n", i)
        printf("I is also %d\n", *j)

        increment(j);

        printf("i is %d\n", i); /** Prints 11 */
    }
```

## The null pointer
Any pointer variable of any pointer type can be set to a special value  called `NULL`. This indicates that this pointer doesn't point to anything.

```c
int *p;
p = NULL
```

*Note:* Since it doesn't point to a value, dereferencing it is undefined behavior, and will probably result in a crash.

## Note of declaring pointers
```c
int *p, q; /* P is a pointer variable, q is a normal integer variable */
int* p; /* Also Valid */
int *a, b, c, *d; /* Valid */
```
