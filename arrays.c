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
