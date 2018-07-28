// Demoing shared library callable from Python

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Actual functions in extern "C" block to control the symbol names in the shared library.
// Without it, C++ mangles symbol names.

extern "C"
{

    int add(int a, int b)
    {
        return a + b;
    }

    char *say_hi(const char *to_whom)
    {
        size_t msg_len = strlen(to_whom) + 5;
        char *hi_message = static_cast<char *>(malloc((msg_len) * sizeof(char)));
        printf("buffer at %p\n", hi_message);
        snprintf(hi_message, msg_len, "hi %s!", to_whom);
        return hi_message;
    }

    void say_my_address(const char *buff)
    {
        printf("buffer at %p\n", buff);
    }
}