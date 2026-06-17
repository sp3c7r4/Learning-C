// #include <stdio.h>

// void print2DArray(int a[2][3])
// {
//     for (int r = 0; r < 2; r++)
//         for (int c = 0; c < 3; c++)
//             printf("(%d, %d) is %d\n", r, c, a[r][c]);
// }

// int main(void)
// {
//     int x[2][3] = {
//         {1,2,3},
//         {4,5,6}
//     };
//     print2DArray(x);
// }

// #include <stdio.h>
// int plusOne(int n)
// {
//     return n + 1;
// }

// int main(void)
// {
//     int j = plusOne(1);
//     printf("Adding 1: %d", j);
// }

// #include <stdio.h>
// void increment(int a) {
//     a++; /* Post increment */
// }

// int main(void)
// {
//     int i = 1;
//     increment(i);
//     printf("The value of i is: %d\n", i);
// }

// #include <stdio.h>

// void increment(int *p) {
//     *p = *p + 1;
// }

// int main(void) {
//     int i = 10;
//     int *j = &i;

//     printf("I is %d\n", i);
//     printf("I is also %d\n", *j);

//     increment(j);

//     printf("i is %d\n", i);
// }

/* Exercise 2 */
#include <stddef.h>
#include <stdio.h>

int main1(void)
{
    int a, b = 5;
    a = (b++, b * 2, b + 1);
    printf("%d %d\n", a, b);
    /* Outputs 7 & 6 */
}
/*
 * Explanation:
 * When we run this program we have two variables
 * a declared and b is defined/initialized with a value `5`
 * so we have multiple expressions seperated by the comma
 * for the first one b++ it's a size effect - Post increment it runs first. But since this is a side effect the b value is mutated by adding a 1
 * Moving to the 2nd subexpression b * 2 get's evaluated with b being 6 which results in 12 but since it's seperated by a comma it get's thrown away, moves to the 3rd expression
 * b + 1 which say's 6 + 1 = 7. we have our final value for a = 7 and b = 6
 */

/* Exercise 3 */
int main2(void)
{
    int v = 5;
    int *p1 = &v;
    int *p2 = &v;
    *p1 = 100;
    printf("%d %d %d\n", v, *p1, *p2);
}
/*
 * Explanation
 * We have one integer vaiable v initialized to 5
 * We have 2 integer pointer variables *p1 & *p2 which are initialized to variable `v`'s address
 * Then we Destructure the value from *p1 and replaced it with a new value `100`
 * Since *p1 points to V's address then v becomes 100
 * So therefore *p1, *p2 & v's value is 100
 */

/* Part 2 - Variables, Operators & Control Flows */
// Digit Sum
//
// int getLength(int i) {
//     size_t size = sizeof(i)/sizeof(int);
//     return size;
// }

/* Digit Sum */
int part2(int i) {
    int count = 0;
    do {
        if (i == 0 ) {
            printf("Zero input: 0\n");
            return 0;
        };

        int lastDigit = i % 10;
        i = i / 10;
        count += lastDigit;
    } while (i != 0);


    printf("The total is: %d\n", count);
}

/* Ternary only fizzBuzz */
int part3(int i) {
    for (int j = 0; j < i + 1; j++) {
        printf(
            j % 15 == 0 ?
                "FIZZBUZZ\n" :
                    j % 3 == 0 ?
                        j % 5 == 0 ? "FIZZBUZZ\n" : "FIZZ\n" :
                            j % 5 == 0 ? "BUZZ\n" : "%d\n", j

        );
    }
}

/* Diamond of Asterisks */
int part4(int height) {
    if (height % 2 == 0) {
        printf("Only odd numbers required");
        return 0;
    };

    char s[] = " ";
    int doubleHeight = height * 2;

    int switched = 0;
    int evenCounter = 2;
    int lastCounter = 0;
    for (int i = 0; i < doubleHeight; i++) {
        int padding = doubleHeight - i;
        int noOfAsterisk = i + (i+1);
        char *asteriskSymbol = "*";

        int heightCenter = (doubleHeight / 2);
        int inHeightCenter = i == heightCenter;

        // printf("%d", inHeightCenter);
        if (inHeightCenter) {
            switched = 1;
            lastCounter = noOfAsterisk;
        };

        if (!switched) {
            for (int j = 0; j < padding; j++) {
                printf("%s", s);
            }
            for (int k = 0; k < noOfAsterisk; k++) {
                printf("%s", asteriskSymbol);
            }
            for (int j = 0; j < padding; j++) {
                printf("%s", s);
            }
            printf("\n");
        } else {
            padding = i + 1;
            noOfAsterisk = lastCounter - evenCounter;
            // printf("%d, %d", padding, noOfAsterisk);
            evenCounter += 2;
            for (int m = 0; m < padding; m++) {
                printf("%s", s);
            }
            for (int n = 0; n < noOfAsterisk; n++) {
                printf("%s", asteriskSymbol);
            }
            for (int m = 0; m < padding; m++) {
                printf("%s", s);
            }
            printf("\n");
        }

    }
}

int main(void)
{
    // main1();
    // main2();
    // printf("%d\n", getLength(8))
    // part2(0);
    // part3(30);
    part4(7);
}
