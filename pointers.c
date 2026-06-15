// #include <stdio.h>

// int main(void) {
//     int i = 10;
//     printf("The value of i is %d\n", i);
//     printf("And its address is: %p\n", (void *)&i);

//     /* Outputs
//      * The value of i is 10
//      * And its address is: 0x7fff9f6d2f04
//      */
// }

// #include <stdio.h>
// void main(void)
// {
//     int i;
//     int *p; /* Created a pointer variable */

//     p = &i; /* Stored i's location in the location storage */
//     i = 10; /* Addigned 10 to i variable */

//     *p = 20;/* Derefereced the value of i from the pointer variable */

//     printf("The value of i is: %d!\n", i);
//     printf("[Dereferenced] The value of is is: %d\n", *p);
// }

#include <stdio.h>

void increment(int *p) { /* Declares a pointer address */
    *p = *p + 1; /* Adds one to the thing p points to */
}

int main(void) {
    int *p, q; /* P is a pointer variable, q is a normal integer variable */
    int* r; /* Also Valid */
    int *a, b, c, *d; /* Valid */
}
