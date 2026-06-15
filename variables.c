// #include <stdio.h>

// int main(void)
// {
//     /* This is a function declaration, they're both uninitialized. It's when we define them we've assinged a value or data to the variable. */
//     // int i;
//     // float f;
//     //
//     int i;

//     i = 2 // Assigned a value into the variable

//     printf("Working with variables\n");
// }


// #include <stdio.h>

// int main(void)
// {
//     int i = 2;
//     float f = 3.142;
//     char *s = "Hello, world!"; //char * ("char pointer") is the string type in c

//     printf("%s i = %d and f = %f!\n", s, i, f);
// }

/* Boolean */

#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int i;
    int j;
    for (i = 0, j = 10; i < 100; i++, j++)
    printf("%d, %d\n", i, j);
}
