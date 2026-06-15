// // #include <stdio.h>

// // int main(void)
// // {
// //     /* This is a function declaration, they're both uninitialized. It's when we define them we've assinged a value or data to the variable. */
// //     // int i;
// //     // float f;
// //     //
// //     int i;

// //     i = 2 // Assigned a value into the variable

// //     printf("Working with variables\n");
// // }


// // #include <stdio.h>

// // int main(void)
// // {
// //     int i = 2;
// //     float f = 3.142;
// //     char *s = "Hello, world!"; //char * ("char pointer") is the string type in c

// //     printf("%s i = %d and f = %f!\n", s, i, f);
// // }

// /* Boolean */

// #include <stdio.h>
// #include <stdbool.h>

// int main(void)
// {
//     // int i;
//     // int j;
//     // for (i = 0, j = 10; i < 100; i++, j++)
//     // printf("%d, %d\n", i, j);

//     // int x;
//     // x = (1,2,3);
//     // printf("x is %d\n", x);

//     // int x = 10;
//     // if (x == 10) {
//     //     printf("x is 10\n");
//     //     printf("And also this happends when x is 10\n");
//     // }
//     //

//     // int i = 0;
//     // do {
//     //     printf("do-while: is is %d\n", i);
//     //     i++;
//     // } while (i < 0);

//     // printf("All done!\n");
//     //


// }

#include <stdio.h>
int main(void)
{
    int goat_count = 2;
    switch (goat_count) {
        case 0:
            printf("You have no goats.\n");
            break;
        case 1:
            printf("You have a singular goat.\n");
            break;
        case 2:
            printf("You have 2 goats.\n");
            break;
        default:
            printf("You have an infinite goat!\n");
            break;
    }
}
