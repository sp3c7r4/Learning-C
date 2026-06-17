# Arrays

```c
#include <stdio.h>
void main() 
{
    int i;
    float f[4]; /* An array of 4 floats */

    f[0] = 3.14159; /* Indexing starts on 0 */
    f[1] = 1.41421;
    f[2] = 0.34;
    f[3] = 2.90;

    for (i=0; i<4; i++) {
        printf("%f\n", f[i]);
    }

    /* Output
     * 3.141590
     * 1.414210
     * 0.340000
     * 2.900000
     */
}
```
*Note:* When we declare an arrayy, we have to give it a fixed size

## Getting the Length of an Array
C doesn't store the length of an Array. We have to manage it manually in another variable. Why? Arrays are just pointers to the first element of the array under the hood. No additional information recording the length. Even when you pass an array to a function, you're actually just passing a pointer to the first element of that array not the entire array.
```c
void main()
{
    int x[12];
    printf("%zu\n", sizeof x);
    printf("%zu\n", sizeof(int));

    printf("Length of array x: %d\n", sizeof(x)/sizeof(int));
}
```

## Array Initializers
You can initialize arrays with constants ahead of time.
```c
#include <stdio.h>
int main(void)
{
    int i;
    int a[5] = { 22, 37, 3490, 18, 95 }; /* Initialized a new array with these values */

    for (i = 0; i < 5; i++) {
        printf("%d\n", a[i]);
    }
}
```
*Note:* you should never have more than the elements you've defined. But you can have few elements than you've defined in an array the remaining space will be initialized with zero

```c
int a[5] = {1,2,3};
// Is still the same as
int a[5] = {1,2,3,0,0};

/* Common initializer example - shortcut */
int a[100] = {0};
/* This initializes a new array with a fixed length of 100 max elements */

/* You can set specific elements in an array */
int a[10] = {0,2,3,[5]=99,66,77};
// 0,2,3,0,0,99,66,77,0,0
```

*You can put simple constant expressions in there as well.*
```c
#define COUNT 5
int a[COUNT] = {[COUNT-3]=3,2,1};
// 0 0 3 2 1
```

*Having c to compute the size for us*
```c
int a[3] = {1,2,3}; 
/* Still same as */
int a[] = {1,2,3}
```

## Multidimensional Arrays
```c
int a[10];
int b[2][7];
int c[4][5][6];
```
*Note* These are stored in _row-major order_. This means 2D Array. First Index = Row, Second Index = Column.

*You can also use initializers on multidimensional arrays - Nesting*

```c
#include <stdio.h>
int main(void)
{
    int row, col;
    int a[2][5] = {
        {0, 1, 2, 3, 4},
        {5, 6, 7, 8, 9}
    };

    for (row = 0; row < 2; row++) {
        for (col = 0; col < 5; col++) {
            printf("(%d,%d) = %d\n", row, col, a[row][col]);
        }
    }
}
```

## Arrays and Pointers
### Gettingg a pointer into an array
When a c programmer talks about a pointer to an array, they're talking about a pointer to the first element of the array.
So let's get a pointer to the first element of an array.

```c
#include <stdio.h>

int main(void)
{
    int a[5] = {11,22,33,44,55};
    int *p; /* Pointer variable to store an address */

    p = &a[0]; /* Stores the address of the first element of the array - same as p = a
    */

    printf("%d\n", *p); // 11
}
```

## Passing single Dimensional Arrays to Functions
```c
#include <stdio.h>

void times2(int *a, int len)
{
    for (int i = 0; i < len; i++)
        printf("%d\n", a[i] * 2);
}

/* Using array notation */
void times3(int a[], int len)
{
    for (int i = 0; i < len; i++)
        printf("%d\n", a[i] * 3);
}

/* Using array notation with size */
void times4(int a[5], int len)
{
    for (int i = 0; i< len; i++)
        printf("%d\n", a[i] * 4);
}

int main(void)
{
    int x[5] = {11, 22, 33, 44, 55};

    times2(x, 5);
    times3(x, 5);
    times4(x, 5);
}
```

## Changing Arrays in Functions
When we pass in a pointer into the function it has access and can manipulate the values in that array and those changes are visible out in the caller.

```c
#include <stdio.h>

void double_array(int *a, int len)
{
    for (int i = 0; i < len; i++)
        a[i] *= 2;
}

int main(void)
{
    int x[5] = {1,2,3,4,5};

    double_array(x, 5);

    for (int i = 0; i < 5; i++)
        printf("%d\n", x[i]); // 2, 4, 6, 8, 10!
}
```
## Passing Multidimensional Arrays to Functions
```c
#include <stdio.h>

void print2DArray(int a[2][3])
{
    for (int r = 0; r < 2; r++)
        for (int c = 0; c < 3; c++)
            printf("(%d, %d) is %d\n", r, c, a[r][c]);
}

int main(void)
{
    int x[2][3] = {
        {1,2,3},
        {4,5,6}
    };
    print2DArray(x);
}
```
