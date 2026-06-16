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
