// #include <stdio.h>
// void increment(int a) {
//     a++; /* Post increment */
// }

// void main()
// {
//     int i = 1;
//     increment(i);
//     printf("The value of i is: %d\n", i);
// }

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
