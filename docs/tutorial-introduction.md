# What to expect from C

C is a low level language. Compared to the languages we have tday that has abstracted most of the implementations of C. C inspired Go, Rust, Python etc.

## Hello, World!
Anything between the digraphs `/**/` is called a Comment and it will be completely ignored by the compiler. Same goes for anythin after `//`

`#include` - This tells the c preprocessor to pull the contents of another file and insert it into the code we added it to

## C Preprocessor
There are two stages to compilation
The preprocessor - The preprocessor operations on anything that starts with the octothorpe `#` symbol. Commmon preprocessor directives are `#include` & `#define`
The complier - After the preprocessor is done the results are ready for the compiler to maybe produce the assembly code & machine code
Machine Code- This is what the cpu of a system/machine understands

`<stdio.h>` - This is known as the header file. The dot-h at the end gave it all 😂. It's the "Standard I/O" header file that we'll grow to know and love and it gives us access to a bunch of I/O functionality

`printf()` - This function allows us to output a string to the shell/terminal. So needing access to this fuunction requires us to import the Standard I/O header file which gives us access to a bunch of tools.

So how do we know we need to include the `#include <stdio.h>` for `printf()`

`main()` - This is definition of the function main; everything in between the squirelly braces `{}` is part of the function. It's called the function body. This is the function that will be called automatically when your program starts executing. Nothing of your get's called before the function main. When the function main finishes executing meaning getting pass the `}` closing squirelly brace the program will exit and you'll be back on your shell. So calling a function like the `printf(...);` doesn't include the body i.e. `+{}`

## Running a c program
- Compilation - This generates an executable object file that's ready to load into memory and get's executed by the cpu
```bash
$ gcc -o <output> <file.c> // E.g gcc -o hello hello.c
```
- Execution
```bash
$ ./hello
```

- Source code example
```c
#include <stdio.h> /* Includeing the Standard input/output Header file */
int main() /* Declaring a function name `main` which will be returning an integer i.e. number */
{
    printf("Hello, World!\n") /* Calling a function from the stdio header file named printf to output the `Hello, World\n` string with a newline `\n` */
}
```

## Compilation Details
Compilation is the pocess of taking a c source code and converting it into a program that's ready to be loaded into memory so that your operating system can execute.

When compiling C _machine code_ is generated. This is the 1s and 0s that can be executed directly and speedily by the CPU.

## Building with gcc
Having a source file called hello.c in the current directory, you can build it into a program using gcc
```bash
$ gcc -o
```
-o <filename> <source-code>- Flag says output as this filename from this source-code
