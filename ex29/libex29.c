#include <stdio.h>
#include <ctype.h>
#include "../dbg.h"

int print_a_message(const char *msg)
{
    printf("A STRING: %s\n", msg);

    return 0;
}

int uppercase(const char *msg)
{
    int i = 0;

    // BUG: \0 termination problem
    for (i = 0; i < msg[i]; i++) {
        printf("%c", toupper(msg[i]));
    }

    putchar('\n');

    return 0;
}

int lowercase(const char *msg)
{
    int i = 0;

    // BUG: \0 termination problem
    for (i = 0; i < msg[i]; i++) {
        printf("%c", tolower(msg[i]));
    }

    putchar('\n');

    return 0;
}

int fail_on_purpose(const char *msg)
{
    return -1;
}
