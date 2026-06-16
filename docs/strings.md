# Strings Literals
These are sequence of characters in double quotes E.g. "Hello, World!"

# String variables

```c
char *s = "Hello, world!";

printf("%s\n", s) // "Hello, world!"
```

## String Variables as Arrays
```c
/* Other equivalent to the above char * usage*/
char s[14] = "Hello, World!";
char s[] = "Hello, World!";
```
*Note:* We can use array notations to access characters in a string

Printing a single character we use `%c`

```c
void main(void)
{
    char *s = "Hello, world!";
    //char s[] = "Hello, world!"; // Same

    for (int i = 0; i < 13; i++)
        printf("%c", s[i]);
    printf("\n");
}
```

## String Initializers
```c
char *c = "Hello, World!";
char t[] = "Hello, World!";
```
The pointer form points to whereever that string was placed. A place far away from the proogram's memory(read-only memory) for performance and safety reasons

So if we try to mutate that string
```c
chat *s = "Hello, World";
s[0] = 'z' // Error - Tried to mutate a string literal
```
Pointing at a string literal gives you read only memory

But by declaring it in an array is different. The compiler doesn't show those bytes in another part of town, they're right down the street. This one is a mutable copy of the string - one we can change at will
```c
chat s[] = "Hello world";
s[0] = 'z' // zello world
```
While declaring an array gives you your own private, writeable copy

Easier workaround
```c
/* Using a heap memory */
char *c = malloc(6); strcpy(c, "hello")
```

## Getting string length
```c
#include <stdio.h>
#include <string.h>

int main(void)
{
    char *s = "Hello, World!";
    printf("The string is %zu bytes long.\n", strlen(s));
    /* The string is 13 bytes long. */
}
```

*Note:* Like we said earlier C doesn't track length of variables. But there's a specific function in string.h called `strlen(<string>)` that returns the _format specifier_ of size_t of `sizeof()` function. which does the string length computation for us.

## String Termination
When you're making a new language, you have two options for storing a string in memory.
-  Store the bytes of the string along with a number indicating the length of the string
- Store the bytes of the string, and mark the end of the string with a special byte called the _terminator_
In C a string is defined by two basic characteristics
  + A pointer to the first character in the string.
  + A zero-valued byte(NUL character) somewhere in memory after the pointer that indicates the end of the string.
*Note:* A `NUL` character can be writeen in C code as `\0`. When you include a string in double quotes in your code, the `NUL` character is automatically, implicitly included.

```c
char *s = "Hello!"; /* Hello!\0 behind the scenes*/
```

- Example source code
```c
/* Let's write our own strlen() */

int my_strlen(char *s) {
    int count = 0;

    while(s[count] != '\0')
        count++;

    return count;
}

int main(void)
{
    char *string = "Hello, World!";
    int len = my_strlen(string);

    printf("The string length is: %d", len);
}
```

## Copying a string
You can't sopy a string using the `=` assignment operator. All you're just doing is duplicating the pointer to the first character.

instead we use the `strcpy(<destination>, <string>)`

```c
#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[] = "Hello, World!"; 
    char t[100]; /* Each character is one byte, so plenty of room */

    /* This makes a copy of a string */
    strcpy(t, s);

    /* We modify it */
    t[0] = 'z';

    /* And s remains unaffected */
    printf("%s\n",s); // Hello, World!

    // But t has been changed to zello, World!
    printf("%s\n", t); // "zello, world!"
}
```
